#include<stdio.h>
#define max 25
int main(){
    int frag[max],b[max],p[max],i,j,nb,np,temp,lowest=10000;
    static int bf[max],pf[max];
    scanf("%d",&nb);
    scanf("%d",&np);
    for(i=1;i<=nb;i++){
        scanf("%d",&b[i]);
    }
    for(i=1;i<=np;i++){
        scanf("%d",&p[i]);
    }
    for(i=1;i<=np;i++){
        for(j=1;j<=nb;j++){
            if(bf[j]!=1){
                temp=b[j]-p[i];
                if(temp>=0){
                    if(lowest>temp){
                        pf[i]=j;
                        lowest=temp;
                    }
                }
            }
        }
        frag[i]=lowest;
        bf[pf[i]]=1;
        lowest=10000;
    }
    printf("Process_no\tProcess_size\tBlock_no\tBlock_size\tFragment");
    for(i=1;i<=np && pf[i]!=0;i++){
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",i,p[i],pf[i],b[pf[i]],frag[i]);
    }
    return 0;
}
