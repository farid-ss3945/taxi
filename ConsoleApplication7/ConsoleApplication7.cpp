#include<iostream>

// task 1

// void seat_point(int arr[],int row,int col){
//     bool flag=true;
//     int a=0,b=0,c=col;
//     for(int i=0;i<row*col;i++){
//         if(i==row || (i%row==0 and i/row>0)){
//             a+=1;
//         }
//         if(b==row || (b%row==0 and b/row>0)){
//             b=0;
//             c=col;
//         }
//         for(int j=row*a;j<row*a+row;j++){
//             if(*(arr+j)<*(arr+i)){
//                 flag=false;
//                 break;
//             }
//             
//         }
//         for(int k=b;k<=row*col-c;k+=row){
//             if(*(arr+k)>*(arr+i)){
//                 flag=false;
//                 break;
//             }
//             
//         }
//         if(flag==true){
//             std::cout<<*(arr+i);
//         }
//         flag=true;
//         b+=1;
//         c-=1;
//     }
// }
//
// int main()
// {
//     int Arr[3][3]={{7,2,9},
//                    {6,5,8},
//                    {1,4,3}};
//                
//     seat_point(*Arr,3,3);
//     return 0;
// }

// =============================================

// task 2

// void turn(int arr[],int row,int col){
//     int a=*(arr+col-1);
//     int b=*(arr+row*col-1);
//     int c=*(arr+row*(col-1));
//     int temp=*arr,temp_2;
//     for(int i=1;i<col;i++){
//         temp_2=*(arr+i);
//         *(arr+i)=temp;
//         temp=temp_2;
//     }
//     temp=a,temp_2;
//     for(int i=2;i<row+1;i++){
//         temp_2=*(arr+i*col-1);
//         *(arr+i*col-1)=temp;
//         temp=temp_2;
//     }
//     temp=b,temp_2;
//     for(int i=1;i<col;i++){
//         temp_2=*(arr+row*col-1-i);
//         *(arr+row*col-1-i)=temp;
//         temp=temp_2;
//     }
//     temp=c,temp_2;
//     for(int i=row-2;i>=0;i--){
//         temp_2=*(arr+row*i);
//         *(arr+row*i)=temp;
//         temp=temp_2;
//     }
//     
// }
//
// int main()
// {
//     int Arr[4][4]={{1,2,3,4},
//                   {5,6,7,8},
//                   {9,10,11,12},
//                   {13,14,15,16}};
//     int another[2][2]={{1,2},
//                        {3,4}};
//     turn(*Arr,4,4);
//     turn(*another,2,2);
//     for(int i=0;i<4;i++){
//         for(int j=0;j<4;j++){
//             std::cout<<Arr[i][j]<<" ";
//         }
//         std::cout<<"\n";
//     }
//     for(int i=0;i<2;i++){
//         for(int j=0;j<2;j++){
//             std::cout<<another[i][j]<<" ";
//         }
//         std::cout<<"\n";
//     }
//     return 0;
// }

// =========================================

// task 3
//
// void magic_center(int arr[],int row,int col){
//     int sum_1=0,sum_2=0;
//     int a=0,b=0,c=col;
//     for(int i=0;i<row*col;i++){
//         sum_1=0,sum_2=0;
//         if(i==row || (i%row==0 and i/row>0)){
//             a+=1;
//         }
//         if(b==row || (b%row==0 and b/row>0)){
//             b=0;
//             c=col;
//         }
//         for(int j=row*a;j<row*a+row;j++){
//             sum_1+=*(arr+j);
//         }
//         for(int k=b;k<=row*col-c;k+=row){
//             sum_2+=*(arr+k);
//             
//         }
//         if(sum_1==sum_2){
//             std::cout<<*(arr+i);
//         }
//         b+=1;
//         c-=1;
//     }
// }
//
// int main()
// {
//     int Arr[3][3]={{4,9,2},
//                    {3,5,7},
//                    {8,1,6}};
//     int Arr_2[3][3]={{4,9,11},
//                      {3,2,12},
//                      {8,1,6}};
//     
//     magic_center(*Arr,3,3);
//     magic_center(*Arr_2,3,3);
//     return 0;
// }
