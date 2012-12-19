/* 
 * File:   Ataque.h
 * Author: danielnobusada
 *
 * Created on November 5, 2012, 8:05 PM
 */

#ifndef ATAQUE_H
#define	ATAQUE_H

using namespace std;

class Ataque
{
private:
    bool fisico;
    int ataque, dano, alcanceMin, alcanceMax;
    char* nome;
public:
    Ataque();
    Ataque(int, int, int, int, char*, bool);
    Ataque(Ataque&);
    ~Ataque(){};
    
    void setFisico(bool);
    void setAtaque(int);
    void setDano(int);
    void setAlcanceMin(int);
    void setAlcanceMax(int);
    void setNome(char*);
    
    bool getFisico();
    int getAtaque();
    int getDano();
    int getAlcanceMin();
    int getAlcanceMax();
    char* getNome();
    
    void printTudo();
};

#endif	/* ATAQUE_H */

