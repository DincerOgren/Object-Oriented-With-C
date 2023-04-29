/**
*
* @author Emre Dinçer Öğren
* <p>
*           Dosyadan okunan kisileri depolayan ve kisilerin parası üzerinde değişiklik yapabilen kişinin bilgilerini tutan
*		fonksyionların imazaları
* </p>
*/

#ifndef KISI_H
#define KISI_H

#include "stdio.h"
#include "stdlib.h"

typedef enum Bool{false, true}boolean;

struct KISI{
	char *name;
	double money;
	double betAmount;
	int betNumber;


	boolean (*isWin)(struct KISI*,int);
	double (*getMoney)(struct KISI*);
	double (*betMoney)(struct KISI*);
	double (*bet)(struct KISI*,double);
	double (*winBet)(struct KISI*,double);

	void (*delete)(struct KISI*);
};
typedef struct KISI* Person;
Person new_Kisi(char*,double,double,int);
boolean isWin(const Person,int);
double getMoney(const Person);
double betMoney(const Person);
double bet(const Person,double);
double winBet(const Person,double);
void delete_Kisi(const Person);



#endif