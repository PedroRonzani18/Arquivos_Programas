#ifndef _WAVE_H
#define _WAVE_H

#include <vector>
#include "../../BaseClasses/Header/Enemy.h"
#include "globalParameters.h"

/*
    metodos que settam
        1. tipos de inimigos que serão chamados na wave
        2. posição inicial
        3. quantidade de inimigos

    chamado em uma timer auxiliar
    para serem jogados na tela, tem que ser adicionados no vetor de inimigos do level
*/

    std::vector<Enemy> waveCaller(int waveType);

    std::vector<Enemy> waveBasicShipParabolaBaixa1();
    std::vector<Enemy> waveBasicShipParabolaBaixaReversa2();
    std::vector<Enemy> waveBasicShipZigZag3();
    std::vector<Enemy> waveBasicShip3Parabola4();
    std::vector<Enemy> waveBasicShipParabolaAlta5();
    std::vector<Enemy> waveBasicShipParabolaAltaReversa6();
    std::vector<Enemy> waveBasicShipEspiral7();
    std::vector<Enemy> waveBasicShipTerceiroGrauComTankEliptico8();

    std::vector<Enemy> waveSegueParabolaBaixa9();
    std::vector<Enemy> waveSegueParabolaBaixaReversa10();
    std::vector<Enemy> waveSegueZigZag11();
    std::vector<Enemy> waveSegue3Parabola12();
    std::vector<Enemy> waveSegueParabolaAlta13();
    std::vector<Enemy> waveSegueParabolaAltaReversa14();
    std::vector<Enemy> waveSegueTerceiroGrauComTankEliptico15();

    std::vector<Enemy> waveTankBateVolta16();
    std::vector<Enemy> wave2TanksElipses17();
    std::vector<Enemy> waveKamikaseAcelerado18();
    std::vector<Enemy> waveKamikaseSegue19();
    std::vector<Enemy> waveSniperSolo20();
    std::vector<Enemy> waveSniperSoloComTank21();
    std::vector<Enemy> waveTorretaReta22();
    std::vector<Enemy> waveTorretaEliptica23();
    std::vector<Enemy> waveTorretaParadaComEnimigos24();
    std::vector<Enemy> waveLevel1();
    std::vector<Enemy> waveLevel2();
    std::vector<Enemy> waveMissaoConcluida();
    std::vector<Enemy> waveGameOver();
    std::vector<Enemy> waveChad();
    std::vector<Enemy> waveBoss();
    std::vector<Enemy> waveBossEntrada();

#endif