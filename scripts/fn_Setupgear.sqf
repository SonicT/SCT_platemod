/* idc reference 
	Body parts combobox = 5983;
	inventory finding combobox idc = 5984;
	Plates which are being used = 5985;
	Plates in inventory selected on combobox = 5986;

	activate plate button = 5987;
	disable and put plates to inventory = 5988;
	close window = 5989;
*/
_unit = _this;
//_unit = uiNamespace getVariable ["SCT_setupINV", player];
closeDialog 0; //close all UI dialog. when this function spawned ingame, the dialogue will be SCT_PLATE_MANAGER.

//_plates = _unit getVariable [("SCT_part_" + _place),[]]; //get where you selected plate part.

//_ableParts = getArray(configFile >> "cfgWeapons" >> vest _unit >> "SCT_vest_objects" >> "enabledParts"); //code for future dev.

createDialog "SCT_PLATE_MANAGER_2";

waitUntil{!isNull (findDisplay 5981)};
disableSerialization;

_disp = findDisplay 5981;
_cbveh = _disp displayCtrl 5983;
_lbveh = _disp displayCtrl 5985;
_cbinv = _disp displayCtrl 5984;
_lbinv = _disp displayCtrl 5986;


lbAdd [5983, localize "STR_EquippedP"];
lbSetCurSel [5983, 0];

lbAdd [5984, localize "STR_SelAll"];
lbAdd [5984, localize "STR_ItemsEx"];
lbAdd [5984, localize "STR_ItemsInt"];

lbSetCurSel [5984, 0];

//_cbveh ctrlAddEventHandler [];
//_cbinv ctrlAddEventHandler [];
/*
_vc = "SCT_virtualcargo" createVehicle (position _unit);
_vc setPosASL (getPosASL _unit);
_vc setVariable ["SCT_virtualCargoRepresent", _place];

/*
_platearr = [];
{
	if(_x isKindOf "SCT_vest_base") then {
		_magname = getText (configFile >> "cfgVehicles" >> typeOf _x >> "SCT_veh_Info" >> "magazine");
		systemChat format ["plate of here %1 : %2", _place, _magname];
		_hp = 1 - (damage _x);
		_count = round (_hp * 100000);
		_vc addMagazineAmmoCargo [_magname, 1, _count];
		_platearr pushBack [_magname, _count];
	};
	
}forEach _plates;
_vc setVariable ["SCT_container_plates", _platearr];
_unit action ["Gear", _vc];

[_unit, _vc] spawn {
	params["_unit", "_veh"];
	_platearr = _veh getVariable "SCT_container_plates";
	_place = _veh getVariable "SCT_virtualCargoRepresent";
	if(isNil "_place") exitWith {hint "NIL error : no place data";};
	_del = false;
	while{!_del} do {
		
		_currmag = magazinesAmmoCargo _veh;
		_currarmor = [];
		{
			_typename = _x select 0;
			if(_typename isKindOf "SCT_container_plates") then {
				_currarmor pushBack _x;
			};
		}forEach _currmag;
		if(!(_platearr isEqualTo _currarmor)) then {
			systemChat format ["_currmag = %1, _platearr = %2, adjusting", _currmag, _platearr];
			
			_platearr = _currmag;
			//_veh setVariable ["SCT_container_plates", _platearr];
		};
		
		_del = _veh getVariable ["SCT_delcargo", false];
	};
	_veh setVariable ["SCT_container_plates", _platearr];

	deleteVehicle _veh;
};*/
