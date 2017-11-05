params["_unit", "_tem", "_HP"];

if(isNil("_tem")) exitWith{};

_Plateprot = _unit getVariable ["SCT_EquippedPlates" , []];
_count = getNumber(configFile >> "CfgMagazines" >> _tem >> "count");


if(_HP <0) then {
	_HP = _count;
	systemChat format ["%1 magtype init : %2", _tem, _HP];
};

_Plateprot pushBack [_tem, _HP];

_unit setVariable["SCT_EquippedPlates", _Plateprot];
[_unit, _Plateprot] call SCT_fnc_virtualLoad;