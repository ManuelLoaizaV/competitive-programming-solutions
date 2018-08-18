//
// Creado por ManuelLoaiza el 12/11/2017
//

#include <bits/stdc++.h>

using namespace std;

string posiciones[] = {"1U", "1D", "1W", "1E",
						"2U", "2D", "2S", "2N",
						"3N", "3S", "3W", "3E",
						"4U", "4D", "4W", "4E",
						"5U", "5D", "5S", "5N",
						"6N", "6S", "6W", "6E"};

void siguientePosicion(string &s, char c) {
	
	if (s == "1U" and c == 'F') {s = "3N"; return;}	
	if (s == "1U" and c == 'B') {s = "6N"; return;}	
	if (s == "1U" and c == 'L') {s = "5N"; return;}	
	if (s == "1U" and c == 'R') {s = "2N"; return;}	
	if (s == "1D" and c == 'F') {s = "6N"; return;}	
	if (s == "1D" and c == 'B') {s = "3N"; return;}	
	if (s == "1D" and c == 'L') {s = "2N"; return;}	
	if (s == "1D" and c == 'R') {s = "5N"; return;}	
	if (s == "1W" and c == 'F') {s = "5N"; return;}	
	if (s == "1W" and c == 'B') {s = "2N"; return;}	
	if (s == "1W" and c == 'L') {s = "6N"; return;}	
	if (s == "1W" and c == 'R') {s = "3N"; return;}	
	if (s == "1E" and c == 'F') {s = "2N"; return;}	
	if (s == "1E" and c == 'B') {s = "5N"; return;}	
	if (s == "1E" and c == 'L') {s = "3N"; return;}	
	if (s == "1E" and c == 'R') {s = "6N"; return;}	
	
	if (s == "4U" and c == 'F') {s = "3S"; return;}	
	if (s == "4U" and c == 'B') {s = "6S"; return;}	
	if (s == "4U" and c == 'L') {s = "2S"; return;}	
	if (s == "4U" and c == 'R') {s = "5S"; return;}	
	if (s == "4D" and c == 'F') {s = "6S"; return;}	
	if (s == "4D" and c == 'B') {s = "3S"; return;}	
	if (s == "4D" and c == 'L') {s = "5S"; return;}	
	if (s == "4D" and c == 'R') {s = "2S"; return;}	
	if (s == "4W" and c == 'F') {s = "5S"; return;}	
	if (s == "4W" and c == 'B') {s = "2S"; return;}	
	if (s == "4W" and c == 'L') {s = "3S"; return;}	
	if (s == "4W" and c == 'R') {s = "6S"; return;}	
	if (s == "4E" and c == 'F') {s = "2S"; return;}	
	if (s == "4E" and c == 'B') {s = "5S"; return;}	
	if (s == "4E" and c == 'L') {s = "6S"; return;}	
	if (s == "4E" and c == 'R') {s = "3S"; return;}	
		
	if (s == "2U" and c == 'F') {s = "3W"; return;}
	if (s == "2U" and c == 'B') {s = "6W"; return;}
	if (s == "2U" and c == 'L') {s = "1W"; return;}
	if (s == "2U" and c == 'R') {s = "4W"; return;}
	if (s == "2D" and c == 'F') {s = "6W"; return;}
	if (s == "2D" and c == 'B') {s = "3W"; return;}
	if (s == "2D" and c == 'L') {s = "4W"; return;}
	if (s == "2D" and c == 'R') {s = "1W"; return;}
	if (s == "2S" and c == 'F') {s = "1W"; return;}
	if (s == "2S" and c == 'B') {s = "4W"; return;}
	if (s == "2S" and c == 'L') {s = "6W"; return;}
	if (s == "2S" and c == 'R') {s = "3W"; return;}
	if (s == "2N" and c == 'F') {s = "4W"; return;}
	if (s == "2N" and c == 'B') {s = "1W"; return;}
	if (s == "2N" and c == 'L') {s = "3W"; return;}
	if (s == "2N" and c == 'R') {s = "6W"; return;}
	
	if (s == "5U" and c == 'F') {s = "3E"; return;}
	if (s == "5U" and c == 'B') {s = "6E"; return;}
	if (s == "5U" and c == 'L') {s = "4E"; return;}
	if (s == "5U" and c == 'R') {s = "1E"; return;}
	if (s == "5D" and c == 'F') {s = "6E"; return;}
	if (s == "5D" and c == 'B') {s = "3E"; return;}
	if (s == "5D" and c == 'L') {s = "1E"; return;}
	if (s == "5D" and c == 'R') {s = "4E"; return;}
	if (s == "5S" and c == 'F') {s = "1E"; return;}
	if (s == "5S" and c == 'B') {s = "4E"; return;}
	if (s == "5S" and c == 'L') {s = "3E"; return;}
	if (s == "5S" and c == 'R') {s = "6E"; return;}
	if (s == "5N" and c == 'F') {s = "4E"; return;}
	if (s == "5N" and c == 'B') {s = "1E"; return;}
	if (s == "5N" and c == 'L') {s = "6E"; return;}
	if (s == "5N" and c == 'R') {s = "3E"; return;}

	if (s == "3N" and c == 'F') {s = "4D"; return;}
	if (s == "3N" and c == 'B') {s = "1D"; return;}
	if (s == "3N" and c == 'L') {s = "5D"; return;}
	if (s == "3N" and c == 'R') {s = "2D"; return;}
	if (s == "3S" and c == 'F') {s = "1D"; return;}
	if (s == "3S" and c == 'B') {s = "4D"; return;}
	if (s == "3S" and c == 'L') {s = "2D"; return;}
	if (s == "3S" and c == 'R') {s = "5D"; return;}
	if (s == "3W" and c == 'F') {s = "5D"; return;}
	if (s == "3W" and c == 'B') {s = "2D"; return;}
	if (s == "3W" and c == 'L') {s = "1D"; return;}
	if (s == "3W" and c == 'R') {s = "4D"; return;}
	if (s == "3E" and c == 'F') {s = "2D"; return;}
	if (s == "3E" and c == 'B') {s = "5D"; return;}
	if (s == "3E" and c == 'L') {s = "4D"; return;}
	if (s == "3E" and c == 'R') {s = "1D"; return;}
	
	if (s == "6N" and c == 'F') {s = "4U"; return;}
	if (s == "6N" and c == 'B') {s = "1U"; return;}
	if (s == "6N" and c == 'L') {s = "2U"; return;}
	if (s == "6N" and c == 'R') {s = "5U"; return;}
	if (s == "6S" and c == 'F') {s = "1U"; return;}
	if (s == "6S" and c == 'B') {s = "4U"; return;}
	if (s == "6S" and c == 'L') {s = "5U"; return;}
	if (s == "6S" and c == 'R') {s = "2U"; return;}
	if (s == "6W" and c == 'F') {s = "5U"; return;}
	if (s == "6W" and c == 'B') {s = "2U"; return;}
	if (s == "6W" and c == 'L') {s = "4U"; return;}
	if (s == "6W" and c == 'R') {s = "1U"; return;}
	if (s == "6E" and c == 'F') {s = "2U"; return;}
	if (s == "6E" and c == 'B') {s = "5U"; return;}
	if (s == "6E" and c == 'L') {s = "1U"; return;}
	if (s == "6E" and c == 'R') {s = "4U"; return;}
	
}

int main() {
	string posicionFinal, movimientos;
	cin >> posicionFinal >> movimientos;
	int l = movimientos.size();
	
	for (int i = 0; i < 24; i++) {
		string posicionInicial = posiciones[i];
		
		for (int j = 0; j < l; j++) {
			siguientePosicion(posicionInicial, movimientos[j]);
		}
		
		if (posicionInicial == posicionFinal) {
			cout << posiciones[i] << endl;
			break;
		}
	}
	
	return 0;
}
