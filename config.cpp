#ifndef SCT_ARMOR_RATINGS
#define SCT_ARMOR_RATINGS 1
#define SCT_NIJII_CMASS 20
#define SCT_NIJII_ARMOR 8
#define SCT_NIJIIIA_CMASS 25
#define SCT_NIJIIIA_ARMOR 15
#define SCT_NIJIII_ARMOR 30
#define SCT_NIJIV_ARMOR 48
#define SCT_LITE_TRAUMAPAD 0.15
#define SCT_TRAUMAPAD 0.1
#endif

class CfgPatches {

	class SonicT_Items {
		units[] = {};
		weapons[] = {"SonicT_Item_Base",
			"SCT_plate_ceramic_esapi",
			"SCT_plate_steel_ar5001",
			"SCT_plate_poly_DFNDR"
			};
		requiredVersion = 1.550000;
		version = 0.400000;
		requiredAddons[] = {
			"A3_Data_F",
			"A3Data",
			"A3_Characters_F",
			"A3_Weapons_F",
			3den
			};
		author = "Sonic.T";
		fileName = "SonicT_vest.pbo";
	};
	
	class SCTEVENT : SonicT_Items {
		author = "";
		weapons[] = {};
	};

};

class CfgMods{
	class Mod_Base;
	class SCT_ARMOR{
		author = "Sonic.T";
		picture = "\SCT\sonict.paa";
		logo = "\SCT\sonict.paa";
		logoOver = "\SCT\sonict.paa";
		logoSmall = "\SCT\sonict.paa";
		dlcColor[] = {0, 0, 0, 1};
		tooltip = "SCT Armor Plate";
		tooltipOwned = "Sonic.T";
		name = "Sonic.T's modern - future plate armor mod";
		overview = "stuff hard armor plates in your vest, to make sure your safety";
		dir = "SCT";
	};
};

//making additional custom 'init' eventhandler.
class SCTEVTEX_base {
	init = "[_this select 0]execVM '\SCT\addons\SonicT_vest\scripts\fn_ManInit.sqf';";
};

class SCTEVENT : SCTEVTEX_base{};

class DefaultEventhandlers {
	class SCTEVENT : SCTEVTEX_base {};
};

class CfgFunctions{
	class SCT{
		class VestFnc {
			file = "SCT\addons\SonicT_vest\scripts";
			class SysPreInit{
				preInit = 1;
				description= "Sonict system initialization codes";
			};
			class SysPostInit{
				postInit = 1;
				description = "make settings bar on the map";
			};
			class ManInit{
				description="Sonict vest initializing manbase units";
			};
			class UserConfig {};
			
			class ChangeSettings {
				preInit = 1;
			};
			
			class OpenSettings {};
			class Hitpush{};
			class UpdateAttachPos{};
			class AttachVest{};
			class Setupgear{};
			
		};
	};
};

//to make option menus on the map, with CBA free.

class RscPicture;	// External class reference
class RscProgressBar;	// External class reference
class RscStructuredText;	// External class reference
class RscText;	// External class reference
class RscEdit;	// External class reference
class RscButton;	// External class reference
class RscListbox;	// External class reference
class RscObject;	// External class reference
class RscCombo;	// External class reference
class IGUIBack;	// External class reference
class RscSlider;	// External class reference
class RscCheckbox;	// External class reference

class SCT_PLATE_SETTINGS {
	idd = 5964;
	movingEnable = 1;
	enableSimulation = 1;
	onLoad = "uiNamespace setVariable ['SCT_plate_Settings', (_this select 0)]";
	
	class controls {
		class SCT_PLATE_menu_BackGround : IGUIBack {
			idc = -1;
			x = "0.396875 * safezoneW + safezoneX";
			y = "0.291 * safezoneH + safezoneY";
			w = "0.20625 * safezoneW";
			h = "0.242 * safezoneH";
			colorBackground[] = {0, 0, 0, 1};
			colorText[] = {1, 1, 1, 1};
		};
		
		class SCT_PLATE_menu__Header : RscText {
			idc = -1;
			text = "Sonic.T's Armor Plate Settings";
			x = "0.396875 * safezoneW + safezoneX";
			y = "0.291 * safezoneH + safezoneY";
			w = "0.20625 * safezoneW";
			h = "0.033 * safezoneH";
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.69])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.75])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.5])", 0.7};
			colorText[] = {1, 1, 1, 1};
		};
		
		class SCT_PLATE_menu_TRAUMAPAD : RscText {
			idc = -1;
			text = "PADdmg:";
			x = "0.428125 * safezoneW + safezoneX";
			y = "0.357 * safezoneH + safezoneY";
			w = "0.0567187 * safezoneW";
			h = "0.022 * safezoneH";
			colorText[] = {1, 1, 1, 1};
		};
		
		class SCT_PLATE_menu_RiflePenetDefault : RscText {
			idc = -1;
			text = "PnetDMG:";
			x = "0.428125 * safezoneW + safezoneX";
			y = "0.401 * safezoneH + safezoneY";
			w = "0.0567187 * safezoneW";
			h = "0.022 * safezoneH";
			colorText[] = {1, 1, 1, 1};
		};
		
		class SCT_PLATE_menu_DEBUG : RscText {
			idc = -1;
			text = "Indicators";
			x = "0.448438 * safezoneW + safezoneX";
			y = "0.445 * safezoneH + safezoneY";
			w = "0.0670312 * safezoneW";
			h = "0.022 * safezoneH";
			colorText[] = {1, 1, 1, 1};
		};
		
		class SCT_PLATE_menu_TRAUMAPAD_Edit : RscEdit {
			idc = 5965;
			text = 128;
			x = "0.494844 * safezoneW + safezoneX";
			y = "0.357 * safezoneH + safezoneY";
			w = "0.0567187 * safezoneW";
			h = "0.022 * safezoneH";
			tooltip = "damage divider for stopped bullet";
		};
		
		class SCT_PLATE_menu_RiflePenet_Edit : RscEdit {
			idc = 5966;
			text = 2;
			x = "0.494844 * safezoneW + safezoneX";
			y = "0.401 * safezoneH + safezoneY";
			w = "0.0567187 * safezoneW";
			h = "0.022 * safezoneH";
			tooltip = "FMJ penet multiplier";
		};
		
		class SCT_PLATE_menu_DEBUG_Checkbox : RscCheckbox {
			idc = 5967;
			x = "0.520625 * safezoneW + safezoneX";
			y = "0.445 * safezoneH + safezoneY";
			w = "0.0154688 * safezoneW";
			h = "0.022 * safezoneH";
			tooltip = "Apply settings";
		};
		
		class SCT_PLATE_menu_Apply : RscButton {
			idc = 5968;
			text = "Apply";
			x = "0.479375 * safezoneW + safezoneX";
			y = "0.489 * safezoneH + safezoneY";
			w = "0.0515625 * safezoneW";
			h = "0.033 * safezoneH";
			action = "call SCT_fnc_ChangeSettings; CloseDialog 0;";
			colorText[] = {1, 1, 1, 1};
			colorDisabled[] = {0, 0.6, 0, 1};
			colorBackground[] = {0, 0.6, 0, 1};
			colorBackgroundDisabled[] = {0, 0.6, 0, 1};
			colorBackgroundActive[] = {0, 0.5, 0, 1};
			colorFocused[] = {0, 0.5, 0, 1};
			colorShadow[] = {0, 0.3, 0, 1};
			colorBorder[] = {0, 0.3, 0, 1};
		};
		
		class SCT_PLATE_menu_Exit : RscButton {
			idc = -1;
			text = "X";
			x = "0.5825 * safezoneW + safezoneX";
			y = "0.291 * safezoneH + safezoneY";
			w = "0.020625 * safezoneW";
			h = "0.033 * safezoneH";
			action = "CloseDialog 0";
		};
	};
};

class SCT_PLATE_MANAGER{
	idd = 5969;
	movingEnalbed = 1;
	enableSimulation = 1;
	
	class controls{
		 class SCT_PLATE_MANAGER_BackGround : IGUIBack {
			idc = -1;
			x = "0.05 * safezoneW + safezoneX";
			y = "0.1 * safezoneH + safezoneY";
			w = "0.37 * safezoneW";
			h = "0.8 * safezoneH";
			colorBackground[] = {0, 0, 0, 0.8};
			colorText[] = {1, 1, 1, 1};
		};
		
		class SCT_PLATE_MANAGER_Header : RscText {
			idc = 5970;
			text = "Plate carrying pouch/rig";
			x = "0.05 * safezoneW + safezoneX";
			y = "0.1 * safezoneH + safezoneY";
			w = "0.375 * safezoneW";
			h = "0.033 * safezoneH";
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.69])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.75])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.5])", 0.7};
			colorText[] = {1, 1, 1, 1};
		};
		
		//armor stats to be seen RPG-like style.
		class SCT_PLATE_MANAGER_ITEM_HeadGear : RscPicture {
			idc = 5971;
			style = 48;
			text = "\SCT\addons\SonicT_vest\data\ui\cannot.paa";
			x = "0.18 * safezoneW + safezoneX";
			y = "0.25 * safezoneH + safezoneY";
			w = "0.100 * safezoneW";
			h = "0.1 * safezoneH";
			
		};
		

		class SCT_PLATE_MANAGER_ITEM_ShoulderL : RscButton {
			idc = 5972;
			style = 48;
			text = "\SCT\addons\SonicT_vest\data\ui\ui_ls01.paa";
			x = "0.1 * safezoneW + safezoneX";
			y = "0.375 * safezoneH + safezoneY";
			w = "0.0750 * safezoneW";
			h = "0.075 * safezoneH";
			action = "['LShoulder']call SCT_fnc_Setupgear;";
		};
		
		class SCT_PLATE_MANAGER_ITEM_ShoulderR : RscButton {
			idc = 5973;
			style = 48;
			text = "\SCT\addons\SonicT_vest\data\ui\ui_rs01.paa";
			x = "0.285 * safezoneW + safezoneX";
			y = "0.375 * safezoneH + safezoneY";
			w = "0.0750 * safezoneW";
			h = "0.075 * safezoneH";
			action = "['RShoulder']call SCT_fnc_Setupgear;";
		};

		class SCT_PLATE_MANAGER_ITEM_Front : RscButton {
			idc = 5974;
			style = 48;
			text = "\SCT\addons\SonicT_vest\data\ui\ui_front01.paa";
			x = "0.18 * safezoneW + safezoneX";
			y = "0.4 * safezoneH + safezoneY";
			w = "0.10 * safezoneW";
			h = "0.1 * safezoneH";
			action = "['Front']call SCT_fnc_Setupgear;";
		};

		class SCT_PLATE_MANAGER_ITEM_Back : RscButton {
			idc = 5975;
			style = 48;
			text = "\SCT\addons\SonicT_vest\data\ui\ui_back01.paa";
			x = "0.18 * safezoneW + safezoneX";
			y = "0.525 * safezoneH + safezoneY";
			w = "0.100 * safezoneW";
			h = "0.1 * safezoneH";
			action = "['Back']call SCT_fnc_Setupgear;";
		};
		
		class SCT_PLATE_MANAGER_ITEM_SideL : RscButton {
			idc = 5976;
			style = 48;
			text = "\SCT\addons\SonicT_vest\data\ui\ui_sidel01.paa";
			x = "0.1 * safezoneW + safezoneX";
			y = "0.525 * safezoneH + safezoneY";
			w = "0.0750 * safezoneW";
			h = "0.075 * safezoneH";
			action = "['Lside']call SCT_fnc_Setupgear;";
		};
		
		class SCT_PLATE_MANAGER_ITEM_SideR : RscButton {
			idc = 5977;
			style = 48;
			text = "\SCT\addons\SonicT_vest\data\ui\ui_sider01.paa";
			x = "0.285 * safezoneW + safezoneX";
			y = "0.525 * safezoneH + safezoneY";
			w = "0.0750 * safezoneW";
			h = "0.075 * safezoneH";
			action = "['Rside']call SCT_fnc_Setupgear;";
		};
	
		class SCT_PLATE_MANAGER_ITEM_Pelvis : RscButton {
			idc = 5978;
			style = 48;
			text = "\SCT\addons\SonicT_vest\data\ui\ui_pelv01.paa";
			x = "0.18 * safezoneW + safezoneX";
			y = "0.65 * safezoneH + safezoneY";
			w = "0.100 * safezoneW";
			h = "0.1 * safezoneH";
			action = "['Pelvis']call SCT_fnc_Setupgear;";
		};
	
		class SCT_PLATE_MANAGER_ITEM_LegL : RscButton {
			idc = 5979;
			style = 48;
			text = "\SCT\addons\SonicT_vest\data\ui\cannot.paa";
			x = "0.1 * safezoneW + safezoneX";
			y = "0.625 * safezoneH + safezoneY";
			w = "0.075 * safezoneW";
			h = "0.075 * safezoneH";
			
		};
	
		class SCT_PLATE_MANAGER_ITEM_LegR : RscButton {
			idc = 5980;
			style = 48;
			text = "\SCT\addons\SonicT_vest\data\ui\cannot.paa";
			x = "0.285 * safezoneW + safezoneX";
			y = "0.625 * safezoneH + safezoneY";
			w = "0.0750 * safezoneW";
			h = "0.075 * safezoneH";
			
		};

	};
};

class SCT_veh_Info {
	magazine = "";
	
};

class SCT_mag_Info {
	vehicle = "SCT_vest_base";
};

class CfgVehicles{
//for basic init. reference : CBA
	class Land;
	/*class Man: Land{
		class EventHandlers{
			class SCTEVENT : SCTEVTEX_base {};
		};
	};*/ // involving this will cause super rabbit or something
//followed CBA config but found they are partially enabled, so looked up original	
	class CAManBase {

		class EventHandlers {
			class SCTEVENT : SCTEVTEX_base {};
		};
	};
	class Civilian_F;
	class SoldierGB;
	class B_Soldier_base_F;
	class B_Soldier_02_f; //extern
	class B_Soldier_03_f;
	class B_CTRG_Soldier_3_F;	// External class reference
	
	class C_man_1: Civilian_F {

		class EventHandlers {
			class SCTEVENT : SCTEVTEX_base {};
		};
	};
	
	class B_RangeMaster_F: B_Soldier_base_F{
		class EventHandlers {
			class SCTEVENT : SCTEVTEX_base {};
		};
	};
	
	
	
	class B_Story_SF_Captain_F: B_Soldier_02_f{
		class EventHandlers {
			class SCTEVENT : SCTEVTEX_base {};
		};
	};
	
	class B_Story_Protagonist_F: B_Soldier_02_f{
		class EventHandlers {
			class SCTEVENT : SCTEVTEX_base {};
		};
	};
	
	class B_Story_Engineer_F: B_Soldier_base_F{
		class EventHandlers {
			class SCTEVENT : SCTEVTEX_base {};
		};
	};
	
	class B_Story_Pilot_F: B_Soldier_base_F{
		class EventHandlers {
			class SCTEVENT : SCTEVTEX_base {};
		};
	};
	
	class B_CTRG_soldier_GL_LAT_F: B_Soldier_base_F{
		class EventHandlers {
			class SCTEVENT : SCTEVTEX_base {};
		};
	};
	
	class B_CTRG_soldier_engineer_exp_F: B_Soldier_02_f{
		class EventHandlers {
			class SCTEVENT : SCTEVTEX_base {};
		};
	};
	

	
	class B_CTRG_soldier_M_medic_F: B_Soldier_03_f{
		class EventHandlers {
			class SCTEVENT : SCTEVTEX_base {};
		};
	};
	
	class B_CTRG_soldier_AR_A_F: B_Soldier_03_f{
		class EventHandlers {
			class SCTEVENT : SCTEVTEX_base {};
		};
	};
	
	class B_CTRG_Miller_F : B_CTRG_Soldier_3_F {
		class EventHandlers {
			class SCTEVENT : SCTEVTEX_base {};
		};
		
	};
	
	class C_man_hunter_1_F: C_man_1{
		class EventHandlers {
			class SCTEVENT : SCTEVTEX_base {};
		};
	};
	
	class C_man_pilot_F: C_man_1{
		class EventHandlers {
			class SCTEVENT : SCTEVTEX_base {};
		};
	};
	
	class C_journalist_F : C_man_1 {
		class EventHandlers {
			class SCTEVENT : SCTEVTEX_base {};
		};
		
	};
	
	class C_Orestes; //Extern
	
	class C_Nikos: C_Orestes{
		class EventHandlers {
			class SCTEVENT : SCTEVTEX_base {};
		};
	};
	
	class I_G_Soldier_base_F: SoldierGB{
		class EventHandlers {
			class SCTEVENT : SCTEVTEX_base {};
		};
	};
	
	class B_G_Soldier_F;
	
	class I_G_Story_Protagonist_F: B_G_Soldier_F{
		class EventHandlers {
			class SCTEVENT : SCTEVTEX_base {};
		};
	};
	
	class I_G_Story_SF_Captain_F: B_G_Soldier_F{
		class EventHandlers {
			class SCTEVENT : SCTEVTEX_base {};
		};
	};
	
	class I_G_resistanceLeader_F: I_G_Story_Protagonist_F{
		class EventHandlers {
			class SCTEVENT : SCTEVTEX_base {};
		};
	};
	
	class C_Soldier_VR_F: C_man_1{
		class EventHandlers {
			class SCTEVENT : SCTEVTEX_base {};
		};
	};
	

	class C_man_w_worker_F;	// External class reference
	
	class C_scientist_F : C_man_w_worker_F {
		class EventHandlers {
			class SCTEVENT : SCTEVTEX_base {};
		};
		
	};
	

	
	class C_Driver_1_F : C_man_1 {
		class EventHandlers {
			class SCTEVENT : SCTEVTEX_base {};
		};
		
	};

	
	class VirtualMan_F : Civilian_F {
		class EventHandlers {
			class SCTEVENT : SCTEVTEX_base {};
		};
		
	};
	
	class VirtualSpectator_F : VirtualMan_F {
		class EventHandlers {
			class SCTEVENT : SCTEVTEX_base {};
		};
		
	};

//virtual weapnholder( indicates vest plateholder
	class ReammoBox_F; //extern.
	class SCT_virtualcargo : ReammoBox_F{
		displayname = "vest pouch";
		maximumLoad = 200;
		destrType = "DestructNo";
		supplyRadius = 2;
		class EventHandlers {
			init = "_cargo = _this select 0; _cargo addEventHandler ['ContainerClosed', {(_this select 0)setVariable ['SCT_delcargo', true];}];";
		};
	};
	
//vehicle models for plates
	
	class Thing;
	
	class SCT_vest_base : Thing{
		author = "Sonic.T";
		scope = 1;
		model="\SCT\addons\SonicT_vest\data\objects\plate_base.p3d";
		cost = 500;
		armor = 60;
		icon = "\SCT\addons\SonicT_vest\data\ui\icon_plate.paa";
		destrType= "DestructBuilding";
		class DestructionEffects
		{
			
		};
		class EventHandlers{
			
			init = "[_this select 0]execVM '\SCT\addons\SonicT_vest\scripts\init_vehiclevest.sqf';";
		};
		class SCT_veh_Info{
			magazine = "SCT_plate_ceramic_esapi_magtype";
		};
		
		class HitPoints{
			class Part11{
				armor = 20;
				radius = 0.2;
				explosionShielding=1;
				material=60;
				name="hitpoint11";
				passThrough=0.11;
			};
			class Part12{
				armor = 20;
				radius = 0.2;
				explosionShielding=1;
				material=60;
				name="hitpoint12";
				passThrough=0.11;
			};
			
			class Part13{
				armor = 24;
				radius = 0.2;
				explosionShielding=1;
				material=60;
				name="hitpoint13";
				passThrough=0.11;
			};
			
			class Part21{
				armor = 24;
				radius = 0.2;
				explosionShielding=1;
				material=60;
				name="hitpoint21";
				passThrough=0.11;
			};
			
			class Part22{
				armor = 24;
				radius = 0.2;
				explosionShielding=1;
				material=60;
				name="hitpoint22";
				passThrough=0.11;
			};
			
			class Part23{
				armor = 24;
				radius = 0.2;
				explosionShielding=1;
				material=60;
				name="hitpoint23";
				passThrough=0.11;
			};
			
			class Part31{
				armor = 24;
				radius = 0.2;
				explosionShielding=1;
				material=60;
				name="hitpoint31";
				passThrough=0.11;
			};
			
			class Part32{
				armor = 24;
				radius = 0.2;
				explosionShielding=1;
				material=60;
				name="hitpoint32";
				passThrough=0.11;
			};
			
			class Part33{
				armor = 24;
				radius = 0.2;
				explosionShielding=1;
				material=60;
				name="hitpoint33";
				passThrough=0.11;
			};
		};
		
	};
	
	class SCT_plate_side_base : SCT_vest_base{
		model="\SCT\addons\SonicT_vest\data\objects\plate_side_base_L.p3d";
		cost = 250;
		armor = 60;
		icon = "\SCT\addons\SonicT_vest\data\ui\icon_plate.paa";
		
	};
	
	class SCT_esapi_side : SCT_plate_side_base{
		cost = 125;
		armor = 60;
		class SCT_veh_Info{
			magazine = "SCT_esapi_side_magtype";
		};
	};
	
};

//this is for life system is sonict. vest
class CfgMagazines{
	class CA_Magazine;
	class SonicT_Item_Base_magtype: CA_Magazine{
		class SCT_mag_Info {
			vehicle = "SCT_vest_base";
		};
		author = "Sonic.T";
		scope = 1;
		access = 3;
		displayName = "ESAPI ICW NIJ IV plate";
		detectRange = -1;
		type = 131072;
		mass = 30;
		count = 100000;
		picture = "\SCT\addons\SonicT_vest\data\esapi.paa";
		descriptionShort = "bar shows plate durability";
	};
	class SCT_plate_ceramic_esapi_magtype: SonicT_Item_Base_magtype{
		scope = 1;
		displayName = "ESAPI plate";
		picture = "\SCT\addons\SonicT_vest\data\esapi.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\plate_base.p3d";
		descriptionShort = "NIJ level IV ceramic plate, ICW IIIA vest.";
		mass = 28;
	};
	
	class SCT_esapi_side_magtype : SCT_plate_ceramic_esapi_magtype {
		class SCT_mag_Info {
			vehicle = "SCT_vest_base";
		};
		displayNmae = "ESAPI side plate";
		picture = "\SCT\addons\SonicT_vest\data\esapi_side.paa";
		mass = 10;
	};
	
	class SCT_plate_steel_ar500_qinch_magtype: SonicT_Item_Base_magtype {
		scope = 1;
		displayName = "AR500 lv III+ plate";
		picture = "\SonicT_vest\data\ar500.paa";
		model = "\SonicT_vest\data\objects\steel_ar500_3p.p3d"
		descriptionShort = "NIJ level III+ standalone still plate, multi-hit capability.";
		mass = 37;

	};
	
	class SCT_plate_poly_DFNDR_magtype: SonicT_Item_Base_magtype {
		scope = 1;
		displayName = "DFNDR lv III+ lightweight plate";
		picture = "\SonicT_vest\data\esapi.paa";
		model = "\SonicT_vest\data\objects\steel_ar500_3p.p3d"
		descriptionShort = "NIJ level III+ Polyethylene panel.";
		mass = 14;
	};	
};

class SCT_vest_objects_base {
	descriptionShort = "nonPlateCarrier";
};

class SCT_vest_objects : SCT_vest_objects_base {

};

class CfgWeapons {
	
	class ItemCore;
	class InventoryItem_Base_F;

	class SonicT_Item_Base: ItemCore {
		scope = 1;
		access = 3;
		displayName = "Vest Insert Manager";
		detectRange = -1;
		picture = "\SCT\addons\SonicT_vest\data\ui\icon_plate.paa";
		simulation = "ItemMineDetector";
		useAsBinocular = 0;
		type = 4096;
		descriptionShort = "";

		class ItemInfo: InventoryItem_Base_F {
			mass = 0;
		};
	};

	class SCT_plate_ceramic_esapi: SonicT_Item_Base {
		scope = 2;
		displayName = "ESAPI plate set";
		picture = "\SCT\addons\SonicT_vest\data\esapi.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "NIJ level IV ceramic plate, ICW IIIA vest.";

		class ItemInfo: ItemInfo {
			mass = 56;
		};
	};

	class SCT_plate_steel_ar5001: SonicT_Item_Base {
		scope = 2;
		displayName = "AR500 lv III+ plate set";
		picture = "\SCT\addons\SonicT_vest\data\ar500.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "NIJ level III+ standalone still plate, multi-hit capability.";

		class ItemInfo: ItemInfo {
			mass = 74;
		};	
	};
	
	class SCT_plate_poly_DFNDR: SonicT_Item_Base {
		scope = 2;
		displayName = "DFNDR lv III+ lightweight plate set";
		picture = "\SCT\addons\SonicT_vest\data\SCT_poly_dfndr_3p.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_poly_dfndr_3p.p3d"
		descriptionShort = "NIJ level III+ Polyethylene panel.";

		class ItemInfo: ItemInfo {
			mass = 28;
		};	
	};

	
	class CfgGlasses {
		class None;
	};
	
	class Vest_Camo_Base;
	class Vest_NoCamo_Base;
	class VestItem;
	class V_PlateCarrier1_rgr: Vest_NoCamo_Base { //NATO plate Carrier light.
		descriptionShort = "NIJ IIIA, plate attachable";
		class SCT_vest_objects : SCT_vest_objects_base {
			descriptionShort = "PlateCarrier";
		};
		class ItemInfo: VestItem {
			containerClass = "Supply210"; //vanilla 140. 2 sapi plates. 2* sapi is about 5.7kg. 2035 lightweight approx. 5kg
			mass = 25; //vanilla 60
			//armor = 100;
			class HitpointsProtectionInfo {

				
				class Chest {
					HitpointName = "HitChest";
					armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD_LITE;
				};

				class Diaphragm {
					HitpointName = "HitDiaphragm";
					armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD_LITE;
				};

				class Abdomen {
					hitpointName = "HitAbdomen";
					armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD_LITE;
				};

				class Body {
					hitpointName = "HitBody";
					//passthrough = 0.150000;
				};
				
			};
		};
	};

	class V_PlateCarrier2_rgr: V_PlateCarrier1_rgr {
		scope = 2;
		descriptionShort = "NIJ IIIA, plate attachable";
		class SCT_vest_objects : SCT_vest_objects_base {
			descriptionShort = "PlateCarrier";
		};
		
		class ItemInfo: VestItem {
			uniformModel = "\A3\Characters_F\BLUFOR\equip_b_vest01";
			containerClass = "Supply230"; //vanilla 140. - plate protection
			mass = 40; //vanilla 100

			class HitpointsProtectionInfo {

				class Chest {
					HitpointName = "HitChest";
					armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD;
				};

				class Diaphragm {
					HitpointName = "HitDiaphragm";
					armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD;
				};

				class Abdomen {
					hitpointName = "HitAbdomen";
					armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_NIJIV_ARMOR;
				};

				class Body {
					hitpointName = "HitBody";
					//passthrough = SCT_TRAUMAPAD_LITE;
				};
				
			};
		};
	};

	class V_PlateCarrier2_blk;

	class V_PlateCarrier3_rgr: Vest_NoCamo_Base {
		descriptionShort = "NIJ IIIA, plate attachable";
		class SCT_vest_objects : SCT_vest_objects_base {
			descriptionShort = "PlateCarrier";
		};
		class ItemInfo: VestItem {
			uniformModel = "\A3\Characters_F\BLUFOR\equip_b_vest01.p3d";
			containerClass = "Supply200"; //vanilla 140. - plate protection
			mass = 50; //vanilla 100

			class HitpointsProtectionInfo {

				class Chest {
					HitpointName = "HitChest";
					armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD;
				};

				class Diaphragm {
					HitpointName = "HitDiaphragm";
					armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD;
				};

				class Abdomen {
					hitpointName = "HitAbdomen";
					armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD;
				};

				class Body {
					hitpointName = "HitBody";
					//passthrough = SCT_TRAUMAPAD_LITE;
				};
				
			};
		};
	};

	class V_PlateCarrierGL_rgr: Vest_NoCamo_Base {
		descriptionShort = "NIJ IIIA + extended body part protection, explosive resistant";
		class SCT_vest_objects : SCT_vest_objects_base {
			descriptionShort = "PlateCarrier";
		};
		class ItemInfo: VestItem {
			containerClass = "Supply170"; //vanilla 140. did not increased that much since it is very heavy
			mass = 75; //IOTV full set (with pelvic protecion) is about 12kg. vanilla 100.

			class HitpointsProtectionInfo {

				class Neck {
					hitpointName = "HitNeck";
					armor = SCT_NIJIIIA_ARMOR;
					passthrough = SCT_TRAUMAPAD_LITE;
				};

				class Arms {
					hitpointName = "HitArms";
					armor = SCT_NIJIIIA_ARMOR;
					passthrough = SCT_TRAUMAPAD_LITE;
				};

				class Chest {
					hitpointName = "HitChest";
					armor = SCT_NIJIIIA_ARMOR;
					passthrough = SCT_TRAUMAPAD;
				};

				class Diaphragm {
					hitpointName = "HitDiaphragm";
					armor = SCT_NIJIIIA_ARMOR;
					passthrough = SCT_TRAUMAPAD;
				};

				class Abdomen {
					hitpointName = "HitAbdomen";
					armor = SCT_NIJIIIA_ARMOR;
					passthrough = SCT_TRAUMAPAD;
				};

				class Pelvis {
					hitpointName = "HitPelvis";
					armor = SCT_NIJIIIA_ARMOR;
					passthrough = SCT_TRAUMAPAD_LITE;
				};

				class Body {
					hitpointName = "HitBody";
					passthrough = 0.600000;
				};
			};
		};
	};

	class V_PlateCarrier1_blk: Vest_Camo_Base {

		descriptionShort = "NIJ IIIA, plate attachable";
		class SCT_vest_objects : SCT_vest_objects_base {
			descriptionShort = "PlateCarrier";
		};
		class ItemInfo: VestItem {
			uniformModel = "\A3\Characters_F\BLUFOR\equip_b_vest02.p3d";
			containerClass = "Supply210";
			mass = 15;

			class HitpointsProtectionInfo {

				class Chest {
					HitpointName = "HitChest";
					armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD_LITE;
				};

				class Diaphragm {
					HitpointName = "HitDiaphragm";
					armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD_LITE;
				};

				class Abdomen {
					hitpointName = "HitAbdomen";
					armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD_LITE;
				};

				class Body {
					hitpointName = "HitBody";
					//passthrough = SCT_TRAUMAPAD_LITE;
				};
			};
		};
	};

	class V_PlateCarrierSpec_rgr: Vest_NoCamo_Base {

		descriptionShort = "Heavy duty carrier, NIJ IIIA";
		class SCT_vest_objects : SCT_vest_objects_base {
			descriptionShort = "PlateCarrier";
		};
		class ItemInfo: VestItem {
			uniformModel = "\A3\Characters_F\BLUFOR\equip_b_carrier_spec_rig.p3d";
			containerClass = "Supply160";
			mass = 65; //made it less heavier than gl rig because there is no pelvic armor

			class HitpointsProtectionInfo {

				class Neck {
					hitpointName = "HitNeck";
					armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD_LITE;
				};

				class Arms {
					hitpointName = "HitArms";
					armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD_LITE;
				};

				class Chest {
					hitpointName = "HitChest";
					armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD;
				};

				class Diaphragm {
					hitpointName = "HitDiaphragm";
					armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD;
				};

				class Abdomen {
					hitpointName = "HitAbdomen";
					armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD;
				};

				class Body {
					hitpointName = "HitBody";
					//passthrough = SCT_TRAUMAPAD;
				};
			};
		};
	};

	class V_TacVest_khk: Vest_Camo_Base {

		descriptionShort = "NIJ level II";
		class SCT_vest_objects : SCT_vest_objects_base {
			
		};
		class ItemInfo: VestItem {
			containerClass = "Supply100";
			mass = SCT_NIJII_CMASS;

			class HitpointsProtectionInfo {

				class Chest {
					hitpointName = "HitChest";
					armor = SCT_NIJII_ARMOR;
					//passthrough = SCT_TRAUMAPAD_LITE;
				};

				class Diaphragm {
					hitpointName = "HitDiaphragm";
					armor = SCT_NIJII_ARMOR;
					//passthrough = SCT_TRAUMAPAD_LITE;
				};

				class Abdomen {
					hitpointName = "HitAbdomen";
					armor = SCT_NIJII_ARMOR;
					//passthrough = SCT_TRAUMAPAD_LITE;
				};

				class Body {
					hitpointName = "HitBody";
					//passthrough = 0.500000;
				};
			};
		};
	};

	class V_TacVest_camo: Vest_Camo_Base {

		descriptionShort = "NIJ level II";
		class SCT_vest_objects : SCT_vest_objects_base {
			
		};
		class ItemInfo: VestItem {
			uniformModel = "A3\Characters_F\Common\equip_tacticalvest";
			containerClass = "Supply100";
			mass = SCT_NIJII_CMASS;

			class HitpointsProtectionInfo {

				class Chest {
					hitpointName = "HitChest";
					armor = SCT_NIJIIIA_ARMOR
					//passthrough = SCT_TRAUMAPAD_LITE;
				};

				class Diaphragm {
					hitpointName = "HitDiaphragm";
					armor = SCT_NIJIIIA_ARMOR
					//passthrough = SCT_TRAUMAPAD_LITE;
				};

				class Abdomen {
					hitpointName = "HitAbdomen";
					armor = SCT_NIJIIIA_ARMOR
					//passthrough = SCT_TRAUMAPAD_LITE;
				};

				class Body {
					hitpointName = "HitBody";
					//passthrough = 0.500000;
				};
			};
		};
	};

	class V_TacVest_blk_POLICE: Vest_Camo_Base {
		author = "$STR_A3_Bohemia_Interactive";
		_generalMacro = "V_TacVest_blk_POLICE";
		scope = 2;
		class SCT_vest_objects : SCT_vest_objects_base {
			
		};
		descriptionShort = "NIJ IIIA";

		class ItemInfo: VestItem {
			uniformModel = "A3\Characters_F\Common\equip_tacticalvest";
			containerClass = "Supply100";
			mass = 30;

			class HitpointsProtectionInfo {

				class Chest {
					hitpointName = "HitChest";
					armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD_LITE;
				};

				class Diaphragm {
					hitpointName = "HitDiaphragm";
					armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD_LITE;
				};

				class Abdomen {
					hitpointName = "HitAbdomen";
					armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD_LITE;
				};

				class Body {
					hitpointName = "HitBody";
					//passthrough = SCT_TRAUMAPAD_LITE;
				};
			};
		};
	};

	class V_TacVestIR_blk: Vest_NoCamo_Base {
		author = "$STR_A3_Bohemia_Interactive";
		_generalMacro = "V_TacVestIR_blk";
		scope = 2;
		displayName = "$STR_A3_V_TacVestIR_blk0";
		picture = "\A3\characters_f\Data\UI\icon_V_TacVestIR_blk_CA.paa";
		model = "\A3\Characters_F_Beta\INDEP\equip_ir_vest01";
		descriptionShort = "NIJ level II";
		class SCT_vest_objects : SCT_vest_objects_base {
			
		};
		class ItemInfo: VestItem {
			uniformModel = "\A3\Characters_F_Beta\INDEP\equip_ir_vest01";
			containerClass = "Supply140";
			mass = SCT_NIJII_CMASS;

			class HitpointsProtectionInfo {

				class Chest {
					hitpointName = "HitChest";
					armor = SCT_NIJII_ARMOR
					//passthrough = SCT_TRAUMAPAD_LITE;
				};

				class Diaphragm {
					hitpointName = "HitDiaphragm";
					armor = SCT_NIJII_ARMOR
					//passthrough = SCT_TRAUMAPAD_LITE;
				};

				class Abdomen {
					hitpointName = "HitAbdomen";
					armor = SCT_NIJII_ARMOR
					//passthrough = SCT_TRAUMAPAD_LITE;
				};

				class Body {
					hitpointName = "HitBody";
					//passthrough = SCT_TRAUMAPAD_LITE;
				};
			};
		};
	};

	class V_TacVestCamo_khk: Vest_Camo_Base {

		descriptionShort = "NIJ level II";
		class SCT_vest_objects : SCT_vest_objects_base {
			
		};
		class ItemInfo: VestItem {

			containerClass = "Supply100";
			mass = SCT_NIJII_CMASS;

			class HitpointsProtectionInfo {

				class Chest {
					hitpointName = "HitChest";
					armor = SCT_NIJII_ARMOR
					//passthrough = SCT_TRAUMAPAD_LITE;
				};

				class Diaphragm {
					hitpointName = "HitDiaphragm";
					armor = SCT_NIJII_ARMOR
					//passthrough = SCT_TRAUMAPAD_LITE;
				};

				class Abdomen {
					hitpointName = "HitAbdomen";
					armor = SCT_NIJII_ARMOR
					//passthrough = SCT_TRAUMAPAD_LITE;
				};

				class Body {
					hitpointName = "HitBody";
					//passthrough = SCT_TRAUMAPAD_LITE;
				};
			};
		};
	};

	class V_PlateCarrierIA1_dgtl: Vest_NoCamo_Base { //greenback carrier GA lite

		descriptionShort = "NIJ IIIA, Plate attachable";
		class SCT_vest_objects : SCT_vest_objects_base {
			descriptionShort = "PlateCarrier";
		};
		class ItemInfo: VestItem {
			containerClass = "Supply180"; //vanilla 140. 2 sapi plates. 2* sapi is about 5.7kg. 2035 lightweight approx. 5kg
			mass = 20; //vanilla 60

			class HitpointsProtectionInfo {

				class Chest {
					HitpointName = "HitChest";
					armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD;
				};

				class Diaphragm {
					HitpointName = "HitDiaphragm";
					armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD;
				};

				class Abdomen {
					hitpointName = "HitAbdomen";
					armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD;
				};

				class Body {
					hitpointName = "HitBody";
					//passthrough = SCT_TRAUMAPAD;
				};
			};
		};
	};

	class V_PlateCarrierIA2_dgtl: V_PlateCarrierIA1_dgtl {
		descriptionShort = "NIJ IIIA, plate attachable";
		class SCT_vest_objects : SCT_vest_objects_base {
			descriptionShort = "PlateCarrier";
		};
		class ItemInfo: VestItem {
			uniformModel = "A3\Characters_F_Beta\INDEP\equip_ia_vest02";
			containerClass = "Supply210";
			mass = 50; //vanilla 80 - pelvic armors are heavy enough to protect your balls.

			class HitpointsProtectionInfo {

				class Chest {
					hitpointName = "HitChest";
					armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD;
				};

				class Diaphragm {
					hitpointName = "HitDiaphragm";
					armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD;
				};

				class Abdomen {
					hitpointName = "HitAbdomen";
					armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD;
				};

				class Pelvis { //i really didn't know GA carrier rig have pelvic protection
					hitpointName = "HitPelvis";
					armor = SCT_NIJIIIA_ARMOR
					//passthrough = SCT_TRAUMAPAD_LITE;
				};

				class Body {
					hitpointName = "HitBody";
					//passthrough = SCT_TRAUMAPAD;
				};
			};
		};
	};

	class V_PlateCarrierIAGL_dgtl: V_PlateCarrierIA2_dgtl {
		descriptionShort = "NIJ IIIA + extended body part protection, explosive resistant";
		class SCT_vest_objects : SCT_vest_objects_base {
			descriptionShort = "PlateCarrier";
		};
		class ItemInfo: VestItem {
			containerClass = "Supply160";
			mass = 75;


			class HitpointsProtectionInfo {

				class Neck {
					hitpointName = "HitNeck";
					armor = SCT_NIJIIIA_ARMOR
					//passthrough = SCT_TRAUMAPAD_LITE;
				};

				class Arms {
					hitpointName = "HitArms";
					armor = SCT_NIJIIIA_ARMOR
					//passthrough = SCT_TRAUMAPAD_LITE;
				};

				class Chest {
					hitpointName = "HitChest";
					armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD;
				};

				class Diaphragm {
					hitpointName = "HitDiaphragm";
					armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD;
				};

				class Abdomen {
					hitpointName = "HitAbdomen";
					armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD;
				};

				class Pelvis {
					hitpointName = "HitPelvis";
					armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD;
				};

				class Body {
					hitpointName = "HitBody";
					//passthrough = 0.600000;
				};
			};
		};
	};

	class V_RebreatherB: Vest_Camo_Base {
		descriptionShort = "Rebreather with a little protection";
		class SCT_vest_objects : SCT_vest_objects_base {
			
		};
	};

	class V_Press_F: Vest_Camo_Base {
		class SCT_vest_objects : SCT_vest_objects_base {
			descriptionShort = "PlateCarrier";
		};
		descriptionShort = "NIJ IIIA, plate attachable"; // I really didn't like about this vest because it looked like plate armor but it was not.

		class ItemInfo: VestItem {
			containerClass = "Supply120"; //minimal weights for the armor plates
			mass = 40;

			class HitpointsProtectionInfo {

				class Chest {
					hitpointName = "HitChest";
					armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD;
				};

				class Diaphragm {
					hitpointName = "HitDiaphragm";
					armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD;
				};

				class Abdomen {
					hitpointName = "HitAbdomen";
					armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD;
				};

				class Pelvis {
					hitpointName = "HitPelvis";
					armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD;
				};

				class Body {
					hitpointName = "HitBody";
					//passthrough = SCT_TRAUMAPAD;
				};
			};
		};
	};

	class Uniform_Base;
	class UniformItem;
	class U_O_CombatUniform_ocamo: Uniform_Base{
		descriptionShort="CSAT Hex camo GOST level 2";
	};
	class U_O_CombatUniform_oucamo: Uniform_Base{
		descriptionShort="CSAT Urban camo GOST level 2";
	};

};

