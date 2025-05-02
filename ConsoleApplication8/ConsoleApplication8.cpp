#include<iostream>
int str_len(char arr[])
{
    int length = 0;
    for (int i = 0; arr[i] != '\0'; i++)
    {
        length+=1;
    }
    return length;
}
char* str_chr(char arr[], char a)
{
    for(int i = 0; arr[i] != '\0'; i++)
    {
        if (arr[i]==a)
        {
            return &arr[i];
        }
    }
}
char* str_str(char arr[],char a[]) 
{
    int c=0,b=0;
    for(int i = 0; arr[i] != '\0'; i++)
    {
        if(arr[i]==a[0])
        {
            b=i;
        }
        if (arr[i]==a[c])
        {
            c+=1;
            
        }
        else
        {
            c=0;
        }
        if(c==str_len(a))
        {
            return &arr[b];
        }
    }
}
int str_cmp(char arr[],char arr_2[])
{
    srand(time(0));
    int equals=0;
    if (str_len(arr)>str_len(arr_2))
    {
        return 1;
    }
    if (str_len(arr)<str_len(arr_2))
    {
        return -1;
    }
    for(int i = 0; arr[i] != '\0'; i++)
    {
        if (arr[i]==arr_2[i])
        {
            equals+=1;
        }
    }
    if(equals==str_len(arr_2))
    {
        return 0;
    }
    else
    {
        return rand()%2-1;
    }
}
char* str_cat(char arr[],char a[])
{
    int size=str_len(arr)+str_len(a)+1;
    char* temp=new char[size];
    for(int i = 0; i <str_len(arr); i++)
    {
        temp[i]=arr[i];
    }
    int s=0;
    for(int i = str_len(arr); temp[i] != '\0'; i++)
    {
        temp[i]=a[s];
        s+=1;
    }
    return &temp[0];
}

void str_copy(char arr[],char arr_2[],int count)
{
    for(int i = 0; i < count; i++)
    {
        arr[i]=arr_2[i];
    }
}
int main()
{
    char str[12]="hello world";
    char str_2[]="hello";
    char str_3[]="Floyd";
    char str_4[]="Floyd";
    std::cout<<str_len(str)<<" "<<strlen(str)<<"\n";
    std::cout<<str_chr(str,'o')<<" "<<strchr(str,'o')<<"\n";
    std::cout<<str_str(str,str_2)<<" "<<strstr(str,"hello")<<"\n";
    std::cout<<str_cmp(str_3,str_4)<<" "<<str_cmp(str_3,str)<<" "<<str_cmp(str,str_3)<<"\n";
    std::cout<<strcmp(str_3,str_4)<<" "<<strcmp(str_3,str)<<" "<<strcmp(str,str_3)<<"\n";
    std::cout<<str_cat(str_3,str_4)<<" "<<str_cat(str_3,str)<<" "<<str_cat(str,str_3)<<"\n";
    char src[] = "Salam";
    char dest[20];
    str_copy(dest, src, sizeof(dest) - 1);
    dest[sizeof(dest) - 1] = '\0';

    std::cout << dest << "\n";
    
    
    return 0;
    
}
