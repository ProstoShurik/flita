
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int deg2(short deg){
  int result=2;
  if(deg==0){
    return 1;
  }
  for(short i=1;i<deg;i++){
    result=result*2;
  }
  return result;
}


int bin_perevod(char arg1[]){
  char len=strlen((arg1));
  int summ=0;
  char counter=0;
  for(char y=len-1;y>=0;y--){
      summ=summ+((deg2(counter)*(arg1[y]-48)));
      counter++;
  }
  return summ;
}

int main(void){
  char input;
  int decimal[128];  char processing[128];
  char counter1=0 ;char counter2=0; char counter3=0 ;char counted=0;
  while ((input=getchar())!='\n'){
   if(input!=' '){
        processing[counter1]=input;
        counter1++;
    }
    if(input==' '){
    decimal[counter2]=bin_perevod(processing);
    counter2++;
    memset(processing,0,strlen(processing));
    counter1=0;
    }
  }
  decimal[counter2]=bin_perevod(processing);
    counter2++;
    memset(processing,0,strlen(processing));
    counter1=0;
  for(int j=0;j<counter2;j++){
      printf("%d ",decimal[j]);
  }
}

