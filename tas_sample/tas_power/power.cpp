#include <wiringPi.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
 
#define POWER 17 // Enter your GPIO port
#define VCC_PIN 0

int power_on() {
  printf("%s\n", "Power ON!");
  digitalWrite(VCC_PIN,LOW);
  digitalWrite(POWER, LOW);
  return 0;
} 


int power_off() {
  printf("%s\n", "Power OFF!");
  digitalWrite(VCC_PIN,HIGH);
  digitalWrite(POWER, HIGH);
}

int main(int argc, char *argv[])
{
  int i;
  for (i=0; i<argc; i++) {
//    printf("Argument %d is %s \n",i,argv[i]);
  }

  wiringPiSetup();
  pinMode(VCC_PIN,OUTPUT);
  pinMode(POWER, OUTPUT);

  if(argc == 2){
    char* comm = argv[1];
    
    if(strcmp(comm, "1") == 0){
      power_on();
    } else if(strcmp(comm, "2") == 0){
      power_off();
    }

  }  

  return 0;
}
