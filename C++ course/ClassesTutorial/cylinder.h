#ifndef _CYLINDER_H
#define _CYLINDER_H

#include <math.h>

class Cylinder{
    private:
        double raio;
        double altura;

    public:

        Cylinder();
        Cylinder(double raio, double altura);

        void setRaio(double raio);
        double getRaio();

        void setAltura(double altura);
        double getAltura();

        double calculaVolume();
};

#endif