#include <GL/glut.h>
#include <stdlib.h> 
 static int window;
static int menu_id;
static int submenu_id;
static int value = 0; 

void menu(int num){
  if(num == 0){
    glutDestroyWindow(window);
    exit(0);
  }else{
    value = num;
  }
  glutPostRedisplay();
} 
void createMenu(void){     
    submenu_id = glutCreateMenu(menu);
    glutAddMenuEntry("Wired Teapot", 1);
    glutAddMenuEntry("Solid teapot", 2);
    menu_id = glutCreateMenu(menu);
    glutAddSubMenu("Select", submenu_id);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
} 
static void resize(int width, int height)
{
    const float ar = (float) width / (float) height; 
 
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0); 
 
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
} 
 
static void display(void)
{ 
 
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(0,1,0); 
    glClear(GL_COLOR_BUFFER_BIT);   if(value == 0){
    return; //glutPostRedisplay();
    }
    else if(value == 2)
    {
    glPushMatrix();
        glTranslated(0.0, 1.5, -6);
        glRotated(30, 0.0, -1.0, 0.0);
        glutSolidTeapot(1);
    glPopMatrix(); 
    glutSwapBuffers();
    }
else
{
    glColor3d(1, 0, 0);
    glPushMatrix();
        glTranslated(0.0, -1.2, -6.0);
        glutWireTeapot(1);
    glPopMatrix();
    glutSwapBuffers();
}
} 
 
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f }; 
 
const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f }; 
 
/* Program entry point */
 
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); 
 
    glutCreateWindow("Programming Techniques - 3D Teapots"); 
    // glutCreateMenu(menu);
    // glutAddSubMenu("Select", os);
    // glutAddMenuEntry("Wired", 1);
    // glutAddMenuEntry("solid", 2);
    createMenu();
 
    glutReshapeFunc(resize);
    glutDisplayFunc(display); 
 
    glClearColor(1,1,1,1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK); 
 
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS); 
 
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING); 
 
    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position); 
 
    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess); 
 
    glutMainLoop(); 
 
    return EXIT_SUCCESS;
}