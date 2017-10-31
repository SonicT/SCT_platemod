params["_unit", "_tem", "_HP", "_where"];

_Plateprot = _unit getVariable ["SCT_EquippedPlates" , []];

_num = -1;

if((count _Plateprot) > 0) then {

	{
		_name = _x select 0;
		_thp = _x select 1;
		
		if((_name isEqualTo _tem) && (_thp == _HP)) then {
			_num = _forEachIndex;
		};
	}forEach _Plateprot;
	
	if(_num > 0 ) then {
		_Plateprot deleteAt _num;
	};
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
	};
} else{
	if(_unit canAdd _magname) then {
		_unit addMagazine [_magname, _magcount];
	} else {
		if(local player) then {hint "item dropped on the ground, for you have no space to add.";};
		 _v = "GroundWeaponHolder" createVehicle (position _unit);
		 _v setPosASL (getPosASL _unit);
		 _v addMagazineAmmoCargo [_magname,1, _magcount];
	};
};