#include <GL/freeglut.h>
#include <stdio.h>
#include <SOIL/SOIL.h>

int slices = 16, stacks = 16;
int angle=60;
GLuint sol, terra, lua, estrelas;
float razaoAspecto;

void configuraProjecao() // determina se é p ou o e muda para ortho ou frustrum
{
    float razaoAspecto = (float) glutGet(GLUT_WINDOW_WIDTH) / (float) glutGet(GLUT_WINDOW_HEIGHT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glFrustum(-razaoAspecto, razaoAspecto, -1.0, 1.0, 2, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void drawSolidSphere(double radius, int stacks, int columns)
{
    GLUquadric* quadObj = gluNewQuadric(); // cira uma quadrica 
    gluQuadricDrawStyle(quadObj, GLU_FILL); // estilo preenchido
    gluQuadricNormals(quadObj, GLU_SMOOTH);
    gluQuadricTexture(quadObj, GL_TRUE); // chama 01 glTexCoord por vértice
    gluSphere(quadObj, radius, stacks, columns); // cria os vértices de uma esfera
    gluDeleteQuadric(quadObj);
}

void drawSun(double angle)
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, sol);

    glTranslated(0,0,-6);// coloca ele mais para tras na tela
    glRotated(-60,1,0,0); // rotaciona para frente para dar mais visibilidade na rotação
    glRotated(angle,0,0,1); // rotaciona no proprio eixo 
    //glutSolidSphere(1,slices,stacks);
    drawSolidSphere(1,slices,stacks);
}

void drawEarth(double angle)
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, terra);

    glRotated(angle,0,0,1); 
    glTranslated(-1.8,0, 0); // determina o raio da rotação (e indiretamente o centro de rotação)
    //glutSolidSphere(0.4,slices,stacks);
    drawSolidSphere(0.4,slices,stacks);
}

void drawMoon(double angle)
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, lua);

    glRotated(angle*2,0,0,1);
    glTranslated(-0.6,0, 0); 
    //glutSolidSphere(0.17,slices,stacks);
    drawSolidSphere(0.15,slices,stacks);
}

void drawBackground(double z)
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, estrelas);
    glColor3f(1,1,1);
    glBegin(GL_TRIANGLE_FAN);

    double x = razaoAspecto * 10;
    double y = 10;

    glBegin(GL_TRIANGLE_FAN);
        glTexCoord2f(0,0); 
        glVertex3f (-x,-y,z);

        glTexCoord2f(1,0);
        glVertex3f (x,-y,z);

        glTexCoord2f(1,1);
        glVertex3f (x,y,z);

        glTexCoord2f(0,1);
        glVertex3f(-x,y,z);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

void desenha()
{
    configuraProjecao();

    double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;

    double a = t*10.0;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
        glTranslated(0,0,-10);
        //drawBackground(-10);
    glPopMatrix();

    glPushMatrix();

        drawSun(a);

        glPushMatrix();

            drawEarth(a);

            glPushMatrix();
                drawMoon(a);
            glPopMatrix();

        glPopMatrix();

    glPopMatrix();

    glutSwapBuffers();
}

void timer(int t)
{
    glutPostRedisplay();
    glutTimerFunc(t, timer, t);
}

void redimensiona(int width, int height)
{
    glViewport(0, 0, width, height);

    razaoAspecto = (float) glutGet(GLUT_WINDOW_WIDTH) / (float) glutGet(GLUT_WINDOW_HEIGHT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glFrustum(-razaoAspecto, razaoAspecto, -1.0, 1.0, 2, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}

static void teclado(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27 :     // Tecla 'ESC
            exit(0);
            break;

        case '+':
            slices++;
            stacks++;
            break;

        case '-':
            if (slices>3 && stacks>3)
            {
                slices--;
                stacks--;
            }
            break;

        case 'l':
            angle+=2;
            break;

    }

    glutPostRedisplay();
}

GLuint loadTexture(const char* arquivo)
{
    GLuint idTextura = SOIL_load_OGL_texture(
        arquivo,
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
    );

    if (idTextura == 0) {
        printf("Erro do SOIL: '%s' + %s\n", SOIL_last_result(),arquivo);
    }

    return idTextura;
}

void enables()
{
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glEnable(GL_LIGHT0); // "liga" a possivel fonte de luz 0
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
}

void initializeTextures()
{
    sol = loadTexture("imagens/2k_sun.jpg");
    terra = loadTexture("imagens/2k_earth_daymap.jpg");
    lua = loadTexture("imagens/2k_moon.jpg");
    estrelas = loadTexture("imagens/2k_stars_milky_way.jpg");
}

void init()
{
    glClearColor(1,1,1,1);

    enables();
    initializeTextures();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("Lista 3");
    init();

    glutReshapeFunc(redimensiona);
    glutDisplayFunc(desenha);
    glutKeyboardFunc(teclado);
    glutTimerFunc(8, timer, 8);

    glutMainLoop();

    return EXIT_SUCCESS;
}