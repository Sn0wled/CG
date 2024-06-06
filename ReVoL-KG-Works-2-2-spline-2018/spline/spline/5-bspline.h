// 2007 ReVoL Primer Template
// 5-bspline

// узловой вектор
int V[MAX_POINT + MAX_POINT + 1];

// вычисляет базисную функцию B-сплайна
double nikt(int i, int k, double t, int ln) {
    return 0;
}

// рисует B-сплайн
// px, py - точки многоугольника
// m      - количество точек (схватов)
// ln     - количество сегментов прямых
// k      - порядок кривой
void draw_bspline(HDC hdc, const int * px, const int * py, int m, int ln, int k) {
}

// строит узловой вектор для B-сплайна
// px, py - точки многоугольника
// m      - количество точек (схватов)
// k      - порядок кривой
// x      - узловой вектор
void build_knot(const int * px, const int * py, int m, int k, int * x) {
}
