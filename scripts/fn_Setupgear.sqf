params["_place"];
_arr = uiNamespace getVariable ["SCT_setupINV", [player, player]];
_unit = _arr select 0;
_cargo = _arr select 1;
closeDialog 0;
_vc = "SCT_virtualcargo" createVehicle (position _unit);
_vc setPosASL (getPosASL _unit);
_vc setVariable ["SCT_virtualCargoRepresent", _place];
_plates = _unit getVariable [("SCT_part_" + _place),[]];
/*
[_vc, [_unit, "SCT_parts_inv_" + _place],
"inheritsFrom (configFile >> 'cfgMagazines' >> 'SonicT_Item_Base_magtype')" configClasses (configFile >> "cfgMagazines")
] call BIS_fnc_loadInventory;
*/
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
	/*
	_hint = [_veh, [_unit, "SCT_parts_inv_" + _place]] call BIS_fnc_saveInventory;
	hint format ["saved load :\n  %1", _hint];
	*/
	deleteVehicle _veh;
};
