#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <fstream>
#include <cmath>
using namespace std;
string intToStr(int value){
    string output;
    stringstream translator;
    translator << value;
    translator >> output;
    return output;
}
class user {
    
    public:
        void setName(string inputName);
        void setPasswd(string inputPasswd);
        void setPasswd();
        void setMethod(string inputMethod);
        void setMethod();
        string getInfo();
        string getMethod();
        string getPasswd();
        string name;
        string passwd;
        string method;

};
string user::getInfo(){
    return name + "    " + passwd + "    " + method;
}
void user::setName(string inputName){
    name = inputName;
}
void user::setPasswd(string inputPasswd){
    passwd = inputPasswd;
}
void user::setPasswd(){
    cout << "what is the password" << endl;
    cin >> passwd;
}
void user::setMethod(string inputMethod){
    method = inputMethod;
}
void user::setMethod(){
    cout << "what was the method" << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, method);
}
string user::getMethod(){
    return method;
}
string user::getPasswd(){
    return passwd;
}
int main(){
    cout << "what is the file/filepath" << endl;
    string filename = "";
    getline(cin, filename);
    fstream file(filename, ios::in | ios::out | ios::app);
    if(file){
        cout << "File loaded successfully" <<endl;
    } else {
        cout << "File failed to load" << endl;
        return 1;
    }
    cout << "where are you starting" << endl;
    int startUser = 0;
    cin >> startUser;
    cout << "what challenge is this (Bandit, Natal, etc)" << endl;
    string challengeName = "";
    cin >> challengeName;
    string challengeUser = challengeName + intToStr(startUser);
    user userCurrent;
    user userLast1;
    user userLast2;
    user userLast3;
    user userLast4;
    int count = 1;
    int a = 1;
    int b = 1;
    while (a == b){
        switch (count){
            case 1:{
                userLast4.setName(challengeUser);
                userLast4.setPasswd();
                userLast4.setMethod();
                file << startUser << "   " << userLast4.getInfo() << endl;
            }
            break;
            case 2:{
                userLast3.setName(challengeUser);
                userLast3.setPasswd();
                userLast3.setMethod();
                file << startUser << "   " << userLast3.getInfo() << endl;
            }
            break;
            case 3:{
                userLast2.setName(challengeUser);
                userLast2.setPasswd();
                userLast2.setMethod();
                file << startUser << "   " << userLast2.getInfo() << endl;
            }
            break;
            case 4:{
                userLast1.setName(challengeUser);
                userLast1.setPasswd();
                userLast1.setMethod();
                file << startUser << "   " << userLast1.getInfo() << endl;
            }
            break;
            case 5:{
                userCurrent.setName(challengeUser);
                userCurrent.setPasswd();
                userCurrent.setMethod();
                file << startUser << "   " << userCurrent.getInfo() << endl;
            }
            break;
        }
        count += 1;
        if (count == 6){
            count =1;
        }
        startUser += 1;
        challengeUser = challengeName + intToStr(startUser);
        cout << "is there a user you need to go back to (0 is none, 1 is most recent to 4 is least recent)" << endl;
        int pastUser=0;
        cin >> pastUser;
        int userTmp = 0;
        int tmp = 0;
        if(pastUser != 0){
            userTmp = count - pastUser;
            if(userTmp <= 0){
                userTmp = abs(userTmp);
            }
        } 
        switch(userTmp){
            case 1:
            {
                cout << userLast4.getInfo() << endl;
            }
            break;
            case 2:
            {
                cout << userLast3.getInfo() << endl;
            }
            break;
            case 3:
            {
                cout << userLast2.getInfo() << endl;
            }
            break;
            case 4:
            {
                cout << userLast1.getInfo() << endl;
            }
            break;
            case 5:
            {
                cout << userCurrent.getInfo() << endl;
            }
            break;
        }
        cout << "are you finished (y(0) or n(1))" << endl;
        cin >> a;
    }
    file.close();
}
