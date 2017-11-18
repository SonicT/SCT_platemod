//SonicT's armor overhaul script written in sept. 28th

#include "SCT_PENETRATORS.hpp"
#include "SCT_LPENET.hpp"
#include "SCT_SPENET.hpp"
	
params ["_unit", "_ace"];



FUNC_OVERHAULARMOR = {
	params["_hitpoint"];
	_newhitpoint = 5;
	if(_hitpoint > 8) then{_newhitpoint = 8 + (_hitpoint /64)} else { _newhitpoint = _hitpoint};
	_newhitpoint
};

FUNC_forEachPlateDmg = {
	params["_plate", "_dmgleft", "_hitindex", "_padset"];

	_name = _plate select 0;
	_hp = _plate select 1;
	_platedmg = _hp;
	_protarr = getArray(configFile >>"CfgMagazines">> _name >> "SCT_ITEMINFO" >> "enableparts");
	_imarr = getArray(configFile >>"CfgMagazines">> _name >> "SCT_ITEMINFO" >> "blunttraumaPad");
	
	if((count _protarr <(_hitindex + 1)) or (count _imarr < (_hitindex +1)))exitWith{
		_cnt = count _protarr;
		if(!isNil("_hitindex") or (_hitindex < 9)) then {
			for [{_i=0}, {_i < (9 - _cnt)}, {_i = _i + 1}] do {_protarr pushBack 0;};
			systemChat format ["AAPM error : item %1 in config.cpp has low number of protection values - need 9 but just %2. autopush-back for stable system", _name, _cnt];
		}
		else{
			_hitindex = 4;
			systemChat format ["AAPM error : FUNC_forEachPlateDmg in fn_Vestinit.sqf somehow could not read variable 'hitindex' which means where the unit hit. set auto value to 'abdomen' number 4."];
		};
	};
	_prot = _protarr select _hitindex;
	
	_impactabs = _imarr select _hitindex;
	_type = (getArray(configFile >> "CfgMagazines">> _name >> "SCT_ITEMINFO" >> "plateinfo")) select 1;
	_impactdam = (_dmgleft - _prot) max (_dmgleft/((_padset * _impactabs)+1));
	
	if(_impactdam > 0) then {
		_platedmg = floor(_hp - (_impactdam * 10000));
		systemChat format ["indiv. plate - dmg left : %1, hp : %2, where : %3", _impactdam, _platedmg, _hitindex];
	};
		
	if(_penet < 0) //it means if the damage is from explosive, adding dmg to hitpoint "".
	then{
	
	};
	_output = [_impactdam, _platedmg];
	//_output = [_impactdam, _hp - 2000];
	
	_output
};

FUNC_DAMAGEMODULE = {
	params ["_impact","_unit", "_basearmor","_penet", "_hitindex"];
	
	_traumapadedit = missionNameSpace getVariable ["SCT_PLATE_menu_TRAUMAPAD",16];
	_debug = missionNameSpace getVariable ["SCT_PLATE_menu_DEBUG_Checkbox",false];
	_humandam = 4+ (3.48*_penet* _penet); // divider for adjusting human flesh
	
	_impactdam = ((_impact - _basearmor)/_humandam)max (_impact/(_traumapadedit+1));

	_penetval = ((_penet*_impact) -(_basearmor))max 0; //this can have minus value.
	_penetdam = (_penetval/(_humandam)) max 0; //internal penetrating damage
	
	_fdam = _impactdam + _penetdam;
	
	
	_vplates = [];
	_uplates = [];
	_vcon = vestContainer _unit;
	_ucon = uniformContainer _unit;

	if(!(isNull _vcon)) then {
		{
			_name = _x select 0;
			_magcount = _x select 1;
			if(_name isKindOf ["AAPM_Item_Base_magtype", configFile >> "CfgMagazines"]) then{
				_vplates pushBack [_name, _magcount];
			};
		}forEach (magazinesAmmoCargo _vcon);
	};
	
	if(!(isNull _ucon)) then {
		{
			_name = _x select 0;
			_magcount = _x select 1;
			if(_name isKindOf ["AAPM_Item_Base_magtype", configFile >> "CfgMagazines"]) then{
				_uplates pushBack [_name, _magcount];
			};
		}forEach (magazinesAmmoCargo _ucon);
	};
	
	{
		_name = _x select 0;
		_arr = [_x, _fdam, _hitindex, _traumapadedit] call FUNC_forEachPlateDmg;
		_hp = _arr select 1;
		_fdam = _arr select 0;
		_vplates set [_forEachIndex, [_name, _hp]];
		systemChat format ["plate should be damaged : %1, hp : %2", _fdam, _hp];
		
	}forEach _vplates;
	
	
	{
		_unit globalChat format ["damagemodule call plate %1, dmg : %2, where : %3", _x, _impact, _hitindex];
		_arr = [_x, _fdam, _hitindex, _traumapadedit] call FUNC_forEachPlateDmg;
		_hp = _arr select 1;
		_fdam = _arr select 0;
		_uplates set [_forEachIndex, [(_x select 0), _hp]];
		
	}forEach _uplates;
	
	{
		_unit removeItemFromVest (_x select 0);
	}forEach _vplates;
	
	{
		_vcon addMagazineAmmoCargo [_x select 0, 1, _x select 1];
		
	}forEach _vplates;
	
	{
		_unit removeItemFromUniform (_x select 0);
	}forEach _uplates;	
	{
		_ucon addMagazineAmmoCargo [_x select 0, 1, _x select 1];
	}forEach _uplates;

	_fdam
};

FUNC_CHECKPLATE = {
	params["_unit"];
	_debug = missionNameSpace getVariable ["SCT_PLATE_menu_DEBUG_Checkbox",false];
	//get original this unit's armor ratings.
	_uniform = uniform _unit;
	//uniform config has no armor data - it is 'man' which has armor data. to access, we have to find out 'uniform class'.
	_uniformdata = getText(configFile>> "cfgWeapons" >> _uniform >> "ItemInfo" >> "uniformClass");
	_vest = vest _unit;

	//new headgear feature requested by V.Verlioz. I'm not sure how it will be implemented, though.
	_hGear = headgear _unit;
	
	_armorfull = getNumber (configFile>>"cfgVehicles">>"CAManBase" >>"armor");
	if((isNil "_armorfull") or (_armorfull ==0)) then {_armorfull = 2};
	_armoruniformhitpoint = [
	getNumber (configFile>>"cfgVehicles">>"CAManBase" >>"Hitpoints">>"HitNeck">>"armor"),
	getNumber (configFile>>"cfgVehicles">>"CAManBase" >>"Hitpoints">>"HitArms">>"armor"),
	getNumber (configFile>>"cfgVehicles">>"CAManBase" >>"Hitpoints">>"HitChest">>"armor"),
	getNumber (configFile>>"cfgVehicles">>"CAManBase" >>"Hitpoints">>"HitDiaphragm">>"armor"),
	getNumber (configFile>>"cfgVehicles">>"CAManBase" >>"Hitpoints">>"HitAbdomen">>"armor"),
	getNumber (configFile>>"cfgVehicles">>"CAManBase" >>"Hitpoints">>"HitPelvis">>"armor"),
	getNumber (configFile>>"cfgVehicles">>"CAManBase" >>"Hitpoints">>"HitLegs">>"armor"),
	getNumber (configFile>>"cfgVehicles">>"CAManBase" >>"Hitpoints">>"HitHead">>"armor"),
	getNumber (configFile>>"cfgVehicles">>"CAManBase" >>"Hitpoints">>"HitFace">>"armor")
	];
	
	
	_armorvesthitpoint = [0,0,0,0,0,0,0,0,0];
		
		
	//vanilla vest protection only cares about neck, arms, chest, diaphragm, abdomen and pelvis - i dunno whether other values work. plus vanilla body armor is 1000 default, so theres so mere way to direct damage of this part. this part is damaged almost by dependency.
	if(_vest isEqualTo "") then {_vest = "empty";}
	else{
		_armorvesthitpoint set [0, getNumber (configFile>>"cfgWeapons">>_vest>>"ItemInfo">>"HitpointsProtectionInfo">>"Neck">>"armor")];
		_armorvesthitpoint set [1, getNumber (configFile>>"cfgWeapons">>_vest>>"ItemInfo">>"HitpointsProtectionInfo">>"Arms">>"armor")];
		_armorvesthitpoint set [2, getNumber (configFile>>"cfgWeapons">>_vest>>"ItemInfo">>"HitpointsProtectionInfo">>"Chest">>"armor")];
		_armorvesthitpoint set [3, getNumber (configFile>>"cfgWeapons">>_vest>>"ItemInfo">>"HitpointsProtectionInfo">>"Diaphragm">>"armor")];
		_armorvesthitpoint set [4, getNumber (configFile>>"cfgWeapons">>_vest>>"ItemInfo">>"HitpointsProtectionInfo">>"Abdomen">>"armor")];
		_armorvesthitpoint set [5, getNumber (configFile>>"cfgWeapons">>_vest>>"ItemInfo">>"HitpointsProtectionInfo">>"Pelvis">>"armor")];
		_armorvesthitpoint set [6, getNumber (configFile>>"cfgWeapons">>_vest>>"ItemInfo">>"HitpointsProtectionInfo">>"Legs">>"armor")];
		
	};

	//HEADGEAR FEATURE - CONTINUE WORK AT HOME
	if(_hGear isEqualTo "") then {_hGear = "empty";}
	else{
		_armorvesthitpoint set [7, getNumber (configFile>>"cfgWeapons">>_hGear>>"ItemInfo">>"HitpointsProtectionInfo">>"Head">>"armor")];
		_armorvesthitpoint set [8, getNumber (configFile>>"cfgWeapons">>_hGear>>"ItemInfo">>"HitpointsProtectionInfo">>"Face">>"armor")];
		
	};
		
	if(_uniform isEqualTo "") then {_uniform = "empty"}
	else{
		_armorfull = getNumber (configFile>>"cfgVehicles">>_uniformdata >>"armor");
		_armoruniformhitpoint set [0, getNumber (configFile>>"cfgVehicles">>_uniformdata >>"Hitpoints">>"HitNeck">>"armor")];
		_armoruniformhitpoint set [1, getNumber (configFile>>"cfgVehicles">>_uniformdata >>"Hitpoints">>"HitArms">>"armor")];
		_armoruniformhitpoint set [2, getNumber (configFile>>"cfgVehicles">>_uniformdata >>"Hitpoints">>"HitChest">>"armor")];
		_armoruniformhitpoint set [3, getNumber (configFile>>"cfgVehicles">>_uniformdata >>"Hitpoints">>"HitDiaphragm">>"armor")];
		_armoruniformhitpoint set [4, getNumber (configFile>>"cfgVehicles">>_uniformdata >>"Hitpoints">>"HitAbdomen">>"armor")];
		_armoruniformhitpoint set [5, getNumber (configFile>>"cfgVehicles">>_uniformdata >>"Hitpoints">>"HitPelvis">>"armor")];
		_armoruniformhitpoint set [6, getNumber (configFile>>"cfgVehicles">>_uniformdata >>"Hitpoints">>"HitLegs">>"armor")];
		_armoruniformhitpoint set [5, getNumber (configFile>>"cfgVehicles">>_uniformdata >>"Hitpoints">>"HitPelvis">>"armor")];
		_armoruniformhitpoint set [6, getNumber (configFile>>"cfgVehicles">>_uniformdata >>"Hitpoints">>"HitLegs">>"armor")];
		_armoruniformhitpoint set [7, getNumber (configFile>>"cfgVehicles">>_uniformdata >>"Hitpoints">>"HitHead">>"armor")];
		_armoruniformhitpoint set [8, getNumber (configFile>>"cfgVehicles">>_uniformdata >>"Hitpoints">>"HitFace">>"armor")];
	};
	
	//find out protection value to calculate original hit
	_hitprotection = [_armorfull*(_armoruniformhitpoint select 0) + (_armorvesthitpoint select 0), _armorfull*(_armoruniformhitpoint select 1) + (_armorvesthitpoint select 1),
		_armorfull*(_armoruniformhitpoint select 2) + (_armorvesthitpoint select 2),_armorfull*(_armoruniformhitpoint select 3) + (_armorvesthitpoint select 3),
		_armorfull*(_armoruniformhitpoint select 4) + (_armorvesthitpoint select 4), _armorfull*(_armoruniformhitpoint select 5) + (_armorvesthitpoint select 5),
		_armorfull*(_armoruniformhitpoint select 6) + (_armorvesthitpoint select 6), _armorfull*(_armoruniformhitpoint select 7) + (_armorvesthitpoint select 7),
		_armorfull*(_armoruniformhitpoint select 8) + (_armorvesthitpoint select 8)];
		
	
	//Make an array that will contain armor plate information.
	//plate array 0 : full HP; 1 : armor value; 2 : armor name 3 : armor type
	
	{    
		if(_x isKindof ["SonicT_Item_Base", configFile >> "cfgWeapons"]) then{    
			_infoarr = getArray(configFile >>"CfgWeapons">> _x >> "SCT_ITEMINFO" >> "plateinfo");
			_infoprot = getArray(configFile >>"CfgWeapons">> _x >> "SCT_ITEMINFO" >> "enableparts");
			_cnt = count _infoprot;
			_canAdd = getArray(configFile >>"CfgWeapons">> _x >> "SCT_ITEMINFO" >> "enablePlace");
			if(count _infoarr > 0 && ("Vest" in _canAdd)) then{
				_magtype = format["%1_magtype", _x];
				_unit removeItemFromVest _x;
				_unit addItemToVest _magtype;
			};
		};
		
	}forEach (vestItems _unit);
	
	{    
		if(_x isKindof ["SonicT_Item_Base", configFile >> "cfgWeapons"]) then{    
			_infoarr = getArray(configFile >>"CfgWeapons">> _x >> "SCT_ITEMINFO" >> "plateinfo");
			_infoprot = getArray(configFile >>"CfgWeapons">> _x >> "SCT_ITEMINFO" >> "enableparts");
			_cnt = count _infoprot;
			_canAdd = getArray(configFile >>"CfgWeapons">> _x >> "SCT_ITEMINFO" >> "enablePlace"); //it WAS my mistake where error comes out : you just ommitted this line
			if(count _infoarr > 0 && ("Uniform" in _canAdd)) then{
				_magtype = format["%1_magtype", _x];
				_unit removeItemFromUniform _x;
				_unit addItemToUniform _magtype;
			};
		};
		
	}forEach (uniformItems _unit);
	
	{    
		if(_x isKindof ["SonicT_Item_Base", configFile >> "cfgWeapons"]) then{    
			_infoarr = getArray(configFile >>"CfgWeapons">> _x >> "SCT_ITEMINFO" >> "plateinfo");
			_infoprot = getArray(configFile >>"CfgWeapons">> _x >> "SCT_ITEMINFO" >> "enableparts");
			_cnt = count _infoprot;
			_canAdd = getArray(configFile >>"CfgWeapons">> _x >> "SCT_ITEMINFO" >> "enablePlace"); //it WAS my mistake where error comes out : you just ommitted this line
			if(count _infoarr > 0 && ("Backpack" in _canAdd)) then{
				_magtype = format["%1_magtype", _x];
				_unit removeItemFromBackpack _x;
				_unit addItemToBackpack _magtype;
			};
		};
		
	}forEach (backpackItems _unit);
	
	//if there is no plate in your vest, the array saves 'no plate'

	
	//Make overhauled armor.
	_overhaularmor = _hitprotection apply {[_x] call FUNC_OVERHAULARMOR};

	_unit setVariable ["SCT_BaseArmor", _hitprotection];
	_unit setVariable["SCT_newArmor", _overhaularmor];
	
};
   
    
    
FUNC_EVENTDMGHANDLE = { 

	_rifledmg = missionNameSpace getVariable ["SCT_PLATE_menu_RiflePenet",1.375];
	_debug = missionNameSpace getVariable ["SCT_PLATE_menu_DEBUG_Checkbox",false];
		 
	_unit = _this select 0;
	_cancallhitback = false;


	_basearmor = _unit getVariable "SCT_BaseArmor";
	_newarmor = _unit getVariable "SCT_newArmor";

	if(isNil "_basearmor") then {_basearmor = [1,5,1,1,1,6,5];}; //if basearmor is Nil return to vanilla civilian default.
	//armor : 0 - hitneck, 1 - hitnarms, 2 - hitchest 3- hitdiaphragm, 4- hitabdomen, 5- hitpelvis, 6- hitlegs 7- HITHEAD, 8-HITFACE
	
	_highspeed = 0; // this value will determine whether hard armor needs or not.       
	_endurance = _armorstat select 0;
	_platetype = ((_armorstat select 1) select 0) select 1;
	_tPad = _armorstat select 2;
	
	_shooter = _this select 3;
	_dmg = _this select 2;
	_hitnum = _this select 5;
	//infantry hitselection number 0 : face_hub, 1: neck, 2 : head, 3 : pelvis, 4 : spine1, 5 : spine2, 6 : spine3, 7 : body, 8 : arms, 9: hands, 10 : legs
	_dmgfrom = _this select 4;
	_hitpoint = _this select 7;
	_prevdmg = _unit getHitIndex _hitnum;

	_selectionarmor = 1;
	_currarmor = _newarmor select 2;
	
	_hitnow = _dmg - _prevdmg; //know current damage
	_originalhit = _hitnow;
	if(getNumber (configFile >> "cfgAmmo" >> _dmgfrom >> "typicalSpeed") > 800) then {_highspeed = _rifledmg;} else{_highspeed = 0;}; // penetrates soft armor, multiplying dmg
	if(getNumber (configFile >> "cfgAmmo" >> _dmgfrom >> "typicalSpeed") > 980) then {_highspeed*1.3;} else{_highspeed = 0;}; // Better simulation of higher-velocity cartridges like M193.
	if(_dmgfrom in SCT_PENETRATORS) then {_highspeed = _rifledmg*1.7; }; //Basic AP rounds. Believed to be not effective on flesh targets.
	if(_dmgfrom in SCT_SPENET) then {_highspeed = _rifledmg*2.2; }; //Exotic AP rounds. Barely effective on flesh targets but brutally good against armor.
	if(_dmgfrom in SCT_LPENET) then {_highspeed = _rifledmg*0.85;}; // less penetratable rounds - Believed to be effective on flesh targets, but not effective to other materials.
		//implement new damage model

	
	
	switch (_hitpoint) do {
			
			
			
		case "HitNeck" : {
			_selectionarmor = _basearmor select 0;
			_originalhit = _hitnow * _selectionarmor; //revert to original bullet damage, not divided by armor protection
			_hitnow = [_originalhit, _unit, _selectionarmor, _highspeed, 0] call FUNC_DAMAGEMODULE;
						
		};
		case "HitArms" : {
			_selectionarmor = _basearmor select 1;
			_originalhit = _hitnow * _selectionarmor; //revert to original bullet damage, not divided by armor protection
			_hitnow = [_originalhit, _unit, _selectionarmor, _highspeed, 1] call FUNC_DAMAGEMODULE;
							
		};
		case "HitChest" : {
			_selectionarmor = _basearmor select 2;
			_originalhit = _hitnow * _selectionarmor; //revert to original bullet damage, not divided by armor protection
			_hitnow = [_originalhit, _unit, _selectionarmor, _highspeed, 2] call FUNC_DAMAGEMODULE;
				
		};
		case "HitDiaphragm" : {
			_selectionarmor = _basearmor select 3;
			_originalhit = _hitnow * _selectionarmor; //revert to original bullet damage, not divided by armor protection
			_hitnow = [_originalhit, _unit, _selectionarmor, _highspeed, 3] call FUNC_DAMAGEMODULE;
		};
		case "HitAbdomen" : {
			_selectionarmor = _basearmor select 4;
			_originalhit = _hitnow * _selectionarmor; //revert to original bullet damage, not divided by armor protection
			_hitnow = [_originalhit, _unit, _selectionarmor, _highspeed, 4] call FUNC_DAMAGEMODULE;
		};
		case "HitPelvis": {
			_selectionarmor = _basearmor select 5;
			_originalhit = _hitnow * _selectionarmor; //revert to original bullet damage, not divided by armor protection
			_hitnow = [_originalhit, _unit, _selectionarmor, _highspeed, 5] call FUNC_DAMAGEMODULE;
		};
		case "HitLegs" : {
			_selectionarmor = _basearmor select 6;
			_originalhit = _hitnow * _selectionarmor; //revert to original bullet damage, not divided by armor protection
			_hitnow = [_originalhit, _unit, _selectionarmor, _highspeed, 6] call FUNC_DAMAGEMODULE;
		};
		case "HitBody" : {
			
		};
			
		case "HitHead" : {
			_selectionarmor = _basearmor select 7;
			_originalhit = _hitnow * _selectionarmor; //revert to original bullet damage, not divided by armor protection
			_hitnow = [_originalhit, _unit, _selectionarmor, _highspeed, 7] call FUNC_DAMAGEMODULE;
			
		};
		case "HitFace" : {
			_selectionarmor = _basearmor select 8;
			_originalhit = _hitnow * _selectionarmor; //revert to original bullet damage, not divided by armor protection
			_hitnow = [_originalhit, _unit, _selectionarmor, _highspeed, 8] call FUNC_DAMAGEMODULE;
			
		};
		
		case "HitLeftArm" : {
			_selectionarmor = _basearmor select 1;
			_originalhit = _hitnow * _selectionarmor; //revert to original bullet damage, not divided by armor protection
			_hitnow = [_originalhit, _unit, _selectionarmor, _highspeed, 1] call FUNC_DAMAGEMODULE;
		};
		
		case "HitRightArm" : {
			_selectionarmor = _basearmor select 1;
			_originalhit = _hitnow * _selectionarmor; //revert to original bullet damage, not divided by armor protection
			_hitnow = [_originalhit, _unit, _selectionarmor, _highspeed, 1] call FUNC_DAMAGEMODULE;
		};
		
		case "HitLeftLeg" : {
			_selectionarmor = _basearmor select 6;
			_originalhit = _hitnow * _selectionarmor; //revert to original bullet damage, not divided by armor protection
			_hitnow = [_originalhit, _unit, _selectionarmor, _highspeed, 6] call FUNC_DAMAGEMODULE;
		};
		
		case "HitRightLeg" : {
			_selectionarmor = _basearmor select 6;
			_originalhit = _hitnow * _selectionarmor; //revert to original bullet damage, not divided by armor protection
			_hitnow = [_originalhit, _unit, _selectionarmor, _highspeed, 6] call FUNC_DAMAGEMODULE;
		};
		
		case "" : {
			_cancallhitback = true;
			_hitnow = 0;
			_hmul = 1;
			if(_dmgfrom isKindOf "BulletBase") then {
				
				if(isNil{_unit getHitPointDamage "leg_l"}) then {
					if(((_unit getHitPointDamage "HitArms") > 0.99) or ((_unit getHitPointDamage "HitLegs") >0.99)) then {
						_hmul = 1;
					}else{
						_hmul = 0;
					};
					_hitnow = _hitnow * _hmul;
				} else{
					if(((_unit getHitPointDamage "leg_l") > 0.99) or ((_unit getHitPointDamage "leg_r") >0.99)
					or ((_unit getHitPointDamage "hand_r") >0.99)or ((_unit getHitPointDamage "hand_r") >0.99)) then {
						_hmul = 1;
						
					} else{
						_hmul = 0;
					};
					_hitnow = _hitnow * _hmul;
				};
				
			}
			/*
			else{
				if(_dmgfrom != "") then {
					_orhit = _hitnow;
					if(_debug) then {
						systemChat format ["unit %1 hit by non bullet(explosive), %2", _unit, _dmgfrom];
					};
					_impactarr = [4,1,5,4,5,4,1,4,4]; //neck, arms, chest, diaphragm, abs, pelvis, legs, head and face
					_totdmg = 0;
					{
						_index = _forEachIndex;
						_totdmg = _totdmg + (([_orhit, _unit, 1, -1,_index] call FUNC_DAMAGEMODULE) * _x);
					}forEach _impactarr;
					_hitnow = _totdmg/32;
				};
			};
			*/
		};
		default {
			
		};
	};		
	_dmg = _hitnow + _prevdmg;
	
	if((_dmg < 0.02) and (_dmgfrom isKindOf "BulletBase")) then {
		_bullet = getPos _unit nearestObject _dmgfrom;
		deleteVehicle _bullet;
	};
	
	if(((_hitnow> 0.3) or (_originalhit > 1)) && _debug) then {
		_unit globalChat format ["Major hit here : %1, %2 , with armor %3, tot DMG : %4", _hitpoint, _originalhit, _currarmor, _dmg];
	};
		
	//backblast effect.
	
	_dir = (getPosASL (_shooter))vectorFromTo (getPosASL (_unit));
	_originalhitclamp = [_unit, _originalhit] call {params ["_unit", "_originalhit"]; _goback = 0; 
	if(_originalhit > 80) then {_goback = 80 + (_originalhit * 0.01);} else {_goback = _originalhit}; _goback};
	_force = _dir vectorMultiply (_originalhitclamp/16);
	_vel = velocity _unit;
	if((_dmgfrom isKindOf "TimeBombCore") or (_dmgfrom isKindOf "GrenadeCore")or (_dmgfrom isKindOf "FuelExplosion")) then {
		_force set [2, abs(_force select 2) * 3];
		_dir set [2, 3 * abs(_dir select 2) +3];
	}else {
		if(_dmgfrom isKindOf "Grenade") then {
			_force = _dir vectorMultiply _originalhitclamp;
			_force set [2, 0.5 + abs(_force select 2) * 2];
			_dir set [2, abs(_dir select 2)];
		};
	
	};
	_nvel = [(_vel select 0) + ((_force select 0)/(1 + abs(_vel select 0))), (_vel select 1) + ((_force select 1)/(1 + abs(_vel select 1))), (_vel select 2) + (2*(_force select 2)/(1 + abs(_vel select 2)))];
	
	
	if(alive _unit) then {
		_unit setVelocity _nvel;
	};
	
	
	if(!(_unit isKindOf "Man")) then{
		_dmg = _dmg;
	};
	
	_dmg  
}; 



[_unit] call FUNC_CHECKPLATE;

if(_ace == 1) then {
_unit addEventHandler["HandleDamage", {[_this select 0, _this select 1, _this call FUNC_EVENTDMGHANDLE, _this select 3, _this select 4, _this select 5, _this select 6] call ACE_medical_fnc_handleDamage;}];

}
else{
	_unit addEventHandler["HandleDamage", {[_this select 0, _this select 1, _this select 2, _this select 3, _this select 4, _this select 5, _this select 6, _this select 7] call FUNC_EVENTDMGHANDLE;}];

};
_unit addEventHandler["Respawn", {[_this select 0] call FUNC_CHECKPLATE;}];
[_unit] spawn {
	params["_unit"];
	_tems = Items _unit;
	_dduk = headgear _unit;
	_ve = vest _unit;
	while{alive _unit} do {
		
		waitUntil{!(_tems isEqualTo (Items _unit)) or !(_dduk isEqualTo (headgear _unit)) or !(_ve isEqualTo (vest _unit))};
		[_unit] call FUNC_CHECKPLATE;
		_tems = Items _unit;
		_dduk = headgear _unit;
		_ve = vest _unit;
	};
	

	
};