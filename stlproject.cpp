// Example program
#include <iostream>
#include <list>
#include<algorithm>
using namespace std;

int main (){
list<int>thelist; //creation of the list
list<int>::iterator t1; //creation of the iterator
for(int x=1; x<=15; x++)
thelist.push_back(x*2);
t1 = find(thelist.begin(), thelist.end(), 10); //algorithm
thelist.insert(t1, 9);
for (t1 = thelist.begin(); t1 != thelist.end(); t1++) 
        cout << *t1 << " ";
        
cout << endl;
return 0;
}