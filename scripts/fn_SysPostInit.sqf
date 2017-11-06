



if(isServer && !isDedicated && !isNull player) then {

	player createDiarySubject ["SCT_VestFnc","SCT_options"];

	player createDiaryRecord ["SCT_VestFnc", ["Help/Credits", "

	<br/><br/>
	Made by Sonic.T. referenced from : RHS, CBA, ACE, and much more mods.
	"]];
	player createDiaryRecord ["SCT_VestFnc", ["Settings", ("
	<br/>
	Click Below to Adjust Settings.<br/>
	<font color='#CC0001'><execute expression = 'call SCT_fnc_OpenSettings'>Options</execute></font color>
	")]];
	/*
	_killdropeventid = addMissionEventHandler ["EntityKilled",{
			_unit = _this select 0; _var = _unit getVariable["SCT_EquippedPlates", []];
			_unit setVariable["AAPM_RespawnPlates", _var];
			hint format ["unit %1 should dropt items %2", _unit, _var];
			_v = "GroundWeaponHolder" createVehicle (position _unit);
			_v setPosASL (getPosASL _unit);
			{ 
				_v addMagazineAmmoCargo [_magname,1, _magcount];
			}forEach _var; 
		} ];
*/
};
