//I doubt this moethod will cause heavy system load, but I also think it is neccessary proccess for smooth interplation.
params ["_unit"];
	_uinv = uniformItems _unit;
	_vinv = vestItems _unit;
	
	_num = {_x == "SonicT_Item_Base"} count _uinv;
	if(_num == 0) then {
		_unit addItemToUniform "SonicT_Item_Base";
	}
	else {
		if( _num > 1) then {
			for [{_i=0}, {_i < _num}, {_i = _i + 1}] do {
				_unit removeItemFromUniform "SonicT_Item_Base";
			};
		};
	};
	_num = {_x == "SonicT_Item_Base"} count _vinv;
	if(_num == 0) then {
		_unit addItemToVest "SonicT_Item_Base";
	}
	else {
		if( _num > 1) then {
			for [{_i=0}, {_i < _num}, {_i = _i + 1}] do {
				_unit removeItemFromVest "SonicT_Item_Base";
			};
		};
	};

	
	
	_objs = _unit getVariable "SCT_vest_attachedObjs";
	if(isNil "_objs") exitWith{};

	_diaphpos = _unit modelToWorldVisualWorld(_unit selectionPosition "Spine3");
	_neckpos = _unit modelToWorldVisualWorld(_unit selectionPosition "Neck");
	_slpos = _unit modelToWorldVisualWorld(_unit selectionPosition "LeftShoulder");
	_srpos = _unit modelToWorldVisualWorld(_unit selectionPosition "RightShoulder");
	_shoulderposcentre = (_slpos vectorAdd _srpos)vectorMultiply 0.5;
	_abspos = _unit modelToWorldVisualWorld(_unit selectionPosition "Pelvis");
	_femurl = _unit modelToWorldVisualWorld(_unit selectionPosition "lfemur");
	_femurr = _unit modelToWorldVisualWorld(_unit selectionPosition "rfemur");
	_rknee = _unit modelToWorldVisualWorld(_unit selectionPosition "rknee");
	_lknee = _unit modelToWorldVisualWorld(_unit selectionPosition "lknee");
	
	_vector1 = _slpos vectorDiff _abspos;
		
	_vector2 = _srpos vectorDiff _abspos;
	_vector3 = [((_vector1 select 1)*(_vector2 select 2))- ((_vector1 select 2)*(_vector2 select 1))
		,((_vector1 select 2)*(_vector2 select 0))- ((_vector1 select 0)*(_vector2 select 2)),
		((_vector1 select 0)*(_vector2 select 1))- ((_vector1 select 1)*(_vector2 select 0))];
	_finalvector = vectorNormalized _vector3;
	
	//_upvector = _diaphpos vectorFromTo _neckpos;
	_upvector = _diaphpos vectorFromTo _shoulderposcentre;
	_upvectordn = _abspos vectorFromTo _diaphpos;
	_shoulderLtoR = vectorNormalized(_slpos vectorFromTo _srpos);
	_upvecShoulderL = vectorNormalized((_unit modelToWorldVisualWorld(_unit selectionPosition "lelbow"))vectorFromTo _slpos);
	_upvecShoulderR = vectorNormalized((_unit modelToWorldVisualWorld(_unit selectionPosition "relbow"))vectorFromTo _srpos);
	
	_dvec1 = _lknee vectorFromTo _femurl;
	_dvec2 = _rknee vectorFromTo _femurr;
	

	{
		_obj = _x select 0;
		_hdir = _x select 4;
		_hoffset = _x select 2;
		_voffset = _x select 3;
		_vdir = _x select 5;
		_place = _x select 1;
		
		
		
		switch (_place) do {
			case "Shoulders" : {_place = _shoulderposcentre;};
			
			case "spine3" : {
				_place = (_diaphpos) vectorAdd (_shoulderLtoR vectorMultiply 0.007);
				_obj setVectorDirAndUp [_finalvector vectorMultiply _hdir, _upvector vectorMultiply _vdir];
			};
			
			case "Lshoulder" : {
				_place = _slpos;
				_obj setVectorDirAndUp [(_shoulderLtoR) vectorMultiply (_hdir* (-1)), _upvecShoulderL vectorMultiply _vdir];
			};
			
			case "Rshoulder" : {
				_place = _slpos;
				_obj setVectorDirAndUp [(_shoulderLtoR) vectorMultiply _hdir, _upvecShoulderR vectorMultiply _vdir];
			};
			
			case "Pelvis" : {
				_place = _abspos;
				_obj setVectorDirAndUp [_finalvector vectorMultiply _hdir, _upvectordn vectorMultiply _vdir];
			};
			
			case "Lleg" : {
				_place = _lknee;
				_obj setVectorDirAndUp [_finalvector vectorMultiply _hdir, _dvec1 vectorMultiply _vdir];
			};
			
			case "Rleg" : {
				_place = _rknee;
				_obj setVectorDirAndUp [_finalvector vectorMultiply _hdir, _dvec2 vectorMultiply _vdir];
			};
			
			default {
				_place = _unit modelToWorldVisualWorld(_unit selectionPosition _place);
				_obj setVectorDirAndUp [_finalvector vectorMultiply _hdir, _upvector vectorMultiply _vdir];
			};
		};
		_obj setPosASL (_place vectorAdd (_finalvector vectorMultiply _hoffset) vectorAdd (_upvector vectorMultiply _voffset));
				
				
	}forEach _objs;
