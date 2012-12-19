/* 
 * File:   Defesa.h
 * Author: danielnobusada
 *
 * Created on November 5, 2012, 7:56 PM
 */
#ifndef DEFESA_H
#define	DEFESA_H

using namespace std;

class Defesa
{
private:
    int normal, desarmada;
public:
    Defesa();
    Defesa(int, int);
    Defesa(Defesa&);
    ~Defesa(){};
    
    void setNormal(int);
    void setDesarmada(int);
    int getNormal();
    int getDesarmada();
    
    bool verificaAtaqueXNormal(int);
    bool verificaAtaqueXDesarmada(int);
    void printTudo();
};

#endif	/* DEFESA_H */
