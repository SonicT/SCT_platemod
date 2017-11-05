/* idc reference 
	Body parts combobox = 5983;
	inventory finding combobox idc = 5984;
	Plates which are being used = 5985;
	Plates in inventory selected on combobox = 5986;

	activate plate button = 5987;
	disable and put plates to inventory = 5988;
	close window = 5989;
*/

lbClear 5985;
lbClear 5986;

_paramarr = uiNamespace getVariable ["SCT_setupINV", [player, objNull]];

_unit = _paramarr select 0;
_container = _paramarr select 1;

_parr = _unit getVariable ["SCT_EquippedPlates", []];

if((count _parr) > 0 ) then {
	{
		_magname = _x select 0;
		_hp = _x select 1;
		
		_index = _forEachIndex;
		
		_dispn = getText(configFile >> "CfgMagazines" >> _magname >> "displayName");
		_pic = getText(configFile >> "CfgMagazines" >> _magname >> "picture");
		_fhp = getNumber(configFile >> "CfgMagazines" >> _magname >> "count");
		
		_percent = round((_hp/_fhp) * 100);
		_num = lbAdd[5985, (format["%1(%2)",_dispn , _percent])];
		lbSetPicture[5985, _num, _pic];
		lbSetData [5985, _num, format["%1,%2,inner", _magname, _hp]];
	} forEach _parr;
}else {
	lbClear 5985;
};

if((lbCurSel 5984) != 1) then{
	_arrex = magazinesAmmo _unit;
	{
		_magname = _x select 0;
		_magcount = _x select 1;
		if(_magname isKindOf ["SonicT_Item_Base_magtype", configFile >> "cfgMagazines"]) then{
			_fhp = getNumber(configFile >> "CfgMagazines" >> _magname >> "count");
			_pic = getText(configFile >> "CfgMagazines" >> _magname >> "picture");
			_dispn = getText(configFile >> "CfgMagazines" >> _magname >> "displayName");
			_percent = round((_magcount/_fhp) * 100);
			
			_num = lbAdd[5986,format["%1(%2)",_dispn , _percent]];
			lbSetPicture[5986, _num, _pic];
			lbSetData [5986, _num, format["%1,%2,inner", _magname, _magcount]];
		};
	}forEach _arrex;
};

if((!(isNull _container)) && ((lbCurSel 5984) < 2)) then{
	_arrex = magazinesAmmoCargo _container;
	{
		_magname = _x select 0;
		_magcount = _x select 1;
		if(_magname isKindOf ["SonicT_Item_Base_magtype", configFile >> "cfgMagazines"]) then {
			_fhp = getNumber(configFile >> "CfgMagazines" >> _magname >> "count");
			_pic = getText(configFile >> "CfgMagazines" >> _magname >> "picture");
			_dispn = getText(configFile >> "CfgMagazines" >> _magname >> "displayName");
			_percent = round((_magcount/_fhp) * 100);
			
			_num = lbAdd[5986, format["%1(%2)",_dispn , _percent]];
			lbSetPicture[5986, _num, _pic];
			lbSetData [5986, format["%1,%2,outer", _magname, _magcount]];
		};
	}forEach _arrex;
};




