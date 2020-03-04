#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <math.h>
/* Global variables */
char title[] = "3D Shapes";
float th1,th;
void display();
 
/* Initialize OpenGL Graphics */
void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   glClearDepth(1.0f);                   // Set background depth to farthest
   glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
   glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
   glShadeModel(GL_SMOOTH);   // Enable smooth shading
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);


}
 /*

/* Handler for window-repaint event. Called back when the window first appears and
   whenever the window needs to be re-painted. */

void display1() {
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
   glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix
 
   // Render a color-cube consisting of 6 quads with different colors
   glLoadIdentity();  // Nice perspective corrections    // Reset the model-view matrix
   glTranslatef(1.5f, 0.0f, -7.0f);  // Move right and into the screen
 
   glBegin(GL_TRIANGLES);           // Begin drawing the pyramid with 4 triangles
      // Front
      glColor3f(0.0f, 1.0f, 0.0f);     // Red
      glVertex3f( 0.0f, 1.0f, 0.0f);
      glColor3f(0.0f, 1.0f, 1.0f);     // Green
      glVertex3f(-1.0f, -1.0f, 1.0f);
      glColor3f(1.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(1.0f, -1.0f, 1.0f);
 
      // Right
     glColor3f(0.0f, 1.0f, 0.0f);     // Red
      glVertex3f(0.0f, 1.0f, 0.0f);
      glColor3f(0.0f, 1.0f, 1.0f);    // Blue
      glVertex3f(1.0f, -1.0f, 1.0f);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(1.0f, -1.0f, -1.0f);
 
      // Back
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f(0.0f, 1.0f, 0.0f);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(1.0f, -1.0f, -1.0f);
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(-1.0f, -1.0f, -1.0f);
 
      // Left
      glColor3f(1.0f,0.0f,0.0f);       // Red
      glVertex3f( 0.0f, 1.0f, 0.0f);
      glColor3f(0.0f,0.0f,1.0f);       // Blue
      glVertex3f(-1.0f,-1.0f,-1.0f);
      glColor3f(0.0f,1.0f,0.0f);       // Green
      glVertex3f(-1.0f,-1.0f, 1.0f);
   glEnd();   // Done drawing the pyramid
 //glutPostRedisplay();

glLoadIdentity();                  // Reset the model-view matrix
   glTranslatef(-1.5f, 0.0f, -6.0f);

glBegin(GL_TRIANGLES);           // Begin drawing the pyramid with 4 triangles
      // Front
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f( 0.0f, 1.0f*cos(th) - sin(th)*0.0f, 0.0f*cos(th) + sin(th)*1.0f);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f( -1.0f, -1.0f*cos(th) - sin(th)*1.0f, 1.0f*cos(th) + sin(th)*-1.0f);
      //glVertex3f(-1.0f*tx, -1.0f*ty, 1.0f*tz);
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f( 1.0f, -1.0f*cos(th) - sin(th)*1.0f, 1.0f*cos(th) + sin(th)*-1.0f);
      //glVertex3f(1.0f*tx, -1.0f*ty, 1.0f*tz);
 
      // Right
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f( 0.0f, 1.0f*cos(th) - sin(th)*0.0f, 0.0f*cos(th) + sin(th)*1.0f);
      //glVertex3f(0.0f*tx, 1.0f*ty, 0.0f*tz);
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f( 1.0f, -1.0f*cos(th) - sin(th)*1.0f, 1.0f*cos(th) + sin(th)*-1.0f);
      //glVertex3f(1.0f*tx, -1.0f*ty, 1.0f*tz);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f( 1.0f, -1.0f*cos(th) - sin(th)*-1.0f, -1.0f*cos(th) + sin(th)*-1.0f);
      //glVertex3f(1.0f*tx, -1.0f*ty, -1.0f*tz);
 
      // Back
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f( 0.0f, 1.0f*cos(th) - sin(th)*0.0f, 0.0f*cos(th) + sin(th)*1.0f);
      //glVertex3f(0.0f*tx, 1.0f*ty, 0.0f*tz);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f( 1.0f, -1.0f*cos(th) - sin(th)*-1.0f, -1.0f*cos(th) + sin(th)*-1.0f);
      //glVertex3f(1.0f*tx, -1.0f*ty, -1.0f*tz);
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f( -1.0f, -1.0f*cos(th) - sin(th)*-1.0f, -1.0f*cos(th) + sin(th)*-1.0f);
      //glVertex3f(-1.0f*tx, -1.0f*ty, -1.0f*tz);
 
      // Left
      glColor3f(1.0f,0.0f,0.0f);       // Red
      glVertex3f( 0.0f, 1.0f*cos(th) - sin(th)*0.0f, 0.0f*cos(th) + sin(th)*1.0f);
      //glVertex3f( 0.0f*tx, 1.0f*ty, 0.0f*tz);
      glColor3f(0.0f,0.0f,1.0f);       // Blue
      glVertex3f( -1.0f, -1.0f*cos(th) - sin(th)*-1.0f, -1.0f*cos(th) + sin(th)*-1.0f);
     // glVertex3f(-1.0f*tx,-1.0f*ty,-1.0f*tz);
      glColor3f(0.0f,1.0f,0.0f);       // Green
      glVertex3f( -1.0f, -1.0f*cos(th) - sin(th)*1.0f, 1.0f*cos(th) + sin(th)*-1.0f);
     // glVertex3f(-1.0f*tx,-1.0f*ty, 1.0f*tz);
     glEnd();


   glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)
}
 
/* Handler for window re-size event. Called back when the window first appears and
   whenever the window is re-sized with its new width and height */
void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
   // Compute aspect ratio of the new window
   if (height == 0) height = 1;                // To prevent divide by 0
   GLfloat aspect = (GLfloat)width / (GLfloat)height;
 
   // Set the viewport to cover the new window
   glViewport(0, 0, width, height);
 
   // Set the aspect ratio of the clipping volume to match the viewport
   glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
   glLoadIdentity();             // Reset
   // Enable perspective projection with fovy, aspect, zNear and zFar
   gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}
 
/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {

	int opt;
	printf("Enter 1.for cube\n");
	scanf("%d",&opt);
printf("Enter theta for rotation\n");
	scanf("%f",&th1);
   th= th1 * 3.1416 / 180;


   glutInit(&argc, argv);       


     // Initialize GLUT
   glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
   glutInitWindowSize(640, 480);   // Set the window's initial width & height
   glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
   glutCreateWindow(title); 

	glutDisplayFunc(display1); 
      // Register callback handler for window re-paint event
   glutReshapeFunc(reshape);       // Register callback handler for window re-size event
   initGL();                       // Our own OpenGL initialization
   glutMainLoop();                 // Enter the infinite event-processing loop
   return 0;
}