// ao inves de deslocar o objeto de lugar udamos o sistema dfe coordenadas da origem

/*Damos as coordenadas assumindo que estamos na origem, mas transladamos o objeto 
para onde queremos que ele realmente seja desenhado*/

glPushMatrix();                 // empilha uma copia do sistema de coordenadas atual (no topo)
    glTranslatef(nave.x, nave.y, 0); //translada e rotaciona o sistema de coordenadas
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(-nave.larg/2, -nave.alt/2); // v3---v2  //coordenadas permanecem constantes
        glVertex2f( nave.larg/2, -nave.alt/2); // |     |
        glVertex2f( nave.larg/2,  nave.alt/2); // |     |
        glVertex2f(-nave.larg/2,  nave.alt/2); // v0---v1
    glEnd();
glPopMatrix();                  // desempilha e volta para o sistema original

//usado para criar uma animação

