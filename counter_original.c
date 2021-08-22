// This code is an original property of JarVis1734
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define LED0_PATH "/sys/class/leds/beaglebone:green:usr0/brightness"
#define LED1_PATH "/sys/class/leds/beaglebone:green:usr1/brightness"
#define LED2_PATH "/sys/class/leds/beaglebone:green:usr2/brightness"
#define LED3_PATH "/sys/class/leds/beaglebone:green:usr3/brightness"


void writeLED(char filename[] ,int val){
   FILE *fp = fopen(filename,"r+");
   if (val !=0){
       fwrite("1",sizeof(char),1,fp);
        }
   else{
      fwrite("0",sizeof(char),1,fp);
    }
   fclose(fp);
}
int main(){
    int a[4]={0},count,n,max_count =16,max_led=4;
    int i;
    for(count=0;count<max_count;count++){
        n = count;
        printf("\n Count : %d ",count);
        for(i=0;n>0;i++){
            a[i]=n%2;
            n=n/2;
        }
		printf("Binary of Given Number is=");
        for(i=max_led-1;i>=0;i--){
            printf("%d",a[i]);
		}
        writeLED(LED0_PATH,a[0]);
        writeLED(LED1_PATH,a[1]);
        writeLED(LED2_PATH,a[2]);
        writeLED(LED3_PATH,a[3]);
        usleep(1000000);
} //reset the leds
   writeLED(LED0_PATH,0);
   writeLED(LED1_PATH,0);
   writeLED(LED2_PATH,0);
   writeLED(LED3_PATH,0);
	return 0;
}