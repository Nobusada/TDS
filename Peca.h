/* 
 * File:   Peca.h
 * Author: danielnobusada
 *
 * Created on November 5, 2012, 8:10 PM
 */

#ifndef PECA_H
#define	PECA_H

#include <string>
#include "Ataque.h"
#include "Defesa.h"
#include <vector>
#include <list>

using namespace std; 

class Peca
{
private:
    vector<Ataque*>* vetorAtaques;
    list<Ataque*> listAtaques;
    Defesa *defesa;
    int movimentacao, quantidadeVida;
    char* nome;
public:
    Peca();
    Peca(int, int, char*);
    Peca(Peca &copia);
    ~Peca();
    
    void setMovimentacao(int);
    void setQuantidadeVida(int);
    void setNome(char*);
    void setDefesa(Defesa*);
    
    int getMovimentacao();
    int getQuantidadeVida();
    Defesa* getDefesa();
    vector<Ataque*>* getVectorAtaque();
    char* getNome();
    
    void inserirAtaque(Ataque*);
    void removerTodosAtaques();
    void removerAtaque(char*);
    void exibeAtaque();
    
    void inserirDefesa(Defesa*);
    void deletarDefesa();
    void exibeDefesa();
    
    void ataca(Peca*, Ataque*, bool, bool);
    void exibeTudo();
};

#endif	/* PECA_H */

