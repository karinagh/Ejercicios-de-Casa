//Semestre 2019 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//******************** GALVÁN HERNÁNDEZ KARINA ***************//
//******************** VISUAL STUDIO 2017 ********************//
//************************************************************//
#include "Main.h"


// Variables used to calculate frames per second: (Windows)
DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime = 0;
DWORD dwElapsedTime = 0;


//Variables used to create movement

int sol = 0;
int mercurio = 0;
int venus = 0;
int tierra = 0;
int conejo = 0;
int marte = 0;
int lunau = 0;
int jupiter = 0;
int urano = 0;
int saturno = 0;
int neptuno = 0;
int pluton = 0;

int satelite = 0;
int satelite2 = 0;
float camaraZ = 0.0;
float camaraX = 0.0;

GLfloat SolDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };			// Diffuse Light Values
GLfloat SolSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat SolPosition[] = { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position

GLfloat MercurioDiffuse[] = { 2.0f, 2.0f, 2.0f, 1.0f };	// Mercurio
GLfloat MercurioSpecular[] = { 3.0, 3.5, 3.5, 1.0 };
GLfloat MercurioShininess[] = { 50.0 };

GLfloat VenusDiffuse[] = { 0.7f, 0.7f, 2.5f, 1.0f };	// Venus
GLfloat VenusSpecular[] = { 2.0, 2.5, 2.5, 1.0 };
GLfloat VenusShininess[] = { 50.0 };

GLfloat TierraDiffuse[] = { 0.2f, 0.2f, 1.0f, 1.0f };	// Tierra
GLfloat TierraSpecular[] = { 0.3, 0.3, 0.3, 1.0 };
GLfloat TierraShininess[] = { 50.0 };

GLfloat ConejoDiffuse[] = { 0.5f, 0.5f, 0.5f, 1.0f };	// Luna (Conejo)
GLfloat ConejoSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat ConejoShininess[] = { 50.0 };

GLfloat MarteDiffuse[] = { 0.9f, 0.5f, 0.1f, 1.0f };	// Marte
GLfloat MarteSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat MarteShininess[] = { 50.0 };

GLfloat JupiterDiffuse[] = { 0.3f, 0.5f, 0.1f, 1.0f };	// Jupiter
GLfloat JupiterSpecular[] = { 3.0, 2.5, 0.0, 1.0 };
GLfloat JupiterShininess[] = { 50.0 };

GLfloat SaturnoDiffuse[] = { 0.5f, 1.3f, 1.2f, 1.0f };	// Saturno
GLfloat SaturnoSpecular[] = { 5.0, 3.5, 0.0, 1.0 };
GLfloat SaturnoShininess[] = { 50.0 };

GLfloat UranoDiffuse[] = { 2.0f, 2.5f, 0.2f, 1.0f };	// Urano
GLfloat UranoSpecular[] = { 1.0, 0.0, 1.0, 1.0 };
GLfloat UranoShininess[] = { 50.0 };

GLfloat NeptunoDiffuse[] = { 7.0f, 5.0f, 3.0f, 1.0f };	// Neptuno
GLfloat NeptunoSpecular[] = { 4.0, 2.0, 2.0, 1.0 };
GLfloat NeptunoShininess[] = { 50.0 };

GLfloat PlutonDiffuse[] = { 1.5f, 4.0f, 3.0f, 1.0f };	// Pluton
GLfloat PlutonSpecular[] = { 1.0, 2.0, 2.0, 1.0 };
GLfloat PlutonShininess[] = { 50.0 };


void InitGL(GLvoid)     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT1);

	glLightfv(GL_LIGHT1, GL_DIFFUSE, SolDiffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, SolDiffuse);

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);


}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(camaraX, 0.0, -5.0 + camaraZ);	


	glPushMatrix();//sol
	glPushMatrix();
	glRotatef(sol, 0.0, 1.0, 0.0);	
	glColor3f(1.0, 1.0, 0.0);	
	glLightfv(GL_LIGHT1, GL_POSITION, SolPosition);
	glDisable(GL_LIGHTING);
	glutSolidSphere(1.9, 20, 20);  
	glEnable(GL_LIGHTING);

	
	glPushMatrix();//Mercurio
	glRotated(sol, 0, 1, 0);
	glTranslatef(3.2, 0, 0);
	glColor3f(2, 0.5, 1);
	glRotated(mercurio, 0, 1, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MercurioDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MercurioSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MercurioShininess);
	glutSolidSphere(0.3, 20, 20);
	glPopMatrix();

	glPushMatrix();//venus
	glRotated(sol, 0, 1, 0);
	glTranslatef(5.5, 0, 0);
	glColor3f(0.37 ,0.56,0.56); 
	glRotated(venus, 0, 2, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, VenusDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, VenusSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, VenusShininess);
	glutSolidSphere(0.4, 20, 20);
	glPopMatrix();

	glPushMatrix(); //tierra
	glRotatef(sol, 0, 1, 0);
	glTranslatef(7.7, 0, 0);
	glRotatef(tierra, 0, 1, 0);
	glColor3f(0.0, 0.5, 1.0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, TierraDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, TierraSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, TierraShininess);
	glutSolidSphere(0.6, 20, 20);
	glPopMatrix();

	glPushMatrix(); //conejo
	glRotatef(tierra, 0, 1, 0);
	glTranslatef(8.7, 0, 0);
	glRotatef(tierra, 0, 1, 0);
	glColor3f(0.7, 0.7, 0.7);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, ConejoDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, ConejoSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, ConejoShininess);
	glutSolidSphere(0.2, 20, 20);
	glPopMatrix();

	glPopMatrix();

	glPushMatrix(); //marte
	glRotatef(marte, 0, 1, 0);
	glTranslatef(11.5, 0, 0);
	glRotatef(marte, 0, 1, 0);
	glColor3f(1.0, 0, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MarteDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MarteSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MarteShininess);
	glutSolidSphere(0.5, 20, 20);
	glPopMatrix();

	glPushMatrix(); //luna uno (lunau)
	glRotatef(marte, 0, 1, 0);
	glTranslatef(12.5, 0, 0);
	glRotatef(marte, 0, 1, 0);
	glColor3f(0.7, 0.7, 0.7);
	glutSolidSphere(0.2, 20, 20);
	glPopMatrix();

	glPushMatrix(); //jupiter
	glRotatef(jupiter, 0, 1, 0);
	glTranslatef(16, 0, 0);
	glRotatef(jupiter, 0, 1, 0); //(45,1,0,0)
	glColor3f(0.3, 0.2, 0.2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, JupiterDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, JupiterSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, JupiterShininess);
	glutSolidSphere(0.8, 20, 20); //primer variable indica el tamano, los dos ultimos numeros mientras mas grandes mas esferico se volver el cuerpo
	glPopMatrix();

	glPushMatrix(); //satelite1
	glRotated(satelite, 0, 1, 0);
	glTranslatef(18, 0, 0);
	glColor3f(1, 1, 1);
	glRotated(satelite, 0, 1, 0);
	glutSolidSphere(0.1, 20, 20);
	glPopMatrix();

	glPushMatrix();//satelite2
	glRotated(satelite2, 0, 1, 0);
	glTranslatef(20, 0, 0);
	glColor3f(1, 1, 1);
	glRotated(satelite2, 1, 0, 0);
	glutSolidSphere(0.2, 20, 20);
	glPopMatrix();

	glPopMatrix();


	glPushMatrix(); //saturno
	glRotated(saturno, 0, 2, 0);
	glTranslatef(22, 0, 0);
	glColor3f(1, 0.5, 0);
	glRotated(saturno, 0, 2, 0);
	glPushMatrix();

	glutSolidTorus(0.1, 3, 10, 50);

	glPopMatrix();
	glColor3f(1, 0.5, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, SaturnoDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, SaturnoSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, SaturnoShininess);
	glutSolidSphere(1.8, 20, 20);
	glPopMatrix();


	glPushMatrix(); //urano
	glRotated(urano, 0, 2, 0);
	glTranslatef(26, 0, 0);
	glColor3f(0.0, 0.0, 0.9);
	glRotated(urano, 0, 2, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, UranoDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, UranoSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, UranoShininess);
	glutSolidSphere(1.6, 20, 20);
	glPopMatrix();


	glPushMatrix(); //neptuno
	glRotated(neptuno, 0, 2, 0);
	glTranslatef(30, 0, 0);
	glColor3f(0, 1, 1);
	glRotated(neptuno, 0, 2, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, NeptunoDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, NeptunoSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, NeptunoShininess);
	glutSolidSphere(1.4, 20, 20);
	glPopMatrix();

	glPushMatrix(); //pluton
	glRotated(pluton, 0, 2, 0);
	glTranslatef(35, 0, 0);
	glColor3f(0.1, 0.1, 0.1);
	glRotated(pluton, 0, 2, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, PlutonDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, PlutonSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, PlutonShininess);
	glutSolidSphere(1.2, 20, 20);
	glPopMatrix();


	glPopMatrix();
	glPopMatrix();
	glutSwapBuffers();

}

void animacion()
{
	// Calculate the number of frames per one second:
	//dwFrames++;
	dwCurrentTime = GetTickCount(); // Even better to use timeGetTime()
	dwElapsedTime = dwCurrentTime - dwLastUpdateTime;

	if (dwElapsedTime >= 30)
	{
		sol = (sol - 1) % 360;

		mercurio = (mercurio - 1) % 360;
		venus = (venus - 1) % 360;
		tierra = (tierra - 1) % 360;
		conejo = (conejo - 3) % 360;
		marte = (marte - 1) % 360;
		lunau = (lunau - 2) % 360;
		jupiter = (jupiter - 1) % 360;
		saturno = (saturno - 1) % 360;
		urano = (urano - 1) % 360;
		neptuno = (neptuno - 1) % 360;
		satelite = (satelite - 3) % 360;
		satelite2 = (satelite2 + 3) % 360;
		pluton = (pluton - 1) % 360;
		dwLastUpdateTime = dwCurrentTime;
	}

	glutPostRedisplay();
}

void reshape(int width, int height)   // Creamos funcion Reshape
{
	if (height == 0)										// Prevenir division entre cero
	{
		height = 1;
	}

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista

	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	//glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
	case 'w':   //Movimientos de camara
	case 'W':
		camaraZ += 0.5f;
		break;
	case 's':
	case 'S':
		camaraZ -= 0.5f;
		break;
	case 'a':
	case 'A':
		camaraX -= 0.5f;
		break;
	case 'd':
	case 'D':
		camaraX += 0.5f;
		break;

	case 'i':		//Movimientos de Luz
	case 'I':

		break;
	case 'k':
	case 'K':

		break;

	case 'l':   //Activamos/desactivamos luz
	case 'L':
		break;
	case 27:        // Cuando Esc es presionado...
		exit(0);   // Salimos del programa
		break;
	default:        // Cualquier otra
		break;
	}
	glutPostRedisplay();
}

void arrow_keys(int a_keys, int x, int y)  // Funcion para manejo de teclas especiales (arrow keys)
{
	switch (a_keys) {
	case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...

		break;
	case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...

		break;
	case GLUT_KEY_LEFT:

		break;
	case GLUT_KEY_RIGHT:

		break;
	default:
		break;
	}
	glutPostRedisplay();
}


int main(int argc, char** argv)   // Main Function
{
	glutInit(&argc, argv); // Inicializamos OpenGL
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
	glutInitWindowSize(500, 500);	// Tamaño de la Ventana
	glutInitWindowPosition(20, 60);	//Posicion de la Ventana
	glutCreateWindow("Practica 7"); // Nombre de la Ventana
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutIdleFunc(animacion);
	glutMainLoop();          // 

	return 0;
}