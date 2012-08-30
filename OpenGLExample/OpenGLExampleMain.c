#define GLUT_DISABLE_ATEXIT_HACK
#define PI 3.1415926535898 

#include <stdlib.h>
#include <math.h>
#include <gl/glut.h>

static GLfloat spin = 0.0;

void init(void) 
{
   glClearColor(0.0, 0.0, 0.0, 0.0);
   glShadeModel(GL_FLAT);
}

void display(void)
{
	GLubyte wb[2] = {0x00,0xff};
	GLubyte check[512];
	int i,j;
	for(i = 0; i < 64; i++)
	{
		for(j = 0; j < 8; j++)
			check[i*8+j] = wb[(i/8+j)%2];
	}
	/*
	glClearColor(1.0, 0.0, 0.0, 1.0);
	glColor3f(0,1,0);// glRasterPos2d(0, 5);
	glClear(GL_COLOR_BUFFER_BIT);
	*/
	glBitmap(64, 64, 0.0, 0.0, 0.0, 0.0, check);
	
	/*
	GLint i;
	GLfloat angle;
	GLint circle_points = 100; 
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0 ,1.0);
	glBegin(GL_LINE_LOOP); 
	for (i = 0; i < circle_points; i++) {    
	   angle = 2*PI*i/circle_points; 
	   glVertex2f(cos(angle), sin(angle)); 
	}
	glEnd();
	*/
	glFlush();
}


/*
 *  Request double buffer display mode.
 *  Register mouse input callback functions
 */
int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize(300, 300); 
   glutInitWindowPosition(100, 100);
   glutCreateWindow(argv[0]);
   init();
   glutDisplayFunc(&display); 
   glutMainLoop();
   return 0;
}