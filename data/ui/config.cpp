
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
class RscButtonMenuOK;


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
		
		class SCT_PLATE_menu_Header : RscText {
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

class ToPlateMenu: RscButton
{
	text = "$STR_InitMenu"; //--- ToDo: Localize;
	/*x = 22 * GUI_GRID_W + GUI_GRID_X;
	y = 1 * GUI_GRID_H + GUI_GRID_Y;
	w = 6 * GUI_GRID_W;
	h = 1 * GUI_GRID_H;*/
	x = "0.65 * safezoneW + safezoneX";
	y = "0.05 * safezoneH + safezoneY";
	w = "0.125 * safezoneW";
	h = "0.045 * safezoneH";
	tooltip = "manage your plate insert in your vest / uniform"; //--- ToDo: Localize;
	action = "_this spawn SCT_fnc_Setupgear;";
};


class SCT_PLATE_MANAGER_2 {
	idd = 5981;
	movingEnabled = 1;
	enableSimulation = 1;
	
	class Controls {
		
		class SCT_PLATEMGR_Header: RscText
		{
			idc = 5982;
			text = "$STR_PlateMenu"; //--- ToDo: Localize;
			x = 0.181291 * safezoneW + safezoneX;
			y = 0.075 * safezoneH + safezoneY;
			w = 0.637418 * safezoneW;
			h = 0.0425 * safezoneH;
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.69])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.75])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.5])",0.7};
		};
		
		class SCT_PLATE_MANAGER_BackGround : IGUIBack {
			idc = -1;
			x = "0.181291 * safezoneW + safezoneX";
			y = "0.1175 * safezoneH + safezoneY";
			w = "0.637418 * safezoneW";
			h = "0.8 * safezoneH";
			colorBackground[] = {0, 0, 0, 0.8};
			colorText[] = {1, 1, 1, 1};
		};
			
		class SCT_PLATEMGR_T1: RscText
		{
			idc = -1;
			text = "$STR_EquippedP"; //--- ToDo: Localize;
			x = 0.237065 * safezoneW + safezoneX;
			y = 0.16 * safezoneH + safezoneY;
			w = 0.191225 * safezoneW;
			h = 0.085 * safezoneH;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0};
		};
		class SCT_PLATEMGR_T2: RscText
		{
			idc = -1;
			text = "$STR_PlateOwn"; //--- ToDo: Localize;
			x = 0.57171 * safezoneW + safezoneX;
			y = 0.16 * safezoneH + safezoneY;
			w = 0.191225 * safezoneW;
			h = 0.085 * safezoneH;
		};
		
		class SCT_PLATEMGR_PartCB: RscCombo
		{
			idc = 5983;
			text = "gg"; //--- ToDo: Localize;
			x = 0.237065 * safezoneW + safezoneX;
			y = 0.228 * safezoneH + safezoneY;
			w = 0.191225 * safezoneW;
			h = 0.051 * safezoneH;
			onLBSelChanged = "_this call SCT_fnc_RefreshManager;";
		};
		class SCT_PLATEMGR_InvCB: RscCombo
		{
			idc = 5984;
			text = "gg"; //--- ToDo: Localize;
			x = 0.57171 * safezoneW + safezoneX;
			y = 0.228 * safezoneH + safezoneY;
			w = 0.191225 * safezoneW;
			h = 0.051 * safezoneH;
			onLBSelChanged = "_this call SCT_fnc_RefreshManager";
		};
		class SCT_PLATEMGR_InvLB: RscListbox
		{
			idc = 5986;
			x = 0.57171 * safezoneW + safezoneX;
			y = 0.296 * safezoneH + safezoneY;
			w = 0.191225 * safezoneW;
			h = 0.425 * safezoneH;
			colorSelect[] = {0,0,0,1};
			colorSelect2[] = {1,0.5,0,1};
			colorSelectBackground[] = {0.6,0.6,0.6,1};
			colorSelectBackground2[] = {0.2,0.2,0.2,1};
			onLBDblClick = "_this call SCT_fnc_BtnAddP";

		};
		
		class SCT_PLATEMGR_VehLB: RscListbox
		{
			idc = 5985;
			x = 0.237065 * safezoneW + safezoneX;
			y = 0.296 * safezoneH + safezoneY;
			w = 0.191225 * safezoneW;
			h = 0.425 * safezoneH;
			colorSelect[] = {0,0,0,1};
			colorSelect2[] = {1,0.5,0,1};
			colorSelectBackground[] = {0.6,0.6,0.6,1};
			colorSelectBackground2[] = {0.2,0.2,0.2,1};
			onLBDblClick = "_this call SCT_fnc_BtnDelP";
		};

		class SCT_Btn_AddPlate: RscButton
		{
			idc = 5987;
			text = "<<Add Plate"; //--- ToDo: Localize;
			x = 0.452194 * safezoneW + safezoneX;
			y = 0.347 * safezoneH + safezoneY;
			w = 0.0956127 * safezoneW;
			h = 0.085 * safezoneH;
			tooltip = "add this plate to your desired body part container."; //--- ToDo: Localize;
			action = "_this call SCT_fnc_BtnAddP";
		};
		class SCT_Btn_RemovePlateVeh: RscButton
		{
			idc = 5988;
			text = "Remove Plate>>"; //--- ToDo: Localize;
			x = 0.452194 * safezoneW + safezoneX;
			y = 0.534 * safezoneH + safezoneY;
			w = 0.0956127 * safezoneW;
			h = 0.085 * safezoneH;
			tooltip = "Pull out selected plate and add them in inventory."; //--- ToDo: Localize;
			action = "_this call SCT_fnc_BtnDelP";
		};
		
		class SCT_Btn_APPLY: RscButtonMenuOK
		{
			idc = 5989;
			x = 0.547806 * safezoneW + safezoneX;
			y = 0.823 * safezoneH + safezoneY;
			w = 0.12 * safezoneW;
			h = 0.08 * safezoneH;
			action = "closeDialog 0;";
		};

	};
};
