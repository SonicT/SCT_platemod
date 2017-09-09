/* idc reference 
	Body parts combobox = 5983;
	inventory finding combobox idc = 5984;
	Plates which are being used = 5985;
	Plates in inventory selected on combobox = 5986;

	activate plate button = 5987;
	disable and put plates to inventory = 5988;
	close window = 5989;
*/

_invPlatenum = lbCurSel 5986; //returns index number.
_ableParts = ["Front", "Back", "Lside", "Rside" ,"Pelvis"]; //temporary value. later other parts will be enabled.
