
// CPE301 Final Project - Spring '25
// Swamp Cooler
// Thomas Kelly

#include <Stepper.h>
#include <LiquidCrystal.h>
#include <Wire.h>
#include <RTClib.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHT_PIN A0;
#define DHTTYPE DHT11;

// define input pins

// define output pins

volatile unsigned char* my_ADMUX = (unsigned char*) 0x7C;
volatile unsigned char* my_ADCSRB = (unsigned char*) 0x7B;
volatile unsigned char* my_ADCSRA = (unsigned char*) 0x7A;
volatile unsigned int* my_ADC_DATA = (unsigned int*) 0x78;

volatile unsigned char *myUCSR0A = (unsigned char *) 0x00C0;
volatile unsigned char *myUCSR0B = (unsigned char *) 0x00C1;
volatile unsigned char *myUCSR0C = (unsigned char *) 0x00C2;
volatile unsigned char *myUBRR0 = (unsigned char *) 0x00C4;
volatile unsigned char *myUDR0 = (unsigned char *) 0x00C6;

enum CoolerStatus {DISABLED, IDLE, FAN_ON, ERROR};

LiquidCrystal lcd(52, 50, 48, 46, 44, 42);
Stepper stepper(2038, 27, 29, 31, 33);
DHT dht(2, DHT11);
RTC_DS1307 rtc;

void setup() {
  lcd.begin(16, 2);
  rtc.begin();
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  dht.begin();
  U0init(9200);
  adc_init();
}

void loop() {
  if (CURRENT_STATE == IDLE) {
    // monitor temp, water level
    // wait for off signal
  }
  if (CURRENT_STATE == FAN_ON) {
    // run fan
  }
  if (CURRENT_STATE == ERROR) {
    // wait for reset
  }
  if (CURRENT_STATE == DISABLED) {
    // wait for on signal
  }
}



void adc_init() //write your code after each commented line and follow the instruction 
{
 *my_ADCSRA |= 0b10000000;
 *my_ADCSRA &= 0b10111111;
 *my_ADCSRA &= 0b11011111;
 *my_ADCSRA &= 0b11111000;

 *my_ADCSRB &= 0b11110111;
 *my_ADCSRB &= 0b11111000;

 *my_ADMUX &= 0b01111111;
 *my_ADMUX |= 0b01000000;
 *my_ADMUX &= 0b11011111;
 *my_ADMUX &= 0b11100000;
}

unsigned int adc_read(unsigned char adc_channel_num) //work with channel 0
{
  *my_ADMUX &= 0b11100000;
  *my_ADMUX &= 0b11110111;
 
  if (adc_channel_num != 0)
  {
    adc_channel_num = 0;
  }

  *my_ADMUX |= 0b00000111;
  *my_ADCSRA |= 0b01000000;
  while((*my_ADCSRA & 0x40) != 0);
  unsigned int val = *my_ADC_DATA;
  return val;
}

void U0init(int U0baud)
{
 unsigned long FCPU = 16000000;
 unsigned int tbaud;
 tbaud = (FCPU / 16 / U0baud - 1);
 *myUCSR0A = 0x20;
 *myUCSR0B = 0x18;
 *myUCSR0C = 0x06;
 *myUBRR0  = tbaud;
}

unsigned char U0kbhit()
{
  return *myUCSR0A & RDA;
}

unsigned char U0getchar()
{
  return *myUDR0;
}

void U0putchar(unsigned char U0pdata)
{
  while((*myUCSR0A & TBE)==0);
  *myUDR0 = U0pdata;
}
