#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_char 100

int main()
{
    int arr[max_char] = {};
    int temp = 0;
    int counter = 1;
    int dosyaya[max_char][2] = {}; //  {a,b},{c,d},{e,f}...
    int kopya[max_char][2] = {};   //  {a,b},{c,d},{e,f}...   
    FILE *ptr;
    ptr = fopen("input.txt", "r");   //input.txt operations

    if (ptr == NULL)
    {
        printf("ERROR\n");
        return 1;
    }

    int tempInt = 0;
    int i = 0;
    int arrlength = 0;
    while (!feof(ptr))
    {
        fscanf(ptr, "%d", &tempInt);
        arr[i] = tempInt;
        i++;
    }
    arrlength = i;

    for (int i = 0; i < arrlength; i++)        //first i ordered the numbers against their numeritical order
    {
        for (int j = i + 1; j < arrlength; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    int z = 0;
    for (int i = 0; i < arrlength;)
    {
        for (int j = 0; j < arrlength; j++)
        {
            if (arr[i] == arr[j])
            {
                dosyaya[z][0] = arr[i];
                ++dosyaya[z][1]; // it was already 0 so i could increment it
            }
        }
        i += dosyaya[z][1];
        z++;
    }

    for (int p = 0; p < arrlength; p++)     //copied second array for compare
    {
        for (int k = 0; k < 2; k++)
            kopya[p][k] = dosyaya[p][k];
    }
    temp = 0;

    for (int i = 0; i < arrlength; i++)        //for which number is bigger 
    {
        for (int j = i + 1; j < arrlength; j++)
        {
            if (dosyaya[i][1] > dosyaya[j][1])
            {
                temp = dosyaya[i][1];
                dosyaya[i][1] = dosyaya[j][1];
                dosyaya[j][1] = temp;
            }
        }
    }

    temp = 0;
    for (int i = 0; i < arrlength; i++)    //to carry first index's numbers against their value
    {
        for (int j = 0; j < arrlength; j++)
        {
            if (dosyaya[i][1] == kopya[j][1])
            {
                temp = kopya[j][0];
                kopya[j][0] = dosyaya[i][0];
                dosyaya[i][0] = temp;
            }
        }
    }
      
    FILE *pr;                         //output.txt
    pr = fopen("output.txt", "w");

    for (int j = 0; j < arrlength; j++)
    {
        if (dosyaya[j][1] != 0)        
            fprintf(pr,"%d :: %d\n", dosyaya[j][0], dosyaya[j][1]);
    }
    fclose(pr);
    return 0;
}
