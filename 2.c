#include <GL/glut.h>
#include <GL/gl.h>
#include <stdio.h>
// using namespace std;


float sc = 1;
void display (void){
	glClear(GL_COLOR_BUFFER_BIT);
	//glColor3f(1.0,1.0,1.0);
	glFlush();
	
}





void drawSquare(int x, int y) {
	//y = 250-y;
	//x = x-250;
//glClear(GL_COLOR_BUFFER_BIT);
	glScalef(sc, sc, 1);

	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2i(x, y+20);
	glVertex2i(x-20, y-20);
	glVertex2i(x+20, y-20);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 1.0, 0.0);
	glVertex2i(x-20, y+20);
	glVertex2i(x, y-20);
	glVertex2i(x+20, y+20);
	glEnd();
	


	glutSwapBuffers();
	glFlush();
}





// void mouse(int bin, int state , int x , int y) {
// 	if(bin == GLUT_LEFT_BUTTON && state == GLUT_DOWN) drawSquare(x,y);
// }


void mouse(int button,int state,int x,int y)
{
	switch(button)
	{
	case GLUT_LEFT_BUTTON:
		if(state==GLUT_DOWN)
			drawSquare(x,y);
		break;
	case GLUT_RIGHT_BUTTON:
		if(state==GLUT_DOWN)
			drawSquare(x,y);
		break;
	default:
		break;
	}
}

void keyboard(unsigned char key, int x, int y)
{
	//-------- spin --------
	if(key=='s')
	{
		sc += 0.5;
		// glutPostRedisplay();
	}
	else if(key=='r')
	{
		sc -= 0.5;
		// glutPostRedisplay();
	}
}



void init (void)
{
	/* select clearing (background) color */
	glClearColor (1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	
	glViewport( 0,0, 500, 500 );
	glMatrixMode( GL_PROJECTION );
	glOrtho( 0.0, 500.0, 0.0, 500.0, 1.0, -1.0 );
	
	/* initialize viewing values */
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

// void init(){
// 	glClearColor(0,0,0,0);
// 	glMatrixMode(GL_PROJECTION);
// 	glLoadIdentity();
// 	glOrtho(-100,100,-100,100,-1,1);
// }


/*Main*/

int main (int argc,char** argv){
	glutInit(&argc,argv);
	glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE );
	glutInitWindowSize(500,500);
	/*Set the posotion of window*/
	glutInitWindowPosition(0,0);
	glutCreateWindow("My Vindow");
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	init();
	glutMainLoop();
	
	
} 
