SCT_FUNC_OPENMGR = {
	
	waitUntil {!isNull (findDisplay 602)};
	params ["_unit","_container"];
	uiNamespace setVariable ["SCT_setupINV", [_unit, _container]];
	{
		((findDisplay 602) displayCtrl _x) ctrlAddEventHandler ["LBDblClick", "_t = lbText [ctrlIDC (_this select 0), _this select 1];
			if( _t == 'Vest Insert Manager') then {
			closeDialog 0;
			_handle = createDialog 'SCT_PLATE_MANAGER';
			_text = 'Ballistic protection Insert in your vest- select body part protection';
			((uiNamespace getVariable 'SCT_PLATE_MANAGER')displayCtrl 5970) CtrlSetText str _text;
		}; "]; 
	} forEach [633, 638, 619];
	((findDisplay 602) displayCtrl 640) ctrlAddEventHandler ["LBDblClick", "_t = lbText [ctrlIDC (_this select 0), _this select 1];
			if( _t == 'Vest Insert Manager') then {
			closeDialog 0;
			_handle = createDialog 'SCT_PLATE_MANAGER';
			_text = 'Ballistic protection Insert in this body - select body part protection';
			((uiNamespace getVariable 'SCT_PLATE_MANAGER')displayCtrl 5970) CtrlSetText str _text;
		}; "];
	
	if(typeOf _container == "SCT_virtualcargo") then {
		
	};
};


SCT_EventPut = {
	params ["_unit", "_container", "_item"];
	if(_item == "SonicT_Item_Base") then {
		_container removeItem _item;
	};
};

FUNC_RerouteAttachedObjs = {
	params ["_unit", "_posname", "_veh", "_boolturret"];
	
	/*if(_unit != vehicle _unit) then {
		{
			detach _x;
		}forEach attachedObjects _unit;
	
	}
	else{
		_arrayobj = _unit getVariable ["SCT_vest_attachedObjs", []];
		if(count _arrayobj > 0) then {
			{
				_obj = _x select 0;
				_hoffset = _x select 1;
				_voffset = _x select 2;
				_place = _x select 5;
				_obj attachTo [_unit, [0, _hoffset, _voffset], _place];
			}forEach _arrayobj;
		
		};
	};*/
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
		
		_garray = missionNamespace getVariable ["SCT_vest_enabledunits",[]];
		_unithash = count _garray; //make unit hash, to check out unit's item stats.
		_garray pushBack _unit;
		missionNamespace setVariable ["SCT_vest_enabledunits", _garray];
		_unit addMPEventHandler ["MPKilled",
		{_unit = _this select 0; }];
		_unit setVariable ["Init", 1];
		
		//_unit addEventHandler ["GetInMan", {_this call FUNC_RerouteAttachedObjs;}];
		//_unit addEventHandler ["GetOutMan", {_this call FUNC_RerouteAttachedObjs;}];
		_unit addEventHandler ["InventoryOpened", {_this spawn SCT_FUNC_OPENMGR;}];
		_unit addEventHandler ["Put", {_this call SCT_EventPut;}];
	};
	
	
} else{
	
};