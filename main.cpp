#include <iostream>

#include "Defesa.h"
#include "Ataque.h"
#include "Peca.h"
#include "Hexagono.h"

#define tammax 5

using namespace std;

int main()
{
    /*Defesa *d1, *d2;
    Ataque *a1, *a2, *a3;
    Peca *p1,*p2;
    
    d1 = new Defesa(5,5);
    d2 = new Defesa(5,2);
    a1 = new Ataque(3,5,0,1,"Bolacha",true);
    a2 = new Ataque(2,6,0,2,"Tabefe",true);
    a3 = new Ataque(6,6,0,10,"Chinelada",false);
    
    p1 = new Peca(5,10,"Ettore");
    p2 = new Peca(3,25,"Asia");
    
    p1->inserirDefesa(d1);
    p2->inserirDefesa(d2);
    p1->inserirAtaque(a1);
    p1->inserirAtaque(a2);
    p2->inserirAtaque(a3);
    cout << p1->getVectorAtaque()->size()<<endl;
    //O inserir ataque nao esta funfando direito!
    //p1->getDefesa()->printTudo(); Defesa esta OK
    delete d1; delete d2;delete a1; delete a2; delete a3;
    
    cout << p1->getVectorAtaque()->size();
    //p1->exibeTudo();
    //p2->exibeTudo();
    
    p1->ataca(p2,p1->getVectorAtaque()->at(0),true,true);
    p2->ataca(p1,p2->getVectorAtaque()->at(0),false,true);
    
    p1->exibeTudo();
    p2->exibeTudo();*/
    
    Hexagono grid[tammax][3];
    int i, j;
    for(i=0; i<tammax;i++)
        for(j=0; j<3; j++)
            grid[i][j].setPontos(i,j);
    
    for(i=0; i<tammax; i++)
        for(j=0; j<3; j++)
            grid[i][j].printaPontos();
    
    return 0;
}
