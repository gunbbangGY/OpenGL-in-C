#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

GLint X0, Y0, flag=0;
clock_t start, end;

void DrawPixel(int x, int y) {
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

void lineDraw1(int x1, int y1, int x2, int y2) {
	GLfloat y, m;
	GLint x, dx, dy;
	dx = x2 - x1;  dy = y2 - y1;
	m = (float)dy / (float)dx;
	for (x = x1; x <= x2; x++) {
		y = m * (x - x1) + y1;
		DrawPixel(x, round(y));
	}
}

void lineDraw2(int x1, int y1, int x2, int y2) {
	GLfloat y, m;
	GLint x, dx, dy;
	dx = x2 - x1;  dy = y2 - y1;
	m = (float)dy / (float)dx;
	y = y1;
	for (int x = x1; x <= x2; x++) {
		DrawPixel(x, round(y));
		y += m;
	}
}

void Brethnum(int x1, int y1, int x2, int y2) {
	GLint incrE, incrNE, D, x, y, dx, dy;
	dx = x2 - x1; dy = y2 - y1;
	D = 2 * dy - dx;              
	incrE = 2 * dy;
	incrNE = 2 * dy - 2 * dx;        
	x = x1;      y = y1;       
	DrawPixel(x, y);
	while (x < x2) {
		if (D <= 0) D += incrE;
		else {
			D += incrNE;       	
			y++;
		}
		x++;
		DrawPixel(x, y);
	}
}

void displayFunc() {

	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 1500, 0, 1000, -1, 1);
	glViewport(0, 0, 1500, 1000);


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glPointSize(2.0);
	

	X0 = 100; Y0 = 100;
	
	
	switch (flag) {
		case 0 :
			start = clock();
			glColor3f(0.7, 0.0, 0.0);
			for (GLint i = 0; i < 500; i++) {
				Y0 += 1;
				lineDraw1(X0, Y0, X0 + 1300, Y0 + 50);
			}
			end = clock();
			printf("오리지날 방법으로 걸린 시간: %.4f s\n", (double)(end - start) / CLOCKS_PER_SEC);
			break;

		case 1 :
			start = clock();
			glColor3f(0.0, 0.7, 0.0);
			for (GLint i = 0; i < 500; i++) {
				Y0 += 1;
				lineDraw2(X0, Y0, X0 + 1300, Y0 + 50);
			}
			end = clock();
			printf("개선된 방법으로 걸린 시간: %.4f s\n", (double)(end - start) / CLOCKS_PER_SEC);
			break;
	
		case 2 :
			start = clock();
			glColor3f(0.0, 0.0, 0.7);
			for (GLint i = 0; i < 500; i++) {
				Y0 += 1;
				Brethnum(X0, Y0, X0 + 1300, Y0 + 50);
			}
			end = clock();
			printf("브레스넘 방법으로 걸린 시간: %.4f s\n", (double)(end - start) / CLOCKS_PER_SEC);
			break;

		default :
			break;
	}
	glFlush();
	glutSwapBuffers();
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
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(1500, 1000);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("work");
	glClearColor(1.0, 1.0, 1.0, 1.0);


	glutDisplayFunc(displayFunc);
	glutKeyboardFunc(keyboardFunc);
	glutMouseFunc(mouseClickFunc);

	glutMainLoop();

	return 0;
}