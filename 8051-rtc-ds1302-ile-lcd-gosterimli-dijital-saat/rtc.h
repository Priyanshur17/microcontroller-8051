
#define RTC_SCLK P3_0
#define RTC_IO   P3_1
#define RTC_RST  P3_2

void delay_us(int tekrar)
{
	int i;
	for(i=0;i<=tekrar;i++);
}
void bit_yaz(int c)
{
	RTC_IO=c;
	RTC_SCLK=1;
	RTC_SCLK=0;
	RTC_IO=1;
}
int bit_oku()
{
	int c;
	c=RTC_IO;
	RTC_SCLK=1;
	RTC_SCLK=0;
	return c;
}
void write_ds1302_byte(int cmd)
{
	int i,simdiki_bit;
	for(i=0;i<=7;++i)
	{
		simdiki_bit=cmd>>i;
		simdiki_bit=simdiki_bit&1;
		bit_yaz(simdiki_bit);
	}
}

void write_ds1302(int cmd, int veri)
{
   RTC_RST=1;
   write_ds1302_byte(cmd);
   write_ds1302_byte(veri);
   RTC_RST=0;
}
int read_ds1302(int cmd)
{
   int i,veri=0;

   RTC_RST=1;
   write_ds1302_byte(cmd);
   for(i=0;i<=7;++i) 
		veri=veri|(bit_oku()<<i);
   RTC_RST=0;
   return veri;
}

void rtc_init(void)
{
   int x;
   RTC_RST=0;
   delay_us(2);
   RTC_SCLK=0;
   write_ds1302(0x8e,0);
   write_ds1302(0x90,0xa6);
   x=read_ds1302(0x81);
   if((x & 0x80)!=0)
     write_ds1302(0x80,0);
}

int get_bcd(int veri)
{
   int nibh;
   int nibl;

   nibh=veri/10;
   nibl=veri-(nibh*10);

   return((nibh<<4)|nibl);
}

/*int rm_bcd(int veri)
{
   int i;
   i=veri;
   veri=(i>>4)*10;
   veri=veri+(i<<4>>4);
   return veri;
}*/
  int rakam(int veri)
{
	int i;
	i=veri;
	veri=((i>>4)&0x0F)*10;
	veri=veri+(i&0x0F);
	return veri;
}
void rtc_set_datetime(int day,int mth,int year,int dow,int hr,int min)
{
   write_ds1302(0x86,get_bcd(day));
   write_ds1302(0x88,get_bcd(mth));
   write_ds1302(0x8c,get_bcd(year));
   write_ds1302(0x8a,get_bcd(dow));
   write_ds1302(0x84,get_bcd(hr));
   write_ds1302(0x82,get_bcd(min));
   write_ds1302(0x80,get_bcd(0));
}

void rtc_get_date(int *day, int *mth, int *year, int *dow)
{
   *day = rakam(read_ds1302(0x87));
   *mth = rakam(read_ds1302(0x89));
   *year = rakam(read_ds1302(0x8d));
   *dow = rakam(read_ds1302(0x8b));
}

void rtc_get_time(int *hr, int *min, int *sec)
{
   *hr = rakam(read_ds1302(0x85));
   *min = rakam(read_ds1302(0x83));
   *sec = rakam(read_ds1302(0x81));
}
/*
void rtc_write_nvr(BYTE address, BYTE data) {
   write_ds1302(address|0xc0,data);
}

BYTE rtc_read_nvr(BYTE address) {
    return(read_ds1302(address|0xc1));
}
*/


