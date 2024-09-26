/****************************************************************/
/* 				     T_LCD.H	 	 		     */
/****************************************************************/

/* LCD'de kullan�lan komutlar�n tan�mlanmas� */
#define Sil 		 1	// Ekran� temizler
#define BasaDon 	 2	// �mleci sol �st k��eye getirir
#define SolaYaz 	 4  // �mlecin belirtti�i adres azalarak gider
#define SagaYaz 	 6   // �mlecin belirtti�i adres artarak gider
#define ImlecGizle	 12	// G�stergeyi a�, kurs�r g�r�nmesin
#define ImlecYanSon	 15	// Yan�p s�nen blok kurs�r
#define ImlecGeri	 16	// Kurs�r� bir karakter geri kayd�r
#define KaydirSaga	 24	// G�stergeyi bir karakter sa�a kayd�r                   
#define KaydirSola   28	// G�stergeyi bir karakter sola kayd�r   
#define EkraniKapat	 8	// G�stergeyi kapat (veriler silinmez)
#define BirinciSatir 128	// LCD'nin ilk satir ba�lang�� adresi       
                          // (DDRAM adres)
#define IkinciSatir  192	// �kinci sat�r�n ba�lang�� adresi
#define KarakUretAdres 64	// Karakter �reteci adresini belirle  
                          // (CGRAM adres)

/* LCD'de Kullan�lan Fonksiyon Se�imi */
#define CiftSatir8Bit  56	 // 8 bit ara birim, 2 sat�r, 5*7 piksel
#define CiftSatir4Bit  48	 // 8 bit ara birim, 1 sat�r, 5*7 piksel
#define TekSatir8Bit   40	 // 4 bit ara birim, 2 sat�r, 5*7 piksel
#define TekSatir4Bit   32	 // 4 bit ara birim, 1 sat�r, 5*7 piksel

/* LCD Giri�lerinin Tan�mlanmas� */
#define Data  P1	  // LCD Data giri�leri i�in port ata
#define RS	P2_0 // Saklay�c� se�me giri�i RS=0 komut, RS=1 veri
#define RW	P2_1  // Oku/Yaz giri�i RW=0 yaz, RW=1 oku
#define EN	P2_2   // Yetki giri�i 

/* LCD Gecikme Fonksiyonu */
void Gecikme (long int sure)
{
  long int i;
  for (i=1;i<=sure;i++)
    {;}
}

/* LCD Haz�r Olana Kadar Bekle Fonksiyonu */
void LcdHazir ()
{
   Data=0xFF;	      // LCD den veri almaya hazirlan 	  	
   RS = 0;	      // komut modu
   RW = 1;	      // LCDden okuma
   EN = 1;         // yetki i�in d��en kenar ayar�
   Gecikme(200);   // k�sa bir bekleme s�resi
   while(Data & 0x7F == 0x80); // mesgul bitini kontrol et.
}

/* LCD'ye Komut Yazd�rma Fonksiyonu */
void Komut (int komut) 
{
  LcdHazir();      // LCD hazir olana kadar bekle
  RS=0;	      // RS komut modunda
  RW=0;	      // RW yaz modunda
  EN=1;	// i�lemin yetkilendirilmesi i�in d��en kenar ayar�           
  Data=komut;	      // LCD data giri�lerine komut bilgisini aktar
  EN=0;	      // yetki i�in d��en kenar sa�land�
  Gecikme(1000);   // gecikme
}	
/* LCD'ye Tek Bir Karakter Yazd�rma Fonksiyonu */
void Veri (char veri, long int hiz)	
{
  LcdHazir();      // LCD hazir olana kadar bekle
  RS=1;	      // RS komut modunda
  RW=0;	      // RW yaz modunda
  EN=1;	      // yetki i�in d�sen kenar ayar i�lemi
  Data=veri;       // LCD data giri�lerine veri bilgisini aktar
  EN=0;            // yetki i�in d��en kenar sa�land�
  Gecikme(hiz); // Ekranda karakterlerin g�r�nmesi aras�ndaki s�re
}

/* LCD'ye Karakter Dizisi (String) Yazd�rma Fonksiyonu */
/*void VeriDizi (char veri[], long int hiz)	
{
  int i=0;
  while(veri[i]!=0)
  {
    LcdHazir();     // LCD hazir olana kadar bekle
    RS=1;	       // RS komut modunda
    RW=0;	       // RW yaz modunda
    EN=1;	       // yetki i�in d�sen kenar ayar i�lemi
    Data=veri[i];   // LCD data giri�lerine veri bilgisini aktar
    EN=0;           // yetki i�in d��en kenar sa�land�
    i++;   // bir sonraki veri bitini almak i�in dizi'yi 1 artt�r 
    Gecikme(hiz);   // karakterlerin g�r�nmesi aras�ndaki s�re
  }
}*/
/* LCD Ba�lang�� Ayarlar�n� Yapan Fonksiyon */
void LcdAc(void)            
{ 	
  Komut(ImlecGizle);
  Komut(CiftSatir8Bit);
  Komut(SagaYaz);
}

