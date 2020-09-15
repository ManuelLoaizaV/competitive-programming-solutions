#include <iostream>
#define fastio ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

typedef long long Long;

struct Punto {
  Long x, y;
  Punto() {}
  Punto(Long x_, Long y_) :
    x(x_), y(y_) {}
};

Punto operator + (Punto p1, Punto  p2) {
  return Punto(p1.x + p2.x, p1.y + p2.y);
}

Punto operator * (Long k, Punto p) {
  return Punto(k * p.x, k * p.y);
}

Punto operator - (Punto p1, Punto p2) {
  return p1 + (-1LL) * p2;
}

Long CrossProduct(Punto p1, Punto p2) {
  return p1.x * p2.y - p2.x * p1.y;
}

bool Ok(Punto p, Punto puntos[], Long n) {
  for (int i = 0; i < n; i++) {
    Punto &p1 = puntos[i];
    Punto &p2 = puntos[(i + 1) % n];
    if (CrossProduct(p1 - p, p2 - p) < 0LL) return false;
  }
  return true;
}

int main() {
  fastio;
  Long n, q;
  cin >> n >> q;
  Punto puntos[n];
  for (int i = 0; i < n; i++)
   cin >> puntos[i].x >> puntos[i].y;
  Punto p;
  while (q--) {
    cin >> p.x >> p.y;
    if (Ok(p, puntos, n)) {
      cout << "D" << '\n';
    } else {
      cout << "F" << '\n';
    }
  } 
  return 0;
}
