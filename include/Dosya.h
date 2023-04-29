/**
*
* @author Emre Dinçer Öğren
* <p>
*       Dosya yapısını nesne yönelimli benzetimi sadece satır sayma fonksiyonunun imzasına sahip
* </p>
*/

#ifndef DOSYA_H
#define DOSYA_H
#include "stdio.h"
#include "stdlib.h"
#include <string.h>
#include "Kisi.h"

struct DOSYA
{
    FILE *fp;
    char buffer_in[256];
    int count_lines;
    char chr;

    int (*readLines)(struct DOSYA*,char*);

};
typedef struct DOSYA* Dosya;


Dosya new_Dosya();
int readLines(const Dosya,char*);
#endif