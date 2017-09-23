#include "SCT_PENETRATORS.hpp"

params ["_unit", "_ace"];



FUNC_OVERHAULARMOR = {
	params["_hitpoint"];
	_newhitpoint = 5;
	if(_hitpoint > 8) then{_newhitpoint = 8 + (_hitpoint /64)} else { _newhitpoint = _hitpoint};
	_newhitpoint
};

FUNC_DAMAGEMODULE = {
	params ["_impact","_armor", "_penet" , "_type", "_currPad"];
	
	_traumapadedit = missionNameSpace getVariable ["SCT_PLATE_menu_TRAUMAPAD",128];
	_debug = missionNameSpace getVariable ["SCT_PLATE_menu_DEBUG_Checkbox",false];
	_dam = 0; //return 0 when if- scope does not work
	_humandam = 5+ (3.48*_penet* _penet); // divider for adjusting human flesh
	_impactdam = ((_impact - _armor)/_humandam)max (_impact/(_traumapadedit * _currPad));
	
	//hint str (_traumapadedit * _currPad);
	
	_penetval = _penet*(_impact + _type) -(_armor); //this can have minus value.
	_penetdam = (_penetval/(_humandam)) max 0; //internal penetrating damage
	_dam = _impactdam + _penetdam;
		/*	*damage module explanation : if armor cannot hold impact itself, impact will be just go through to body, except armor absorbtion. x0.8 for least shieding.
			*bullet punch : if armor holded whole impact damage, 
			* *0.6 in penetration : penet damage should not be that big.
			* +2 in penetration : vanilla .45cal hit is 8, and 5.45 is 7 - but 5.45 penets iiia armor for 4-5 layers in real world... in ACE3mod situation got worse. carbines have less damage..  so made offset.
			*penetration : if penetration value is high, it is more likely to penetrate armor
		*/

	if(_debug && (_dam > 0.05)) then {
		systemChat format ["damage - impact : %1, penetration : %2, tot %3", _impactdam, _penetdam, _dam];
	};
		

	_dam
};

FUNC_CHECKPLATE = {
	params["_this"];
	_debug = missionNameSpace getVariable ["SCT_PLATE_menu_DEBUG_Checkbox",false];
	//get original this unit's armor ratings.
	_uniform = uniform _unit;
	//uniform config has no armor data - it is 'man' which has armor data. to access, we have to find out 'uniform class'.
	_uniformdata = getText(configFile>> "cfgWeapons" >> _uniform >> "ItemInfo" >> "uniformClass");
	_vest = vest _unit;
	
	_armorfull = getNumber (configFile>>"cfgVehicles">>"CAManBase" >>"armor");
	if((isNil "_armorfull") or (_armorfull ==0)) then {_armorfull = 2};
	_armoruniformhitpoint = [
	getNumber (configFile>>"cfgVehicles">>"CAManBase" >>"Hitpoints">>"HitNeck">>"armor"),
	getNumber (configFile>>"cfgVehicles">>"CAManBase" >>"Hitpoints">>"HitArms">>"armor"),
	getNumber (configFile>>"cfgVehicles">>"CAManBase" >>"Hitpoints">>"HitChest">>"armor"),
	getNumber (configFile>>"cfgVehicles">>"CAManBase" >>"Hitpoints">>"HitDiaphragm">>"armor"),
	getNumber (configFile>>"cfgVehicles">>"CAManBase" >>"Hitpoints">>"HitAbdomen">>"armor"),
	getNumber (configFile>>"cfgVehicles">>"CAManBase" >>"Hitpoints">>"HitPelvis">>"armor"),
	getNumber (configFile>>"cfgVehicles">>"CAManBase" >>"Hitpoints">>"HitLegs">>"armor")
	];
	_armorvesthitpoint = [1,1,1,1,1,1,1];
		
		
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
	};
	
	//find out protection value to calculate original hit
	_hitprotection = [_armorfull*(_armoruniformhitpoint select 0) + (_armorvesthitpoint select 0), _armorfull*(_armoruniformhitpoint select 1) + (_armorvesthitpoint select 1),
		_armorfull*(_armoruniformhitpoint select 2) + (_armorvesthitpoint select 2),_armorfull*(_armoruniformhitpoint select 3) + (_armorvesthitpoint select 3),
		_armorfull*(_armoruniformhitpoint select 4) + (_armorvesthitpoint select 4), _armorfull*(_armoruniformhitpoint select 5) + (_armorvesthitpoint select 5),
		_armorfull*(_armoruniformhitpoint select 6) + (_armorvesthitpoint select 6)];
		
	
	//Make an array that will contain armor plate information.
	//plate array 0 : full HP; 1 : armor value; 2 : armor name 3 : armor type
	_arrayp = [];
	_totprot = [0,0,0,0,0,0,0];
	_totReduceImpact = [1,1,1,1,1,1,1];
	{    
		if(_x isKindof ["SonicT_Item_Base", configFile >> "cfgWeapons"]) then{    
			_infoarr = getArray(configFile >>"CfgWeapons">> _x >> "SCT_ITEMINFO" >> "plateinfo");
			_infoprot = getArray(configFile >>"CfgWeapons">> _x >> "SCT_ITEMINFO" >> "enableparts");
			_infotrau = getArray(configFile >>"CfgWeapons">> _x >> "SCT_ITEMINFO" >> "blunttraumaPad");
			_canAdd = getArray(configFile >>"CfgWeapons">> _x >> "SCT_ITEMINFO" >> "enablePlace");
			if(count _infoarr > 0 && ("Vest" in _canAdd)) then{
				_arrayp pushBack _infoarr;
				 for [{_i=0}, {_i < 7}, {_i = _i + 1}] do {
					_totprot set [_i, (_totprot select _i) + (_infoprot select _i)];
					_totReduceImpact set [_i, (_totReduceImpact select _i) + (_infotrau select _i)];
				 };
			};
		};
		
	}forEach (vestItems _this);
	
	{    
		if(_x isKindof ["SonicT_Item_Base", configFile >> "cfgWeapons"]) then{    
			_infoarr = getArray(configFile >>"CfgWeapons">> _x >> "SCT_ITEMINFO" >> "plateinfo");
			_infoprot = getArray(configFile >>"CfgWeapons">> _x >> "SCT_ITEMINFO" >> "enableparts");
			_infotrau = getArray(configFile >>"CfgWeapons">> _x >> "SCT_ITEMINFO" >> "blunttraumaPad");
			if(count _infoarr > 0 && ("Uniform" in _canAdd)) then{
				_arrayp pushBack _infoarr;
				 for [{_i=0}, {_i < 7}, {_i = _i + 1}] do {
					_totprot set [_i, (_totprot select _i) + (_infoprot select _i)];
					_totReduceImpact set [_i, (_totReduceImpact select _i) + (_infotrau select _i)];
				 };
			};
		};
		
	}forEach (uniformItems _this);
	//if there is no plate in your vest, the array saves 'no plate'
	if(count _arrayp < 1) then {
		_arrayp pushBack ["No plate", 0];
	};
	
	//Make overhauled armor.
	_overhaularmor = _hitprotection apply {[_x] call FUNC_OVERHAULARMOR};
	if((isPlayer _unit) && (local _unit) && _debug) then {
		if(isNil{_unit getVariable "SCT_ARMORSTAT"}) then {
			hintSilent format ["        Armor Equipment\n\nuniform : %1\n
				vest : %2\n   plate : %3 \n
				Protection Values\n\n       Neck : %4\n      Arms : %5\nChest : %6\n Diaphragm : %7\n   Abdomen : %8\n
				Pelvis : %9\n       Legs : %10",
				_uniform, _vest,(_arrayp select 0) select 2,
				(_overhaularmor select 0) + (_totprot select 0),
				(_overhaularmor select 1) + (_totprot select 1),
				(_overhaularmor select 2) + (_totprot select 2),
				(_overhaularmor select 3) + (_totprot select 3),
				(_overhaularmor select 4) + (_totprot select 4),
				(_overhaularmor select 5) + (_totprot select 5),
				(_overhaularmor select 6) + (_totprot select 6)];
		} else{ if(!(((_unit getVariable "SCT_ARMORSTAT") select 1)isEqualTo _arrayp)) 
			then {
				hintSilent format ["        Armor Equipment\n\nuniform : %1\n
					vest : %2\n   plate : %3 \n
					Protection Values\n\n       Neck : %4\n      Arms : %5\nChest : %6\n Diaphragm : %7\n   Abdomen : %8\n
					Pelvis : %9\n       Legs : %10",
					_uniform, _vest, _arrayp,
					(_overhaularmor select 0) + (_totprot select 0),
					(_overhaularmor select 1) + (_totprot select 1),
					(_overhaularmor select 2) + (_totprot select 2),
					(_overhaularmor select 3) + (_totprot select 3),
					(_overhaularmor select 4) + (_totprot select 4),
					(_overhaularmor select 5) + (_totprot select 5),
					(_overhaularmor select 6) + (_totprot select 6)];
			};
		};
	};

	_this setVariable["SCT_ARMORSTAT", [_totprot , _arrayp, _totReduceImpact]];
	_this setVariable ["SCT_BaseArmor", _hitprotection];
	_this setVariable["SCT_newArmor", _overhaularmor];
	
};
   
    
    
FUNC_EVENTDMGHANDLE = { 

	_rifledmg = missionNameSpace getVariable ["SCT_PLATE_menu_RiflePenet",2];
	_debug = missionNameSpace getVariable ["SCT_PLATE_menu_DEBUG_Checkbox",false];
		 
	_unit = _this select 0;
	_cancallhitback = false;

	_armorstat = _unit getVariable "SCT_ARMORSTAT";
	_basearmor = _unit getVariable "SCT_BaseArmor";
	_newarmor = _unit getVariable "SCT_newArmor";

	if(isNil "_armorstat") then {_armorstat = [[0,0,0,0,0,0,0], [["NO plate",0]], [1,1,1,1,1,1,1]]};
	if(isNil "_basearmor") then {_basearmor = [2, 10, 2, 2, 2 ,12,10];}; //if basearmor is Nil return to vanilla civilian default.
	//armor : 0 - hitneck, 1 - hitnarms, 2 - hitchest 3- hitdiaphragm, 4- hitabdomen, 5- hitpelvis, 6- hitlegs
	
	_highspeed = 0; // this value will determine whether hard armor needed or not.       
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
	if(getNumber (configFile >> "cfgAmmo" >> _dmgfrom >> "typicalSpeed") > 600) then {_highspeed = _rifledmg;} else{_highspeed = 0;}; // penetrates soft armor, multiplying dmg
	if(_dmgfrom in SCT_PENETRATORS) then {_highspeed = _rifledmg*1.4; }; //AP rounds. Believed to be not effective on flesh targets.
		//implement new damage model
	
	_veh = vehicle _unit;
	/*if(!(_veh isKindOf "Man")&& !(_veh isKindOf "StaticWeapon")) then{
		_dmg = _dmg;
	}*/
	
	switch (_hitpoint) do {
			
			
			
		case "HitNeck" : {
			_selectionarmor = _basearmor select 0;
			_currPad = _tPad select 0;
			_currarmor = (_newarmor select 0) + (_endurance select 0);
			_originalhit = _hitnow * _selectionarmor; //revert to original bullet damage, not divided by armor protection.... it was sick anyway.
			_hitnow = [_originalhit, _currarmor, _highspeed, _platetype, _currPad] call FUNC_DAMAGEMODULE;
						
		};
		case "HitArms" : {
			_selectionarmor = _basearmor select 1;
			_currPad = _tPad select 1;
			_currarmor = (_newarmor select 1)+ (_endurance select 1);
			_originalhit = _hitnow * _selectionarmor; //revert to original bullet damage, not divided by armor protection.... it was sick anyway.
			_hitnow = ([_originalhit, _currarmor, _highspeed, _platetype, _currPad] call FUNC_DAMAGEMODULE);
							
		};
		case "HitChest" : {
			_selectionarmor = _basearmor select 2;
			_currPad = _tPad select 2;
			_currarmor = (_newarmor select 2) + (_endurance select 2);
			_originalhit = _hitnow * _selectionarmor; //revert to original bullet damage, not divided by armor protection.... it was sick anyway.
			_hitnow = [_originalhit, _currarmor, _highspeed, _platetype, _currPad] call FUNC_DAMAGEMODULE;
				
		};
		case "HitDiaphragm" : {
			_selectionarmor = _basearmor select 3;
			_currPad = _tPad select 3;
			_currarmor = (_newarmor select 3) + (_endurance select 3);
			_originalhit = _hitnow * _selectionarmor; //revert to original bullet damage, not divided by armor protection.... it was sick anyway.
			_hitnow = [_originalhit, _currarmor, _highspeed, _platetype, _currPad] call FUNC_DAMAGEMODULE;
		};
		case "HitAbdomen" : {
			_selectionarmor = _basearmor select 4;
			_currPad = _tPad select 4;
			_currarmor = (_newarmor select 4)+ (_endurance select 4) ;
			_originalhit = _hitnow * _selectionarmor; //revert to original bullet damage, not divided by armor protection.... it was sick anyway.
			_hitnow = [_originalhit, _currarmor, _highspeed, _platetype, _currPad] call FUNC_DAMAGEMODULE;
		};
		case "HitPelvis": {
			_selectionarmor = _basearmor select 5;
			_currPad = _tPad select 5;
			_currarmor = (_newarmor select 5) + + (_endurance select 5);	
			_originalhit = _hitnow * _selectionarmor; //revert to original bullet damage, not divided by armor protection.... it was sick anyway.
			_hitnow = [_originalhit, _currarmor, _highspeed, _platetype, _currPad] call FUNC_DAMAGEMODULE;
		};
		case "HitLegs" : {
			_selectionarmor = _basearmor select 6;
			_currPad = _tPad select 6;
			_currarmor = (_newarmor select 6) + + (_endurance select 6);	
			_originalhit = _hitnow * _selectionarmor; //revert to original bullet damage, not divided by armor protection.... it was sick anyway.
			_hitnow = [_originalhit, _currarmor, _highspeed, _platetype, _currPad] call FUNC_DAMAGEMODULE;
		};
		case "HitBody" : {
			/*_selectionarmor = _basearmor select 4;
			_currarmor = ((_newarmor select 4) + _endurance) ;
			_originalhit = _hitnow * _selectionarmor; //revert to original bullet damage, not divided by armor protection.... it was sick anyway.
			_hitnow = [_originalhit, _currarmor, _highspeed] call FUNC_DAMAGEMODULE;*/
		};
			
		case "HitHead" : {};
		case "HitFace" : {};
		case "" : {
			_cancallhitback = true;
	
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
				
			};
				

				//{if(_x > 0.99) then {_hmul = 1;};}forEach((getAllHitPointsDamage _unit)select 2);
				
				
			};
		default {
			
		};
	};
		
	_dmg = _hitnow + _prevdmg;
		
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
	while{alive _unit} do {
		
		waitUntil{!(_tems isEqualTo (Items _unit))};
		[_unit] call FUNC_CHECKPLATE;
		_tems = Items _unit;
	};
	

	
};
