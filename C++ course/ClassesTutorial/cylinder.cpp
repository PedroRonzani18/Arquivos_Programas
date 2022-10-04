#include "cylinder.h"

Cylinder::Cylinder() = default;
Cylinder::Cylinder(double raio, double altura) {
    this->raio = raio;
    this->altura = altura;
}

double Cylinder::calculaVolume() {return raio * altura;}

void Cylinder::setRaio(double raio){this->raio = raio;}
double Cylinder::getRaio(){return this->raio;}

void Cylinder::setAltura(double altura){this->altura = altura;}
double Cylinder::getAltura(){return this->altura;}
