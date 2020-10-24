#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(NULL)
#define debug(x) cout << #x << " = " << x << '\n'
using namespace std;

typedef long long Long;
typedef long double Double;
typedef pair<Long, Long> Pair;

const int N = 1e6;
const Long INF = 1e18;
const Double EPS = 1e-9;

vector<string> text;
string line, word;
set<string> index_word, stop_word;
map<string, int> score;
int L;

bool IsPunctuation(char c) {
  if (c == ',' || c == '.' || c == '?' || c == '!') return true;
  return false;
}

bool IsUpper(char c) {
  if ('A' <= c && c <= 'Z') return true;
  return false;
}

bool decreasing(pair<string, int>& s1, pair<string, int>& s2) {
  if (s1.second == s2.second) return s1.first < s2.first;
  return s1.second > s2.second;
}

/* 
 * Indice: etiqueta especial
 * 0: title
 * 1: abstract
 * 2: body
 */
int value[3] = {5, 3, 1};
stack<int> special;  // Tag abierto actual
set<string> exist;  // Tags especiales
map<string, string> trans;  // Conversiones

int main(void) {
  FAST_IO;
  // Inicializo tags que me importan
  exist.insert("<title>");
  exist.insert("</title>");
  exist.insert("<abstract>");
  exist.insert("</abstract>");
  exist.insert("<body>");
  exist.insert("</body>");

  trans["<title>"] = "+0";
  trans["</title>"] = "-0";
  trans["<abstract>"] = "+1";
  trans["</abstract>"] = "-1";
  trans["<body>"] = "+2";
  trans["</body>"] = "-2";

  exist.insert("+0");
  exist.insert("-0");
  exist.insert("+1");
  exist.insert("-1");
  exist.insert("+2");
  exist.insert("-2");

  // Leo el input y limpio la puntuacion y las mayusculas
  while (getline(cin, line)) {
    int len = line.size();
    string temp = "";
    for (int i = 0; i < len; i++) {
      if (IsPunctuation(line[i])) continue;
      if (IsUpper(line[i])) line[i] += 32;
      temp += line[i];
    }
    line = temp;
    len = line.size();
    for (int i = 0; i < len; i++) {
      // Si encuentro un inicio de tag
      if (line[i] == '<') {
        // Busco el final de ese tag
        for (int j = i; j < len; j++) {
          if (line[j] == '>') {
            string candidate = line.substr(i, j - i + 1);
            for (int k = i; k <= j; k++) line[k] = ' ';
            // Si existe, lo reemplazo por algo que me indique el inicio o el fin
            if (exist.count(candidate)) {
              string to = trans[candidate];
              line[i + 1] = to[0];
              line[i + 2] = to[1];
            }
            i = j;
            break;
          }
        }
      }
    }
    text.push_back(line);
  }
  
  // En la primera linea tenemos las palabras baneadas
  int len = text[0].size();
  for (int i = 0; i < len; i++) {
    if (text[0][i] == ';') text[0][i] = ' ';
  }
  stringstream s1(text[0]);
  while (s1 >> word) stop_word.insert(word);

  // En la segunda linea analizamos las palabras de interes
  len = text[1].size();
  for (int i = 0; i < len; i++) {
    if (text[1][i] == ';') text[1][i] = ' ';
  }
  stringstream s2(text[1]);
  while (s2 >> word) index_word.insert(word);

  // Analicemos cada token del texto
  int lines = text.size();
  for (int i = 2; i < lines; i++) {
    stringstream s3(text[i]);
    while (s3 >> word) {
      //debug(word);
      if (exist.count(word)) {
        if (word[0] == '+') {
          special.push(word[1] - '0');
        } else {
          special.pop();
        } 
      } else {
        if (special.size() > 0) {
          if (stop_word.count(word) || word.size() < 4) continue;
          L++;
          //debug(L);
          if (index_word.count(word)) {
            score[word] += value[special.top()];
          }
        }
      }
    }
  }
  // Finalmente, presentamos el reporte
  vector<pair<string, int>> answer;
  for (auto it = score.begin(); it != score.end(); it++) {
    answer.push_back({it->first, it->second});
  }
  sort(answer.begin(), answer.end(), decreasing);
  len = answer.size();
  int top3 = min(3, len);
  for (int i = 0; i < top3; i++) {
    //debug(answer[i].first);
    //debug(answer[i].second);
    Double sw = answer[i].second * 100.0 / L;
    cout << answer[i].first << ": " << fixed << setprecision(9) << sw << '\n';
  }
  // En caso de empates, imprimimos los que empatan al tercer lugar
  if (len > 3) {
    for (int j = 3; j < len; j++) {
      if (answer[j].second == answer[2].second) {
        Double sw = answer[j].second * 100.0 / L;
        cout << answer[j].first << ": " << fixed << setprecision(9) << sw << '\n';
      } else {
        break;
      }
    }
  }
  return 0;
}
