#include <GL/glut.h>
#include <stdio.h>
int n=1;
float scale=1;
int angley=-0.5;
int anglex;
int tranx,trany;
int count;
int randomColorFlag;
#define BLACK 0
#define WHITE 1
#define RED 2
#define GREEN 3
#define BLUE 4
#define RANDOM 5
#define EXIT_YES 1
#define EXIT_NO 0
#define AUDI 1
#define OLYMPICS 2
int rotationx,rotationy,scaling,translation;
void init2();
void myinit()
{
	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0,1000,0,1000,-10,10); 
     glMatrixMode(GL_MODELVIEW);
}


void resize(int width, int height)
{ 
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10,10,-10,10,-10,10); 
     glMatrixMode(GL_MODELVIEW);
    
} 
void drawolym()
{
	    
	    glColor3d(0,0,1); 
        glPushMatrix();
       glTranslated(-2.7,0,0);
        glRotated(-10, 1.0, 0.0, 0.0);
        glutSolidTorus(0.1, 1.2, 10, 50);
        glPopMatrix(); 
        
	    glColor3d(0,0,0); 
        glPushMatrix();
        glTranslated(0,0,0);
        glRotated(-10, 1.0, 0.0, 0.0);
        glutSolidTorus(0.1, 1.2, 10, 50);
        glPopMatrix(); 
  
        glColor3d(1,0,0);
         glPushMatrix();
        glTranslated(2.7,0,0);
        glRotated(-10, 1.0, 0.0, 0.0);
        glutSolidTorus(0.1, 1.2, 10, 50);
        glPopMatrix(); 
  
       glColor3d(1,1,0);
       glPushMatrix();
       glTranslated(-1.35,-1.4,0);
       glRotated(-10, 1.0, 0.0, 0.0);
       glutSolidTorus(0.1, 1.2, 10, 50);
       glPopMatrix(); 
   
      glColor3d(0,1,0);
      glPushMatrix();
       glTranslated(1.35,-1.4,0);
       glRotated(-10, 1.0, 0.0, 0.0);
       glutSolidTorus(0.1, 1.2, 10, 50);
       glPopMatrix(); 
    
 }
 void drawaudi()
{
	    glColor3d(0.5,.5,.5); 
	    
        glPushMatrix();
        glTranslated(-1.2,0,0);
        glRotated(-10, 1.0, 0.0, 0.0);
        glutSolidTorus(0.2, 0.8, 10, 50);
        glPopMatrix(); 
        
        glPushMatrix();
        glTranslated(0.0,0,0);
        glRotated(-10, 1.0, 0.0, 0.0);
        glutSolidTorus(0.2, 0.8, 10, 50);
        glPopMatrix(); 
  
     glPushMatrix();
        glTranslated(1.2,0,0);
        glRotated(-10, 1.0, 0.0, 0.0);
                 glutSolidTorus(0.2, 0.8, 10, 50);
    glPopMatrix(); 
   
    glPushMatrix();
        glTranslated(2.4,0,0);
        glRotated(-10, 1.0, 0.0, 0.0);
        glutSolidTorus(0.2, 0.8, 10, 50);
    glPopMatrix(); 
    
 }
 void processBgColor(int option)
{
	switch(option)
	{
		case BLACK:	glClearColor(0,0,0,0);randomColorFlag=0;break;
		case WHITE:	glClearColor(1,1,1,0);randomColorFlag=0;break;
		case RED:		glClearColor(1,0,0,0);randomColorFlag=0;break;
		case GREEN:	glClearColor(0,1,0,0);randomColorFlag=0;break;
		case BLUE:		glClearColor(0,0,1,0);randomColorFlag=0;break;
		case RANDOM:	randomColorFlag = 1;break;
	}
	glutPostRedisplay();
}
 

void display1(void)
{ 
 if(((count = count % 50) == 0) && randomColorFlag)
		glClearColor((rand()%100)/100.0,(rand()%100)/100.0,(rand()%100)/100.0,0);
		count++;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    if(translation)
    glTranslatef(tranx,trany,0);
    if(rotationx)
    glRotatef(anglex++,1,0,0);
     if(rotationy)
    glRotatef(angley++,0,1,0);
    if(scaling)
    glScalef(scale,scale,scale);
    drawaudi();
    glPopMatrix();
 
    glutSwapBuffers();
} 
void display2(void)
{ 
 if(((count = count % 50) == 0) && randomColorFlag)
		glClearColor((rand()%100)/100.0,(rand()%100)/100.0,(rand()%100)/100.0,0);
		count++;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    if(translation)
    glTranslatef(tranx,trany,0);
    if(rotationx)
    glRotatef(anglex++,1,0,0);
     if(rotationy)
    glRotatef(angley++,0,1,0);
    if(scaling)
    glScalef(scale,scale,scale);
    drawolym();
    glPopMatrix();
 
    glutSwapBuffers();
} 
 

void keys(unsigned char key,int x,int y)
{
switch(key)
{
	case 'x': scale+=.1; break;
	case 'y': scale-=.1; break;
	case 'w': trany++; break;
	case 's': trany--;break;
	case 'a':tranx--;break;
	case 'd':tranx++;break;
}
}
void processMenuSymbol(int num)
{
	n = num;
	glutPostRedisplay();
}
void processMainMenu2()
{
	
}

void processMenuMain1()
{
	
}
void processMenuExit(int option)
{
	if(EXIT_YES) exit(0);
}
void createGLUTMenus1()
{
	int menu = glutCreateMenu(processMenuSymbol);
	glutAddMenuEntry("AUDI",1);
	glutAddMenuEntry("OLMYPICS",2);
	
	int menuExit = glutCreateMenu(processMenuExit);
	glutAddMenuEntry("Yes",0);
	glutAddMenuEntry("No",1);
	glutCreateMenu(processMenuMain1);
	glutAddSubMenu("CHOOSE LOGO",menu);
	glutAddSubMenu("Exit",menuExit);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}
 void processMenuRot(int option)
 {
	 if(option==1)
	 {
		 rotationx=1;
		 anglex=0;
		 rotationy=translation=scaling=0;
	 }
	 if(option==2)
	 {
		 rotationy=1;
		 angley=0;
		 rotationx=translation=scaling=0;
	 }
	 
	 
}

void dummy(int option)
{
	switch(option)
	{
		case 2: scaling=1;
		scale=1;
		rotationx=translation=rotationy=0;
		break;
		case 3: translation=1;
		tranx=trany=0;
		rotationx=scaling=rotationy=0;
	}
		
}
void createGLUTMenus2()
{
	int menurot = glutCreateMenu(processMenuRot);
	glutAddMenuEntry("X",1);
	glutAddMenuEntry("Y",2);
	
	int menuExit = glutCreateMenu(processMenuExit);
	glutAddMenuEntry("Yes",0);
	glutAddMenuEntry("No",1);
	
	int menuBgColor = glutCreateMenu(processBgColor);
	glutAddMenuEntry("Black",BLACK);
	glutAddMenuEntry("White",WHITE);
	glutAddMenuEntry("Red",RED);
	glutAddMenuEntry("Green",GREEN);
	glutAddMenuEntry("Blue",BLUE);
	glutAddMenuEntry("Random",RANDOM);
    
    glutCreateMenu(dummy);
	glutAddSubMenu("ROTATION",menurot);
	glutAddMenuEntry("SCALING",2);
	glutAddMenuEntry("TRASLATION",3);
	glutAddSubMenu("CHANGE BG COLOR",menuBgColor);
	glutAddSubMenu("Exit",menuExit);
	
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}
void strokeString(float x,float y,float sx,float sy,char *string,int width)
{
	char *c;
	glLineWidth(width);
	glPushMatrix();
	glTranslatef(x,y,0);
	glScalef(sx,sy,0);
	for (c=string; *c != '\0'; c++) 
	{
		glutStrokeCharacter(GLUT_STROKE_ROMAN, *c);
	}
	glPopMatrix();
}
 
void first()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0,1,0);
	strokeString(50,850,0.15,0.15,"BANGALORE INSTITUTE OF TECHNOLOGY",2);
	strokeString(100,750,0.3,0.3,"DEPARTMENT OF COMPUTER SCIENCE",4);
	strokeString(300,670,0.3,0.3,"AND ENGINEERING",4);
	strokeString(200,500,0.3,0.3,"AN OPENGL MINI PROJECT ON",2);
	glColor3f(0.5,0.5,1);
	strokeString(170,420,0.4,0.4,"SIMULATION OF LOGO'S",6);
	glColor3f(0.5,0.5,1);
	strokeString(200,220,0.2,0.2,"LOGO SELECTED :",3);
	glColor3f(0,0.5,1);
	if(n==1)
	strokeString(450,220,0.2,0.2,"AUDI",3);
	if(n==2)
	strokeString(450,220,0.2,0.2,"OLYMPICS",3);
	strokeString(50,100,0.17,0.17,"1 . SELECT THE LOGO TO BE DISPLAYED ",2);
	strokeString(50,50,0.17,0.17,"2 . Press (Enter) to start the simulation",2);
	strokeString(650,200,0.15,0.15,"By:",2);
	glColor3f(0,0.5,1);
	strokeString(650,160,0.18,0.18,"BHARHAV.C",2);
	strokeString(650,60,0.18,0.18,"Prof K.J Bhanushree",2);
	strokeString(650,35,0.18,0.18,"Prof Maya B S",2);
	strokeString(650,10,0.18,0.18,"Prof N THANUJA",2);
	glColor3f(1,0,0);
	strokeString(650,120,0.18,0.18,"1BI13CS036",2);
	strokeString(650,90,0.14,0.14,"Under the guidance of.",2);	
	glutSwapBuffers();
}
void keyboard2(unsigned char c, int x, int y)
{
	switch(c)
	{
		case 13:
			init2();
			if(n==1)
			{
			glutDisplayFunc(display1);
			glutIdleFunc(display1);
			}
			
			if(n==2)
			{
			 glutDisplayFunc(display2);
			 glutIdleFunc(display2);
		    }
			createGLUTMenus2();
			glutReshapeFunc(resize);
			
			glutKeyboardFunc(keys);
			
			
		break;
	}
	glutPostRedisplay();
}

 void lightshow()
 {
	 const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 0, 0, 5.0f, 0.0f }; 
 
const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f }; 


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
 }
void init2()
{
	 glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10,10,-10,10,-10,10); 
     glMatrixMode(GL_MODELVIEW);
     lightshow();
      glClearColor(0.2,.20,0.2,0);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK); 
 }
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(1000,1000);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); 
 
    glutCreateWindow("LOGO'S MENU - 1BI13CS036"); 
     myinit();
     glutDisplayFunc(first);
	createGLUTMenus1();
	glutKeyboardFunc(keyboard2);
    glutMainLoop(); 
 
    return EXIT_SUCCESS;
}
