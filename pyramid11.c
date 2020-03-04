
#include <GL/glut.h>
#include <math.h>
#define PI 3.1415
float X = 0, Y = 0, Z = 0;
void keyboard(unsigned char key, int x, int y)
{
	
	switch (key) {
	case'd':glRotatef(10.0, 0.0, 1.0, 0.0); break;
	case'a':glRotatef(-10.0, 0.0, 1.0, 0.0); break;
	case's':glRotatef(10.0, 1.0, 0.0, 0.0); break;
	case'w':glRotatef(-10.0, 1.0, 0.0, 0.0); break;
	case'q':glRotatef(10.0, 0.0, 0.0, 1.0); break;
	case'e':glRotatef(-10.0, 0.0, 0.0, 1.0); break;
	case'z':glScalef(1.02, 1.0, 1.0); break;
	case'x':glScalef(1.0, 1.02, 1.0); break;
	case'c':glScalef(0.9, 1.0, 1.0); break; 
	case'v':glScalef(1.0, 0.9, 1.0); break; 
	case'b':glScalef(1.0, 1.0, 0.9); break;
	case'n':glScalef(1.0, 1.0, 1.02); break; 
	case't':glTranslatef( 1.0, 1.0, 1.0 ); break;
	case'0':glTranslatef( -1.0, -1.0, -1.0 ); break;

	}
	glutPostRedisplay(); 
}
void keyboard(int key, int x, int y) {
	

	switch (key) {
	case GLUT_KEY_LEFT:X -= 0.01; break;  
	case GLUT_KEY_RIGHT:X += 0.01; break; 
	case GLUT_KEY_UP:Y += 0.01; break; 
	case GLUT_KEY_DOWN:Y -= 0.01; break;  
	case GLUT_KEY_PAGE_UP:Z += 0.01; break;  
	case GLUT_KEY_PAGE_DOWN:Z -= 0.01; break; 
	}
	glutPostRedisplay();
}


void init(void)
{	
	
	glClearColor(0, 0, 0,0); 
	glShadeModel(GL_FLAT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);

}
void display(void) {

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3ub(0, 0, 200);
	glPointSize(5); 
	glBegin(GL_LINE_LOOP);

	
	glColor3f(1, 1, 1);
	glVertex3f(0.25 + X, -0.25 + Y, 0.0 + Z);
	glVertex3f(0.25 + X, 0.25 + Y, 0.0 + Z);
	glVertex3f(-0.25 + X, 0.25 + Y, 0.0 + Z);
	glVertex3f(-0.25 + X, -0.25 + Y, 0.0 + Z);
	glEnd();

	glBegin(GL_LINES);
	
	glVertex3f(0.25 + X, -0.25 + Y, 0.0 + Z);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.0 + X, 0.0 + Y, 0.5 + Z);

	glColor3f(0, 0, 1.0);
	glVertex3f(0.25 + X, 0.25 + Y, 0.0 + Z);
    glColor3f(0, 0.0, 1.0);
	glVertex3f(0.0 + X, 0.0 + Y, 0.5 + Z);

	
	glVertex3f(-0.25 + X, 0.25 + Y, 0.0 + Z);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.0 + X, 0.0 + Y, 0.5 + Z);

	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-0.25 + X, -0.25 + Y, 0.0 + Z);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.0 + X, 0.0 + Y, 0.5 + Z);
	glEnd();

        /* Ekrana basmak için kullanılır  */
	glFlush();
	glutSwapBuffers();



}


int main(int argc, char **argv)
{

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

	glutInitWindowSize(800, 800); // pencere boyutunu ayarlar

	glutInitWindowPosition(0, 0); // pencere pozisyonunu ayarlar

	glutCreateWindow("Pyramid"); // açtığımız pencerenin ismi
	glutSpecialFunc(keyboard); //klavyeden özel karakter girişi alır
	glutKeyboardFunc(keyboard); //klavyeden giriş alır
	init(); // arka plan ayarlarını yaptığımız fonksiyon
	glutDisplayFunc(display); // ekrana yazdırdığımız fonksiyon
	glutMainLoop();

	return 0;
}


