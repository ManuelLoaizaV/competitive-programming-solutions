// Gracias, Rodolfo
// Gracias, MarcosK
// Gracias, Graphter
// Obrigado, Dilson
//#pragma GCC optimize ("Ofast,unroll-loops")
//#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
#define fastio ios::sync_with_stdio(0);cin.tie(0)
#define For(i,a,b) for (Long i = a; i < b; i++)
#define roF(i,a,b) for (Long i = a; i >= b; i--)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(v) (v).begin(),(v).end()

typedef long long Long;
typedef long double Double;
typedef unsigned long long ULong;
typedef pair<Long, Long> Pair;
typedef vector<Long> Vector;
typedef vector<Pair> PairVector;

const int N = 1e6;
const Long INF = 1e18;
const Double EPS = 1e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
Long random(Long a, Long b) { return uniform_int_distribution<Long> (a, b) (rng); }

void calcular(Pair A, Pair B, Long radio, Long& dx, Long& dy, Long& dr_2, Long& D, Long& discriminante) {
  dx = B.x - A.x;
  dy = B.y - A.y;
  dr_2 = dx * dx + dy * dy;
  D = A.x * B.y - A.y * B.x;
  discriminante = radio * radio * dr_2 - D * D;
}

Pair operator *(const Long& k, const Pair& A) {
  return make_pair(k * A.x, k * A.y);
}

Pair operator +(const Pair& A, const Pair& B) {
  return make_pair(A.x + B.x, A.y + B.y);
}

Pair operator - (const Pair& A, const Pair& B) {
  return A + (-1) * B;
}

bool operator ==(const Pair& A, const Pair& B) {
  return A.x == B.x and A.y == B.y;
}

Pair reducir(Pair A) {
  Long gcd = __gcd(abs(A.x), abs(A.y));
  A.x /= gcd;
  A.y /= gcd;
  return A;
}

Long interno(Pair A, Pair B) {
  return A.x * B.x + A.y * B.y;
}

Double interno_real(pair<Double, Double> A, pair<Double, Double> B) {
  return A.x * B.x + A.y + B.y;
}

pair<Double, Double> operator *(const Double& k, const pair<Double, Double>& A) {
  return make_pair(k * A.x, k * A.y);
}

pair<Double, Double> operator +(const pair<Double, Double>& A, const pair<Double, Double>& B) {
  return make_pair(A.x + B.x, A.y + B.y);
}

pair<Double, Double> operator -(const pair<Double, Double>& A, const pair<Double, Double>& B) {
  return A + (-1.0) * B;
}

struct Recta {
  Double A, B, C;
  Recta() {}
  Recta(Pair P, Pair Q) {
    A = P.y - Q.y;
    B = Q.x - P.x;
    C = (-1) * A * P.x - B * P.y;
  }
  Recta(pair<Double, Double> P, pair<Double, Double> Q) {
    A = P.y - Q.y;
    B = Q.x - P.x;
    C = (-1.0) * A * P.x - B * P.y;
  }
};

vector<pair<Double, Double>> interseccion(Recta recta, Long radio) {
  Double r = (Double) radio;
  vector<pair<Double, Double>> ans;
  Double x0 = - recta.A * recta.C / (recta.A * recta.A + recta.B * recta.B);
  Double y0 = - recta.B * recta.C / (recta.A * recta.A + recta.B * recta.B);
  Double d = r * r - recta.C * recta.C / (recta.A * recta.A + recta.B * recta.B);
  Double m = sqrt(d / (recta.A * recta.A + recta.B * recta.B));
  ans.push_back({x0 + recta.B * m, y0 - recta.A * m});
  ans.push_back({x0 - recta.B * m, y0 + recta.A * m});
  return ans;
}

Double distancia_cuadrado(pair<Double, Double> A, pair<Double, Double> B) {
  Double dx = A.x - B.x;
  Double dy = A.y - B.y;
  return dx * dx + dy * dy;
}

bool check(pair<Double, Double> A, pair<Double, Double> V, pair<Double, Double> B, Double& lambda) {
  pair<Double, Double> AB = B - A;
  if (V.x > EPS) lambda = AB.x / V.x;
  else lambda = AB.y / V.y;
  pair<Double, Double> destino = A + lambda * V;
  pair<Double, Double> diferencia = B - destino;
  if (fabs(diferencia.x) < EPS and fabs(diferencia.y) < EPS) return true;
  return false;
}

pair<Double, Double> reflejar(pair<Double, Double> P, Recta recta) {
  pair<Double, Double> answer;
  answer.x = (P.x * (recta.B * recta.B - recta.A * recta.A) - 2 * recta.A * (recta.B * P.y + recta.C)) / (recta.A * recta.A + recta.B * recta.B);
  answer.y = (P.y * (recta.A * recta.A - recta.B * recta.B) - 2 * recta.B * (recta.A * P.x + recta.C)) / (recta.A * recta.A + recta.B * recta.B);
  return answer;
}

string solve() {
  Pair centro;
  cin >> centro.x >> centro.y;
  Long radio;
  cin >> radio;
  Pair A, V, B;
  cin >> A.x >> A.y;
  cin >> V.x >> V.y;
  cin >> B.x >> B.y;
  // Primero realizo un cambio de coordendas con origen en el centro
  A = A - centro;
  B = B - centro;
  // Interseccion circunferencia recta
  Pair A2 = A + V;
  Long dx, dy, dr_2, D, discriminante;
  calcular(A, A2, radio, dx, dy, dr_2, D, discriminante);
  // Si no hay interseccion o la recta es tangente a la circunferencia
  if (discriminante <= 0) {
    Pair AB = B - A;
    Pair AB_reducido = reducir(AB);
    Pair V_reducido = reducir(V);
    if (interno(AB_reducido, V_reducido) > 0 and AB_reducido == V_reducido) return "Yes";
    return "No";
  }
  // Si intersecta con la circunferencia
  Recta recta(A, A2);
  pair<Double, Double> A_real, V_real, B_real;
  A_real = {(Double) A.x, (Double) A.y};
  V_real = {(Double) V.x, (Double) V.y};
  B_real = {(Double) B.x, (Double) B.y};
  // Primero hallo el primer punto de interseccion de A con la circunferencia
  vector<pair<Double, Double>> interceptos = interseccion(recta, radio);
  Double distancia1 = distancia_cuadrado(A_real, interceptos[0]);
  Double distancia2 = distancia_cuadrado(A_real, interceptos[1]);
  pair<Double, Double> intercepto;
  if (distancia1 < distancia2) intercepto = interceptos[0];
  else intercepto = interceptos[1];
  pair<Double, Double> AB = B_real - A_real;
  pair<Double, Double> choque = intercepto - A_real;
  // Analizo si es que A alcanza B antes de chocar con la circunferencia
  // Primer subcaso, A se aleja de la circunferencia
  Double valor = interno_real(V_real, choque);
  Double lambda;
  if (fabs(valor) > EPS and valor < 0) {
    if (check(A_real, V_real, B_real, lambda)) return "Yes";
    return "No";
  }
  // Segundo subcaso, A se acerca a la circunferencia
  Double lambda_A_choca_B, lambda_A_corta_circunferencia;
  bool A_choca_B = check(A_real, V_real, B_real, lambda_A_choca_B);
  check(A_real, V_real, intercepto, lambda_A_corta_circunferencia);
  if (A_choca_B) {
    if (lambda_A_choca_B > 0.0 and lambda_A_choca_B < lambda_A_corta_circunferencia) {
      return "Yes";
    }
  }
  // Hallo la direccion de rebote y analizo si es que llega a B
  Recta recta_intercepto(intercepto, {0.0, 0.0});
  pair<Double, Double> reflejado = reflejar(A_real, recta_intercepto);
  pair<Double, Double> direccion_rebote = reflejado - intercepto;
  if (check(intercepto, direccion_rebote, B_real, lambda)) {
    if (lambda >= 0.0) return "Yes";
    return "No";
  }
  return "No";
}

int main() {
  fastio;
  int t = 1;
  cin >> t;
  For(i, 0, t) {
    cout << "Case #" << i + 1 << ": " << solve() << endl;
  }
  return 0;
}