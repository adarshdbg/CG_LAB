#include <stdio.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <GL/glut.h>
using namespace std;

int pntX1, pntY1,pntz1, choice = 0, edges;
vector<int> pntX;
vector<int> pntY;
vector<int> pntz;
int transX, transY;
double scaleX, scaleY;
double angle, angleRad;
char reflectionAxis, shearingAxis;
int shearingX, shearingY;

double round(double d)
{
	return floor(d + 0.5);
}

void drawPolygon()
{
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	for (int i = 0; i < edges; i++)
	{
		glVertex3i(pntX[i], pntY[i],pntz[i]);
	}
	glEnd();
}


void drawPolygonRotation(double angleRad)
{
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	for (int i = 0; i < edges; i++)
	{
		glVertex3i(round(pntX[i]), round((pntY[i] * cos(angleRad)) - (pntz[i] * sin(angleRad))),round((pntY[i] * sin(angleRad)) - (pntz[i] * cos(angleRad))));
	}
	glEnd();
}

void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-640.0, 640.0, -480.0, 480.0);
}


void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);

	
		drawPolygon();
		drawPolygonRotation(angleRad);
	
	glFlush();
}

int main(int argc, char** argv)
{

	cout << "\n\nFor Polygon:\n" << endl;

	cout << "Enter no of edges: "; cin >> edges;

	for (int i = 0; i < edges; i++)
	{
		cout << "Enter co-ordinates for vertex  " << i + 1 << " : "; cin >> pntX1 >> pntY1>>pntz1;
		pntX.push_back(pntX1);
		pntY.push_back(pntY1);
		pntz.push_back(pntz1);
	}

	
		cout << "Enter the angle for rotation: "; cin >> angle;
		angleRad = angle * 3.1416 / 180;


	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize( 1000, 1000 );
glutInitWindowPosition (1000, 1000);
	glutCreateWindow("polygon rotation Transformations");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();

}
