int listaAnel;

void desenhaCena() {
  glColor3f(0, 0, 1);       // azul
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glCallList(listaAnel);    // chama a lista

  glColor3f(0, 0, 0);       // preto
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glCallList(listaAnel);    // chama a lista
}

void criaListaAnelQuadrado() {
  listaAnel = glGenLists(1); //gera uma lista e retorna id
  glNewList(listaAnel,  GL_COMPILE); //... e renderizado  em compilação  
    glBegin(GL_TRIANGLE_STRIP);
      // os 10 vértices
    glEnd();
  glEndList();
}

int main(int c, char** v) {
  //...
  glutDisplayFunc(desenhaCena);
  criaListaAnelQuadrado();
  glutMainLoop();
}