FUNC_VestItemsOnDestroy = {
	_object = _this select 0;
	detach _object;
	_var = _object getVariable "SCT_obj_attachedTo";
	if(isNil "_var") exitWith {};
	_unit = _var select 0;
	_arrayobjs = _unit getVariable "SCT_vest_attachedObjs";
	_objindex = _arrayobjs find [_object, _var select 1, _var select 2, _var select 3, _var select 4, _var select 5];
	if( _objindex > -1) then {
		_v = _arrayobjs deleteAt _objindex;
		
		_unit setVariable ["SCT_vest_attachedObjs", _arrayobjs];
		_object setVelocity [0,0,-9.8];
	};
};

FUNC_VestHandleDamage = {
#include "SCT_PENETRATORS.hpp"
/*
	select 0 : unit: Object - Object the event handler is assigned to.
	select 1 : hitSelection: String - Name of the selection where the unit was damaged. "" for over-all structural damage, "?" for unknown selections.
	select 2 : damage - Resulting level of damage for the selection.
	select 3 : source: Object - The source unit that caused the damage.
	select 4 : projectile - Classname of the projectile that caused inflicted the damage. ("" for unknown, such as falling damage.)
	select 5 : hitPartIndex - Hit part index of the hit point, -1 otherwise.
	select 6 : instigator: Object - Person who pulled the trigger
	select 7 : hitPoint - hit point Cfg name
*/
	
	_object = _this select 0;
	_hitname = _this select 1;
	_hitindex = _this select 5;
	_totaldmg = _this select 2;
	_currdmg = _totaldmg - (_object getHitIndex _hitindex);
	
	systemChat format ["plate hit - where: %1, with damage %2, Overall damage : %3", _hitname, _currdmg, damage _object];
	
	_totaldmg
};

_object = _this select 0;
_object addMPEventHandler ["MPKilled", {_this call FUNC_VestItemsOnDestroy;}];

_object addEventHandler ["HandleDamage", {_this call FUNC_VestHandleDamage;}];