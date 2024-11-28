#include <gl/glut.h>
#include <gl/gl.h>
#include <gl/glu.h>

void drawBuildings() {

}

/*
void InitLight() {
	GLfloat light0_ambient[] = { 0.5, 0.4, 0.3, 1.0 }; 	//���� Ư��	
	GLfloat light0_diffuse[] = { 0.8, 0.7, 0.6, 1.0 };
	GLfloat light0_specular[] = { 1.0, 1.0, 1.0, 1.0 };

	GLfloat material_ambient[] = { 0.4, 0.4, 0.4, 1.0 };	//��ü Ư��
	GLfloat material_diffuse[] = { 0.9, 0.9, 0.9, 1.0 };
	GLfloat material_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat material_shininess[] = { 25.0 };

	glShadeModel(GL_SMOOTH);	//���� ���̵�		
	glEnable(GL_DEPTH_TEST);	//���� ���� Ȱ��ȭ
	glEnable(GL_LIGHTING);		//���� Ȱ��ȭ
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light0_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light0_specular);
}
*/

void displayFunc() {
	GLfloat LightPosition[] = { 0.0, 0.0, 1.5, 1.0 };
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glOrtho(0, 1500, 0, 1000, -1, 1);
	glViewport(0, 0, 1500, 1000);

	glPushMatrix();


	glPopMatrix();

	/*
		glColor3f(0.6, 0.0, 0.0);
		glBegin(GL_TRIANGLE_STRIP);
			glNormal3f(1.0, 0.0, 0.0);
			glVertex3f(0.0, 0.0, 0.0);
			glVertex3f(1.0, 0.0, 0.2);
			glVertex3f(0.0, 1.0, 0.3);
			glVertex3f(1.0, 1.0, 0.8);
			glVertex3f(0.0, 2.0, 1.0);
			glVertex3f(1.0, 2.0, 0.7);
			glVertex3f(0.0, 3.0, 0.7);
			glVertex3f(1.0, 3.0, 0.2);
		glEnd( );
		glBegin(GL_TRIANGLE_STRIP);
		glNormal3f(1.0, 0.0, 0.0);
			glVertex3f(1.0, 0.0, 0.2);
			glVertex3f(2.0, 0.0, 0.7);
			glVertex3f(1.0, 1.0, 0.8);
			glVertex3f(2.0, 1.0, 1.0);
			glVertex3f(1.0, 2.0, 0.7);
			glVertex3f(2.0, 2.0, 0.6);
			glVertex3f(1.0, 3.0, 0.2);
			glVertex3f(2.0, 3.0, 0.0);
		glEnd( );
		glBegin(GL_TRIANGLE_STRIP);
			glNormal3f(0.0, 1.0, 0.0);
			glVertex3f(2.0, 0.0, 0.7);
			glVertex3f(3.0, 0.0, 1.0);
			glVertex3f(2.0, 1.0, 1.0);
			glVertex3f(3.0, 1.0, 0.7);
			glVertex3f(2.0, 2.0, 0.6);
			glVertex3f(3.0, 2.0, 0.5);
			glVertex3f(2.0, 3.0, 0.0);
			glVertex3f(3.0, 3.0, 0.9);
		glEnd( );
	*/
	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1000, 1000);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Draw Building");
	glClearColor(1.0, 1.0, 1.0, 1.0);

	InitLight();
	glutDisplayFunc(displayFunc);

	glutMainLoop();
	return 0;
}

// triangular horn
// square horn
// cone (circular horn)
// 