#include "BIS_AddonInfo.hpp"
#ifndef SCT_ARMOR_RATINGS
#define SCT_ARMOR_RATINGS 1
#define SCT_NIJII_CMASS 20
#define SCT_NIJII_ARMOR 5
#define SCT_NIJIIIA_CMASS 8
#define SCT_NIJIIIA_ARMOR 6
#define SCT_NIJIII_ARMOR 11
#define SCT_NIJIV_ARMOR 15
#define SCT_LITE_TRAUMAPAD 0.35
#define SCT_TRAUMAPAD 0.29
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
		name = "Sonic.T and V. Berlioz's full-spectrum body armor overhaul";
		overview = "stuff hard armor plates in your vest, to ensure your safety";
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
			mass = 106;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"ESAPI MIL-IV ceramic ICW", 0};
			enableparts[] = {0,0,14,14,14,0,0,0,0};
			blunttraumaPad[] = {0,0,2.1,2.1,2.1,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_isapi: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) ISAPI MIL-III+";
		picture = "\SCT\addons\SonicT_vest\data\sapi.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: United States Military<br />Rating: MIL-III Ceramic, Boron Carbide<br />Introduced: 2001<br />Will withstand .30 Ball";

		class ItemInfo: ItemInfo {
			mass = 102;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"Interceptor SAPI MIL-III+ Interim ICW", 0};
			enableparts[] = {0,0,12,12,12,0,0,0,0};
			blunttraumaPad[] = {0,0,2,2,2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_isapib: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) ISAPI/B MIL-IV*";
		picture = "\SCT\addons\SonicT_vest\data\hesapi.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: United States Military<br />Rating: MIL-IV* Ceramic, Boron Carbide<br />Introduced: ~2000-2004<br />Heavily-enhanced-protection against .30 Ball";

		class ItemInfo: ItemInfo {
			mass = 160;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"ISAPI/B MIL-IV* Ceramic Plate", 0};
			enableparts[] = {0,0,19,19,19,0,0,0,0};
			blunttraumaPad[] = {0,0,2,2,2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
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
			enableparts[] = {0,0,16,16,16,0,0,0,0};
			blunttraumaPad[] = {0,0,1.8,1.8,1.8,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
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
			plateinfo[] = {"ESAPI NIJ IV ceramic ICW, Maximum Coverage", 0};
			enableparts[] = {0,10,15,15,15,10,5,0,0};
			blunttraumaPad[] = {0,2,2,2,2,2,2,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
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
			plateinfo[] = {"XSAPI-2016 MIL-V Ceramic", 0};
			enableparts[] = {0,0,26,26,26,0,0,0,0};
			blunttraumaPad[] = {0,0,2.2,2.2,2.2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_xsapimc: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) XSAPI MIL-V/MC GEN3";
		picture = "\SCT\addons\SonicT_vest\data\xsapi.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: United States Military<br />Rating: MIL-V Ceramic, Boron Carbide<br />Introduced: 2016<br />Will withstand M993, M995, or 7N39<br />Maximum Coverage";

		class ItemInfo: ItemInfo {
			mass = 175;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"XSAPI-2016", 0};
			enableparts[] = {6,3,27,27,27,19,0,0,0};
			blunttraumaPad[] = {2,2,2,2,2,2,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
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
			plateinfo[] = {"XSAPI-2009 MIL-VA", 0};
			enableparts[] = {0,0,18,18,18,0,0,0,0};
			blunttraumaPad[] = {0,0,2,2,2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_xsapi2011: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) XSAPI MIL-V GEN2";
		picture = "\SCT\addons\SonicT_vest\data\xsapi.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: United States Military<br />Rating: MIL-V Ceramic, Boron Carbide<br />Introduced: 2011<br />Special Theater Contingency Plate";

		class ItemInfo: ItemInfo {
			mass = 132;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"XSAPI-2011 GEN2", 0};
			enableparts[] = {0,0,24,24,24,0,0,0,0};
			blunttraumaPad[] = {0,0,2.4,2.4,2.4,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_sapi: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) SAPI MIL-III";
		picture = "\SCT\addons\SonicT_vest\data\sapi.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: United States Military<br />Rating: MIL-III Ceramic, Boron Carbide<br />Introduced: 1998<br />Multi-hit resistant";

		class ItemInfo: ItemInfo {
			mass = 94;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"SAPI MIL-III ICW", 0};
			enableparts[] = {0,0,12,12,12,0,0,0,0};
			blunttraumaPad[] = {0,0,1.9,1.9,1.9,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_hesapi: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) H-ESAPI MIL-V";
		picture = "\SCT\addons\SonicT_vest\data\hesapi.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: US Air Force Pararescuemen<br />Rating: MIL-V Ceramic, Boron Carbide<br />Introduced: 2005<br />Rated to stop M993, M995, or 7N24";

		class ItemInfo: ItemInfo {
			mass = 155;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"H-ESAPI MIL-V", 0};
			enableparts[] = {12,0,28,28,28,0,0,0,0};
			blunttraumaPad[] = {2,0,2.3,2.3,2.3,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_hesapiT: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) H-ESAPI/ASTI MIL-VI";
		picture = "\SCT\addons\SonicT_vest\data\hesapi.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: US Air Force Pararescuemen<br />Rating: MIL-VI Ceramic, Boron Carbide<br />Introduced: 2005<br />Rated to stop .338 Lapua Magnum API526<br />Anti-Spalling and Thickness Increased";

		class ItemInfo: ItemInfo {
			mass = 250;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"H-ESAPI/Anti-Spalling-Thickness-Increased MIL-VI", 0};
			enableparts[] = {17,0,36,36,36,0,0,0,0};
			blunttraumaPad[] = {2,0,2.4,2.4,2.4,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_hesapimc: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) H-ESAPI MIL-V/MC";
		picture = "\SCT\addons\SonicT_vest\data\hesapi.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: US Air Force Pararescuemen<br />Rating: MIL-V Ceramic, Boron Carbide, Maximum Coverage<br />Introduced: 2005<br />Rated to stop M993, M995, or 7N24";

		class ItemInfo: ItemInfo {
			mass = 230;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"H-ESAPI MIL-V/MC", 0};
			enableparts[] = {12,5,28,28,28,12,0,0,0};
			blunttraumaPad[] = {2,1.4,2.3,2.3,2.3,2.3,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_isapo: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) ISAPO MIL-III";
		picture = "\SCT\addons\SonicT_vest\data\rba.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: United States Military<br />Rating: MIL-III Ceramic, Aluminum Oxide<br />Introduced: 1996<br />Will withstand 7.62x51mm Ball";

		class ItemInfo: ItemInfo {
			mass = 138;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"ISAPO MIL-III", 0};
			enableparts[] = {0,0,12,12,12,0,0,0,0};
			blunttraumaPad[] = {0,0,1.8,1.8,1.8,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_pru601: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) PRU-60/P22P-15 MIL-IIIA";
		picture = "\SCT\addons\SonicT_vest\data\pru60.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: American Aircrews<br />Rating: MIL-IIIA, Aluminum Oxide<br />Introduced: 1998<br />Will withstand light small-arms fire, 8x10";

		class ItemInfo: ItemInfo {
			mass = 112;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"PRU-60/P22P-15 Aircrew Plate", 0};
			enableparts[] = {0,0,10,10,5,0,0,0,0};
			blunttraumaPad[] = {0,0,3.2,3.2,2.1,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_pru611: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) PRU-61/P22P-15 MIL-IV";
		picture = "\SCT\addons\SonicT_vest\data\pru60.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: American Aircrews<br />Rating: MIL-IV, Aluminum Oxide<br />Introduced: 1998<br />Withstands repeat 30-06 M2AP, 8x10";

		class ItemInfo: ItemInfo {
			mass = 140;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"PRU-60/P22P-15 Aircrew Plate", 0};
			enableparts[] = {0,0,18,18,11,0,0,0,0};
			blunttraumaPad[] = {0,0,3.2,3.2,2.1,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_pru60A: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) PRU-60/A Airsafe MIL-VIII";
		picture = "\SCT\addons\SonicT_vest\data\pru60.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: American Aircrews<br />Rating: MIL-VIII, Aluminum Oxide<br />Introduced: 1998<br />.50 BMG Protective, 8x10";

		class ItemInfo: ItemInfo {
			mass = 210;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"PRU-60/A Airsafe Aircrew Plate", 0};
			enableparts[] = {0,0,10,160,10,0,0,0,0};
			blunttraumaPad[] = {0,0,3.2,5.2,2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_chicken: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) Chicken Plates MIL-III";
		picture = "\SCT\addons\SonicT_vest\data\doron.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: American Aircrews<br />Rating: MIL-III, Early Aluminum Oxide<br />Introduced: 1965<br />Will withstand repeat 7.62x39mm";

		class ItemInfo: ItemInfo {
			mass = 300;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"Chicken Plate Set - Non-Infantry MIL-III", 0};
			enableparts[] = {0,14,14,14,14,0,0,0,0};
			blunttraumaPad[] = {0,2.3,2.3,2.3,2.3,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_VBA: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) VBAGT/1 MIL-III";
		picture = "\SCT\addons\SonicT_vest\data\doron.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: 1st Cavalry<br />Rating: MIL-III Ceramic, Aluminum Oxide<br />Introduced: 1965<br />7.62x39mm Resistant";

		class ItemInfo: ItemInfo {
			mass = 220;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"Variable Body Armor", 0};
			enableparts[] = {0,0,14,14,14,0,0,0,0};
			blunttraumaPad[] = {0,0,1.3,1.3,1.3,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_VBA2: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) VBAGT/2 MIL-III";
		picture = "\SCT\addons\SonicT_vest\data\doron.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: Navy and Air Force<br />Rating: MIL-III Ceramic, Silicon Carbide<br />Introduced: 1965<br />7.62x39mm Resistant";

		class ItemInfo: ItemInfo {
			mass = 220;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"Variable Body Armor", 0};
			enableparts[] = {0,0,14,14,14,0,0,0,0};
			blunttraumaPad[] = {0,0,1.4,1.4,1.4,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_VBA3: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) VBAGT/3 MIL-III";
		picture = "\SCT\addons\SonicT_vest\data\doron.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: Navy and Air Force<br />Rating: MIL-III Ceramic, Boron Carbide<br />Introduced: 1965<br />7.62x39mm Resistant";

		class ItemInfo: ItemInfo {
			mass = 220;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"Variable Body Armor", 0};
			enableparts[] = {0,0,15.5,15.5,15.5,0,0,0,0};
			blunttraumaPad[] = {0,0,1.1,1.1,1.1,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_m1951: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) M1951 Level II-";
		picture = "\SCT\addons\SonicT_vest\data\doron.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: US Military, Korean War<br />Rating: Level II-, Doron Laminate<br />Introduced: 1951<br />Will withstand .45 ACP";

		class ItemInfo: ItemInfo {
			mass = 95;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"M1951 Doron Laminate Armor", 1};
			enableparts[] = {0,0,0,3.6,3.6,0,0,0,0};
			blunttraumaPad[] = {0,0,0,1,1,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_m1955: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) M1955 Level II-";
		picture = "\SCT\addons\SonicT_vest\data\doron.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: US Military, Vietnam War<br />Rating: Level II-, Doron Laminate<br />Introduced: 1955<br />Will withstand .45 ACP";

		class ItemInfo: ItemInfo {
			mass = 105;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"M1955 Doron Laminate Armor", 1};
			enableparts[] = {0,0,0,3.6,3.6,0,0,0,0};
			blunttraumaPad[] = {0,0,0,1,1,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_m1945: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) M1945 Level II-";
		picture = "\SCT\addons\SonicT_vest\data\doron.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: US Military, Battle of Okinawa<br />Rating: Level II-, Doron Laminate<br />Introduced: 1945<br />Will withstand Flak";

		class ItemInfo: ItemInfo {
			mass = 80;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"M1945 Doron Laminate Armor", 1};
			enableparts[] = {0,0,0,3.6,3.6,0,0,0,0};
			blunttraumaPad[] = {0,0,0,0.9,0.9,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_t522: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) T-52-2 Level II";
		picture = "\SCT\addons\SonicT_vest\data\doron.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: US Military, Vietnam War<br />Rating: Level II-, Doron Laminate<br />Introduced: 1952<br />Will withstand .45 ACP";

		class ItemInfo: ItemInfo {
			mass = 98;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"T-52-2 Doron Laminate Armor", 1};
			enableparts[] = {0,0,0,4,4,0,0,0,0};
			blunttraumaPad[] = {0,0,0,1.2,1.2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_dragonskin: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) DragonSkin Level III";
		picture = "\SCT\addons\SonicT_vest\data\dragonskin.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: PMCs and American Special Forces<br />Rating: NIJ Level III Ceramic, Scalar<br />Introduced: 1999<br />Highly resistant against multiple impacts";

		class ItemInfo: ItemInfo {
			mass = 155;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"SOV-2000 Level III", 0};
			enableparts[] = {5,0,13,13,13,6,0,0,0};
			blunttraumaPad[] = {1,0,3,3,3,3,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_dragonskinheavy: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) DragonSkin Level IV";
		picture = "\SCT\addons\SonicT_vest\data\dragonskin.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: PMCs and American Special Forces<br />Rating: NIJ Level IV Ceramic, Scalar<br />Introduced: 1999<br />Will withstand multiple IV-level threats";

		class ItemInfo: ItemInfo {
			mass = 160;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"SOV-3000 Level IV", 0};
			enableparts[] = {5,0,17,17,17,8,0,0,0};
			blunttraumaPad[] = {1,0,3,3,3,3,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_dragonskinheavyf: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) DragonSkin Level IV/MC";
		picture = "\SCT\addons\SonicT_vest\data\dragonskin.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Tier One Teams<br />Rating: NIJ Level IV Ceramic, Scalar<br />Introduced: 1999<br />Will withstand multiple IV-level threats<br />Maximum Coverage";

		class ItemInfo: ItemInfo {
			mass = 250;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"SOV-3000 Level IV/MC", 0};
			enableparts[] = {5,3,17,17,17,15,0,0,0};
			blunttraumaPad[] = {1.7,1,3,3,3,3,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_dragonskinassault: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) DragonSkin Level V";
		picture = "\SCT\addons\SonicT_vest\data\dragonskin.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Federal Government<br />Rating: MIL-V Ceramic, Scalar<br />Introduced: 1999<br />Will withstand M993, M948, BS40 API, and M995";

		class ItemInfo: ItemInfo {
			mass = 230;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"SOV-5000 Level V", 0};
			enableparts[] = {5,0,25,25,25,14,0,0,0};
			blunttraumaPad[] = {1,0,3,3,3,3,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_dragonskinassault2: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) DragonSkin Level V/MC";
		picture = "\SCT\addons\SonicT_vest\data\dragonskin.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Federal Government<br />Rating: MIL-V Ceramic, Scalar<br />Introduced: 1999<br />Will withstand M993, M948, BS40 API, and M995<br />Maximum Coverage";

		class ItemInfo: ItemInfo {
			mass = 300;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"SOV-5000 Level V/MC", 0};
			enableparts[] = {11,3,25,25,25,13,0,0,0};
			blunttraumaPad[] = {1.6,1,3,3,3,3,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_dragonskinx: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) DragonSkin Level VI";
		picture = "\SCT\addons\SonicT_vest\data\dragonskin.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Federal Government<br />Rating: MIL-VI Ceramic, Scalar<br />Introduced: 1999<br />Will withstand repeat .338 Lapua Magnum";

		class ItemInfo: ItemInfo {
			mass = 290;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"SOV-6000 Level VI", 0};
			enableparts[] = {10,0,32,32,32,21,0,0,0};
			blunttraumaPad[] = {1,0,3,3,3,3,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_dragonskinxmc: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) DragonSkin Level VI/MC";
		picture = "\SCT\addons\SonicT_vest\data\dragonskin.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Federal Government<br />Rating: MIL-VI Ceramic, Scalar<br />Introduced: 1999<br />Will withstand repeat .338 Lapua Magnum<br />Maximum Coverage";

		class ItemInfo: ItemInfo {
			mass = 320;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"SOV-6000 Level VI, Maximum Coverage", 0};
			enableparts[] = {32,12,32,32,32,32,0,0,0};
			blunttraumaPad[] = {3,2,3,3,3,3,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_dragonskinxd: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) DragonSkin Level VII";
		picture = "\SCT\addons\SonicT_vest\data\dragonskin.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Federal Government<br />Rating: MIL-VII Ceramic, Scalar<br />Introduced: 1999<br />Will withstand 12.7x55mm STs-130";

		class ItemInfo: ItemInfo {
			mass = 350;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"SOV-7000 Level VII", 0};
			enableparts[] = {15,0,52,52,52,25,0,0,0};
			blunttraumaPad[] = {1,0,3,3,3,3,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_RBA: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) Ranger Body Armor MIL-IV";
		picture = "\SCT\addons\SonicT_vest\data\rba.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: 75th Ranger Regiment<br />Rating: MIL-IV Ceramic, Aluminum Oxide<br />Introduced: Gothic Serpent, 1993<br />Will withstand multiple 7.62x51mm FMJ rounds";

		class ItemInfo: ItemInfo {
			mass = 145;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"Ranger Body Armor", 0};
			enableparts[] = {0,0,16,16,16,0,0,0,0};
			blunttraumaPad[] = {0,0,2.2,2.2,2.2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_RBAMC: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) Ranger Body Armor MIL-IV/MC";
		picture = "\SCT\addons\SonicT_vest\data\rba.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: 75th Ranger Regiment<br />Rating: MIL-IV Ceramic, Maximum Coverage, Aluminum Oxide<br />Introduced: Gothic Serpent, 1993<br />Will withstand multiple 7.62x51mm FMJ rounds.<br />Maximum Coverage";

		class ItemInfo: ItemInfo {
			mass = 220;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"Ranger Body Armor", 0};
			enableparts[] = {0,8,16,16,16,14,0,0,0};
			blunttraumaPad[] = {0,1,2.2,2.2,2.2,2.2,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_6b46: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) GOST-6A 6B46";
		picture = "\SCT\addons\SonicT_vest\data\6b45.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Russian Armed Forces<br />Rating: GOST 6A Ceramic, Boron Carbide<br />Introduced: 2016<br />Multiple-hit resistant against 7.62x54mm FMJ";

		class ItemInfo: ItemInfo {
			mass = 108;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"GOST-6A 6B46 Plate", 0};
			enableparts[] = {0,0,18,18,18,0,0,0,0};
			blunttraumaPad[] = {0,0,2,2,2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_6b46r2: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) GOST-6A 6B46/R2";
		picture = "\SCT\addons\SonicT_vest\data\6b45.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Russian Special Forces utilizing the Ratnik-II heavy armor systems.<br />Rating: GOST 6A Ceramic, Boron Carbide, Extended Coverage<br />Introduced: 2016<br />Multiple-hit resistant against 7.62x54mm FMJ";

		class ItemInfo: ItemInfo {
			mass = 150;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"GOST-6A 6B46 Plate", 0};
			enableparts[] = {0,6,18,18,18,12,5,0,0};
			blunttraumaPad[] = {0,1.5,2,2,2,2,1.2,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_6b45: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) GOST-6 6B45";
		picture = "\SCT\addons\SonicT_vest\data\6b45.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Russian Armed Forces<br />Rating: GOST 6 Ceramic, Boron Carbide<br />Introduced: 2015<br />Multiple-hit resistant against 7.62x54mm FMJ";

		class ItemInfo: ItemInfo {
			mass = 104;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"GOST-6 6B45 Plate", 0};
			enableparts[] = {0,0,16,16,16,0,0,0,0};
			blunttraumaPad[] = {0,0,2,2,2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_6b23: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) GOST-5 6B23";
		picture = "\SCT\addons\SonicT_vest\data\6b45.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Russian Armed Forces<br />Rating: GOST 5 Ceramic, Aluminum Oxide<br />Introduced: 2000s<br />Multiple-hit resistant against 7.62x39mm";

		class ItemInfo: ItemInfo {
			mass = 150;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"GOST-5 6B23 Plate", 0};
			enableparts[] = {0,0,14,14,14,0,0,0,0};
			blunttraumaPad[] = {0,0,1.8,1.8,1.8,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_6b23S: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) GOST-5A 6B23";
		picture = "\SCT\addons\SonicT_vest\data\6b45.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Russian Armed Forces<br />Rating: GOST 5A Steel<br />Introduced: 2000s<br />Multiple-hit resistant against 7.62x39mm API";

		class ItemInfo: ItemInfo {
			mass = 210;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"GOST-5A 6B23 Plate", 0};
			enableparts[] = {0,0,15,15,15,0,0,0,0};
			blunttraumaPad[] = {0,0,1.2,1.2,1.2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_rus5: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) MIL-V 6B58";
		picture = "\SCT\addons\SonicT_vest\data\6b58.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Spetsnaz<br />Rating: MIL-V Ceramic, Boron Carbide<br />Introduced: 2015<br />Rated to withstand M995, M993, 7N39, and .338 Lapua Magnum Ball";

		class ItemInfo: ItemInfo {
			mass = 130;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-V 6B58 Plate", 0};
			enableparts[] = {0,0,26,26,26,0,0,0,0};
			blunttraumaPad[] = {0,0,2,2,2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_neck1: SonicT_Item_Base {
		scope = 2;
		displayName = "(SpecialInsert) Defender-2 Neck Guard";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: FSB<br />Rating: Level II<br />Introduced: 2000s<br />Rated to withstand 9x19mm";

		class ItemInfo: ItemInfo {
			mass = 40;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"Defender 2 Neck Guard", 1};
			enableparts[] = {5,0,0,0,0,0,0,0,0};
			blunttraumaPad[] = {1,0,0,0,0,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_neck2: SonicT_Item_Base {
		scope = 2;
		displayName = "(SpecialInsert) Galls Level IIIA Neck Guard";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: SWAT Teams<br />Rating: NIJ IIIA<br />Introduced: 2000s<br />Rated to withstand .44 Magnum";

		class ItemInfo: ItemInfo {
			mass = 70;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"Galls Level IIIA Neck Guard", 1};
			enableparts[] = {8,0,0,0,0,0,0,0,0};
			blunttraumaPad[] = {1,0,0,0,0,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_rustrauma: SonicT_Item_Base {
		scope = 2;
		displayName = "(Trauma) Climatic-Amortization Plate";
		picture = "\SCT\addons\SonicT_vest\data\Capture.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Spetsnaz<br />Rating: Class 10 Trauma Pad<br />Introduced: 2015<br />Heavily aids in absorbing bullets";

		class ItemInfo: ItemInfo {
			mass = 70;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"Class 10 Trauma Pad", 0};
			enableparts[] = {0,0,4,4,4,0,0,0,0};
			blunttraumaPad[] = {0,0,6,6,6,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_rus5ovr: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) MIL-V 6B58/OVR";
		picture = "\SCT\addons\SonicT_vest\data\6b58.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Assault Sappers utilizing the FORT OVR-3Sh body armor system<br />Rating: MIL-V Ceramic, Boron Carbide, Extended Coverage<br />Introduced: 2015<br />Rated to withstand M995, M993, 7N39, and .338 Lapua Magnum Ball";

		class ItemInfo: ItemInfo {
			mass = 180;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-V 6B58/OVR Plates", 0};
			enableparts[] = {0,8,26,26,26,22,6,0,0};
			blunttraumaPad[] = {0,1,2,2,2,2,1,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_rus4F: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) MIL-VA 6B54";
		picture = "\SCT\addons\SonicT_vest\data\6b58.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Select Forces<br />Rating: MIL-IV* Ceramic, Boron Carbide<br />Introduced: 2015<br />Rated for M995 and .338 Lapua Magnum Ball";

		class ItemInfo: ItemInfo {
			mass = 130;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-IV* 6B54 Plate", 0};
			enableparts[] = {0,0,19,19,19,0,0,0,0};
			blunttraumaPad[] = {0,0,2,2,2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
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
			enableparts[] = {0,0,17,17,17,0,0,0,0};
			blunttraumaPad[] = {0,0,2.1,2.1,2.1,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
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
			enableparts[] = {0,0,16,16,16,13,0,0,0};
			blunttraumaPad[] = {0,0,2,2,2,1,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};

	class SCT_plate_steel_ar5001: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) AR500 Level III+";
		picture = "\SCT\addons\SonicT_vest\data\ar500.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Contractors, Civilians, PMCs<br />Rating: NIJ Level III+<br />Introduced: 2000s<br />Will withstand repeat 5.56x45mm M193 impacts";

		class ItemInfo: ItemInfo {
			mass = 194;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"AR500 Level III+ ", 2};
			enableparts[] = {0,0,15,15,15,0,0,0,0};
			blunttraumaPad[] = {0,0,1.4,1.4,1.4,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_steel_ar500C: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) AR500 Level III";
		picture = "\SCT\addons\SonicT_vest\data\ar500.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Contractors, Civilians, PMCs<br />Rating: NIJ Level III<br />Introduced: 2000s<br />Will withstand repeat 7.62x51mm FMJ impacts";

		class ItemInfo: ItemInfo {
			mass = 184;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"AR500 Level III", 2};
			enableparts[] = {0,0,12,12,12,0,0,0,0};
			blunttraumaPad[] = {0,0,1.5,1.5,1.5,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_steel_ar500STP: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) AR500 STP";
		picture = "\SCT\addons\SonicT_vest\data\ar500.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Contractors, Civilians, PMCs<br />Rating: Special Threat Plate<br />Introduced: 2000s<br />Will withstand basic 5.56 and 7.62 cartridges";

		class ItemInfo: ItemInfo {
			mass = 134;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"AR500 STP", 2};
			enableparts[] = {0,0,8,8,8,0,0,0,0};
			blunttraumaPad[] = {0,0,1.3,1.3,1.3,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_steel_ar500CS: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) AR500 Level III/S";
		picture = "\SCT\addons\SonicT_vest\data\ar500.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Contractors, Civilians, PMCs<br />Rating: NIJ Level III, Small-sized<br />Introduced: 2000s<br />Will withstand repeat 7.62x51mm FMJ impacts";

		class ItemInfo: ItemInfo {
			mass = 140;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"AR500 Level III, 8x10", 2};
			enableparts[] = {0,0,0,12,12,2,0,0,0};
			blunttraumaPad[] = {0,0,0,1.4,1.4,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_steel_ar500CT: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) AR500 Level III/MC";
		picture = "\SCT\addons\SonicT_vest\data\ar500.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Contractors, Civilians, PMCs<br />Rating: NIJ Level III, Maximum Coverage<br />Introduced: 2000s<br />Will withstand repeat 7.62x51mm FMJ impacts";

		class ItemInfo: ItemInfo {
			mass = 251;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"AR500 Level III/MC", 2};
			enableparts[] = {0,7,12,12,12,12,0,0,0};
			blunttraumaPad[] = {0,1,1.4,1.4,1.4,1,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_steel_ar5004: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) AR500 Level IV";
		picture = "\SCT\addons\SonicT_vest\data\ar500.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Contractors, Civilians, PMCs<br />Rating: NIJ Level IV, Steel<br />Introduced: 2000s<br />Will withstand repeat 30-06 M2AP impacts";

		class ItemInfo: ItemInfo {
			mass = 280;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"AR500 Level IV", 2};
			enableparts[] = {0,0,18,18,18,0,0,0,0};
			blunttraumaPad[] = {0,0,1.6,1.6,1.6,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_steel_ar5004CAA: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) AR500-Ceramic Level IV";
		picture = "\SCT\addons\SonicT_vest\data\ar500.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Contractors, Civilians, PMCs<br />Rating: NIJ Level IV, Ceramic<br />Introduced: 2000s<br />Will withstand .22-250 Remington";

		class ItemInfo: ItemInfo {
			mass = 150;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"AR500 Level IV, Ceramic", 2};
			enableparts[] = {0,0,17,17,17,0,0,0,0};
			blunttraumaPad[] = {0,0,2,2,2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_steel_ar5004MC: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) AR500 Level IV/MC";
		picture = "\SCT\addons\SonicT_vest\data\ar500.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Contractors, Civilians, PMCs<br />Rating: NIJ Level IV, Maximum Coverage<br />Introduced: 2000s<br />Will withstand repeat 30-06 M2AP impacts";

		class ItemInfo: ItemInfo {
			mass = 360;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"AR500 Level IV/MC", 2};
			enableparts[] = {0,8,17,17,17,14,0,0,0};
			blunttraumaPad[] = {0,1.6,1.6,1.6,1.6,1.6,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_steel_ar5005: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) AR500 Level V";
		picture = "\SCT\addons\SonicT_vest\data\ar500.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Well-funded PMCs, well-connected survivalists<br />Rating: NIJ Level IV, MIL-V<br />Introduced: 2010s<br />Rated for .338 Lapua Magnum";

		class ItemInfo: ItemInfo {
			mass = 370;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"AR500 Level V", 2};
			enableparts[] = {0,0,25,25,25,0,0,0,0};
			blunttraumaPad[] = {0,0,2,2,2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_steel_ar5005mc: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) AR500 Level V/MC";
		picture = "\SCT\addons\SonicT_vest\data\ar500.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Well-funded PMCs, well-connected survivalists<br />Rating: NIJ Level IV, MIL-V, Maximum Coverage<br />Introduced: 2010s<br />Rated for .338 Lapua Magnum";

		class ItemInfo: ItemInfo {
			mass = 470;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"AR500 Level V, Maximum Coverage", 2};
			enableparts[] = {0,9,25,25,25,17,0,0,0};
			blunttraumaPad[] = {0,2,2,2,2,2,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
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
			blunttraumaPad[] = {0,0,1.2,1.2,1.2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_kevlar_3: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) Kevlar Level IIIA";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Contractors, Civilians, PMCs<br />Rating: NIJ Level IIIA<br />Introduced: 1980s<br />Will withstand revolver impacts";

		class ItemInfo: ItemInfo {
			mass = 44;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"Kevlar Level IIIA", 4};
			enableparts[] = {0,0,7,7,7,0,0,0,0};
			blunttraumaPad[] = {0,0,0.7,0.7,0.7,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
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
			blunttraumaPad[] = {0,0,0.7,0.7,0.7,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
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
			blunttraumaPad[] = {0,0,0.7,0.7,0.7,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
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
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
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
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_steel_ar680: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) AR680 Level III+";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Contractors, Civilians, PMCs<br />Rating: NIJ Level III+<br />Introduced: 2010s<br />Will withstand repeat 7.62x51mm Ball";

		class ItemInfo: ItemInfo {
			mass = 144;
		};

		class SCT_ITEMINFO{
			plateinfo[] = {"AR680 Level III+", 2};
			enableparts[] = {0,0,13,13,13,0,0,0,0};
			blunttraumaPad[] = {0,0,1.3,1.3,1.3,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_steel_ar680b: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) AR680 Level IV";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Contractors, Civilians, PMCs<br />Rating: NIJ Level IV<br />Introduced: 2010s<br />Will withstand repeat 7.62x51mm Ball";

		class ItemInfo: ItemInfo {
			mass = 164;
		};

		class SCT_ITEMINFO{
			plateinfo[] = {"AR680 Level IV", 2};
			enableparts[] = {0,0,18,18,18,0,0,0,0};
			blunttraumaPad[] = {0,0,1.3,1.3,1.3,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
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
			enableparts[] = {0,0,17,17,17,0,0,0,0};
			blunttraumaPad[] = {0,0,2,2,2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
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
			blunttraumaPad[] = {0,0,2,2,2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
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
			blunttraumaPad[] = {0,0,2,2,2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
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
			enableparts[] = {0,0,16,16,16,0,0,0,0};
			blunttraumaPad[] = {0,0,2,2,2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
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
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_titanium_6b3tm: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) 6B3TM GOST 4";
		picture = "\SCT\addons\SonicT_vest\data\6b3tm.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Former Warsaw Pact Nations<br />Rating: GOST Class 4, Titanium<br />Introduced: 1984<br />Will withstand 7.62x39mm Steel-core rounds";

		class ItemInfo: ItemInfo {
			mass = 110;
		};

		class SCT_ITEMINFO{
			plateinfo[] = {"6B3TM GOST 4", 2};
			enableparts[] = {0,0,11,11,11,0,0,0,0};
			blunttraumaPad[] = {0,0,1,1,1,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};		
	};
	
	class SCT_plate_titanium_6b3tm01: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) 6B3TM01 GOST 5";
		picture = "\SCT\addons\SonicT_vest\data\6b3tm.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Former Warsaw Pact Nations<br />Rating: GOST Class 5, Titanium<br />Introduced: 1984<br />Will withstand 7.62x39mm Steel-core rounds";

		class ItemInfo: ItemInfo {
			mass = 111;
		};

		class SCT_ITEMINFO{
			plateinfo[] = {"6B3TM01 GOST 5", 1};
			enableparts[] = {0,0,14,12,14,0,0};
			blunttraumaPad[] = {0,0,1.25,1.25,1.25,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};		
	};
	
	class SCT_plate_ceramic_ceradyne: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) Ceradyne MIL-VIII";
		picture = "\SCT\addons\SonicT_vest\data\ceradyne2.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: United States Military<br />Rating: MIL-VIII<br />Introduced: 1994<br />.50 BMG Protective, 10x14";

		class ItemInfo: ItemInfo {
			mass = 330;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-VIII Ceradyne .50 BMG Protective", 0};
			enableparts[] = {0,0,190,190,190,0,0,0,0};
			blunttraumaPad[] = {0,0,8,8,8,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_poly_DFNDR: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) DFNDR Level III+";
		picture = "\SCT\addons\SonicT_vest\data\SCT_poly_dfndr_3p.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_poly_dfndr_3p.p3d"
		descriptionShort = "Used By: Civilians, Law Enforcement<br />Rating: NIJ Level III+<br />Introduced: 2000s<br />Rated for 7.62x51mm Ball impacts";

		class ItemInfo: ItemInfo {
			mass = 80;
		};

		class SCT_ITEMINFO{
			plateinfo[] = {"DEFENDER Lightweight Level III+", 1};
			enableparts[] = {0,0,11,11,11,0,0,0,0};
			blunttraumaPad[] = {0,0,0.9,0.9,0.9,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_poly_dragic: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) MD Spectra III";
		picture = "\SCT\addons\SonicT_vest\data\serb.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_poly_dfndr_3p.p3d"
		descriptionShort = "Used By: Serbian Armed Forces<br />Rating: NIJ Level III<br />Introduced: 2000s<br />Rated for M193 5.56x45mm";

		class ItemInfo: ItemInfo {
			mass = 85;
		};

		class SCT_ITEMINFO{
			plateinfo[] = {"Mile Dragic Spectra III", 1};
			enableparts[] = {0,0,11,11,11,0,0,0,0};
			blunttraumaPad[] = {0,0,1.1,1.1,1.1,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
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
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
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
			enableparts[] = {0,0,1,1,1,0,0,0,0};
			blunttraumaPad[] = {0,0,2.2,2.2,2.2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
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
			enableparts[] = {0,0,1,1,1,0,0,0,0};
			blunttraumaPad[] = {0,0,3.2,3.2,3.2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
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
			enableparts[] = {0,0,1,1,1,0,0,0,0};
			blunttraumaPad[] = {0,0,6.2,6.2,6.2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class BER_Boost_Special_Doubler: SonicT_Item_Base {
		scope = 2;
		displayName = "(Special) Euro Extreme Mode";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Switches AAPM into one-shot-kill mode<br />deducts fifty armor";

		class ItemInfo: ItemInfo {
			mass = 1;
		};

		class SCT_ITEMINFO{
			plateinfo[] = {"Euro Extreme Mode", 0};
			enableparts[] = {-50,-50,-50,-50,-50,-50,-50,-50,-50};
			blunttraumaPad[] = {1,1,1,1,1,1,1,1,1};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class BER_Boost_Special_Infiltration: SonicT_Item_Base {
		scope = 2;
		displayName = "(Special) Old School Mode";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Makes you feel like you're in the late 1990s again.<br />deducts twenty-five armor<br />Modeled after UT99 Infiltration.";

		class ItemInfo: ItemInfo {
			mass = 1;
		};

		class SCT_ITEMINFO{
			plateinfo[] = {"Old School Mode", 0};
			enableparts[] = {-25,-25,-25,-25,-25,-25,-25,-25,-25};
			blunttraumaPad[] = {1,1,1,1,1,1,1,1,1};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
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
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
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
			blunttraumaPad[] = {0,0,2,2,2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
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
			blunttraumaPad[] = {0,0,1.6,1.6,1.6,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_poly_PSAPI: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) SPEAR MIL-III";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: United States Military<br />Rating: NIJ Level III, Polyethylene<br />Introduced: 2010s<br />Rated for .308";

		class ItemInfo: ItemInfo {
			mass = 84;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"SPEAR MIL-III Polyethylene", 1};
			enableparts[] = {0,0,10,10,10,0,0,0,0};
			blunttraumaPad[] = {0,0,1.8,1.8,1.8,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_gamma: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) TAP Gamma NIJ-III";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Law Enforcement<br />Rating: NIJ Level III, Ceramic<br />Introduced: 2003<br />Rated for multi-impact .308";

		class ItemInfo: ItemInfo {
			mass = 120;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"TAP Gamma NIJ-III", 0};
			enableparts[] = {0,0,12,12,12,0,0,0,0};
			blunttraumaPad[] = {0,0,2.2,2.2,2.2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_gamma2: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) TAP Gamma NIJ-III+";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Law Enforcement<br />Rating: NIJ Level III+, Ceramic<br />Introduced: 2003<br />Rated for M855 and M193";

		class ItemInfo: ItemInfo {
			mass = 130;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"TAP Gamma NIJ-III+", 0};
			enableparts[] = {0,0,14,14,14,0,0,0,0};
			blunttraumaPad[] = {0,0,2.2,2.2,2.2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_poly_m1199: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) RMA M1199 NIJ-IV";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Civilians<br />Rating: NIJ Level IV, Special Ceramic<br />Introduced: 2010s<br />Rated for many 30-06 M2AP";

		class ItemInfo: ItemInfo {
			mass = 150;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"RMA Level IV Ceramic panel", 0};
			enableparts[] = {0,0,18,18,18,0,0,0,0};
			blunttraumaPad[] = {0,0,2,2,2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_poly_m1155: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) RMA M1155 NIJ-IV*";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Civilians<br />Rating: NIJ Level IV, MIL-VA<br />Introduced: 2010s<br />Rated for five 30-06 M2APs or one .338 Lapua Magnum";

		class ItemInfo: ItemInfo {
			mass = 190;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"RMA Level IV Ceramic panel", 0};
			enableparts[] = {0,0,19.5,19.5,19.5,0,0,0,0};
			blunttraumaPad[] = {0,0,2.1,2.1,2.1,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_poly_angel_308S: SonicT_Item_Base {
		scope = 2;
		displayName = "(Plate) 308S Level III-S";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Civilians, Contractors<br />Rating: NIJ Level III<br />Introduced: 2010s<br />Rated for .308<br />Small 5x8 model";

		class ItemInfo: ItemInfo {
			mass = 65;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"308S Polyethylene panel", 1};
			enableparts[] = {0,0,0,11,11,0,0,0,0};
			blunttraumaPad[] = {0,0,0,1.8,1.8,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
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
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
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
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_uniform_kevlarinsert1: SonicT_Item_Base {
		scope = 2;
		displayName = "(UniformInsert) Level II Kevlar Insert";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Level II Kevlar Insert";

		class ItemInfo: ItemInfo {
			mass = 70;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"Level II Kevlar Insert", 1};
			enableparts[] = {3,3,0,0,0,3,3,0,0};
			blunttraumaPad[] = {1,1,0,0,0,1,1,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_uniform_kevlarinsert3: SonicT_Item_Base {
		scope = 2;
		displayName = "(UniformInsert) Level IIIA Kevlar";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Level IIIA Kevlar Insert";

		class ItemInfo: ItemInfo {
			mass = 86;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"Level IIIA Kevlar Insert", 1};
			enableparts[] = {5,5,0,0,0,5,5,0,0};
			blunttraumaPad[] = {1,1,0,0,0,1,1,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_uniform_KEV3: SonicT_Item_Base {
		scope = 2;
		displayName = "(UniformInsert) DragonSkin Level III";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Contractors, Raid Crews<br />Rating: NIJ Level III<br />Introduced: 1999<br />NIJ Level III, all limbs";

		class ItemInfo: ItemInfo {
			mass = 170;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"DragonSkin SOV-Uniform NIJ III", 0};
			enableparts[] = {13,12.5,10,10,10,12.5,12.5,0,0};
			blunttraumaPad[] = {2,2,2,2,2,2,2,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_uniform_STE3: SonicT_Item_Base {
		scope = 2;
		displayName = "(UniformInsert) AR500 Multipad NIJ III";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Soldiers of Fortune, marathon-sortie operators<br />Rating: NIJ Level III<br />Introduced: 2000s<br />NIJ Level III, all limbs";

		class ItemInfo: ItemInfo {
			mass = 230;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"NIJ III AR500 Multipad", 2};
			enableparts[] = {12,12,10,10,10,12,12,0,0};
			blunttraumaPad[] = {1,1,1,1,1,1,1,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_uniform_STE4: SonicT_Item_Base {
		scope = 2;
		displayName = "(UniformInsert) AR500 Multipad NIJ IV";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Soldiers of Fortune, marathon-sortie operators<br />Rating: NIJ Level IV<br />Introduced: 2000s<br />NIJ Level IV, all limbs";

		class ItemInfo: ItemInfo {
			mass = 340;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"NIJ IV AR500 Multipad", 2};
			enableparts[] = {16,16,12,12,12,16,16,0,0};
			blunttraumaPad[] = {1,1,1,1,1,1,1,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_uniform_3UHMWPE: SonicT_Item_Base {
		scope = 2;
		displayName = "(UniformInsert) UHMWPE NIJ III";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Special Forces<br />Rating: NIJ Level III<br />Introduced: 2010s<br />NIJ Level III, all limbs";

		class ItemInfo: ItemInfo {
			mass = 150;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"NIJ III UHMWPE", 1};
			enableparts[] = {13,13,8,8,8,13,13,0,0};
			blunttraumaPad[] = {1.5,1.5,1.5,1.5,1.5,1.5,1.5,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_uniform_4UHMWPE: SonicT_Item_Base {
		scope = 2;
		displayName = "(UniformInsert) UHMWPE NIJ IV";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Special Forces<br />Rating: NIJ Level IV<br />Introduced: 2010s<br />NIJ Level IV, all limbs";

		class ItemInfo: ItemInfo {
			mass = 200;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"NIJ IV UHMWPE", 1};
			enableparts[] = {15.5,15.5,9,9,9,15.5,15.5,0,0};
			blunttraumaPad[] = {1.5,1.5,1.5,1.5,1.5,1.5,1.5,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_uniform_KEV4: SonicT_Item_Base {
		scope = 2;
		displayName = "(UniformInsert) DragonSkin Level IV";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Contractors, Raid Crews<br />Rating: NIJ Level IV<br />Introduced: 1999<br />NIJ Level IV, all limbs";

		class ItemInfo: ItemInfo {
			mass = 220;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"DragonSkin SOV-Uniform NIJ IV", 0};
			enableparts[] = {16,16,8,8,8,16,16,0,0};
			blunttraumaPad[] = {2,2,2,2,2,2,2,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_uniform_KEV5: SonicT_Item_Base {
		scope = 2;
		displayName = "(UniformInsert) DragonSkin MIL-V";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Federal Government<br />Rating: MIL-V<br />Introduced: 1999<br />MIL-V, all limbs";

		class ItemInfo: ItemInfo {
			mass = 270;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"DragonSkin SOV-Uniform MIL-V", 0};
			enableparts[] = {21,21,10,10,10,21,21,0,0};
			blunttraumaPad[] = {2,2,2,2,2,2,2,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_uniform_KEV6: SonicT_Item_Base {
		scope = 2;
		displayName = "(UniformInsert) DragonSkin MIL-VI";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Federal Government<br />Rating: MIL-VI<br />Introduced: 1999<br />MIL-VI, all limbs";

		class ItemInfo: ItemInfo {
			mass = 400;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"DragonSkin SOV-Uniform MIL-VI", 0};
			enableparts[] = {32,32,20,20,20,32,32,0,0};
			blunttraumaPad[] = {1.8,1.8,1.8,1.8,1.8,1.8,1.8,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	
	class SCT_booster_helmetface3a: SonicT_Item_Base {
		scope = 2;
		displayName = "(Booster) NIJ IIIA Helmet Booster";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Reinforcement for helmet";

		class ItemInfo: ItemInfo {
			mass = 44;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"NIJ IIIA", 2};
			enableparts[] = {0,0,0,0,0,0,0,6,0};
			blunttraumaPad[] = {0,0,0,0,0,0,0,0.8,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_booster_helmetface2: SonicT_Item_Base {
		scope = 2;
		displayName = "(Booster) NIJ II Helmet Booster";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Reinforcement for helmet";

		class ItemInfo: ItemInfo {
			mass = 35;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"NIJ II", 2};
			enableparts[] = {0,0,0,0,0,0,0,4,0};
			blunttraumaPad[] = {0,0,0,0,0,0,0,0.7,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_booster_helmetface3: SonicT_Item_Base {
		scope = 2;
		displayName = "(Booster) NIJ III Helmet Booster";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Helmet reinforcement";

		class ItemInfo: ItemInfo {
			mass = 50;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"NIJ III", 2};
			enableparts[] = {0,0,0,0,0,0,0,13,0};
			blunttraumaPad[] = {0,0,0,0,0,0,0,1,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	
	class SCT_booster_helmetface4: SonicT_Item_Base {
		scope = 2;
		displayName = "(Booster) NIJ IV Helmet Booster";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Heavy Helmet Reinforcement";

		class ItemInfo: ItemInfo {
			mass = 76;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"NIJ IV", 2};
			enableparts[] = {0,0,0,0,0,0,0,16,0};
			blunttraumaPad[] = {0,0,0,0,0,0,0,1,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_booster_helmetface5: SonicT_Item_Base {
		scope = 2;
		displayName = "(Booster) MIL-V Helmet Booster";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Super-heavy Helmet Reinforcement";

		class ItemInfo: ItemInfo {
			mass = 90;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-V", 2};
			enableparts[] = {0,0,0,0,0,0,0,22,0};
			blunttraumaPad[] = {0,0,0,0,0,0,0,1.1,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_booster_helmetface5s: SonicT_Item_Base {
		scope = 2;
		displayName = "(Booster) MIL-VS Helmet Booster";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Ultra-heavy Helmet Reinforcement";

		class ItemInfo: ItemInfo {
			mass = 100;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-VS", 2};
			enableparts[] = {0,0,0,0,0,0,0,22,0};
			blunttraumaPad[] = {0,0,0,0,0,0,0,1.7,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_booster_helmetface6: SonicT_Item_Base {
		scope = 2;
		displayName = "(Booster) MIL-VI Helmet Booster";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Juggernaut Helmet Reinforcement";

		class ItemInfo: ItemInfo {
			mass = 120;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-VI", 2};
			enableparts[] = {0,0,0,0,0,0,0,30,0};
			blunttraumaPad[] = {0,0,0,0,0,0,0,2.7,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_booster_helmetface7: SonicT_Item_Base {
		scope = 2;
		displayName = "(Booster) MIL-VII Helmet Booster";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Assault Juggernaut Helmet Reinforcement";

		class ItemInfo: ItemInfo {
			mass = 150;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-VII", 2};
			enableparts[] = {0,0,0,0,0,0,0,40,0};
			blunttraumaPad[] = {0,0,0,0,0,0,0,3.7,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_booster_face3: SonicT_Item_Base {
		scope = 2;
		displayName = "(Booster) NIJ III Headshot Guard";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Reinforces your face to Level III Standard";

		class ItemInfo: ItemInfo {
			mass = 45;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"NIJ III", 2};
			enableparts[] = {0,0,0,0,0,0,0,0,11};
			blunttraumaPad[] = {0,0,0,0,0,0,0,0,2};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_booster_face3a: SonicT_Item_Base {
		scope = 2;
		displayName = "(Booster) NIJ IIIA Headshot Guard";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Reinforces your face to Level IIIA Standard";

		class ItemInfo: ItemInfo {
			mass = 34;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"NIJ IIIA", 2};
			enableparts[] = {0,0,0,0,0,0,0,0,9};
			blunttraumaPad[] = {0,0,0,0,0,0,0,0,2};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
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
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_booster_face4: SonicT_Item_Base {
		scope = 2;
		displayName = "(Booster) NIJ IV Headshot Guard";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Reinforces your face to Level IV Standard";

		class ItemInfo: ItemInfo {
			mass = 52;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"NIJ IV", 2};
			enableparts[] = {0,0,0,0,0,0,0,0,15};
			blunttraumaPad[] = {0,0,0,0,0,0,0,0,2};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_booster_face5: SonicT_Item_Base {
		scope = 2;
		displayName = "(Booster) MIL-V Headshot Guard";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Reinforces your face to MIL-V Standard";

		class ItemInfo: ItemInfo {
			mass = 70;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-V", 2};
			enableparts[] = {0,0,0,0,0,0,0,0,20};
			blunttraumaPad[] = {0,0,0,0,0,0,0,0,2};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_booster_face6: SonicT_Item_Base {
		scope = 2;
		displayName = "(Booster) MIL-VI Headshot Guard";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Reinforces your face to MIL-VI Standard";

		class ItemInfo: ItemInfo {
			mass = 95;
		};
		
		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-VI", 2};
			enableparts[] = {0,0,0,0,0,0,0,0,30};
			blunttraumaPad[] = {0,0,0,0,0,0,0,0,3};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
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
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
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
		descriptionShort = "Rebreather with a little protection";

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
			containerClass="Supply140";
			mass=80;
		};
	};
	class U_O_CombatUniform_oucamo: Uniform_Base{
		descriptionShort="CSAT Urban camo GOST level 2";
		class ItemInfo: UniformItem
		{
			containerClass="Supply140";
			mass=80;
		};
	};
	
	class U_O_GhillieSuit: Uniform_Base{
		class ItemInfo: UniformItem
		{
			containerClass="Supply140";
			mass=80;
		};
	};
	
	class U_O_PilotCoveralls: Uniform_Base{
		class ItemInfo: UniformItem
		{
			containerClass="Supply140";
			mass=80;
		};
	};
	
	class U_O_Wetsuit: Uniform_Base{
		class ItemInfo: UniformItem
		{
			containerClass="Supply140";
			mass=80;
		};
	};
	
	class U_O_V_Soldier_Viper_F: Uniform_Base
	{
		class ItemInfo: UniformItem
		{
			containerClass="Supply140";
			mass=80;
		};
	};
	class U_O_V_Soldier_Viper_hex_F: Uniform_Base{
		class ItemInfo: UniformItem
		{
			containerClass="Supply140";
			mass=80;
		};
	};
	
};

//magtype classes are for implement durability system.
//for user accessibility, item types are left - users can equip them easily by Virtual Arsenal.
//all magazine type set to 1, which means these magazines cannot access from Virtual Arsenal or 3den Editor(or Zeus).
class CfgMagazines {
	
	class CA_Magazine;

	class AAPM_Item_Base_magtype: CA_Magazine {
		scope = 1;
		access = 3;
		displayName = "-";
		detectRange = -1;
		simulation = "ItemMineDetector";
		useAsBinocular = 0;
		type = 4096;
		picture = "";
		descriptionShort = "";
		count = 6000;
		mass = 1;

	};

	class SCT_plate_ceramic_esapi_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) ESAPI MIL-IV";
		picture = "\SCT\addons\SonicT_vest\data\esapi.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: United States Military<br />Rating: MIL-IV Ceramic, Boron Carbide<br />Introduced: 2005<br />Will withstand 30-06 M2AP";

	
		mass = 106;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"ESAPI MIL-IV ceramic ICW", 0};
			enableparts[] = {0,0,14,14,14,0,0,0,0};
			blunttraumaPad[] = {0,0,2.1,2.1,2.1,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_isapi_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) ISAPI MIL-III+";
		picture = "\SCT\addons\SonicT_vest\data\sapi.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: United States Military<br />Rating: MIL-III Ceramic, Boron Carbide<br />Introduced: 2001<br />Will withstand .30 Ball";

	
		mass = 102;
		
		
		class SCT_ITEMINFO{
			plateinfo[] = {"Interceptor SAPI MIL-III+ Interim ICW", 0};
			enableparts[] = {0,0,12,12,12,0,0,0,0};
			blunttraumaPad[] = {0,0,2,2,2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_isapib_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) ISAPI/B MIL-IV*";
		picture = "\SCT\addons\SonicT_vest\data\hesapi.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: United States Military<br />Rating: MIL-IV* Ceramic, Boron Carbide<br />Introduced: ~2000-2004<br />Heavily-enhanced-protection against .30 Ball";

		mass = 160;

		
		class SCT_ITEMINFO{
			plateinfo[] = {"ISAPI/B MIL-IV* Ceramic Plate", 0};
			enableparts[] = {0,0,19,19,19,0,0,0,0};
			blunttraumaPad[] = {0,0,2,2,2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_TPG_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) TPG Level IV";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Civilians and LE<br />Rating: NIJ Level IV, Aluminum Oxide<br />Introduced: 2010s<br />Will withstand repeat 30-06 impacts";
		mass = 140;
		
		
		class SCT_ITEMINFO{
			plateinfo[] = {"TPG ceramic Aluminum Oxide plate, Level IV", 0};
			enableparts[] = {0,0,16,16,16,0,0,0,0};
			blunttraumaPad[] = {0,0,1.8,1.8,1.8,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_esapimc_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(PLate) ESAPI-MC MIL-IV/MC";
		picture = "\SCT\addons\SonicT_vest\data\esapi.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: United States Military<br />Rating: MIL-IV Ceramic, Boron Carbide<br />Introduced: 2005<br />Will withstand 30-06 M2AP<br />Maximum Coverage";
		mass = 120;

		
		class SCT_ITEMINFO{
			plateinfo[] = {"ESAPI NIJ IV ceramic ICW, Maximum Coverage", 0};
			enableparts[] = {0,10,15,15,15,10,5,0,0};
			blunttraumaPad[] = {0,2,2,2,2,2,2,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_xsapi_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) XSAPI MIL-V GEN3";
		picture = "\SCT\addons\SonicT_vest\data\xsapi.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: United States Military<br />Rating: MIL-V Ceramic, Boron Carbide<br />Introduced: 2016<br />Will withstand M993, M995, or 7N39";
		mass = 102;

		
		class SCT_ITEMINFO{
			plateinfo[] = {"XSAPI-2016 MIL-V Ceramic", 0};
			enableparts[] = {0,0,26,26,26,0,0,0,0};
			blunttraumaPad[] = {0,0,2.2,2.2,2.2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_xsapimc_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) XSAPI MIL-V/MC GEN3";
		picture = "\SCT\addons\SonicT_vest\data\xsapi.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: United States Military<br />Rating: MIL-V Ceramic, Boron Carbide<br />Introduced: 2016<br />Will withstand M993, M995, or 7N39<br />Maximum Coverage";
		mass = 175;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"XSAPI-2016", 0};
			enableparts[] = {6,3,27,27,27,19,0,0,0};
			blunttraumaPad[] = {2,2,2,2,2,2,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_xsapi2009_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) XSAPI MIL-VA GEN1";
		picture = "\SCT\addons\SonicT_vest\data\xsapi.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: United States Military<br />Rating: MIL-VA Ceramic, Boron Carbide<br />Introduced: 2009<br />Will withstand M995";
		mass = 105;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"XSAPI-2009 MIL-VA", 0};
			enableparts[] = {0,0,18,18,18,0,0,0,0};
			blunttraumaPad[] = {0,0,2,2,2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_xsapi2011_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) XSAPI MIL-V GEN2";
		picture = "\SCT\addons\SonicT_vest\data\xsapi.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: United States Military<br />Rating: MIL-V Ceramic, Boron Carbide<br />Introduced: 2011<br />Special Theater Contingency Plate";
		mass = 132;

		
		class SCT_ITEMINFO{
			plateinfo[] = {"XSAPI-2011 GEN2", 0};
			enableparts[] = {0,0,24,24,24,0,0,0,0};
			blunttraumaPad[] = {0,0,2.4,2.4,2.4,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_sapi_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) SAPI MIL-III";
		picture = "\SCT\addons\SonicT_vest\data\sapi.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: United States Military<br />Rating: MIL-III Ceramic, Boron Carbide<br />Introduced: 1998<br />Multi-hit resistant";
		mass = 94;

		
		class SCT_ITEMINFO{
			plateinfo[] = {"SAPI MIL-III ICW", 0};
			enableparts[] = {0,0,12,12,12,0,0,0,0};
			blunttraumaPad[] = {0,0,1.9,1.9,1.9,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_hesapi_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) H-ESAPI MIL-V";
		picture = "\SCT\addons\SonicT_vest\data\hesapi.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: US Air Force Pararescuemen<br />Rating: MIL-V Ceramic, Boron Carbide<br />Introduced: 2005<br />Rated to stop M993, M995, or 7N24";
		mass = 155;

		
		class SCT_ITEMINFO{
			plateinfo[] = {"H-ESAPI MIL-V", 0};
			enableparts[] = {12,0,28,28,28,0,0,0,0};
			blunttraumaPad[] = {2,0,2.3,2.3,2.3,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_hesapiT_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) H-ESAPI/ASTI MIL-VI";
		picture = "\SCT\addons\SonicT_vest\data\hesapi.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: US Air Force Pararescuemen<br />Rating: MIL-VI Ceramic, Boron Carbide<br />Introduced: 2005<br />Rated to stop .338 Lapua Magnum API526<br />Anti-Spalling and Thickness Increased";
		mass = 250;

		
		class SCT_ITEMINFO{
			plateinfo[] = {"H-ESAPI/Anti-Spalling-Thickness-Increased MIL-VI", 0};
			enableparts[] = {17,0,36,36,36,0,0,0,0};
			blunttraumaPad[] = {2,0,2.4,2.4,2.4,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_hesapimc_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) H-ESAPI MIL-V/MC";
		picture = "\SCT\addons\SonicT_vest\data\hesapi.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: US Air Force Pararescuemen<br />Rating: MIL-V Ceramic, Boron Carbide, Maximum Coverage<br />Introduced: 2005<br />Rated to stop M993, M995, or 7N24";
		mass = 230;

		
		class SCT_ITEMINFO{
			plateinfo[] = {"H-ESAPI MIL-V/MC", 0};
			enableparts[] = {12,5,28,28,28,12,0,0,0};
			blunttraumaPad[] = {2,1.4,2.3,2.3,2.3,2.3,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_isapo_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) ISAPO MIL-III";
		picture = "\SCT\addons\SonicT_vest\data\rba.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: United States Military<br />Rating: MIL-III Ceramic, Aluminum Oxide<br />Introduced: 1996<br />Will withstand 7.62x51mm Ball";
		mass = 138;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"ISAPO MIL-III", 0};
			enableparts[] = {0,0,12,12,12,0,0,0,0};
			blunttraumaPad[] = {0,0,1.8,1.8,1.8,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_pru601_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) PRU-60/P22P-15 MIL-IIIA";
		picture = "\SCT\addons\SonicT_vest\data\pru60.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: American Aircrews<br />Rating: MIL-IIIA, Aluminum Oxide<br />Introduced: 1998<br />Will withstand light small-arms fire, 8x10";
		mass = 112;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"PRU-60/P22P-15 Aircrew Plate", 0};
			enableparts[] = {0,0,10,10,5,0,0,0,0};
			blunttraumaPad[] = {0,0,3.2,3.2,2.1,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_pru611_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) PRU-61/P22P-15 MIL-IV";
		picture = "\SCT\addons\SonicT_vest\data\pru60.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: American Aircrews<br />Rating: MIL-IV, Aluminum Oxide<br />Introduced: 1998<br />Withstands repeat 30-06 M2AP, 8x10";
		mass = 140;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"PRU-60/P22P-15 Aircrew Plate", 0};
			enableparts[] = {0,0,18,18,11,0,0,0,0};
			blunttraumaPad[] = {0,0,3.2,3.2,2.1,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_pru60A_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) PRU-60/A Airsafe MIL-VIII";
		picture = "\SCT\addons\SonicT_vest\data\pru60.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: American Aircrews<br />Rating: MIL-VIII, Aluminum Oxide<br />Introduced: 1998<br />.50 BMG Protective, 8x10";
		mass = 210;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"PRU-60/A Airsafe Aircrew Plate", 0};
			enableparts[] = {0,0,10,160,10,0,0,0,0};
			blunttraumaPad[] = {0,0,3.2,5.2,2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_chicken_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) Chicken Plates MIL-III";
		picture = "\SCT\addons\SonicT_vest\data\doron.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: American Aircrews<br />Rating: MIL-III, Early Aluminum Oxide<br />Introduced: 1965<br />Will withstand repeat 7.62x39mm";
		mass = 300;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"Chicken Plate Set - Non-Infantry MIL-III", 0};
			enableparts[] = {0,14,14,14,14,0,0,0,0};
			blunttraumaPad[] = {0,2.3,2.3,2.3,2.3,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_VBA_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) VBAGT/1 MIL-III";
		picture = "\SCT\addons\SonicT_vest\data\doron.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: 1st Cavalry<br />Rating: MIL-III Ceramic, Aluminum Oxide<br />Introduced: 1965<br />7.62x39mm Resistant";
		mass = 220;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"Variable Body Armor", 0};
			enableparts[] = {0,0,14,14,14,0,0,0,0};
			blunttraumaPad[] = {0,0,1.3,1.3,1.3,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_VBA2_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) VBAGT/2 MIL-III";
		picture = "\SCT\addons\SonicT_vest\data\doron.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: Navy and Air Force<br />Rating: MIL-III Ceramic, Silicon Carbide<br />Introduced: 1965<br />7.62x39mm Resistant";
		mass = 220;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"Variable Body Armor", 0};
			enableparts[] = {0,0,14,14,14,0,0,0,0};
			blunttraumaPad[] = {0,0,1.4,1.4,1.4,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_VBA3_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) VBAGT/3 MIL-III";
		picture = "\SCT\addons\SonicT_vest\data\doron.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: Navy and Air Force<br />Rating: MIL-III Ceramic, Boron Carbide<br />Introduced: 1965<br />7.62x39mm Resistant";
		mass = 220;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"Variable Body Armor", 0};
			enableparts[] = {0,0,15.5,15.5,15.5,0,0,0,0};
			blunttraumaPad[] = {0,0,1.1,1.1,1.1,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_m1951_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) M1951 Level II-";
		picture = "\SCT\addons\SonicT_vest\data\doron.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: US Military, Korean War<br />Rating: Level II-, Doron Laminate<br />Introduced: 1951<br />Will withstand .45 ACP";
		mass = 95;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"M1951 Doron Laminate Armor", 1};
			enableparts[] = {0,0,0,3.6,3.6,0,0,0,0};
			blunttraumaPad[] = {0,0,0,1,1,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_m1955_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) M1955 Level II-";
		picture = "\SCT\addons\SonicT_vest\data\doron.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: US Military, Vietnam War<br />Rating: Level II-, Doron Laminate<br />Introduced: 1955<br />Will withstand .45 ACP";
		mass = 105;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"M1955 Doron Laminate Armor", 1};
			enableparts[] = {0,0,0,3.6,3.6,0,0,0,0};
			blunttraumaPad[] = {0,0,0,1,1,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_m1945_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) M1945 Level II-";
		picture = "\SCT\addons\SonicT_vest\data\doron.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: US Military, Battle of Okinawa<br />Rating: Level II-, Doron Laminate<br />Introduced: 1945<br />Will withstand Flak";
		mass = 80;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"M1945 Doron Laminate Armor", 1};
			enableparts[] = {0,0,0,3.6,3.6,0,0,0,0};
			blunttraumaPad[] = {0,0,0,0.9,0.9,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_t522_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) T-52-2 Level II";
		picture = "\SCT\addons\SonicT_vest\data\doron.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: US Military, Vietnam War<br />Rating: Level II-, Doron Laminate<br />Introduced: 1952<br />Will withstand .45 ACP";
		mass = 98;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"T-52-2 Doron Laminate Armor", 1};
			enableparts[] = {0,0,0,4,4,0,0,0,0};
			blunttraumaPad[] = {0,0,0,1.2,1.2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_dragonskin_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) DragonSkin Level III";
		picture = "\SCT\addons\SonicT_vest\data\dragonskin.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: PMCs and American Special Forces<br />Rating: NIJ Level III Ceramic, Scalar<br />Introduced: 1999<br />Highly resistant against multiple impacts";
		mass = 155;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"SOV-2000 Level III", 0};
			enableparts[] = {5,0,13,13,13,6,0,0,0};
			blunttraumaPad[] = {1,0,3,3,3,3,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_dragonskinheavy_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) DragonSkin Level IV";
		picture = "\SCT\addons\SonicT_vest\data\dragonskin.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: PMCs and American Special Forces<br />Rating: NIJ Level IV Ceramic, Scalar<br />Introduced: 1999<br />Will withstand multiple IV-level threats";
		mass = 160;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"SOV-3000 Level IV", 0};
			enableparts[] = {5,0,17,17,17,8,0,0,0};
			blunttraumaPad[] = {1,0,3,3,3,3,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_dragonskinheavyf_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) DragonSkin Level IV/MC";
		picture = "\SCT\addons\SonicT_vest\data\dragonskin.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Tier One Teams<br />Rating: NIJ Level IV Ceramic, Scalar<br />Introduced: 1999<br />Will withstand multiple IV-level threats<br />Maximum Coverage";
		mass = 250;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"SOV-3000 Level IV/MC", 0};
			enableparts[] = {5,3,17,17,17,15,0,0,0};
			blunttraumaPad[] = {1.7,1,3,3,3,3,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_dragonskinassault_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) DragonSkin Level V";
		picture = "\SCT\addons\SonicT_vest\data\dragonskin.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Federal Government<br />Rating: MIL-V Ceramic, Scalar<br />Introduced: 1999<br />Will withstand M993, M948, BS40 API, and M995";
		mass = 230;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"SOV-5000 Level V", 0};
			enableparts[] = {5,0,25,25,25,14,0,0,0};
			blunttraumaPad[] = {1,0,3,3,3,3,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_dragonskinassault2_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) DragonSkin Level V/MC";
		picture = "\SCT\addons\SonicT_vest\data\dragonskin.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Federal Government<br />Rating: MIL-V Ceramic, Scalar<br />Introduced: 1999<br />Will withstand M993, M948, BS40 API, and M995<br />Maximum Coverage";
		mass = 300;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"SOV-5000 Level V/MC", 0};
			enableparts[] = {11,3,25,25,25,13,0,0,0};
			blunttraumaPad[] = {1.6,1,3,3,3,3,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_dragonskinx_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) DragonSkin Level VI";
		picture = "\SCT\addons\SonicT_vest\data\dragonskin.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Federal Government<br />Rating: MIL-VI Ceramic, Scalar<br />Introduced: 1999<br />Will withstand repeat .338 Lapua Magnum";
		mass = 290;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"SOV-6000 Level VI", 0};
			enableparts[] = {10,0,32,32,32,21,0,0,0};
			blunttraumaPad[] = {1,0,3,3,3,3,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_dragonskinxmc_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) DragonSkin Level VI/MC";
		picture = "\SCT\addons\SonicT_vest\data\dragonskin.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Federal Government<br />Rating: MIL-VI Ceramic, Scalar<br />Introduced: 1999<br />Will withstand repeat .338 Lapua Magnum<br />Maximum Coverage";
		mass = 320;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"SOV-6000 Level VI, Maximum Coverage", 0};
			enableparts[] = {32,12,32,32,32,32,0,0,0};
			blunttraumaPad[] = {3,2,3,3,3,3,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_dragonskinxd_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) DragonSkin Level VII";
		picture = "\SCT\addons\SonicT_vest\data\dragonskin.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Federal Government<br />Rating: MIL-VII Ceramic, Scalar<br />Introduced: 1999<br />Will withstand 12.7x55mm STs-130";
		mass = 350;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"SOV-7000 Level VII", 0};
			enableparts[] = {15,0,52,52,52,25,0,0,0};
			blunttraumaPad[] = {1,0,3,3,3,3,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_RBA_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) Ranger Body Armor MIL-IV";
		picture = "\SCT\addons\SonicT_vest\data\rba.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: 75th Ranger Regiment<br />Rating: MIL-IV Ceramic, Aluminum Oxide<br />Introduced: Gothic Serpent, 1993<br />Will withstand multiple 7.62x51mm FMJ rounds";
		mass = 145;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"Ranger Body Armor", 0};
			enableparts[] = {0,0,16,16,16,0,0,0,0};
			blunttraumaPad[] = {0,0,2.2,2.2,2.2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_RBAMC_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) Ranger Body Armor MIL-IV/MC";
		picture = "\SCT\addons\SonicT_vest\data\rba.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: 75th Ranger Regiment<br />Rating: MIL-IV Ceramic, Maximum Coverage, Aluminum Oxide<br />Introduced: Gothic Serpent, 1993<br />Will withstand multiple 7.62x51mm FMJ rounds.<br />Maximum Coverage";
		mass = 220;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"Ranger Body Armor", 0};
			enableparts[] = {0,8,16,16,16,14,0,0,0};
			blunttraumaPad[] = {0,1,2.2,2.2,2.2,2.2,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_6b46_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) GOST-6A 6B46";
		picture = "\SCT\addons\SonicT_vest\data\6b45.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Russian Armed Forces<br />Rating: GOST 6A Ceramic, Boron Carbide<br />Introduced: 2016<br />Multiple-hit resistant against 7.62x54mm FMJ";
		mass = 108;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"GOST-6A 6B46 Plate", 0};
			enableparts[] = {0,0,18,18,18,0,0,0,0};
			blunttraumaPad[] = {0,0,2,2,2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_6b46r2_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) GOST-6A 6B46/R2";
		picture = "\SCT\addons\SonicT_vest\data\6b45.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Russian Special Forces utilizing the Ratnik-II heavy armor systems.<br />Rating: GOST 6A Ceramic, Boron Carbide, Extended Coverage<br />Introduced: 2016<br />Multiple-hit resistant against 7.62x54mm FMJ";
		mass = 150;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"GOST-6A 6B46 Plate", 0};
			enableparts[] = {0,6,18,18,18,12,5,0,0};
			blunttraumaPad[] = {0,1.5,2,2,2,2,1.2,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_6b45_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) GOST-6 6B45";
		picture = "\SCT\addons\SonicT_vest\data\6b45.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Russian Armed Forces<br />Rating: GOST 6 Ceramic, Boron Carbide<br />Introduced: 2015<br />Multiple-hit resistant against 7.62x54mm FMJ";
		mass = 104;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"GOST-6 6B45 Plate", 0};
			enableparts[] = {0,0,16,16,16,0,0,0,0};
			blunttraumaPad[] = {0,0,2,2,2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_6b23_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) GOST-5 6B23";
		picture = "\SCT\addons\SonicT_vest\data\6b45.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Russian Armed Forces<br />Rating: GOST 5 Ceramic, Aluminum Oxide<br />Introduced: 2000s<br />Multiple-hit resistant against 7.62x39mm";
		mass = 150;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"GOST-5 6B23 Plate", 0};
			enableparts[] = {0,0,14,14,14,0,0,0,0};
			blunttraumaPad[] = {0,0,1.8,1.8,1.8,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_6b23S_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) GOST-5A 6B23";
		picture = "\SCT\addons\SonicT_vest\data\6b45.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Russian Armed Forces<br />Rating: GOST 5A Steel<br />Introduced: 2000s<br />Multiple-hit resistant against 7.62x39mm API";
		mass = 210;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"GOST-5A 6B23 Plate", 0};
			enableparts[] = {0,0,15,15,15,0,0,0,0};
			blunttraumaPad[] = {0,0,1.2,1.2,1.2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_rus5_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) MIL-V 6B58";
		picture = "\SCT\addons\SonicT_vest\data\6b58.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Spetsnaz<br />Rating: MIL-V Ceramic, Boron Carbide<br />Introduced: 2015<br />Rated to withstand M995, M993, 7N39, and .338 Lapua Magnum Ball";
		mass = 130;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-V 6B58 Plate", 0};
			enableparts[] = {0,0,26,26,26,0,0,0,0};
			blunttraumaPad[] = {0,0,2,2,2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_neck1_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(SpecialInsert) Defender-2 Neck Guard";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: FSB<br />Rating: Level II<br />Introduced: 2000s<br />Rated to withstand 9x19mm";
		mass = 40;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"Defender 2 Neck Guard", 1};
			enableparts[] = {5,0,0,0,0,0,0,0,0};
			blunttraumaPad[] = {1,0,0,0,0,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_neck2_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(SpecialInsert) Galls Level IIIA Neck Guard";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: SWAT Teams<br />Rating: NIJ IIIA<br />Introduced: 2000s<br />Rated to withstand .44 Magnum";
		mass = 70;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"Galls Level IIIA Neck Guard", 1};
			enableparts[] = {8,0,0,0,0,0,0,0,0};
			blunttraumaPad[] = {1,0,0,0,0,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_rustrauma_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Trauma) Climatic-Amortization Plate";
		picture = "\SCT\addons\SonicT_vest\data\Capture.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Spetsnaz<br />Rating: Class 10 Trauma Pad<br />Introduced: 2015<br />Heavily aids in absorbing bullets";
		mass = 70;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"Class 10 Trauma Pad", 0};
			enableparts[] = {0,0,4,4,4,0,0,0,0};
			blunttraumaPad[] = {0,0,6,6,6,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_rus5ovr_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) MIL-V 6B58/OVR";
		picture = "\SCT\addons\SonicT_vest\data\6b58.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Assault Sappers utilizing the FORT OVR-3Sh body armor system<br />Rating: MIL-V Ceramic, Boron Carbide, Extended Coverage<br />Introduced: 2015<br />Rated to withstand M995, M993, 7N39, and .338 Lapua Magnum Ball";
		mass = 180;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-V 6B58/OVR Plates", 0};
			enableparts[] = {0,8,26,26,26,22,6,0,0};
			blunttraumaPad[] = {0,1,2,2,2,2,1,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_rus4F_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) MIL-VA 6B54";
		picture = "\SCT\addons\SonicT_vest\data\6b58.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Select Forces<br />Rating: MIL-IV* Ceramic, Boron Carbide<br />Introduced: 2015<br />Rated for M995 and .338 Lapua Magnum Ball";
		mass = 130;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-IV* 6B54 Plate", 0};
			enableparts[] = {0,0,19,19,19,0,0,0,0};
			blunttraumaPad[] = {0,0,2,2,2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_4sas7_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) Highcom 4SAS-7 IV";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Civilians<br />Rating: NIJ Level IV Ceramic<br />Introduced: 2000s<br />Rated against 30-06 M2AP";
		mass = 190;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"4SAS-7 Level IV", 0};
			enableparts[] = {0,0,17,17,17,0,0,0,0};
			blunttraumaPad[] = {0,0,2.1,2.1,2.1,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_b4c_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) Multi-Curve B4C IV";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: SWAT Tactical Units<br />Rating: NIJ Level IV Ceramic<br />Introduced: 2000s<br />Rated against 30-06 M2AP";
		mass = 140;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"Multi-Curve B4C IV", 0};
			enableparts[] = {0,0,16,16,16,13,0,0,0};
			blunttraumaPad[] = {0,0,2,2,2,1,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};

	class SCT_plate_steel_ar5001_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) AR500 Level III+";
		picture = "\SCT\addons\SonicT_vest\data\ar500.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Contractors, Civilians, PMCs<br />Rating: NIJ Level III+<br />Introduced: 2000s<br />Will withstand repeat 5.56x45mm M193 impacts";
		mass = 194;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"AR500 Level III+ ", 2};
			enableparts[] = {0,0,15,15,15,0,0,0,0};
			blunttraumaPad[] = {0,0,1.4,1.4,1.4,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_steel_ar500C_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) AR500 Level III";
		picture = "\SCT\addons\SonicT_vest\data\ar500.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Contractors, Civilians, PMCs<br />Rating: NIJ Level III<br />Introduced: 2000s<br />Will withstand repeat 7.62x51mm FMJ impacts";
		mass = 184;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"AR500 Level III", 2};
			enableparts[] = {0,0,12,12,12,0,0,0,0};
			blunttraumaPad[] = {0,0,1.5,1.5,1.5,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_steel_ar500STP_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) AR500 STP";
		picture = "\SCT\addons\SonicT_vest\data\ar500.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Contractors, Civilians, PMCs<br />Rating: Special Threat Plate<br />Introduced: 2000s<br />Will withstand basic 5.56 and 7.62 cartridges";
		mass = 134;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"AR500 STP", 2};
			enableparts[] = {0,0,8,8,8,0,0,0,0};
			blunttraumaPad[] = {0,0,1.3,1.3,1.3,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_steel_ar500CS_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) AR500 Level III/S";
		picture = "\SCT\addons\SonicT_vest\data\ar500.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Contractors, Civilians, PMCs<br />Rating: NIJ Level III, Small-sized<br />Introduced: 2000s<br />Will withstand repeat 7.62x51mm FMJ impacts";
		mass = 140;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"AR500 Level III, 8x10", 2};
			enableparts[] = {0,0,0,12,12,2,0,0,0};
			blunttraumaPad[] = {0,0,0,1.4,1.4,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_steel_ar500CT_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) AR500 Level III/MC";
		picture = "\SCT\addons\SonicT_vest\data\ar500.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Contractors, Civilians, PMCs<br />Rating: NIJ Level III, Maximum Coverage<br />Introduced: 2000s<br />Will withstand repeat 7.62x51mm FMJ impacts";
		mass = 251;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"AR500 Level III/MC", 2};
			enableparts[] = {0,7,12,12,12,12,0,0,0};
			blunttraumaPad[] = {0,1,1.4,1.4,1.4,1,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_steel_ar5004_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) AR500 Level IV";
		picture = "\SCT\addons\SonicT_vest\data\ar500.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Contractors, Civilians, PMCs<br />Rating: NIJ Level IV, Steel<br />Introduced: 2000s<br />Will withstand repeat 30-06 M2AP impacts";
		mass = 280;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"AR500 Level IV", 2};
			enableparts[] = {0,0,18,18,18,0,0,0,0};
			blunttraumaPad[] = {0,0,1.6,1.6,1.6,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_steel_ar5004CAA_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) AR500-Ceramic Level IV";
		picture = "\SCT\addons\SonicT_vest\data\ar500.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Contractors, Civilians, PMCs<br />Rating: NIJ Level IV, Ceramic<br />Introduced: 2000s<br />Will withstand .22-250 Remington";
		mass = 150;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"AR500 Level IV, Ceramic", 2};
			enableparts[] = {0,0,17,17,17,0,0,0,0};
			blunttraumaPad[] = {0,0,2,2,2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_steel_ar5004MC_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) AR500 Level IV/MC";
		picture = "\SCT\addons\SonicT_vest\data\ar500.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Contractors, Civilians, PMCs<br />Rating: NIJ Level IV, Maximum Coverage<br />Introduced: 2000s<br />Will withstand repeat 30-06 M2AP impacts";
		mass = 360;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"AR500 Level IV/MC", 2};
			enableparts[] = {0,8,17,17,17,14,0,0,0};
			blunttraumaPad[] = {0,1.6,1.6,1.6,1.6,1.6,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_steel_ar5005_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) AR500 Level V";
		picture = "\SCT\addons\SonicT_vest\data\ar500.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Well-funded PMCs, well-connected survivalists<br />Rating: NIJ Level IV, MIL-V<br />Introduced: 2010s<br />Rated for .338 Lapua Magnum";
		mass = 370;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"AR500 Level V", 2};
			enableparts[] = {0,0,25,25,25,0,0,0,0};
			blunttraumaPad[] = {0,0,2,2,2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_steel_ar5005mc_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) AR500 Level V/MC";
		picture = "\SCT\addons\SonicT_vest\data\ar500.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Well-funded PMCs, well-connected survivalists<br />Rating: NIJ Level IV, MIL-V, Maximum Coverage<br />Introduced: 2010s<br />Rated for .338 Lapua Magnum";
		mass = 470;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"AR500 Level V, Maximum Coverage", 2};
			enableparts[] = {0,9,25,25,25,17,0,0,0};
			blunttraumaPad[] = {0,2,2,2,2,2,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_steel_arbudget_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) AR500 Level IIIA";
		picture = "\SCT\addons\SonicT_vest\data\ar500.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Contractors, Civilians, PMCs<br />Rating: NIJ Level IIIA<br />Introduced: 2000s<br />Will withstand repeat .44 Magnum impacts";
		mass = 110;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"AR500 Level IIIA ", 2};
			enableparts[] = {0,0,8,8,8,0,0,0,0};
			blunttraumaPad[] = {0,0,1.2,1.2,1.2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_kevlar_3_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) Kevlar Level IIIA";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Contractors, Civilians, PMCs<br />Rating: NIJ Level IIIA<br />Introduced: 1980s<br />Will withstand revolver impacts";
		mass = 44;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"Kevlar Level IIIA", 4};
			enableparts[] = {0,0,7,7,7,0,0,0,0};
			blunttraumaPad[] = {0,0,0.7,0.7,0.7,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_kevlar_2_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) Kevlar Level II";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Contractors, Civilians, PMCs<br />Rating: NIJ Level II<br />Introduced: 1980s<br />Will withstand at least one 9x19mm Parabellum FMJ impact";
		mass = 25;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"Kevlar Level II", 4};
			enableparts[] = {0,0,6,6,6,0,0,0,0};
			blunttraumaPad[] = {0,0,0.7,0.7,0.7,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_kevlar_1_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) Kevlar Level I";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Contractors, Civilians, PMCs<br />Rating: NIJ Level I<br />Introduced: 1980s<br />Will withstand very light shrapnel";
		mass = 15;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"Kevlar Level I", 4};
			enableparts[] = {0,0,2,3,2,0,0,0,0};
			blunttraumaPad[] = {0,0,0.7,0.7,0.7,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_nylon_1_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) B-Nylon Level I";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: United States Military<br />Rating: NIJ Level I<br />Introduced: 1960s<br />Don't try getting shot.";
		mass = 23;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"Ballistic Nylon Level I", 4};
			enableparts[] = {0,0,2,2,2,0,0,0,0};
			blunttraumaPad[] = {0,0,0.7,0.7,0.7,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_nylon_2_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) B-Nylon Level II";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: United States Military<br />Rating: NIJ Level II<br />Introduced: 1960s<br />Designed to stop fragmentation.";
		mass = 26;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"Ballistic Nylon Level II", 4};
			enableparts[] = {0,0,5,5,5,0,0,0,0};
			blunttraumaPad[] = {0,0,0.7,0.7,0.7,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_steel_ar680_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) AR680 Level III+";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Contractors, Civilians, PMCs<br />Rating: NIJ Level III+<br />Introduced: 2010s<br />Will withstand repeat 7.62x51mm Ball";
		mass = 144;

		class SCT_ITEMINFO{
			plateinfo[] = {"AR680 Level III+", 2};
			enableparts[] = {0,0,13,13,13,0,0,0,0};
			blunttraumaPad[] = {0,0,1.3,1.3,1.3,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_steel_ar680b_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) AR680 Level IV";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Contractors, Civilians, PMCs<br />Rating: NIJ Level IV<br />Introduced: 2010s<br />Will withstand repeat 7.62x51mm Ball";
		mass = 164;

		class SCT_ITEMINFO{
			plateinfo[] = {"AR680 Level IV", 2};
			enableparts[] = {0,0,18,18,18,0,0,0,0};
			blunttraumaPad[] = {0,0,1.3,1.3,1.3,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_ffs4_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) FFS4 Level IV+";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Contractors, Civilians, PMCs<br />Rating: NIJ Level IV+<br />Introduced: 2000s<br />Will withstand M61 7.62x51mm AP Ball";
		mass = 152;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"FFS4 IV+", 0};
			enableparts[] = {0,0,17,17,17,0,0,0,0};
			blunttraumaPad[] = {0,0,2,2,2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_SAmix_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) BBA SA Mix";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Armed Forces of South Africa<br />Rating: Unrated<br />Introduced: 2000s<br />Will withstand repeat M193 5.56x45mm Ball";
		mass = 86;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"SA Mix Plate", 0};
			enableparts[] = {0,0,10,10,10,0,0,0,0};
			blunttraumaPad[] = {0,0,2,2,2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_SAIII_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) BBA Level III";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Armed Forces of South Africa<br />Rating: NIJ Level III<br />Introduced: 2000s<br />Will withstand repeat 7.62x51mm Ball";
		mass = 112;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"BBA III", 0};
			enableparts[] = {0,0,11,11,11,0,0,0,0};
			blunttraumaPad[] = {0,0,2,2,2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_SAIV_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) BBA IV";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Armed Forces of South Africa<br />Rating: NIJ Level IV<br />Introduced: 2000s<br />Will withstand 30-06 M2AP";
		mass = 144;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"BBA IV", 0};
			enableparts[] = {0,0,16,16,16,0,0,0,0};
			blunttraumaPad[] = {0,0,2,2,2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_bushtracker_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) BBA Bushtracker";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Armed Forces of South Africa<br />Rating: Unrated<br />Introduced: 2000s<br />Will withstand Elephant Rifle cartridges";
		mass = 170;

		class SCT_ITEMINFO{
			plateinfo[] = {"BBA Bushtracker", 0};
			enableparts[] = {0,0,0,22,22,0,0,0,0};
			blunttraumaPad[] = {0,0,0,4,4,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_titanium_6b3tm_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) 6B3TM GOST 4";
		picture = "\SCT\addons\SonicT_vest\data\6b3tm.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Former Warsaw Pact Nations<br />Rating: GOST Class 4, Titanium<br />Introduced: 1984<br />Will withstand 7.62x39mm Steel-core rounds";
		mass = 110;

		class SCT_ITEMINFO{
			plateinfo[] = {"6B3TM GOST 4", 2};
			enableparts[] = {0,0,11,11,11,0,0,0,0};
			blunttraumaPad[] = {0,0,1,1,1,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};		
	};
	
	class SCT_plate_titanium_6b3tm01_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) 6B3TM01 GOST 5";
		picture = "\SCT\addons\SonicT_vest\data\6b3tm.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Former Warsaw Pact Nations<br />Rating: GOST Class 5, Titanium<br />Introduced: 1984<br />Will withstand 7.62x39mm Steel-core rounds";
		mass = 111;

		class SCT_ITEMINFO{
			plateinfo[] = {"6B3TM01 GOST 5", 1};
			enableparts[] = {0,0,14,12,14,0,0,0,0};
			blunttraumaPad[] = {0,0,1.25,1.25,1.25,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};		
	};
	
	class SCT_plate_ceramic_ceradyne_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) Ceradyne MIL-VIII";
		picture = "\SCT\addons\SonicT_vest\data\ceradyne2.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: United States Military<br />Rating: MIL-VIII<br />Introduced: 1994<br />.50 BMG Protective, 10x14";
		mass = 330;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-VIII Ceradyne .50 BMG Protective", 0};
			enableparts[] = {0,0,190,190,190,0,0,0,0};
			blunttraumaPad[] = {0,0,8,8,8,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_poly_DFNDR_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) DFNDR Level III+";
		picture = "\SCT\addons\SonicT_vest\data\SCT_poly_dfndr_3p.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_poly_dfndr_3p.p3d"
		descriptionShort = "Used By: Civilians, Law Enforcement<br />Rating: NIJ Level III+<br />Introduced: 2000s<br />Rated for 7.62x51mm Ball impacts";
		mass = 80;

		class SCT_ITEMINFO{
			plateinfo[] = {"DEFENDER Lightweight Level III+", 1};
			enableparts[] = {0,0,11,11,11,0,0,0,0};
			blunttraumaPad[] = {0,0,0.9,0.9,0.9,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_poly_dragic_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) MD Spectra III";
		picture = "\SCT\addons\SonicT_vest\data\serb.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_poly_dfndr_3p.p3d"
		descriptionShort = "Used By: Serbian Armed Forces<br />Rating: NIJ Level III<br />Introduced: 2000s<br />Rated for M193 5.56x45mm";
		mass = 85;

		class SCT_ITEMINFO{
			plateinfo[] = {"Mile Dragic Spectra III", 1};
			enableparts[] = {0,0,11,11,11,0,0,0,0};
			blunttraumaPad[] = {0,0,1.1,1.1,1.1,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_poly_PACA_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) PACA Blade Plate";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_poly_dfndr_3p.p3d"
		descriptionShort = "Used By: Corrections Officer<br />Rating: Shank-proof<br />Introduced: 2010s<br />Don't drop the soap!";
		mass = 22;

		class SCT_ITEMINFO{
			plateinfo[] = {"Blade Plate", 1};
			enableparts[] = {0,0,1,1,1,0,0,0,0};
			blunttraumaPad[] = {0,0,1.2,1.2,1.2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_trauma_AR500_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Trauma) AR500 Trauma Pad";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Civilians, SWAT<br />Rating: Non-ballistic<br />Introduced: 2010s<br />Increases chances of survival";
		mass = 15;

		class SCT_ITEMINFO{
			plateinfo[] = {"Class 2 Trauma Pad", 3};
			enableparts[] = {0,0,1,1,1,0,0,0,0};
			blunttraumaPad[] = {0,0,2.2,2.2,2.2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_trauma_Spartan_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Trauma) Spartan Trauma Pad";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Civilians, Survivalists<br />Rating: Non-ballistic<br />Introduced: 2010s<br />Absorbs impact force to aid in withstanding high-powered rounds";
		mass = 20;

		class SCT_ITEMINFO{
			plateinfo[] = {"Class 3 Trauma Pad", 3};
			enableparts[] = {0,0,1,1,1,0,0,0,0};
			blunttraumaPad[] = {0,0,3.2,3.2,3.2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_trauma_Spartanf_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Trauma) Heavy Trauma Pad";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Civilians, Survivalists<br />Rating: Non-ballistic<br />Introduced: 2010s<br />Absorbs impact force to aid in withstanding high-powered rounds";
		mass = 36;

		class SCT_ITEMINFO{
			plateinfo[] = {"Class 5 Trauma Pad", 3};
			enableparts[] = {0,0,1,1,1,0,0,0,0};
			blunttraumaPad[] = {0,0,6.2,6.2,6.2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class BER_Boost_Special_Doubler_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Special) Euro Extreme Mode";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Switches AAPM into one-shot-kill mode<br />deducts fifty armor";
		mass = 1;

		class SCT_ITEMINFO{
			plateinfo[] = {"Euro Extreme Mode", 0};
			enableparts[] = {-50,-50,-50,-50,-50,-50,-50,-50,-50};
			blunttraumaPad[] = {1,1,1,1,1,1,1,1,1};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class BER_Boost_Special_Infiltration_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Special) Old School Mode";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Makes you feel like you're in the late 1990s again.<br />deducts twenty-five armor<br />Modeled after UT99 Infiltration.";
		mass = 1;

		class SCT_ITEMINFO{
			plateinfo[] = {"Old School Mode", 0};
			enableparts[] = {-25,-25,-25,-25,-25,-25,-25,-25,-25};
			blunttraumaPad[] = {1,1,1,1,1,1,1,1,1};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_poly_speedplate3_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) SPEED-Plate Level III";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_poly_dfndr_3p.p3d"
		descriptionShort = "Used By: First Responders, Law Enforcement<br />Rating: NIJ Level III<br />Introduced: 2010s<br />Rated for 5.56x45mm M193";
		mass = 44;

		class SCT_ITEMINFO{
			plateinfo[] = {"SPEED-Plate Level III", 1};
			enableparts[] = {0,0,11,11,11,0,0,0,0};
			blunttraumaPad[] = {0,0,0.5,0.4,0.4,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_poly_speedplate4_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) Paraclete #20015 Level IV";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_poly_dfndr_3p.p3d"
		descriptionShort = "Used By: Civilians, Law Enforcement<br />Rating: NIJ Level IV<br />Introduced: 2010s<br />Rated for 30-06 M2AP";
		mass = 170;

		class SCT_ITEMINFO{
			plateinfo[] = {"Paraclete Level IV", 0};
			enableparts[] = {0,0,14,14,14,0,0,0,0};
			blunttraumaPad[] = {0,0,2,2,2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_poly_JD_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) JD Level IV";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Civilians<br />Rating: NIJ Level IV<br />Introduced: 2010s<br />Rated for 30-06 M2AP";
		mass = 78;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"JD Level IV Polyethylene", 1};
			enableparts[] = {0,0,14,14,14,0,0,0,0};
			blunttraumaPad[] = {0,0,1.6,1.6,1.6,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_poly_PSAPI_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) SPEAR MIL-III";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: United States Military<br />Rating: NIJ Level III, Polyethylene<br />Introduced: 2010s<br />Rated for .308";
		mass = 84;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"SPEAR MIL-III Polyethylene", 1};
			enableparts[] = {0,0,10,10,10,0,0,0,0};
			blunttraumaPad[] = {0,0,1.8,1.8,1.8,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_gamma_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) TAP Gamma NIJ-III";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Law Enforcement<br />Rating: NIJ Level III, Ceramic<br />Introduced: 2003<br />Rated for multi-impact .308";
		mass = 120;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"TAP Gamma NIJ-III", 0};
			enableparts[] = {0,0,12,12,12,0,0,0,0};
			blunttraumaPad[] = {0,0,2.2,2.2,2.2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_ceramic_gamma2_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) TAP Gamma NIJ-III+";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Law Enforcement<br />Rating: NIJ Level III+, Ceramic<br />Introduced: 2003<br />Rated for M855 and M193";
		mass = 130;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"TAP Gamma NIJ-III+", 0};
			enableparts[] = {0,0,14,14,14,0,0,0,0};
			blunttraumaPad[] = {0,0,2.2,2.2,2.2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_poly_m1199_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) RMA M1199 NIJ-IV";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Civilians<br />Rating: NIJ Level IV, Special Ceramic<br />Introduced: 2010s<br />Rated for many 30-06 M2AP";
		mass = 150;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"RMA Level IV Ceramic panel", 0};
			enableparts[] = {0,0,18,18,18,0,0,0,0};
			blunttraumaPad[] = {0,0,2,2,2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_poly_m1155_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) RMA M1155 NIJ-IV*";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Civilians<br />Rating: NIJ Level IV, MIL-VA<br />Introduced: 2010s<br />Rated for five 30-06 M2APs or one .338 Lapua Magnum";
		mass = 190;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"RMA Level IV Ceramic panel", 0};
			enableparts[] = {0,0,19.5,19.5,19.5,0,0,0,0};
			blunttraumaPad[] = {0,0,2.1,2.1,2.1,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_poly_angel_308S_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) 308S Level III-S";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Civilians, Contractors<br />Rating: NIJ Level III<br />Introduced: 2010s<br />Rated for .308<br />Small 5x8 model";
		mass = 65;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"308S Polyethylene panel", 1};
			enableparts[] = {0,0,0,11,11,0,0,0,0};
			blunttraumaPad[] = {0,0,0,1.8,1.8,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_uniform_underwear_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(UniformArmor) Ballistic Underwear";
		picture = "\SCT\addons\SonicT_vest\data\underwear.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Level II Underwear";
		mass = 24;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"Level II Underwear", 0};
			enableparts[] = {0,0,0,0,0,4,0,0,0};
			blunttraumaPad[] = {0,0,0,0,0,1,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_uniform_underwear3_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(UniformArmor) Ballistic Underwear UP";
		picture = "\SCT\addons\SonicT_vest\data\underwear.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Level IIIA Underwear";
		mass = 32;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"Level IIIA Underwear", 0};
			enableparts[] = {0,0,0,0,0,9,0,0,0};
			blunttraumaPad[] = {0,0,0,0,0,1,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_uniform_kevlarinsert1_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(UniformInsert) Level II Kevlar Insert";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Level II Kevlar Insert";
		mass = 70;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"Level II Kevlar Insert", 1};
			enableparts[] = {3,3,0,0,0,3,3,0,0};
			blunttraumaPad[] = {1,1,0,0,0,1,1,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_uniform_kevlarinsert3_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(UniformInsert) Level IIIA Kevlar";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Level IIIA Kevlar Insert";
		mass = 86;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"Level IIIA Kevlar Insert", 1};
			enableparts[] = {5,5,0,0,0,5,5,0,0};
			blunttraumaPad[] = {1,1,0,0,0,1,1,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_uniform_KEV3_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(UniformInsert) DragonSkin Level III";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Contractors, Raid Crews<br />Rating: NIJ Level III<br />Introduced: 1999<br />NIJ Level III, all limbs";
		mass = 170;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"DragonSkin SOV-Uniform NIJ III", 0};
			enableparts[] = {13,12.5,10,10,10,12.5,12.5,0,0};
			blunttraumaPad[] = {2,2,2,2,2,2,2,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_uniform_STE3_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(UniformInsert) AR500 Multipad NIJ III";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Soldiers of Fortune, marathon-sortie operators<br />Rating: NIJ Level III<br />Introduced: 2000s<br />NIJ Level III, all limbs";
		mass = 230;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"NIJ III AR500 Multipad", 2};
			enableparts[] = {12,12,10,10,10,12,12,0,0};
			blunttraumaPad[] = {1,1,1,1,1,1,1,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_uniform_STE4_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(UniformInsert) AR500 Multipad NIJ IV";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Soldiers of Fortune, marathon-sortie operators<br />Rating: NIJ Level IV<br />Introduced: 2000s<br />NIJ Level IV, all limbs";
		mass = 340;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"NIJ IV AR500 Multipad", 2};
			enableparts[] = {16,16,12,12,12,16,16,0,0};
			blunttraumaPad[] = {1,1,1,1,1,1,1,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_uniform_3UHMWPE_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(UniformInsert) UHMWPE NIJ III";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Special Forces<br />Rating: NIJ Level III<br />Introduced: 2010s<br />NIJ Level III, all limbs";
		mass = 150;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"NIJ III UHMWPE", 1};
			enableparts[] = {13,13,8,8,8,13,13,0,0};
			blunttraumaPad[] = {1.5,1.5,1.5,1.5,1.5,1.5,1.5,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_uniform_4UHMWPE_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(UniformInsert) UHMWPE NIJ IV";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Special Forces<br />Rating: NIJ Level IV<br />Introduced: 2010s<br />NIJ Level IV, all limbs";
		mass = 200;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"NIJ IV UHMWPE", 1};
			enableparts[] = {15.5,15.5,9,9,9,15.5,15.5,0,0};
			blunttraumaPad[] = {1.5,1.5,1.5,1.5,1.5,1.5,1.5,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_uniform_KEV4_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(UniformInsert) DragonSkin Level IV";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Contractors, Raid Crews<br />Rating: NIJ Level IV<br />Introduced: 1999<br />NIJ Level IV, all limbs";
		mass = 220;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"DragonSkin SOV-Uniform NIJ IV", 0};
			enableparts[] = {16,16,8,8,8,16,16,0,0};
			blunttraumaPad[] = {2,2,2,2,2,2,2,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_uniform_KEV5_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(UniformInsert) DragonSkin MIL-V";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Federal Government<br />Rating: MIL-V<br />Introduced: 1999<br />MIL-V, all limbs";
		mass = 270;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"DragonSkin SOV-Uniform MIL-V", 0};
			enableparts[] = {21,21,10,10,10,21,21,0,0};
			blunttraumaPad[] = {2,2,2,2,2,2,2,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_uniform_KEV6_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(UniformInsert) DragonSkin MIL-VI";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Federal Government<br />Rating: MIL-VI<br />Introduced: 1999<br />MIL-VI, all limbs";
		mass = 400;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"DragonSkin SOV-Uniform MIL-VI", 0};
			enableparts[] = {32,32,20,20,20,32,32,0,0};
			blunttraumaPad[] = {1.8,1.8,1.8,1.8,1.8,1.8,1.8,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	
	class SCT_booster_helmetface3a_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Booster) NIJ IIIA Helmet Booster";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Reinforcement for helmet";
		mass = 44;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"NIJ IIIA", 2};
			enableparts[] = {0,0,0,0,0,0,0,6,0};
			blunttraumaPad[] = {0,0,0,0,0,0,0,0.8,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_booster_helmetface2_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Booster) NIJ II Helmet Booster";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Reinforcement for helmet";
		mass = 35;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"NIJ II", 2};
			enableparts[] = {0,0,0,0,0,0,0,4,0};
			blunttraumaPad[] = {0,0,0,0,0,0,0,0.7,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_booster_helmetface3_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Booster) NIJ III Helmet Booster";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Helmet reinforcement";
		mass = 50;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"NIJ III", 2};
			enableparts[] = {0,0,0,0,0,0,0,13,0};
			blunttraumaPad[] = {0,0,0,0,0,0,0,1,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	
	class SCT_booster_helmetface4_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Booster) NIJ IV Helmet Booster";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Heavy Helmet Reinforcement";
		mass = 76;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"NIJ IV", 2};
			enableparts[] = {0,0,0,0,0,0,0,16,0};
			blunttraumaPad[] = {0,0,0,0,0,0,0,1,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_booster_helmetface5_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Booster) MIL-V Helmet Booster";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Super-heavy Helmet Reinforcement";
		mass = 90;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-V", 2};
			enableparts[] = {0,0,0,0,0,0,0,22,0};
			blunttraumaPad[] = {0,0,0,0,0,0,0,1.1,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_booster_helmetface5s_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Booster) MIL-VS Helmet Booster";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Ultra-heavy Helmet Reinforcement";
		mass = 100;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-VS", 2};
			enableparts[] = {0,0,0,0,0,0,0,22,0};
			blunttraumaPad[] = {0,0,0,0,0,0,0,1.7,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_booster_helmetface6_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Booster) MIL-VI Helmet Booster";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Juggernaut Helmet Reinforcement";
		mass = 120;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-VI", 2};
			enableparts[] = {0,0,0,0,0,0,0,30,0};
			blunttraumaPad[] = {0,0,0,0,0,0,0,2.7,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_booster_helmetface7_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Booster) MIL-VII Helmet Booster";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Assault Juggernaut Helmet Reinforcement";
		mass = 150;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-VII", 2};
			enableparts[] = {0,0,0,0,0,0,0,40,0};
			blunttraumaPad[] = {0,0,0,0,0,0,0,3.7,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_booster_face3_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Booster) NIJ III Headshot Guard";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Reinforces your face to Level III Standard";
		mass = 45;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"NIJ III", 2};
			enableparts[] = {0,0,0,0,0,0,0,0,11};
			blunttraumaPad[] = {0,0,0,0,0,0,0,0,2};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_booster_face3a_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Booster) NIJ IIIA Headshot Guard";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Reinforces your face to Level IIIA Standard";
		mass = 34;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"NIJ IIIA", 2};
			enableparts[] = {0,0,0,0,0,0,0,0,9};
			blunttraumaPad[] = {0,0,0,0,0,0,0,0,2};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_booster_face2_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Booster) NIJ II Headshot Guard";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Reinforces your face to Level II Standard";
		mass = 20;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"NIJ IIIA", 2};
			enableparts[] = {0,0,0,0,0,0,0,0,6};
			blunttraumaPad[] = {0,0,0,0,0,0,0,0,2};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_booster_face4_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Booster) NIJ IV Headshot Guard";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Reinforces your face to Level IV Standard";
		mass = 52;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"NIJ IV", 2};
			enableparts[] = {0,0,0,0,0,0,0,0,15};
			blunttraumaPad[] = {0,0,0,0,0,0,0,0,2};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_booster_face5_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Booster) MIL-V Headshot Guard";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Reinforces your face to MIL-V Standard";
		mass = 70;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-V", 2};
			enableparts[] = {0,0,0,0,0,0,0,0,20};
			blunttraumaPad[] = {0,0,0,0,0,0,0,0,2};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_booster_face6_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Booster) MIL-VI Headshot Guard";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Reinforces your face to MIL-VI Standard";
		mass = 95;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-VI", 2};
			enableparts[] = {0,0,0,0,0,0,0,0,30};
			blunttraumaPad[] = {0,0,0,0,0,0,0,0,3};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_booster_face7_magtype: AAPM_Item_Base_magtype {
		scope = 1;
		displayName = "(Booster) MIL-VII Headshot Guard";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Reinforces your face to MIL-VI Standard";
		mass = 110;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-VII", 2};
			enableparts[] = {0,0,0,0,0,0,0,0,40};
			blunttraumaPad[] = {0,0,0,0,0,0,0,0,3};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
};

