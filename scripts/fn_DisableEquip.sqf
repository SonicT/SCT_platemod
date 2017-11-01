params["_unit", "_num", "_where"];

_Plateprot = _unit getVariable ["SCT_EquippedPlates" , []];

if(isNil "_Plateprot") exitWith{};

_magname = (_Plateprot select _num) select 0;
_magcount = (_Plateprot select _num) select 1;

if((count _Plateprot) >=(_num + 1)) then {
	_Plateprot deleteAt _num;
	systemChat "deleteDO";
};

_unit setVariable ["SCT_EquippedPlates" , _Plateprot];

if(!isNil("_where")) then {
	if(_where canAdd _magname) then {
		_where addMagazineAmmoCargo [_magname, 1, _magcount];
	} else {
		if(local player) then {hint "item dropped on the ground, for the container have no space to add.";};
		 _v = "GroundWeaponHolder" createVehicle (position _unit);
		 _v setPosASL (getPosASL _unit);
		 _v addMagazineAmmoCargo [_magname,1, _magcount];
		 uiNamespace setVariable ["SCT_setupINV", [_unit, _v]];
	};
} else{
	if(_unit canAdd _magname) then {
		_unit addMagazine [_magname, _magcount];
	} else {
		if(local player) then {hint "item dropped on the ground, for you have no space to add.";};
		 _v = "GroundWeaponHolder" createVehicle (position _unit);
		 _v setPosASL (getPosASL _unit);
		 _v addMagazineAmmoCargo [_magname,1, _magcount];
		 uiNamespace setVariable ["SCT_setupINV", [_unit, _v]];
	};
};

