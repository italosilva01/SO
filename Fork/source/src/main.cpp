#include <iostream>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
using namespace std;

int main(){
    pid_t pid[5]={-1,-1,-1,-1,-1};
    time_t initial = time(0),born;
    sleep(14);
    pid[0] = fork(); 
   
    if(pid[0] < 0){
    
        exit(-1);
    }   
    else if(pid[0] == 0){
        //filho #1

       time_t bornSonOne = born= time(0);
        cout<<"Teve o primeiro filho com :"<<born-initial<<" anos"<<endl;

        //processo filho tem filho 
        sleep(12);
        born= time(0);
        cout<<"primeiro filho teve um filho"<<endl;
        cout<<"Teve o primeiro neto (filho do 1º filho) com :"<<born-initial<<" anos"<<endl;
        pid[2] = fork();//Filho do filho
        if(pid[2] < 0){
        
            exit(-1);
        } else
        if(pid[2]>0){
               //filho #1
               born= time(0);

               sleep(18);
                cout<<"Filho #1 morreu aos :"<<born-bornSonOne<<" anos"<<endl;

               exit(0) ;
        }else{
            //neto filho#1
         bornSonOne =  born = time(0);
            sleep(12);
            cout<<"Neto do Filho#1 morreu aos :"<<born-bornSonOne<<" anos"<<endl;
            exit(0);
        }
    }
    else{
        //pai
        //se pid for pai cria seu filho#2

        sleep(2);//16 anos
        born= time(0);

        cout<<"segundo filho nasceu"<<endl;
        cout<<"Teve o segundo filho com :"<<born-initial<<" anos"<<endl;
        pid[1]= fork();

        if(pid[1]<0){
            exit(-1);
        }else if(pid[1]==0){
        //neto filho2#
        born= time(0);

        sleep(4);
         born= time(0);

        cout<<"segundo filho teve um filho"<<endl;
        cout<<"Teve o segundo neto (filho do segundo filho) com :"<<born-initial<<" anos"<<endl;
        pid[3]=fork();
        

    }
    return 0;
    }