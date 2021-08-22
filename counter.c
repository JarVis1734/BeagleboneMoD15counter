# include <stdio.h>

int main(){
	int a[4]={0},count,n,max_count =25,max_led=5;
	int i;
	for(count=0;count<max_count;count++){
		n = count;
		
			for(i=0;n>0;i++){    
				a[i]=n%2;    
				n=n/2;    
				}      
	    printf("\nBinary of Given Number is=");
			for(i=max_led-1;i>=0;i--){
				printf("%d",a[i]);
				
		}
	}
	return 0;
}
