params["_unit", "_arr"];

if(isNil "_arr")then {
	_arr = _unit getVariable ["SCT_EquippedPlates", []];
};

_masstot = 0;
_formerCoef = _unit getVariable["SCT_VPCoef", 1];

{
	_name = _x select 0;
	
	_mass = getNumber(configFile >> "CfgMagazines" >> _name >> "mass");
	if(isNil("_mass")) then {_mass = 0};
	_masstot = _masstot + _mass;
}forEach _arr;

_orLoad = (_unit getUnitTrait "loadCoef")/_formerCoef;

_absLoad = getNumber (configFile >> "CfgInventoryGlobalVariable" >> "maxSoldierLoad");

_currCoef = _absLoad/(_absLoad - _masstot);

_unit setVariable["SCT_VPCoef", _currCoef];

_unit setUnitTrait["loadCoef", _orLoad * _currCoef];