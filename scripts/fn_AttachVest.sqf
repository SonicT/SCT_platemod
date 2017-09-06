params ["_unit","_obj", "_place", "_horoffset", "_vertoffset","_hdir", "_vdir"];

if(isNil "_horoffset") then {_horoffset = 0;};
if(isNil "_vertoffset") then {_vertoffset = 0;};
if(isNil "_hdir") then {_hdir = 1;};
if(isNil "_vdir") then {_vdir = 1;};
if(isNil "_place") then {_place = "spine3";};
_originalp = _place;
_num2 = 0;


switch (_place) do {
	case "LShoulder" : {
		_arr = _unit getVariable ["SCT_part_LShoulder", []];
		_num2 = count _arr;
		_arr pushBack _obj;
		_unit setVariable ["SCT_part_LShoulder", _arr];
	};
	case "RShoulder" : {
		_arr = _unit getVariable ["SCT_part_RShoulder", []];
		_num2 = count _arr;
		_arr pushBack _obj;
		_unit setVariable ["SCT_part_RShoulder", _arr];
		_hdir = -_hdir;
		
	};
	case "Lside" : {
		_arr = _unit getVariable ["SCT_part_Lside", []];
		_num2 = count _arr;
		_arr pushBack _obj;
		_unit setVariable ["SCT_part_Lside", _arr];
		_place = "Pelvis";
		_vertoffset = 0.02;
	};
	case "Rside" : {
		_arr = _unit getVariable ["SCT_part_Rside", []];
		_num2 = count _arr;
		_arr pushBack _obj;
		_unit setVariable ["SCT_part_Rside", _arr];
		_place = "Pelvis";
		_hdir = -_hdir;
		_vertoffset = 0.02;
	};
	case "Pelvis" : {
		_arr = _unit getVariable ["SCT_part_Pelvis", []];
		_num2 = count _arr;
		_arr pushBack _obj;
		_unit setVariable ["SCT_part_Pelvis", _arr];
	};
	case "Lleg" : {};
	case "Rleg" : {};
	case "Front" : {
		_arr = _unit getVariable ["SCT_part_Front", []];
		_num2 = count _arr;
		_arr pushBack _obj;
		_unit setVariable ["SCT_part_Front", _arr];
		_place = "spine3";
		_horoffset = 0.0075;
		_vertoffset = -0.225;
	};
	case "Back" : {
		_arr = _unit getVariable ["SCT_part_Back", []];
		_num2 = count _arr;
		_arr pushBack _obj;
		_unit setVariable ["SCT_part_Back", _arr];
		_place = "spine3";
		_hdir = -_hdir;
		_horoffset = -0.02;
		_vertoffset = -0.175;
	};
	case "Head" : {};
	default {};
};


_arrayobj = _unit getVariable ["SCT_vest_attachedObjs", []];
_num = count _arrayobj;
_obj setVariable ["SCT_obj_attachedTo",[_unit, _num, _originalp, _num2]]; //save unit and index, to make them sure when deleting it.

_obj setVectorDirAndUp [[0,0,0], [0,0,1]];
_arrayobj pushBack [_obj, _place, _horoffset, _vertoffset, _hdir, _vdir];
_unit setVariable ["SCT_vest_attachedObjs", _arrayobj];