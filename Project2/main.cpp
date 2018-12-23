#include <Windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include "Header.h"
#include "lodepng.h"
using namespace std;


void drawOkta() {
	if (okta_speed == 1) okta_angle++;
	if (okta_angle == 360) okta_angle = 0;
	glLoadIdentity();
	if(mask) glDepthMask(false);
	if (text_e == 1) glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, tex);
	glRotatef(d*okta_angle*1.0, 0.0, 1.0, 0.0);	
	glRotatef(l, 0.0, 0.0, 1.0);
		glPushMatrix();
		glTranslatef(okta_pos, okta_pos, -okta_pos);
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
	if (text_e == 1) 	glDisable(GL_TEXTURE_2D);
	if(mask) glDepthMask(true);
	
}
void drawOkta_2() {
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	GLfloat x = 0.028, y = 0.01;
	glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
	glBegin(GL_TRIANGLES);

	glColor4f(1.0, 1.0, 1.0, 0.5);
	glNormal3f(0.58, 0.58, 0.58); glVertex3f((0.142 - y) / 2, (0.858 + y) / 2, y / 2);
	glNormal3f(0.58, 0.58, 0.58); glVertex3f(y / 2, (0.858 + y) / 2, (0.142 - y) / 2);
	glNormal3f(0.58, 0.58, 0.58); glVertex3f(y / 2, (1.0 - y) / 2, y / 2);
	glEnd();
	for (int i = 1; i < 31; i++) {
		glColor4f(1.0 - 0.03*i, 1.0 - 0.03*i, 1.0 - 0.03*i, 0.5);
		glBegin(GL_QUADS);
		glNormal3f(0.58, 0.58, 0.58); glVertex3f((0.142 + y + (i - 1) * x) / 2, (0.858 - y - (i - 1)*x) / 2, (0.0 + y) / 2);
		glNormal3f(0.58, 0.58, 0.58); glVertex3f((0.142 - y + i * x) / 2, (0.858 + y - i * x) / 2, (0.0 + y) / 2);
		glNormal3f(0.58, 0.58, 0.58); glVertex3f((0.0 + y) / 2, (0.858 + y - i * x) / 2, (0.142 - y + i * x) / 2);
		glNormal3f(0.58, 0.58, 0.58); glVertex3f((0.0 + y) / 2, (0.858 - y - (i - 1)*x) / 2, (0.142 + y + (i - 1) * x) / 2);
		glEnd();
	}

	glPushMatrix();
	glRotatef(90.0, 0.0, 1.0, 0.0);
	glBegin(GL_TRIANGLES);
	glColor4f(1.0, 0.0, 0.0, 0.5);
	glNormal3f(0.58, 0.58, 0.58); glVertex3f((0.142 - y) / 2, (0.858 + y) / 2, y / 2);
	glNormal3f(0.58, 0.58, 0.58); glVertex3f(y / 2, (0.858 + y) / 2, (0.142 - y) / 2);
	glNormal3f(0.58, 0.58, 0.58); glVertex3f(y / 2, (1.0 - y) / 2, y / 2);
	glEnd();
	for (int i = 1; i < 31; i++) {
		glBegin(GL_QUADS);
		glNormal3f(0.58, 0.58, 0.58); glVertex3f((0.142 + y + (i - 1) * x) / 2, (0.858 - y - (i - 1)*x) / 2, (0.0 + y) / 2);
		glNormal3f(0.58, 0.58, 0.58); glVertex3f((0.142 - y + i * x) / 2, (0.858 + y - i * x) / 2, (0.0 + y) / 2);
		glNormal3f(0.58, 0.58, 0.58); glVertex3f((0.0 + y) / 2, (0.858 + y - i * x) / 2, (0.142 - y + i * x) / 2);
		glNormal3f(0.58, 0.58, 0.58); glVertex3f((0.0 + y) / 2, (0.858 - y - (i - 1)*x) / 2, (0.142 + y + (i - 1) * x) / 2);
		glEnd();
	}
	glPopMatrix();
	glPushMatrix();
	glRotatef(180.0, 0.0, 1.0, 0.0);
	glBegin(GL_TRIANGLES);
	glColor4f(1.0, 0.5, 0.0, 0.5);
	glNormal3f(0.58, 0.58, 0.58); glVertex3f((0.142 - y) / 2, (0.858 + y) / 2, y / 2);
	glNormal3f(0.58, 0.58, 0.58); glVertex3f(y / 2, (0.858 + y) / 2, (0.142 - y) / 2);
	glNormal3f(0.58, 0.58, 0.58); glVertex3f(y / 2, (1.0 - y) / 2, y / 2);
	glEnd();
	for (int i = 1; i < 31; i++) {
		glBegin(GL_QUADS);
		glNormal3f(0.58, 0.58, 0.58); glVertex3f((0.142 + y + (i - 1) * x) / 2, (0.858 - y - (i - 1)*x) / 2, (0.0 + y) / 2);
		glNormal3f(0.58, 0.58, 0.58); glVertex3f((0.142 - y + i * x) / 2, (0.858 + y - i * x) / 2, (0.0 + y) / 2);
		glNormal3f(0.58, 0.58, 0.58); glVertex3f((0.0 + y) / 2, (0.858 + y - i * x) / 2, (0.142 - y + i * x) / 2);
		glNormal3f(0.58, 0.58, 0.58); glVertex3f((0.0 + y) / 2, (0.858 - y - (i - 1)*x) / 2, (0.142 + y + (i - 1) * x) / 2);
		glEnd();
	}
	glPopMatrix();
	glPushMatrix();
	glRotatef(270.0, 0.0, 1.0, 0.0);
	glBegin(GL_TRIANGLES);
	glColor4f(0.0, 0.5, 0.0, 0.5);
	glNormal3f(0.58, 0.58, 0.58); glVertex3f((0.142 - y) / 2, (0.858 + y) / 2, y / 2);
	glNormal3f(0.58, 0.58, 0.58); glVertex3f(y / 2, (0.858 + y) / 2, (0.142 - y) / 2);
	glNormal3f(0.58, 0.58, 0.58); glVertex3f(y / 2, (1.0 - y) / 2, y / 2);
	glEnd();
	for (int i = 1; i < 31; i++) {
		glBegin(GL_QUADS);
		glNormal3f(0.58, 0.58, 0.58); glVertex3f((0.142 + y + (i - 1) * x) / 2, (0.858 - y - (i - 1)*x) / 2, (0.0 + y) / 2);
		glNormal3f(0.58, 0.58, 0.58); glVertex3f((0.142 - y + i * x) / 2, (0.858 + y - i * x) / 2, (0.0 + y) / 2);
		glNormal3f(0.58, 0.58, 0.58); glVertex3f((0.0 + y) / 2, (0.858 + y - i * x) / 2, (0.142 - y + i * x) / 2);
		glNormal3f(0.58, 0.58, 0.58); glVertex3f((0.0 + y) / 2, (0.858 - y - (i - 1)*x) / 2, (0.142 + y + (i - 1) * x) / 2);
		glEnd();
	}
	glPopMatrix();

	glPushMatrix();
	glRotatef(180.0, 1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLES);
	glColor4f(0.0, 1.0, 0.0, 0.5);
	glNormal3f(0.58, 0.58, 0.58); glVertex3f((0.142 - y) / 2, (0.858 + y) / 2,  y / 2);
	glNormal3f(0.58, 0.58, 0.58); glVertex3f(y / 2, (0.858 + y) / 2, (0.142 - y) / 2);
	glNormal3f(0.58, 0.58, 0.58); glVertex3f(y / 2, (1.0 - y) / 2, y / 2);
	glEnd();
	for (int i = 1; i < 31; i++) {

		glBegin(GL_QUADS);
		glColor4f(0.0, 1.0, 0.0, 0.5);
		glNormal3f(0.58, 0.58, 0.58); glVertex3f((0.142 + y + (i - 1) * x) / 2, (0.858 - y - (i - 1)*x) / 2, (0.0 + y) / 2);
		glNormal3f(0.58, 0.58, 0.58); glVertex3f((0.142 - y + i * x) / 2, (0.858 + y - i * x) / 2, (0.0 + y) / 2);
		glNormal3f(0.58, 0.58, 0.58); glVertex3f((0.0 + y) / 2, (0.858 + y - i * x) / 2, (0.142 - y + i * x) / 2);
		glNormal3f(0.58, 0.58, 0.58); glVertex3f((0.0 + y) / 2, (0.858 - y - (i - 1)*x) / 2, (0.142 + y + (i - 1) * x) / 2);
		glEnd();
	}
	glPopMatrix();

	glPushMatrix();
	glRotatef(90.0, 0.0, 1.0, 0.0);
	glRotatef(180.0, 1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLES);
	glColor4f(0.0, 0.0, 1.0, 0.5);
	glNormal3f(0.58, 0.58, 0.58); glVertex3f((0.142 - y) / 2, (0.858 + y) / 2, y / 2);
	glNormal3f(0.58, 0.58, 0.58); glVertex3f(y / 2, (0.858 + y) / 2, (0.142 - y) / 2);
	glNormal3f(0.58, 0.58, 0.58); glVertex3f(y / 2, (1.0 - y) / 2, y / 2);
	glEnd();
	for (int i = 1; i < 31; i++) {
		glBegin(GL_QUADS);
		glNormal3f(0.58, 0.58, 0.58); glVertex3f((0.142 + y + (i - 1) * x) / 2, (0.858 - y - (i - 1)*x) / 2, (0.0 + y) / 2);
		glNormal3f(0.58, 0.58, 0.58); glVertex3f((0.142 - y + i * x) / 2, (0.858 + y - i * x) / 2, (0.0 + y) / 2);
		glNormal3f(0.58, 0.58, 0.58); glVertex3f((0.0 + y) / 2, (0.858 + y - i * x) / 2, (0.142 - y + i * x) / 2);
		glNormal3f(0.58, 0.58, 0.58); glVertex3f((0.0 + y) / 2, (0.858 - y - (i - 1)*x) / 2, (0.142 + y + (i - 1) * x) / 2);
		glEnd();
	}
	glPopMatrix();
	glPushMatrix();
	glRotatef(180.0, 0.0, 1.0, 0.0);
	glRotatef(180.0, 1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLES);
	glColor4f(0.0, 1.0, 1.0, 0.5);
	glNormal3f(0.58, 0.58, 0.58); glVertex3f((0.142 - y) / 2, (0.858 + y) / 2, y / 2);
	glNormal3f(0.58, 0.58, 0.58); glVertex3f(y / 2, (0.858 + y) / 2, (0.142 - y) / 2);
	glNormal3f(0.58, 0.58, 0.58); glVertex3f(y / 2, (1.0 - y) / 2, y / 2);
	glEnd();
	for (int i = 1; i < 31; i++) {
		glBegin(GL_QUADS);
		glNormal3f(0.58, 0.58, 0.58); glVertex3f((0.142 + y + (i - 1) * x) / 2, (0.858 - y - (i - 1)*x) / 2, (0.0 + y) / 2);
		glNormal3f(0.58, 0.58, 0.58); glVertex3f((0.142 - y + i * x) / 2, (0.858 + y - i * x) / 2, (0.0 + y) / 2);
		glNormal3f(0.58, 0.58, 0.58); glVertex3f((0.0 + y) / 2, (0.858 + y - i * x) / 2, (0.142 - y + i * x) / 2);
		glNormal3f(0.58, 0.58, 0.58); glVertex3f((0.0 + y) / 2, (0.858 - y - (i - 1)*x) / 2, (0.142 + y + (i - 1) * x) / 2);
		glEnd();
	}
	glPopMatrix();
	glPushMatrix();
	glRotatef(270.0, 0.0, 1.0, 0.0);
	glRotatef(180.0, 1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLES);
	glColor4f(1.0, 0.0, 1.0, 0.5);
	glNormal3f(0.58, 0.58, 0.58); glVertex3f((0.142 - y) / 2, (0.858 + y) / 2,  y / 2);
	glNormal3f(0.58, 0.58, 0.58); glVertex3f(y / 2, (0.858 + y) / 2, (0.142 - y) / 2);
	glNormal3f(0.58, 0.58, 0.58); glVertex3f(y / 2, (1.0 - y) / 2, y / 2);
	glEnd();
	for (int i = 1; i < 31; i++) {
		glBegin(GL_QUADS);
		glNormal3f(0.58, 0.58, 0.58); glVertex3f((0.142 + y + (i - 1) * x) / 2, (0.858 - y - (i - 1)*x) / 2, (0.0 + y) / 2);
		glNormal3f(0.58, 0.58, 0.58); glVertex3f((0.142 - y + i * x) / 2, (0.858 + y - i * x) / 2, (0.0 + y) / 2);
		glNormal3f(0.58, 0.58, 0.58); glVertex3f((0.0 + y) / 2, (0.858 + y - i * x) / 2, (0.142 - y + i * x) / 2);
		glNormal3f(0.58, 0.58, 0.58); glVertex3f((0.0 + y) / 2, (0.858 - y - (i - 1)*x) / 2, (0.142 + y + (i - 1) * x) / 2);
		glEnd();
	}
	glPopMatrix();
	//glLoadIdentity();
	//	glFlush();
}
void drawSphere(){
	if (sphere_speed == 1) sphere_angle++;
	if (sphere_angle == 360) sphere_angle = 0;
	glPushMatrix();
	glTranslatef(0.0 - 0.8*cos(sphere_angle*PI / 180), 0.0, 0.0 + f*0.8*sin(sphere_angle*PI / 180));
	glRotatef(sphere_angle*1.0, 0.0, 1.0, 0.0);
	glColor4f(1.0, 1.0, 1.0 , 1.0);
	if((0.0 + f * 0.8*sin(sphere_angle*PI / 180))>0) glColor4f(1.0,1.0,0.0,1.0);
	glutWireSphere(0.05, 20, 20);
	glPopMatrix();
}
void drawLight() {
	GLfloat light_position_1[4];
	light_position_1[0] = 0.0 - 0.8*cos(sphere_angle*PI / 180);
	light_position_1[1] = 0.0;
	light_position_1[2] = 0.0 + f*0.8*sin(sphere_angle*PI / 180);
	light_position_1[3] = 1;
	glLightfv(GL_LIGHT0, GL_POSITION, light_position_1);
}
void display_2(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
	glMatrixMode(GL_MODELVIEW);
	//drawOkta();
	glCallList(theTorus);
	drawSphere();
	drawLight();
	glFlush();
}
void init() {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glShadeModel(GL_SMOOTH);
	glEnableClientState(GL_COLOR_ARRAY);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glColorPointer(4, GL_FLOAT, 0, colors);
	glVertexPointer(3, GL_FLOAT, 0, vertices);
	glNormalPointer(GL_FLOAT, 0, normals);
	glTexCoordPointer(2, GL_FLOAT, 0, textures);



	glEnable(GL_DEPTH_TEST);
	//glEnable(GL_BLEND);
	glEnable(GL_POINT_SMOOTH);
	//glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_ALPHA_TEST);

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	//glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_dif);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_collor);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, light_dir);
	glEnable(GL_LIGHT0);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess);
	glGenTextures(1, &tex);
	glBindTexture(GL_TEXTURE_2D, tex);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	//for (int i = 0; i < 8; i++) {
	//	glGenTextures(1, &tex_2[i]);
	//	glBindTexture(GL_TEXTURE_2D, tex_2[i]);
	//	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, &image_2[i]);
		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		//glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
//	}


	theTorus = glGenLists(1);
	glNewList(theTorus, GL_COMPILE);
	drawOkta_2();
	glEndList();
}
void Timer_Func(int value)
{
	//angle_y += speed_change;
	//angle_yO += speed_changeO;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	if(m==1) drawOkta();
	else {
		glLoadIdentity();
		glPushMatrix();
		if (okta_speed == 1) {
			okta_angle += 1.0;
			if (okta_angle == 360) a = 0;
		}

		glRotatef(d*okta_angle*1.0, 0.0, 1.0, 0.0);
		glRotatef(l, 0.0, 0.0, 1.0);
		glCallList(theTorus);
		glPopMatrix();
	}
	drawSphere();
	drawLight();
	glutSwapBuffers();
	glutTimerFunc(10, Timer_Func, 1);
}
void keyboard_2(unsigned char key, int x, int y)
{
	switch (key)
	{
		
	case 'c': {
		//mask = true;
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		break;
	}
	case 'v': {
		//mask = false;
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
		break;
	}
	case 'm': {
		m *= -1;
		break;
	}
	case'l': {
		l += 1;
		if (l == 360) l = 0;
		break;
	}
	case'd': {
		d *= -1;
		okta_angle = 360 - okta_angle;
		break;
	}
	case 'f': {
		f *= -1;
		sphere_angle = 360 - sphere_angle;
		break;
	}
	
	case 'z': {
		text_e = 1;
		//mask = true;
		//glEnable(GL_TEXTURE_2D);
		break;
	}
	case 'x': {
		text_e = 0;
		//glDisable(GL_TEXTURE_2D);
		break;
	}
	case 'u': {
		glEnable(GL_LIGHTING);
		break;
	}
	case 'i': {
		glDisable(GL_LIGHTING);
		break;
	}
	case 'o':
	{
		mask = true;
		glEnable(GL_BLEND);
		break;
	}
	case 'p': {
		mask = false;
		glDisable(GL_BLEND);
		break;
	}
	case 'w': {
		sphere_speed = 0;
		break;
	}
	case 'q': {
		sphere_speed = 1;
		break;
	}
	case 'e': {
		okta_speed = 1;
		break;
	}
	case 'r': {
		okta_speed = 0;
		break;
	}
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
	gluPerspective(90.0, aspect, 1.0, 700.0); 
	glMatrixMode(GL_MODELVIEW); 
	//glLoadIdentity(); 
	//glTranslatef(0.0, 0.0, -10.0); 
}
void textures_init() {
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	unsigned error = lodepng_decode32_file(&image, &w, &h, falls_filename);
	//for (int i = 0; i < 1; i++) {
		//glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		//lodepng_decode32_file(&image_2[0], &w, &h, falls_filename_2[0]);
	//}
}

int main(int argc, char **argv)
{
	a = 0;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(640, 640);
	glutInitWindowPosition(1, 0);

	glutCreateWindow("weryy!");
	textures_init();

	init();	
	glutDisplayFunc(display_2);
	glutKeyboardFunc(keyboard_2);
	glutTimerFunc(10, Timer_Func, 1);
	glutMainLoop();

}