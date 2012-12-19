#include "Hexagono.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

Hexagono::Hexagono(int posX, int posY)
{
    pontos.posX = posX;
    pontos.posY = posY;
}

Hexagono::Hexagono()
{
    pontos.posX = 0;
    pontos.posY = 0;
}

/*Hexagono::~Hexagono()
{
    delete p;
}*/

//gets e sets
Pontos Hexagono::getPontos(){return this->pontos;}
//Peca* Hexagono::getPeca(){return this->p;}
void Hexagono::setPontos(int posX, int posY){pontos.posX = posX; pontos.posY = posY;}
//void Hexagono::setPeca(Peca* p){this->p;}

void Hexagono::printaPontos()
{
    cout <<"X: "<< this->getPontos().posX<<", Y:"<<this->getPontos().posY<<endl;
    
    cout<<"Lado30------ X:"<< this->getLado30().posX <<","<< this->getLado30().posY<<endl;
    cout<<"Lado90------ X:"<< this->getLado90().posX <<","<<  this->getLado90().posY<<endl;
    cout<<"Lado150------ X:"<< this->getLado150().posX <<","<<  this->getLado150().posY<<endl;
    cout<<"Lado210------ X:"<< this->getLado210().posX <<","<<  this->getLado210().posY<<endl;
    cout<<"Lado270------ X:"<< this->getLado270().posX <<","<<  this->getLado270().posY<<endl;
    cout<<"Lado330------ X:"<< this->getLado330().posX << ","<< this->getLado330().posY<<endl;
}

//funcoes de retornas lados
Pontos Hexagono::getLado30()
{
    Pontos p;
    int i = this->pontos.posX;
    int j = this->pontos.posY;
    
    if(j != 15 && i != 1)
    {
        if (j%2 == 1)
        {
            p.posX = i-1;
            p.posY = j+1;
        }
        else 
        {
            p.posX = i;
            p.posY = j+1;
        }
    }
    else
    {
        p.posX = -1;
        p.posY = -1;
    }
    return p;
}

Pontos Hexagono::getLado90()
{
    Pontos p;
    int i = this->pontos.posX;
    int j = this->pontos.posY;
    
    if(i != 0)
    {
        p.posX = i-1;
        p.posY = j;
    }
    else
    {
        p.posX = -1;
        p.posY = -1;
    }
    return p;
}

Pontos Hexagono::getLado150()
{
    Pontos p;
    int i = this->pontos.posX;
    int j = this->pontos.posY;
    
    if(j != 1 && i != 1)
    {
        if (j%2 == 1)
        {
            p.posX = i-1;
            p.posY = j-1;
        }
        else 
        {
            p.posX = i;
            p.posY = j-1;
        }
    }
    else
    {
        p.posX = -1;
        p.posY = -1;
    }
    return p;
}

Pontos Hexagono::getLado210()
{
    Pontos p;
    int i = this->pontos.posX;
    int j = this->pontos.posY;
    
    if(j != 1 && i != 15)
    {
        if (j%2 == 1)
        {
            p.posX = i;
            p.posY = j-1;
        }
        else 
        {
            p.posX = i;
            p.posY = j-1;
        }
    }
    else
    {
        p.posX = -1;
        p.posY = -1;
    }
    return p;
}

Pontos Hexagono::getLado270()
{
    Pontos p;
    int i = this->pontos.posX;
    int j = this->pontos.posY;
    
    if(i != 15)
    {
        p.posX = i+1;
        p.posY = j;
    }
    else
    {
        p.posX = -1;
        p.posY = -1;
    }
    return p;
}

Pontos Hexagono::getLado330()
{
    Pontos p;
    int i = this->pontos.posX;
    int j = this->pontos.posY;
    
    if(j != 25 && i != 15)
    {
        if (j%2 == 1)
        {
            p.posX = i;
            p.posY = j+1;
        }
        else 
        {
            p.posX = i+1;
            p.posY = j+1;
        }
    }
    else
    {
        p.posX = -1;
        p.posY = -1;
    }
    return p;
}