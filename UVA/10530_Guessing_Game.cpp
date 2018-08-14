//
// Created by ManuelLoaiza on 01/30/18.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int guess;
    int limiteInferior = 0, limiteSuperior = 11;

    while (cin >> guess) {
        if (guess == 0) break;
        string a, b;
        cin >> a >> b;
        string response = a + " " + b;

        if (response == "too high") {
            limiteSuperior = min(limiteSuperior, guess);
        } else {
            if (response == "too low") {
                limiteInferior = max(limiteInferior, guess);
            } else {

                if (response == "right on") {

                    if (limiteInferior < guess and guess < limiteSuperior) {
                        cout << "Stan may be honest" << endl;
                    } else {
                        cout << "Stan is dishonest" << endl;
                    }

                    limiteInferior = 0;
                    limiteSuperior = 11;
                }
            }
        }
    }

    return 0;
}
