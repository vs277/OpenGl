#include <Windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
//#include<GL/glaux.h>
#include "Header.h"
#include "lodepng.h"
using namespace std;
/*
void display()
{
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColorPointer(3, GL_FLOAT, 0, colors);
	glVertexPointer(3, GL_FLOAT, 0, vertices);
	glNormalPointer(GL_FLOAT, 3, normals);
	glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
	//gluLookAt(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	//glLoadIdentity();
	//glRotatef(160.0, 0.0, 1.0, 0.0);
	
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, &indices[0]);
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, &indices[3]);
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, &indices[6]);
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, &indices[9]);
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, &indices[12]);
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, &indices[15]);
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, &indices[18]);
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, &indices[21]);
	glColor3f(0.5, 0.5, 0.5);
	glPushMatrix();
	glTranslatef(-0.8, 0.7, 0.0);
	glutWireSphere(0.2, 20, 20);
	glPopMatrix();
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glutSwapBuffers();

}
void goUp() {
	for (int i = 0; i < 50; i++) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glTranslatef(0.004*i, 0.004*i, 0.004*i);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, &indices[0]);
		glLoadIdentity();
		glTranslatef(0.004*i, 0.004*i, -0.004*i);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, &indices[3]);
		glLoadIdentity();
		glTranslatef(-0.004*i, 0.004*i, -0.004*i);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, &indices[6]);
		glLoadIdentity();
		glTranslatef(-0.004*i, 0.004*i, 0.004*i);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, &indices[9]);
		glLoadIdentity();
		glTranslatef(0.004*i, -0.004*i, 0.004*i);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, &indices[12]);
		glLoadIdentity();
		glTranslatef(0.004*i, -0.004*i, -0.004*i);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, &indices[15]);
		glLoadIdentity();
		glTranslatef(-0.004*i, -0.004*i, -0.004*i);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, &indices[18]);
		glLoadIdentity();
		glTranslatef(-0.004*i, -0.004*i, 0.004*i);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, &indices[21]);
		glLoadIdentity();
		glColor3f(0.5, 0.5, 0.5);
		glPushMatrix();
		glTranslatef(-0.8, 0.7, 0.0);
		glutWireSphere(0.2, 20, 20);
		glPopMatrix();
		glLightfv(GL_LIGHT0, GL_POSITION, light_position);
		glutSwapBuffers();
		a = 1;
		Sleep(35);
	}
};
void goDown() {
	for (int i = 0; i < 51; i++) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glTranslatef(0.2 - 0.004*i, 0.2 - 0.004*i, 0.2 - 0.004*i);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, &indices[0]);
		glLoadIdentity();
		glTranslatef(0.2 - 0.004*i, 0.2 - 0.004*i, -0.2 + 0.004*i);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, &indices[3]);
		glLoadIdentity();
		glTranslatef(-0.2 + 0.004*i, 0.2 - 0.004*i, -0.2 + 0.004*i);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, &indices[6]);
		glLoadIdentity();
		glTranslatef(-0.2 + 0.004*i, 0.2 - 0.004*i, 0.2 - 0.004*i);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, &indices[9]);
		glLoadIdentity();
		glTranslatef(0.2 - 0.004*i, -0.2 + 0.004*i, 0.2 - 0.004*i);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, &indices[12]);
		glLoadIdentity();
		glTranslatef(0.2 - 0.004*i, -0.2 + 0.004*i, -0.2 + 0.004*i);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, &indices[15]);
		glLoadIdentity();
		glTranslatef(-0.2 + 0.004*i, -0.2 + 0.004*i, -0.2 + 0.004*i);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, &indices[18]);
		glLoadIdentity();
		glTranslatef(-0.2 + 0.004*i, -0.2 + 0.004*i, 0.2 - 0.004*i);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, &indices[21]);
		glLoadIdentity();
		glColor3f(0.5, 0.5, 0.5);
		glPushMatrix();
		glTranslatef(-0.8, 0.7, 0.0);
		glutWireSphere(0.2, 20, 20);
		glPopMatrix();
		glLightfv(GL_LIGHT0, GL_POSITION, light_position);
		glutSwapBuffers();
		a = 0;
		Sleep(35);
	}
};
void goAround() {
	for (int i = 0; i < 361; i++) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glRotatef(i*1.0, 0.0, 1.0, 0.0);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, &indices[0]);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, &indices[3]);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, &indices[6]);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, &indices[9]);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, &indices[12]);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, &indices[15]);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, &indices[18]);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, &indices[21]);
		glColor3f(0.5, 0.5, 0.5);
		glPushMatrix();
		glTranslatef(0.0 - 0.8*cos(i*PI / 180), 0.7, 0.0 + 0.8*sin(i*PI / 180));
		glRotatef(i*1.0, 0.0, 1.0, 0.0);
		glutWireSphere(0.2, 20, 20);
		GLfloat light_position_1[4];
		light_position_1[0] = 0.0 - 0.8*cos(i*PI / 180);
		light_position_1[1] = 0.7;
		light_position_1[2] = 0.0 + 0.8*sin(i*PI / 180);
		light_position_1[3] = 0;
		glLightfv(GL_LIGHT0, GL_POSITION, light_position_1);
		glPopMatrix();
		
		glutSwapBuffers();
		Sleep(50);
	}
}

void mouse(int button, int state, int x, int y)
{
	switch (button)
	{
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN && a == 0) goUp();
			break; 
		
	case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN && a == 1) goDown();
			break;
	
	default:
		break;
	}
}
void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'b':
		if (a == 0) goAround();


		break;
	default:
		break;
	}
}
*/
void init() {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glShadeModel(GL_SMOOTH);
	glEnableClientState(GL_COLOR_ARRAY);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glColorPointer(4, GL_FLOAT, 0, colors);
	glVertexPointer(3, GL_FLOAT, 0, vertices);
	glNormalPointer(GL_FLOAT, 0, normals);
	glTexCoordPointer(GL_FLOAT, 2, 0, textures);
	glEnable(GL_DEPTH_TEST);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_NORMALIZE);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//glEnable(GL_LIGHTING);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_dif);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_collor);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, light_dir);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess);
	glGenTextures(1, &tex);
	glBindTexture(GL_TEXTURE_2D, tex);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	
}
void drawOkta() {
	if (okta_speed == 1) okta_angle++;
	if (okta_angle == 360) okta_angle = 0;
	glLoadIdentity();
	if(mask) glDepthMask(false);
	if (text_e == 1) glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, tex);
	//glTranslatef(0.0, 0.0, -2.0);
	glRotatef(okta_angle*1.0, 0.0, 1.0, 0.0);	
	
		glPushMatrix();
		glTranslatef(okta_pos, okta_pos, -okta_pos);
		//glBindTexture(GL_TEXTURE_2D, tex);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, &indices[3]);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(okta_pos, okta_pos, okta_pos);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, &indices[0]);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-okta_pos, okta_pos, -okta_pos);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, &indices[6]);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-okta_pos, okta_pos, okta_pos);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, &indices[9]);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(okta_pos, -okta_pos, -okta_pos);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, &indices[15]);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(okta_pos, -okta_pos, okta_pos);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, &indices[12]);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-okta_pos, -okta_pos, -okta_pos);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, &indices[18]);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-okta_pos, -okta_pos, okta_pos);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, &indices[21]);
		glPopMatrix();

    glLoadIdentity();
	if (text_e == 1) 
		glDisable(GL_TEXTURE_2D);
	if(mask) glDepthMask(true);
	//glTranslatef(0.0, 0.0, -2.0);
}
void drawSphere(){
	if (sphere_speed == 1) sphere_angle++;
	if (sphere_angle == 360) sphere_angle = 0;
	glPushMatrix();
	glTranslatef(0.0 - 0.8*cos(sphere_angle*PI / 180), 0.7, 0.0 + 0.8*sin(sphere_angle*PI / 180));
	glRotatef(sphere_angle*1.0, 0.0, 1.0, 0.0);
	glColor4f(1.0, 1.0, 1.0 , 1.0);
	glutWireSphere(0.2, 20, 20);
	glPopMatrix();
}
void drawLight() {
	GLfloat light_position_1[4];
	light_position_1[0] = 0.0 - 0.8*cos(sphere_angle*PI / 180);
	light_position_1[1] = 0.7;
	light_position_1[2] = 0.0 + 0.8*sin(sphere_angle*PI / 180);
	light_position_1[3] = 1;
	glLightfv(GL_LIGHT0, GL_POSITION, light_position_1);
}
void display_2(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glMatrixMode(GL_MODELVIEW);
	//glTranslatef(0.0, 0.0, -10.0);
	
		
		drawOkta();
	
	drawSphere();
	drawLight();
	//glutSwapBuffers();
	//glTranslatef(0.0, 0.0, 10.0);
	glFlush();
}
void Timer_Func(int value)
{
	//angle_y += speed_change;
	//angle_yO += speed_changeO;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	drawOkta();
	drawSphere();
	drawLight();
	glutSwapBuffers();
	glutTimerFunc(10, Timer_Func, 1);
}
void keyboard_2(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'z':
		text_e = 1;
		break;
	case 'x':
		text_e = 0;
		break;
	case 'u':
		glEnable(GL_LIGHTING);
		break;
	case 'i':
		glDisable(GL_LIGHTING);
		break;
	case 'o':
		mask = true;
		glEnable(GL_BLEND);
		break;
	case 'p':
		mask = false;
		glDisable(GL_BLEND);
		break;
	case 'w':
		sphere_speed=0;
		break;
	case 'q':
		sphere_speed=1;
		break;
	case 'e':
		okta_speed=1;
		break;
	case 'r':
		okta_speed=0;
		break;
	case 't':
	{
		okta_pos += 0.004;
		if (okta_pos > 0.2) okta_pos = 0.2;
		break;
	}
	case 'y':
	{
		okta_pos -= 0.004;
		if (okta_pos < 0.0) okta_pos = 0.0;
		break;
	}
	default:
		break;
	}
}

void reshape(int w, int h) { 
	glViewport(0, 0, (GLsizei)w, (GLsizei)h); 
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity(); 
	double aspect = (double)(w) / (double)(h);
	gluPerspective(90.0, aspect, 1.0, 200.0); 
	glMatrixMode(GL_MODELVIEW); 
	//glLoadIdentity(); 
	//glTranslatef(0.0, 0.0, -10.0); 
}
void textures_init() {
	//falls_image = auxDIBImageLoad(falls_filename);
	
	unsigned error = lodepng_decode32_file(&image, &w, &h, falls_filename);
	



}
int main(int argc, char **argv)
{
	a = 0;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(640, 640);
	glutInitWindowPosition(1, 0);
	glutCreateWindow("weryy!");
	textures_init();
	init();	
	
	glutDisplayFunc(display_2);
	glutKeyboardFunc(keyboard_2);
	glutTimerFunc(10, Timer_Func, 1);
	//glutReshapeFunc(reshape);
	//pImage = auxDIBImageLoad("qwer.bmp");
	
	glutMainLoop();

}