#include <GL/freeglut.h>
#include <stdio.h>

float aspectRatio = 1;
GLuint thePlane;

float move_x = 5, move_y = 5;
double posi_x = 0, posi_y = 0;

static void plane(void)
{
    glColor3f(0.5, 0.5, 0.5); //cinza
    
    glBegin(GL_TRIANGLES);
        // ponta
        glVertex3f(0, 25, 0);
        glVertex3f(-5, 15, 0);
        glVertex3f(5, 15, 0);
        // tronco
        glVertex3f( -5, 15,  0);
        glVertex3f(  5, 15,  0);
        glVertex3f( -5, -20, 0);
        glVertex3f(  5, 15,  0);
        glVertex3f( -5, -20, 0);
        glVertex3f(  5, -20, 0);
        // caldae
        glVertex3f( -5, -20, 0);
        glVertex3f(-15, -30, 0);
        glVertex3f( -5, -15, 0);
        // caldad
        glVertex3f(  5,-20, 0);
        glVertex3f( 15,-30, 0);
        glVertex3f(  5,-15, 0);
        // asa_d
        glVertex3f(  5,  5, 0);
        glVertex3f(  5,  0, 0);
        glVertex3f( 20,-10, 0);
        // asa_e
        glVertex3f( -5,  0, 0);
        glVertex3f(-20,-10, 0);
        glVertex3f( -5,  5, 0);
    glEnd();

    glColor3f(0, 0, 1); // azul

    glBegin(GL_TRIANGLES);
        //asa_d
        glVertex3f(  5,  0, 0);
        glVertex3f( 20,-10, 0);
        glVertex3f(  5, -5, 0);
        //asa_e
        glVertex3f( -5,  0, 0);
        glVertex3f(-20,-10, 0);
        glVertex3f( -5, -5, 0);
        //calda_d
        glVertex3f(  0,-20, 0);
        glVertex3f( 15,-30, 0);
        glVertex3f(  0,-15, 0);
        //calda_e
        glVertex3f(  0,-20, 0);
        glVertex3f(-15,-30, 0);
        glVertex3f(  0,-15, 0);
    glEnd();
}

void inicializar(void) 
{
    thePlane = glGenLists(1);
    glNewList(thePlane, GL_COMPILE); // declaro o que está dentro da lista e chamo ela de "thePlane"
        plane();
    glEndList();
    glClearColor(0.60, 0.847, 0.93, 6); // preparo para a lista ser executada
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
        glTranslatef(posi_x, posi_y, 0);
        glCallList(thePlane); // executa a lista
    glPopMatrix();
    //veiculo1()
    //veiculo2()
    glutSwapBuffers();
}

void reshape(int w, int h)
{
    aspectRatio = (float)glutGet(GLUT_WINDOW_WIDTH) / (float)glutGet(GLUT_WINDOW_HEIGHT);
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-100 * aspectRatio, 100 * aspectRatio, -100 , 100, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key){
        case 27: 
            exit(0); 
            break;
            
        case 119: // w
            posi_y += move_y;
            glutPostRedisplay();
            break;

        case 115: // s
            posi_y -= move_y;
            glutPostRedisplay();
            break;

        case 100: // d
            posi_x += move_x;
            glutPostRedisplay();
            break;

        case  97: // a
            posi_x -= move_x;
            glutPostRedisplay();
            break;
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Lista 2");

    inicializar();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}