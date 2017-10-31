/* idc reference 
	Body parts combobox = 5983;
	inventory finding combobox idc = 5984;
	Plates which are being used = 5985;
	Plates in inventory selected on combobox = 5986;

	activate plate button = 5987;
	disable and put plates to inventory = 5988;
	close window = 5989;
*/

_paramarr = uiNamespace getVariable ["SCT_setupINV", [player, objNull]];

_unit = _paramarr select 0;
_container = _paramarr select 1;


_index = lbCurSel 5985;
_String = (lbData[5985, _index]) splitString ",";
hint str _String;
_magname = _String select 0;
_magcount = parseNumber (_String select 1);

_where = _String select 2;

if(_where isEqualTo "outer") then{
	[_unit, _magname, _magcount, _container] call SCT_fnc_DisableEquip;
}else{
	[_unit, _magname, _magcount] call SCT_fnc_DisableEquip;
};

lbDelete[5985, _index];