#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include <windows.h>
#include <glut.h>




int drawgrid;
int drawaxes;


struct point
{
	double x,y,z;
};

double x,y;

void drawAxes()
{
	if(drawaxes==1)
	{
		glColor3f(1.0, 0.0, 0.0);
		glBegin(GL_LINES);{
			glVertex3f( 100,0,0);
			glVertex3f(-100,0,0);

			glVertex3f(0,-100,0);
			glVertex3f(0, 100,0);

			glVertex3f(0,0, 100);
			glVertex3f(0,0,-100);
		}glEnd();
	}
}


void drawGrid()
{
	int i;


    glColor3f(0.6, 0.6, 0.6);	//grey
    glBegin(GL_LINES);{
        for(i=-20;i<=20;i++){

            if(i==0)
                continue;	//SKIP the MAIN axes

            //lines parallel to Y-axis
            glVertex3f(i*5, -90, 0);
            glVertex3f(i*5,  90, 0);

            //lines parallel to X-axis
            glVertex3f(-90, i*5, 0);
            glVertex3f( 90, i*5, 0);
        }
    }glEnd();

}

void point()
{
    glColor3f(0.0f, 0.0f, 1.0f);
    glPointSize(1.5);
    glBegin(GL_POINTS);
    glVertex2f(0.5,0.5);
    glVertex2f(1,1);
    glVertex2f(1.5,1.5);
    glEnd();
}

void pointsMany(int num)
{
    glColor3f(1.0f, 1.0f, 1.0f);
    glPointSize(1.5);
    glBegin(GL_POINTS);
    for(int i = 0;i<num;i++)
    {
        glVertex2f((i*13)%31,(i*31)%39);
    }
    glEnd();
}
void just_line()
{
    glColor3f(0.176f, 0.356f, 0.007f); //BLUE LINE
    glBegin(GL_LINES); // It can be any type Gl_POINT,_LINE

        glVertex2d(0.0,-117.0);
        glVertex2d(0.0,-130.0);

         glVertex2d(-12.0,-117.0);
        glVertex2d(-12.0,-130.0);

         glVertex2d(-24.0,-117.0);
        glVertex2d(-24.0,-130.0);

        glVertex2d(100.0,-117.0);
        glVertex2d(100.0,-130.0);

         glVertex2d(88.0,-117.0);
        glVertex2d(88.0,-130.0);

         glVertex2d(76.0,-117.0);
        glVertex2d(76.0,-130.0);

        glVertex2d(-80.0,-77.0);
        glVertex2d(-80.0,-90.0);

         glVertex2d(-92.0,-77.0);
        glVertex2d(-92.0,-90.0);

         glVertex2d(-104.0,-77.0);
        glVertex2d(-104.0,-90.0);

        glVertex2d(70.0,-77.0);
        glVertex2d(70.0,-90.0);

         glVertex2d(58.0,-77.0);
        glVertex2d(58.0,-90.0);

         glVertex2d(46.0,-77.0);
        glVertex2d(46.0,-90.0);
    glEnd();

}
void lines()
{
    glColor3f(0.0f, 1.0f, 0.0f); // GREEN RECTANGLE
    glBegin(GL_LINE_LOOP); // It can be any type Gl_POINT,_LINE

        glVertex2d(20,20);
        glVertex2d(-20,20);
        glVertex2d(-20,-20);
        glVertex2d(20,-20);

    glEnd();
}
void triangle()
{
    glColor3f(1.0f, 0.0f, 0.0f); //RED TRIANGLE
    glBegin(GL_LINE_LOOP); // It can be any type Gl_POINT,_LINE

        glVertex2d(0.0,2.5);
        glVertex2d(-2.5,0.0);
        glVertex2d(2.5,0.0);

    glEnd();

}

void Circle(float cx,float cy,float r,int num_segments){

    glBegin(GL_POLYGON);
    int i;
    for(i=0;i<num_segments;i++)
    {
        float theta=2.0f*3.1415926f*float(i)/float(num_segments);
        float x=r*cosf(theta);
        float y=r*sinf(theta);

        glVertex2f(x+cx,y+cy);

    }
    glEnd();


}

void drawCircle(float radius_x, float radius_y)
{
	int i = 0;
	float angle = 0.0;

	glBegin(GL_POLYGON);
    {
		for(i = 0; i < int(5000); i++)
		{
			angle = 2 * 3.1416 * i / 1000;
			glVertex2f ( radius_x* cos(angle), radius_y * sin(angle));
		}

    }

	glEnd();
}

void drawCloud(){

    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    Circle(-50,90,10,100);//upper part
    Circle(-65,95,10,100);
    Circle(-60,85,10,100);
    Circle(-56,98,10,100);

    /*Circle(50,90,10,100); //lower part
    Circle(80,125,10,100);
    Circle(20,85,10,100);
    Circle(60,75,10,100);
    */

    Circle(50,90,10,100);//upper part
    Circle(65,95,10,100);
    Circle(60,85,10,100);
    Circle(56,98,10,100);
    glPopMatrix();

}
void s_triangle()
{
    glBegin(GL_TRIANGLES); // DRAWING 3 SIDED TRIANGLE
        glColor3f(0.121f, 0.349f, 0.039f);
        glVertex2d(80.0,-40.0);
        glVertex2d(80.0,5.0);
        glVertex2d(85.0,-40.0);

        glColor3f(0.211f, 0.407f, 0.133f);
        glVertex2d(80.0,-40.0);
        glVertex2d(75.0,-40.0);
        glVertex2d(80.0,5.0);

        glColor3f(0.121f, 0.349f, 0.039f);
        glVertex2d(67.0,-45.0);
        glVertex2d(67.0,-5.0);
        glVertex2d(72.0,-45.0);

        glColor3f(0.211f, 0.407f, 0.133f);
        glVertex2d(67.0,-45.0);
        glVertex2d(62.0,-45.0);
        glVertex2d(67.0,-5.0);

        glColor3f(0.121f, 0.349f, 0.039f);
        glVertex2d(90.0,-45.0);
        glVertex2d(90.0,-9.0);
        glVertex2d(94.0,-45.0);

        glColor3f(0.211f, 0.407f, 0.133f);
        glVertex2d(90.0,-45.0);
        glVertex2d(86.0,-45.0);
        glVertex2d(90.0,-9.0);

        glColor3f(0.121f, 0.349f, 0.039f);
        glVertex2d(-30.0,-45.0);
        glVertex2d(-30.0,-5.0);
        glVertex2d(-25.0,-45.0);

        glColor3f(0.211f, 0.407f, 0.133f);
        glVertex2d(-30.0,-45.0);
        glVertex2d(-35.0,-45.0);
        glVertex2d(-30.0,-5.0);

        glColor3f(0.121f, 0.349f, 0.039f);
        glVertex2d(-50.0,-45.0);
        glVertex2d(-50.0, 5.0);
        glVertex2d(-45.0,-45.0);

        glColor3f(0.211f, 0.407f, 0.133f);
        glVertex2d(-50.0,-45.0);
        glVertex2d(-55.0,-45.0);
        glVertex2d(-50.0, 5.0);

    glEnd();

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
    glColor3f(0.317f,0.301f,0.262f);
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
    glColor3f(0.317f,0.301f,0.262f);
    glBegin(GL_QUADS);{
		glVertex2f(33,-40);
		glVertex2f(42,-40);
		glVertex2f(42,-42);
		glVertex2f(33,-42);
    }glEnd();


}
void glassnob2()
{
    glColor3f(0.317f,0.301f,0.262f);
    glBegin(GL_POLYGON);{
        glVertex2f(46,-40);
		glVertex2f(47,-40);
		glVertex2f(47,-26);
		glVertex2f(54,-26);
		glVertex2f(54,-40);
		glVertex2f(55,-40);
		glVertex2f(55,-24);
		glVertex2f(46,-24);
    }glEnd();
    glColor3f(0.317f,0.301f,0.262f);
    glBegin(GL_QUADS);{
		glVertex2f(46,-40);
		glVertex2f(55,-40);
		glVertex2f(55,-42);
		glVertex2f(46,-42);
    }glEnd();
}
void window()
{
    glColor3f(0.317f,0.301f,0.262f);//window line 1
    glBegin(GL_LINES);{
        glVertex2f( 34,-33);
        glVertex2f(41,-33);

        glVertex2f(37.5,-40);
        glVertex2f(37.5,-26);
    }glEnd();

    glColor3f(0.615f,0.878f,0.964f);
    glBegin(GL_QUADS);{  //window one
		glVertex2f(34,-40);
		glVertex2f(41,-40);
		glVertex2f(41,-26);
		glVertex2f(34,-26);

	}glEnd();
	glassnob1();

	glColor3f(0.317f,0.301f,0.262f);//window line 2
    glBegin(GL_LINES);{
        glVertex2f(47,-33);
        glVertex2f(54,-33);

        glVertex2f(50.5,-40);
        glVertex2f(50.5,-26);
    }glEnd();
    glColor3f(0.615f,0.878f,0.964f);
    glBegin(GL_QUADS);{   //window two
		glVertex2f(47,-40);
		glVertex2f(54,-40);
		glVertex2f(54,-26);
		glVertex2f(47,-26);

	}glEnd();
	glassnob2();

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
void detail()
{
    glColor3f(0.490f,0.333f,0.211f);
	glBegin(GL_LINES);
	{
	    glVertex2f(2,-50);
	    glVertex2f(2,-17);

	    glVertex2f(4,-50);
	    glVertex2f(4,-14);

        glVertex2f(6,-50);
	    glVertex2f(6,-12);

	    glVertex2f(8,-50);
	    glVertex2f(8,-10);

	    glVertex2f(10,-24);
	    glVertex2f(10,-7);

        glVertex2f(12,-24);
	    glVertex2f(12,-4);

	    glVertex2f(14,-24);
	    glVertex2f(14,-1);

        glVertex2f(16,-24);
	    glVertex2f(16,-0.5);

	    glVertex2f(18,-24);
	    glVertex2f(18,-4);

	    glVertex2f(28,-50);
	    glVertex2f(28,-17);

        glVertex2f(26,-50);
	    glVertex2f(26,-14);

        glVertex2f(24,-50);
	    glVertex2f(24,-12);

        glVertex2f(22,-50);
	    glVertex2f(22,-10);

        glVertex2f(20,-50);
	    glVertex2f(20,-8);

	    ///above for wall1

        glVertex2f(15,1);
	    glVertex2f(45,1);

	    glVertex2f(18,-3);
	    glVertex2f(48,-3);

        glVertex2f(20,-7);
	    glVertex2f(50,-7);

	    glVertex2f(24,-11);
	    glVertex2f(54,-11);

	    glVertex2f(26,-15);
	    glVertex2f(56,-15);

	}glEnd();
}
void home()
{
    glTranslatef(-10,0,0);
    detail();
    door();
    window();
	wall1st();
	wall2nd();
	//wall3rd();
	wall4th();
	wall5th();
}


void snow()
{
    glPushMatrix();
     ///1st mountain er khaj (first part)
    glColor3f(0.643,0.501,0.462);
    glBegin(GL_TRIANGLES);{
        glVertex2f(-31,30);
        glVertex2f(-28.25,35);
        glVertex2f(-25.5,30);

    }glEnd();

    ///1st mountain er 2nd khaj
    glColor3f(0.643,0.501,0.462);
    glBegin(GL_TRIANGLES);{
        glVertex2f(-25.5,30);
        glVertex2f(-20,30);
        glVertex2f(-22.75,35);
    }glEnd();

    ///1st mountain er 3rd khaj
    glColor3f(0.576,0.454,0.419);
    glBegin(GL_TRIANGLES);{
        glVertex2f(-20,30);
        glVertex2f(-14.5,30);
        glVertex2f(-17.25,35);
    }glEnd();

    ///1st mountain er 4rd khaj
    glColor3f(0.576,0.454,0.419);
    glBegin(GL_TRIANGLES);{
        glVertex2f(-14.5,30);
        glVertex2f(-9,30);
        glVertex2f(-11.75,35);
    }glEnd();

    glColor3f(0.945,0.921,0.854);
    glBegin(GL_TRIANGLES);{
        glVertex2f(-31,30);
        glVertex2f(-20,60); /// 1st mountain er chura
        glVertex2f(-20,30);
    } glEnd();
    glColor3f(0.847,0.827,0.768);
    glBegin(GL_TRIANGLES);{
        glVertex2f(-20,60); ///1ts mountain er chura
        glVertex2f(-20,30);
         glVertex2f(-9,30);
    }glEnd();
    glPopMatrix();



    glPushMatrix();

    ///2nd mountain er khaj 1st part
       glColor3f(0.643,0.501,0.462);

    glBegin(GL_TRIANGLES);{
        glVertex2f(11.5,30);
        glVertex2f(18.25,30);
        glVertex2f(14.875,38);
    }glEnd();
    ///2nd mountain er khaj 2nd part
       glColor3f(0.643,0.501,0.462);

    glBegin(GL_TRIANGLES);{
        glVertex2f(18.25,30);
        glVertex2f(25,30);
        glVertex2f(21.625,38);
    }glEnd();

    ///2nd mountain er khaj 3rd part
   glColor3f(0.576,0.454,0.419);
    glBegin(GL_TRIANGLES);{
        glVertex2f(25,30);
        glVertex2f(31.75,30);
        glVertex2f(28.375,38);
    }glEnd();

    ///2nd mountain er khaj 4th part
  glColor3f(0.576,0.454,0.419);
    glBegin(GL_TRIANGLES);{
        glVertex2f(31.75,30);
        glVertex2f(38.5,30);
        glVertex2f(35.125,38);
    }glEnd();

    glColor3f(0.945,0.921,0.854);
    glBegin(GL_TRIANGLES);{
        glVertex2f(11.5,30);
        glVertex2f(25,80); /// 2nd mountain er chura
        glVertex2f(25,30);
    }glEnd();
    glColor3f(0.847,0.827,0.768);
    glBegin(GL_TRIANGLES);{
        glVertex2f(25,80); /// 2nd mountain er chura
        glVertex2f(25,30);
        glVertex2f(38.5,30);
    }glEnd();
    glPopMatrix();

    glPushMatrix();

    ///3rd mountain er khaj 1st part
        glColor3f(0.643,0.501,0.462);

    glBegin(GL_TRIANGLES);{
        glVertex2f(56.5,30);
        glVertex2f(60.75,30);
        glVertex2f(58.625,35);
    }glEnd();

    ///3rd mountain er khaj 2st part
       glColor3f(0.643,0.501,0.462);

    glBegin(GL_TRIANGLES);{
        glVertex2f(60.75,30);
        glVertex2f(65,30);
        glVertex2f(62.875,35);
    }glEnd();
    ///3rd mountain er khaj 3st part
   glColor3f(0.576,0.454,0.419);
    glBegin(GL_TRIANGLES);{
        glVertex2f(65,30);
        glVertex2f(69,30);
        glVertex2f(67,35);
    }glEnd();
    ///3rd mountain er khaj 3st part
    glColor3f(0.576,0.454,0.419);
    glBegin(GL_TRIANGLES);{
        glVertex2f(69,30);
        glVertex2f(73,30);
        glVertex2f(71,35);
    }glEnd();




    glColor3f(0.945,0.921,0.854);
    glBegin(GL_TRIANGLES);{
        glVertex2f(56.5,30);
        glVertex2f(65,60); /// 3rd mountain er chura
        glVertex2f(65,30);
    }glEnd();

    glColor3f(0.847,0.827,0.768);
    glBegin(GL_TRIANGLES);{
        glVertex2f(65,60); /// 3rd mountain er chura
        glVertex2f(65,30);
        glVertex2f(73,30);
    }glEnd();
    glPopMatrix();


}

void mini()
{
    glColor3f(0.580,0.647,0.309);
    glBegin(GL_TRIANGLES);{  ///1st mini
        glVertex2f(-45,-50);
        glVertex2f(-25,-50);
        glVertex2f(-25,20);
    }glEnd();
    glColor3f(0.498,0.568,0.160);
    glBegin(GL_TRIANGLES);{
        glVertex2f(-25,-50);
        glVertex2f(-25,20);
        glVertex2f(-5,-50);
    }glEnd();

    glColor3f(0.650,0.709,0.341);
    glBegin(GL_TRIANGLES);{ ///2nd mini
        glVertex2f(-20,-50);
        glVertex2f(0,25);
        glVertex2f(0,-50);
    }glEnd();

    glColor3f(0.590,0.650,0.219);
    glBegin(GL_TRIANGLES);{
        glVertex2f(0,25);
        glVertex2f(0,-50);
        glVertex2f(20,-50);
    }glEnd();


     glColor3f(0.643,0.717,0.298);
    glBegin(GL_TRIANGLES);{ ///3rd mini
        glVertex2f(5,-50);
        glVertex2f(25,27);
        glVertex2f(25,-50);
    }glEnd();

     glColor3f(0.603,0.650,0.254);
    glBegin(GL_TRIANGLES);{
        glVertex2f(25,27);
        glVertex2f(25,-50);
        glVertex2f(45,-50);
    }glEnd();

    glColor3f(0.580,0.647,0.309);
    glBegin(GL_TRIANGLES);{ ///4th mini
        glVertex2f(28,-50);
        glVertex2f(48,-50);
        glVertex2f(48,27);
    }glEnd();

    glColor3f(0.498,0.568,0.160);
    glBegin(GL_TRIANGLES);{
        glVertex2f(48,-50);
        glVertex2f(48,27);
        glVertex2f(68,-50);
    }glEnd();

    glColor3f(0.580,0.647,0.309);
    glBegin(GL_TRIANGLES);{  ///5th mini
        glVertex2f(52,-50);
        glVertex2f(72,-50);
        glVertex2f(72,29);
    }glEnd();
    glColor3f(0.498,0.568,0.160);
    glBegin(GL_TRIANGLES);{
        glVertex2f(72,-50);
        glVertex2f(72,29);
        glVertex2f(92,-50);
    }glEnd();

    glColor3f(0.580,0.647,0.309);
    glBegin(GL_TRIANGLES);{ ///6th mini
        glVertex2f(48,-50);
        glVertex2f(60,-50);
        glVertex2f(60,25);
    }glEnd();

    glColor3f(0.498,0.568,0.160);
    glBegin(GL_TRIANGLES);{
        glVertex2f(60,-50);
        glVertex2f(60,25);
         glVertex2f(72,-50);
    }glEnd();

    ///7th mini
    glColor3f(0.584,0.647,0.266);
    glBegin(GL_TRIANGLES);{
        glVertex2f(-45,-50);
        glVertex2f(-55,-50);
         glVertex2f(-55,29);
    }glEnd();

    glColor3f(0.650,0.705,0.388);
    glBegin(GL_TRIANGLES);{
         glVertex2f(-55,-50);
         glVertex2f(-55,29);
         glVertex2f(-65,-50);
    }glEnd();
    ///8th mini
   /* glColor3f(0.584,0.647,0.266);
    glBegin(GL_TRIANGLES);{
         glVertex2f(-63,-50);
         glVertex2f(-73,-50);
         glVertex2f(-73,22);
    }glEnd();
    glColor3f(0.650,0.705,0.388);
    glBegin(GL_TRIANGLES);{
         glVertex2f(-73,-50);
         glVertex2f(-73,22);
          glVertex2f(-83,-50);
    }glEnd();
*/

}

void mini2()
{
    glColor3f(0.584,0.647,0.266);
    glBegin(GL_TRIANGLES);{
         glVertex2f(-63,-50);
         glVertex2f(-73,-50);
         glVertex2f(-73,22);
    }glEnd();
    glColor3f(0.650,0.705,0.388);
    glBegin(GL_TRIANGLES);{
         glVertex2f(-73,-50);
         glVertex2f(-73,22);
          glVertex2f(-83,-50);
    }glEnd();
}

void mini3()
{
    glPushMatrix();
    glTranslatef(170,0,0);
    mini2();
    glPopMatrix();
}


void Hill()
{
    snow();
    mini3();
    mini();

    glPushMatrix();
    glColor3f(0.643,0.501,0.462);
    glBegin(GL_TRIANGLES);{
        glVertex2f(-60,-50);
        glVertex2f(-20,60);
        glVertex2f(-20,-50);
    }glEnd();

    glColor3f(0.576,0.454,0.419);
    glBegin(GL_TRIANGLES);{
        glVertex2f(-20,60);
        glVertex2f(-20,-50);
        glVertex2f(20,-50);
    }glEnd();
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.643,0.501,0.462);
        glBegin(GL_TRIANGLES);{
        glVertex2f(-10,-50);
        glVertex2f(25,80);
        glVertex2f(25,-50);

    }glEnd();
     glColor3f(0.576,0.454,0.419);
    glBegin(GL_TRIANGLES);{
        glVertex2f(25,80);
        glVertex2f(25,-50);
        glVertex2f(60,-50);

    }glEnd();
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.643,0.501,0.462);
        glBegin(GL_TRIANGLES);{
        glVertex2f(35,-50);
        glVertex2f(65,60);
        glVertex2f(65,-50);
        }glEnd();

        glColor3f(0.576,0.454,0.419);
        glBegin(GL_TRIANGLES);{

        glVertex2f(65,60);
        glVertex2f(65,-50);
        glVertex2f(95,-50);

    }glEnd();



    glPopMatrix();

}
void tcircle(float radius_x, float radius_y)
{
   int i = 0;
	float angle = 0.0;

	glBegin(GL_POLYGON);
    {
		for(i = 0; i < int(5000); i++)
		{
			angle =2 * 3.1416 * i / 1000;
			glVertex2f ( radius_x* cos(angle), radius_y * sin(angle));
		}

    }

	glEnd();
}
void t1()
{
    glPushMatrix();
    glTranslatef(-20,-50,0);
    glColor3f(0.262f,0.611f,0.121f);
    tcircle(35,45);
    glPopMatrix();
}
void t1shad()
{
    glPushMatrix();
    glTranslatef(-20,-60,0);
    glColor3f(0.239f,0.568f,0.101f);
    tcircle(35,45);
    glPopMatrix();
}
void t2()
{
    glPushMatrix();
    glTranslatef(60,-50,0);
    glColor3f(0.262f,0.611f,0.121f);
    tcircle(35,45);
    glPopMatrix();
}
void t2shad()
{
    glPushMatrix();
    glTranslatef(60,-60,0);
    glColor3f(0.239f,0.568f,0.101f);
    tcircle(35,45);
    glPopMatrix();
}
void sun()
{
    glPushMatrix();
    glTranslatef(100,100,0);
    glColor3f(0.968,0.803,0.450);
    drawCircle(20,30);
    glPopMatrix();
}
void brunch1()
{

    glPushMatrix();
    glTranslatef(-20,-50,0);
    glColor3f(0.349f,0.694f,0.2f);
    tcircle(8,16);
    glPopMatrix();
}
void brunch2()
{

    glPushMatrix();
    glTranslatef(-40,-50,0);
    glColor3f(0.349f,0.694f,0.2f);
    tcircle(10,20);
    glPopMatrix();
}
void brunch3()
{

    glPushMatrix();
    glTranslatef(-30,-50,0);
    glColor3f(0.349f,0.694f,0.2f);
    tcircle(5,10);
    glPopMatrix();
}
void brunch4()
{

    glPushMatrix();
    glTranslatef(-55,-50,0);
    glColor3f(0.349f,0.694f,0.2f);
    tcircle(8,16);
    glPopMatrix();

}

void brunch5()
{

    glPushMatrix();
    glTranslatef(-65,-50,0);
    glColor3f(0.349f,0.694f,0.2f);
    tcircle(5,10);
    glPopMatrix();
}

void brunch6()
{

    glPushMatrix();
    glTranslatef(-6,-50,0);
    glColor3f(0.349f,0.694f,0.2f);
    tcircle(10,20);
    glPopMatrix();
}

void brunch7()
{

    glPushMatrix();
    glTranslatef(60,-50,0);
    glColor3f(0.349f,0.694f,0.2f);
    tcircle(8,16);
    glPopMatrix();
}

void brunch8()
{

    glPushMatrix();
    glTranslatef(75,-50,0);
    glColor3f(0.349f,0.694f,0.2f);
    tcircle(10,20);
    glPopMatrix();
}

void brunch9()
{

    glPushMatrix();
    glTranslatef(88,-50,0);
    glColor3f(0.349f,0.694f,0.2f);
    tcircle(5,10);
    glPopMatrix();
}

void brunch10()
{

    glPushMatrix();
    glTranslatef(100,-50,0);
    glColor3f(0.349f,0.694f,0.2f);
    tcircle(8,16);
    glPopMatrix();
}

void sotoghash()
{
    glBegin(GL_TRIANGLES); // DRAWING 3 SIDED TRIANGLE
        glColor3f(0.207f, 0.490f, 0.105f);
        glVertex2d(80.0,-50.0);
        glVertex2d(84.0,-50.0);
        glVertex2d(82.0,-45.0);

        glVertex2d(80.0,-50.0);
        glVertex2d(76.0,-50.0);
        glVertex2d(78.0,-45.0);

        glVertex2d(76.0,-50.0);
        glVertex2d(72.0,-50.0);
        glVertex2d(74.0,-45.0);

        glVertex2d(72.0,-50.0);
        glVertex2d(68.0,-50.0);
        glVertex2d(70.0,-45.0);

        glVertex2d(68.0,-50.0);
        glVertex2d(64.0,-50.0);
        glVertex2d(66.0,-45.0);

        glVertex2d(64.0,-50.0);
        glVertex2d(60.0,-50.0);
        glVertex2d(62.0,-45.0);

        glVertex2d(60.0,-50.0);
        glVertex2d(56.0,-50.0);
        glVertex2d(58.0,-45.0);

        glVertex2d(56.0,-50.0);
        glVertex2d(52.0,-50.0);
        glVertex2d(54.0,-45.0);

        glVertex2d(84.0,-50.0);
        glVertex2d(88.0,-50.0);
        glVertex2d(86.0,-45.0);

        glVertex2d(88.0,-50.0);
        glVertex2d(92.0,-50.0);
        glVertex2d(90.0,-45.0);

        glVertex2d(92.0,-50.0);
        glVertex2d(96.0,-50.0);
        glVertex2d(94.0,-45.0);

        glVertex2d(96.0,-50.0);
        glVertex2d(100.0,-50.0);
        glVertex2d(98.0,-45.0);

        glVertex2d(102.0,-50.0);
        glVertex2d(106.0,-50.0);
        glVertex2d(104.0,-45.0);

        glVertex2d(106.0,-50.0);
        glVertex2d(110.0,-50.0);
        glVertex2d(108.0,-45.0);

        glVertex2d(110.0,-50.0);
        glVertex2d(114.0,-50.0);
        glVertex2d(112.0,-45.0);

        glVertex2d(-40.0,-50.0);
        glVertex2d(-44.0,-50.0);
        glVertex2d(-42.0,-45.0);

        glVertex2d(-44.0,-50.0);
        glVertex2d(-48.0,-50.0);
        glVertex2d(-46.0,-45.0);

        glVertex2d(-48.0,-50.0);
        glVertex2d(-52.0,-50.0);
        glVertex2d(-50.0,-45.0);

        glVertex2d(-52.0,-50.0);
        glVertex2d(-56.0,-50.0);
        glVertex2d(-54.0,-45.0);

        glVertex2d(-56.0,-50.0);
        glVertex2d(-60.0,-50.0);
        glVertex2d(-58.0,-45.0);

        glVertex2d(-60.0,-50.0);
        glVertex2d(-64.0,-50.0);
        glVertex2d(-62.0,-45.0);

        glVertex2d(-64.0,-50.0);
        glVertex2d(-68.0,-50.0);
        glVertex2d(-66.0,-45.0);

        glVertex2d(-68.0,-50.0);
        glVertex2d(-72.0,-50.0);
        glVertex2d(-70.0,-45.0);

        glVertex2d(-40.0,-50.0);
        glVertex2d(-36.0,-50.0);
        glVertex2d(-38.0,-45.0);

        glVertex2d(-36.0,-50.0);
        glVertex2d(-32.0,-50.0);
        glVertex2d(-34.0,-45.0);

        glVertex2d(-32.0,-50.0);
        glVertex2d(-28.0,-50.0);
        glVertex2d(-30.0,-45.0);

        glVertex2d(-28.0,-50.0);
        glVertex2d(-24.0,-50.0);
        glVertex2d(-26.0,-45.0);

        glVertex2d(-24.0,-50.0);
        glVertex2d(-21.0,-50.0);
        glVertex2d(-22.0,-45.0);

        glVertex2d(-18.0,-50.0);
        glVertex2d(-14.0,-50.0);
        glVertex2d(-16.0,-45.0);

        glVertex2d(-14.0,-50.0);
        glVertex2d(-10.0,-50.0);
        glVertex2d(-12.0,-45.0);

        glVertex2d(-10.0,-50.0);
        glVertex2d(-6.0,-50.0);
        glVertex2d(-8.0,-45.0);

        glVertex2d(-6.0,-50.0);
        glVertex2d(-2.0,-50.0);
        glVertex2d(-4.0,-45.0);

    glEnd();
}

void tree5()
{
    glPushMatrix();
    glTranslatef(-30,-28,0);
    //glRotatef(150,0,0,1);
    glColor3f(0.243f,0.482f,0.133f);
    tcircle(3,17);
    glPopMatrix();
}





void tree4()
{
    glPushMatrix();
    glTranslatef(-10,-28,0);
    //glRotatef(150,0,0,1);
    glColor3f(0.243f,0.482f,0.133f);
    tcircle(3,17);
    glPopMatrix();
}





void tree3()
{
    glPushMatrix();
    glTranslatef(-50,-28,0);
    //glRotatef(150,0,0,1);
    glColor3f(0.243f,0.482f,0.133f);
    tcircle(3,17);
    glPopMatrix();
}

void tree2()
{
    glPushMatrix();
    glTranslatef(110,-28,0);
    //glRotatef(150,0,0,1);
    glColor3f(0.243f,0.482f,0.133f);
    tcircle(3,17);
    glPopMatrix();
}


void tree1()
{
    //glTranslatef(65,-30,0);
    //glRotatef(90,0,0,1);
    //glPushMatrix();
    //glPopMatrix();

    glPushMatrix();
    glTranslatef(65,-28,0);
    //glRotatef(150,0,0,1);
    glColor3f(0.243f,0.482f,0.133f);
    tcircle(3,17);
    glPopMatrix();

}
void kando()
{
         glBegin(GL_QUADS);

        glColor3f(0.478f, 0.364f, 0.203f);
        glVertex2d(76.0,-50.0);
        glVertex2d(78.0,-50.0);
        glVertex2d(78.0,-40.0);
        glVertex2d(76.0,-40.0);

        glColor3f(0.478f, 0.364f, 0.203f);
        glVertex2d(89.0,-50.0);
        glVertex2d(91.0,-50.0);
        glVertex2d(91.0,-40.0);
        glVertex2d(89.0,-40.0);

        glColor3f(0.478f, 0.364f, 0.203f);
        glVertex2d(99.0,-50.0);
        glVertex2d(101.0,-50.0);
        glVertex2d(101.0,-45.0);
        glVertex2d(99.0,-45.0);

        glColor3f(0.478f, 0.364f, 0.203f);
        glVertex2d(-20.0,-50.0);
        glVertex2d(-22.0,-50.0);
        glVertex2d(-22.0,-45.0);
        glVertex2d(-20.0,-45.0);

        glColor3f(0.478f, 0.364f, 0.203f);
        glVertex2d(-29.0,-50.0);
        glVertex2d(-31.0,-50.0);
        glVertex2d(-31.0,-44.0);
        glVertex2d(-29.0,-44.0);

        glVertex2d(-38.5,-50.0);
        glVertex2d(-40.5,-50.0);
        glVertex2d(-40.5,-45.0);
        glVertex2d(-38.5,-45.0);

        glVertex2d(-49,-50.0);
        glVertex2d(-51,-50.0);
        glVertex2d(-51,-44.0);
        glVertex2d(-49,-44.0);

         glVertex2d(-9,-50.0);
        glVertex2d(-11,-50.0);
        glVertex2d(-11,-45.0);
        glVertex2d(-9,-45.0);

         glVertex2d(109.0,-50.0);
        glVertex2d(111.0,-50.0);
        glVertex2d(111.0,-45.0);
        glVertex2d(109.0,-45.0);

         glVertex2d(64,-50.0);
        glVertex2d(66,-50.0);
        glVertex2d(66,-45.0);
        glVertex2d(64,-45.0);
       glEnd();
}

void chtr1()
{
    glBegin(GL_TRIANGLES);
    glColor3f(0.211f, 0.407f, 0.133f);
    glVertex2d(-30.0,-4.0);
    glVertex2d(-35.0,-4.0);
    glVertex2d(-32.5, 5.0);

     glColor3f(0.211f, 0.407f, 0.133f);
    glVertex2d(-30.0,-8.0);
    glVertex2d(-35.0,-8.0);
    glVertex2d(-32.5, 1.0);

    glEnd();
}
void chtr2()
{
    glPushMatrix();
    glTranslatef(86,3,0);
    chtr1();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(94,3,0);
    chtr1();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(102,0,0);
    chtr1();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(108,-2,0);
    chtr1();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(28,-2,0);
    chtr1();
    glPopMatrix();
    glPushMatrix();
     glTranslatef(22,2,0);
    chtr1();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(14,4,0);
    chtr1();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(8,2,0);
    chtr1();
    glPopMatrix();

}
void ghash()
{
    glBegin(GL_QUADS); // DRAWING 4 SIDED QUADRILATERAL
    //ghash aka
        glColor3f(0.243f, 0.478f, 0.137f);
        glVertex2d(-200.0,-200.0);
        glVertex2d(200.0,-200.0);
        glVertex2d(200.0,-130.0);
        glVertex2d(-200.0,-130.0);

        glColor3f(0.341f, 0.682f, 0.192f);

         glVertex2d(-200.0,-90.0);
        glVertex2d(200.0,-90.0);
        glVertex2d(200.0, -50.0);
        glVertex2d(-200.0,-50.0);

        glColor3f(0.286f, 0.572f, 0.164f);

         glVertex2d(-200.0,-130.0);
        glVertex2d(200.0,-130.0);
        glVertex2d(200.0, -90.0);
        glVertex2d(-200.0,-90.0);

        glEnd();
}
void akash()
{
    glBegin(GL_QUADS); // DRAWING 4 SIDED QUADRILATERAL

        //AKASHHHH

        glColor3f(0.835f, 0.945f, 1.0f);

        glVertex2d(-200.0,-50.0);
        glVertex2d(200.0,-50.0);
        glVertex2d(200.0, 0.0);
        glVertex2d(-200.0,0.0);

        glColor3f(0.717f, 0.917f, 1.0f);

        glVertex2d(-200.0,0.0);
        glVertex2d(200.0,0.0);
        glVertex2d(200.0, 60.0);
        glVertex2d(-200.0,60.0);

        glColor3f(0.658f, 0.898f, 1.0f);

        glVertex2d(-200.0,60.0);
        glVertex2d(200.0,60.0);
        glVertex2d(200.0, 120.0);
        glVertex2d(-200.0,120.0);

        glColor3f(0.435f, 0.701f, 0.819f);

        glVertex2d(-200.0,120.0);
        glVertex2d(200.0,120.0);
        glVertex2d(200.0, 200.0);
        glVertex2d(-200.0,200.0);

    glEnd();

}
void s_poly()
{
    glBegin(GL_POLYGON); // DRAWING POLYGON
        glColor3f(1.0, 1.0, 0.0); // yellow
        glVertex2f(0.0, 0.0) ;
        glVertex2f(0.0, 3.0) ;
        glVertex2f(4.0, 3.0) ;
        glVertex2f(4.5, 1.5) ;
        glVertex2f(4.0, 0.0);
    glEnd();

}

void cloud(){

    glPushMatrix();
    glTranslatef(-50+x,-50+y,0.0);
    drawCloud();
    glPopMatrix();

}

void cloud1(){

    glPushMatrix();
    glTranslatef(-20+x,-20,0.0);
    drawCloud();
    glPopMatrix();

}
void cloud2()
{
    glPushMatrix();
    glTranslatef(60+x,20,0.0);
    drawCloud();
    glPopMatrix();

}

void cloud3()
{
    glPushMatrix();
    glTranslatef(-195+x,20,0.0);
    drawCloud();
    glPopMatrix();

}
void flower()
{
    glPushMatrix();
    glColor3f(1.0f, 0.0f, 0.0f);
    glTranslatef(0,-115,0);
    drawCircle(2,3);
    glPopMatrix();


    glPushMatrix();
    glColor3f(1.0f, 0.949f, 0.0f);
    glTranslatef(0,-115,0);
    drawCircle(4,5);
    glPopMatrix();


}

void f1()
{
    glPushMatrix();
    glColor3f(1.0f, 0.0f, 0.0f);
    glTranslatef(-12,0,0);
    flower();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0f, 0.0f, 0.0f);
    glTranslatef(-24,0,0);
    flower();
    glPopMatrix();

}

void flower1()
{
     glPushMatrix();
    glColor3f(1.0f, 0.949f, 0.0f);
    glTranslatef(100,-115,0);
    drawCircle(2,3);
    glPopMatrix();


    glPushMatrix();
    glColor3f(1.0f, 0.0f, 0.501f);
    glTranslatef(100,-115,0);
    drawCircle(4,5);
    glPopMatrix();


}

void f2()
{
    glPushMatrix();
   // glColor3f(1.0f, 0.0f, 0.0f);
    glTranslatef(-12,0,0);
    flower1();
    glPopMatrix();

    glPushMatrix();
    //glColor3f(1.0f, 0.0f, 0.0f);
    glTranslatef(-24,0,0);
    flower1();
    glPopMatrix();

}

void flower2()
{
     glPushMatrix();
    glColor3f(1.0f, 0.949f, 0.0f);
    glTranslatef(-80,-75,0);
    drawCircle(2,3);
    glPopMatrix();


    glPushMatrix();
    glColor3f(1.0f, 0.501f, 1.0f);
    glTranslatef(-80,-75,0);
    drawCircle(4,5);
    glPopMatrix();


}

void f3()
{
    glPushMatrix();
    //glColor3f(1.0f, 0.0f, 0.0f);
    glTranslatef(-12,0,0);
    flower2();
    glPopMatrix();

    glPushMatrix();
    //glColor3f(1.0f, 0.0f, 0.0f);
    glTranslatef(-24,0,0);
    flower2();
    glPopMatrix();

}

void flower3()
{
     glPushMatrix();
    glColor3f(1.0f, 0.501f, 1.0f);
    glTranslatef(70,-75,0);
    drawCircle(2,3);
    glPopMatrix();


    glPushMatrix();
    glColor3f(1.0f, 0.501f, 0.0f);
    glTranslatef(70,-75,0);
    drawCircle(4,5);
    glPopMatrix();


}

void f4()
{
    glPushMatrix();
    //glColor3f(1.0f, 0.0f, 0.0f);
    glTranslatef(-12,0,0);
    flower3();
    glPopMatrix();

    glPushMatrix();
    //glColor3f(1.0f, 0.0f, 0.0f);
    glTranslatef(-24,0,0);
    flower3();
    glPopMatrix();

}

void grass()
{
    glBegin(GL_TRIANGLES); // DRAWING 3 SIDED TRIANGLE
        glColor3f(0.298f, 0.564f, 0.035f);
        glVertex2d(60.0,-165.0);
        glVertex2d(63,-155.0);
        glVertex2d(66.0,-165.0);

        glVertex2d(65.0,-165.0);
        glVertex2d(68.5,-148.0);
        glVertex2d(72.0,-165.0);

        glVertex2d(71.0,-165.0);
        glVertex2d(73,-145.0);
        glVertex2d(76.0,-165.0);

         glVertex2d(75.0,-165.0);
        glVertex2d(77,-147.0);
        glVertex2d(81.0,-165.0);
    glEnd();
}

void grass1()
{
    glPushMatrix();
    glTranslatef(-134,0,0);
    grass();
    glPopMatrix();

     glPushMatrix();
    glTranslatef(-154,35,0);
    grass();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(40,35,0);
    grass();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-134,75,0);
    grass();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-70,75,0);
    grass();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(20,75,0);
    grass();
    glPopMatrix();
}



void display(){

	//clear the display

	glClearColor(0,0,0,0);	//color black
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/********************
	/ set-up camera here
	********************/
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


	/****************************
	/ Add your objects from here
	****************************/
	//add objects

	//drawAxes();
	//drawGrid();
	//point();
	//pointsMany(100);
	//lines();
	cloud();
	cloud1();
	cloud2();
	cloud3();
	s_triangle();
	home();
	sotoghash();
	kando();
	f1();
	flower();
	f2();
	flower1();
	f3();
	flower2();
	f4();
	flower3();
	just_line();
	grass();
	grass1();
	ghash();
	tree1();
	tree2();
	tree3();
	tree4();
	tree5();
	brunch1();
	brunch2();
	brunch3();
	brunch4();
	brunch5();
	brunch6();
	brunch7();
	brunch8();
	brunch9();
	brunch10();
	t1shad();
	t1();
	t2shad();
	t2();
	chtr1();
	chtr2();
	Hill();
	sun();
	akash();
	//s_poly();




	//ADD this line in the end --- if you use double buffer (i.e. GL_DOUBLE)
	/*
	Another decision you need to make when setting up the display mode is whether you want to use single buffering (GLUT_SINGLE)
    or double buffering (GLUT_DOUBLE). Applications that use both front and back color buffers are double-buffered. Smooth animation
    is accomplished by rendering into only the back buffer (which isn't displayed), then causing the front and back buffers to be swapped.
    If you aren't using annimation, stick with single buffering, which is the default.
	*/
	glutSwapBuffers();
}


void animate(){
	//angle+=0.05;
	x+=0.025;
	y+=0.025;

	//codes for any changes in Models, Camera
	glutPostRedisplay();
}

void init(){
	//codes for initialization
	//drawgrid=0;
	drawaxes=1;
	//cameraHeight=150.0;
	//cameraAngle=1.0;

	//clear the screen
	glClearColor(0,0,0,0);

	/************************
	/ set-up projection here
	************************/
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
}

int main(int argc, char **argv){
	glutInit(&argc,argv);
	glutInitWindowSize(1000, 600);
	glutInitWindowPosition(0, 0);
	/*
	The next thing we need to do is call the glutInitDisplayMode() procedure to specify the display mode for a window. You must first decide whether you want to use an RGBA (GLUT_RGBA) or color-index (GLUT_INDEX) color model.
	The RGBA mode stores its color buffers as red, green, blue, and alpha color components. The forth color component, alpha, corresponds to the notion of opacity. An alpha value of 1.0 implies complete opacity, and an alpha value of 0.0 complete transparancy.
    Color-index mode, in contrast, stores color buffers in indicies. Your decision on color mode should be based on hardware availability and what you application requires. More colors can usually be simultaneously represented with
    RGBA mode than with color-index mode. And for special effects, such as shading, lighting, and fog, RGBA mode provides more flexibility. In general, use RGBA mode whenever possible. RGBA mode is the default.
	*/
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);	//Depth, Double buffer, RGB color

	glutCreateWindow("My OpenGL Program");

	init();

	glEnable(GL_DEPTH_TEST);	//enable Depth Testing

	glutDisplayFunc(display);	//display callback function
	glutIdleFunc(animate);		//what you want to do in the idle time (when no drawing is occuring)



	glutMainLoop();		//The main loop of OpenGL

	return 0;
}
