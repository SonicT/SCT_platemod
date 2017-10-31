class SonicT_Item_Base_magtype: CA_Magazine {
		scope = 1;
		access = 3;
		displayName = "-";
		detectRange = -1;
		simulation = "ItemMineDetector";
		useAsBinocular = 0;
		type = 4096;
		picture = "";
		descriptionShort = "";
		mass = 1;
		count = 100;
	};

	class SCT_plate_ceramic_esapi_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) ESAPI MIL-IV";
		picture = "\SCT\addons\SonicT_vest\data\esapi.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: United States Military<br />Rating: MIL-IV Ceramic, Boron Carbide<br />Introduced: 2005<br />Will withstand 30-06 M2AP";
		mass = 108;
		count = 100;
		class SCT_ITEMINFO{
			plateinfo[] = {"ESAPI NIJ IV ceramic ICW soft body armor", 0};
			enableparts[] = {0,0,14,14,14,0,0,0,0};
			blunttraumaPad[] = {0,0,1.1,1.1,1.1,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_ceramic_esapic_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) ESAPI MIL-IV (Ceradyne)";
		picture = "\SCT\addons\SonicT_vest\data\esapi.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: United States Military<br />Rating: MIL-IV Ceramic, Boron Carbide<br />Introduced: 2009<br />Will withstand 30-06 M2AP";
		mass = 120;
		count = 100;

		class SCT_ITEMINFO{
			plateinfo[] = {"ESAPI NIJ IV ceramic, Ceradyne-produced", 0};
			enableparts[] = {0,0,15,15,15,0,0,0,0};
			blunttraumaPad[] = {0,0,0.9,0.9,0.9,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_ceramic_TPG_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) TPG Level IV";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Civilians and LE<br />Rating: NIJ Level IV, Aluminum Oxide<br />Introduced: 2010s<br />Will withstand repeat 30-06 impacts";
		count = 100;

		mass = 140;

		class SCT_ITEMINFO{
			plateinfo[] = {"TPG ceramic Aluminum Oxide plate, Level IV", 0};
			enableparts[] = {0,0,13,13,13,0,0,0,0};
			blunttraumaPad[] = {0,0,1.4,1.4,1.4,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_ceramic_esapimc_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(PLate) ESAPI-MC MIL-IV/MC";
		picture = "\SCT\addons\SonicT_vest\data\esapi.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: United States Military<br />Rating: MIL-IV Ceramic, Boron Carbide<br />Introduced: 2005<br />Will withstand 30-06 M2AP<br />Maximum Coverage";

		count = 100;
		mass = 120;

		class SCT_ITEMINFO{
			plateinfo[] = {"ESAPI NIJ IV ceramic ICW soft body armor", 0};
			enableparts[] = {0,10,14,14,14,10,5,0,0};
			blunttraumaPad[] = {0,1,1,1,1,1,1,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_ceramic_xsapi_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) XSAPI MIL-V GEN3";
		picture = "\SCT\addons\SonicT_vest\data\xsapi.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: United States Military<br />Rating: MIL-V Ceramic, Boron Carbide<br />Introduced: 2016<br />Will withstand M993, M995, or 7N39";

		count = 100;
		mass = 102;

		class SCT_ITEMINFO{
			plateinfo[] = {"XSAPI-2016 ceramic ICW soft body armor", 0};
			enableparts[] = {0,0,25,25,25,0,0,0,0};
			blunttraumaPad[] = {0,0,0.9,0.9,0.9,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_ceramic_lv_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) Xin Xing MIL-V";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: People's Liberation Army, African Mercenaries<br />Rating: MIL-V Ceramic, Aluminum Oxide<br />Introduced: 2010s<br />Will withstand M993, M995, or 7N39";

		count = 100;
		mass = 105;


		class SCT_ITEMINFO{
			plateinfo[] = {"Xin Xing MIL-V Plate", 0};
			enableparts[] = {0,0,24,23,24,0,0,0,0};
			blunttraumaPad[] = {0,0,0.98,0.98,0.98,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_ceramic_lvi_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) Jianhuren MIL-VI";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: People's Liberation Army SO<br />Rating: MIL-VI Ceramic, Aluminum Oxide<br />Introduced: 2010s<br />Will withstand heavy impacts";

		count = 100;
		mass = 180;


		class SCT_ITEMINFO{
			plateinfo[] = {"Jianhuren MIL-VI Plate", 0};
			enableparts[] = {0,0,32,32,32,0,0,0,0};
			blunttraumaPad[] = {0,0,1.98,1.98,1.98,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_ceramic_xsapimc_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) XSAPI MIL-V/MC GEN3";
		picture = "\SCT\addons\SonicT_vest\data\xsapi.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: United States Military<br />Rating: MIL-V Ceramic, Boron Carbide<br />Introduced: 2016<br />Will withstand M993, M995, or 7N39<br />Maximum Coverage";

		count = 100;
		mass = 155;


		class SCT_ITEMINFO{
			plateinfo[] = {"XSAPI-2016 ceramic ICW soft body armor", 0};
			enableparts[] = {6,10,10,25,25,25,6,0,0};
			blunttraumaPad[] = {1,1,1,1,1,1,1,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_ceramic_xsapi2009_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) XSAPI MIL-VA GEN1";
		picture = "\SCT\addons\SonicT_vest\data\xsapi.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: United States Military<br />Rating: MIL-VA Ceramic, Boron Carbide<br />Introduced: 2009<br />Will withstand M995";

		count = 100;
		mass = 105;


		class SCT_ITEMINFO{
			plateinfo[] = {"XSAPI-2009 MIL-VA ICW soft body armor", 0};
			enableparts[] = {0,0,16,16,16,0,0,0,0};
			blunttraumaPad[] = {0,0,1,1,1,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_ceramic_xsapi2011_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) XSAPI MIL-V GEN2";
		picture = "\SCT\addons\SonicT_vest\data\xsapi.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: United States Military<br />Rating: MIL-V Ceramic, Boron Carbide<br />Introduced: 2011<br />Special Theater Contingency Plate";

		count = 100;
		mass = 121;


		class SCT_ITEMINFO{
			plateinfo[] = {"XSAPI-2011 GEN2", 0};
			enableparts[] = {0,0,18,18,18,0,0,0,0};
			blunttraumaPad[] = {0,0,1,1,1,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_ceramic_sapi_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) SAPI MIL-III";
		picture = "\SCT\addons\SonicT_vest\data\sapi.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: United States Military<br />Rating: MIL-III Ceramic, Boron Carbide<br />Introduced: 1998<br />Multi-hit resistant";

		count = 100;
		mass = 96;


		class SCT_ITEMINFO{
			plateinfo[] = {"SAPI MIL-III ICW soft body armor", 0};
			enableparts[] = {0,0,12,12,12,0,0,0,0};
			blunttraumaPad[] = {0,0,1,1,1,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_ceramic_hesapi_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) H-ESAPI MIL-V";
		picture = "\SCT\addons\SonicT_vest\data\hesapi.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: US Air Force Pararescuemen<br />Rating: MIL-V Ceramic, Boron Carbide<br />Introduced: 2007<br />Rated to stop M993, M995, or 7N24";

		count = 100;
		mass = 158;


		class SCT_ITEMINFO{
			plateinfo[] = {"H-ESAPI MIL-V", 0};
			enableparts[] = {12,0,26,26,26,0,0,0,0};
			blunttraumaPad[] = {1,0,1.4,1.4,1.4,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_ceramic_hesapimc_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) H-ESAPI MIL-V/MC";
		picture = "\SCT\addons\SonicT_vest\data\hesapi.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: US Air Force Pararescuemen<br />Rating: MIL-V Ceramic, Boron Carbide, Maximum Coverage<br />Introduced: 2007<br />Rated to stop M993, M995, or 7N24";

		count = 100;
		mass = 198;

		class SCT_ITEMINFO{
			plateinfo[] = {"H-ESAPI MIL-V/MC", 0};
			enableparts[] = {12,12,26,26,26,12,12,0,0};
			blunttraumaPad[] = {1.2,1.4,1.4,1.4,1.4,1.2,1,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_ceramic_isapo_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) ISAPO MIL-III";
		picture = "\SCT\addons\SonicT_vest\data\rba.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: United States Military<br />Rating: MIL-III Ceramic, Aluminum Oxide<br />Introduced: 1996<br />Will withstand 7.62x51mm Ball";

		count = 100;
		mass = 128;

		class SCT_ITEMINFO{
			plateinfo[] = {"ISAPO MIL-III first-generation ceramic body armor", 0};
			enableparts[] = {0,0,12,12,12,0,0,0,0};
			blunttraumaPad[] = {0,0,1.5,1.5,1.5,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_ceramic_chicken_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) Chicken Plates MIL-III";
		picture = "\SCT\addons\SonicT_vest\data\doron.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: US Pilots<br />Rating: MIL-III, Early Aluminum Oxide<br />Introduced: 1965<br />Will withstand repeat 7.62x39mm";

		count = 100;
		mass = 300;


		class SCT_ITEMINFO{
			plateinfo[] = {"Chicken Plate Set - Non-Infantry MIL-III", 0};
			enableparts[] = {0,0,10,10,10,0,0,0,0};
			blunttraumaPad[] = {0,0,1.3,1.3,1.3,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_ceramic_aircrewman_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) SAP-AC MIL-III";
		picture = "\SCT\addons\SonicT_vest\data\doron.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: US Aircrewmen<br />Rating: MIL-III, Early Aluminum Oxide<br />Introduced: 1970s<br />Will withstand .30 Ball";

		count = 100;
		mass = 280;


		class SCT_ITEMINFO{
			plateinfo[] = {"Small Arms Protective - Aircrewman", 0};
			enableparts[] = {0,0,10,10,10,0,0,0,0};
			blunttraumaPad[] = {0,0,1.5,1.5,1.5,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_ceramic_m1951_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) M1951 Level II-";
		picture = "\SCT\addons\SonicT_vest\data\doron.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: US Army, Korean War<br />Rating: Level II-, Doron Laminate<br />Introduced: 1951<br />Will withstand .45 ACP";

		count = 100;
		mass = 95;

		class SCT_ITEMINFO{
			plateinfo[] = {"M1951 Doron Laminate Armor", 1.1};
			enableparts[] = {0,0,0,5,5,0,0,0,0};
			blunttraumaPad[] = {0,0,0,1,1,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_ceramic_m1955_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) M1955 Level II-";
		picture = "\SCT\addons\SonicT_vest\data\doron.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: US Army, Vietnam War<br />Rating: Level II-, Doron Laminate<br />Introduced: 1955<br />Will withstand .45 ACP";

		count = 100;
		mass = 105;

		class SCT_ITEMINFO{
			plateinfo[] = {"M1955 Doron Laminate Armor", 1.1};
			enableparts[] = {0,0,0,6,6,0,0,0,0};
			blunttraumaPad[] = {0,0,0,1,1,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_ceramic_m1945_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) M1945 Level II-";
		picture = "\SCT\addons\SonicT_vest\data\doron.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: US Army, Battle of Okinawa<br />Rating: Level II-, Doron Laminate<br />Introduced: 1945<br />Will withstand Flak";

		count = 100;
		mass = 80;

		class SCT_ITEMINFO{
			plateinfo[] = {"M1945 Doron Laminate Armor", 1.1};
			enableparts[] = {0,0,0,5,5,0,0,0,0};
			blunttraumaPad[] = {0,0,0,0.9,0.9,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_ceramic_t522_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) T-52-2 Level II";
		picture = "\SCT\addons\SonicT_vest\data\doron.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "Used By: US Army, Vietnam War<br />Rating: Level II-, Doron Laminate<br />Introduced: 1952<br />Will withstand .45 ACP";

		count = 100;
		mass = 98;


		class SCT_ITEMINFO{
			plateinfo[] = {"T-52-2 Doron Laminate Armor", 1.1};
			enableparts[] = {0,0,0,5,5,0,0,0,0};
			blunttraumaPad[] = {0,0,0,1.3,1.3,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_ceramic_dragonskin_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) DragonSkin Level III";
		picture = "\SCT\addons\SonicT_vest\data\dragonskin.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: PMCs and American Special Forces<br />Rating: NIJ Level III Ceramic, Special Design<br />Introduced: 1999<br />Highly resistant against multiple impacts";


		mass = 106;
		count = 100;

		class SCT_ITEMINFO{
			plateinfo[] = {"SOV-2000 Level III", 0};
			enableparts[] = {0,0,13,13,13,0,0,0,0};
			blunttraumaPad[] = {0,0,1.8,1.8,1.8,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_ceramic_dragonskinheavy_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) DragonSkin Level IV";
		picture = "\SCT\addons\SonicT_vest\data\dragonskin.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: PMCs and American Special Forces<br />Rating: NIJ Level IV Ceramic, Special Design<br />Introduced: 1999<br />Will withstand multiple IV-level threats";

		count = 100;
		mass = 114;


		class SCT_ITEMINFO{
			plateinfo[] = {"SOV-2000 Level IV", 0};
			enableparts[] = {0,0,15,15,15,0,0,0,0};
			blunttraumaPad[] = {0,0,1.7,1.7,1.7,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_ceramic_dragonskinassault_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) DragonSkin Level V";
		picture = "\SCT\addons\SonicT_vest\data\dragonskin.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: American Special Forces<br />Rating: MIL-V Ceramic, Special Design<br />Introduced: 1999<br />Will withstand M993 and M995";

		count = 100;
		mass = 130;


		class SCT_ITEMINFO{
			plateinfo[] = {"SOV-3000 Level V", 0};
			enableparts[] = {0,0,25,25,25,0,0,0,0};
			blunttraumaPad[] = {0,0,1.6,1.6,1.6,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_ceramic_dragonskinO_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) DragonSkin Level VI";
		picture = "\SCT\addons\SonicT_vest\data\dragonskin.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: American Special Forces<br />Rating: MIL-VI Ceramic, Special Design<br />Introduced: 1999<br />Will withstand .338 Lapua Magnum";

		count = 100;
		mass = 130;


		class SCT_ITEMINFO{
			plateinfo[] = {"SOV-5000 Level VI", 0};
			enableparts[] = {0,0,32,32,32,0,0,0,0};
			blunttraumaPad[] = {0,0,1.6,1.6,1.6,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_ceramic_RBA_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) Ranger Body Armor MIL-IV";
		picture = "\SCT\addons\SonicT_vest\data\rba.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: 75th Ranger Regiment<br />Rating: MIL-IV Ceramic, Aluminum Oxide<br />Introduced: 1993<br />Will withstand multiple 7.62x51mm FMJ rounds";

		count = 100;
		mass = 140;


		class SCT_ITEMINFO{
			plateinfo[] = {"Ranger Body Armor", 0};
			enableparts[] = {0,0,14,14,14,0,0,0,0};
			blunttraumaPad[] = {0,0,1.6,1.6,1.6,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_ceramic_RBAMC_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) Ranger Body Armor MIL-IV/MC";
		picture = "\SCT\addons\SonicT_vest\data\rba.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: 75th Ranger Regiment<br />Rating: MIL-IV Ceramic, Maximum Coverage, Aluminum Oxide<br />Introduced: 1993<br />Will withstand multiple 7.62x51mm FMJ rounds.<br />Maximum Coverage";

		count = 100;
		mass = 190;


		class SCT_ITEMINFO{
			plateinfo[] = {"Ranger Body Armor", 0};
			enableparts[] = {0,10,14,14,14,14,3,0,0};
			blunttraumaPad[] = {0,1.4,1.7,1.7,1.7,1.4,1.4,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_ceramic_INFI_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) Infidel Armor Level IV";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Preppers<br />Rating: MIL-IV Ceramic, Aluminum Oxide<br />Introduced: 2010s<br />Will withstand M61 7.62x51mm AP Ball";

		count = 100;
			mass = 152;


		class SCT_ITEMINFO{
			plateinfo[] = {"Infidel Armor Level IV", 0};
			enableparts[] = {0,0,15,15,15,0,0,0,0};
			blunttraumaPad[] = {0,0,1.8,1.8,1.8,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_ceramic_6b46_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) 6B46 GOST-6A";
		picture = "\SCT\addons\SonicT_vest\data\6b45.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Russian Armed Forces<br />Rating: GOST 6A Ceramic, Boron Carbide<br />Introduced: 2016<br />Multiple-hit resistant against 7.62x54mm FMJ";

		count = 100;
		mass = 108;


		class SCT_ITEMINFO{
			plateinfo[] = {"GOST-6A 6B46 Plate", 0};
			enableparts[] = {0,0,15,15,15,0,0,0,0};
			blunttraumaPad[] = {0,0,1.2,1.2,1.2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_ceramic_6b45_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) 6B45 GOST-6";
		picture = "\SCT\addons\SonicT_vest\data\6b45.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Russian Armed Forces<br />Rating: GOST 6 Ceramic, Boron Carbide<br />Introduced: 2015<br />Multiple-hit resistant against 7.62x54mm FMJ";

		count = 100;
		mass = 104;


		class SCT_ITEMINFO{
			plateinfo[] = {"GOST-6 6B45 Plate", 0};
			enableparts[] = {0,0,14,14,14,0,0,0,0};
			blunttraumaPad[] = {0,0,1,1,1,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_ceramic_rus5_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) MIL-V 6B58";
		picture = "\SCT\addons\SonicT_vest\data\6b58.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Spetsnaz<br />Rating: MIL-V Ceramic, Boron Carbide<br />Introduced: 2016<br />Highly resistant to all standard small arm cartridges";

		count = 100;
		mass = 130;


		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-V 6B58 Plate", 0};
			enableparts[] = {0,0,19,19,19,0,0,0,0};
			blunttraumaPad[] = {0,0,1.3,1.2,1.3,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_ceramic_rusgun_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) MIL-VS OVR-3Sh";
		picture = "\SCT\addons\SonicT_vest\data\OVR-3SH.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Alfa Group, Spetsnaz<br />Rating: MIL-VS Sapper-grade, Aluminum Oxide<br />Introduced: 2017<br />Capable against repeat AP 7.62x54mm";

		count = 100;
		mass = 225;


		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-VS OVR-3Sh Plate", 0};
			enableparts[] = {0,15,24,24,24,15,0,0,0};
			blunttraumaPad[] = {0,0.6,2,2,2,0.6,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_ceramic_gookgun_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) MIL-VS Tianshi";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: PLA Honor Guard<br />Rating: MIL-VS, Aluminum Oxide<br />Introduced: 2017<br />Capable against repeat AP 7.62x54mm";

		count = 100;
		mass = 204;


		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-VS Tianshi Plate", 0};
			enableparts[] = {0,15,20,20,20,15,0,0,0};
			blunttraumaPad[] = {0,0.9,1.8,1.8,1.8,0.9,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_ceramic_ratnik2L_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) MIL-V RATNIK-2 Legioner";
		picture = "\SCT\addons\SonicT_vest\data\6b58.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Alfa Group, Spetsnaz<br />Rating: MIL-V, RATNIK-2<br />Introduced: 2016<br />Capable against 7.62x54mm repeat impacts";

		count = 100;
		mass = 120;


		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-V RATNIK-2 Legioner", 0};
			enableparts[] = {0,10,21,21,21,10,0,0,0};
			blunttraumaPad[] = {0,0,2.1,2.1,2.1,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_ceramic_ratnik2C_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) MIL-VI+ RATNIK-2 Centurion";
		picture = "\SCT\addons\SonicT_vest\data\6b58.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Alfa Group, Spetsnaz<br />Rating: MIL-VI+, Perfected Boron Carbide<br />Introduced: 2017<br />Rated against repeat .338 Lapua Magnum";

		count = 100;
		mass = 210;


		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-VI+ RATNIK-2 Centurion", 0};
			enableparts[] = {0,10,37,37,37,37,0,0,0};
			blunttraumaPad[] = {0,1,3.5,3.5,3.5,1,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_ceramic_ratnik2S_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) MIL-IV RATNIK-2 Sherp";
		picture = "\SCT\addons\SonicT_vest\data\6b58.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: OMON, Alfa Group<br />Rating: MIL-VA Ceramic, Boron Carbide<br />Introduced: 2017<br />Resistant against common small-arms AP cartridges";

		count = 100;
		mass = 90;


		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-IV RATNIK-2 Sherp", 0};
			enableparts[] = {0,0,13,13,13,5,0,0,0};
			blunttraumaPad[] = {0,0,1.2,1.2,1.1,1,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_ceramic_ratnik2G_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) MIL-VI RATNIK-2 Gladiator";
		picture = "\SCT\addons\SonicT_vest\data\6b58.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Assault Spetsnaz<br />Rating: MIL-VI Ceramic, Boron Carbide<br />Introduced: 2017<br />Rated against .338 Lapua Magnum";

		count = 100;
		mass = 190;

		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-VI RATNIK-2 Gladiator", 0};
			enableparts[] = {0,13,33,33,22,13,0,0,0};
			blunttraumaPad[] = {0,1.5,2,2,2,1.5,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_ceramic_4sas7_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) Highcom 4SAS-7 IV";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Civilians<br />Rating: NIJ Level IV Ceramic<br />Introduced: 2000s<br />Rated against 30-06 M2AP";

		count = 100;
		mass = 190;


		class SCT_ITEMINFO{
			plateinfo[] = {"4SAS-7 Level IV", 0};
			enableparts[] = {0,0,14,14,15,0,0,0,0};
			blunttraumaPad[] = {0,0,1,1,1,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_ceramic_leison4_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) Leison IV";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Civilians<br />Rating: NIJ Level IV Ceramic<br />Introduced: 2000s<br />Rated against 30-06 M2AP";

		count = 100;
		mass = 170;


		class SCT_ITEMINFO{
			plateinfo[] = {"Wenzhou Leizon Level III/IV Plate", 0};
			enableparts[] = {0,0,12,12,12,0,0,0,0};
			blunttraumaPad[] = {0,0,0.9,1,0.7,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_ceramic_b4c_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) Multi-Curve B4C IV";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: SWAT Tactical Units<br />Rating: NIJ Level IV Ceramic<br />Introduced: 2000s<br />Rated against 30-06 M2AP";

		count = 100;
		mass = 140;


		class SCT_ITEMINFO{
			plateinfo[] = {"Multi-Curve B4C IV", 0};
			enableparts[] = {0,0,15,15,15,13,0,0,0};
			blunttraumaPad[] = {0,0,1.3,1.5,1.3,1,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_ceramic_rus6_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) MIL-VI 6B72";
		picture = "\SCT\addons\SonicT_vest\data\6b72.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Assault Spetsnaz<br />Rating: MIL-VI Ceramic<br />Introduced: 2017<br />Rated to stop .338 Lapua Magnum";

		count = 100;
		mass = 164;


		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-VI 6B72 Plate", 0};
			enableparts[] = {0,0,34,34,34,0,0,0,0};
			blunttraumaPad[] = {0,0,1.2,1.3,1.2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_ceramic_rus7_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) MIL-VII 6B83";
		picture = "\SCT\addons\SonicT_vest\data\6B83.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Heavy Assault Spetsnaz<br />Rating: MIL-VII Ceramic<br />Introduced: 2017<br />Rated to stop .460 Weatherby Magnum impacts or a large number of small-caliber rounds.";

		count = 100;
		mass = 190;


		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-VII 6B83", 0};
			enableparts[] = {0,0,45,45,45,0,0,0,0};
			blunttraumaPad[] = {0,0,3.2,3,3.2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_ceramic_rus7t_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) MIL-VII+ 6B87";
		picture = "\SCT\addons\SonicT_vest\data\6B83.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Heavy Assault Spetsnaz<br />Rating: MIL-VII+ Ceramic<br />Introduced: 2017<br />Rated to stop repeat .338 API526 impacts.";

		count = 100;
		mass = 230;


		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-VII 6B83", 0};
			enableparts[] = {0,0,55,55,55,0,0,0,0};
			blunttraumaPad[] = {0,0,3.2,3,3.2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_ceramic_rus8_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) MIL-VIIIA 6B92";
		picture = "\SCT\addons\SonicT_vest\data\6B92.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Ultra-Heavy Assault Spetsnaz<br />Rating: MIL-VIIIA Ceramic<br />Introduced: 2017<br />Rated to stop 12.7x99 or 12.7x108mm FMJ";

		count = 100;
		mass = 250;


		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-VIIIA 6B92", 0};
			enableparts[] = {0,0,145,145,145,0,0,0,0};
			blunttraumaPad[] = {0,0,4.2,4,4.2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_ceramic_rus11_magtype: SonicT_Item_Base_magtype {
		scope = 1;
		displayName = "(Plate) MIL-XI 6B100";
		picture = "\SCT\addons\SonicT_vest\data\6B92.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Vladimir Putin<br />Rating: MIL-XI Depleted Uranium<br />Introduced: 2017<br />Rated to stop 25x59mm APFSDS";

		count = 100;
		mass = 250;


		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-XI 6B100", 0};
			enableparts[] = {0,0,550,550,550,0,0,0,0};
			blunttraumaPad[] = {0,0,24,24,24,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_ceramic_rus82_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) MIL-VIII 6B96";
		picture = "\SCT\addons\SonicT_vest\data\6B92.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Ultra-Heavy Assault Spetsnaz<br />Rating: MIL-VIII Ceramic<br />Introduced: 2017<br />Rated to stop 12.7x99 or 12.7x108mm FMJ";

		count = 100;
		mass = 290;


		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-VIII 6B96", 0};
			enableparts[] = {0,0,167,166,167,0,0,0,0};
			blunttraumaPad[] = {0,0,7.8,7.8,7.8,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_steel_ar5001_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) AR500 Level III+";
		picture = "\SCT\addons\SonicT_vest\data\ar500.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Contractors, Civilians, PMCs<br />Rating: NIJ Level III+<br />Introduced: 2000s<br />Will withstand repeat 5.56x45mm M193 impacts";

		count = 100;
		mass = 158;


		class SCT_ITEMINFO{
			plateinfo[] = {"AR500 Level III+ ", 2};
			enableparts[] = {0,0,11,11,11,0,0,0,0};
			blunttraumaPad[] = {0,0,1.6,1.6,1.6,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_steel_ar500C_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) AR500 Level III";
		picture = "\SCT\addons\SonicT_vest\data\ar500.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Contractors, Civilians, PMCs<br />Rating: NIJ Level III<br />Introduced: 2000s<br />Will withstand repeat 7.62x51mm FMJ impacts";

		count = 100;
		mass = 164;


		class SCT_ITEMINFO{
			plateinfo[] = {"AR500 Level III", 2};
			enableparts[] = {0,0,12,12,12,0,0,0,0};
			blunttraumaPad[] = {0,0,1.5,1.5,1.5,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_steel_ar500CS_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) AR500 Level III/S";
		picture = "\SCT\addons\SonicT_vest\data\ar500.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Contractors, Civilians, PMCs<br />Rating: NIJ Level III, Small-sized<br />Introduced: 2000s<br />Will withstand repeat 7.62x51mm FMJ impacts";

		count = 100;
		mass = 140;


		class SCT_ITEMINFO{
			plateinfo[] = {"AR500 Level III, 8x10", 2};
			enableparts[] = {0,0,0,12,12,0,0,0,0};
			blunttraumaPad[] = {0,0,0,1.5,1.5,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_steel_ar500CT_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) AR500 Level III/MC";
		picture = "\SCT\addons\SonicT_vest\data\ar500.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Contractors, Civilians, PMCs<br />Rating: NIJ Level III, Maximum Coverage<br />Introduced: 2000s<br />Will withstand repeat 7.62x51mm FMJ impacts";

		count = 100;
		mass = 231;


		class SCT_ITEMINFO{
			plateinfo[] = {"AR500 Level III/MC", 2};
			enableparts[] = {0,12,12,12,12,12,12,0,0};
			blunttraumaPad[] = {0,1,1.5,1.5,1.5,1,1,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_steel_ar5004_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) AR500 Level IV";
		picture = "\SCT\addons\SonicT_vest\data\ar500.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Contractors, Civilians, PMCs<br />Rating: NIJ Level IV, Steel<br />Introduced: 2000s<br />Will withstand repeat 30-06 M2AP impacts";

		count = 100;
		mass = 195;


		class SCT_ITEMINFO{
			plateinfo[] = {"AR500 Level IV", 2};
			enableparts[] = {0,0,15,15,15,0,0,0,0};
			blunttraumaPad[] = {0,0,1.5,1.5,1.5,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_steel_ar5004CAA_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) AR500-Ceramic Level IV";
		picture = "\SCT\addons\SonicT_vest\data\ar500.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Contractors, Civilians, PMCs<br />Rating: NIJ Level IV, Ceramic<br />Introduced: 2000s<br />Will withstand .22-250 Remington";

		count = 100;
		mass = 150;


		class SCT_ITEMINFO{
			plateinfo[] = {"AR500 Level IV, Ceramic", 2};
			enableparts[] = {0,0,15,15,15,0,0,0,0};
			blunttraumaPad[] = {0,0,1,1,1,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_steel_ar5004MC_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) AR500 Level IV/MC";
		picture = "\SCT\addons\SonicT_vest\data\ar500.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Contractors, Civilians, PMCs<br />Rating: NIJ Level IV, Maximum Coverage<br />Introduced: 2000s<br />Will withstand repeat 30-06 M2AP impacts";

		count = 100;
		mass = 270;


		class SCT_ITEMINFO{
			plateinfo[] = {"AR500 Level IV/MC", 2};
			enableparts[] = {0,13,15,15,15,13,13,0,0};
			blunttraumaPad[] = {0,1.2,1.5,1.5,1.5,0,1.2,1.2,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_steel_ar5005_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) AR500 Level V";
		picture = "\SCT\addons\SonicT_vest\data\ar500.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Well-funded PMCs, well-connected survivalists<br />Rating: NIJ Level IV, MIL-V<br />Introduced: 2010s<br />Rated for .338 Lapua Magnum";

		count = 100;
		mass = 230;


		class SCT_ITEMINFO{
			plateinfo[] = {"AR500 Level V", 2};
			enableparts[] = {0,0,25,25,25,0,0,0,0};
			blunttraumaPad[] = {0,0,3.5,3.5,3.5,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_steel_ar5006_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) AR500 Level VI";
		picture = "\SCT\addons\SonicT_vest\data\ar500.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Expert Survivalists, Gray Men<br />Rating: MIL-VI<br />Introduced: 2010s<br />Rated for 7N39, 7N37, XM1154, or .338 Lapua Magnum";


		mass = 270;
		count = 100;

		class SCT_ITEMINFO{
			plateinfo[] = {"AR500 Level VI", 2};
			enableparts[] = {0,0,33,33,33,0,0,0,0};
			blunttraumaPad[] = {0,0,3.5,3.5,3.5,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_steel_ar5005mc_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) AR500 Level V/MC";
		picture = "\SCT\addons\SonicT_vest\data\ar500.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Well-funded PMCs, well-connected survivalists<br />Rating: NIJ Level IV, MIL-V, Maximum Coverage<br />Introduced: 2010s<br />Rated for .338 Lapua Magnum";

		count = 100;
		mass = 330;


		class SCT_ITEMINFO{
			plateinfo[] = {"AR500 Level V, Maximum Coverage", 2};
			enableparts[] = {0,17,25,25,25,17,17,0,0};
			blunttraumaPad[] = {0,3.1,3.7,3.7,3.7,3.1,3.1,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_steel_TAC_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) TAC Steel Level IV+";
		picture = "\SCT\addons\SonicT_vest\data\ar500.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Survivalists, PMCs<br />Rating: NIJ Level IV<br />Introduced: 2010s<br />Will withstand, on paper, a .338 Lapua Magnum";


		mass = 174;


		class SCT_ITEMINFO{
			plateinfo[] = {"TAC Steel Level IV+", 2};
			enableparts[] = {0,0,17.5,17.5,17.5,0,0,0,0};
			blunttraumaPad[] = {0,0,2.6,2.6,2.6,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_steel_arbudget_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) AR500 Level IIIA";
		picture = "\SCT\addons\SonicT_vest\data\ar500.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Contractors, Civilians, PMCs<br />Rating: NIJ Level IIIA<br />Introduced: 2000s<br />Will withstand repeat .44 Magnum impacts";


		mass = 110;


		class SCT_ITEMINFO{
			plateinfo[] = {"AR500 Level IIIA ", 2};
			enableparts[] = {0,0,8,8,8,0,0,0,0};
			blunttraumaPad[] = {0,0,1.8,1.8,1.8,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_kevlar_3_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) Kevlar Level IIIA";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Contractors, Civilians, PMCs<br />Rating: NIJ Level IIIA<br />Introduced: 1980s<br />Will withstand revolver impacts";


		mass = 40;


		class SCT_ITEMINFO{
			plateinfo[] = {"Kevlar Level IIIA", 4};
			enableparts[] = {0,0,8,8,8,0,0,0,0};
			blunttraumaPad[] = {0,0,1,1,1,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_kevlar_2_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) Kevlar Level II";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Contractors, Civilians, PMCs<br />Rating: NIJ Level II<br />Introduced: 1980s<br />Will withstand at least one 9x19mm Parabellum FMJ impact";


		mass = 25;


		class SCT_ITEMINFO{
			plateinfo[] = {"Kevlar Level II", 4};
			enableparts[] = {0,0,6,6,6,0,0,0,0};
			blunttraumaPad[] = {0,0,1,1,1,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_kevlar_1_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) Kevlar Level I";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Contractors, Civilians, PMCs<br />Rating: NIJ Level I<br />Introduced: 1980s<br />Will withstand very light shrapnel";


		mass = 15;


		class SCT_ITEMINFO{
			plateinfo[] = {"Kevlar Level I", 4};
			enableparts[] = {0,0,2,3,2,0,0,0,0};
			blunttraumaPad[] = {0,0,1,1,1,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_nylon_1_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) B-Nylon Level I";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: United States Military<br />Rating: NIJ Level I<br />Introduced: 1960s<br />Don't try getting shot.";


		mass = 23;


		class SCT_ITEMINFO{
			plateinfo[] = {"Ballistic Nylon Level I", 4};
			enableparts[] = {0,0,2,2,2,0,0,0,0};
			blunttraumaPad[] = {0,0,0.7,0.7,0.7,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_nylon_2_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) B-Nylon Level II";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: United States Military<br />Rating: NIJ Level II<br />Introduced: 1960s<br />Designed to stop fragmentation.";


		mass = 26;


		class SCT_ITEMINFO{
			plateinfo[] = {"Ballistic Nylon Level II", 4};
			enableparts[] = {0,0,5,5,5,0,0,0,0};
			blunttraumaPad[] = {0,0,0.7,0.7,0.7,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_steel_ar680_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) AR680 Level III+";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Contractors, Civilians, PMCs<br />Rating: NIJ Level III+<br />Introduced: 2010s<br />Will withstand repeat 7.62x51mm Ball";


		mass = 124;


		class SCT_ITEMINFO{
			plateinfo[] = {"AR680 Level III+", 2.1};
			enableparts[] = {0,0,11,11,11,0,0,0,0};
			blunttraumaPad[] = {0,0,2,2,2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_steel_ar680b_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) AR680 Level IV";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Contractors, Civilians, PMCs<br />Rating: NIJ Level IV<br />Introduced: 2010s<br />Will withstand repeat 7.62x51mm Ball";


		mass = 144;


		class SCT_ITEMINFO{
			plateinfo[] = {"AR680 Level IV", 2.1};
			enableparts[] = {0,0,14,15,14,0,0,0,0};
			blunttraumaPad[] = {0,0,2,2,2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_steel_U_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) Zeta-6H Level IV";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: SWAT, Riot Control<br />Rating: NIJ Level IV<br />Introduced: 2010s<br />Rated for many 7.62x51mm rounds";


		mass = 150;


		class SCT_ITEMINFO{
			plateinfo[] = {"United Shield Zeta-6H Level IV", 0};
			enableparts[] = {0,0,14,14,14,6,0,0,0};
			blunttraumaPad[] = {0,0,1.8,1.8,1.8,1,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_titanium_MILIV_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) DARPA TI-CER MIL-IV";
		picture = "\SCT\addons\SonicT_vest\data\titanoceramic.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: DARPA<br />Rating: MIL-IV, Titanium Diboride<br />Introduced: Late 2000s<br />Will withstand repeat 30-06 M2AP";


		mass = 96;


		class SCT_ITEMINFO{
			plateinfo[] = {"DARPA MIL-IV", 0.1};
			enableparts[] = {0,0,14,14,14,0,0,0,0};
			blunttraumaPad[] = {0,0,2.8,2.8,2.8,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_titanium_MILIVS_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) DARPA TI-CER MIL-IV/MC";
		picture = "\SCT\addons\SonicT_vest\data\titanoceramric.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: DARPA<br />Rating: MIL-IV, Titanium Diboride<br />Introduced: Late 2000s<br />Built for heavy riot control";


		mass = 130;


		class SCT_ITEMINFO{
			plateinfo[] = {"DARPA MIL-IV/MC", 0.1};
			enableparts[] = {0,12,14,14,14,14,0,0,0};
			blunttraumaPad[] = {0,3.2,3.4,3.4,3.4,3.4,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_titanium_MILVA_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) DARPA TI-CER MIL-VA";
		picture = "\SCT\addons\SonicT_vest\data\titanoceramic.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: DARPA<br />Rating: MIL-VA, Titanium Diboride<br />Introduced: Late 2000s<br />Will withstand M993 or M995";


		mass = 110;


		class SCT_ITEMINFO{
			plateinfo[] = {"DARPA MIL-VA", 0.1};
			enableparts[] = {0,0,18,18,18,0,0,0,0};
			blunttraumaPad[] = {0,0,2.8,2.8,2.8,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_titanium_MILV_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) DARPA TI-CER MIL-V";
		picture = "\SCT\addons\SonicT_vest\data\titanoceramic.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: DARPA<br />Rating: MIL-V, Titanium Diboride<br />Introduced: Late 2000s<br />Will withstand repeat 9.3x64mm Brenneke";


		mass = 130;


		class SCT_ITEMINFO{
			plateinfo[] = {"DARPA MIL-V", 0.2};
			enableparts[] = {0,0,25,25,25,0,0,0,0};
			blunttraumaPad[] = {0,0,2.8,2.8,2.8,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_titanium_MILVS_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) DARPA RIOT-TI MIL-VS";
		picture = "\SCT\addons\SonicT_vest\data\titanoceramric.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: DARPA<br />Rating: MIL-VS, Titanium Diboride<br />Introduced: Late 2000s<br />Urban Warfare/Riot Control";


		mass = 182;


		class SCT_ITEMINFO{
			plateinfo[] = {"DARPA MIL-VS Riot", 0.2};
			enableparts[] = {0,0,26,26,26,0,0,0,0};
			blunttraumaPad[] = {0,0,3.8,3.8,3.8,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_titanium_MILVI_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) DARPA TI-CER MIL-VI";
		picture = "\SCT\addons\SonicT_vest\data\titanoceramic.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: DARPA<br />Rating: MIL-VI, Titanium Diboride<br />Introduced: Late 2000s<br />Withstands .338 API526";


		mass = 156;


		class SCT_ITEMINFO{
			plateinfo[] = {"DARPA MIL-VI", 0};
			enableparts[] = {0,0,35,35,35,0,0,0,0};
			blunttraumaPad[] = {0,0,2.8,2.8,2.8,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_titanium_MILVII_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) DARPA TI-CER MIL-VII";
		picture = "\SCT\addons\SonicT_vest\data\titanoceramic.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: DARPA<br />Rating: MIL-VII, Titanium Diboride<br />Introduced: Late 2000s<br />Withstands .408 at-range";


		mass = 184;


		class SCT_ITEMINFO{
			plateinfo[] = {"DARPA MIL-VII", 0.2};
			enableparts[] = {0,0,59,59,59,0,0,0,0};
			blunttraumaPad[] = {0,0,2.8,2.8,2.8,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_titanium_MILVIII_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) DARPA TI-CER MIL-VIII";
		picture = "\SCT\addons\SonicT_vest\data\titanoceramic.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: DARPA<br />Rating: MIL-VIII, Titanium Diboride<br />Introduced: Late 2000s<br />.50 BMG Protective";


		mass = 230;
		class SCT_ITEMINFO{
			plateinfo[] = {"DARPA MIL-VIII", 0.2};
			enableparts[] = {0,0,189,189,189,0,0,0,0};
			blunttraumaPad[] = {0,0,3.8,3.8,3.8,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_titanium_MILIX_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) DARPA TI-CER MIL-IX";
		picture = "\SCT\addons\SonicT_vest\data\titanoceramic.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: DARPA, RoboCop<br />Rating: MIL-IX, Titanium Diboride<br />Introduced: Late 2000s<br />.50 BMG APDS Protective";


		mass = 280;

		class SCT_ITEMINFO{
			plateinfo[] = {"DARPA MIL-IX", 0};
			enableparts[] = {0,0,209,209,209,0,0,0,0};
			blunttraumaPad[] = {0,0,9.8,9.8,9.8,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_titanium_MILX_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) DARPA TI-CER MIL-X";
		picture = "\SCT\addons\SonicT_vest\data\titanoceramic.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: DARPA, The Terminator<br />Rating: MIL-X, Titanium Diboride<br />Introduced: Late 2000s<br />20x110mm Protective";


		mass = 320;

		class SCT_ITEMINFO{
			plateinfo[] = {"DARPA MIL-X", 0};
			enableparts[] = {0,0,269,269,269,0,0,0,0};
			blunttraumaPad[] = {0,0,10,10,10,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_ceramic_ffs4_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) FFS4 Level IV+";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Contractors, Civilians, PMCs<br />Rating: NIJ Level IV+<br />Introduced: 2000s<br />Will withstand M61 7.62x51mm AP Ball";


		mass = 152;

		class SCT_ITEMINFO{
			plateinfo[] = {"FFS4 IV+", 0};
			enableparts[] = {0,0,15,15,15,0,0,0,0};
			blunttraumaPad[] = {0,0,1,1,1,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_ceramic_SAmix_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) BBA SA Mix";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Armed Forces of South Africa<br />Rating: Unrated<br />Introduced: 2000s<br />Will withstand repeat M193 5.56x45mm Ball";


		mass = 86;

		class SCT_ITEMINFO{
			plateinfo[] = {"SA Mix Plate", 0};
			enableparts[] = {0,0,10,10,10,0,0,0,0};
			blunttraumaPad[] = {0,0,1,1,1,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_ceramic_SAIII_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) BBA Level III";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Armed Forces of South Africa<br />Rating: NIJ Level III<br />Introduced: 2000s<br />Will withstand repeat 7.62x51mm Ball";


		mass = 112;

		class SCT_ITEMINFO{
			plateinfo[] = {"BBA III", 0};
			enableparts[] = {0,0,11,11,11,0,0,0,0};
			blunttraumaPad[] = {0,0,1.3,1.3,1.3,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_ceramic_SAIV_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) BBA IV";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Armed Forces of South Africa<br />Rating: NIJ Level IV<br />Introduced: 2000s<br />Will withstand 30-06 M2AP";


		mass = 144;

		class SCT_ITEMINFO{
			plateinfo[] = {"BBA IV", 0};
			enableparts[] = {0,0,14,14,14,0,0,0,0};
			blunttraumaPad[] = {0,0,1.3,1.3,1.3,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_ceramic_bushtracker_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) BBA Bushtracker";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Armed Forces of South Africa<br />Rating: Unrated<br />Introduced: 2000s<br />Will withstand Elephant Rifle cartridges";


		mass = 170;

		class SCT_ITEMINFO{
			plateinfo[] = {"BBA Bushtracker", 0};
			enableparts[] = {0,0,0,22,22,0,0,0,0};
			blunttraumaPad[] = {0,0,0,4,4,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_titanium_6b3tm_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) 6B3TM GOST 4";
		picture = "\SCT\addons\SonicT_vest\data\6b3tm.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Former Warsaw Pact Nations<br />Rating: GOST Class 4, Titanium<br />Introduced: 1984<br />Will withstand 7.62x39mm Steel-core rounds";


		mass = 110;

		class SCT_ITEMINFO{
			plateinfo[] = {"6B3TM GOST 4", 2};
			enableparts[] = {0,0,11,11,11,0,0,0,0};
			blunttraumaPad[] = {0,0,1,1,1,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	//update Oct 8
	class SCT_plate_titanium_6b3tm01_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) 6B3TM01 GOST 5";
		picture = "\SCT\addons\SonicT_vest\data\6b3tm.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Former Warsaw Pact Nations<br />Rating: GOST Class 5, Titanium<br />Introduced: 1984<br />Will withstand 7.62x39mm Steel-core rounds";


		mass = 111;

		class SCT_ITEMINFO{
			plateinfo[] = {"6B3TM01 GOST 5", 1};
			enableparts[] = {0,0,14,12,14,0,0};
			blunttraumaPad[] = {0,0,1.25,1.25,1.25,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_ceramic_ceradyne_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) Ceradyne MIL-VIII";
		picture = "\SCT\addons\SonicT_vest\data\ceradyne2.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: United States Military<br />Rating: MIL-VIII<br />Introduced: 1994<br />.50 BMG Protective";


		mass = 280;

		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-VIII Ceradyne .50 BMG Protective", 0};
			enableparts[] = {0,0,190,190,190,0,0,0,0};
			blunttraumaPad[] = {0,0,9,9,9,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_poly_DFNDR_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) DFNDR Level III+";
		picture = "\SCT\addons\SonicT_vest\data\SCT_poly_dfndr_3p.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_poly_dfndr_3p.p3d"
		descriptionShort = "Used By: Civilians, Law Enforcement<br />Rating: NIJ Level III+<br />Introduced: 2000s<br />Rated for 7.62x51mm Ball impacts";


		mass = 80;

		class SCT_ITEMINFO{
			plateinfo[] = {"DEFENDER Lightweight Level III+", 1};
			enableparts[] = {0,0,11,11,11,0,0,0,0};
			blunttraumaPad[] = {0,0,0.9,0.9,0.9,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_poly_speedplate_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) SPEED-Plate Level IIIA";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_poly_dfndr_3p.p3d"
		descriptionShort = "Used By: Civilians, Mall Ninjas<br />Rating: NIJ Level IIIA<br />Introduced: 2010s<br />Rated for 12-gauge Slugs";


		mass = 40;

		class SCT_ITEMINFO{
			plateinfo[] = {"SPEED-Plate Level IIIA", 1};
			enableparts[] = {0,0,9,10,9,0,0,0,0};
			blunttraumaPad[] = {0,0,0.9,0.9,0.9,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class BER_Boost_Special_Doubler_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Special) Euro Extreme Mode";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Switches AAPM into one-shot-kill mode<br />deducts fifty armor";


		mass = 1;

		class SCT_ITEMINFO{
			plateinfo[] = {"Euro Extreme Mode", 0};
			enableparts[] = {-50,-50,-50,-50,-50,-50,-50,-50,-50};
			blunttraumaPad[] = {1,1,1,1,1,1,1,1,1};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class BER_Boost_Special_Infiltration_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Special) Old School Mode";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Makes you feel like you're in the late 1990s again.<br />deducts twenty-five armor<br />Modeled after UT99 Infiltration.";


			mass = 1;


		class SCT_ITEMINFO{
			plateinfo[] = {"Old School Mode", 0};
			enableparts[] = {-25,-25,-25,-25,-25,-25,-25,-25,-25};
			blunttraumaPad[] = {1,1,1,1,1,1,1,1,1};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class BER_Boost_Special_Tutorial_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Special) Easy Mode";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Massively improves your survivability.<br />Adds fifteen armor<br />Modeled after modern-era shooters.";


			mass = 1;


		class SCT_ITEMINFO{
			plateinfo[] = {"Easy Mode", 0};
			enableparts[] = {15,15,15,15,15,15,15,15,15};
			blunttraumaPad[] = {1,1,1,1,1,1,1,1,1};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_poly_speedplate3_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) SPEED-Plate Level III";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_poly_dfndr_3p.p3d"
		descriptionShort = "Used By: First Responders, Law Enforcement<br />Rating: NIJ Level III<br />Introduced: 2010s<br />Rated for 5.56x45mm M193";


			mass = 44;


		class SCT_ITEMINFO{
			plateinfo[] = {"SPEED-Plate Level III", 1};
			enableparts[] = {0,0,11,11,11,0,0,0,0};
			blunttraumaPad[] = {0,0,0.5,0.4,0.4,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_poly_speedplate4_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) Paraclete #20015 Level IV";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_poly_dfndr_3p.p3d"
		descriptionShort = "Used By: Civilians, Law Enforcement<br />Rating: NIJ Level IV<br />Introduced: 2010s<br />Rated for 30-06 M2AP";


			mass = 170;


		class SCT_ITEMINFO{
			plateinfo[] = {"Paraclete Level IV", 0};
			enableparts[] = {0,0,14,14,14,0,0,0,0};
			blunttraumaPad[] = {0,0,1.2,1.2,1.2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_poly_speedplate4plus_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) Paraclete LV7200 Level IV+";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_poly_dfndr_3p.p3d"
		descriptionShort = "Used By: Civilians, Law Enforcement<br />Rating: Level IV+<br />Introduced: 2010s<br />Rated for .300 WM";


			mass = 180;


		class SCT_ITEMINFO{
			plateinfo[] = {"Paraclete Level IV+", 0};
			enableparts[] = {0,0,16,16,16,0,0,0,0};
			blunttraumaPad[] = {0,0,1.34,1.34,1.35,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_poly_JD_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) JD Level IV";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Civilians<br />Rating: NIJ Level IV<br />Introduced: 2010s<br />Rated for 30-06 M2AP";


			mass = 78;


		class SCT_ITEMINFO{
			plateinfo[] = {"JD Level IV Polyethylene", 1};
			enableparts[] = {0,0,14,14,14,0,0,0,0};
			blunttraumaPad[] = {0,0,0.9,0.9,0.9,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_poly_PSAPI_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) SPEAR MIL-III";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Civilians<br />Rating: NIJ Level III, Polyethylene<br />Introduced: 2010s<br />Rated for .308";


			mass = 84;


		class SCT_ITEMINFO{
			plateinfo[] = {"SPEAR MIL-III Polyethylene", 1};
			enableparts[] = {0,0,10,10,10,0,0,0,0};
			blunttraumaPad[] = {0,0,0.9,0.9,0.9,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_poly_m1199_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) RMA M1199 NIJ-IV";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Civilians<br />Rating: NIJ Level IV, Special Ceramic<br />Introduced: 2010s<br />Rated for many 30-06 M2AP";


			mass = 140;


		class SCT_ITEMINFO{
			plateinfo[] = {"RMA Level IV Ceramic panel", 0};
			enableparts[] = {0,0,16,16,16,0,0,0,0};
			blunttraumaPad[] = {0,0,1.4,1,1,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_poly_m1155_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) RMA M1155 NIJ-IV*";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Civilians<br />Rating: NIJ Level IV, MIL-VA<br />Introduced: 2010s<br />Rated for five 30-06 M2APs or one .338 Lapua Magnum";


			mass = 180;


		class SCT_ITEMINFO{
			plateinfo[] = {"RMA Level IV Ceramic panel", 0};
			enableparts[] = {0,0,18.5,18.5,18.5,0,0,0,0};
			blunttraumaPad[] = {0,0,1.4,1.5,1.4,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_plate_poly_angel_308S_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate) 308S Level III-S";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Civilians, Contractors<br />Rating: NIJ Level III<br />Introduced: 2010s<br />Rated for .308<br />Small 5x8 model";


			mass = 65;


		class SCT_ITEMINFO{
			plateinfo[] = {"308S Polyethylene panel", 1};
			enableparts[] = {0,0,0,11,11,0,0,0,0};
			blunttraumaPad[] = {0,0,0,1,1,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_uniform_underwear_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(UniformArmor) Ballistic Underwear";
		picture = "\SCT\addons\SonicT_vest\data\underwear.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Level II Underwear";


			mass = 24;


		class SCT_ITEMINFO{
			plateinfo[] = {"Level II Underwear", 0};
			enableparts[] = {0,0,0,0,0,4,0,0,0};
			blunttraumaPad[] = {0,0,0,0,0,1,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_uniform_underwear3_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(UniformArmor) Ballistic Underwear UP";
		picture = "\SCT\addons\SonicT_vest\data\underwear.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Level IIIA Underwear";


			mass = 32;


		class SCT_ITEMINFO{
			plateinfo[] = {"Level IIIA Underwear", 0};
			enableparts[] = {0,0,0,0,0,9,0,0,0};
			blunttraumaPad[] = {0,0,0,0,0,1,0,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_uniform_kevlarinsert1_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(UniformInsert) Level II Kevlar Insert";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Level II Kevlar Insert";


			mass = 50;


		class SCT_ITEMINFO{
			plateinfo[] = {"Level II Kevlar Insert", 1};
			enableparts[] = {3,3,0,0,0,3,3,0,0};
			blunttraumaPad[] = {1,1,0,0,0,1,1,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_uniform_kevlarinsert3_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(UniformInsert) Level IIIA Kevlar Insert";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Level IIIA Kevlar Insert";


			mass = 66;


		class SCT_ITEMINFO{
			plateinfo[] = {"Level IIIA Kevlar Insert", 1};
			enableparts[] = {5,5,0,0,0,5,5,0,0};
			blunttraumaPad[] = {1,1,0,0,0,1,1,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_uniform_KEV3_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(UniformInsert) Level III Kevlar";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Level III Kevlar UP";


			mass = 95;


		class SCT_ITEMINFO{
			plateinfo[] = {"Level III Kevlar", 1};
			enableparts[] = {10,11,0,0,0,11,11,0,0};
			blunttraumaPad[] = {0.8,0.8,0,0,0,0.8,0.8,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};


	class SCT_uniform_OVR_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(UniformInsert) Level IV OVR-UP";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Level IV Russian Sapper Uniform Upgrade<br />Urban Warfare Type";


			mass = 110;


		class SCT_ITEMINFO{
			plateinfo[] = {"Level IV OVR-UP", 1};
			enableparts[] = {13,13,0,0,0,13,13,0,0};
			blunttraumaPad[] = {0.95,0.95,0,0,0,0.95,0.95,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_uniform_OVR2_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(UniformInsert) MIL-V Assault UP";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "MIL-V Aramid Uniform Upgrade, Assault-Type";


			mass = 180;


		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-V Assault UP", 1};
			enableparts[] = {22,22,0,0,0,22,22,0,0};
			blunttraumaPad[] = {3,3,0,0,0,3,3,0,0};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_uniform_CAPTAINPRICESIR_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(UniformInsert) MIL-VI Juggernaut UP";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "MIL-VI Aramid Uniform Upgrade, Juggernaut-Type";


			mass = 260;


		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-VI Juggernaut UP", 0};
			enableparts[] = {30,30,0,0,0,30,30,15,15};
			blunttraumaPad[] = {4,4,0,0,0,4,4,1.5,1.5};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_uniform_GAZWHERETHEHELLISTHATHELICOPTER_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(UniformInsert) MIL-VII Juggernaut+ UP";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "MIL-VII Aramid Uniform Upgrade, Assault Juggernaut-Type";


			mass = 320;


		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-VII Juggernaut+ UP", 0};
			enableparts[] = {50,50,50,50,50,50,50,25,25};
			blunttraumaPad[] = {5,5,5,5,5,5,5,1.5,1.5};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_uniform_DOYOUHAVETHEDSM_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(UniformInsert) MIL-VIII Panzersoldat";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "MIL-VIII Aramid Uniform Upgrade, Ubernaut-Type";


			mass = 390;


		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-VIII Panzersoldat", 0};
			enableparts[] = {170,170,170,170,170,170,50,25,25};
			blunttraumaPad[] = {7,7,7,7,7,7,7,2.5,2.5};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};

	class SCT_uniform_kevlarinsertweak_magtype: SonicT_Item_Base_magtype {
		scope = 2;
		displayName = "(UniformInsert) Level I Kevlar Insert";
		picture = "";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Level I Kevlar Insert";


			mass = 30;


		class SCT_ITEMINFO{
			plateinfo[] = {"Level I Kevlar Insert", 1};
			enableparts[] = {1,2,0,0,0,2,1,0,0};
			blunttraumaPad[] = {0.7,0,0,0,0.7,0.7,1,0.7,0.7};
			enablePlace[] = {"Vest", "Uniform"};
		};
	};
