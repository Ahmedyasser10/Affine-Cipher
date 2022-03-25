#include <iostream>
using namespace std;
#include <vector>

int main() {

    vector<char> alphabet{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S','T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    vector<int> index;
    vector<int> x;

    int a, b, c, r, j;
    string s, z ;


    cout << "please enter the text that you want to encrypt or decrypt it:" << endl;
    getline(cin, s);
    for (int i = 0; i < s.length(); ++i) {
        s[i] = toupper(s[i]);
    }
    cout << "please Enter the keys 'a','b' and 'c' separated by spaces " << endl;
    cin >> a >> b >> c;
    while ((a * c) % 26 != 1) {

        cout << "invalid keys " << endl;
        cout << "please Enter the keys 'a','b' and 'c' separated by spaces " << endl;
        cin >> a >> b >> c;
    }

    for (int i = 0; i < s.length(); ++i) {

        for (int j = 0; j < 26; ++j) {
            if (s[i] == alphabet.at(j))
                index.push_back(j);
        }
    }
  cout<<"Enter '1' to encrypt the text or '2' to decrypt it: ";
    cin>>r;
   if(r==1){
       for(int i=0 ;i<index.size();++i){

           x.push_back( ((a*index.at(i)) + b ) % 26 );

       }for(int i =0; i<x.size(); ++i){
           z+=alphabet.at(x.at(i));


       }cout<<"the encrypted message is: "<<z<<endl;

   } else{
        for (int i =0; i<index.size(); ++i){

            j = (c * (index.at(i) - b)) % 26;
            if(j<0){
               j+=26;


            }x.push_back(j);

        }
       for (int i = 0; i <x.size() ; ++i) {

           z+=alphabet.at(x.at(i));
       }
       cout<<"the decrypted message is: "<<z<<endl;

   }

}












