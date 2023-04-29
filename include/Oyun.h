/**
*
* @author Emre Dinçer Öğren
* <p>
*           Oyun nesnesi(simülasyon) içinde o an en çok parası olan kişiyi tutan değişken ve çeşitli değişkenlere sahip
*           oyunun ilerlemesini sağlıycak fonksiyon imzalarına sahip
* </p>
*/

#ifndef OYUN_H
#define OYUN_H

#include "stdio.h"
#include "stdlib.h"
#include "Kisi.h"


struct OYUN
{
    Person mostWinner;
    double tableMoney;
    int luckyNum;
    int round;


    int (*passRound)(struct OYUN*);
    void (*delete_Oyun)(struct OYUN*);
    void (*printScreen)(struct OYUN*);

    void (*updateLuckyNum)(struct OYUN*,int);
    void (*printEnd)(struct OYUN*);
    
};
typedef struct OYUN* Oyun;      

Oyun new_Oyun();
int passRound(const Oyun);
void printScreen(const Oyun);
void printEnd(const Oyun);
void updateLuckyNum(const Oyun,int);
void delete_Oyun(const Oyun);


#endif