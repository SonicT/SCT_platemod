params["_unit", "_tem", "_HP"];


_Plateprot = _unit getVariable ["SCT_EquippedPlates" , []];
_count = getNumber(configFile >> "CfgMagazines" >> _tem >> "count");


if(_HP <0) then {
	_HP = _count;
};

_Plateprot pushBack [_tem, _HP];

_unit setVariable["SCT_EquippedPlates", _Plateprot];