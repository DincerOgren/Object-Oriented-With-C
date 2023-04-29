#include "stdio.h"
#include "Kisi.h"
#include "stdlib.h"
#include <string.h>
#include "Oyun.h"
#include "Dosya.h"
int main()
{



    Dosya reader=new_Dosya();
    int count_lines = reader->readLines(reader,"Kisiler.txt");//Satır sayısı saydıran fonksiyon
    
    int personNum=0;
    Person persons[count_lines];
    
        char buffer_in[256];
        char *namePerson;
        char temp[64]={0};
        double money;
        double betAmount;
        int betNumber;

    FILE* fp;
    fp=fopen("Kisiler.txt","r");
    while (!feof(fp))//dosya içindeki kişi bilgilierini kaydeden döngü
    {
        fgets(buffer_in, 256 , fp);
        sscanf(buffer_in, "%[a-zA-Z ]#%lf#%lf#%d",temp,&money,&betAmount,&betNumber);
        namePerson=&temp[0];
        persons[personNum]=new_Kisi(namePerson,money,betAmount,betNumber);
        personNum++;
    }
    
    fclose(fp);
   


//----------------------------------OYUN SECTİON----------------------------

    Oyun game =new_Oyun();
    int gameline = reader->readLines(reader,"Sayilar.txt");
    FILE* file=fopen("Sayilar.txt","r");
    
    int winnerNumber[gameline];
    int counter=0;
    int numbers;
    while(!feof(file))
    {
        fscanf(file, "%d",&numbers);
        winnerNumber[counter]=numbers;
        counter++;
    }
    fclose(file);
    
    double bettedMoney;
    int breakPoint=0;
    int ctr=counter;
    int n=personNum;
    double bigger;
    for (int i = 0; i < ctr; i++)//OYUN DONGÜSÜ tüm oyuncuları kontrol edip bir sonraki raunda geçiyor
    {
        game->passRound(game);
        game->updateLuckyNum(game,winnerNumber[i]);
        bigger=0;
        for (int j = 0; j < n; j++)//oyuncu kontrol dongüsü
        {
            
            if (persons[j]->money<=1000.0)//parası 1000 den düşük olan siliniyor
            {
                persons[j]->delete(persons[j]);
                for(int i=j; i<n-1; i++)
                {
                    persons[i] = persons[i + 1];
                }
                
                n--;
                if (n<=0)
                {
                    printf("<<<<<<<<<<<<<<<<<<<YOUN BITTI>>>>>>>>>>>>>>>>>>>>\n");
                    breakPoint=1;
                    break;
                } 
                j--;
                continue;
            }
            


            bettedMoney = persons[j]->betMoney(persons[j]);//  oyuncu iddiasını koyuyor
            persons[j]->money=persons[j]->bet(persons[j],bettedMoney);// oyuncu parası güncellendi
            
            
            if (persons[j]->betNumber==game->luckyNum)
            {
                game->tableMoney=game->tableMoney - (9*bettedMoney);
                
                persons[j]->money=persons[j]->winBet(persons[j],bettedMoney);//oyuncu kazanırsa parası güncelleniyor

            }
            else{
                
                game->tableMoney=game->tableMoney + bettedMoney;// oyuncu kaybederse idda koyduğu paranın hepsi masa parasına ekleniyor

            }
            

            
            
        
            if (bigger<=persons[j]->money)// en fazla paraya sahip oyuncu bulunuyor
            {
                bigger=persons[j]->money;
                game->mostWinner=persons[j];
            }
            
            
            

        }

        if (breakPoint==1)// nested loop tan çıkış için tanımladıgım bir koşul
        {
            printf("\n\n");
            break;
        }
    
        printf("\n\n");
        game->printScreen(game);
        system("cls");
    }
    

    
    game->printEnd(game);
    game->delete_Oyun(game);
    return 0;
}