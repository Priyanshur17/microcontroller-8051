/****************************************************************/
/* 				     T_LCD.H	 	 		     */
/****************************************************************/

/* LCD'de kullanýlan komutlarýn tanýmlanmasý */
#define Sil 		 1	// Ekraný temizler
#define BasaDon 	 2	// Ýmleci sol üst köþeye getirir
#define SolaYaz 	 4  // Ýmlecin belirttiði adres azalarak gider
#define SagaYaz 	 6   // Ýmlecin belirttiði adres artarak gider
#define ImlecGizle	 12	// Göstergeyi aç, kursör görünmesin
#define ImlecYanSon	 15	// Yanýp sönen blok kursör
#define ImlecGeri	 16	// Kursörü bir karakter geri kaydýr
#define KaydirSaga	 24	// Göstergeyi bir karakter saða kaydýr                   
#define KaydirSola   28	// Göstergeyi bir karakter sola kaydýr   
#define EkraniKapat	 8	// Göstergeyi kapat (veriler silinmez)
#define BirinciSatir 128	// LCD'nin ilk satir baþlangýç adresi       
                          // (DDRAM adres)
#define IkinciSatir  192	// Ýkinci satýrýn baþlangýç adresi
#define KarakUretAdres 64	// Karakter üreteci adresini belirle  
                          // (CGRAM adres)

/* LCD'de Kullanýlan Fonksiyon Seçimi */
#define CiftSatir8Bit  56	 // 8 bit ara birim, 2 satýr, 5*7 piksel
#define CiftSatir4Bit  48	 // 8 bit ara birim, 1 satýr, 5*7 piksel
#define TekSatir8Bit   40	 // 4 bit ara birim, 2 satýr, 5*7 piksel
#define TekSatir4Bit   32	 // 4 bit ara birim, 1 satýr, 5*7 piksel

/* LCD Giriþlerinin Tanýmlanmasý */
#define Data  P1	  // LCD Data giriþleri için port ata
#define RS	P2_0 // Saklayýcý seçme giriþi RS=0 komut, RS=1 veri
#define RW	P2_1  // Oku/Yaz giriþi RW=0 yaz, RW=1 oku
#define EN	P2_2   // Yetki giriþi 

/* LCD Gecikme Fonksiyonu */
void Gecikme (long int sure)
{
  long int i;
  for (i=1;i<=sure;i++)
    {;}
}

/* LCD Hazýr Olana Kadar Bekle Fonksiyonu */
void LcdHazir ()
{
   Data=0xFF;	      // LCD den veri almaya hazirlan 	  	
   RS = 0;	      // komut modu
   RW = 1;	      // LCDden okuma
   EN = 1;         // yetki için düþen kenar ayarý
   Gecikme(200);   // kýsa bir bekleme süresi
   while(Data & 0x7F == 0x80); // mesgul bitini kontrol et.
}

/* LCD'ye Komut Yazdýrma Fonksiyonu */
void Komut (int komut) 
{
  LcdHazir();      // LCD hazir olana kadar bekle
  RS=0;	      // RS komut modunda
  RW=0;	      // RW yaz modunda
  EN=1;	// iþlemin yetkilendirilmesi için düþen kenar ayarý           
  Data=komut;	      // LCD data giriþlerine komut bilgisini aktar
  EN=0;	      // yetki için düþen kenar saðlandý
  Gecikme(1000);   // gecikme
}	
/* LCD'ye Tek Bir Karakter Yazdýrma Fonksiyonu */
void Veri (char veri, long int hiz)	
{
  LcdHazir();      // LCD hazir olana kadar bekle
  RS=1;	      // RS komut modunda
  RW=0;	      // RW yaz modunda
  EN=1;	      // yetki için düsen kenar ayar iþlemi
  Data=veri;       // LCD data giriþlerine veri bilgisini aktar
  EN=0;            // yetki için düþen kenar saðlandý
  Gecikme(hiz); // Ekranda karakterlerin görünmesi arasýndaki süre
}

/* LCD'ye Karakter Dizisi (String) Yazdýrma Fonksiyonu */
/*void VeriDizi (char veri[], long int hiz)	
{
  int i=0;
  while(veri[i]!=0)
  {
    LcdHazir();     // LCD hazir olana kadar bekle
    RS=1;	       // RS komut modunda
    RW=0;	       // RW yaz modunda
    EN=1;	       // yetki için düsen kenar ayar iþlemi
    Data=veri[i];   // LCD data giriþlerine veri bilgisini aktar
    EN=0;           // yetki için düþen kenar saðlandý
    i++;   // bir sonraki veri bitini almak için dizi'yi 1 arttýr 
    Gecikme(hiz);   // karakterlerin görünmesi arasýndaki süre
  }
}*/
/* LCD Baþlangýç Ayarlarýný Yapan Fonksiyon */
void LcdAc(void)            
{ 	
  Komut(ImlecGizle);
  Komut(CiftSatir8Bit);
  Komut(SagaYaz);
}

