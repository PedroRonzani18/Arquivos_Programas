#include <GL/freeglut.h>
#include <stdio.h>
#include <SOIL/SOIL.h>
#include <SDL2/SDL_mixer.h>

#include "drawings.h"
#include "globalParameters.h"
#include "Planet.h"
#include "Space.h"

Space space;
static bool light0Ligada = 0;   // Luz branca ligada?
static bool light1Ligada = 0;   // Luz verde ligada?
static bool light2Ligada = 0;   // Luz verde ligada?
static float d = 1.0;           // Intensidade da cor difusa da luz branca
static float e = 1.0;           // Intensidade da cor especular da luz branca
static float m = 0.2;           // Intensidade da luz ambiente global
static float p = 1.0;           // A luz branca é posicional?
static float s = 50.0;          // Expoente especular do material (shininess)
static bool localViewer = false;
int xAngle = 0;
int yAngle = 0;
bool isLightingOn = true;
static float xMouse = 250, yMouse = 250;        // (x,y) do ponteiro do mouse
static float larguraJanela, alturaJanela;       // (w,h) da janela
int matShine = 50;
float z=3;

/* Propriedades das fontes de luz */
    float lightAmb[] = { 0.0, 0.0, 0.0, 1.0 }; // ??

    float lightDif0[] = { d, d, d, 1.0 }; // intensidade da difusa do branco
    float lightSpec0[] = { e, e, e, 1.0 }; // intensidade da especular do branco
    float lightPos0[] = { 0.0, 0.0, z, p }; // posição ?? da liz
                                            // p altera fonte direcional ou posicional (0 ou 1);
                                            // p=1 atravessa textura, mas menor
                                            // p=0 não atra\vessa mas é maior

    float lightDifAndSpec1[] = { 0.0, 1.0, 0.0, 1.0 }; // idem
    float lightPos1[] = { 1.0, 2.0, 0.0, 1.0 }; // idem

    float lightDifAndSpec2[] = { 1.0, 1.0, 0.0, 1.0 }; // idem
    float lightPos2[] = { -1.0, 2.0, 0.0, 1.0 }; // idem

    float globAmb[] = { m, m, m, 1.0 };

void configuraProjecao() // determina se é p ou o e muda para ortho ou frustrum
{
    float razaoAspecto = (float) glutGet(GLUT_WINDOW_WIDTH) / (float) glutGet(GLUT_WINDOW_HEIGHT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glFrustum(-razaoAspecto, razaoAspecto, -1.0, 1.0, 2, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void atualizaPropriedadesLuz()
{
    for(int i=0; i<3; i++)
        lightDif0[i] = d;

    for(int i=0; i<3; i++)
        lightSpec0[i] = e;

    lightPos0[3] = p;
    lightPos0[2] = z;

    for(int i=0; i<3; i++)
        globAmb[i] = m;

}

void atualizaCaracteristicaLuz()
{
    /* Propriedades da fonte de luz LIGHT0 */
        glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmb); // rgb da luz ambiente
        glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDif0);
        glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpec0);

    /* Propriedades da fonte de luz LIGHT1 */
        glLightfv(GL_LIGHT1, GL_AMBIENT, lightAmb);
        glLightfv(GL_LIGHT1, GL_DIFFUSE, lightDifAndSpec1);
        glLightfv(GL_LIGHT1, GL_SPECULAR, lightDifAndSpec1);

    /* Propriedads da fonte de luz LIGHT2 */
        glLightfv(GL_LIGHT2, GL_AMBIENT, lightAmb);
        glLightfv(GL_LIGHT2, GL_DIFFUSE, lightDifAndSpec2);
        glLightfv(GL_LIGHT2, GL_SPECULAR, lightDifAndSpec2);



    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globAmb);        // Luz ambiente global
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, localViewer);// Enable local viewpoint

    matShine = 100; // tem que variarcmom pressionamento de tela
    glMaterialf(GL_FRONT, GL_SHININESS, matShine);
}

void onOffFonteLuz()
{
    /* Ativa fonte de luz branca */
        if(light0Ligada) 
            glEnable(GL_LIGHT0);
        else glDisable(GL_LIGHT0);
    
    /* Ativa fonte de luz verde */
        if(light1Ligada) 
            glEnable(GL_LIGHT1);
        else glDisable(GL_LIGHT1);

        if(light2Ligada) 
            glEnable(GL_LIGHT2);
        else glDisable(GL_LIGHT2);
}

void setupCamera()
{
            // Posiciona a câmera de acordo com posição x,y do mouse na janela
        gluLookAt(1*(xMouse-larguraJanela/2)/(larguraJanela/16), -1*(yMouse-alturaJanela/2)/(alturaJanela/16) + 3, 5,
                0, 0, 0,
                0, 1, 0);
}

void desenhaFonteLuzBranca()
{
        /* Light0 e esfera indicativa (ou seta) */
        glPushMatrix();
            glRotatef(xAngle, 1.0, 0.0, 0.0); // Rotação no eixo x
            glRotatef(yAngle, 0.0, 1.0, 0.0); // Rotação no eixo y

            glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);
            glTranslatef(lightPos0[0], lightPos0[1], lightPos0[2]);
            glColor3f(d, d, d);
            
            if (light0Ligada){
                if (p) glutWireSphere(0.1, 8, 8); // Esfera indicativa
                else // Seta apontando na direção da fonte de luz direcional
                {
                    glLineWidth(3.0);
                    glBegin(GL_LINES);
                        glVertex3f(0.0, 0.0, 0.25);
                        glVertex3f(0.0, 0.0, -0.25);
                        glVertex3f(0.0, 0.0, -0.25);
                        glVertex3f(0.05, 0.0, -0.2);
                        glVertex3f(0.0, 0.0, -0.25);
                        glVertex3f(-0.05, 0.0, -0.2);
                    glEnd();
                    glLineWidth(1.0);
                }
            }
        glPopMatrix();
}

void desenhaFonteLuzVerde()
{
    /* Light1 e sua esfera indicativa */
        glPushMatrix();
            glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);
            glTranslatef(lightPos1[0], lightPos1[1], lightPos1[2]);
            glColor3f(0.0, 1.0, 0.0);
            
            if (light1Ligada) glutWireSphere(0.05, 8, 8);
        glPopMatrix();
}

void desenhafonteDOIDS()
{
    /* Light1 e sua esfera indicativa */
        glPushMatrix();
            glLightfv(GL_LIGHT2, GL_POSITION, lightPos2);
            glTranslatef(lightPos2[0], lightPos2[1], lightPos2[2]);
            glColor3f(1.0, 1.0, 0.0);
            if (light2Ligada) glutWireSphere(0.05, 8, 8);
        glPopMatrix();
}

void desenha()
{
    configuraProjecao();

    atualizaPropriedadesLuz();
    atualizaCaracteristicaLuz();
    onOffFonteLuz();

    /* Limpa a tela e o z-buffer */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    setupCamera();

    /* Desabilita iluminação para desenhar as esferas que representam as luzes */
        glDisable(GL_LIGHTING);

    desenhaFonteLuzBranca();
    desenhaFonteLuzVerde();
    desenhafonteDOIDS();

    if (isLightingOn) 
        glEnable(GL_LIGHTING);

    glColor3f(1, 1, 1);
    double tempo = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    space.drawAndMove(tempo);

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

    larguraJanela = width;
    alturaJanela = height;

    razaoAspecto = (float) glutGet(GLUT_WINDOW_WIDTH) / (float) glutGet(GLUT_WINDOW_HEIGHT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glFrustum(-razaoAspecto, razaoAspecto, -1.0, 1.0, 2, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

static void teclado(unsigned char key, int x, int y)
{
    char formattedKey = (char) toupper(key);

    switch (formattedKey)
    {
        case 27 :     // Tecla 'ESC
            exit(0);
            break;

        case 'M':
            if(!Mix_PlayingMusic())
                Mix_PlayMusic(music1,-1);
            else if(Mix_PausedMusic())
                Mix_ResumeMusic();
            else
                Mix_PauseMusic();
            break;

        case 'R':
            xAngle++;
            break;

        case 'E':
            yAngle++;
            break;

        case 'L':
            isLightingOn = !isLightingOn;
            break;

        case 'W':
            if (light0Ligada) light0Ligada = false;
            else light0Ligada = true;
            break;

        case 'G':
            if (light1Ligada) light1Ligada = false;
            else light1Ligada = true;
            break;

        case 'P':
            if (p) p = 0.0;
            else p = 1.0;
            break;

        case 'T':
            usarTextura = !usarTextura;
            break;

        case 'B':
            if (light2Ligada) light2Ligada = false;
            else light2Ligada = true;
            break;
        

        case 'Z':
            z--;
            break;
    }

    glutPostRedisplay();
}

void enables()
{
    // Não mostrar faces do lado de dentro
    glEnable(GL_CULL_FACE); 
    glCullFace(GL_BACK);

    // Ativa teste Z
    glEnable(GL_DEPTH_TEST);
    //glDepthFunc(GL_LESS);

    //glEnable(GL_BLEND);
    //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glEnable(GL_LIGHT0); // "liga" a possivel fonte de luz 0
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
}

void configuraTextures()
{
    sol = loadTexture("imagens/2k_sun.jpg");
    terra = loadTexture("imagens/2k_earth_daymap.jpg");
    lua = loadTexture("imagens/2k_moon.jpg");
    estrelas = loadTexture("imagens/2k_stars_milky_way.jpg");
}

Planet createPlanetTemplate(GLuint texture, double coreRadius, double rotationRadius, double angularSpeed)
{
    Planet p;
    p.setTexture(texture);
    p.setCoreRadius(coreRadius);
    p.setRotationRadius(rotationRadius);
    p.setAngularSpeed(angularSpeed);
    return p;
}

void configuraMateriais()
{
    // Propriedades do material da esfera
    float matAmbAndDif[] = {1.0, 1.0, 1.0, 1.0};    // cor ambiente e difusa: branca (ambiente = cor | )
    float matSpec[] = { 1.0, 1.0, 1,0, 1.0};       // cor especular: branca
    //float matEmiss[] = { 1, 1, 1, 1};         // faz com que todos os materiais emitam luz

    // Definindo as propriedades do material
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, matAmbAndDif);
    glMaterialfv(GL_FRONT, GL_SPECULAR, matSpec);
    glMaterialf(GL_FRONT, GL_SHININESS, 0);
    //glMaterialfv(GL_FRONT, GL_EMISSION, matEmiss);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
}

void initPlanets()
{
    //Planet sun(sol,1,0,1);
    Planet sun = createPlanetTemplate(sol,1,0,10);
    space.addPlaneta(sun);

    Planet earth = createPlanetTemplate(terra,0.4,1.8,20);
    space.addPlaneta(earth);

    Planet moon = createPlanetTemplate(lua,0.15,0.6,50);
    space.addPlaneta(moon);
}

void configureMusic()
{
    Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,2,4096);
    music1 = Mix_LoadMUS("audio/background.mp3");
    
}

void init()
{
    glClearColor(0,0,0,1);

    enables();
    configuraTextures();
    configuraMateriais();

    configureMusic();
    initPlanets();
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