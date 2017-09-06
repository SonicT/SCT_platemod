_handle = createDialog "SCT_plate_Settings";

_traumapadedit = missionNameSpace getVariable ["SCT_PLATE_menu_TRAUMAPAD",128];
_rifledmgedit = missionNameSpace getVariable ["SCT_PLATE_menu_RiflePenet",2];
_debug = missionNameSpace getVariable ["SCT_PLATE_menu_DEBUG_Checkbox",false];

if(isServer) then {
	_traumapadedit = profileNameSpace getVariable ["SCT_PLATE_menu_TRAUMAPAD",128];
	_rifledmgedit = profileNameSpace getVariable ["SCT_PLATE_menu_RiflePenet",2];
	_debug = profileNameSpace getVariable ["SCT_PLATE_menu_DEBUG_Checkbox",false];
	
	if(_traumapad <= 0) then{
	_traumapad = 128;
	};

	if(_rifledmg <= 0 ) then {
		_rifledmg = 2;
	};
	
	missionNameSpace setVariable ["SCT_PLATE_menu_TRAUMAPAD",_traumapadedit];
	missionNameSpace setVariable ["SCT_PLATE_menu_RiflePenet",_rifledmgedit];
	missionNameSpace setVariable ["SCT_PLATE_menu_DEBUG_Checkbox",_debug];
};

((uiNamespace getVariable 'SCT_plate_Settings')displayCtrl 5965) CtrlSetText format ["%1",_traumapadedit];
((uiNamespace getVariable 'SCT_plate_Settings')displayCtrl 5966) CtrlSetText format ["%1", _rifledmgedit];
((uiNamespace getVariable 'SCT_plate_Settings')displayCtrl 5967) cbSetChecked _debug;