#include "Scene.h"
#include <gtc/matrix_transform.hpp>  
#include <gtc/type_ptr.hpp>

//-------------------------------------------------------------------------

void Scene::init()
{ // OpenGL basic setting
	
  glClearColor(1.0, 1.0, 1.0, 1.0);  // background color (alpha=1 -> opaque)
  glEnable(GL_DEPTH_TEST);  

  
  //camera->setAZ();
    
  // lights
  glClearColor(0.6f, 0.7f, 0.8f, 1.0); // Fondo azul (o el que prefieras)
  glEnable(GL_COLOR_MATERIAL);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0); // Light0
  GLfloat d[] = { 1.0f, 1.0f, 1.0f, 1.0f };
  glLightfv(GL_LIGHT0, GL_DIFFUSE, d);
  GLfloat as[] = { 0.3f, 0.3f, 0.3f, 1.0f };
  glLightfv(GL_LIGHT0, GL_AMBIENT, as);
  GLfloat s[] = { 1.0f, 1.0f, 1.0f, 1.0f };
  glLightfv(GL_LIGHT0, GL_SPECULAR, s);
  GLfloat p[] = { 600.0f, 600.0f, 600.0f, 1.0f };
  glLightfv(GL_LIGHT0, GL_POSITION, p);
  camera->set3D();
  // textures  
  /**
  Necesario para poder usar texturas
  */
  glEnable(GL_TEXTURE_2D);
  // objets
  objetos.push_back(new EjesRGB(200.0));
  //objetos.push_back(new Triangle(100.0));
  //objetos.push_back(new TriangleRGB(100.0));
  //objetos.push_back(new TriPyramid(100.0, 250.0));
  //objetos.push_back(new ContCubo(100.0));
  //objetos.push_back(new Diabolo(100.0, 250.0));
  //objetos.push_back(new Cubo(100.0, 100.0));
  //objetos.push_back(new Dragon(3000));
  //objetos.push_back(new Poliespiral(0.0, 0.0, 0.0, 160.0, 1.0, 1.0, 50));
  //objetos.push_back(new Poliespiral(0.0, 0.0, 0.0, 72.0, 30.0, 0.001, 5));
  //objetos.push_back(new Poliespiral(0.0, 0.0, 0.0, 60.0, 0.5, 0.5, 100));
  //objetos.push_back(new Poliespiral(0.0, 0.0, 0.0, 89.5, 0.5, 0.5, 100));
  //objetos.push_back(new Poliespiral(0.0, 0.0, 0.0, 45.0, 1.0, 1.0, 50));
  //objetos.push_back(new RectanguloTex(100.0, 100.0, 0, 0));
  //objetos.push_back(new CuboTex(50.0, 50.0, 0, 0, 50.0, 50.0, 50.0));
  //objetos.push_back(new DiaboloTex(100.0, 200.0, -200.0, 100.0, -200.0));
  //objetos.push_back(new Suelo(100.0, 100.0, 10, 10));
  //objetos.push_back(new Grass(100.0, 100.0, 0, 0, 200.0, 50.0, -200.0));
  //objetos.push_back(new GlassPot(100.0, 100.0, 0, 0, 200.0, 50.0, -200.0));
  //objetos.push_back(new Poligon(100.0, 6));
  //objetos.push_back(new MPR(50));
  numL = 20;
  numR = 1000;
  a = 7;
  b = 4;
  c = 2;
  Hipotrocoide* hipo = new Hipotrocoide(numL, numR, a, b, c);//x, 300, 70, 40, 20 (para hacerla grande, pon estos y los que hay en los metodos de la hipomesh
  objetos.push_back(hipo);
  mat = hipo->mesh->getMatriz();
  //hipo->modelMat = glm::scale(hipo->modelMat, glm::dvec3(30.0, 30.0, 30.0));

  //BB8
  //Entidad compuesta de BB8
  CompoundEntity* robot = new CompoundEntity();
  //Metemos el robot en los objetos de la escena
  objetos.push_back(robot);
  this->moveBB8();
  //robot->modelMat = glm::translate(robot->modelMat, glm::dvec3(4.8*300.0, -0.13*300.0, 0.97*300.0));
  
  //Cabeza BB8
  RevolutionsShpere* cabeza = new RevolutionsShpere(50);
  //Se le da el color a la pieza
  cabeza->setColor(1.0, 1.0, 1.0);
  //Se coloca
  cabeza->modelMat = glm::translate(cabeza->modelMat, glm::dvec3(0, 85, 0));
  //Se mete dentr0 de los objetos del robot
  robot->entities.push_back(cabeza);
  Sphere* ojo = new Sphere(5.0, 30, 30);
  ojo->modelMat = glm::translate(ojo->modelMat, glm::dvec3(47, 100, 10));
  ojo->setColor(0.0, 0.0, 0.0);
  robot->entities.push_back(ojo);
  Sphere* ojoGrande = new Sphere(15.0, 30, 30);
  ojoGrande->modelMat = glm::translate(ojoGrande->modelMat, glm::dvec3(25, 110, 25));
  ojoGrande->setColor(0.0, 0.0, 0.0);
  robot->entities.push_back(ojoGrande);
  //Cuerpo BB8
  CompoundEntity* cuerpo = new CompoundEntity();
  robot->entities.push_back(cuerpo);
  cuerpo->modelMat = glm::rotate(cuerpo->modelMat, glm::radians(45.0), glm::dvec3(0, 1, 0));
  Sphere* centro = new Sphere(90.0, 30, 30);
  centro->setColor(0.96, 0.96, 0.86);
  cuerpo->entities.push_back(centro);
  //Esfera para ver si rota el cuerpo
  Sphere* rotador = new Sphere(20, 30, 30);
  rotador->setColor(0.0, 0.0, 0.0);
  rotador->modelMat = glm::translate(rotador->modelMat, glm::dvec3(0, 0, 85));
  cuerpo->entities.push_back(rotador);

  /**
  Los objetos opacos van primero, los semitransparentes o transparentes segundos y por ultimo los translucidos
  */

}
//-------------------------------------------------------------------------

Scene::~Scene()
{ // free memory and resources 
  
  for each (Entity* it in objetos)
  {
	  delete it;
  }
}
//-------------------------------------------------------------------------

void Scene::render()
{
	glMatrixMode(GL_MODELVIEW);

	for each (Entity* it in objetos)
	{
		it->render(camera->getViewMat());
	}
	/**
	Permite a�adir varios puntos de vista, en esta ocasion son 4
	*/
	/*Viewport* viewport = camera->getVP();
	viewport->setSize(viewport->getW() / 2, viewport->getH() / 2);
	int i = 0;
	for (Entity* it : objetos)
	{
		switch (i) {
		case 0:
			viewport->setPos(0, 0);
			break;
		case 1:
			viewport->setPos(viewport->getW(), 0);
			break;
		case 2:
			viewport->setPos(0, viewport->getH());
			break;
		case 3:
			viewport->setPos(viewport->getW(), viewport->getH());
			break;
		default:
			break;
		}

		it->render(camera->getViewMat());
		i++;
	}
	viewport->setSize(viewport->getW() * 2, viewport->getH() * 2);
	viewport->setPos(0, 0);*/
}
//-------------------------------------------------------------------------

/**
Metodos para poder obtener los objetos dados, en el main se llama a esta funcion y desde alli se puede llamar a las funciones de los objetos
para despues llamar al
*/
Diabolo* Scene::getDiabolo(){
	return (Diabolo*)objetos.back();
}

DiaboloTex* Scene::getDiaboloTex(){
	return (DiaboloTex*)objetos[2];
}

//Rota el cuerpo del objeto 2 (BB8). El cuerpo es la 3� esfera del robot
void Scene::rotateBody(){
	CompoundEntity* c = (CompoundEntity*)objetos[2];
	CompoundEntity* ce = (CompoundEntity*)c->entities[3];
	ce->modelMat = glm::rotate(ce->modelMat, glm::radians(7.0), glm::dvec3(1, 0, 0));
}

void Scene::moveBB8(){
	if (move == numR){
		move = 0;
	}
	CompoundEntity* bb = (CompoundEntity*)objetos[2];
	glm::dmat4 aux =(mat.at(move));
	//Cambio la ultima fila por la curva (en X 3 en la matriz)
	aux[3][0] = aux[0][3];
	aux[3][1] = aux[1][3];
	aux[3][2] = aux[2][3];

	aux[0][3] = 0.0;
	aux[1][3] = 0.0;
	aux[2][3] = 0.0;

	bb->modelMat = aux;
	bb->modelMat = glm::scale(bb->modelMat, glm::dvec3(1.0, -1.0, 1.0));
	bb->modelMat = glm::scale(bb->modelMat, glm::dvec3(0.003, 0.003, 0.003));
	bb->modelMat = glm::rotate(bb->modelMat, glm::radians(-90.0), glm::dvec3(0, 1, 0));
	move++;
}