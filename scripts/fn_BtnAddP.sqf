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

_parr = _unit getVariable ["SCT_EquippedPlates", []];

_index = lbCurSel 5986;
_String = (lbData[5986, _index]) splitString ",";
hint str _String;
_magname = _String select 0;
_magcount = parseNumber (_String select 1);

_where = _String select 2;

if((_where isEqualTo "outer") && ! (isNull _container)) then {
	_num = -1;
	
	_itemarr = magazinesAmmoCargo _container;
	{
		_name = _x select 0;
		_ccount = _x select 1;
		
		if((_name isEqualTo _magname) && (_magcount == _ccount)) then {
			_num = _forEachIndex;
		};
	}forEach _itemarr;
	
	if(_num > 0) then {
		_itemarr deleteAt _num;
		clearMagazineCargo _container;
		{
			_container addMagazineAmmoCargo [_x select 0, 1, _x select 1];
		
		}forEach _itemarr;
		
	};
};

if(_where isEqualTo "inner") then {
	_itemarr = magazinesAmmo _unit;
	{
		_name = _x select 0;
		_ccount = _x select 1;
		
		if((_name isEqualTo _magname) && (_magcount == _ccount)) exitWith {
			_num = _forEachIndex;
		};
	}forEach _itemarr;
	
	if(_num > 0) then {
		_itemarr deleteAt _num;
		_ritems = items _unit;
		
		removeAllItemsWithMagazines _unit;
		
		{
			_unit addItem _x;
		}forEach _ritems;
		
		{
			_unit addMagazine [_x select 0, _x select 1];
		}forEach _itemarr;
	};
	
	
};//not done yet


[_unit, _magname, _magcount] call SCT_fnc_EquipPlate;