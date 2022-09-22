#include <GL/freeglut.h>      //adiciona bibliotecas padrão glut


void desenhaMinhaCena(){					//função de renderização de tela

	glClearColor(1.0, 1.0, 1.0, 1.0);       /*cadastra qual é a cor de preencimento da 
	 						     			 limpeza (nesse caso preenche com branco)*/
	 						     
	glClear(GL_COLOR_BUFFER_BIT);           //limpa o buffer de cores
							    			//pode limpar buffer de profundidade
							    
	glColor3f(0.0, 1.0, 0.0);		    //Seleciona qual cor será usada no desenho
							    		//3  =3 informações
							    		//f = float

	glBegin(GL_TRIANGLE_FAN);
		glVertex3f(-0.5, -0.5, 0.0);
		glVertex3f(0.5, -0.5, 0.0);
		glVertex3f(-0.5, -0.5, 0.0);
		glVertex3f(-0.5, -0.5, 0.0);

	glEnd();                         //fecha o polígono
									 //para adicionar outro poligono tem que dar end

	glFlush();						//pega informação do frame buffer e gera a cena
}	

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitContextVersion(1, 1);
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);   //inicializa o perfil d eocntexo
														  //quer que a glut seja carregada com um perfil de ocmpatibilidade maxima que o pc tem

	glutInitDisplayMode(GLUT_SINGLE);//numero de buffers (single = 2D / duplo = 3D)

	glutInitWindowSize(500,500);//detterina tamanho da janela
}
