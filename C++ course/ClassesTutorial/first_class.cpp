#include <bits/stdc++.h>
#include <math.h>
#include "cylinder.h"

using namespace std;

int main(){

    //Cylinder c1;
    Cylinder c1(2,2);
    Cylinder* c2 = new Cylinder();

    Cylinder* c3 = new Cylinder(4,4);

    //c1.setAltura(1);
    //c1.setRaio(1);

    c2->setAltura(2);
    c2->setRaio(2);

    cout << "v1: " << c1.calculaVolume() << endl;
    cout << "v2: " << c2->calculaVolume() << endl;
    cout << "v3: " << c3->calculaVolume() << endl;

    delete c2;
    delete c3;
}
