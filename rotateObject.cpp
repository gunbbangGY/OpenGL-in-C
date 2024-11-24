#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>

GLfloat eX = 0.0;
GLfloat eY = 0.0;
GLfloat eZ = 0.0;
GLfloat aX = 0.0;
GLfloat aY = 0.0;
GLfloat aZ = 1.0;
GLfloat uX = 0.0;
GLfloat uY = 1.0;
GLfloat uZ = 0.0;

void InitLight() {

	GLfloat mat_diffuse[] = { 0.5, 0.4, 0.3, 1.0 };
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_ambient[] = { 0.5, 0.4, 0.3, 1.0 };
	GLfloat mat_shininess[] = { 15.0 };
	GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
	GLfloat light_ambient[] = { 0.3, 0.3, 0.3, 1.0 };
	GLfloat light_position[] = { -3, 6, 3.0, 0.0 };

	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}

void MyDisplay() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eX, eY, eZ, aX, aY, aZ, uX, uY, uZ);
	glutSolidTeapot(0.5);
	glFlush();
}

void MyReshape(int w, int h) {

	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}

void KB(unsigned char KeyPressed, int X, int Y) {

	switch (KeyPressed) {
		case 'q':
		case 'Q':
			eX += 0.1;
			break;

		case 'w':
		case 'W':
			eY += 0.1;
			break;

		case 'e':
		case 'E':
			eZ += 0.1;
			break;

		case 'a':
		case 'A':
			eX -= 0.1;
			break;
	
		case 's':
		case 'S':
			eY -= 0.1;
			break;
	
		case 'd':
		case 'D':
			eZ -= 0.1;
			break;

		case 'r':
		case 'R':
			aX += 0.1;
			break;

		case 't':
		case 'T':
			aY += 0.1;
			break;

		case 'y':
		case 'Y':
			aZ += 0.1;
			break;

		case 'f':
		case 'F':
			aX -= 0.1;
			break;

		case 'g':
		case 'G':
			aY -= 0.1;
			break;

		case 'h':
		case 'H':
			aZ -= 0.1;
			break;

		case 'u':
		case 'U':
			uX += 0.1;
			break;
	
		case 'i':
		case 'I':
			uY += 0.1;
			break;
	
		case 'o':
		case 'O':
			uZ += 0.1;
			break;
	
		case 'j':
		case 'J':
			uX -= 0.1;
			break;
	
		case 'k':
		case 'K':
			uY -= 0.1;
			break;
	
		case 'l':
		case 'L':
			uZ -= 0.1;
			break;
	}

	printf("eye(%.2f, %.2f, %.2f) at(%.2f, %.2f, %.2f) up(%.2f, %.2f, %.2f)\n", eX, eY, eZ, aX, aY, aZ, uX, uY, uZ);

	glutPostRedisplay();
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL Sample Drawing");
	glClearColor(0.4, 0.4, 0.4, 0.0);
	InitLight();
	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(MyReshape);
	glutKeyboardFunc(KB);
	glutMainLoop();

	return 0;
}