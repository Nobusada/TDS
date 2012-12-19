/* 
 * File:   Defesa.cpp
 * Author: danielnobusada
 * 
 * Created on November 5, 2012, 7:56 PM
 */

#include "Defesa.h"
#include <iostream>

using namespace std;

Defesa::Defesa(int n, int d)
{
    this->normal = n;
    this->desarmada = d;
}

Defesa::Defesa(Defesa& de)
{
    this->normal = de.getNormal();
    this->desarmada = de.getDesarmada();
}

void Defesa::setDesarmada(int d)
{
    this->desarmada = d;
}

void Defesa::setNormal(int n)
{
    this->normal = n;
}

int Defesa::getDesarmada(){return this->desarmada;}
int Defesa::getNormal(){return this->normal;}

bool Defesa::verificaAtaqueXNormal(int ataque)
{
    if(ataque >= this->getNormal())
        return true;
    else
        return false;
}

bool Defesa::verificaAtaqueXDesarmada(int ataque)
{
    if(ataque >= this->getDesarmada())
        return true;
    else
        return false;
}

void Defesa::printTudo()
{
    cout<<"Normal: " << this->getNormal()<<endl;
    cout<<"Desarmada: " << this->getDesarmada()<<endl;
}