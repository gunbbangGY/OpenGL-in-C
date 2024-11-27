#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

GLint X0, Y0, flag = 0;
clock_t start, end;

void DrawPixel(int x, int y) {
	glBegin(GL_POINTS);
	glVertex2f(x, y);
	glEnd();
	glFlush();
}

void lineDraw1(int x1, int y1, int x2, int y2) {
	GLfloat y, m;
	GLint x, dx, dy;
	dx = x2 - x1;  dy = y2 - y1;
	m = (float)dy / dx;
	for (x = x1; x <= x2; x++) {
		y = m * (x - x1) + y1;
		DrawPixel(x, round(y));
	}
}

void lineDraw2(int x1, int y1, int x2, int y2) {
	GLfloat y, m;
	GLint x, dx, dy;
	dx = x2 - x1;  dy = y2 - y1;
	m = (float)dy / dx;
	y = y1;
	for (int x = x1; x <= x2; x++) {
		DrawPixel(x, round(y));
		y += m;
	}
}

void Brethnum(int x1, int y1, int x2, int y2) {
	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);
	int sx = (x1 < x2) ? 1 : -1; // x 방향의 증가 또는 감소
	int sy = (y1 < y2) ? 1 : -1; // y 방향의 증가 또는 감소

	int err = dx - dy;
	int e2;

	int x = x1;
	int y = y1;

	while (1) {
		DrawPixel(x, y); // 현재 점 그리기
		if (x == x2 && y == y2) break; // 종료 조건

		e2 = 2 * err;
		if (e2 > -dy) {
			err -= dy;
			x += sx; // x를 이동
		}
		if (e2 < dx) {
			err += dx;
			y += sy; // y를 이동
		}
	}
}

void displayFunc() {

	glPointSize(2.0);
	X0 = 0; Y0 = 420;

	start = clock();
	glColor3f(0.7, 0.0, 0.0);
	for (GLint i = 0; i < 11; i++) {
		Y0 -= 1;
		lineDraw1(X0, Y0, X0 + 640, Y0 - 220);
	}
	glFinish();
	end = clock();
	printf("오리지날 방법으로 걸린 시간: %.4f s\n", (double)(end - start) / CLOCKS_PER_SEC);

	start = clock();
	glColor3f(0.0, 0.7, 0.0);
	for (GLint i = 0; i < 11; i++) {
		Y0 -= 1;
		lineDraw2(X0, Y0, X0 + 640, Y0 - 220);
	}
	glFinish();
	end = clock();
	printf("개선된 방법으로 걸린 시간: %.4f s\n", (double)(end - start) / CLOCKS_PER_SEC);

	start = clock();
	glColor3f(0.0, 0.0, 0.7);
	for (GLint i = 0; i < 11; i++) {
		Y0 -= 1;
		Brethnum(X0, Y0, X0 + 640, Y0 - 220);
	}
	glFinish();
	end = clock();
	printf("브레스넘 방법으로 걸린 시간: %.4f s\n", (double)(end - start) / CLOCKS_PER_SEC);

	//switch (flag) {
	//case 0:
	//	start = clock();
	//	glColor3f(0.7, 0.0, 0.0);
	//	for (GLint i = 0; i < 11; i++) {
	//		Y0 -= 1;
	//		lineDraw1(X0, Y0, X0 + 640, Y0 - 220);
	//	}
	//	end = clock();
	//	printf("오리지날 방법으로 걸린 시간: %.4f s\n", (double)(end - start) / CLOCKS_PER_SEC);
	//	break;

	//case 1:
	//	start = clock();
	//	glColor3f(0.0, 0.7, 0.0);
	//	for (GLint i = 0; i < 11; i++) {
	//		Y0 -= 1;
	//		lineDraw2(X0, Y0, X0 + 640, Y0 - 220);
	//	}
	//	end = clock();
	//	printf("개선된 방법으로 걸린 시간: %.4f s\n", (double)(end - start) / CLOCKS_PER_SEC);
	//	break;

	//case 2:
	//	start = clock();
	//	glColor3f(0.0, 0.0, 0.7);
	//	for (GLint i = 0; i < 11; i++) {
	//		Y0 -= 1;
	//		Brethnum(X0, Y0, X0 + 640, Y0 - 220);
	//	}
	//	end = clock();
	//	printf("브레스넘 방법으로 걸린 시간: %.4f s\n", (double)(end - start) / CLOCKS_PER_SEC);
	//	break;

	//default:
	//	break;
	//}
}

void keyboardFunc(unsigned char keyPressed, int keyX, int keyY) {
	flag = 0;

	glutPostRedisplay();
}

void mouseClickFunc(GLint buttonDirection, GLint stateDirection, GLint mouseX, GLint mouseY) {
	if (buttonDirection == GLUT_LEFT_BUTTON && stateDirection == GLUT_DOWN) flag = 1;
	if (buttonDirection == GLUT_RIGHT_BUTTON && stateDirection == GLUT_DOWN) flag = 2;

	glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 420);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("work");
	glClearColor(0.0, 0.0, 0.0, 1.0);

	glOrtho(0, 640, 0, 420, -1, 1);
	glViewport(0, 0, 640, 420);


	glutDisplayFunc(displayFunc);
	glutKeyboardFunc(keyboardFunc);
	glutMouseFunc(mouseClickFunc);

	glutMainLoop();
	return 0;
}