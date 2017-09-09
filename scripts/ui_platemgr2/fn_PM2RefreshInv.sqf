SCT_FilterAdd = {
	params["_info", "_filter", "_vehindex"];
	_magname = _info select 0;
	
	if(_magname isKindOf "SonicT_Item_Base_magtype") then {
		_magCount = _info select 1;
		_lbPic = getText (configFile >> "cfgMagazines" >> _magname >> "picture");
		_lbtext = getText (configFile >> "cfgMagazines" >> _magname >> "displayName");
		if(_filter == "All") then {
			lbAdd[5985, _lbtext + "(" + (str _count) + "%)"];
			lbSetData [5985, _vehindex, [typeOf _x, _magname, _magcount]];
			lbSetPicture [5985, _vehindex, _lbpic];
			_vehindex;
		}
		else{
			if(_info select 4 == _filter) then {
				lbAdd[5985, _lbtext + "(" + (str _count) + "%)"];
				lbSetData [5985, _vehindex, [typeOf _x, _magname, _magcount]];
				lbSetPicture [5985, _vehindex, _lbpic];
				_vehindex;
			};
		};
		
	};
};

_idc = ctrlIDC(_this select 0);
_index = _this select 1;
_text = lbText [_idc, _index];
_unit = uiNamespace getVariable ['SCT_setupINV', player];

lbClear 5986;
_allMags = magazinesAmmoFull _unit;
_vindex = 0;
{
	_vindex = [_x, _text, _vindex] call SCT_FilterAdd;
} forEach _allMags;