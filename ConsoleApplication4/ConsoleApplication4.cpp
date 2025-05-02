#include <iostream>

template<typename T1,typename T2,typename T3>
T1 calc(T1 a,T2 b,T3 oper){
    double res;
    if(oper=='+'){
        res = a+b;
    }
    else if(oper=='-'){
        res = a-b;
    }
    else if(oper=='*'){
        res = a*b;
    }
    else if(oper=='/'){
        res = a/b;
    }
    return res;
}

template<typename c>
void reverse(int size,c arr[]){
    for(int i=size-1;i>-1;i--){
        std::cout<<arr[i]<<" ";
    }
}
template<typename d>
void mix(int size,d arr[]){
    srand(time(0));
    for (int i = 0; i < size; i++) {
        int j = i + rand() % (size - i);
        d temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
template<typename u>
u unique(int size,u arr[]){
    int quantity=0;
    for(int i = 0; i < size; i++){
        int count=0;
        for(int j = 0; j < size; j++){
            if(arr[i]==arr[j]){
                count+=1;
            }
        }
        if(count==1){
            quantity+=1;
        }
    }
    return quantity;
}
template<typename last>
last sub(int size_1,last arr[],int size_2,last arr_2[]){
    int i;
    bool match = true;
    for (i = 0; i <= size_1 - size_2; i++) {
        if(arr[i]==arr_2[0]){
            bool match = true;
            for (int j = 0; j < size_2; j++) {
                if (arr[i + j] != arr_2[j]) {
                    match = false;
                    break;
                }
            }
        }
    }
    if (match) {
        return i;
    }
}
int main() {
    int arr[5]={1,2,3,4,5};
    int arr_2[6]={1,2,2,4,4,5};
    int arr_3[2]={3,4};
    std::cout<<calc(1.2,8,'+')<<std::endl;
    std::cout<<calc(1,6.8,'-')<<std::endl;
    std::cout<<calc(1,6.8,'*')<<std::endl;
    std::cout<<calc(1,6.8,'/')<<std::endl;
    reverse(5,arr);
    std::cout<<std::endl;
    mix(5,arr);
    for (int i = 0; i < 5; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout<<std::endl;
    std::cout<<unique(6,arr_2)<<std::endl;
    std::cout<<std::endl;
    std::cout<<sub(5,arr,2,arr_3)<<std::endl;
    
    return 0;
}