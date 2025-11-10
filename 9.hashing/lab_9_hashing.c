//pavan Bokare-IT-B-153
/*AIM: Assume that you have a seven-slot closed hash table (the slots are numbered o through 6) Write program  to final hash table that would result if you used the hash function h(k) - k mod 7.*/

#include <stdio.h>

int main(){
    int hash[7], i, key, index, n;
    for(i=0;i<7;i++) hash[i] = -1;

    printf("Enter number of keys: ");
    scanf("%d",&n);

    while(n--){
        printf("Enter key: ");
        scanf("%d",&key);
        index = key % 7;

        while(hash[index] != -1)
            index = (index + 1) % 7;
        hash[index] = key;
    }
    printf("\nFinal Hash Table:\n");
    for(i=0;i<7;i++)
        printf("Index %d -> %d\n",i,hash[i]);
}