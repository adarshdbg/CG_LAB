#include <GL/glut.h>
#include<stdio.h>
int r=20;
int x1=0,y1=0;
char spin = 0;
void keyboard( unsigned char key, int x, int y )
{
    if( key =='C' )
    {
        r*=2;
    }
if(key=='D')
r/=2;

}
void myInit() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 500, 0, 500);
}

void draw_pixel(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void displayBresenamOctants(int x,int y){
    draw_pixel(x1+x,y1+y);
    draw_pixel(x1-x,y1+y);
    draw_pixel(x1+x,y1-y);
    draw_pixel(x1-x,y1-y);
    draw_pixel(x1+y,y1+x);
    draw_pixel(x1-y,y1+x);
    draw_pixel(x1+y,y1-x);
    draw_pixel(x1-y,y1-x);
}

void draw_line(int x,int y,int r)
{
//glClearColor (0.0, 0.0, 0.0, 0.0);
 glClear (GL_COLOR_BUFFER_BIT);
    //glColor3f( 1, 1, 1 );
    glColor3f(1.0, 0.0, 0.0);
 x=0,y=r;
    int deicsionParameter = 3-2*r;
    displayBresenamOctants(x,y);
    while(y>=x){
        x++;
        if(deicsionParameter>0){
            y--;
            deicsionParameter=deicsionParameter+4*(x-y)+10;
        }
        else{
            deicsionParameter=deicsionParameter+4*x+6;
        }
        displayBresenamOctants(x,y);
    }
    
    
 
}

void myDisplay() {
    /*printf("Enter the co-ordinates of circle\n");
    
    // cin>>x1>>y1;
    scanf("%d%d",&x1,&y1);
    
    printf("Enter the value of radius\n");
    scanf("%d",&r);*/
    int x=0,y=0;
    glTranslatef(0.0f,0.0f,0);
    draw_line(x,y,r);
    glFlush();
}

float angle = 0;
void timer( int value )
{
    if( spin==1 )
    {
        angle += 3;
    }



    glutTimerFunc( 16, timer, 0 );
    glutPostRedisplay();
}
/*void mouse(int button,int state,int x,int y)
{
	switch(button)
	{
	case GLUT_LEFT_BUTTON:

			exit(0);
		break;
	
	case GLUT_RIGHT_BUTTON:
			draw(x,y);
printf("%d %d\n",x,y);
		break;
	default:
		break;
	}
}*/


void display()

{
//draw(100,100);
 glClear (GL_COLOR_BUFFER_BIT);
//glClearColor (0.0, 0.0, 0.0, 0.0);
 glutSwapBuffers();
}
 void init(void)
 {
 glClearColor (0.0, 0.0, 0.0, 0.0);
 glOrtho(-1000.0, 1000.0, -1000.0, 1000.0, -1.0, 1.0);
 }
int main( int argc, char **argv )
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE );
    glutInitWindowSize( 1000, 1000 );
glutInitWindowPosition (1000, 1000);
    glutCreateWindow( "GLUT" );
init();
    glutDisplayFunc( myDisplay );
    glutKeyboardFunc( keyboard );	
   // glutMouseFunc(mouse);
glutIdleFunc(display);
   // glutTimerFunc( 0, timer, 0 );
    glutMainLoop();
    return 0;
}





/*void draw_line() {
    
}*/





/*int main(int argc, char **argv) {

    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Bresenham's Cricle Drawing");
    myInit();
    glutDisplayFunc(myDisplay);
    glutMainLoop();
    return 0;
}*/

