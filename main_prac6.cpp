//Semestre 2019 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//******************** GALVÁN HERNÁNDEZ KARINA	**************//
//******************** VISUAL STUDIO 2017 ********************//
//************************************************************//
#include "Main.h"


// Variables used to calculate frames per second: (Windows)
DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime = 0;
DWORD dwElapsedTime = 0;


//Variables used to create movement
int p = 0; //proton
int e1 = 0; //electron 1
int e2 = 0; //electron 2
int e3 = 0; //electron 3
int e4 = 0; //electron 4
int e5 = 0; //electron 5
int e6 = 0; //electron 6

float camaraZ = 0.0;
float camaraX = 0.0;
float camaraY = 0.0;

GLfloat SunDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };			// Diffuse Light Values
GLfloat SunSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat SunPosition[] = { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position



void InitGL(GLvoid)     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);


}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(camaraX, camaraY, -5.0 + camaraZ);			//camara


	glPushMatrix(); //proton
	glRotatef(p, 0.0, 1.0, 0.0); 
	glColor3f( 0, 1, 1);
	glutSolidSphere(1.9, 20, 20); 

	//aqui comienzan las orbitas
	glPushMatrix();
	glPushMatrix();

	glColor3f(1.9, 1.0, 1.0);
	glutSolidTorus(.03, 5, 10, 50); //orbita 1
	glRotatef(90, 1, 0, 0);
	glutSolidTorus(.03, 5, 10, 50); //orbita 2
	glRotatef(90, 0, 1, 0);
	glutSolidTorus(.03, 5, 10, 50); //orbita 3
	glRotatef(45, 0, 1, 0);
	glutSolidTorus(.03, 5, 10, 50); //orbita 4
	glRotatef(90, 0, 1, 0);
	glutSolidTorus(.03, 5, 10, 50); //orbita 5
	glRotatef(105, 0, 1, 0);
	glutSolidTorus(.03, 5, 10, 50); //orbita 6

	glPopMatrix();

	glPushMatrix(); //primer electron
	glRotatef(150, 0, 0, 1);
	glRotatef(e1, 0, 1, 0);
	glTranslatef(5, 0, 0);
	glColor3f(1, 0, 0);
	glutSolidSphere(0.3, 20, 20);
	glPopMatrix();
	
	glPushMatrix(); //segundo electron
	glRotatef(45, 0, 0, 1);
	glRotatef(e2, 1, 0, 0);
	glTranslatef(0, 5, 0);
	glColor3f(1, 0, 1);
	glutSolidSphere(0.3, 20, 20);
	glPopMatrix();

	glPushMatrix(); //tercer electron
	glRotatef(45, 0, 0, 1);
	glRotatef(e3, 0, 1, 0);
	glTranslatef(5, 0, 0);
	glColor3f(0, 1, 0);
	glutSolidSphere(0.3, 20, 20);
	glPopMatrix();
	
	glPushMatrix(); //cuarto electron 
	glRotatef(90, 0, 0, 1);
	glRotatef(e4, 0, 1, 0);
	glTranslatef(-5, 0, 0);
	glColor3f(1, 0.5, 0);
	glutSolidSphere(0.3, 20, 20);
	glPopMatrix();
	
	glPushMatrix(); //quinto electron 
	glRotatef(45, 0, 1, 0);
	glRotatef(e5, 0, 1, 0);
	glTranslatef(5, 0, 0);
	glColor3f(1.5, 1.5, 0);
	glutSolidSphere(0.3, 20, 20);
	glPopMatrix();

	glPushMatrix(); //sexto electron
	glRotatef(180, 1, 1, 0);
	glRotatef(e6, 0, 0, 1);
	glTranslatef(0, -5, 0);
	glColor3f(0, 0, 1);
	glutSolidSphere(0.3, 20, 20);
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
		p = (p - 1) % 360; //velocidad del proton
		e1 = (e1 + 1) % 360; //velocidad del electron 1
		e2 = (e2 - 2) % 360; //velocidad del electron 2
		e3 = (e3 + 1) % 360; //velocidad del electron 3
		e4 = (e4 - 3) % 360; //velocidad del electron 4
		e5 = (e5 + 1) % 360; //velocidad del electron 5
		e6 = (e6 - 4) % 360; //velocidad del electron 6
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
		camaraY -= 0.5f;
		break;
	case 'k':
	case 'K':
		camaraY += 0.5f;
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
	glutInitWindowSize(600, 600);	// Tamaño de la Ventana
	glutInitWindowPosition(30, 60);	//Posicion de la Ventana
	glutCreateWindow("Practica 6"); // Nombre de la Ventana
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutIdleFunc(animacion);
	glutMainLoop();          // 

	return 0;
}