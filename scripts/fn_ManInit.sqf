SCT_FUNC_OPENMGR = {
	waitUntil {!isNull (findDisplay 602)};
	params ["_unit","_container"];
	uiNamespace setVariable ["SCT_setupINV", [_unit, _container]];
	//hint "this should func";
	disableSerialization;
	_disp = findDisplay 602;
	_bar = _disp ctrlCreate ["ToPlateMenu", 5971];
};

_unit = _this select 0;

//_unit globalChat "SCT mod enabled, reporting for duty";
if(isNil {_unit getVariable "Init"}) then {

	

	
	if(_unit isKindOf "CAManBase") then {
		if(isClass (configFile >> "CfgPatches" >> "ace_medical")) then {
		//_unit globalChat "ACEMOD enabled - overriding damage module";
			
			[_unit] spawn {
				params["_this"];
				sleep 2;
				_this removeAllEventHandlers "HandleDamage";
				[_this, 1] execVM "\SCT\addons\SonicT_vest\scripts\fn_Vestinit.sqf";	
			};
		}else{
			[_unit, 0] execVM "\SCT\addons\SonicT_vest\scripts\fn_Vestinit.sqf";
			
		};

		_unit addEventHandler ["InventoryOpened", {_this spawn SCT_FUNC_OPENMGR;}];	
		
		/*_unit addMPEventHandler ["MPKilled", {_unit = _this select 0; _var = _unit getVariable["SCT_EquippedPlates", []]; 
			_unit setVariable["AAPM_RespawnPlates", _var]; {[_unit, _forEachIndex]call SCT_fnc_DisableEquip;}forEach _var; }];
			
		_unit addMPEventHandler ["MPRespawn", {_unit = _this select 0; _var = _unit getVariable["AAPM_RespawnPlates",[]]; hint format ["%1 killed", _unit];
			{[_unit, _x select 0, _x select 1]call SCT_fnc_EquipPlate;}forEach _var;}];
		*/	
		_unit addMPEventHandler ["MPKilled", {
			_unit = _this select 0; _var = _unit getVariable["SCT_EquippedPlates", []];
			_unit setVariable["AAPM_RespawnPlates", _var];
			_v = "GroundWeaponHolder" createVehicle (position _unit);
			_v setPosASL (getPosASL _unit);
			{ 
				_v addMagazineAmmoCargo [_magname,1, _magcount];}forEach _var; 
			}];
			
		_unit addEventHandler ["Respawn", {_unit = _this select 0; _var = _unit getVariable["AAPM_RespawnPlates",[]]; hint format ["%1 killed", _unit];
			{[_unit, _x select 0, _x select 1]call SCT_fnc_EquipPlate;}forEach _var;}];
	};
	
	
} else{
	
};