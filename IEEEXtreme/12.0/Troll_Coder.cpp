#include <bits/stdc++.h>
using namespace std;

void print(char c, string &s) {
    cout << c;
    for (int i = 0; i < s.size(); i++) cout << " " << s[i];
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; 
    cin >> n;
    string answer;
    for (int i = 0; i < n; i++) answer += '0';
    print('Q', answer);
    cout.flush();
    int correct, ward;
    cin >> correct;
    for (int i = 0; i < n; ++i) {
        answer[i] = '1';
        print('Q', answer);
        cout.flush();
        cin >> ward;
        if (ward < correct) {
            answer[i] = '0';
        } else {
            correct = ward;
        }
    }
    print('A', answer);
    return 0;
}
