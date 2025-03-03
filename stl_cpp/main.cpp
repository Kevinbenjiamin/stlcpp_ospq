
#include <cstdlib>
#include <iostream>

#include "include/speechManager.h"
#include <time.h>


int main(){
    srand((unsigned int) time(NULL));

    SpeechManager sm;
    int choice;
    while(true){
        sm.show_Menu();
        cout << "input choice: "<< endl;
        cin >> choice; //接受用户的选项

        switch(choice){
            case 1: //start
                sm.startSpeech();
                break;
            case 2: //查看记录
                sm.showRecord();
                break;
            case 3:
                sm.clearRecord();
                break;
            case 0:
                sm.exitSystem();
            default:
                system("cls");//清屏
                break;

        }

    }
    system("pause");
    return 0;
}