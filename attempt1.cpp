#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

//--------------------void marks() is just an attempt--------------------//
//--------------------it can be ignored----------------------------------//
void Marks(){
    deque<double> studentMarks;
    deque<double>::iterator it;
    
    for(int a = 0; a < 20; a+=2){
        studentMarks.push_back(a*10);
    }

    for(int a = 0; a < studentMarks.size(); a++){
        cout << studentMarks[a] << endl;
    }
    cout << "============the end=============" <<endl;

    it = find(studentMarks.begin(), studentMarks.end(), 70);
    cout<< *it << "is" << endl << "this what you are looking for????? hmmmmm" << endl;
};
//--------------------------void MarksNumber2() is the actual one----------//
void MarksNumber2(){
    deque<double> studentMarks;
    deque<double>::iterator it;
//--------request user to input a series of random number to be sorted-----------//
    int a;
    cout << "Please enter a series of numbers and enter 0 to end:" <<endl;
    
    do{
        cin >> a;
        studentMarks.push_back(a);
    }
    while(a != 0);
    
    cout<< "==========your numbers before sorting below=======================" <<endl;
    
    for(it = studentMarks.begin(); it < studentMarks.end(); it++){
        cout << *it << endl;
    }
    cout << "============ your numbers after sorting below=============" <<endl;
    
    sort(studentMarks.begin(), studentMarks.end());
    
    for(it = studentMarks.begin(); it < studentMarks.end(); it++){
        cout << *it << endl;
    }
};

int main(){
//    Marks();
    MarksNumber2();
    return 0;
}