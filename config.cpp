#include "BIS_AddonInfo.hpp"
#ifndef SCT_ARMOR_RATINGS
#define SCT_ARMOR_RATINGS 1
#define SCT_NIJII_CMASS 20
#define SCT_NIJII_ARMOR 6
#define SCT_NIJIIIA_CMASS 8
#define SCT_NIJIIIA_ARMOR 10
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
			
			class ChangeSettings {
				preInit = 1;
			};
			
			class OpenSettings {};
			class Hitpush{};
			
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
	
};

class CfgWeapons {
	
	class ItemCore;
	class InventoryItem_Base_F;

	class SonicT_Item_Base: ItemCore {
		scope = 1;
		access = 3;
		displayName = "-";
		detectRange = -1;
		simulation = "ItemMineDetector";
		useAsBinocular = 0;
		type = 4096;
		picture = "";
		descriptionShort = "";

		class ItemInfo: InventoryItem_Base_F {
			mass = 1;
		};
	};

	class SCT_plate_ceramic_esapi: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) ESAPI MIL-IV";
		picture = "\SCT\addons\SonicT_vest\data\esapi.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: United States Military<br />Rating: MIL-IV Ceramic, Boron Carbide<br />Introduced: 2005<br />Will withstand 30-06 M2AP";

		class ItemInfo: ItemInfo {
			mass = 108;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"ESAPI NIJ IV ceramic ICW soft body armor", 0};
			enableparts[] = {0,0,14,14,14,0,0,0,0};
			blunttraumaPad[] = {0,0,1,1,1,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_ceramic_esapic: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) ESAPI MIL-IV (Ceradyne)";
		picture = "\SCT\addons\SonicT_vest\data\esapi.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: United States Military<br />Rating: MIL-IV Ceramic, Boron Carbide<br />Introduced: 2009<br />Will withstand 30-06 M2AP";

		class ItemInfo: ItemInfo {
			mass = 120;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"ESAPI NIJ IV ceramic, Ceradyne-produced", 0};
			enableparts[] = {0,0,15,15,15,0,0,0,0};
			blunttraumaPad[] = {0,0,1.4,1.4,1.4,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_ceramic_TPG: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) TPG Level IV";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Civilians and LE<br />Rating: NIJ Level IV, Aluminum Oxide<br />Introduced: 2010s<br />Will withstand repeat 30-06 impacts";

		class ItemInfo: ItemInfo {
			mass = 140;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"TPG ceramic Aluminum Oxide plate, Level IV", 0};
			enableparts[] = {0,0,13,13,13,0,0,0,0};
			blunttraumaPad[] = {0,0,1.6,1.6,1.6,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_ceramic_esapimc: SonicT_Item_Base {
		scope = 2;
		displayName = "(PLate) ESAPI-MC MIL-IV/MC";
		picture = "\SCT\addons\SonicT_vest\data\esapi.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: United States Military<br />Rating: MIL-IV Ceramic, Boron Carbide<br />Introduced: 2005<br />Will withstand 30-06 M2AP<br />Maximum Coverage";

		class ItemInfo: ItemInfo {
			mass = 120;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"ESAPI NIJ IV ceramic ICW soft body armor", 0};
			enableparts[] = {0,10,14,14,14,10,5,0,0};
			blunttraumaPad[] = {0.3,0,1,1,1,1,0.3,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_ceramic_xsapi: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) XSAPI MIL-V GEN3";
		picture = "\SCT\addons\SonicT_vest\data\xsapi.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: United States Military<br />Rating: MIL-V Ceramic, Boron Carbide<br />Introduced: 2016<br />Will withstand M993, M995, or 7N39";

		class ItemInfo: ItemInfo {
			mass = 102;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"XSAPI-2016 ceramic ICW soft body armor", 0};
			enableparts[] = {0,0,20,20,20,0,0,0,0};
			blunttraumaPad[] = {0,0,1,1,1,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_ceramic_lv: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) Xin Xing MIL-V";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: People's Liberation Army, African Mercenaries<br />Rating: MIL-V Ceramic, Aluminum Oxide<br />Introduced: 2010s<br />Will withstand M993, M995, or 7N39";

		class ItemInfo: ItemInfo {
			mass = 105;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"Xin Xing MIL-V Plate", 0};
			enableparts[] = {0,0,19,19,19,0,0,0,0};
			blunttraumaPad[] = {0,0,0.98,0.98,0.98,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_ceramic_lvi: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) Jianhuren MIL-VI";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: People's Liberation Army SO<br />Rating: MIL-VI Ceramic, Aluminum Oxide<br />Introduced: 2010s<br />Will withstand heavy impacts";

		class ItemInfo: ItemInfo {
			mass = 180;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"Jianhuren MIL-VI Plate", 0};
			enableparts[] = {0,0,28,26,28,0,0,0,0};
			blunttraumaPad[] = {0,0,1.98,1.98,1.98,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_ceramic_xsapimc: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) XSAPI MIL-V/MC GEN3";
		picture = "\SCT\addons\SonicT_vest\data\xsapi.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: United States Military<br />Rating: MIL-V Ceramic, Boron Carbide<br />Introduced: 2016<br />Will withstand M993, M995, or 7N39<br />Maximum Coverage";

		class ItemInfo: ItemInfo {
			mass = 115;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"XSAPI-2016 ceramic ICW soft body armor", 0};
			enableparts[] = {6,10,10,19,19,19,6,0,0};
			blunttraumaPad[] = {0.2,0.4,1,1,1,1,0.3,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_ceramic_xsapi2009: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) XSAPI MIL-VA GEN1";
		picture = "\SCT\addons\SonicT_vest\data\xsapi.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: United States Military<br />Rating: MIL-VA Ceramic, Boron Carbide<br />Introduced: 2009<br />Will withstand M995";

		class ItemInfo: ItemInfo {
			mass = 105;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"XSAPI-2009 MIL-VA ICW soft body armor", 0};
			enableparts[] = {0,0,16,16,16,0,0,0,0};
			blunttraumaPad[] = {0,0,1,1,1,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_ceramic_xsapi2011: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) XSAPI MIL-V GEN2";
		picture = "\SCT\addons\SonicT_vest\data\xsapi.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: United States Military<br />Rating: MIL-V Ceramic, Boron Carbide<br />Introduced: 2011<br />Special Theater Contingency Plate";

		class ItemInfo: ItemInfo {
			mass = 121;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"XSAPI-2011 GEN2", 0.4};
			enableparts[] = {0,0,18,18,18,0,0,0,0};
			blunttraumaPad[] = {0,0,1,1,1,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_ceramic_sapi: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) SAPI MIL-III";
		picture = "\SCT\addons\SonicT_vest\data\sapi.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: United States Military<br />Rating: MIL-III Ceramic, Boron Carbide<br />Introduced: 1998<br />Multi-hit resistant";

		class ItemInfo: ItemInfo {
			mass = 96;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"SAPI MIL-III ICW soft body armor", 0};
			enableparts[] = {0,0,12,12,12,0,0,0,0};
			blunttraumaPad[] = {0,0,1,1,1,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_ceramic_hesapi: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) H-ESAPI MIL-V";
		picture = "\SCT\addons\SonicT_vest\data\hesapi.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: US Air Force Pararescuemen<br />Rating: MIL-V Ceramic, Boron Carbide<br />Introduced: 2007<br />Rated to stop M993, M995, or 7N24";

		class ItemInfo: ItemInfo {
			mass = 158;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"H-ESAPI MIL-V", 0};
			enableparts[] = {0,0,22,22,22,0,0,0,0};
			blunttraumaPad[] = {0,0,1.2,1.2,1.2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_ceramic_isapo: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) ISAPO MIL-III";
		picture = "\SCT\addons\SonicT_vest\data\rba.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: United States Military<br />Rating: MIL-III Ceramic, Aluminum Oxide<br />Introduced: 1996<br />Will withstand 7.62x51mm Ball";

		class ItemInfo: ItemInfo {
			mass = 128;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"ISAPO MIL-III first-generation ceramic body armor", 0};
			enableparts[] = {0,0,12,12,12,0,0,0,0};
			blunttraumaPad[] = {0,0,1.5,1.5,1.5,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_ceramic_dragonskin: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) DragonSkin Level III";
		picture = "\SCT\addons\SonicT_vest\data\dragonskin.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: PMCs and American Special Forces<br />Rating: NIJ Level III Ceramic, Special Design<br />Introduced: 1999<br />Highly resistant against multiple impacts";

		class ItemInfo: ItemInfo {
			mass = 102;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"SOV-2000 Level III", 0};
			enableparts[] = {0,0,12,12,12,0,0,0,0};
			blunttraumaPad[] = {0,0,1.8,1.8,1.8,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_ceramic_dragonskinheavy: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) DragonSkin Level IV";
		picture = "\SCT\addons\SonicT_vest\data\dragonskin.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: PMCs and American Special Forces<br />Rating: NIJ Level IV Ceramic, Special Design<br />Introduced: 1999<br />Will withstand multiple IV-level threats";

		class ItemInfo: ItemInfo {
			mass = 110;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"SOV-2000 Level IV", 0};
			enableparts[] = {0,0,15,15,15,0,0,0,0};
			blunttraumaPad[] = {0,0,1.7,1.7,1.7,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_ceramic_dragonskinassault: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) DragonSkin Level V";
		picture = "\SCT\addons\SonicT_vest\data\dragonskin.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: American Special Forces<br />Rating: MIL-V Ceramic, Special Design<br />Introduced: 1999<br />Will withstand M993 and M995";

		class ItemInfo: ItemInfo {
			mass = 130;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"SOV-3000 Level V", 0};
			enableparts[] = {0,0,19,19,19,0,0,0,0};
			blunttraumaPad[] = {0,0,1.6,1.6,1.6,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_ceramic_RBA: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) Ranger Body Armor MIL-IV";
		picture = "\SCT\addons\SonicT_vest\data\rba.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: 75th Ranger Regiment<br />Rating: MIL-IV Ceramic, Aluminum Oxide<br />Introduced: 1993<br />Will withstand multiple 7.62x51mm FMJ rounds";

		class ItemInfo: ItemInfo {
			mass = 140;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"Ranger Body Armor", 0};
			enableparts[] = {0,0,14,14,14,0,0,0,0};
			blunttraumaPad[] = {0,0,1.6,1.6,1.6,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_ceramic_RBAMC: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) Ranger Body Armor MIL-IV/MC";
		picture = "\SCT\addons\SonicT_vest\data\rba.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: 75th Ranger Regiment<br />Rating: MIL-IV Ceramic, Maximum Coverage, Aluminum Oxide<br />Introduced: 1993<br />Will withstand multiple 7.62x51mm FMJ rounds.<br />Maximum Coverage";

		class ItemInfo: ItemInfo {
			mass = 160;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"Ranger Body Armor", 0};
			enableparts[] = {0,10,14,14,14,14,3,0,0};
			blunttraumaPad[] = {0,1.4,1.7,1.7,1.7,1.4,1.4,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_ceramic_INFI: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) Infidel Armor Level IV";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Preppers<br />Rating: MIL-IV Ceramic, Aluminum Oxide<br />Introduced: 2010s<br />Will withstand M61 7.62x51mm AP Ball";

		class ItemInfo: ItemInfo {
			mass = 152;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"Infidel Armor Level IV", 0};
			enableparts[] = {0,0,15,15,15,0,0,0,0};
			blunttraumaPad[] = {0,0,1.8,1.8,1.8,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_ceramic_6b46: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) 6B46 GOST-6A";
		picture = "\SCT\addons\SonicT_vest\data\6b45.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Russian Armed Forces<br />Rating: GOST 6A Ceramic, Boron Carbide<br />Introduced: 2016<br />Multiple-hit resistant against 7.62x54mm FMJ";

		class ItemInfo: ItemInfo {
			mass = 108;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-IV 6B46 Plate", 0};
			enableparts[] = {0,0,15,15,15,0,0,0,0};
			blunttraumaPad[] = {0,0,1.2,1.2,1.2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_ceramic_6b45: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) 6B45 GOST-6";
		picture = "\SCT\addons\SonicT_vest\data\6b45.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Russian Armed Forces<br />Rating: GOST 6 Ceramic, Boron Carbide<br />Introduced: 2015<br />Multiple-hit resistant against 7.62x54mm FMJ";

		class ItemInfo: ItemInfo {
			mass = 104;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-IV 6B45 Plate", 0};
			enableparts[] = {0,0,14,14,14,0,0,0,0};
			blunttraumaPad[] = {0,0,1,1,1,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_ceramic_rus5: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) MIL-V 6B58";
		picture = "\SCT\addons\SonicT_vest\data\6b58.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Spetsnaz<br />Rating: MIL-V Ceramic, Boron Carbide<br />Introduced: 2016<br />Highly resistant to all standard small arm cartridges";

		class ItemInfo: ItemInfo {
			mass = 130;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-V 6B58 Plate", 0};
			enableparts[] = {0,0,19,19,19,0,0,0,0};
			blunttraumaPad[] = {0,0,1.3,1.2,1.3,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_ceramic_rusgun: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) MIL-VS OVR-3Sh";
		picture = "\SCT\addons\SonicT_vest\data\OVR-3SH.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Alfa Group, Spetsnaz<br />Rating: MIL-VS Sapper-grade, Aluminum Oxide<br />Introduced: 2017<br />Capable against repeat AP 7.62x54mm";

		class ItemInfo: ItemInfo {
			mass = 225;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-VS OVR-3Sh Plate", 0};
			enableparts[] = {0,15,24,24,24,15,0,0,0};
			blunttraumaPad[] = {0,0.6,2,2,2,0.6,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_ceramic_gookgun: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) MIL-VS Tianshi";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: PLA Honor Guard<br />Rating: MIL-VS, Aluminum Oxide<br />Introduced: 2017<br />Capable against repeat AP 7.62x54mm";

		class ItemInfo: ItemInfo {
			mass = 204;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-VS Tianshi Plate", 0};
			enableparts[] = {0,15,20,20,20,15,0,0,0};
			blunttraumaPad[] = {0,0.9,1.8,1.8,1.8,0.9,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_ceramic_ratnik2L: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) MIL-V RATNIK-2 Legioner";
		picture = "\SCT\addons\SonicT_vest\data\6b58.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Alfa Group, Spetsnaz<br />Rating: MIL-V, RATNIK-2<br />Introduced: 2016<br />Capable against 7.62x54mm repeat impacts";

		class ItemInfo: ItemInfo {
			mass = 120;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-V RATNIK-2 Legioner", 0};
			enableparts[] = {0,10,21,21,21,10,0,0,0};
			blunttraumaPad[] = {0,0,2.1,2.1,2.1,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_ceramic_ratnik2C: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) MIL-VI+ RATNIK-2 Centurion";
		picture = "\SCT\addons\SonicT_vest\data\6b58.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Alfa Group, Spetsnaz<br />Rating: MIL-VI+, Perfected Boron Carbide<br />Introduced: 2017<br />Rated against repeat .338 Lapua Magnum";

		class ItemInfo: ItemInfo {
			mass = 210;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-VI+ RATNIK-2 Centurion", 0};
			enableparts[] = {0,10,28,28,28,28,0,0,0};
			blunttraumaPad[] = {0,1,3.5,3.5,3.5,1,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_ceramic_ratnik2S: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) MIL-IV RATNIK-2 Sherp";
		picture = "\SCT\addons\SonicT_vest\data\6b58.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: OMON, Alfa Group<br />Rating: MIL-VA Ceramic, Boron Carbide<br />Introduced: 2017<br />Resistant against common small-arms AP cartridges";

		class ItemInfo: ItemInfo {
			mass = 70;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-IV RATNIK-2 Sherp", 0};
			enableparts[] = {0,0,13,13,13,5,0,0,0};
			blunttraumaPad[] = {0,0,1.2,1.2,1.1,1,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_ceramic_ratnik2G: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) MIL-VI RATNIK-2 Gladiator";
		picture = "\SCT\addons\SonicT_vest\data\6b58.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Assault Spetsnaz<br />Rating: MIL-VI Ceramic, Boron Carbide<br />Introduced: 2017<br />Rated against .338 Lapua Magnum";

		class ItemInfo: ItemInfo {
			mass = 190;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-V RATNIK-2 Gladiator", 0};
			enableparts[] = {0,13,22,22,22,13,0,0,0};
			blunttraumaPad[] = {0,1.5,2,2,2,1.5,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_ceramic_4sas7: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) Highcom 4SAS-7 IV";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Civilians<br />Rating: NIJ Level IV Ceramic<br />Introduced: 2000s<br />Rated against 30-06 M2AP";

		class ItemInfo: ItemInfo {
			mass = 190;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"4SAS-7 Level IV", 0};
			enableparts[] = {0,0,14,14,15,0,0,0,0};
			blunttraumaPad[] = {0,0,1,1,1,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_ceramic_leison4: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) Leison IV";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Civilians<br />Rating: NIJ Level IV Ceramic<br />Introduced: 2000s<br />Rated against 30-06 M2AP";

		class ItemInfo: ItemInfo {
			mass = 170;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"Wenzhou Leizon Level III/IV Plate", 0};
			enableparts[] = {0,0,12,12,12,0,0,0,0};
			blunttraumaPad[] = {0,0,0.9,1,0.7,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_ceramic_b4c: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) Multi-Curve B4C IV";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: SWAT Tactical Units<br />Rating: NIJ Level IV Ceramic<br />Introduced: 2000s<br />Rated against 30-06 M2AP";

		class ItemInfo: ItemInfo {
			mass = 140;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"Multi-Curve B4C IV", 0};
			enableparts[] = {0,0,15,15,15,13,0,0,0};
			blunttraumaPad[] = {0,0,1.3,1.5,1.3,1,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_ceramic_rus6: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) MIL-VI 6B72";
		picture = "\SCT\addons\SonicT_vest\data\6b72.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Assault Spetsnaz<br />Rating: MIL-VI Ceramic<br />Introduced: 2017<br />Rated to stop .338 Lapua Magnum";

		class ItemInfo: ItemInfo {
			mass = 164;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-VI 6B72 Plate", 0};
			enableparts[] = {0,0,25,25,25,0,0,0,0};
			blunttraumaPad[] = {0,0,1.2,1.3,1.2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_ceramic_rus7: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) MIL-VII 6B83";
		picture = "\SCT\addons\SonicT_vest\data\6B83.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Heavy Assault Spetsnaz<br />Rating: MIL-VII Ceramic<br />Introduced: 2017<br />Rated to stop .460 Weatherby Magnum impacts or a large number of small-caliber rounds.";

		class ItemInfo: ItemInfo {
			mass = 190;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-VII 6B83", 0};
			enableparts[] = {0,0,40,40,40,0,0,0,0};
			blunttraumaPad[] = {0,0,3.2,3,3.2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_ceramic_rus7t: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) MIL-VII+ 6B87";
		picture = "\SCT\addons\SonicT_vest\data\6B83.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Heavy Assault Spetsnaz<br />Rating: MIL-VII+ Ceramic<br />Introduced: 2017<br />Rated to stop repeat .338 API526 impacts.";

		class ItemInfo: ItemInfo {
			mass = 230;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-VII 6B83", 0};
			enableparts[] = {0,0,55,55,55,0,0,0,0};
			blunttraumaPad[] = {0,0,3.2,3,3.2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_ceramic_rus8: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) MIL-VIIIA 6B92";
		picture = "\SCT\addons\SonicT_vest\data\6B92.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Ultra-Heavy Assault Spetsnaz<br />Rating: MIL-VIIIA Ceramic<br />Introduced: 2017<br />Rated to stop 12.7x99 or 12.7x108mm FMJ";

		class ItemInfo: ItemInfo {
			mass = 250;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-VIIIA 6B92", 0};
			enableparts[] = {0,0,145,145,145,0,0,0,0};
			blunttraumaPad[] = {0,0,4.2,4,4.2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_ceramic_rus11: SonicT_Item_Base {
		scope = 1;
		displayName = "(Plate) MIL-XI 6B100";
		picture = "\SCT\addons\SonicT_vest\data\6B92.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Vladimir Putin<br />Rating: MIL-XI Depleted Uranium<br />Introduced: 2017<br />Rated to stop 25x59mm APFSDS";

		class ItemInfo: ItemInfo {
			mass = 250;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-XI 6B100", 0};
			enableparts[] = {0,0,550,550,550,0,0,0,0};
			blunttraumaPad[] = {0,0,24,24,24,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_ceramic_rus82: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) MIL-VIII 6B96";
		picture = "\SCT\addons\SonicT_vest\data\6B92.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Ultra-Heavy Assault Spetsnaz<br />Rating: MIL-VIII Ceramic<br />Introduced: 2017<br />Rated to stop 12.7x99 or 12.7x108mm FMJ";

		class ItemInfo: ItemInfo {
			mass = 290;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-VIII 6B96", 0};
			enableparts[] = {0,0,167,166,167,0,0,0,0};
			blunttraumaPad[] = {0,0,7.8,7.8,7.8,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_steel_ar5001: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) AR500 Level III+";
		picture = "\SCT\addons\SonicT_vest\data\ar500.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Contractors, Civilians, PMCs<br />Rating: NIJ Level III+<br />Introduced: 2000s<br />Will withstand repeat 7.62x51mm FMJ impacts";

		class ItemInfo: ItemInfo {
			mass = 158;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"AR500 Level III+ ", 2};
			enableparts[] = {0,0,11,11,11,0,0,0,0};
			blunttraumaPad[] = {0,0,2,2,2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_steel_ar500C: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) AR500 Level III";
		picture = "\SCT\addons\SonicT_vest\data\ar500.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Contractors, Civilians, PMCs<br />Rating: NIJ Level III<br />Introduced: 2000s<br />Will withstand repeat 7.62x51mm FMJ impacts";

		class ItemInfo: ItemInfo {
			mass = 134;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"AR500 Level III", 2};
			enableparts[] = {0,0,10,10,10,0,0,0,0};
			blunttraumaPad[] = {0,0,1.9,1.9,1.9,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_steel_ar500CT: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) AR500 Target 3/8";
		picture = "\SCT\addons\SonicT_vest\data\ar500.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Survivalists<br />Rating: NIJ Target Level III<br />Introduced: 2000s<br />50% thicker over standard AR500.";

		class ItemInfo: ItemInfo {
			mass = 201;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"AR500 Level III Target", 2};
			enableparts[] = {0,0,10,10,10,0,0,0,0};
			blunttraumaPad[] = {0,0,2.9,2.9,2.9,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_steel_ar5004: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) AR500 Level IV";
		picture = "\SCT\addons\SonicT_vest\data\ar500.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Contractors, Civilians, PMCs<br />Rating: NIJ Level IV<br />Introduced: 2000s<br />Will withstand repeat 30-06 M2AP impacts";

		class ItemInfo: ItemInfo {
			mass = 165;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"AR500 Level IV", 2};
			enableparts[] = {0,0,15,15,15,0,0,0,0};
			blunttraumaPad[] = {0,0,2,2,2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_steel_ar5005: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) AR500 Level V";
		picture = "\SCT\addons\SonicT_vest\data\ar500.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Well-funded PMCs, well-connected survivalists<br />Rating: NIJ Level IV, MIL-V<br />Introduced: 2010s<br />Rated for .338 Lapua Magnum";

		class ItemInfo: ItemInfo {
			mass = 194;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"AR500 Level V", 2};
			enableparts[] = {0,0,21,21,21,0,0,0,0};
			blunttraumaPad[] = {0,0,3.5,3.5,3.5,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_steel_ar5006: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) AR500 Level VI";
		picture = "\SCT\addons\SonicT_vest\data\ar500.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Expert Survivalists, Gray Men<br />Rating: MIL-VI<br />Introduced: 2010s<br />Rated for 7N39, 7N37, XM1154";

		class ItemInfo: ItemInfo {
			mass = 250;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"AR500 Level VI", 2};
			enableparts[] = {0,0,29,29,29,0,0,0,0};
			blunttraumaPad[] = {0,0,3.5,3.5,3.5,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_steel_ar5005mc: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) AR500 Level V/MC";
		picture = "\SCT\addons\SonicT_vest\data\ar500.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Well-funded PMCs, well-connected survivalists<br />Rating: NIJ Level IV, MIL-V, Maximum Coverage<br />Introduced: 2010s<br />Rated for .338 Lapua Magnum";

		class ItemInfo: ItemInfo {
			mass = 220;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"AR500 Level V", 2};
			enableparts[] = {0,17,21,21,21,17,17,0,0};
			blunttraumaPad[] = {0,3.1,3.7,3.7,3.7,3.1,3.1,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_steel_TAC: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) TAC Steel Level IV+";
		picture = "\SCT\addons\SonicT_vest\data\ar500.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Survivalists, PMCs<br />Rating: NIJ Level IV<br />Introduced: 2010s<br />Will withstand, on paper, a .338 Lapua Magnum";

		class ItemInfo: ItemInfo {
			mass = 174;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"TAC Steel Level IV+", 2};
			enableparts[] = {0,0,17.5,17.5,17.5,0,0,0,0};
			blunttraumaPad[] = {0,0,2.6,2.6,2.6,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_steel_arbudget: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) AR500 Level IIIA";
		picture = "\SCT\addons\SonicT_vest\data\ar500.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Contractors, Civilians, PMCs<br />Rating: NIJ Level IIIA<br />Introduced: 2000s<br />Will withstand repeat .44 Magnum impacts";

		class ItemInfo: ItemInfo {
			mass = 110;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"AR500 Level IIIA ", 2};
			enableparts[] = {0,0,8,8,8,0,0,0,0};
			blunttraumaPad[] = {0,0,2,2,2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_kevlar_3: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) Kevlar Level IIIA";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Contractors, Civilians, PMCs<br />Rating: NIJ Level IIIA<br />Introduced: 1980s<br />Will withstand revolver impacts";

		class ItemInfo: ItemInfo {
			mass = 40;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"Kevlar Level IIIA", 4};
			enableparts[] = {0,0,8,8,8,0,0,0,0};
			blunttraumaPad[] = {0,0,1,1,1,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_kevlar_2: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) Kevlar Level II";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Contractors, Civilians, PMCs<br />Rating: NIJ Level II<br />Introduced: 1980s<br />Will withstand at least one 9x19mm Parabellum FMJ impact";

		class ItemInfo: ItemInfo {
			mass = 25;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"Kevlar Level II", 4};
			enableparts[] = {0,0,6,6,6,0,0,0,0};
			blunttraumaPad[] = {0,0,1,1,1,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_kevlar_1: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) Kevlar Level I";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Contractors, Civilians, PMCs<br />Rating: NIJ Level I<br />Introduced: 1980s<br />Will withstand very light shrapnel";

		class ItemInfo: ItemInfo {
			mass = 15;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"Kevlar Level I", 4};
			enableparts[] = {0,0,2,3,2,0,0,0,0};
			blunttraumaPad[] = {0,0,1,1,1,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_nylon_1: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) B-Nylon Level I";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: United States Military<br />Rating: NIJ Level I<br />Introduced: 1960s<br />Don't try getting shot.";

		class ItemInfo: ItemInfo {
			mass = 23;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"Ballistic Nylon Level I", 4};
			enableparts[] = {0,0,2,2,2,0,0,0,0};
			blunttraumaPad[] = {0,0,0.7,0.7,0.7,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_nylon_2: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) B-Nylon Level II";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: United States Military<br />Rating: NIJ Level II<br />Introduced: 1960s<br />Designed to stop fragmentation.";

		class ItemInfo: ItemInfo {
			mass = 26;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"Ballistic Nylon Level II", 4};
			enableparts[] = {0,0,5,5,5,0,0,0,0};
			blunttraumaPad[] = {0,0,0.7,0.7,0.7,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_steel_ar680: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) AR680 Level III+";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Contractors, Civilians, PMCs<br />Rating: NIJ Level III+<br />Introduced: 2010s<br />Will withstand repeat 7.62x51mm Ball";

		class ItemInfo: ItemInfo {
			mass = 124;
		};

		class SCT_ITEMINFO{
			plateinfo[] = {"AR680 Level III+", 2.1};
			enableparts[] = {0,0,11,11,11,0,0,0,0};
			blunttraumaPad[] = {0,0,2,2,2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_steel_ar680b: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) AR680 Level IV";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Contractors, Civilians, PMCs<br />Rating: NIJ Level IV<br />Introduced: 2010s<br />Will withstand repeat 7.62x51mm Ball";

		class ItemInfo: ItemInfo {
			mass = 144;
		};

		class SCT_ITEMINFO{
			plateinfo[] = {"AR680 Level IV", 2.1};
			enableparts[] = {0,0,14,15,14,0,0,0,0};
			blunttraumaPad[] = {0,0,2,2,2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_steel_U: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) Zeta-6H Level IV";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: SWAT, Riot Control<br />Rating: NIJ Level IV<br />Introduced: 2010s<br />Rated for many 7.62x51mm rounds";

		class ItemInfo: ItemInfo {
			mass = 150;
		};

		class SCT_ITEMINFO{
			plateinfo[] = {"United Shield Zeta-6H Level IV", 0};
			enableparts[] = {0,0,14,14,14,6,0,0,0};
			blunttraumaPad[] = {0,0,1.8,1.8,1.8,1,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_titanium_MILIV: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) DARPA TI-CER MIL-IV";
		picture = "\SCT\addons\SonicT_vest\data\titanoceramic.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: DARPA<br />Rating: MIL-IV, Titanium Diboride<br />Introduced: Late 2000s<br />Will withstand repeat 30-06 M2AP";

		class ItemInfo: ItemInfo {
			mass = 96;
		};

		class SCT_ITEMINFO{
			plateinfo[] = {"DARPA MIL-IV", 0.1};
			enableparts[] = {0,0,14,14,14,0,0,0,0};
			blunttraumaPad[] = {0,0,2.8,2.8,2.8,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_titanium_MILIVS: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) DARPA TI-CER MIL-IV/MC";
		picture = "\SCT\addons\SonicT_vest\data\titanoceramric.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: DARPA<br />Rating: MIL-IV, Titanium Diboride<br />Introduced: Late 2000s<br />Built for heavy riot control";

		class ItemInfo: ItemInfo {
			mass = 130;
		};

		class SCT_ITEMINFO{
			plateinfo[] = {"DARPA MIL-VA", 0.1};
			enableparts[] = {0,12,14,14,14,14,0,0,0};
			blunttraumaPad[] = {0,3.2,3.4,3.4,3.4,3.4,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_titanium_MILVA: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) DARPA TI-CER MIL-VA";
		picture = "\SCT\addons\SonicT_vest\data\titanoceramic.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: DARPA<br />Rating: MIL-VA, Titanium Diboride<br />Introduced: Late 2000s<br />Will withstand M993 or M995";

		class ItemInfo: ItemInfo {
			mass = 110;
		};

		class SCT_ITEMINFO{
			plateinfo[] = {"DARPA MIL-VA", 0.1};
			enableparts[] = {0,0,17,17,17,0,0,0,0};
			blunttraumaPad[] = {0,0,2.8,2.8,2.8,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_titanium_MILV: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) DARPA TI-CER MIL-V";
		picture = "\SCT\addons\SonicT_vest\data\titanoceramic.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: DARPA<br />Rating: MIL-V, Titanium Diboride<br />Introduced: Late 2000s<br />Will withstand repeat 9.3x64mm Brenneke";

		class ItemInfo: ItemInfo {
			mass = 130;
		};

		class SCT_ITEMINFO{
			plateinfo[] = {"DARPA MIL-V", 0.2};
			enableparts[] = {0,0,22,22,22,0,0,0,0};
			blunttraumaPad[] = {0,0,2.8,2.8,2.8,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_titanium_MILVS: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) DARPA RIOT-TI MIL-VS";
		picture = "\SCT\addons\SonicT_vest\data\titanoceramric.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: DARPA<br />Rating: MIL-VS, Titanium Diboride<br />Introduced: Late 2000s<br />Urban Warfare/Riot Control";

		class ItemInfo: ItemInfo {
			mass = 182;
		};

		class SCT_ITEMINFO{
			plateinfo[] = {"DARPA MIL-VS Riot", 0.2};
			enableparts[] = {0,0,24,24,24,0,0,0,0};
			blunttraumaPad[] = {0,0,3.8,3.8,3.8,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_titanium_MILVI: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) DARPA TI-CER MIL-VI";
		picture = "\SCT\addons\SonicT_vest\data\titanoceramic.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: DARPA<br />Rating: MIL-VI, Titanium Diboride<br />Introduced: Late 2000s<br />Withstands .338 API526";

		class ItemInfo: ItemInfo {
			mass = 156;
		};

		class SCT_ITEMINFO{
			plateinfo[] = {"DARPA MIL-VI", 0};
			enableparts[] = {0,0,35,35,35,0,0,0,0};
			blunttraumaPad[] = {0,0,2.8,2.8,2.8,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_titanium_MILVII: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) DARPA TI-CER MIL-VII";
		picture = "\SCT\addons\SonicT_vest\data\titanoceramic.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: DARPA<br />Rating: MIL-VII, Titanium Diboride<br />Introduced: Late 2000s<br />Withstands .408 at-range";

		class ItemInfo: ItemInfo {
			mass = 184;
		};

		class SCT_ITEMINFO{
			plateinfo[] = {"DARPA MIL-VII", 0.2};
			enableparts[] = {0,0,59,59,59,0,0,0,0};
			blunttraumaPad[] = {0,0,2.8,2.8,2.8,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_titanium_MILVIII: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) DARPA TI-CER MIL-VIII";
		picture = "\SCT\addons\SonicT_vest\data\titanoceramic.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: DARPA<br />Rating: MIL-VIII, Titanium Diboride<br />Introduced: Late 2000s<br />.50 BMG Protective";

		class ItemInfo: ItemInfo {
			mass = 230;
		};

		class SCT_ITEMINFO{
			plateinfo[] = {"DARPA MIL-VIII", 0.2};
			enableparts[] = {0,0,189,189,189,0,0,0,0};
			blunttraumaPad[] = {0,0,3.8,3.8,3.8,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_titanium_MILIX: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) DARPA TI-CER MIL-IX";
		picture = "\SCT\addons\SonicT_vest\data\titanoceramic.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: DARPA, RoboCop<br />Rating: MIL-IX, Titanium Diboride<br />Introduced: Late 2000s<br />.50 BMG APDS Protective";

		class ItemInfo: ItemInfo {
			mass = 280;
		};

		class SCT_ITEMINFO{
			plateinfo[] = {"DARPA MIL-IX", 0};
			enableparts[] = {0,0,209,209,209,0,0,0,0};
			blunttraumaPad[] = {0,0,9.8,9.8,9.8,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_titanium_MILX: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) DARPA TI-CER MIL-X";
		picture = "\SCT\addons\SonicT_vest\data\titanoceramic.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: DARPA, The Terminator<br />Rating: MIL-X, Titanium Diboride<br />Introduced: Late 2000s<br />20x110mm Protective";

		class ItemInfo: ItemInfo {
			mass = 320;
		};

		class SCT_ITEMINFO{
			plateinfo[] = {"DARPA MIL-X", 0};
			enableparts[] = {0,0,269,269,269,0,0,0,0};
			blunttraumaPad[] = {0,0,10,10,10,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_ceramic_ffs4: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) FFS4 Level IV+";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Contractors, Civilians, PMCs<br />Rating: NIJ Level IV+<br />Introduced: 2000s<br />Will withstand M61 7.62x51mm AP Ball";

		class ItemInfo: ItemInfo {
			mass = 152;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"FFS4 IV+", 0};
			enableparts[] = {0,0,15,15,15,0,0,0,0};
			blunttraumaPad[] = {0,0,1,1,1,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_ceramic_SAmix: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) BBA SA Mix";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Armed Forces of South Africa<br />Rating: Unrated<br />Introduced: 2000s<br />Will withstand repeat M193 5.56x45mm Ball";

		class ItemInfo: ItemInfo {
			mass = 86;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"SA Mix Plate", 0};
			enableparts[] = {0,0,10,10,10,0,0,0,0};
			blunttraumaPad[] = {0,0,1,1,1,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_ceramic_SAIII: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) BBA Level III";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Armed Forces of South Africa<br />Rating: NIJ Level III<br />Introduced: 2000s<br />Will withstand repeat 7.62x51mm Ball";

		class ItemInfo: ItemInfo {
			mass = 112;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"BBA III", 0};
			enableparts[] = {0,0,11,11,11,0,0,0,0};
			blunttraumaPad[] = {0,0,1.3,1.3,1.3,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_ceramic_SAIV: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) BBA IV";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Armed Forces of South Africa<br />Rating: NIJ Level IV<br />Introduced: 2000s<br />Will withstand 30-06 M2AP";

		class ItemInfo: ItemInfo {
			mass = 144;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"BBA IV", 0};
			enableparts[] = {0,0,14,14,14,0,0,0,0};
			blunttraumaPad[] = {0,0,1.3,1.3,1.3,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_ceramic_bushtracker: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) BBA Bushtracker";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Armed Forces of South Africa<br />Rating: Unrated<br />Introduced: 2000s<br />Will withstand Elephant Rifle cartridges";

		class ItemInfo: ItemInfo {
			mass = 170;
		};

		class SCT_ITEMINFO{
			plateinfo[] = {"BBA Bushtracker", 0};
			enableparts[] = {0,0,0,22,22,0,0,0,0};
			blunttraumaPad[] = {0,0,0,4,4,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_titanium_6b3tm: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) 6B3TM GOST 4";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Former Warsaw Pact Nations<br />Rating: GOST Class 4, Titanium<br />Introduced: 1984<br />Will withstand 7.62x39mm Steel-core rounds";

		class ItemInfo: ItemInfo {
			mass = 110;
		};

		class SCT_ITEMINFO{
			plateinfo[] = {"6B3TM GOST 4", 2};
			enableparts[] = {0,0,11,11,11,0,0,0,0};
			blunttraumaPad[] = {0,0,1,1,1,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};		
	};
	
	//update Oct 8
	class SCT_plate_titanium_6b3tm01: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) 6B3TM01 GOST 5";
		picture = "\SCT\addons\SonicT_vest\data\6b3tm.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "GOST 5 standalone plate, titanium";

		class ItemInfo: ItemInfo {
			mass = 60;
		};

		class SCT_ITEMINFO{
			plateinfo[] = {"6B3TM01 GOST 5", 1};
			enableparts[] = {0,0,14,12,14,0,0};
			blunttraumaPad[] = {0,0,1.25,1.25,1.25,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};		
	};
	
	class SCT_plate_ceramic_ceradyne: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) Ceradyne MIL-VIII";
		picture = "\SCT\addons\SonicT_vest\data\ceradyne2.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: United States Military<br />Rating: MIL-VIII<br />Introduced: 1994<br />.50 BMG Protective";

		class ItemInfo: ItemInfo {
			mass = 280;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-VIII Ceradyne .50 BMG Protective", 0};
			enableparts[] = {0,0,170,170,170,0,0,0,0};
			blunttraumaPad[] = {0,0,9,9,9,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_ceramic_DU: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) DU-00 MIL-IXS";
		picture = "\SCT\addons\SonicT_vest\data\ceradyne2.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: I'm not really sure...<br />Rating: MIL-IX, Depleted Uranium<br />Introduced: 2017<br />14.5x114mm Rated";

		class ItemInfo: ItemInfo {
			mass = 390;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-IXS 14.5x114mm Protective", 0};
			enableparts[] = {0,0,270,270,270,7,0,0,0};
			blunttraumaPad[] = {0,0,12,12,12,0.3,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_poly_DFNDR: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) DFNDR Level III+";
		picture = "\SCT\addons\SonicT_vest\data\SCT_poly_dfndr_3p.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_poly_dfndr_3p.p3d"
		descriptionShort = "Used By: Civilians, Law Enforcement<br />Rating: NIJ Level III+<br />Introduced: 2000s<br />Rated for 7.62x51mm Ball impacts";

		class ItemInfo: ItemInfo {
			mass = 56;
		};

		class SCT_ITEMINFO{
			plateinfo[] = {"DEFENDER Lightweight Level III+", 1};
			enableparts[] = {0,0,11,11,11,0,0,0,0};
			blunttraumaPad[] = {0,0,0.9,0.9,0.9,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_poly_speedplate: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) SPEED-Plate Level IIIA";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_poly_dfndr_3p.p3d"
		descriptionShort = "Used By: Civilians, Mall Ninjas<br />Rating: NIJ Level IIIA<br />Introduced: 2010s<br />Rated for 12-gauge Slugs";

		class ItemInfo: ItemInfo {
			mass = 40;
		};

		class SCT_ITEMINFO{
			plateinfo[] = {"SPEED-Plate Level IIIA", 1};
			enableparts[] = {0,0,9,10,9,0,0,0,0};
			blunttraumaPad[] = {0,0,0.9,0.9,0.9,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_poly_PACA: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) PACA Blade Plate";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_poly_dfndr_3p.p3d"
		descriptionShort = "Used By: Corrections Officer<br />Rating: Shank-proof<br />Introduced: 2010s<br />Don't drop the soap!";

		class ItemInfo: ItemInfo {
			mass = 22;
		};

		class SCT_ITEMINFO{
			plateinfo[] = {"Blade Plate", 1};
			enableparts[] = {0,0,1,1,1,0,0,0,0};
			blunttraumaPad[] = {0,0,1.2,1.2,1.2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_trauma_AR500: SonicT_Item_Base {
		scope = 2;
		displayName = "(Trauma) AR500 Trauma Pad";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Civilians, SWAT<br />Rating: Non-ballistic<br />Introduced: 2010s<br />Increases chances of survival";

		class ItemInfo: ItemInfo {
			mass = 15;
		};

		class SCT_ITEMINFO{
			plateinfo[] = {"Class 2 Trauma Pad", 3};
			enableparts[] = {0,0,0.1,0.1,0.1,0,0,0,0};
			blunttraumaPad[] = {0,0,2.2,2.2,2.2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_trauma_Spartan: SonicT_Item_Base {
		scope = 2;
		displayName = "(Trauma) Spartan Trauma Pad";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Civilians, Survivalists<br />Rating: Non-ballistic<br />Introduced: 2010s<br />Absorbs impact force to aid in withstanding high-powered rounds";

		class ItemInfo: ItemInfo {
			mass = 20;
		};

		class SCT_ITEMINFO{
			plateinfo[] = {"Class 3 Trauma Pad", 3};
			enableparts[] = {0,0,0.7,0.7,0.7,0,0,0,0};
			blunttraumaPad[] = {0,0,3.2,3.2,3.2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_trauma_Spartanf: SonicT_Item_Base {
		scope = 2;
		displayName = "(Trauma) Heavy Trauma Pad";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Civilians, Survivalists<br />Rating: Non-ballistic<br />Introduced: 2010s<br />Absorbs impact force to aid in withstanding high-powered rounds";

		class ItemInfo: ItemInfo {
			mass = 36;
		};

		class SCT_ITEMINFO{
			plateinfo[] = {"Class 5 Trauma Pad", 3};
			enableparts[] = {0,0,0.7,0.7,0.7,0,0,0,0};
			blunttraumaPad[] = {0,0,6.2,6.2,6.2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_poly_speedplate3: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) SPEED-Plate Level III";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_poly_dfndr_3p.p3d"
		descriptionShort = "Used By: First Responders, Law Enforcement<br />Rating: NIJ Level III<br />Introduced: 2010s<br />Rated for 5.56x45mm M193";

		class ItemInfo: ItemInfo {
			mass = 44;
		};

		class SCT_ITEMINFO{
			plateinfo[] = {"SPEED-Plate Level III", 1};
			enableparts[] = {0,0,11,11,11,0,0,0,0};
			blunttraumaPad[] = {0,0,0.5,0.4,0.4,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_poly_speedplate4: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) Paraclete #20015 Level IV";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_poly_dfndr_3p.p3d"
		descriptionShort = "Used By: Civilians, Law Enforcement<br />Rating: NIJ Level IV<br />Introduced: 2010s<br />Rated for 30-06 M2AP";

		class ItemInfo: ItemInfo {
			mass = 170;
		};

		class SCT_ITEMINFO{
			plateinfo[] = {"Paraclete Level IV", 0};
			enableparts[] = {0,0,14,14,14,0,0,0,0};
			blunttraumaPad[] = {0,0,1.2,1.2,1.2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_poly_speedplate4plus: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) Paraclete LV7200 Level IV+";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_poly_dfndr_3p.p3d"
		descriptionShort = "Used By: Civilians, Law Enforcement<br />Rating: Level IV+<br />Introduced: 2010s<br />Rated for .300 WM";

		class ItemInfo: ItemInfo {
			mass = 180;
		};

		class SCT_ITEMINFO{
			plateinfo[] = {"Paraclete Level IV+", 0};
			enableparts[] = {0,0,16,16,16,0,0,0,0};
			blunttraumaPad[] = {0,0,1.34,1.34,1.35,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_poly_JD: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) JD Level IV";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Civilians<br />Rating: NIJ Level IV<br />Introduced: 2010s<br />Rated for 30-06 M2AP";

		class ItemInfo: ItemInfo {
			mass = 78;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"JD Level IV Polyethylene", 1};
			enableparts[] = {0,0,14,14,14,0,0,0,0};
			blunttraumaPad[] = {0,0,0.9,0.9,0.9,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_poly_PSAPI: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) SPEAR MIL-III";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Civilians<br />Rating: NIJ Level III, Polyethylene<br />Introduced: 2010s<br />Rated for .308";

		class ItemInfo: ItemInfo {
			mass = 84;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"SPEAR MIL-III Polyethylene", 1};
			enableparts[] = {0,0,10,10,10,0,0,0,0};
			blunttraumaPad[] = {0,0,0.9,0.9,0.9,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_poly_m1199: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) RMA Level IV";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Civilians<br />Rating: NIJ Level IV<br />Introduced: 2010s<br />Rated for 30-06 M2AP";

		class ItemInfo: ItemInfo {
			mass = 90;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"RMA Level IV Polyethylene panel", 1};
			enableparts[] = {0,0,15,15,15,0,0,0,0};
			blunttraumaPad[] = {0,0,1,1,1,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_plate_poly_angel_308S: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) 308S Level III-S";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Civilians, Contractors<br />Rating: NIJ Level III<br />Introduced: 2010s<br />Rated for .308<br />Small 5x8 model";

		class ItemInfo: ItemInfo {
			mass = 45;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"RMA Level IV Polyethylene panel", 1};
			enableparts[] = {0,0,0,10,10,0,0,0,0};
			blunttraumaPad[] = {0,0,0,1,1,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_uniform_underwear: SonicT_Item_Base {
		scope = 2;
		displayName = "(UniformArmor) Ballistic Underwear";
		picture = "\SCT\addons\SonicT_vest\data\underwear.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Level II Underwear";

		class ItemInfo: ItemInfo {
			mass = 24;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"Level II Underwear", 0};
			enableparts[] = {0,0,0,0,0,4,0,0,0};
			blunttraumaPad[] = {0,0,0,0,0,1,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_uniform_underwear3: SonicT_Item_Base {
		scope = 2;
		displayName = "(UniformArmor) Ballistic Underwear UP";
		picture = "\SCT\addons\SonicT_vest\data\underwear.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Level IIIA Underwear";

		class ItemInfo: ItemInfo {
			mass = 32;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"Level IIIA Underwear", 0};
			enableparts[] = {0,0,0,0,0,9,0,0,0};
			blunttraumaPad[] = {0,0,0,0,0,1,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_uniform_kevlarinsert1: SonicT_Item_Base {
		scope = 2;
		displayName = "(UniformInsert) Level II Kevlar Insert";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Level II Kevlar Insert";

		class ItemInfo: ItemInfo {
			mass = 50;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"Level II Kevlar Insert", 1};
			enableparts[] = {3,3,0,0,0,3,3,0,0};
			blunttraumaPad[] = {1,1,0,0,0,1,1,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_uniform_kevlarinsert3: SonicT_Item_Base {
		scope = 2;
		displayName = "(UniformInsert) Level IIIA Kevlar Insert";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Level IIIA Kevlar Insert";

		class ItemInfo: ItemInfo {
			mass = 66;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"Level IIIA Kevlar Insert", 1};
			enableparts[] = {5,5,0,0,0,5,5,0,0};
			blunttraumaPad[] = {1,1,0,0,0,1,1,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_uniform_teiinsert3: SonicT_Item_Base {
		scope = 2;
		displayName = "(UniformInsert) Level IIIA Teijin Aramid";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Level IIIA Teijin Aramid Insert";

		class ItemInfo: ItemInfo {
			mass = 66;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"Level IIIA Teijin Aramid", 1};
			enableparts[] = {7,7,0,0,0,7,7,0,0};
			blunttraumaPad[] = {1,1,0,0,0,1,1,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_uniform_barmitsa: SonicT_Item_Base {
		scope = 2;
		displayName = "(UniformInsert) Level III RATNIK";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Level III Russian Body Armor Upgrade";

		class ItemInfo: ItemInfo {
			mass = 95;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"Level III RATNIK-Barmitsa", 1};
			enableparts[] = {10,10,0,0,0,10,10,0,0};
			blunttraumaPad[] = {1.1,1.1,0,0,0,1.2,1.2,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_uniform_KEV3: SonicT_Item_Base {
		scope = 2;
		displayName = "(UniformInsert) Level III Kevlar";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Level III Kevlar UP";

		class ItemInfo: ItemInfo {
			mass = 95;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"Level III Kevlar", 1};
			enableparts[] = {10,10,0,0,0,10,10,0,0};
			blunttraumaPad[] = {1,1,0,0,0,1,1,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_uniform_traumac2: SonicT_Item_Base {
		scope = 2;
		displayName = "(UniformInsert) Class II Trauma Cover";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Full-body trauma padding, non-ballistic.";

		class ItemInfo: ItemInfo {
			mass = 25;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"Class II Trauma Cover", 1};
			enableparts[] = {1,1,0,0,0,1,1,0,0};
			blunttraumaPad[] = {2,2,0,0,0,2,2,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_uniform_traumac3: SonicT_Item_Base {
		scope = 2;
		displayName = "(UniformInsert) Class III Trauma Cover";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Full-body trauma padding, non-ballistic.";

		class ItemInfo: ItemInfo {
			mass = 45;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"Class III Trauma Cover", 1};
			enableparts[] = {1,1,0,0,0,1,1,0,0};
			blunttraumaPad[] = {3,3,0,0,0,3,3,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_uniform_OVR: SonicT_Item_Base {
		scope = 2;
		displayName = "(UniformInsert) Level IV OVR-UP";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Level IV Russian Sapper Uniform Upgrade<br />Urban Warfare Type";

		class ItemInfo: ItemInfo {
			mass = 110;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"Level IV OVR-UP", 1};
			enableparts[] = {17,17,0,0,0,17,17,0,0};
			blunttraumaPad[] = {1.5,1.5,0,0,0,1.5,1.5,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_uniform_OVR2: SonicT_Item_Base {
		scope = 2;
		displayName = "(UniformInsert) MIL-V Assault UP";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "MIL-V Aramid Uniform Upgrade, Assault-Type";

		class ItemInfo: ItemInfo {
			mass = 150;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-V Assault UP", 1};
			enableparts[] = {22,22,0,0,0,22,22,0,0};
			blunttraumaPad[] = {3,3,0,0,0,3,3,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_uniform_CAPTAINPRICESIR: SonicT_Item_Base {
		scope = 2;
		displayName = "(UniformInsert) MIL-VI Juggernaut UP";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "MIL-VI Aramid Uniform Upgrade, Juggernaut-Type";

		class ItemInfo: ItemInfo {
			mass = 220;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-VI Juggernaut UP", 0};
			enableparts[] = {30,30,0,0,0,30,30,15,15};
			blunttraumaPad[] = {4,4,0,0,0,4,4,1.5,1.5};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_uniform_GAZWHERETHEHELLISTHATHELICOPTER: SonicT_Item_Base {
		scope = 2;
		displayName = "(UniformInsert) MIL-VII Juggernaut+ UP";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "MIL-VII Aramid Uniform Upgrade, Assault Juggernaut-Type";

		class ItemInfo: ItemInfo {
			mass = 290;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-VII Juggernaut+ UP", 0};
			enableparts[] = {50,50,50,50,50,50,50,25,25};
			blunttraumaPad[] = {5,5,5,5,5,5,5,1.5,1.5};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_uniform_DOYOUHAVETHEDSM: SonicT_Item_Base {
		scope = 2;
		displayName = "(UniformInsert) MIL-VIII Panzersoldat";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "MIL-VIII Aramid Uniform Upgrade, Ubernaut-Type";

		class ItemInfo: ItemInfo {
			mass = 360;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-VIII Panzersoldat", 0};
			enableparts[] = {170,170,170,170,170,170,50,25,25};
			blunttraumaPad[] = {7,7,7,7,7,7,7,2.5,2.5};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_uniform_kevlarinsertweak: SonicT_Item_Base {
		scope = 2;
		displayName = "(UniformInsert) Level I Kevlar Insert";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Level I Kevlar Insert";

		class ItemInfo: ItemInfo {
			mass = 30;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"Level I Kevlar Insert", 1};
			enableparts[] = {1,2,0,0,0,2,1,0,0};
			blunttraumaPad[] = {0.7,0,0,0,0.7,0.7,1,0.7,0.7};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_special_realismweight5: SonicT_Item_Base {
		scope = 2;
		displayName = "(PlateMisc)5LB Combat Weight";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Five-Pound Combat Weight, for increasing realism.";

		class ItemInfo: ItemInfo {
			mass = 50;
		};
	};
	
	class SCT_special_realismweight10: SonicT_Item_Base {
		scope = 2;
		displayName = "(PlateMisc)10LB Combat Weight";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Ten-Pound Combat Weight, for increasing realism.";

		class ItemInfo: ItemInfo {
			mass = 100;
		};
	};
	
	class SCT_special_realismweight20: SonicT_Item_Base {
		scope = 2;
		displayName = "(PlateMisc)20LB Combat Weight";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Twenty-Pound Combat Weight, for increasing realism.";

		class ItemInfo: ItemInfo {
			mass = 200;
		};
	};
	
	class SCT_special_realismweight15: SonicT_Item_Base {
		scope = 2;
		displayName = "(PlateMisc)15LB Combat Weight";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Fifteen-Pound Combat Weight, for increasing realism.";

		class ItemInfo: ItemInfo {
			mass = 150;
		};
	};
	
	class SCT_booster_helmetface3a: SonicT_Item_Base {
		scope = 2;
		displayName = "(Booster) NIJ IIIA Helmet Booster";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Reinforcement for helmet that includes headshot protection";

		class ItemInfo: ItemInfo {
			mass = 34;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"NIJ IIIA", 2};
			enableparts[] = {0,0,0,0,0,0,0,6,0};
			blunttraumaPad[] = {0,0,0,0,0,0,0,0.8,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_booster_helmetface2: SonicT_Item_Base {
		scope = 2;
		displayName = "(Booster) NIJ II Helmet Booster";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Reinforcement for helmet that includes headshot protection";

		class ItemInfo: ItemInfo {
			mass = 25;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"NIJ II", 2};
			enableparts[] = {0,0,0,0,0,0,0,4,0};
			blunttraumaPad[] = {0,0,0,0,0,0,0,0.7,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_booster_helmetface3: SonicT_Item_Base {
		scope = 2;
		displayName = "(Booster) NIJ III Helmet Booster";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Helmet reinforcement";

		class ItemInfo: ItemInfo {
			mass = 40;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"NIJ III", 2};
			enableparts[] = {0,0,0,0,0,0,0,11,0};
			blunttraumaPad[] = {0,0,0,0,0,0,0,0.9,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_booster_helmetfacetrauma: SonicT_Item_Base {
		scope = 2;
		displayName = "(Booster) Class 3 Helmet Insulation";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Ballistic insulation that serves to distribute impact force. Non-ballistic.";

		class ItemInfo: ItemInfo {
			mass = 21;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"Class 3 non-ballistic.", 2};
			enableparts[] = {0,0,0,0,0,0,0,1,0};
			blunttraumaPad[] = {0,0,0,0,0,0,0,1.8,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_booster_helmetface4: SonicT_Item_Base {
		scope = 2;
		displayName = "(Booster) NIJ IV Helmet Booster";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Heavy Helmet Reinforcement";

		class ItemInfo: ItemInfo {
			mass = 56;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"NIJ IV", 2};
			enableparts[] = {0,0,0,0,0,0,0,14,0};
			blunttraumaPad[] = {0,0,0,0,0,0,0,0.9,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_booster_helmetface5: SonicT_Item_Base {
		scope = 2;
		displayName = "(Booster) MIL-V Helmet Booster";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Super-heavy Helmet Reinforcement";

		class ItemInfo: ItemInfo {
			mass = 60;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-V", 2};
			enableparts[] = {0,0,0,0,0,0,0,19,0};
			blunttraumaPad[] = {0,0,0,0,0,0,0,1.1,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_booster_helmetface5s: SonicT_Item_Base {
		scope = 2;
		displayName = "(Booster) MIL-VS Helmet Booster";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Ultra-heavy Helmet Reinforcement";

		class ItemInfo: ItemInfo {
			mass = 80;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-VS", 2};
			enableparts[] = {0,0,0,0,0,0,0,22,0};
			blunttraumaPad[] = {0,0,0,0,0,0,0,1.7,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_booster_helmetface6: SonicT_Item_Base {
		scope = 2;
		displayName = "(Booster) MIL-VI Helmet Booster";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Juggernaut Helmet Reinforcement";

		class ItemInfo: ItemInfo {
			mass = 100;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-VI", 2};
			enableparts[] = {0,0,0,0,0,0,0,30,0};
			blunttraumaPad[] = {0,0,0,0,0,0,0,2.7,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_booster_helmetface7: SonicT_Item_Base {
		scope = 2;
		displayName = "(Booster) MIL-VII Helmet Booster";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Assault Juggernaut Helmet Reinforcement";

		class ItemInfo: ItemInfo {
			mass = 100;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-VII", 2};
			enableparts[] = {0,0,0,0,0,0,0,40,0};
			blunttraumaPad[] = {0,0,0,0,0,0,0,3.7,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_booster_face3: SonicT_Item_Base {
		scope = 2;
		displayName = "(Booster) NIJ III Headshot Guard";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Reinforces your face to Level III Standard";

		class ItemInfo: ItemInfo {
			mass = 30;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"NIJ III", 2};
			enableparts[] = {0,0,0,0,0,0,0,0,11};
			blunttraumaPad[] = {0,0,0,0,0,0,0,0,2};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_booster_face3a: SonicT_Item_Base {
		scope = 2;
		displayName = "(Booster) NIJ IIIA Headshot Guard";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Reinforces your face to Level IIIA Standard";

		class ItemInfo: ItemInfo {
			mass = 24;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"NIJ IIIA", 2};
			enableparts[] = {0,0,0,0,0,0,0,0,9};
			blunttraumaPad[] = {0,0,0,0,0,0,0,0,2};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_booster_face2: SonicT_Item_Base {
		scope = 2;
		displayName = "(Booster) NIJ II Headshot Guard";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Reinforces your face to Level II Standard";

		class ItemInfo: ItemInfo {
			mass = 20;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"NIJ IIIA", 2};
			enableparts[] = {0,0,0,0,0,0,0,0,6};
			blunttraumaPad[] = {0,0,0,0,0,0,0,0,2};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_booster_face4: SonicT_Item_Base {
		scope = 2;
		displayName = "(Booster) NIJ IV Headshot Guard";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Reinforces your face to Level IV Standard";

		class ItemInfo: ItemInfo {
			mass = 38;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"NIJ IV", 2};
			enableparts[] = {0,0,0,0,0,0,0,0,15};
			blunttraumaPad[] = {0,0,0,0,0,0,0,0,2};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_booster_face5: SonicT_Item_Base {
		scope = 2;
		displayName = "(Booster) MIL-V Headshot Guard";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Reinforces your face to MIL-V Standard";

		class ItemInfo: ItemInfo {
			mass = 52;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-V", 2};
			enableparts[] = {0,0,0,0,0,0,0,0,20};
			blunttraumaPad[] = {0,0,0,0,0,0,0,0,2};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_booster_face6: SonicT_Item_Base {
		scope = 2;
		displayName = "(Booster) MIL-VI Headshot Guard";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Reinforces your face to MIL-VI Standard";

		class ItemInfo: ItemInfo {
			mass = 80;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-VI", 2};
			enableparts[] = {0,0,0,0,0,0,0,0,30};
			blunttraumaPad[] = {0,0,0,0,0,0,0,0,3};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
	class SCT_booster_face7: SonicT_Item_Base {
		scope = 2;
		displayName = "(Booster) MIL-VII Headshot Guard";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Reinforces your face to MIL-VI Standard";

		class ItemInfo: ItemInfo {
			mass = 110;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-VII", 2};
			enableparts[] = {0,0,0,0,0,0,0,0,40};
			blunttraumaPad[] = {0,0,0,0,0,0,0,0,3};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
	
//override all vanilla body armor at most class iiia
	
	class CfgGlasses {
		class None;
	};
	
	class Vest_Camo_Base;
	class Vest_NoCamo_Base;
	class VestItem;
	class V_PlateCarrier1_rgr: Vest_NoCamo_Base { //NATO plate Carrier light.
		descriptionShort = "NIJ IIIA, plate attachable";
		class ItemInfo: VestItem {
			containerClass = "Supply500"; //vanilla 140. 2 sapi plates. 2* sapi is about 5.7kg. 2035 lightweight approx. 5kg
			mass = 20; //vanilla 60
			//armor = 100;
			class HitpointsProtectionInfo {

				
				class Chest {
					HitpointName = "HitChest";
					//armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD_LITE;
				};

				class Diaphragm {
					HitpointName = "HitDiaphragm";
					//armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD_LITE;
				};

				class Abdomen {
					hitpointName = "HitAbdomen";
					//armor = SCT_NIJIIIA_ARMOR;
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

		class ItemInfo: VestItem {
			uniformModel = "\A3\Characters_F\BLUFOR\equip_b_vest01";
			containerClass = "Supply500"; //vanilla 140. - plate protection
			mass = 60; //vanilla 100

			class HitpointsProtectionInfo {

				class Chest {
					HitpointName = "HitChest";
					//armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD;
				};

				class Diaphragm {
					HitpointName = "HitDiaphragm";
					//armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD;
				};

				class Abdomen {
					hitpointName = "HitAbdomen";
					//armor = SCT_NIJIIIA_ARMOR;
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

		class ItemInfo: VestItem {
			uniformModel = "\A3\Characters_F\BLUFOR\equip_b_vest01.p3d";
			containerClass = "Supply500"; //vanilla 140. - plate protection
			mass = 60; //vanilla 100

			class HitpointsProtectionInfo {

				class Chest {
					HitpointName = "HitChest";
					//armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD;
				};

				class Diaphragm {
					HitpointName = "HitDiaphragm";
					//armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD;
				};

				class Abdomen {
					hitpointName = "HitAbdomen";
					//armor = SCT_NIJIIIA_ARMOR;
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
		class ItemInfo: VestItem {
			containerClass = "Supply440"; //vanilla 140. did not increased that much since it is very heavy
			mass = 90; //IOTV full set (with pelvic protecion) is about 12kg. vanilla 100.

			class HitpointsProtectionInfo {

				class Neck {
					hitpointName = "HitNeck";
					//armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD_LITE;
				};

				class Arms {
					hitpointName = "HitArms";
					//armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD_LITE;
				};

				class Chest {
					hitpointName = "HitChest";
					//armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD;
				};

				class Diaphragm {
					hitpointName = "HitDiaphragm";
					//armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD;
				};

				class Abdomen {
					hitpointName = "HitAbdomen";
					//armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD;
				};

				class Pelvis {
					hitpointName = "HitPelvis";
					//armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD_LITE;
				};

				class Body {
					hitpointName = "HitBody";
					//passthrough = 0.600000;
				};
			};
		};
	};

	class V_PlateCarrier1_blk: Vest_Camo_Base {

		descriptionShort = "Plate attachable, No armor";

		class ItemInfo: VestItem {
			uniformModel = "\A3\Characters_F\BLUFOR\equip_b_vest02.p3d";
			containerClass = "Supply500";
			mass = 15;

			class HitpointsProtectionInfo {

				class Chest {
					HitpointName = "HitChest";
					//armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD_LITE;
				};

				class Diaphragm {
					HitpointName = "HitDiaphragm";
					//armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD_LITE;
				};

				class Abdomen {
					hitpointName = "HitAbdomen";
					//armor = SCT_NIJIIIA_ARMOR;
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

		class ItemInfo: VestItem {
			uniformModel = "\A3\Characters_F\BLUFOR\equip_b_carrier_spec_rig.p3d";
			containerClass = "Supply500";
			mass = 70; //made it less heavier than gl rig because there is no pelvic armor

			class HitpointsProtectionInfo {

				class Neck {
					hitpointName = "HitNeck";
					//armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD_LITE;
				};

				class Arms {
					hitpointName = "HitArms";
					//armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD_LITE;
				};

				class Chest {
					hitpointName = "HitChest";
					//armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD;
				};

				class Diaphragm {
					hitpointName = "HitDiaphragm";
					//armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD;
				};

				class Abdomen {
					hitpointName = "HitAbdomen";
					//armor = SCT_NIJIIIA_ARMOR;
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

		class ItemInfo: VestItem {
			containerClass = "Supply100";
			mass = SCT_NIJII_CMASS;

			class HitpointsProtectionInfo {

				class Chest {
					hitpointName = "HitChest";
					//armor = SCT_NIJII_ARMOR;
					//passthrough = SCT_TRAUMAPAD_LITE;
				};

				class Diaphragm {
					hitpointName = "HitDiaphragm";
					//armor = SCT_NIJII_ARMOR;
					//passthrough = SCT_TRAUMAPAD_LITE;
				};

				class Abdomen {
					hitpointName = "HitAbdomen";
					//armor = SCT_NIJII_ARMOR;
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

		class ItemInfo: VestItem {
			uniformModel = "A3\Characters_F\Common\equip_tacticalvest";
			containerClass = "Supply100";
			mass = SCT_NIJII_CMASS;

			class HitpointsProtectionInfo {

				class Chest {
					hitpointName = "HitChest";
					//armor = SCT_NIJIIIA_ARMOR
					//passthrough = SCT_TRAUMAPAD_LITE;
				};

				class Diaphragm {
					hitpointName = "HitDiaphragm";
					//armor = SCT_NIJIIIA_ARMOR
					//passthrough = SCT_TRAUMAPAD_LITE;
				};

				class Abdomen {
					hitpointName = "HitAbdomen";
					//armor = SCT_NIJIIIA_ARMOR
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

		descriptionShort = "NIJ IIIA";

		class ItemInfo: VestItem {
			uniformModel = "A3\Characters_F\Common\equip_tacticalvest";
			containerClass = "Supply100";
			mass = 30;

			class HitpointsProtectionInfo {

				class Chest {
					hitpointName = "HitChest";
					//armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD_LITE;
				};

				class Diaphragm {
					hitpointName = "HitDiaphragm";
					//armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD_LITE;
				};

				class Abdomen {
					hitpointName = "HitAbdomen";
					//armor = SCT_NIJIIIA_ARMOR;
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

		class ItemInfo: VestItem {
			uniformModel = "\A3\Characters_F_Beta\INDEP\equip_ir_vest01";
			containerClass = "Supply140";
			mass = SCT_NIJII_CMASS;

			class HitpointsProtectionInfo {

				class Chest {
					hitpointName = "HitChest";
					//armor = SCT_NIJII_ARMOR
					//passthrough = SCT_TRAUMAPAD_LITE;
				};

				class Diaphragm {
					hitpointName = "HitDiaphragm";
					//armor = SCT_NIJII_ARMOR
					//passthrough = SCT_TRAUMAPAD_LITE;
				};

				class Abdomen {
					hitpointName = "HitAbdomen";
					//armor = SCT_NIJII_ARMOR
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

		class ItemInfo: VestItem {

			containerClass = "Supply100";
			mass = SCT_NIJII_CMASS;

			class HitpointsProtectionInfo {

				class Chest {
					hitpointName = "HitChest";
					//armor = SCT_NIJII_ARMOR
					//passthrough = SCT_TRAUMAPAD_LITE;
				};

				class Diaphragm {
					hitpointName = "HitDiaphragm";
					//armor = SCT_NIJII_ARMOR
					//passthrough = SCT_TRAUMAPAD_LITE;
				};

				class Abdomen {
					hitpointName = "HitAbdomen";
					//armor = SCT_NIJII_ARMOR
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
		class ItemInfo: VestItem {
			containerClass = "Supply500"; //vanilla 140. 2 sapi plates. 2* sapi is about 5.7kg. 2035 lightweight approx. 5kg
			mass = 15; //vanilla 60

			class HitpointsProtectionInfo {

				class Chest {
					HitpointName = "HitChest";
					//armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD;
				};

				class Diaphragm {
					HitpointName = "HitDiaphragm";
					//armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD;
				};

				class Abdomen {
					hitpointName = "HitAbdomen";
					//armor = SCT_NIJIIIA_ARMOR;
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

		class ItemInfo: VestItem {
			uniformModel = "A3\Characters_F_Beta\INDEP\equip_ia_vest02";
			containerClass = "Supply500";
			mass = 55; //vanilla 80 - pelvic armors are heavy enough to protect your balls.

			class HitpointsProtectionInfo {

				class Chest {
					hitpointName = "HitChest";
					//armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD;
				};

				class Diaphragm {
					hitpointName = "HitDiaphragm";
					//armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD;
				};

				class Abdomen {
					hitpointName = "HitAbdomen";
					//armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD;
				};

				class Pelvis { //i really didn't know GA carrier rig have pelvic protection
					hitpointName = "HitPelvis";
					//armor = SCT_NIJIIIA_ARMOR
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

		class ItemInfo: VestItem {
			containerClass = "Supply500";
			mass = 80;


			class HitpointsProtectionInfo {

				class Neck {
					hitpointName = "HitNeck";
					//armor = SCT_NIJIIIA_ARMOR
					//passthrough = SCT_TRAUMAPAD_LITE;
				};

				class Arms {
					hitpointName = "HitArms";
					//armor = SCT_NIJIIIA_ARMOR
					//passthrough = SCT_TRAUMAPAD_LITE;
				};

				class Chest {
					hitpointName = "HitChest";
					//armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD;
				};

				class Diaphragm {
					hitpointName = "HitDiaphragm";
					//armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD;
				};

				class Abdomen {
					hitpointName = "HitAbdomen";
					//armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD;
				};

				class Pelvis {
					hitpointName = "HitPelvis";
					//armor = SCT_NIJIIIA_ARMOR;
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
		descriptionShort = "Rebreather with a littel protection";

	};

	class V_Press_F: Vest_Camo_Base {

		descriptionShort = "NIJ IIIA, plate attachable"; // I really didn't like about this vest because it looked like plate armor but it was not.

		class ItemInfo: VestItem {
			containerClass = "Supply80"; //minimal weights for the armor plates
			mass = 45;

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

	//this is to make auto-equip CSAT Units with uniform bodywear(Oct 07)
	class Uniform_Base;
	class UniformItem;
	class U_O_CombatUniform_ocamo: Uniform_Base{
		descriptionShort="CSAT Hex camo GOST level 2";
		class ItemInfo: UniformItem
		{
			containerClass="Supply100";
			mass=80;
		};
	};
	class U_O_CombatUniform_oucamo: Uniform_Base{
		descriptionShort="CSAT Urban camo GOST level 2";
		class ItemInfo: UniformItem
		{
			containerClass="Supply100";
			mass=80;
		};
	};
	
	class U_O_GhillieSuit: Uniform_Base{
		class ItemInfo: UniformItem
		{
			containerClass="Supply100";
			mass=80;
		};
	};
	
	class U_O_PilotCoveralls: Uniform_Base{
		class ItemInfo: UniformItem
		{
			containerClass="Supply100";
			mass=80;
		};
	};
	
	class U_O_Wetsuit: Uniform_Base{
		class ItemInfo: UniformItem
		{
			containerClass="Supply100";
			mass=80;
		};
	};
	
	class U_O_V_Soldier_Viper_F: Uniform_Base
	{
		class ItemInfo: UniformItem
		{
			containerClass="Supply120";
			mass=80;
		};
	};
	class U_O_V_Soldier_Viper_hex_F: Uniform_Base{
		class ItemInfo: UniformItem
		{
			containerClass="Supply120";
			mass=80;
		};
	};

};

