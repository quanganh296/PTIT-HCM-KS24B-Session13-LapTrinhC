#include <stdio.h>

int GCD(int a,int b){
  int gcd=1;
  for(int i=0;i>=1;i++){
    if(a%i==0&&b%i==0){
        gcd=i;
        printf("%d",i);
    }
    return gcd;

  }

}


int main() {
    int a, b;

 
    printf("Nhap so thu nhat: ");
    scanf("%d", &a);
    printf("Nhập so thu hai: ");
    scanf("%d", &b);

    printf("Uoc chung lon nhat cua hai so la: %d ",GCD(a,b));
    
    return 0;
}
