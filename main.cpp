#include <iostream>
#include "Sculptor.h"

using namespace std;

int main()
{

    Sculptor nave(100,100,100); // OK

    // ---- COLOCANDO BLOCOS ----
    // CABINE
    nave.putSphere(50,50,50,15);
    nave.setColor(50,50,50);

    // BRACOS
    nave.putEllipsoid(50,50,50,10,37,10);
    nave.setColor(100,100,100);

    // PLACAS
    nave.putBox(30,70,15,15,30,70);
    nave.setColor(100,100,100);
    nave.putBox(30,70,85,85,30,70);
    nave.setColor(100,100,100);



    // ---- CORTANDO BLOCOS ----

    for(int i = 30; i <= 70; i++){
        int j = i;
        nave.cutVoxel(i,85,j);
        nave.cutVoxel(i,15,j);

        nave.putVoxel(i,85,j);
        nave.setColor(0,0,0);
        nave.putVoxel(i,15,j);
        nave.setColor(0,0,0);
    }

    for(int i = 30; i <= 70; i++){
        int j = 100-i;
        nave.cutVoxel(i,85,j);
        nave.cutVoxel(i,15,j);

        nave.putVoxel(i,85,j);
        nave.setColor(0,0,0);
        nave.putVoxel(i,15,j);
        nave.setColor(0,0,0);
    }

    for(int i = 30; i <= 70; i++){
        nave.cutVoxel(i,85,50);
        nave.cutVoxel(i,15,50);

        nave.putVoxel(i,85,50);
        nave.setColor(0,0,0);
        nave.putVoxel(i,15,50);
        nave.setColor(0,0,0);

    }

    nave.cutEllipsoid(50,50,50,7,35,7);
    nave.cutSphere(50,50,50,12);
    nave.cutBox(60,75,40,60,40,60);

    // CADEIRA
    nave.putBox(45,53,45,55,45,55);
    nave.setColor(0,0,0);
    nave.cutBox(48,53,45,55,50,55);
    nave.cutBox(48,53,47,53,48,55);


    /* ---- TESTANDO OS METODOS ----
    nave.putVoxel(50,50,50); // OK
    nave.cutVoxel(50,50,50); // OK
    nave.putBox(40,60,15,85,45,55); // OK
    nave.cutBox(40,60,15,85,40,50); // OK
    nave.putSphere(50,50,50,15); // OK
    nave.cutSphere(50,50,50,15); // OK
    nave.putEllipsoid(50,50,50,15,35,10); // OK
    nave.cutEllipsoid(50,50,50,15,35,10); // OK
    nave.setColor(0,0,0) // OK
    */

    nave.writeOFF((char*)"nave.off"); // OK

    cout << "Arquivo gravado com sucesso!" << endl;
    return 0;

}
