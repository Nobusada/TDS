/* 
 * File:   Ataque.cpp
 * Author: danielnobusada
 *
 * Created on November 5, 2012, 8:05 PM
 */


#include "Ataque.h"
#include <iostream>

using namespace std;

Ataque::Ataque(int a, int d, int aMin, int aMax, char* n, bool f)
{
    this->ataque = a;
    this->dano = d;
    this->alcanceMin = aMin;
    this->alcanceMax = aMax;
    this->nome = n;
    this->fisico = f;
}

Ataque::Ataque(Ataque& at)
{
    this->ataque = at.getAtaque();
    this->dano = at.getDano();
    this->alcanceMin = at.getAlcanceMin();
    this->alcanceMax = at.getAlcanceMax();
    this->nome = at.getNome();
    this->fisico = at.getFisico();    
}

void Ataque::setAlcanceMax(int aMax){this->alcanceMax = aMax;}
void Ataque::setAlcanceMin(int aMin){this->alcanceMin = aMin;}
void Ataque::setAtaque(int a){this->ataque = a;}
void Ataque::setDano(int d){this->dano = d;}
void Ataque::setNome(char* n){this->nome = n;}
void Ataque::setFisico(bool f){this->fisico = f;}

int Ataque::getAlcanceMax(){return this->alcanceMax;}
int Ataque::getAlcanceMin(){return this->alcanceMin;}
int Ataque::getAtaque(){return this->ataque;}
int Ataque::getDano(){return this->dano;}
bool Ataque::getFisico(){return this->fisico;}
char* Ataque::getNome(){return this->nome;}

void Ataque::printTudo()
{
    cout<<"Nome: "<<this->getNome()<<endl;
    cout<<"Ataque: "<<this->getAtaque()<<endl;
    cout<<"Dano: "<<this->getDano()<<endl;
    cout<<"Alcances: ("<<this->getAlcanceMin()<<","<<this->getAlcanceMax()<<")"<<endl;
}