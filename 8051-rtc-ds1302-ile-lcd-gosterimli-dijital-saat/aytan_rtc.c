#include <89c51rd2.H>

#include <stdio.h>
#include "T_LCD.h"
#include "rtc.h"
#define program P3_5
#define azalt   P3_6
#define arttir  P3_7

code char  sayi[10]={'0','1','2','3','4','5','6','7','8','9'};
//code char gunler[7][3]={"CTS","PZR","PZT","SAL","CAR","PER","CUM"};
code unsigned char reklam[16]={"  AYTEN  ASLAN  "};
int gun,ay,yil,dow;
int saat,dakika,saniye;
int a1=0,a2=0;g1=0,g2=0,y1=0,y2=0,hg1=0,hg2=0;
int sa1=0,sa2=0,dkk1=0,dkk2=0,sn1=0,sn2=0;

int i;
int  s=0;

void main(void)
{
	LcdAc();
	rtc_init();
	Komut(Sil);
	while(1)
	{
		Komut(BirinciSatir);
		
rtc_get_time(&saat,&dakika,&saniye);



		if((saniye%10)!=0)
		{
		Veri('-',0);Veri('-',0);Veri('-',0);Veri('-',0);
		
			sa1=saat/10;		
			Veri(sayi[sa1],0);
			sa2=saat%10;	
			Veri(sayi[sa2],0);

			Veri(':',0);

			dkk1=dakika/10;	
			Veri(sayi[dkk1],0);
			dkk2=dakika%10;	
			Veri(sayi[dkk2],0);	

			Veri(':',0);

			sn1=saniye/10;	
			Veri(sayi[sn1],0);
			sn2=saniye%10;	
			Veri(sayi[sn2],0);

		Veri('-',0);Veri('-',0);Veri('-',0);Veri('-',0);
		}
else
			for(i=0;i<16;i++)
				Veri(reklam[i],0);
		
	Komut(IkinciSatir);

	rtc_get_date(&gun,&ay,&yil,&dow);
		Veri('-',0);Veri('-',0);Veri('-',0);Veri('-',0);
		g1=gun/10;		Veri(sayi[g1],0);
		g2=gun%10;		Veri(sayi[g2],0);
		Veri('/',0);
		a1=ay/10;		Veri(sayi[a1],0);
		a2=ay%10;		Veri(sayi[a2],0);
		Veri('/',0);
		y1=yil/10;		Veri(sayi[y1],0);
		y2=yil%10;		Veri(sayi[y2],0);
		//Veri('/',0);
/*	for(i=0;i<3;i++)
	Veri(gunler[dow][i],0);*/
	Veri('-',0);Veri('-',0);Veri('-',0);Veri('-',0);
	
		
	
if(!(program))
    s++;


  if(s==1)
   
 if(!(arttir))
      {
         saat=read_ds1302(0x85);
		 saat++;
        if((saat&(0x0F)==0x0A)) saat+=6; 
         
         if((saat>=0x24)) saat=0x00;
         write_ds1302(0x84,saat);
         }
   else if(!(azalt))

      {saat= read_ds1302(0x85);
        saat--;
         if((saat&(0x0F))==0x0F) saat-=6; 
         if(saat<=0x00) saat=0x24;

         write_ds1302(0x84,saat);
   }
      if (s==2)

    if(!(arttir))

        { dakika = read_ds1302(0x83);
         dakika++;
        if((dakika&0x0F)==0x0A) dakika+=6;
         if(dakika>=0x60) dakika=0x00;
         write_ds1302(0x82,dakika);
         }
       else if(!(azalt))
        {
         dakika=read_ds1302(0x83);
         dakika--;
         if((dakika&0x0F)==0x0F) dakika-=6;
         if(dakika<=0x00) dakika=0x60;
         write_ds1302(0x82,dakika);

         }
		  if(s==3)

 if(!(arttir))
      {
         gun=read_ds1302(0x87);
         gun++;
         if((gun&(0x0F)==0x0A)) gun+=6;
         if((gun>=0x31)) gun=0x01;
         write_ds1302(0x86,gun);
         }
   else if(!(azalt))

      {gun=read_ds1302(0x87);
         gun--;
         if((gun&(0x0F))==0x0F) gun-=6;
         if(gun<=0x01) gun=0x31;

         write_ds1302(0x86,gun);
   }
   if(s==4)

 if(!(arttir))
      {
         ay=read_ds1302(0x89);
         ay++;
         if((ay&(0x0F)==0x0A)) ay+=6;
         if((ay>=0x12)) ay=0x01;
         write_ds1302(0x88,ay);
         }
   else if(!(azalt))

      {ay=read_ds1302(0x89);
         ay--;
         if((ay&(0x0F))==0x0F) ay-=6;
         if(ay<=0x01) ay=0x12;

         write_ds1302(0x88,ay);
   }
   if(s==5)

 if(!(arttir))
      {
         yil=read_ds1302(0x8D);
         yil++;
         if((yil&(0x0F)==0x0A)) yil+=6;
         //if((gun>=0x31)) gun=0x00;
         write_ds1302(0x8C,yil);
         }
   else if(!(azalt))

      {yil=read_ds1302(0x8D);
         yil--;
         if((yil&(0x0F))==0x0F) yil-=6;
         //if(gun<=00) gun=0x31;

         write_ds1302(0x8C,yil);
   }
         if(s==6)
         {
         s=0;
	}
     }
}
