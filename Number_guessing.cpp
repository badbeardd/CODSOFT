#include <iostream>
#include <random>
#include <ctime>
#include <cstdlib>

using namespace std;

mt19937 eng;

inline int random_generation()
{
    int min = 1;
    int max = 10;

    uniform_int_distribution<> distr(min, max);
    int random_num = distr(eng);

    cout << "Random number between " << min << " and " << max << ": " << random_num << endl;
    return random_num;
}
int main() {
    eng.seed(time(0));

    int random_number = random_generation();

    while(true){
        int input;
        cout<<" Guess The Number within 1 to 10: ";
        cin>>input;

        if(input - random_number == 0 ){
            cout<<" Correct Number"<<endl;
            break;
        }
        else if(input - random_number > 0){
            cout<<" Too High"<<endl;
        }
        else if(input - random_number < 0){
            cout<<" Too Low"<<endl;
        }
        else{
            cout<<" Not in Range"<<endl;
        }
       cout << "Press Enter to clear the screen..." << endl;
       cin.ignore();
       cin.get();
       system("cls");
    }
    return 0;
}
