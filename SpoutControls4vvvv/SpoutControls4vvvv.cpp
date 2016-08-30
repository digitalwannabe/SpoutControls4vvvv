#include "SpoutControls4vvvv.h"

vector<control> myControls;
SpoutControls spoutcontrols;

void InitializeControls(char *sendername, int *numControls, char** names, int *types, float* floats, float* toggles, float* press, char** text) {

	int Vcontrols = (INT_PTR)numControls[0];//actually only the number of all controls needed...
	int Tcontrols = (INT_PTR)numControls[1];
	int Pcontrols = (INT_PTR)numControls[2];
	int Scontrols = (INT_PTR)numControls[3];

	int all = Vcontrols + Tcontrols + Pcontrols + Scontrols;
	int v=0, t=0, p=0, s = 0;

	for (int controlID = 0; controlID < all; controlID++) {

		if (types[controlID] == 0) {
			spoutcontrols.CreateControl(names[controlID], "float",0.0,1.0, floats[v]);
			v++;
		}
		if (types[controlID] == 1) {
			spoutcontrols.CreateControl(names[controlID], "bool", toggles[t]);
			t++;
		}
		if (types[controlID] == 2) {
			spoutcontrols.CreateControl(names[controlID], "event", press[p]);
			p++;
		}
		if (types[controlID] == 3) {
			spoutcontrols.CreateControl(names[controlID], "text", text[s]);
			s++;
		}

	}
	
	spoutcontrols.OpenControls(sendername);
}


bool UpdateControls(const char** text, float * floats, float *toggles, float *press, int *numControls) {
	int Vcontrols = (INT_PTR)numControls[0];//actually only the number of all controls needed...
	int Tcontrols = (INT_PTR)numControls[1];
	int Pcontrols = (INT_PTR)numControls[2];
	int Scontrols = (INT_PTR)numControls[3];


	int all = Vcontrols + Tcontrols + Pcontrols + Scontrols;
	int v = 0, t = 0, p = 0, s = 0;

	

	if (spoutcontrols.CheckControls(myControls)) {

		for (int controlID = 0; controlID < all; controlID++) {

			if (myControls[controlID].type == 10) {
				floats[v] = myControls[controlID].value;
				v++;
			}
			if (myControls[controlID].type == 0) {
				toggles[t] = myControls[controlID].value;
				t++;
			}
			if (myControls[controlID].type == 1) {
				press[p] = myControls[controlID].value;
				p++;
			}
			if (myControls[controlID].type == 100) {
				text[s] = myControls[controlID].text.data();
				s++;
			}

		}
		return true;
	}
	return false;
}

void UpdateFloatControls(int *numControls, float * floats) {

	int Vcontrols = (INT_PTR)numControls[0];//actually only the number of all controls needed...
	int Tcontrols = (INT_PTR)numControls[1];
	int Pcontrols = (INT_PTR)numControls[2];
	int Scontrols = (INT_PTR)numControls[3];

	int all = Vcontrols + Tcontrols + Pcontrols + Scontrols;
	int index = 0;

	floats = new float[Vcontrols];
	
	if (spoutcontrols.CheckControls(myControls)) {

		for (int controlID = 0; controlID < all; controlID++) {

			if (myControls[controlID].type == 10) {
				floats[index]=myControls[controlID].value;
				index++;
			}
		}
	}

	delete[] floats;
}

void CloseControls() {
	spoutcontrols.CloseControls();
}