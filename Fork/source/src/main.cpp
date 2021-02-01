#include <iostream>
#include <sys/wait.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
using namespace std;

string hora_nascimento(time_t nasceu){
    string hora_nascimento; 
    time(&nasceu);
    hora_nascimento = ctime(&nasceu);
    return hora_nascimento;
}




int main(){
    pid_t pid[5]={-1,-1,-1,-1,-1};
    time_t initial =time(0);
    time_t nasceu;
    string nascimentos[5];
    time_t born = time(0), morte;
    time_t int_nascidos[5];


    nasceu = time(&initial);
    nascimentos[0] = hora_nascimento(nasceu);
    int_nascidos[0] = nasceu;
    cout << "Pai nasceu. " << endl;
    cout << "Hora de nascimento: " << nascimentos[0];
    cout << "Pid do pai: " << getpid() << endl;

    sleep(14);
    pid[0] = fork(); 
   
    if(pid[0] < 0){
        exit(-1);
    }   
    else if(pid[0] == 0){
        //filho #1

        time_t born = time(0);
        nascimentos[1] = hora_nascimento(born);
        int_nascidos[1] = born;
        cout<<"Teve o filho#1 com :"<<born-initial<<" anos"<<endl ;
        cout << "Hora de nascimento: " << nascimentos[1];
        cout << "Pid do filho 1: " << getpid() << endl;


        //processo filho#1 tem filho 
        sleep(12);//pai = 26
        born= time(0);
        cout<<"Filho#1 teve um filho"<< endl ;
        cout<<"Teve o primeiro neto (filho do 1º filho) com :"<<born-initial<<" anos"<<endl;
        
    

        pid[2] = fork();//Filho do filho#1
        born= time(0);
        nascimentos[3] = hora_nascimento(born);
        int_nascidos[3] = born;

        

        if(pid[2] < 0){
            exit(-1);
        } else if(pid[2]==0){
            //neto filho#1
            cout << "Hora de nascimento: " << nascimentos[3];
            cout << "Pid primeiro neto: " << getpid() <<endl;

            sleep(12);
            morte = time(NULL);
            cout<<"Neto do Filho#1 morreu."<<endl;
            cout << "Hora de nascimento: " << nascimentos[3];
            time(&morte);
            cout << "Hora da morte: " << ctime(&morte);
            cout << "Quantos anos viveu: " << morte-int_nascidos[3] << endl;

            exit(0);
        }else if(pid[2]>0){           
            //filho #1
            born= time(0);

            sleep(18);
            morte = time(0);
            cout<<"Filho#1 morreu. " <<endl;
            cout << "Hora de nascimento: " << nascimentos[1];
            time(&morte);
            cout << "Hora da morte: " << ctime(&morte);
            cout << "Quantos anos viveu: " << morte-int_nascidos[1] << endl;

            exit(0);
        }
    }else if(pid[0]>0){

        //pai
        //se pid for pai cria seu filho#2
        
        sleep(2);//16 anos
        born = time(0);//Filho#2
        nascimentos[2] = hora_nascimento(born);
        int_nascidos[2] = born;

        cout<<"Teve o filho#2 com :"<<born-initial<<" anos"<<endl;
        cout << "Hora de nascimento: " << nascimentos[2];

        pid[1]= fork();

        if(pid[1]<0){
            exit(-1);
        }else if(pid[1]==0){
            //filho#2
            cout << "Pid do filho 2: " << getpid() << endl;
            born= time(0);

            sleep(14);
            born= time(0);

            cout<<"Filho#2 teve um filho"<<endl;
            cout<<"Teve o segundo neto (filho do segundo filho) com :"<<born-initial<<" anos"<<endl;
            nascimentos[4] = hora_nascimento(born);
            int_nascidos[4] = born;

            pid[3]=fork();

            if(pid[3]<0){
                exit(-1);
            }else if(pid[3]==0){
                //neto filho#2

                cout << "Hora de nascimento: " << nascimentos[4];
                cout <<"Pid do segundo neto: " << getpid() << endl;
                sleep(18);
                morte = time(0);
                cout<<"Neto Filho#2 morreu. "<<endl;
                cout << "Hora de nascimento: " << nascimentos[4];
                time(&morte);
                cout << "Hora da morte: " << ctime(&morte);
                cout << "Quantos anos viveu: " << morte-int_nascidos[4] << endl;
                
                exit(0);

            }else if(pid[3]>0){
            //Filho#2
        
                sleep(16);
                morte = time(0);
                cout<<"Filho#2 morreu."<<endl;
                cout << "Hora de nascimento: " << nascimentos[2];
                time(&morte);
                cout << "Hora da morte: " << ctime(&morte);
                cout << "Quantos anos viveu: " << morte-int_nascidos[2] << endl;

                exit(0);
            }
        }
        
        wait(NULL);
        wait(NULL);
        wait(NULL);
        sleep(14);


        morte = time(0);
        cout<<"Pai morreu. "<<endl;
        cout << "Hora de nascimento: " << nascimentos[0];
        time(&morte);
        cout << "Hora da morte: " << ctime(&morte);
        cout << "Quantos anos viveu: " << morte-initial << endl;
        cout<<"-----Acabou-----"<<endl;


        return 0;
    }
}