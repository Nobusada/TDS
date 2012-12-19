/* 
 * File:   Hexagono.h
 * Author: danielnobusada
 *
 * Created on December 17, 2012, 7:35 PM
 */

#ifndef HEXAGONO_H
#define	HEXAGONO_H

#include "Peca.h"

struct Pontos {
    int posX, posY;
};

class Hexagono
{
private:
    Pontos pontos;
    //Peca* p;
public:
    Hexagono();
    Hexagono(int, int);
    ~Hexagono(){};
    
    void setPontos(int, int);
    //void setPeca(Peca*);
    Pontos getPontos();
    //Peca* getPeca();
    Hexagono getHex();
    Pontos getLado30();
    Pontos getLado90();
    Pontos getLado150();
    Pontos getLado210();
    Pontos getLado270();
    Pontos getLado330();
    void printaPontos();
};

#endif	/* HEXAGONO_H */

