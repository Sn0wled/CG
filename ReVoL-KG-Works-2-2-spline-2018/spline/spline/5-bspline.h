// 2007 ReVoL Primer Template
// 5-bspline

// ������� ������
int V[MAX_POINT + MAX_POINT + 1];

// ��������� �������� ������� B-�������
double nikt(int i, int k, double t, int ln) {
    return 0;
}

// ������ B-������
// px, py - ����� ��������������
// m      - ���������� ����� (�������)
// ln     - ���������� ��������� ������
// k      - ������� ������
void draw_bspline(HDC hdc, const int * px, const int * py, int m, int ln, int k) {
}

// ������ ������� ������ ��� B-�������
// px, py - ����� ��������������
// m      - ���������� ����� (�������)
// k      - ������� ������
// x      - ������� ������
void build_knot(const int * px, const int * py, int m, int k, int * x) {
}
