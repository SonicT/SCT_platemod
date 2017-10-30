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
	};
	
	
} else{
	
};