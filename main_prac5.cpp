//Semestre 2019 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//******************* GALVÁN HERNÁNDEZ KARINA ****************//
//******************* VISUAL STUDIO 2017 *********************//
//************************************************************//
#include "Main.h"

float transZ = -5.0f;
float transX = 0.0f;
float angleX = 0.0f;
float angleY = 0.0f;
int screenW = 0.0;
int screenH = 0.0;


float angHombro;
float angCodo;
float angPalma;
float angMano;
float angDedos;
float angTorso;
float angHombroI;
float angCodoI;
float angPalmaI;
float angManoI;
float angDedosI;
float angPierna;
float angCabeza;
float angPiernaB;

GLfloat Position[] = { 0.0f, 3.0f, 0.0f, 1.0f };			// Light Position
GLfloat Position2[] = { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

void InitGL(void)     // Inicializamos parametros
{

	glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing

	//Configuracion luz
	glLightfv(GL_LIGHT0, GL_POSITION, Position);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);


	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glEnable(GL_COLOR_MATERIAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void prisma(void)
{
	GLfloat vertice[8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
	};

	glBegin(GL_POLYGON);	//Front
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[1]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Left
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Bottom
	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[2]);
	glVertex3fv(vertice[3]);
	glEnd();

	glBegin(GL_POLYGON);  //Top
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[7]);
	glEnd();
}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limpiamos pantalla y Depth Buffer
	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(transX, 0.0f, transZ);
	glRotatef(angleY, 0.0, 1.0, 0.0);
	glRotatef(angleX, 1.0, 0.0, 0.0);
	//Poner Código Aquí. (0,0,0)


	glPushMatrix();    //DIBUJA BRAZO
		glTranslatef(-2.5, 1.25, 0); //(-2.5, 1.25, 0); TRASLACION A ESTE PUNTO DEL CUADRANTE
		glRotatef(angHombro, 0, 0, 1);
		glPushMatrix();//COMIENZA A DIBUJAR HOMBRO
		glTranslatef(2.8, 1.25, 0); //(0,0,0) TRASLACION AL ORIGEN
		glScalef(5, 2.5, 5);
		prisma();
	glPopMatrix();
	glPushMatrix();    //ANTEBRAZO DERECHO
		glTranslatef(-1, 0, 0);
		glRotatef(angCodo, 0, 0, 1);
		glPushMatrix();//COMIENZA A DIBUJAR ANTEBRAZO DERECHO
		glTranslatef(8, 1.25, 0);
		glScalef(6, 2.5, 3);
		prisma();
	glPopMatrix();
	glPushMatrix();    //PALMA
		glTranslatef(9.4, 0, 0);
		glRotatef(angPalma, 0, 1, 0);
		glPushMatrix();//COMIENZA  DIBUJAR LA PALMA
		glTranslatef(2.5, 1.25, 0);
		glScalef(2, 2, 2);
		prisma();
	glPopMatrix();
	glPushMatrix();    //DEDO PULGAR
		glTranslatef(9.4, 1.5, 0);
		glRotatef(angMano, 1, 0, 0);
		glPushMatrix();//COMIENZA  DIBUJAR DEDO PULGAR
		glTranslatef(2.5, 1, 0);
		glScalef(0.5, 1, 0.5);
		prisma();
	glPopMatrix();
		glRotatef(angMano, 1, 0, 0);
	glPushMatrix();//COMIENZA  DIBUJAR LA SIGUIENTE FALANGE DEL DEDO PULGAR
		glTranslatef(11.9, 3.4, 0);
		glScalef(0.5, 1, 0.5);
		prisma();
	glPopMatrix();
	glPushMatrix();    //DEDO INDICE
		glTranslatef(10.9, 1.5, 0);
		glRotatef(angDedos, 0, 1, 0);
		glPushMatrix();//COMIENZA  DIBUJAR DEDO INDICE
		glTranslatef(2.5, 1, 0);
		glScalef(1, 0.5, 0.5);
		prisma();
	glPopMatrix();
		glRotatef(angDedos, 0, 1, 0);
	glPushMatrix();//COMIENZA  DIBUJAR LA SIGUIENTE FALANGE DEL DEDO INDICE
		glTranslatef(14.4, 2.5, 0);
		glScalef(1, 0.5, 0.5);
		prisma();
	glPopMatrix();
	glPushMatrix();    //DEDO MEDIO
		glTranslatef(10.8, 0.9, 0);
		glRotatef(angDedos, 0, 1, 0);
		glPushMatrix();//COMIENZA  DIBUJAR EL DEDO MEDIO
		glTranslatef(2.5, 1, 0);
		glScalef(1, 0.5, 0.5);
		prisma();
	glPopMatrix();
		glRotatef(angDedos, 0, 1, 0);
	glPushMatrix();//COMIENZA  DIBUJAR LA SIGUIENTE FALANGE DEL DEDO MEDIO
		glTranslatef(14.3, 1.9, 0);
		glScalef(1.7, 0.5, 0.5);
		prisma();
	glPopMatrix();
	glPushMatrix();    //DEDO ANULAR
		glTranslatef(10.9, 0.3, 0);
		glRotatef(angDedos, 0, 1, 0);
	glPushMatrix();//COMIENZA  DIBUJAR EL DEDO ANULAR
		glTranslatef(2.5, 1, 0);
		glScalef(1, 0.5, 0.5);
		prisma();
	glPopMatrix();
		glRotatef(angDedos, 0, 1, 0);
	glPushMatrix();//COMIENZA  DIBUJAR LA SIGUIENTE FALANGE DEL DEDO ANULAR
		glTranslatef(14.3, 1.3, 0);
		glScalef(1, 0.5, 0.5);
		prisma();
	glPopMatrix();
	glPushMatrix();    //EN ESTA PARTE NO PUSE FALANGE AL MENIQUE POR SER EL DEDO MAS PEQUEÑO
		/*glTranslatef(10.9, -0.99, 0);
			glRotatef(angDedos, 0, 1, 0);
			glPushMatrix();
			glTranslatef(2.5, 1, 0);
			glScalef(1, 0.5, 0.5);
			prisma();*/
	glPopMatrix();
		glRotatef(angDedos, 0, 1, 0);
	glPushMatrix();//DEDO MENIQUE
		glTranslatef(13.4, 0.7, 0);
		glScalef(1.4, 0.5, 0.5);
		prisma();
	glPopMatrix();
	glPushMatrix();    //TORSO
		glTranslatef(-7.5, -1, 0);
		glRotatef(angTorso, 0, 0, 1);
	glPushMatrix();//COMIENZA  DIBUJAR EL TORSO
		glTranslatef(2.5, 1, 0);
		glScalef(10, 10, 5);
		prisma();
	glPopMatrix();
		glRotatef(angTorso, 0, 0, 1);
	glPopMatrix();
	glPushMatrix();    //DIBUJA BRAZO IZQUIERDO
		glTranslatef(-17.7, 1.25, 0);
		glRotatef(angHombroI, 0, 0, 1);
	glPushMatrix();//COMIENZA A DIBUJAR HOMBRO IZQUIERDO
		glTranslatef(2.8, 1.25, 0); 
		glScalef(5, 2.5, 5);
		prisma();
	glPopMatrix();
	glPushMatrix();    //ANTEBRAZO IZQUIERDO
		glTranslatef(5.3, 1.3, 0);
		glRotatef(angCodoI, 0, 0, 1);
	glPushMatrix();//COMIENZA A DIBUJAR ANTEBRAZO IZQUIERDO
		glTranslatef(-8, 0, 0);
		glScalef(6, 2.5, 3);
		prisma();
	glPopMatrix();
	glPushMatrix();    //PALMA IZQUIERDA
		glTranslatef(-9, 0, 0);
		glRotatef(angPalmaI, 0, 1, 0);
	glPushMatrix();//COMIENZA  DIBUJAR LA PALMA IZQUIERDA
		glTranslatef(2.5, 1.25, 0);
		glScalef(2, 2, 2);
		prisma();
	glPopMatrix();
	glPushMatrix();    //DEDO PULGAR IZQUIERDO
		glTranslatef(-9.4, 1.5, 0);
		glRotatef(angManoI, 1, 0, 0);
	glPushMatrix();//COMIENZA  DIBUJAR DEDO PULGAR IZQUIERDO
		glTranslatef(2.5, 1, 0);
		glScalef(0.5, 1, 0.5);
		prisma();
	glPopMatrix();
		glRotatef(angManoI, 1, 0, 0);
	glPushMatrix();//COMIENZA  DIBUJAR LA SIGUIENTE FALANGE DEL DEDO PULGAR
		glTranslatef(-6.9, 3.4, 0);
		glScalef(0.5, 1, 0.5);
		prisma();
	glPopMatrix();
	glPushMatrix();    //DEDO INDICE IZQUIERDO
		glTranslatef(-10.5, 1.5, 0);
		glRotatef(angDedosI, 0, 1, 0);
	glPushMatrix();//COMIENZA  DIBUJAR DEDO INDICE IZQUIERDO
		glTranslatef(2.5, 1, 0);
		glScalef(1, 0.5, 0.5);
		prisma();
	glPopMatrix();
		glRotatef(angDedosI, 0, 1, 0);
	glPushMatrix();//COMIENZA  DIBUJAR LA SIGUIENTE FALANGE DEL DEDO INDICE IZQUIERDO
		glTranslatef(-9, 2.5, 0);
		glScalef(1, 0.5, 0.5);
		prisma();
	glPopMatrix();
	glPushMatrix();    //DEDO MEDIO IZQUIERDO
		glTranslatef(-10.5, 0.9, 0);
		glRotatef(angDedosI, 0, 1, 0);
	glPushMatrix();//COMIENZA  DIBUJAR EL DEDO MEDIO IZQUIERDO
		glTranslatef(2.5, 1, 0);
		glScalef(1, 0.5, 0.5);
		prisma();
	glPopMatrix();
		glRotatef(angDedosI, 0, 1, 0);
	glPushMatrix();//COMIENZA  DIBUJAR LA SIGUIENTE FALANGE DEL DEDO MEDIO IZQUIERDO
		glTranslatef(-9, 1.9, 0);
		glScalef(1.7, 0.5, 0.5);
		prisma();
	glPopMatrix();
		glPushMatrix();    //DEDO ANULAR IZQUIERDO
		glTranslatef(-10.5, 0.3, 0);
		glRotatef(angDedosI, 0, 1, 0);
	glPushMatrix();//COMIENZA  DIBUJAR EL DEDO ANULAR IZQUIERDO
		glTranslatef(2.5, 1, 0);
		glScalef(1, 0.5, 0.5);
		prisma();
	glPopMatrix();
		glRotatef(angDedosI, 0, 1, 0);
	glPushMatrix();//COMIENZA  DIBUJAR LA SIGUIENTE FALANGE DEL DEDO ANULAR
		glTranslatef(-9, 1.3, 0);
		glScalef(1, 0.5, 0.5);
		prisma();
	glPopMatrix();
	glPushMatrix();    //EN ESTA PARTE NO PUSE FALANGE AL MENIQUE POR SER EL DEDO MAS PEQUEÑO
		/*glTranslatef(10.9, -0.99, 0);
			glRotatef(angDedos, 0, 1, 0);
			glPushMatrix();
			glTranslatef(2.5, 1, 0);
			glScalef(1, 0.5, 0.5);
			prisma();*/
	glPopMatrix();
		glRotatef(angDedosI, 0, 1, 0);
	glPushMatrix();//DEDO MENIQUE IZQUIERDO
		glTranslatef(-8, 0.7, 0);
		glScalef(1.4, 0.5, 0.5);
		prisma();
	glPopMatrix();
	glPushMatrix();    //PIERNA DERECHA
		glTranslatef(-7.5, -1, 0);
		glRotatef(angPierna, 1, 0, 0);
	glPushMatrix();//COMIENZA  DIBUJAR LA PIERNA DERECHA
		glTranslatef(22, -8, 0);
		glScalef(3, 6, 5);
		prisma();
	glPopMatrix();
		glRotatef(angPierna, 1, 0, 0);
	glPopMatrix();
	glPushMatrix();    //PIERNA IZQUIERDA
		glTranslatef(-31, 0, 0);
		glRotatef(angPierna, 1, 0, 0);
	glPushMatrix();//COMIENZA  DIBUJAR LA PIERNA IZQUIERDA
		glTranslatef(22, -8, 0);
		glScalef(3, 6, 5);
		prisma();
	glPopMatrix();
		glRotatef(angPierna, 1, 0, 0);
	glPopMatrix();
	glPushMatrix();    //CABEZA
		glTranslatef(-7.5, -1, 0);
		glRotatef(angCabeza, 0, 0, 1);
	glPushMatrix();//COMIENZA  DIBUJAR LA CABEZA
		glTranslatef(1.8, 8, 0);
		glScalef(5, 5, 5);
		prisma();
	glPopMatrix();
		glRotatef(angCabeza, 0, 0, 1);
	glPopMatrix();
	glPushMatrix();    //PIERNA BAJA DERECHA
		glTranslatef(-25.2, -5, 0);
		glRotatef(angPiernaB, 1, 0, 0);
	glPushMatrix();//COMIENZA  DIBUJAR LA PIERNA BAJA DERECHA
		glTranslatef(22, -8, 0);
		glScalef(2, 5, 5);
		prisma();
	glPopMatrix();
		glRotatef(angPiernaB, 1, 0, 0);
	glPopMatrix();
	glPushMatrix();    //PIERNA BAJA IZQUIERDA
		glTranslatef(-31, -5, 0);
		glRotatef(angPiernaB, 1, 0, 0);
	glPushMatrix();//COMIENZA  DIBUJAR LA PIERNA BAJA IZQUIERDA
		glTranslatef(22, -8, 0);
		glScalef(2, 5, 5);
		prisma();
	glPopMatrix();
		glRotatef(angPiernaB, 1, 0, 0);
	glPopMatrix();

	glPopMatrix();



	glutSwapBuffers();
	// Swap The Buffers
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
	//glOrtho(-5,5,-5,5,0.2,20);	
	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	//glLoadIdentity();									
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
	case 'w':
	case 'W':
		transZ += 0.2f;
		break;
	case 's':
	case 'S':
		transZ -= 0.2f;
		break;
	case 'a':
	case 'A':
		transX += 0.2f;
		break;
	case 'd':
	case 'D':
		transX -= 0.2f;
		break;
	case 'h': //AQUI EMPIEZA EL MOVIMIENTO DEL HOMBRO HACIA ARRIBA	
		if (angHombro < 90) {
			angHombro += 0.5f;
			printf("%f", angHombro);
		}
		angHombro += 0.2f;
		break;
	case 'H': //AQUI EMPIEZA EL MOVIMIENTO DEL HOMBRO HACIA ABAJO
		if (angHombro < -90) {
			angHombro -= 0.5f;
			printf("%f", angHombro);
		}
		angHombro -= 0.2f;
		break;
	case 'c': //AQUI EMPIEZA EL MOVIMIENTO DEL CODO DERECHO HACIA ARRIBA	
		if (angCodo < 50) {
			angCodo += 0.5f;
			printf("%f", angCodo);
		}
		angCodo += 0.2f;
		break;
	case 'C': //AQUI EMPIEZA EL MOVIMIENTO DEL CODO DERECHO HACIA ABAJO
		if (angCodo < -50) {
			angCodo -= 0.5f;
			printf("%f", angCodo);
		}
		angCodo -= 0.2f;
		break;
	case 'p': //AQUI EMPIEZA EL MOVIMIENTO DE LA PALMA HACIA AFUERA
		if (angPalma < 18) {
			angPalma += 0.5f;
			printf("%f", angPalma);
		}
		angPalma += 0.2f;
		break;
	case 'P': //AQUI EMPIEZA EL MOVIMIENTO DE LA PALMA HACIA ADENTRO
		if (angPalma < -18) {
			angPalma -= 0.5f;
			printf("%f", angPalma);
		}
		angPalma -= 0.2f;
		break;
	case 'm': //AQUI EMPIEZA EL MOVIMIENTO DE LA MANO PARA CERRAR LOS DEDOS
		if (angMano < 8) {
			angMano += 0.5f;
			printf("%f", angMano);
		}
		angMano += 0.2f;
		break;
	case 'M': //AQUI EMPIEZA EL MOVIMIENTO DE LA MANO PARA ABRIR LOS DEDOS
		if (angMano < -8) {
			angMano -= 0.5f;
			printf("%f", angMano);
		}
		angMano -= 0.2f;
		break;
	case 'f': //AQUI EMPIEZA EL MOVIMIENTO DE LA MANO PARA ABRIR LOS DEDOS
		if (angDedos < 8) {
			angDedos += 0.5f;
			printf("%f", angDedos);
		}
		angDedos += 0.2f;
		break;
	case 'F': //AQUI EMPIEZA EL MOVIMIENTO DE LA MANO PARA CERRAR LOS DEDOS
		if (angDedos < -8) {
			angDedos -= 0.5f;
			printf("%f", angDedos);
		}
		angDedos -= 0.2f;
		break;
	case 'T': //AQUI EMPIEZA EL MOVIMIENTO DEL TORSO
		if (angTorso < 5) {
			angTorso -= 0.5f;
			printf("%f", angTorso);
		}
		angTorso -= 0.2f;
		break;
	case 't': //AQUI EMPIEZA EL MOVIMIENTO DEL TORSO
		if (angTorso < -5) {
			angTorso += 0.5f;
			printf("%f", angTorso);
		}
		angTorso -= 0.2f;
		break;
	case 'l': //AQUI EMPIEZA EL MOVIMIENTO DEL HOMBRO IZQUIERDO HACIA ARRIBA	
		if (angHombroI < 90) {
			angHombroI += 0.5f;
			printf("%f", angHombroI);
		}
		angHombroI += 0.2f;
		break;
	case 'L': //AQUI EMPIEZA EL MOVIMIENTO DEL HOMBRO IZQUIERDO HACIA ABAJO
		if (angHombroI < -90) {
			angHombroI -= 0.5f;
			printf("%f", angHombroI);
		}
		angHombroI -= 0.2f;
		break;
	case 'i': //AQUI EMPIEZA EL MOVIMIENTO DEL CODO IZQUIERDO HACIA ARRIBA	
		if (angCodoI < 50) {
			angCodoI += 0.5f;
			printf("%f", angCodoI);
		}
		angCodoI += 0.2f;
		break;
	case 'I': //AQUI EMPIEZA EL MOVIMIENTO DEL CODO IZQUIERDO HACIA ABAJO
		if (angCodoI < -50) {
			angCodoI -= 0.5f;
			printf("%f", angCodoI);
		}
		angCodoI -= 0.2f;
		break;
	case 'o': //AQUI EMPIEZA EL MOVIMIENTO DE LA PALMA  IZQUIERDA HACIA AFUERA
		if (angPalmaI < 18) {
			angPalmaI += 0.5f;
			printf("%f", angPalmaI);
		}
		angPalmaI += 0.2f;
		break;
	case 'O': //AQUI EMPIEZA EL MOVIMIENTO DE LA PALMA IZQUIERDA HACIA ADENTRO
		if (angPalmaI < -18) {
			angPalmaI -= 0.5f;
			printf("%f", angPalmaI);
		}
		angPalmaI -= 0.2f;
		break;
	case 'z': //AQUI EMPIEZA EL MOVIMIENTO DE LA MANO IZQUIERDA PARA CERRAR LOS DEDOS
		if (angManoI < 8) {
			angManoI += 0.5f;
			printf("%f", angManoI);
		}
		angManoI += 0.2f;
		break;
	case 'Z': //AQUI EMPIEZA EL MOVIMIENTO DE LA MANO IZQUIERDA PARA ABRIR LOS DEDOS
		if (angManoI < -8) {
			angManoI -= 0.5f;
			printf("%f", angManoI);
		}
		angManoI -= 0.2f;
		break;
	case 'g': //AQUI EMPIEZA EL MOVIMIENTO DE LA MANO PARA ABRIR LOS DEDOS
		if (angDedosI < 8) {
			angDedosI += 0.5f;
			printf("%f", angDedosI);
		}
		angDedosI += 0.2f;
		break;
	case 'G': //AQUI EMPIEZA EL MOVIMIENTO DE LA MANO PARA CERRAR LOS DEDOS
		if (angDedosI < -8) {
			angDedosI -= 0.5f;
			printf("%f", angDedosI);
		}
		angDedosI -= 0.2f;
		break;
	case 'y': //AQUI EMPIEZA EL MOVIMIENTO DE LA PIERNA DERECHA HACIA DELANTE
		if (angPierna < 8) {
			angPierna -= 0.5f;
			printf("%f", angPierna);
		}
		angPierna += 0.2f;
		break;
	case 'Y': //AQUI EMPIEZA EL MOVIMIENTO DE LA PIERNA DERECHA HACIA ATRAS
		if (angPierna < -8) {
			angPierna += 0.5f;
			printf("%f", angPierna);
		}
		angPierna += 0.2f;
		break;
	case 'u': //AQUI EMPIEZA EL MOVIMIENTO DE LA CABEZA
		if (angCabeza < 5) {
			angCabeza -= 0.5f;
			printf("%f", angCabeza);
		}
		angCabeza -= 0.2f;
		break;
	case 'U': //AQUI EMPIEZA EL MOVIMIENTO DE LA CABEZA
		if (angCabeza < -5) {
			angCabeza += 0.5f;
			printf("%f", angCabeza);
		}
		angCabeza -= 0.2f;
		break;
	case 'b': //AQUI EMPIEZA EL MOVIMIENTO DE LA PIERNA BAJA DERECHA HACIA DELANTE
		if (angPiernaB < 8) {
			angPiernaB -= 0.5f;
			printf("%f", angPiernaB);
		}
		angPiernaB += 0.2f;
		break;
	case 'B': //AQUI EMPIEZA EL MOVIMIENTO DE LA PIERNA BAJA DERECHA HACIA ATRAS
		if (angPiernaB < -8) {
			angPiernaB += 0.5f;
			printf("%f", angPiernaB);
		}
		angPiernaB += 0.2f;
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
	case GLUT_KEY_UP:		// Presionamos tecla ARRIBA...
		angleX += 2.0f;
		break;
	case GLUT_KEY_DOWN:		// Presionamos tecla ABAJO...
		angleX -= 2.0f;
		break;
	case GLUT_KEY_LEFT:
		angleY += 2.0f;
		break;
	case GLUT_KEY_RIGHT:
		angleY -= 2.0f;
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
	screenW = glutGet(GLUT_SCREEN_WIDTH);
	screenH = glutGet(GLUT_SCREEN_HEIGHT);
	glutInitWindowSize(500, 500);	// Tamaño de la Ventana
	glutInitWindowPosition(0, 0);	//Posicion de la Ventana
	glutCreateWindow("Practica 5"); // Nombre de la Ventana
	printf("Resolution H: %i \n", screenW);
	printf("Resolution V: %i \n", screenH);
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutMainLoop();          // 

	return 0;
}

