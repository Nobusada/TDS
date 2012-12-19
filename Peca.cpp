/* 
 * File:   Peca.cpp
 * Author: danielnobusada
 * 
 * Created on November 5, 2012, 8:10 PM
 */

#include "Peca.h"
#include <string>
#include <string.h>
#include <iostream>

using namespace std;

Peca::Peca(int m, int qV, char* n)
{
    vetorAtaques = new vector<Ataque*>();
    this->movimentacao = m;
    this->quantidadeVida = qV;
    this->nome = n;
}

//nao sei se isso funciona!!
Peca::Peca(Peca& copia)
{
    this->defesa = copia.defesa;
    this->nome = copia.nome;
    this->quantidadeVida = copia.quantidadeVida;
    this->listAtaques = copia.listAtaques;
    this->vetorAtaques = copia.vetorAtaques;
}

Peca::~Peca()
{
    int i;
    this->deletarDefesa();
    this->removerTodosAtaques();
    this->vetorAtaques->clear();
    delete vetorAtaques;
}

//gets and setters
void Peca::setMovimentacao(int m){this->movimentacao = m;}
void Peca::setNome(char* n){this->nome = n;}
void Peca::setQuantidadeVida(int qV){this->quantidadeVida = qV;}
void Peca::setDefesa(Defesa *defesa){this->defesa = defesa;}

int Peca::getMovimentacao(){return this->movimentacao;}
int Peca::getQuantidadeVida(){return this->quantidadeVida;}
Defesa* Peca::getDefesa(){return this->defesa;}
vector<Ataque*>* Peca::getVectorAtaque(){return this->vetorAtaques;}
char* Peca::getNome(){return this->nome;}

void Peca::inserirAtaque(Ataque *at)
{
    Ataque *ataque = new Ataque(*at);
    cout<<ataque->getNome()<<endl;
    this->getVectorAtaque()->push_back(ataque);
    //cout<< "tamanho: " << this->getVectorAtaque()->size()<<endl;
}

void Peca::inserirDefesa(Defesa *de)
{
    Defesa *defesa = new Defesa(*de);
    this->setDefesa(defesa);
}

void Peca::deletarDefesa(){delete this->getDefesa();}

/*
 Esta funcao dá delete em todos os elementos do vector vetorAtaques.
 */
void Peca::removerTodosAtaques()
{
    int i;
    for (i=0; i< (this->getVectorAtaque()->size()); i++)
        delete this->getVectorAtaque()->at(i);
}


/*
 Esta funcao da delete no elemento cujo nome é passado por parâmetro, se este existir.
 */
void Peca::removerAtaque(char* nome)
{
    int i;
    if (!this->getVectorAtaque()->empty())
    {   
        for(i=0; i<(this->getVectorAtaque()->size()); i++)
        {
            if(strcmp( this->getVectorAtaque()->at(i)->getNome() , nome ) == 0)
                delete this->getVectorAtaque()->at(i);
            else
                cout<<"Ataque -"<<nome<<"- nao consta no vetor de ataques"<<endl;
        }
    }
    else
        cout<<"Ataque -"<<nome<<"- nao consta no vetor de ataques"<<endl;
}

void Peca::exibeTudo()
{
    int i;
    
    cout << "Nome: " << this->getNome() << endl;
    cout << "Defesa: "<< this->getDefesa()->getNormal() << "(" << this->getDefesa()->getDesarmada() << ")" << endl;
    for (i=0;i<this->getVectorAtaque()->size()-1; i++)
    {
        cout << i <<endl;
        cout << this->getVectorAtaque()->size()<<endl;
        cout << "Nome: " << this->getVectorAtaque()->at(i)->getNome() << ", com " << this->getVectorAtaque()->at(i)->getAtaque() << " de Ataque" << endl;
        cout << "Dano: " << this->getVectorAtaque()->at(i)->getDano() << ", Alcance: ("<< this->getVectorAtaque()->at(i)->getAlcanceMin() << ","<< this->getVectorAtaque()->at(i)->getAlcanceMax() << ")"<<endl;
        if(this->getVectorAtaque()->at(i)->getFisico())
            cout<< "O ataque eh corpo-a-corpo!"<<endl;
        else
            cout<< "O ataque eh a distancia!"<<endl;
        
    }
}

//Eh necessario documentar esse metodo
void Peca::ataca(Peca *p, Ataque *a, bool desarmado, bool verbose)
{
    if (!verbose)
    {
        if(!desarmado)
        {
            if (p->getDefesa()->verificaAtaqueXNormal(a->getAtaque()))
                p->setQuantidadeVida(p->getQuantidadeVida() - a->getDano());
            else
                cout << "Ataque Falhou!" << endl;
        }
        else
        {
            if(p->getDefesa()->verificaAtaqueXDesarmada(a->getAtaque()))
                p->setQuantidadeVida(p->getQuantidadeVida() - a->getDano());
            else
                cout << "Ataque Falhou!" << endl;
        }
    }
    else
    {
        if(!desarmado)
        {
            cout << "ATAQUE NORMAL!!"<<endl;
            cout << this->getNome() << ": Ataque = " << a->getAtaque() << ", Dano = " << a->getDano() << endl << endl;
            cout << p->getNome() << ": Vida = " << p->getQuantidadeVida() << ", Defesa desarmada: " << p->defesa->getDesarmada() << endl << endl;
            
            if (p->defesa->verificaAtaqueXNormal(a->getAtaque()))
            {
                p->setQuantidadeVida(p->getQuantidadeVida() - a->getDano());
                cout << this->getNome() << " causou " << a->getDano() << " de dano em " << p->getNome() << " que tem agora " << p->getQuantidadeVida() << " pontos de vida! "<<endl<<endl;
            }
            else
                cout << "Ataque Falhou!" << endl;
        }
        else
        {
            cout<< "ATAQUE DESARMADO!!"<<endl;
            cout << this->getNome() << ": Ataque = " << a->getAtaque() << ", Dano = " << a->getDano() << endl << endl;
            cout << p->getNome() << ": Vida = " << p->getQuantidadeVida() << ", Defesa desarmada: " << p->defesa->getDesarmada() << endl << endl;
            
            if(p->defesa->verificaAtaqueXDesarmada(a->getAtaque()))
            {
                p->setQuantidadeVida(p->getQuantidadeVida() - a->getDano());
                cout << this->getNome() << " causou " << a->getDano() << " de dano em " << p->getNome() << " que tem agora " << p->getQuantidadeVida() << " pontos de vida! "<<endl<<endl;
            }
            else
                cout << "Ataque Falhou!" << endl;
        }
    }
}


