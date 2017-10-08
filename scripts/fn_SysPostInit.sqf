



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
	


};
