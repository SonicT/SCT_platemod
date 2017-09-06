
FUNC_UpdateAttachPos = {

//I doubt this mothod will cause heavy system load, but I also think it is neccessary proccess for smooth interplation.
	_targets = missionNameSpace getVariable ["SCT_vest_enabledunits", []];
	if((isNil "_targets") or (count _targets < 1)) exitWith{};
	{
		[_x] call SCT_fnc_UpdateAttachPos;
	}forEach _targets;
};



if(isServer) then {
	
	if(!isDedicated && !isNull player) then {
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
	};
	
	
	["6974SCTVEST", "onEachFrame", {call FUNC_UpdateAttachPos}] call BIS_fnc_addStackedEventHandler;
	missionNamespace setVariable ["SCT_init",true];
};
