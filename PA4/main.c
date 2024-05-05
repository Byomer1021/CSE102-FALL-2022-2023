#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define kelime 100

#define ROW_SIZE 100
#define COL_SIZE 250

void Esearch(char words[kelime][10], char table[ROW_SIZE][COL_SIZE], int row, int kelime_sayisi,char direction[kelime][3],int indexes[100][2])//East direction
{
    int kelime_x = 0;
    int flag = 0, found = 0;
    int start = 0;

    for (kelime_x = 0; kelime_x < kelime_sayisi - 1; kelime_x++)//this for rotates words 
    {
        for (int i = 0; i < row; i++)//this is rotates rows
        {
            for (int j = 0; table[i][j] != '\0'; j++)//this is for columns
            {
                if (j + strlen(words[kelime_x]) <= 250 && table[i][j] == words[kelime_x][start] && words[kelime_x][start] != '\0') //this if checks for words first letter equals table letters??? and also checks boundaries
                {

                    int h;
                    for (h = 0; h < strlen(words[kelime_x]); h++)// if first if true this for starts to rotate along word length
                    {
                        if (table[i][j + h] == words[kelime_x][h])//this if controls the other letter along east direction
                            found++;//increment found for every match so we can compare main word length and finding word 
                    }
                }
                else
                    found = 0, start = 0;// if first if false this provide keep continue
                if (found == strlen(words[kelime_x]))//checking for main word and finding word
                {
                    indexes[kelime_x][0]=i+1; //things to go output file ,first one row second column third is direction
                    indexes[kelime_x][1]=j+1;
                    direction[kelime_x][0]='E';
                    
                    kelime_x++;//for next word
                    if (kelime_x == kelime_sayisi)//for checking all words finished
                        flag = 1;
                    found = 0;
                    start = 0;
                }
            }
            if (flag)
                break;
        }
    }
}
void SEsearch(char words[kelime][10], char table[ROW_SIZE][COL_SIZE], int row, int kelime_sayisi,char direction[kelime][3],int indexes[100][2]) //aynı işlem farklı yön farkı sadece yoruma üstle aynı
{
    int kelime_x = 0;
    int flag = 0, found = 0;
    int start = 0;

    for (kelime_x = 0; kelime_x < kelime_sayisi - 1; kelime_x++)
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; table[i][j] != '\0'; j++)
            {
                if (i + strlen(words[kelime_x]) <= row && j + strlen(words[kelime_x]) <= 250 && table[i][j] == words[kelime_x][start] && words[kelime_x][start] != '\0') 
                {

                    int h;
                    for (h = 0; h < strlen(words[kelime_x]); h++)
                    {
                        if (table[i + h][j + h] == words[kelime_x][h])
                            found++;
                    }
                }
                else
                    found = 0, start = 0;
                if (found == strlen(words[kelime_x]))
                {
                    indexes[kelime_x][0]=i+1;
                    indexes[kelime_x][1]=j+1;
                    direction[kelime_x][0]='S';
                    direction[kelime_x][1]='E';
                    
                    kelime_x++;
                    if (kelime_x == kelime_sayisi)
                        flag = 1;
                    found = 0;
                    start = 0;
                }
            }
            if (flag)
                break;
        }
    }
}
void Ssearch(char words[kelime][10], char table[ROW_SIZE][COL_SIZE], int row, int kelime_sayisi,char direction[kelime][3],int indexes[100][2])
{
    int kelime_x = 0;
    int flag = 0, found = 0;
    int start = 0;

    for (kelime_x = 0; kelime_x < kelime_sayisi - 1; kelime_x++)
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; table[i][j] != '\0'; j++)
            {
                if (i + strlen(words[kelime_x]) <= row && table[i][j] == words[kelime_x][start] && words[kelime_x][start] != '\0') //&& start<strlen(words[kelime_x]))
                {

                    int h;
                    for (h = 0; h < strlen(words[kelime_x]); h++)
                    {
                        if (table[i + h][j] == words[kelime_x][h])
                            found++;
                    }
                }
                else
                    found = 0, start = 0;
                if (found == strlen(words[kelime_x]))
                {
                    indexes[kelime_x][0]=i+1;
                    indexes[kelime_x][1]=j+1;
                    direction[kelime_x][0]='S';
                    
                    kelime_x++;
                    if (kelime_x == kelime_sayisi)
                        flag = 1;
                    found = 0;
                    start = 0;
                }
            }
            if (flag)
                break;
        }
    }
}
void SWsearch(char words[kelime][10], char table[ROW_SIZE][COL_SIZE], int row, int kelime_sayisi,char direction[kelime][3],int indexes[100][2])
{
    int kelime_x = 0;
    int flag = 0, found = 0;
    int start = 0;

    for (kelime_x = 0; kelime_x < kelime_sayisi - 1; kelime_x++)
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; table[i][j] != '\0'; j++)
            {
                if (i + strlen(words[kelime_x]) <= row && j - strlen(words[kelime_x]) >= 0 && table[i][j] == words[kelime_x][start] && words[kelime_x][start] != '\0') //&& start<strlen(words[kelime_x]))
                {

                    int h;
                    for (h = 0; h < strlen(words[kelime_x]); h++)
                    {
                        if (table[i + h][j - h] == words[kelime_x][h])
                            found++;
                    }
                }
                else
                    found = 0, start = 0;
                if (found == strlen(words[kelime_x]))
                {
                    indexes[kelime_x][0]=i+1;
                    indexes[kelime_x][1]=j+1;
                    direction[kelime_x][0]='S';
                    direction[kelime_x][1]='W';
                    
                    kelime_x++;
                    if (kelime_x == kelime_sayisi)
                        flag = 1;
                    found = 0;
                    start = 0;
                }
            }
            if (flag)
                break;
        }
    }
}
void Wsearch(char words[kelime][10], char table[ROW_SIZE][COL_SIZE], int row, int kelime_sayisi,char direction[kelime][3],int indexes[100][2])
{
    int kelime_x = 0;
    int flag = 0, found = 0;
    int start = 0;

    for (kelime_x = 0; kelime_x < kelime_sayisi - 1; kelime_x++)
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; table[i][j] != '\0'; j++)
            {
                if (j - strlen(words[kelime_x]) >= 0 && table[i][j] == words[kelime_x][start] && words[kelime_x][start] != '\0') 
                {

                    int h;
                    for (h = 0; h < strlen(words[kelime_x]); h++)
                    {
                        if (table[i][j - h] == words[kelime_x][h])
                            found++;
                    }
                }
                else
                    found = 0, start = 0;
                if (found == strlen(words[kelime_x]))
                {
                    indexes[kelime_x][0]=i+1;
                    indexes[kelime_x][1]=j+1;
                    direction[kelime_x][0]='W';
                    
                    kelime_x++;
                    if (kelime_x == kelime_sayisi)
                        flag = 1;
                    found = 0;
                    start = 0;
                }
            }
            if (flag)
                break;
        }
    }
}
void NWsearch(char words[kelime][10], char table[ROW_SIZE][COL_SIZE], int row, int kelime_sayisi,char direction[kelime][3],int indexes[100][2])
{
    int kelime_x = 0;
    int flag = 0, found = 0;
    int start = 0;

    for (kelime_x = 0; kelime_x < kelime_sayisi - 1; kelime_x++)
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; table[i][j] != '\0'; j++)
            {
                if (i - strlen(words[kelime_x]) >= 0 && j - strlen(words[kelime_x]) >= 0 && table[i][j] == words[kelime_x][start] && words[kelime_x][start] != '\0') //&& start<strlen(words[kelime_x]))
                {

                    int h;
                    for (h = 0; h < strlen(words[kelime_x]); h++)
                    {
                        if (table[i - h][j - h] == words[kelime_x][h])
                            found++;
                    }
                }
                else
                    found = 0, start = 0;
                if (found == strlen(words[kelime_x]))
                {
                    indexes[kelime_x][0]=i+1;
                    indexes[kelime_x][1]=j+1;
                    direction[kelime_x][0]='N';
                    direction[kelime_x][1]='W';
                    
                    kelime_x++;
                    if (kelime_x == kelime_sayisi)
                        flag = 1;
                    found = 0;
                    start = 0;
                }
            }
            if (flag)
                break;
        }
    }
}
void Nsearch(char words[kelime][10], char table[ROW_SIZE][COL_SIZE], int row, int kelime_sayisi,char direction[kelime][3],int indexes[100][2])
{
    int kelime_x = 0;
    int flag = 0, found = 0;
    int start = 0;

    for (kelime_x = 0; kelime_x < kelime_sayisi - 1; kelime_x++)
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; table[i][j] != '\0'; j++)
            {
                if (i - strlen(words[kelime_x]) >= 0 && table[i][j] == words[kelime_x][start] && words[kelime_x][start] != '\0' && i - strlen(words[kelime_x]) >= 0) //&& start<strlen(words[kelime_x]))
                {

                    int h;
                    for (h = 0; h < strlen(words[kelime_x]); h++)
                    {
                        if (table[i - h][j] == words[kelime_x][h])
                            found++;
                    }
                }
                else
                    found = 0, start = 0;
                if (found == strlen(words[kelime_x]))
                {
                    indexes[kelime_x][0]=i+1;
                    indexes[kelime_x][1]=j+1;
                    direction[kelime_x][0]='N';
                    
                    kelime_x++;
                    if (kelime_x == kelime_sayisi)
                        flag = 1;
                    found = 0;
                    start = 0;
                }
            }
            if (flag)
                break;
        }
    }
}
void NEsearch(char words[kelime][10], char table[ROW_SIZE][COL_SIZE], int row, int kelime_sayisi,char direction[kelime][3],int indexes[100][2])
{
    int kelime_x = 0;
    int flag = 0, found = 0;
    int start = 0;

    for (kelime_x = 0; kelime_x < kelime_sayisi - 1; kelime_x++)
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; table[i][j] != '\0'; j++)
            {
                if (i - strlen(words[kelime_x]) >= 0 && j + strlen(words[kelime_x]) <= 250 && table[i][j] == words[kelime_x][0] && words[kelime_x][start] != '\0') //&& start<strlen(words[kelime_x]))
                {
                    int h;
                    for (h = 0; h < strlen(words[kelime_x]); h++)
                    {
                        if (table[i - h][j + h] == words[kelime_x][h])
                            found++;
                    }
                    if (found == strlen(words[kelime_x]))
                    {
                        indexes[kelime_x][0]=i+1;
                        indexes[kelime_x][1]=j+1;
                        direction[kelime_x][0]='N';
                        direction[kelime_x][1]='E';
                       
                        kelime_x++;
                        if (kelime_x == kelime_sayisi)
                            flag = 1;
                        found = 0;
                        start = 0;
                    }
                }
                else
                    found = 0, start = 0;
            }
            if (flag)
                break;
        }
    }
}
void print_file(FILE *p,char words[kelime][10],char direction[kelime][3],int indexes[100][2],int word_number)//output file proccess
{
    for(int i=0;i<word_number;i++)
    {
        if(indexes[i][1]!=-1)
            fprintf(p,"%s (%d,%d) %s\n", words[i], indexes[i][0], indexes[i][1],direction[i]);  
    }
}
void null_edit(char *des) //this function is for free array for next row
{
    int i = 0;
    while (des[i] != 0)
    {
        des[i] = 0;
        i += 1;
    }
}

int main()
{
    FILE *ptr, *pr, *p;
    int i = 0, j, kelime_sayisi = 0;
    char directions[kelime][3];
    char words[kelime][10];
    char table[100][250];
    char arr[1000];
    ptr = fopen("input1.txt", "r");
    while (!feof(ptr))
    {
        fscanf(ptr, "%s", words[i]);//ı got the words from input1
        kelime_sayisi++;//to find how many words in file
        i++;
        if (i > 100)//if there is over than hundered words it breaks
            break;
    }
    const int index_of_word=i;
    int indexes[100][2];
    for (int h = 0,m=0;m<kelime, h < 100;m++, h++) //for searching direction and locations and which word is ı create this proccess
    {
        directions[m][0]=0;
        directions[m][1]=0;
        directions[m][2]=0;
        indexes[h][0]=-1;
        indexes[h][1]=-1;
        /* code */
    }
    
    fclose(ptr);

    char tempchar = 0;
    int row = 0;
    j = 0;
    pr = fopen("input2.txt", "r");
    i = 0;
    while (!feof(ptr))
    {
        tempchar = getc(pr);//first ı got whole letter then put in a array
        arr[j] = tempchar;
        j++;
        if (tempchar == '\0' || tempchar == '\n')
        {
            strcpy(table[i], arr);//then ı copied row by row double matrix array
            i++;//this is count row number
            null_edit(arr);//this function provides the free array for next row
            j = 0;
        }
        table[i][j] = arr[j];
    }

    row = i;
    fclose(pr);

    p = fopen("output.txt", "w"); //for output

    Esearch(words, table, row, kelime_sayisi,directions,indexes);
    SEsearch(words, table, row, kelime_sayisi,directions,indexes);
    Ssearch(words, table, row, kelime_sayisi,directions,indexes);
    SWsearch(words, table, row, kelime_sayisi,directions,indexes);
    NWsearch(words, table, row, kelime_sayisi,directions,indexes);
    Nsearch(words, table, row, kelime_sayisi,directions,indexes);
    NEsearch(words, table, row, kelime_sayisi,directions,indexes);
    print_file(p,words,directions,indexes,kelime_sayisi);

    fclose(p);
}