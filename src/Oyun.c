/**
*
* @author Emre Dinçer Öğren
* <p>
*       Oyun structunun işaret ettiği fonksiyonların gövdeleri
* </p>
*/

#include "Oyun.h"


Oyun new_Oyun(){
    Oyun this;
    this=(Oyun)malloc(sizeof(struct OYUN));
    this->round=0;
    this->tableMoney=0;
    this->passRound=&passRound;
    this->updateLuckyNum=&updateLuckyNum;
    this->printScreen=&printScreen;
    this->printEnd=&printEnd;
    this->delete_Oyun=&delete_Oyun;
    return this;
}
int passRound(const Oyun this){
    this->round=this->round+1;
    return this->round;
}
void printScreen(const Oyun this)
{
    printf("#############################################\n");
    printf("##             SANSLI SAYI: %-14d ##\n",this->luckyNum);
    printf("#############################################\n");
    printf("#############################################\n");
    printf("##             TUR: %-23d##\n",this->round);
    printf("##     MASA BAKIYE: %-23.0lf##\n",this->tableMoney);
    printf("##                                         ##\n");
    printf("##-----------------------------------------##\n");
    printf("##           EN ZENGIN KISI                ##\n");
    printf("##           %-30s##\n",this->mostWinner->name);
    printf("##     BAKIYESI:  %-25.0lf##\n",this->mostWinner->money);
    printf("##                                         ##\n");
    printf("#############################################\n");

}

void printEnd(const Oyun this)
{
    printf("#############################################\n");
    printf("##             TUR: %-23d##\n",this->round);
    printf("##     MASA BAKIYE: %-23.0lf##\n",this->tableMoney);
    printf("##                                         ##\n");
    printf("##-----------------------------------------##\n");
    printf("##             OYUN BITTI                  ##\n");
    printf("##                                         ##\n");
    printf("##                                         ##\n");
    printf("#############################################\n");

}
void updateLuckyNum(const Oyun this,int value){
    this->luckyNum=value;
}

void delete_Oyun(const Oyun this){
    if(this==NULL) return;
    free(this);
}