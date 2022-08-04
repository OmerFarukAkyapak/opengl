#include "glew.h"
#include "freeglut.h"
#include "glut.h"
#include<iostream>
#include<math.h>
#include <stdlib.h>
#include<stdio.h>
#include<stdarg.h>

#define GL_GLEXT_PROTOTYPES

// ÖMER FARUK AKYAPAK 190401008

using namespace std;

void display();
void SpecialKey(int key, int x, int y);

double y_ekseni = 0;
double x_ekseni = 0;

int animasyon_durumu = 0;
int stop = 0;



void Loop(int t)
{
	cout << t << endl;
	y_ekseni -= 5;
	glutPostRedisplay();

	if (animasyon_durumu == 1) glutTimerFunc(100, Loop, 0); 
}

void klavye(unsigned char key, int x, int y)
{
	if (key == 'x')
	{
		if(stop!=1) glutTimerFunc(100, Loop, 0);
		stop = 1;
		animasyon_durumu = 1;
		
	}
	if (key == 'y') { 
		stop = 0;
		animasyon_durumu = 0; 
	}

}

void mouse(int button, int state, int x, int y)
{
	switch (button) {
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN)
		{
			
			cout << "SOL_BASILI: " << x << "-" << y << endl;
		}

		if (state == GLUT_UP)
		{
			
			cout << "SOL_YUKARI" << endl;
		}

		break;
	case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN)
			
			cout << "SAG_BASILI" << endl;
		if (state == GLUT_UP)
			
			cout << "SAG_YUKARI" << endl;
		break;
	case GLUT_MIDDLE_BUTTON:
		if (state == GLUT_DOWN)
			cout << "ORTA_BASILI" << endl;
		if (state == GLUT_UP)
			cout << "ORTA_YUKARI" << endl;
		break;
	case 3:
		if (state == GLUT_DOWN)
			cout << "SCROLL_UP_Down1" << endl;
		if (state == GLUT_UP)
			cout << "SCROLL_UP_up1" << endl;
		break;

	case 4:
		if (state == GLUT_DOWN)
			cout << "SCROLL_DOWN_Down1" << endl;
		if (state == GLUT_UP)
			cout << "SCROLL_DOWN_up1" << endl;
		break;
	default:
		break;
	}

}


int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Kup Cizimi");
	glEnable(GL_DEPTH_TEST);
	glutDisplayFunc(display);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glutSpecialFunc(SpecialKey);
	glutKeyboardFunc(klavye); 
	glutMouseFunc(mouse);

	glutMainLoop();
	return 0;
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity(); 	
	glRotatef(x_ekseni, 1.0, 0.0, 0.0);
	glRotatef(y_ekseni, 0.0, 1.0, 0.0);
	//Küpün renkli ön yüzü
	glBegin(GL_POLYGON); 
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.5, -0.5, -0.5);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0.5, 0.5, -0.5);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(-0.5, 0.5, -0.5);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(-0.5, -0.5, -0.5);
	glEnd();

	// Gri yüz-arka
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(-0.5, -0.5, 0.5);
	glEnd();

	// Mor yüz - sað
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glEnd();

	// Yeþil yüz - sol
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(-0.5, -0.5, -0.5);
	glEnd();

	// Mavi yüz - üst
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glEnd();

	// Kýrmýzý yüz - alt
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(-0.5, -0.5, -0.5);
	glEnd();

	glFlush();
	glutSwapBuffers();
}

void SpecialKey(int key, int x, int y)
{
	if (key == GLUT_KEY_RIGHT)
		y_ekseni -= 5;
	else if (key == GLUT_KEY_LEFT)
		y_ekseni += 5;
	else if (key == GLUT_KEY_UP)
		x_ekseni += 5;
	else if (key == GLUT_KEY_DOWN)
		x_ekseni -= 5;
	glutPostRedisplay();
}