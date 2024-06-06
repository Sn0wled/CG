// 2007 ReVoL Primer Template
// 1-nonparam.h

// ������ ����������������� ������
// px, py - ������� ��������� �����
// ln     - ���������� ��������� ������
void draw_nonparam(HDC hdc, const int * px, const int * py, int ln) {
	if (ln == 0) return;
	int x0 = px[0], x1 = px[1], x0grip = px[GRIP_L], x1grip = px[GRIP_R];
	int y0 = py[0], y1 = py[1], y0grip = py[GRIP_L], y1grip = py[GRIP_R];
	int dx, dy;
	dx = x0grip - x0;
	dy = y0grip - y0;
	double k0 = (double)dy / dx;
	dx = x1 - x1grip;
	dy = y1 - y1grip;
	double k1 = (double)dy / dx;
	int t = x1 - x0;
	double a3 = (3 * (y1 - y0) / pow(t, 2)) + ((k0 + k1) / t);
	double a4 = (2 * (y0 - y1) / pow(t, 3)) + ((k0 + k1) / pow(t, 2));
	int ax = t / ln;
	MoveToEx(hdc, x0, y0, 0);
	for (int i = 0, x = 0; i < ln; i++) {
		x += ax;
		int y = y0 + (k0 + (a3 + a4 * x) * x) * x;
		LineTo(hdc, x0 + x, y);
	}
}
