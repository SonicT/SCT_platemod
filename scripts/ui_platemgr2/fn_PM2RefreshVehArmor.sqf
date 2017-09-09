/* idc reference 
	Body parts combobox = 5983;
	inventory finding combobox idc = 5984;
	Plates which are being used = 5985;
	Plates in inventory selected on combobox = 5986;

	activate plate button = 5987;
	disable and put plates to inventory = 5988;
	close window = 5989;
*/

_idc = ctrlIDC(_this select 0);
_index = _this select 1;
_text = lbText [_idc, _index];
_unit = uiNamespace getVariable ['SCT_setupINV', player];
//hint format ['change info : idc - %1, origin %2, index %3, %4 \n owned by %5', _idc, _this select 0, _index, _text, _unit];

lbClear 5985;
_plates = _unit getVariable [("SCT_part_" + _text),[]];
_vehindex = 0;
{
	
	if(_x isKindOf "SCT_vest_base") then {
	_magname = getText (configFile >> "cfgVehicles" >> typeOf _x >> "SCT_veh_Info" >> "magazine");
	_lbtext = getText (configFile >> "cfgMagazines" >> _magname >> "displayName");
	_lbpic = getText (configFile >> "cfgMagazines" >> _magname >> "picture");
	_hp = 1 - (damage _x);
		
	_magcount = round (_hp * 100000);
	_count = round (_magcount / 1000);
	lbAdd[5985, _lbtext + "(" + (str _count) + "%)"];
	lbSetData [5985, _vehindex, [_x, _magname, _magcount]];
	lbSetPicture [5985, _vehindex, _lbpic];
		
	_vehindex = _vehindex + 1;
	};
}forEach _plates;