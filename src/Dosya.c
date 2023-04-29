/**
*
* @author Emre Dinçer Öğren
* <p>
*       Dosya yapısını kurucu işaretci fonkisyonu ve  satır sayma işaretci fonksiyonunun gövdelerine sahip
* </p>
*/

#include "Dosya.h"

Dosya new_Dosya()
{
    Dosya this=(Dosya)malloc(sizeof(struct DOSYA));
    
    this->readLines=&readLines;
    return this;
}
int readLines(Dosya this,char* fileName){
    
    this->fp=fopen(fileName,"r");
    if (this->fp==NULL)
    {
        return 1;
    }
    
    this->count_lines = 0;
    this->chr;
    
    this->chr = getc(this->fp);
    while (this->chr != EOF)
    {
        //Count whenever new line is encountered
        if (this->chr == '\n')
        {
            this->count_lines = this->count_lines + 1;
        }
        //take next character from file.
        this->chr = getc(this->fp);
    }

    rewind(this->fp);
    
    return this->count_lines;
}