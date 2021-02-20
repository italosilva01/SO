#include <iostream>
#include <pthread.h>

using namespace std;
float area = 0;
int status;

void* hello_world(void *tid){
    cout<<"estes"<<endl;
    pthread_exit(NULL);
}

int main(){
    int t,n;

    cout<<"Digite a quantidade de threads"<<endl;
    cin>>t;
    cout<<"Digite a quantidade de trapezios"<<endl;
    cin>>n;
    pthread_t threads[n];
    cout<<"Testeando a função 1°"<<"\n"<<endl;
    for (int i = 0; i<t;i++){
        status = pthread_create(&threads[i],NULL,hello_world,(void*)(size_t)n);
        
    }


    return 0;
}