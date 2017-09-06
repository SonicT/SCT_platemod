#include "SCT_PENETRATORS.hpp"

params ["_unit", "_ace"];



FUNC_OVERHAULARMOR = {
	params["_hitpoint"];
	_newhitpoint = 5;
	if(_hitpoint > 8) then{_newhitpoint = 8 + (_hitpoint /64)} else { _newhitpoint = _hitpoint};
	_newhitpoint
};

FUNC_DAMAGEMODULE = {
	params ["_impact","_armor", "_penet" , "_type"];
	_traumapadedit = missionNameSpace getVariable ["SCT_PLATE_menu_TRAUMAPAD",128];
	_debug = missionNameSpace getVariable ["SCT_PLATE_menu_DEBUG_Checkbox",false];
	_dam = 0; //return 0 when if- scope does not work
	_humandam = 5+ (3.48*_penet* _penet); // divider for adjusting human flesh
	_impactdam = ((_impact - _armor)/_humandam)max (_impact /(_traumapadedit + 32*_type));
	_penetval = _penet*(_impact + _type)- _armor; //this can have minus value.
	_penetdam = (_penetval/(_humandam)) max 0; //internal penetrating damage
	_dam = _impactdam + _penetdam;
		/*	*damage module explanation : if armor cannot hold impact itself, impact will be just go through to body, except armor absorbtion. x0.8 for least shieding.
			*bullet punch : if armor holded whole impact damage, 
			* *0.6 in penetration : penet damage should not be that big.
			* +2 in penetration : vanilla .45cal hit is 8, and 5.45 is 7 - but 5.45 penets iiia armor for 4-5 layers in real world... in ACE3mod situation got worse. carbines have less damage..  so made offset.
			*penetration : if penetration value is high, it is more likely to penetrate armor
		*/
	/*if(_impact > (2 * _armor)) then {
		_dam = _impact - (_armor*0.5); //no _impact - (_armor * 2 )? i will see arma3's buggy engine would make it penetrable....
	}else {
		
	};*/
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
	_armorvesthitpoint = [0,0,0,0,0,0,0];
		
		
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
	_arrayp = [];
	{    
	_front = true;
		if(_x isKindof ["SonicT_Item_Base", configFile >> "cfgWeapons"]) then{    
			switch (_x) do{ 
				
				case "SCT_plate_ceramic_esapi" : { 
					_arrayp pushBack "ESAPI NIJ IV ceramic ICW soft body armor";
					[_unit, _x] spawn {
						params ["_unit", "_vest"];
						waitUntil{!isNil{missionNamespace getVariable "SCT_init"}};
						
						_unit removeItemFromVest _vest;
						_objs1 = "SCT_esapi_side" createVehicle (position _unit); 
						[_unit, _objs1,"Lside"] call SCT_fnc_AttachVest;
						_objs2 = "SCT_esapi_side" createVehicle (position _unit); 
						[_unit, _objs2,"Rside"] call SCT_fnc_AttachVest;
						_obj1 = "SCT_vest_base" createVehicle (position _unit);
						[_unit, _obj1,"Back"] call SCT_fnc_AttachVest;
						_obj2 = "SCT_vest_base" createVehicle (position _unit);
						[_unit, _obj2,"Front"] call SCT_fnc_AttachVest;
					};
					
				};    
				case "SCT_plate_steel_ar5001" : {    
					_arrayp pushBack "AR500 NIJ III 'plus' steel standalone";
				};    
				case "SCT_plate_poly_DFNDR" : {    
					_arrayp pushBack "DFNDR NIJ III '2plus' polyethylene standalone";    
				};    
				default {};    
			};
		};
		
	}forEach (vestItems _this);
	//if there is no plate in your vest, the array saves 'no plate'
	if(count _arrayp < 1) then {
		_arrayp pushBack [0,0, "No plate", 0];
	};
	
	/*
	//Make overhauled armor.
	_overhaularmor = _hitprotection apply {[_x] call FUNC_OVERHAULARMOR};
	if((isPlayer _unit) && (local _unit) && _debug) then {
		if(isNil{_unit getVariable "SCT_ARMORSTAT"}) then {
			hintSilent format ["        Armor Equipment\n\nuniform : %1\n    vest : %2\n   plate : %3 \n     Protection Values\n\n       Neck : %4\n      Arms : %5\nChest : %6\n Diaphragm : %7\n   Abdomen : %8\n     Pelvis : %9\n       Legs : %10", _uniform, _vest,(_arrayp select 0) select 2, _overhaularmor select 0, _overhaularmor select 1, (_overhaularmor select 2) + ((_arrayp select 0) select 1), (_overhaularmor select 3) + ((_arrayp select 0) select 1), (_overhaularmor select 4) + ((_arrayp select 0) select 1), _overhaularmor select 5, _overhaularmor select 6];
		} else{ if(!((_unit getVariable "SCT_ARMORSTAT")isEqualTo _arrayp)) 
			then {
					hintSilent format ["        Armor Equipment\n\nuniform : %1\n    vest : %2\n   plate : %3 \n     Protection Values\n\n       Neck : %4\n      Arms : %5\nChest : %6\n Diaphragm : %7\n   Abdomen : %8\n     Pelvis : %9\n       Legs : %10", _uniform, _vest,(_arrayp select 0) select 2, _overhaularmor select 0, _overhaularmor select 1, (_overhaularmor select 2) + ((_arrayp select 0) select 1), (_overhaularmor select 3) + ((_arrayp select 0) select 1), (_overhaularmor select 4) + ((_arrayp select 0) select 1), _overhaularmor select 5, _overhaularmor select 6];

			};
		};
	};
	*/

	_this setVariable["SCT_ARMORSTAT", _arrayp];
	_this setVariable ["SCT_BaseArmor", _hitprotection];
	
};
   
    
    
FUNC_EVENTDMGHANDLE = { 

	_rifledmg = missionNameSpace getVariable ["SCT_PLATE_menu_RiflePenet",2];
	_debug = missionNameSpace getVariable ["SCT_PLATE_menu_DEBUG_Checkbox",false];
		 
	_unit = _this select 0;
	_cancallhitback = false;

	_basearmor = _unit getVariable "SCT_BaseArmor";

	if(isNil "_armorstat") then {_armorstat = [0,0, "no armor"]};
	if(isNil "_basearmor") then {_basearmor = [2, 10, 2, 2, 2 ,12,10];}; //if basearmor is Nil return to vanilla civilian default.
	

	_shooter = _this select 3;
	_dmg = _this select 2;
	_hitnum = _this select 5;
	//infantry hitselection number 0 : face_hub, 1: neck, 2 : head, 3 : pelvis, 4 : spine1, 5 : spine2, 6 : spine3, 7 : body, 8 : arms, 9: hands, 10 : legs
	_dmgfrom = _this select 4;
	_hitpoint = _this select 7;
	_prevdmg = _unit getHitIndex _hitnum;


	_hitnow = _dmg - _prevdmg; //know current damage
	_originalhit = _hitnow;
	if(getNumber (configFile >> "cfgAmmo" >> _dmgfrom >> "typicalSpeed") > 600) then {_highspeed = _rifledmg;} else{_highspeed = 0;}; // penetrates soft armor, multiplying dmg
	//implement damage description model
	
	
	switch (_hitpoint) do {
			
			
			
		case "HitNeck" : {
			_selectionarmor = _basearmor select 0;
			_originalhit = _hitnow * _selectionarmor; //revert to original bullet damage, not divided by armor protection.... it was sick anyway.
						
		};
		case "HitArms" : {
			_selectionarmor = _basearmor select 1;
			_originalhit = _hitnow * _selectionarmor; //revert to original bullet damage, not divided by armor protection.... it was sick anyway.
							
		};
		case "HitChest" : {
			_selectionarmor = _basearmor select 2;
			_originalhit = _hitnow * _selectionarmor; //revert to original bullet damage, not divided by armor protection.... it was sick anyway.
				
		};
		case "HitDiaphragm" : {
			_selectionarmor = _basearmor select 3;
			_originalhit = _hitnow * _selectionarmor; //revert to original bullet damage, not divided by armor protection.... it was sick anyway.
		};
		case "HitAbdomen" : {
			_selectionarmor = _basearmor select 4;
			_originalhit = _hitnow * _selectionarmor; //revert to original bullet damage, not divided by armor protection.... it was sick anyway.
		};
		case "HitPelvis": {
			_selectionarmor = _basearmor select 5;	
			_originalhit = _hitnow * _selectionarmor; //revert to original bullet damage, not divided by armor protection.... it was sick anyway.
		};
		case "HitLegs" : {
			_selectionarmor = _basearmor select 6;
			_originalhit = _hitnow * _selectionarmor; //revert to original bullet damage, not divided by armor protection.... it was sick anyway.
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
			/*if(((_unit getHitPointDamage "HitArms") > 0.8) or ((_unit getHitPointDamage "HitLegs") >0.85)) then {
				_hitnow = 0.08+_hitnow;
			}else{
				_hitnow = 0;
			};*/
			//because vr targets have different hitpoints, and "hitleg" and "hitarms" placed weired place, so it need to be re-align.
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
	_originalhitclamp = [_unit, _originalhit] call {params ["_unit", "_originalhit"]; _goback = 0; if(_originalhit > 80) then {_goback = 80 + (_originalhit * 0.01);} else {_goback = _originalhit}; _goback};
	_force = _dir vectorMultiply (_originalhitclamp/16);
	_vel = velocity _unit;
	if((_dmgfrom isKindOf "TimeBombCore") or (_dmgfrom isKindOf "GrenadeCore")or (_dmgfrom isKindOf "FuelExplosion")) then {
		_force set [2, abs(_force select 2) * 3];
		_dir set [2, 3 * abs(_dir select 2) +3];
	}else {
		if(_dmgfrom isKindOf "Grenade") then {
			_force = _dir vectorMultiply _originalhitclamp;
			_force set [2, 0.5 + abs(_force select 2) * 3];
			_dir set [2, abs(_dir select 2) +3];
		};
	
	};
	_nvel = [(_vel select 0) + ((_force select 0)/(1 + abs(_vel select 0))), (_vel select 1) + ((_force select 1)/(1 + abs(_vel select 1))), (_vel select 2) + (2*(_force select 2)/(1 + abs(_vel select 2)))];
	
	
	if(alive _unit) then {
		_unit setVelocity _nvel;
	}else {
		if(_cancallhitback) then{
			//[_unit, _dir, _originalhit/16]call SCT_fnc_Hitpush; //dev stage.
		};
			
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
	_uniform = uniform _unit;
	_vestitem = vestItems _unit;
	_vest = vest _unit;
	while{alive _unit} do {
		waitUntil{(!(_vestitem isEqualTo(vestItems _unit))) or (!(_vest isEqualTo(vest _unit))) or (!(_uniform isEqualTo (uniform _unit)))};
		[_unit] call FUNC_CHECKPLATE;
		_vestitem = vestItems _unit;
		_vest = vest _unit;
		_uniform = uniform _unit;
	};
	

	
};
