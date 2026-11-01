#include <iostream>
#include <string>

using namespace std;

int main(){

    int t;
    cin >> t;
    
    while(t > 0){

        string entry;
        cin >> entry;

        int entry_len = entry.size();

        bool pattern1 = false;
        bool pattern2 = false;

        int index = 1;
        while(index < entry_len - 1){

            if((entry[index - 1] == '1' && entry[index] == '0' && entry[index + 1] == '1') || 
            (entry[index - 1] == '0' && entry[index] == '1' && entry[index + 1] == '0')){
                pattern1 = true;
            }

            if((entry[index - 1] == '1' && entry[index] == '1' && entry[index + 1] == '1') || 
            (entry[index - 1] == '0' && entry[index] == '0' && entry[index + 1] == '0')){
                pattern2 = true;
            }

            if(pattern1 && pattern2) break;

            index++;
        }

        if(pattern1 && pattern2){
            cout << 3 << endl;
        } else if(pattern1 || pattern2){
            cout << 2 << endl;
        } else {
            cout << 1 << endl;
        }

        t--;
    }

}