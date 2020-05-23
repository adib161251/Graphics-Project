#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>

#include <windows.h>
#include <glut.h>
#define pi (2*acos(0.0))

double cameraHeight;
double cameraAngle;
int drawgrid;
int drawaxes;
double angle;
double incx=50, incy;
int state;
struct point
{
	double x,y,z;
};
struct point2D
{
    double x,y;
};

struct point2D cp[200];
int cpidx;
double red=1,green,blue;


void push_pop(void)
{
    glPushMatrix();
        glRotatef(45, 0, 0, 1);
        glPushMatrix(); // Furthest Triangle, Draw first


            //glRotatef(45, 0, 0, 1);
            glTranslatef(-20, 0, 0);
            //glScaled(2, 1, 0);
            glColor3f(0.0, 0.0, 1.0);
            glBegin(GL_POLYGON);
                glVertex2f(10, 10);
                glVertex2f(10, 0);
                glVertex2f(-10, 0);
            glEnd();
        glPopMatrix();

        glPushMatrix(); // Middle Triangle, Draw 2nd
            glColor3f(0.0, 1.0, 0.0);
            glBegin(GL_POLYGON);
                glVertex2f(10, 10);
                glVertex2f(10, 0);
                glVertex2f(-10, 0);
            glEnd();
        glPopMatrix();

        glPushMatrix(); // Nearest Triangle, Draw last
            glTranslatef(20, 0, 0);
            glColor3f(1.0, 0.0, 0.0);
            glBegin(GL_POLYGON);
                glVertex2f(10, 10);
                glVertex2f(10, 0);
                glVertex2f(-10, 0);
            glEnd();
        glPopMatrix();



    glPopMatrix();

}


void drawAxes()
{

		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_LINES);{
			glVertex3f( 200,-50,0);
			glVertex3f(-200,-50,0);

			glVertex3f(0,-200,0);
			glVertex3f(0, 200,0);

			glVertex3f(0,0, 200);
			glVertex3f(0,0,-200);
		}glEnd();

}


void drawGrid()
{
	int i;

    glColor3f(0.6, 0.6, 0.6);	//grey
    glBegin(GL_LINES);{
        for(i=-8;i<=8;i++){

            if(i==0)
                continue;	//SKIP the MAIN axes

            //lines parallel to Y-axis
            glVertex3f(i*10, -90, 0);
            glVertex3f(i*10,  90, 0);

            //lines parallel to X-axis
            glVertex3f(-90, i*10, 0);
            glVertex3f( 90, i*10, 0);
        }
    }glEnd();

}

void drawSquare(double a)
{
    //glColor3f(1.0,0.0,0.0);
	glBegin(GL_QUADS);{
		glVertex3f( a, a,0);
		glVertex3f( a,-a,0);
		glVertex3f(-a,-a,0);
		glVertex3f(-a, a,0);
	}glEnd();
}


void drawCircle(float radius_x, float radius_y)
{
	int i = 0;
	float angle = 0.0;

	glBegin(GL_POLYGON);
    {
		for(i = 0; i < 100; i++)
		{
			angle = 2 * 3.1416 * i / 100;
			glVertex3f (cos(angle) * radius_x, sin(angle) * radius_y, 0);
		}

    }

	glEnd();
}
void rec_animation()
{
    glColor3f(0,1,0);
    glRotatef(5*angle,0,0,1);
    glTranslatef(incx,incy,0);
    glRotatef(5*angle,0,0,1);
    drawSquare(5);

}
void draw_rec()
{
    glColor3f(0,1,0);

    drawSquare(5);

}
void drawSS()
{
    glColor3f(1,0,0);
    drawSquare(20);
    glPushMatrix();
    glRotatef(angle,0,0,1);
    glTranslatef(110,0,0);
    glRotatef(2*angle,0,0,1);
    glColor3f(0,1,0);
    drawSquare(15);
    //glPopMatrix();

    glRotatef(angle,0,0,1);
    glTranslatef(60,0,0);
    glRotatef(2*angle,0,0,1);
    glColor3f(0,0,1);
    drawSquare(10);




}

void simple_trans()
{
    glRotatef(45, 0, 0, 1);
    glTranslatef(-10, 0, 0);
    glColor3f(0.0, 1.0, 0.0);
    draw_rec();
    glRotatef(45, 0, 0, 1);
    glTranslatef(-20, 0, 0);
    glColor3f(1.0, 0.0, 0.0);
    draw_rec();
}
double curve_by_points()
{
    ///
}
double func(double x)
{
    return x*x;
}
void curve()
{
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_LINES);
    for(double i =-180; i<180;i+=.5)
    {
        glVertex2d(i,10*func(i));
        glVertex2d(i+.5, 10*func(i+.5));
    }
     // It can be any type Gl_POINT,_LINE
    glEnd();

}

void surface() ///Adib kortese surface
{
    glColor3f(114.0f,159.0f,28.0f);
    glBegin(GL_QUADS);{
		glVertex3f(0,0,0);
		glVertex3f(0,94,0);
		glVertex3f(1000,94,0);
		glVertex3f(1000,0,0);
	}glEnd();

}

void wall2nd()
{
    glColor3f(0.721f,0.549f,0.384f);
    glBegin(GL_QUADS);{
		glVertex2f(-5,-20);
		glVertex2f(0,-20);
		glVertex2f(15,0);
		glVertex2f(13,3); //this will be used in wall4th

	}glEnd();
}
void wall1st()
{
    glColor3f(0.788f,0.635f,0.482f);
    glBegin(GL_POLYGON);{
		glVertex2f(0,-50);
		glVertex2f(0,-20);
		glVertex2f(15,0);
		glVertex2f(30,-20); //this will be used in wall4h
		glVertex2f(30,-50);

	}glEnd();
}

void wall4th()
{
    glColor3f(0.721f,0.549f,0.384f);
    glBegin(GL_QUADS);{
		glVertex2f(13,3);
		glVertex2f(30,-20);
		glVertex2f(60,-20);
		glVertex2f(43,3);

	}glEnd();
}

void wall5th()
{
    glColor3f(0.490f,0.333f,0.211f);
    glBegin(GL_QUADS);{
		glVertex2f(30,-20);
		glVertex2f(30,-50);
		glVertex2f(57,-50);
		glVertex2f(57,-20);

	}glEnd();
}

void doornob()
{
    glColor3f(0.552f,0.4f,0.247f);
    glBegin(GL_POLYGON);{
		glVertex2f(9,-50);
		glVertex2f(10,-25);
		glVertex2f(18,-25);
		glVertex2f(18,-50);
		glVertex2f(19,-50);
		glVertex2f(19,-24);
		glVertex2f(9,-24);

	}glEnd();
}
void glassnob1()
{
     glColor3f(1.615f,1.878f,0.964f);
    glBegin(GL_POLYGON);{
        glVertex2f(33,-40);
		glVertex2f(34,-40);
		glVertex2f(34,-26);
		glVertex2f(41,-26);
		glVertex2f(41,-40);
		glVertex2f(42,-40);
		glVertex2f(42,-24);
		glVertex2f(33,-24);

    }glEnd();
    glColor3f(1.615f,0.878f,0.964f);
    glBegin(GL_QUADS);{
		glVertex2f(33,-40);
		glVertex2f(42,-40);
		glVertex2f(42,-42);
		glVertex2f(33,-42);
    }glEnd();


}
void window()
{
    glColor3f(0.615f,0.878f,0.964f);
    glBegin(GL_QUADS);{
		glVertex2f(34,-40);
		glVertex2f(41,-40);
		glVertex2f(41,-26);
		glVertex2f(34,-26);

	}glEnd();
	glassnob1();
    glColor3f(0.615f,0.878f,0.964f);
    glBegin(GL_QUADS);{
		glVertex2f(47,-40);
		glVertex2f(54,-40);
		glVertex2f(54,-26);
		glVertex2f(47,-26);

	}glEnd();

}
void door()
{
    glColor3f(0.662f,0.509f,0.352f);
    glBegin(GL_QUADS);{
		glVertex2f(10,-50);
		glVertex2f(10,-25);
		glVertex2f(18,-25);
		glVertex2f(18,-50);

	}glEnd();

	doornob();
}

void home()
{
	wall1st();
	wall2nd();
	//wall3rd();
	wall4th();
	wall5th();


}

void mouseListener(int button, int state, int x, int y){	//x, y is the x-y of the screen (2D)
	switch(button){
		case GLUT_LEFT_BUTTON:
			if(state == GLUT_DOWN){		// 2 times?? in ONE click? -- solution is checking DOWN or UP

                std::cout << x << " " << y << std::endl;

                cp[cpidx].x = (double)x;
                cp[cpidx].y = (double)(600 - y);
                std::cout << cp[cpidx].x << " " << cp[cpidx].y << std::endl;
                cpidx++;
			}
			break;

		case GLUT_RIGHT_BUTTON:
			//........
			break;

		case GLUT_MIDDLE_BUTTON:
			//........
			break;

		default:
			break;
	}
}



void display(){

	//clear the display
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0,0,0,0);	//color black
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	//load the correct matrix -- MODEL-VIEW matrix
	glMatrixMode(GL_MODELVIEW);

	//initialize the matrix
	glLoadIdentity();

	//now give three info
	//1. where is the camera (viewer)?
	//2. where is the camera looking?
	//3. Which direction is the camera's UP direction?

	//gluLookAt(100,100,100,	0,0,0,	0,0,1);
	//gluLookAt(200*cos(cameraAngle), 200*sin(cameraAngle), cameraHeight,		0,0,0,		0,0,1);
	gluLookAt(0,0,200,	0,0,0,	0,1,0);


	//again select MODEL-VIEW
	glMatrixMode(GL_MODELVIEW);



	//add objects

	drawAxes();
	//drawGrid();
	//curve();
	//drawCircle(5,5);
    //drawSS();
    //draw_rec();
    //push_pop();
    //simple_trans();
    //rec_animation();
    door();
    window();
    home();
    //surface();







	//ADD this line in the end --- if you use double buffer (i.e. GL_DOUBLE)
	glutSwapBuffers();
}


void animate(){
    //rotation
    //angle+=0.005;

	//codes for any changes in Models, Camera
	//linear_oscillation

    /*if(state ==0 && incx>50){ state =1;}
    if(state ==1 && incx <-50){state =0;}

    if(state == 0) incx+=0.05;
    else incx-=0.05;*/

	glutPostRedisplay();
}

void init(){
	//codes for initialization
	drawgrid=0;
	drawaxes=1;
	cameraHeight=150.0;
	cameraAngle=1.0;
	angle=0;
	cpidx=0;

	//clear the screen
	glClearColor(0,0,0,0);


	//load the PROJECTION matrix
	glMatrixMode(GL_PROJECTION);

	//initialize the matrix
	glLoadIdentity();

	//give PERSPECTIVE parameters
	gluPerspective(80,	1,	1,	1000.0);
	//field of view in the Y (vertically)
	//aspect ratio that determines the field of view in the X direction (horizontally)
	//near distance
	//far distance
    //gluOrtho2D(0, 1000, 0, 600);

}

int main(int argc, char **argv){
	glutInit(&argc,argv);
	glutInitWindowSize(1000, 600);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);	//Depth, Double buffer, RGB color

	glutCreateWindow("My OpenGL Program");

	init();

	glEnable(GL_DEPTH_TEST);	//enable Depth Testing

	glutDisplayFunc(display);	//display callback function
	glutIdleFunc(animate);		//what you want to do in the idle time (when no drawing is occuring)

	//glutKeyboardFunc(keyboardListener);
	//glutSpecialFunc(specialKeyListener);
	glutMouseFunc(mouseListener);

	glutMainLoop();		//The main loop of OpenGL

	return 0;
}

