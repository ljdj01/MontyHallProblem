#include <iostream>

using namespace std;

int main()
{
    int ub = 9, lb = 1;
    srand(time(0));
    
    int nPlayed = 0, nWon = 0, nLose = 0 ;
    int wonByChange = 0, wonByNotChanging = 0;
    int lostByChange = 0, lostByNotChanging = 0;
    
    while(true){
        
        int action;
        bool doors[3] = {false};
        cout << "<><><><><><><><><><><><><><><><><><><><>\n" << endl;
        cout << "Pick your action from the list\n";
        cout << "1. Play\n";
        cout << "2. Stats\n";
        cout << "0. Exit\n";
        cout << "-------------------\n";
        
        cin >> action;
        
        switch (action){
            case 1:{
                int prizeDoor;
                int r = (rand() % (ub - lb + 1)) + lb;
                if(r >= 1 && r< 3) prizeDoor = 0;
                else if(r >= 3 && r < 6) prizeDoor = 1;
                else prizeDoor = 2;
                
                doors[prizeDoor] = true;
                
                cout << "Pick your door 0, 1 or 2:\n";
                int pickedDoor;
                cin >> pickedDoor;
                if(pickedDoor > 2) {
                    cout << "!!! GRESKA !!!";
                    break;
                }
                cout <<"You picked door ";
                cout << pickedDoor;
                cout << endl;
                
                int hostDoor;
                
                if(doors[(pickedDoor + 1) % 3] == false){
                    hostDoor = (pickedDoor + 1) % 3;
                }else if(doors[(pickedDoor + 2) % 3] == false){
                    hostDoor = (pickedDoor + 2) % 3;
                }
                
                cout << "Host says that there is no prize behind door ";
                cout << hostDoor;
                cout << "\nWould you like to change your pick to other remaining door?\n";
                cout << "0. No\n";
                cout << "1. Yes\n";
                
                int change;
                cin >> change;
                
                if(change != 0 && change != 1){
                    cout << "!!! GRESKA !!!";
                    break;
                }
                
                switch (change){
                    case 0:{
                        
                    }break;
                    case 1:{
                        for(int i = 0; i < 3; i++){
                            if(i != pickedDoor && i != hostDoor){
                                pickedDoor = i;
                                break;
                            }
                        }
                        cout << "You changed your pick to door ";
                        cout << pickedDoor << endl;
                        
                    }
                }
                nPlayed++;
                if(doors[pickedDoor] == true){
                    cout<<"YOU WON\n";
                    nWon++;
                    if (change == 0 ){
                        wonByNotChanging++;
                    }else if(change == 1){
                        wonByChange++;
                    }
                }else{
                    cout<<"YOU LOSE\n";
                    nLose++;
                    if (change == 0 ){
                        lostByNotChanging++;
                    }else if(change == 1){
                        lostByChange++;
                    }
                }
                
                cout << "---------------------------\n";
            }break;
            
            case 2:{
                cout << "---------------------------\n";
                cout << "Played " << nPlayed << " times." << endl;
                cout << nWon << " times you won. "<< endl;
                cout << "From which:\n" << wonByChange << " by changing \n" << wonByNotChanging << " by not changing\n" << endl;
                cout << nLose << " times you lost. " << endl;
                cout << "From which:\n" << lostByChange << " by changing \n" << lostByNotChanging << " by not changing\n" << endl;
                cout << "---------------------------\n";
            }break;
            
            case 0: return 0;
            
        }
        
        
    }

    return 0;
}
