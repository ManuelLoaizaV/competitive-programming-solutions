#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

typedef long long Long;

struct Punto {
  Long x_, y_;
  Punto() {}
  Punto(Long x, Long y) :
    x_(x), y_(y) {}
};

Punto operator + (const Punto& p1, const Punto& p2) {
  return Punto(p1.x_ + p2.x_, p1.y_ + p2.y_);
}

Punto operator * (const Long k, const Punto& p) {
  return Punto(k * p.x_, k * p.y_);
}

Punto operator - (const Punto& p1, const Punto& p2) {
  return p1 + (-1) * p2;
}

bool operator == (const Punto& p1, const Punto& p2) {
  if (p1.x_ == p2.x_ && p1.y_ == p2.y_) return true;
  return false;
}

bool operator != (const Punto& p1, const Punto& p2) {
  return !(p1 == p2);
}

Long InnerProduct(const Punto& p1, const Punto& p2) {
  return p1.x_ * p2.x_ + p1.y_ * p2.y_;
}

Long CrossProduct(const Punto& p1, const Punto& p2) {
  return p1.x_ * p2.y_ - p2.x_ * p1.y_;
}

struct Segmento {
  Punto p1_, p2_;
  Segmento() {}
  Segmento(Punto p1, Punto p2) {
    p1_ = p1;
    p2_ = p2;
  }
};

bool OnSegment(const Punto& p, const Segmento& s) {
  if (CrossProduct(p - s.p1_, p - s.p2_) != 0) return false;
  if (min(s.p1_.x_, s.p2_.x_) <= p.x_ && p.x_ <= max(s.p1_.x_, s.p2_.x_) &&
      min(s.p1_.y_, s.p2_.y_) <= p.y_ && p.y_ <= max(s.p1_.y_, s.p2_.y_))
    return true;
  return false;
}

bool Check(const Punto& p, const Segmento& s) {
  Punto v1 = s.p2_ - p;
  Punto v2 = p - s.p1_; 
  Long mini, maxi;
  if (v1.x_ == 0 && v2.x_ == 0) {
    mini = min(abs(v1.y_), abs(v2.y_));
    maxi = max(abs(v1.y_), abs(v2.y_));
    if (4 * mini >= maxi) return true;
  } else {
    mini = min(abs(v1.x_), abs(v2.x_));
    maxi = max(abs(v1.x_), abs(v2.x_));
    if (4 * mini >= maxi) return true;
  }
  return false;
}

bool Ok(Segmento seg[]) {
  // seg[] = {Izquierda, Derecha, Centro}
  // Chequeo si extremo derecho de Izquierda coincide con extremo izquierdo
  // de Derecha
  if (seg[0].p2_ != seg[1].p1_) return false;
  // Chequeo si el angulo entre Izquierda y Derecho pertenece a (0, 90]
  if (InnerProduct(seg[0].p1_ - seg[0].p2_, seg[1].p2_ - seg[1].p1_) < 0) return false;
  // Chequeo si el extremo izquierdo de Centro pertenece a Izquierda
  if (!OnSegment(seg[2].p1_, seg[0])) return false; 
  // Si pertenece, chequeo que cumpla con la proporcion
  if (!Check(seg[2].p1_, seg[0])) return false;
  // Chequeo si el extremo derecho de Centro pertenece a Derecha
  if (!OnSegment(seg[2].p2_, seg[1])) return false;
  // Si pertenece, chequeo que cumpla con la proporcion
  if (!Check(seg[2].p2_, seg[1])) return false;
  return true;
}

void Solve() {
  Punto values[3][2];
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 2; j++)
      cin >> values[i][j].x_ >> values[i][j].y_;

  int perm[] = {0, 1, 2};
  int lim = 1 << 3;
  Segmento segments[3];
  do {
    for (int mask = 0; mask < lim; mask++) {
      int copy = mask;
      for (int bit = 0; bit < 3; bit++) {
        int d = copy & 1;
        copy >>= 1;
        segments[bit].p1_ = values[perm[bit]][d];
        segments[bit].p2_ = values[perm[bit]][d ^ 1];
      }
      for (int i = 0; i < 3; i++)
      if (Ok(segments)) {
        cout << "YES" << endl;
        return;
      }
    }
  } while (next_permutation(perm, perm + 3));
  cout << "NO" << endl;
}

int main() {
  fastio;
  Long t;
  cin >> t;
  while (t--) Solve();
  return 0;
}
