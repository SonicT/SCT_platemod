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
		requiredVersion = 2.20000;
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

#include "data\ui\config.cpp"
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
			
			class Setupgear{};
			
			class DisableEquip{};
			
			class EquipPlate{};
			
			class RefreshManager{};
			
			class BtnAddP{};
			
			class BtnDelP{};
			
			class virtualLoad{};
			
		};
	};
};





class CfgVehicles{
	class Land;
	class Man;
	/*class Man: Land{
		class EventHandlers{
			class SCTEVENT : SCTEVTEX_base {};
		};
	};*/ // involving this will cause super rabbit or something
//followed CBA config but found they are partially enabled, so looked up original	
	class CAManBase :Man {

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

class CfgMagazines {
	class CA_Magazine;
	#include "data\objects\items_body_plate_magtype.hpp"
};

class CfgWeapons {
	
	class ItemCore;
	class InventoryItem_Base_F;

	#include "data\objects\items_body_plate.hpp"
	#include "data\objects\items_body_traumapads.hpp"
	#include "data\objects\items_head_protection.hpp"
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

