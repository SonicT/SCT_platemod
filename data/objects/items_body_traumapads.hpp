
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
