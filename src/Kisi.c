/**
*
* @author Emre Dinçer Öğren
* <p>
*       Kisi header dosyasında tutulan fonksiyonların gövdeleri
* </p>
*/#include "Kisi.h"

Person new_Kisi(char* name,double money,double betAmount, int betNumber)
{
    Person this;
    this = (Person)malloc(sizeof(struct KISI));
    //name=malloc(sizeof(char)*64);
    this->name=strdup(name);
    this->money = money;
    this->betAmount = betAmount;
    this-> betNumber = betNumber;


    this->delete = &delete_Kisi;
    this->isWin = &isWin;
    this->getMoney=&getMoney;
    this->betMoney=&betMoney;
    this->winBet=&winBet;
    this->bet=&bet;


    return this;
}

boolean isWin(const Person this,int num){
    if (num==this->betNumber)
    {
        return true;
    }
    else
        return false;
}

double getMoney(const Person this){
    return this->money;
}

double betMoney(const Person this){
    
    return  (this->money) * (this->betAmount);
}

double bet(const Person this,double beta){
    this->money=this->money - beta;
    return this->money;
}
double winBet(const Person this,double beti){
    this->money=this->money+(beti*10);
    return this->money;
}

void delete_Kisi(const Person this){
    if(this==NULL) return;
    free(this);
}
