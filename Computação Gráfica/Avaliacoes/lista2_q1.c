#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <GL/freeglut.h>
#include <math.h>

#define radianoParaGraus(radianos) (radianos * (180.0 / M_PI))
#define grausParaRadianos(graus) ((graus * M_PI) / 180.0)

//variaveis globais
double proporcao_tela=1;
float proporcao_aviao=20.0;//proporcao do deseneho do aviao
int valid_x=1,valid_y=1,valid_2x=1,valid_2y=1;//ablbueblasd coisas para ajudar na validacao da IA
int keys[5]={0,0,0,0,0};//armazana o presionamento das teclas
GLuint Draw_player, Draw_npc1, Draw_npc2,Draw_missel,Draw_npc3,Draw_npc4,Draw_npc5; 

typedef struct {
  double xpos;
  double ypos;
  double angle;
  double movement;
int on_screen;
int alive;
}Objeto;

//[0]=player,[1]atack,[2 to 6]npc1,2,3,4,5

Objeto lista[7] ={
  {0.0, 0.0, 0.0, 2.5, 1, 1},//player
  {0.0, 0.0, 0.0, 4.5, 0, 1},//atack
  {0.0, 60.0, 0.0, 1.1, 1, 1},//npc1
  {60.0, 60.0, 0.0, 0.875, 1, 1},//npc2
  {90.0, 70.0, 0.0, 0.0, 1, 1},//npc3
  {0.0, 80.0, 270.0, 2.5, 1, 1},//npc4
  {-80.0, 0.0, 0.0, 2.5, 1,1}//npc5
 };

//se estiver na tela
int on_screenn(Objeto batata){

  if(batata.xpos<=100*proporcao_tela +5.0 && batata.xpos>=-100*proporcao_tela -5.0 && batata.ypos<=100 +5.0 &&batata.ypos>=-100-5.0)
    return 1;
  else
    return 0;

}

//sistema de colisao por raios
void hitbox(){

  double soma_raios = 0.5*proporcao_aviao + 0.5*proporcao_aviao;
  double soma_atack= 2.5+0.5*proporcao_aviao;
  double distancia =0.0;

  printf("npc1 = %d ,npc2 =%d, alive=%d\n",lista[2].alive,lista[3].alive,lista[0].alive);
  for(int x= 2;x<7;x++){
    distancia =sqrt(pow(lista[0].xpos-lista[x].xpos,2)+pow(lista[0].ypos-lista[x].ypos,2));
    if(distancia <soma_raios){
      lista[0].alive=0;
    }

  }

  for(int x= 2;x<7;x++){
    distancia =sqrt(pow(lista[1].xpos-lista[x].xpos,2)+pow(lista[1].ypos-lista[x].ypos,2));
    if(distancia<soma_atack){
      lista[x].alive=0;
      lista[x].movement =0;
      lista[x].xpos=300;
      lista[x].ypos=300;
    }
  }
  
}

//printa que o jogo acabou
void crash(){
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0.0, 0.0, 0.0); 
  glRasterPos2f(-20.0, 0.0);

  glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, "Game Over");

}

//condicao de ganhar
void ganhou(){
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0.0, 0.0, 0.0); 
  glRasterPos2f(-20.0, 0.0);

  glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, "Voce Venceu");

}

//reseta para as condicoes originais do jogo
void restart(){
  valid_x=1;valid_y=1;valid_2x=1;valid_2y=1;
  lista[0].xpos=0.0;
  lista[0].ypos=0.0;
  lista[0].alive=1.0;
  lista[0].angle=0.0;
  lista[1].xpos=1000;
  lista[1].ypos=1000;
  lista[1].angle=0;
  lista[2].xpos=0.0;
  lista[2].ypos=60.0;
  lista[2].alive=1;
  lista[2].movement=  1.1;
  lista[3].xpos=60.0;
  lista[3].ypos=60.0;
  lista[3].alive=1;
  lista[3].movement= 0.875;
  lista[4].xpos=90.0;
  lista[4].ypos=70.0;
  lista[4].alive=1;
  lista[5].xpos=0.0;
  lista[5].ypos=80.0;
  lista[5].alive=1;
  lista[5].movement= 2.5;
  lista[5].angle=270;
  lista[6].xpos=-80.0;
  lista[6].ypos=0.0;
  lista[6].alive=1;
  lista[6].movement= 2.5;
  lista[6].angle=0;
}
//efeitos foguetes, nao consegui com a lista pois essa funcao tem q ser desenhada manualmente se for acionada

void Missel(){

  glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-2.5,0.0,0.0);
    glVertex3f(0.0,3.0,0.0);
    glVertex3f(2.5,0.0,0.0);
  glEnd();

  glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.9,0.2,0.0);
    glVertex3f(0.0,0.0,0.0);
    glVertex3f(-1.0,-0.5,0.0);
    glVertex3f(0.0,-1.5,0.0);
    glVertex3f(1.0,-0.5,0.0);
  glEnd();

}

//descricao dos controles
void description(){
  glColor3f(0.0, 0.0, 0.0); 
  glRasterPos2f(-95.0, -90.0);

  glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, "w a s d e setas para movimentar spaco para atirar");
}

void Player_efects(){

  glPushMatrix();
    glTranslated(lista[0].xpos,lista[0].ypos,0.0);
    glRotated(lista[0].angle,0,0,1);
    if(keys[0]){
      //foguinho
      glBegin(GL_TRIANGLE_FAN);
        glColor3d(0.8,0.0,0.2);
        glVertex3d(0.0*proporcao_aviao,-0.7*proporcao_aviao,0.0f);
        glVertex3d(0.05*proporcao_aviao,-0.75*proporcao_aviao,0.0f);
        glVertex3d(0.0*proporcao_aviao,-0.85*proporcao_aviao,0.0f);
        glVertex3d(-0.05*proporcao_aviao,-0.75*proporcao_aviao,0.0f);

      glEnd();
    }
    if(keys[1]){
      glBegin(GL_TRIANGLE_FAN);
        glColor3d(0.8,0.0,0.2);
        //ini -0.5 0.35
        glVertex3d(-0.5*proporcao_aviao,0.35*proporcao_aviao,0.0f);
        glVertex3d(-0.55*proporcao_aviao,0.4*proporcao_aviao,0.0f);
        glVertex3d(-0.5*proporcao_aviao,0.5*proporcao_aviao,0.0f);
        glVertex3d(-0.45*proporcao_aviao,0.4*proporcao_aviao,0.0f);
      glEnd();

      glBegin(GL_TRIANGLE_FAN);
        glColor3d(0.8,0.0,0.2);
        //ini 0.5 0.35
        glVertex3d(0.5*proporcao_aviao,0.35*proporcao_aviao,0.0f);
        glVertex3d(0.55*proporcao_aviao,0.4*proporcao_aviao,0.0f);
        glVertex3d(0.5*proporcao_aviao,0.5*proporcao_aviao,0.0f);
        glVertex3d(0.45*proporcao_aviao,0.4*proporcao_aviao,0.0f);
      glEnd();
    }
    if(keys[2]){
      glBegin(GL_TRIANGLE_FAN);
        glColor3d(0.8,0.0,0.2);
        //ini -0.5 0.35
        glVertex3d(-0.5*proporcao_aviao,0.35*proporcao_aviao,0.0f);
        glVertex3d(-0.55*proporcao_aviao,+0.35*proporcao_aviao,0.0f);
        glVertex3d(-0.6*proporcao_aviao,+0.25*proporcao_aviao,0.0f);
        glVertex3d(-0.5*proporcao_aviao,+0.30*proporcao_aviao,0.0f);
      glEnd();
    }
    if(keys[3]){
      glBegin(GL_TRIANGLE_FAN);
        glColor3d(0.8,0.0,0.2);
        //ini 0.5 0.35
        glVertex3d(0.5*proporcao_aviao,0.35*proporcao_aviao,0.0f);
        glVertex3d(0.55*proporcao_aviao,+0.35*proporcao_aviao,0.0f);
        glVertex3d(0.6*proporcao_aviao,+0.25*proporcao_aviao,0.0f);
        glVertex3d(0.5*proporcao_aviao,+0.30*proporcao_aviao,0.0f);
      glEnd();
    }
  glPopMatrix();

    
  if(keys[4]==1 && lista[1].on_screen==0){
    lista[1].xpos = lista[0].xpos;
    lista[1].ypos = lista[0].ypos;
    lista[1].angle= lista[0].angle;
    lista[1].on_screen=1;
  }
  if(lista[1].on_screen==1){
    double angulo1=grausParaRadianos(lista[1].angle);
    lista[1].xpos-=(sin(angulo1)*lista[1].movement);
    lista[1].ypos+=(cos(angulo1)*lista[1].movement);
    glPushMatrix();
      glTranslated(lista[1].xpos,lista[1].ypos,0.0);
      glRotated(lista[1].angle,0,0,1);
      glCallList(Draw_missel);
    glPopMatrix();
  }

}
//modelo do foguete do player
void Draw(){
  
  //ASA DIREITA
  glBegin(GL_TRIANGLE_FAN );
    glColor3d(0.5,0.5,0.5);
    glVertex3d(+0.0f*proporcao_aviao,-0.5*proporcao_aviao,0.0f);
    glVertex3d(+0.5f*proporcao_aviao,+0.35f*proporcao_aviao,0.0f);
    glVertex3d(+0.5f*proporcao_aviao,+0.2f*proporcao_aviao,0.0f);
    glVertex3d(+0.0f*proporcao_aviao,+-0.7f*proporcao_aviao,0.0f);
  glEnd();

  //ASA ESQUERDA
  glBegin(GL_TRIANGLE_FAN);
    glColor3d(0.5,0.5,0.5);
    glVertex3d(+0.0f*proporcao_aviao,-0.5*proporcao_aviao,0.0f);
    glVertex3d(-0.5f*proporcao_aviao,+0.35f*proporcao_aviao,0.0f);
    glVertex3d(-0.5f*proporcao_aviao,+0.2f*proporcao_aviao,0.0f);
    glVertex3d(-0.0f*proporcao_aviao,+-0.7f*proporcao_aviao,0.0f);
  glEnd();  

  //TRONCO
  glBegin(GL_TRIANGLE_FAN);
    glColor3d(0.5,0.5,0.5);
    glVertex3d(-0.08*proporcao_aviao,-0.5*proporcao_aviao,0.0f);    
    glVertex3d(-0.08*proporcao_aviao,0.3*proporcao_aviao,0.0f);
    glVertex3d(0.08*proporcao_aviao,0.3*proporcao_aviao,0.0f);
    glVertex3d(0.08*proporcao_aviao,-0.5*proporcao_aviao,0.0f);
  glEnd();

  //CABINE
  glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.0,0.7,0.0);
    glVertex3d(0.08*proporcao_aviao,0.3*proporcao_aviao,0.0f);
    glVertex3d(0.0*proporcao_aviao,0.5*proporcao_aviao,0.0f);
    glVertex3d(-0.08*proporcao_aviao,0.3*proporcao_aviao,0.0f);
  glEnd();
}
//modelo do foguete dos npcs
void Draw2(){
  
  //ASA DIREITA
  glBegin(GL_TRIANGLE_FAN );
    glColor3d(0.2,0.2,0.2);
    glVertex3d(+0.0f*proporcao_aviao,0.3*proporcao_aviao,0.0f);
    glVertex3d(+0.55f*proporcao_aviao,+0.25f*proporcao_aviao,0.0f);
    glVertex3d(+0.5f*proporcao_aviao,+0.15f*proporcao_aviao,0.0f);
    glVertex3d(+0.0f*proporcao_aviao,+-0.1f*proporcao_aviao,0.0f);
  glEnd();

  //ASA ESQUERDA
  glBegin(GL_TRIANGLE_FAN);
    glColor3d(0.2,0.2,0.2);
    glVertex3d(+0.0f*proporcao_aviao,0.3*proporcao_aviao,0.0f);
    glVertex3d(-0.55f*proporcao_aviao,+0.25f*proporcao_aviao,0.0f);
    glVertex3d(-0.5f*proporcao_aviao,+0.15f*proporcao_aviao,0.0f);
    glVertex3d(-0.0f*proporcao_aviao,-0.1f*proporcao_aviao,0.0f);
  glEnd();  

  //TRONCO
  glBegin(GL_TRIANGLE_FAN);
    glColor3d(0.2,0.2,0.2);
    glVertex3d(-0.09*proporcao_aviao,-0.4*proporcao_aviao,0.0f);    
    glVertex3d(-0.09*proporcao_aviao,0.3*proporcao_aviao,0.0f);
    glVertex3d(0.09*proporcao_aviao,0.3*proporcao_aviao,0.0f);
    glVertex3d(0.09*proporcao_aviao,-0.4*proporcao_aviao,0.0f);
  glEnd();

  //CABINE
  glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.5,0.0,0.0);
    glVertex3d(0.08*proporcao_aviao,0.3*proporcao_aviao,0.0f);
    glVertex3d(0.0*proporcao_aviao,0.5*proporcao_aviao,0.0f);
    glVertex3d(-0.08*proporcao_aviao,0.3*proporcao_aviao,0.0f);
  glEnd();
}

void Draw3(){
	glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.0,0.0,0.0);
		glVertex3f(0.0, 0.0,-0.1); 
		for(int i = 0; i <= 20;i++){
      glColor3f(0.5,0.8,0.9); 
			glVertex3f(0.0 + (8 * cos(i *  2.0*M_PI / 20)),0.0 + (8 * sin(i * 2.0*M_PI / 20)),-0.1 );
      }
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0,1.0,1.0);
		glVertex3f(0.0, 0.0,0.0); 
		for(int i = 0; i <= 20;i++){ 
      glColor3f((float)i/20,(float)i/20,(float)i/20);
			glVertex3f(0.0 + (2 * cos(i *  2.0*M_PI / 20)),0.0 + (2 * sin(i * 2.0*M_PI / 20)) ,0.0);
      }

	glEnd();
}

//logica para mover os desenhos na tela
void Physics(){

  //movimento player
  {
  double angulo = grausParaRadianos(lista[0].angle),angulo2,angulo3;
  lista[0].xpos-= (keys[0]-keys[1])*sin(angulo)*lista[0].movement;
  lista[0].ypos+= (keys[0]-keys[1])*cos(angulo)*lista[0].movement;
  lista[0].angle-=(keys[2]-keys[3])*4.0;


  glPushMatrix();
    glTranslated(lista[0].xpos,lista[0].ypos,0.0);
    glRotated(lista[0].angle,0,0,1);
    glCallList(Draw_player);
  glPopMatrix();
  }

  //desinteligentecia artificial para as naves
  //nave1
  {
  if(valid_x==1)
    lista[2].xpos+= lista[2].movement;
  else
    lista[2].xpos-= lista[2].movement;
  
  if(lista[2].xpos>=120)
    valid_x=0;
  if(lista[2].xpos<=-120)
    valid_x=1;

  if(valid_y==1){
    lista[2].ypos+= pow(lista[2].xpos/80,2.0) -0.06*lista[2].xpos ;
  }
  else
    lista[2].ypos-= pow(lista[2].xpos/80,2.0) -0.06*lista[2].xpos ;
  if(lista[2].ypos>=120){
    valid_y=0;
    lista[2].ypos=120;
    }

  if(lista[2].ypos<=-120){
    valid_y=1;
    lista[2].ypos=-120;
    }
  if(on_screenn(lista[2])){
    glPushMatrix();
      glTranslated(lista[2].xpos,lista[2].ypos,0.0);
      glRotated(lista[2].angle,0,0,1);
      glCallList(Draw_npc1);
    glPopMatrix();}
  }

  //nave2
  {
  if(valid_2x==1)
    lista[3].xpos+= lista[3].movement*3;
  else
    lista[3].xpos-= lista[3].movement*3;
  
  if(valid_2y==1)
    lista[3].ypos+= lista[3].movement/2;
  else
    lista[3].ypos-= lista[3].movement/2;

  if(lista[3].xpos>=100*proporcao_tela)
    valid_2x=0;
  if(lista[3].xpos<=-100*proporcao_tela)
    valid_2x=1;
  if(lista[3].ypos>=115)
    valid_2y=0;
  if(lista[3].ypos<=-115)
    valid_2y=1;
  

  if(on_screenn(lista[3])){
    glPushMatrix();
      glTranslated(lista[3].xpos,lista[3].ypos,0.0);
      glRotated(lista[3].angle,0,0,1);
      glCallList(Draw_npc2);
    glPopMatrix();}
  }
  //nave3 estacionaria
  {
  if(on_screenn(lista[4])){
    glPushMatrix();
      glTranslated(lista[4].xpos,lista[4].ypos,0.0);
      glRotated(lista[4].angle,0,0,1);
      glCallList(Draw_npc3);
    glPopMatrix();
  }    
  }
  //nave 4 anda somente no eixo X
  {
    lista[5].xpos+=lista[5].movement;
    if(lista[5].xpos>=100){
      lista[5].movement*=-1;
      lista[5].angle=90;
      }
    if(lista[5].xpos<=-100){
      lista[5].movement*=-1;
      lista[5].angle=270;
      }

    if(on_screenn(lista[5])){
      glPushMatrix();
        glTranslated(lista[5].xpos,lista[5].ypos,0.0);
        glRotated(lista[5].angle,0,0,1);
        glCallList(Draw_npc4);
      glPopMatrix();
    }

  }

  //nave 5 anda somente no eixo y
  {
    lista[6].ypos+=lista[6].movement;
    if(lista[6].ypos>=100){
      lista[6].movement*=-1;
      lista[6].angle=180;
      }
    if(lista[6].ypos<=-100){
      lista[6].movement*=-1;
      lista[6].angle=0;
      }

    if(on_screenn(lista[6])){
      glPushMatrix();
        glTranslated(lista[6].xpos,lista[6].ypos,0.0);
        glRotated(lista[6].angle,0,0,1);
        glCallList(Draw_npc5);
      glPopMatrix();
    }

  }
  //atack da nave
  if(!on_screenn(lista[1])){
    lista[1].on_screen=0;
    lista[1].xpos=-15000;
    }
}

//fixar nave na tela
void World_limits(){

  if(proporcao_tela>=1){
  if(lista[0].xpos>=100*proporcao_tela-0.5*proporcao_aviao){
    lista[0].xpos=100*proporcao_tela-0.5*proporcao_aviao;
  }
  if(lista[0].xpos<=-100*proporcao_tela+0.5*proporcao_aviao){
    lista[0].xpos=-100*proporcao_tela+0.5*proporcao_aviao;
  }
  if(lista[0].ypos>=100-0.5*proporcao_aviao){
    lista[0].ypos=100-0.5*proporcao_aviao;
  }
  if(lista[0].ypos<=-100+0.5*proporcao_aviao){
    lista[0].ypos=-100+0.5*proporcao_aviao;
  }
  }
  else{
  if(lista[0].xpos>=100-0.5*proporcao_aviao){
    lista[0].xpos=100-0.5*proporcao_aviao;
  }
  if(lista[0].xpos<=-100+0.5*proporcao_aviao){
    lista[0].xpos=-100+0.5*proporcao_aviao;
  }
  if(lista[0].ypos>=100/proporcao_tela-0.5*proporcao_aviao){
    lista[0].ypos=100/proporcao_tela-0.5*proporcao_aviao;
  }
  if(lista[0].ypos<=-100/proporcao_tela+0.5*proporcao_aviao){
    lista[0].ypos=-100/proporcao_tela+0.5*proporcao_aviao;
  }
  }


}
//mudar a proporcao da tela
static void Reshape(int new_w,int new_h){

  proporcao_tela = (float)new_w/(float)new_h;

  glViewport(0,0,new_w,new_h);

  glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(new_w>=new_h)
      glOrtho(-100.0 *proporcao_tela,100.0f*proporcao_tela,-100.0f,100.0f,-1.0f, 1.0f);
    else
      glOrtho(-100.0 ,100.0f,-100.0f/proporcao_tela,100.0f/proporcao_tela,-1.0f, 1.0f);

  glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
}
//trata os eventos do teclado e armazena num vetor de int
static void teclado(unsigned char key, int x, int y){

  switch (key)
  {
  //key =0
  case 'w':
  case 'W':
  if(keys[0]){
    keys[0]=0;
  }
  else
    keys[0]=1;

  break;

  //key =1
  case 's':
  case 'S':
  if(keys[1]){
    keys[1]=0;
  }
  else
    keys[1]=1;
  break;

  //key =2
  case 'd':
  case 'D':
  if(keys[2]){
    keys[2]=0;
  }
  else
    keys[2]=1;
  break;

  //key=3
  case 'a':
  case 'A':
  if(keys[3]){
    keys[3]=0;
  }
  else
    keys[3]=1;
  break;

  case ' ':
  if(keys[4]){
    keys[4]=0;
  }
  else
    keys[4]=1;

  }

}

//teclado so para as setas:
static void teclado2(unsigned char key, int x, int y){

  switch (key)
  {
  //key =0
  case GLUT_KEY_UP:
  if(keys[0]){
    keys[0]=0;
  }
  else
    keys[0]=1;

  break;

  //key =1
  case GLUT_KEY_DOWN:
  if(keys[1]){
    keys[1]=0;
  }
  else
    keys[1]=1;
  break;

  //key =2
  case GLUT_KEY_RIGHT:
  if(keys[2]){
    keys[2]=0;
  }
  else
    keys[2]=1;
  break;

  //key=3
  case GLUT_KEY_LEFT:
  if(keys[3]){
    keys[3]=0;
  }
  else
    keys[3]=1;
  break;

  }
}

void timer(int x){


  hitbox();
  World_limits();
  if(lista[0].alive==1 && (lista[2].alive +lista[3].alive+lista[4].alive+lista[5].alive+lista[6].alive>0)){
    glutTimerFunc(1000/40,timer,0);
    glutPostRedisplay();
    }
  else{
    glutPostRedisplay(); 
    glutTimerFunc(3000,timer,0);
     
  }

}

void init(){
  glClearColor(1,1,1,0);
  Draw_player = glGenLists(1);
  Draw_npc1 = glGenLists(1);
  Draw_npc2 = glGenLists(1);
  Draw_npc3 = glGenLists(1);
  Draw_npc4 = glGenLists(1);
  Draw_npc5 = glGenLists(1);
  Draw_missel = glGenLists(1);

  glNewList(Draw_player,GL_COMPILE);
    Draw();
  glEndList();

  glNewList(Draw_npc1,GL_COMPILE);
    Draw2();
  glEndList();

  glNewList(Draw_npc2,GL_COMPILE);
    Draw3();
  glEndList();

  glNewList(Draw_npc3,GL_COMPILE);
    Draw3();
  glEndList();

  glNewList(Draw_npc4,GL_COMPILE);
    Draw2();
  glEndList();

  glNewList(Draw_npc5,GL_COMPILE);
    Draw2();
  glEndList();

  glNewList(Draw_missel,GL_COMPILE);
    Missel();
  glEndList();
  
}

void cena(){
  glClear(GL_COLOR_BUFFER_BIT);
  Physics();
  Player_efects();
  description();
  if(lista[0].alive==0){
    crash();
    restart();
  }
  if(lista[2].alive+ lista[3].alive+lista[4].alive+lista[5].alive+lista[6].alive==0){
    ganhou();
    restart();
  }
  
  glutSwapBuffers();
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
  glutInitWindowPosition(320,180);
  glutInitWindowSize(720,480);
  glutCreateWindow("navinha andante!");
  init();
  glutIgnoreKeyRepeat(1);

  //redimensionamento
  glutReshapeFunc(Reshape);

  //presionamento de tecla
  glutKeyboardFunc(teclado);
  glutKeyboardUpFunc(teclado);
  glutSpecialFunc(teclado2);
  glutSpecialUpFunc(teclado2);


  //atualiza tudo
  glutDisplayFunc(cena);
  glutTimerFunc(0,timer,0);
  glutMainLoop();

  return 0;            
}
