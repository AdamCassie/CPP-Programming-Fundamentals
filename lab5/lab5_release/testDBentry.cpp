#include <iostream>
#include <sstream>
#include <string>
using namespace std;

#include "DBentry.h"

// test harness below

int main () {
    DBentry i;
    DBentry j("name", 5, true);
    cout << j.getName() << " " << j.getIPaddress() << " " << j.getActive() << endl;
    
    i.setName("Izra");
    i.setIPaddress(619);
    i.setActive(true);
    cout << i.getName() << " " << i.getIPaddress() << " " << i.getActive() << endl;
    
    string title = "Aaron";
    int num = 3294951;
    bool flag = false;
    j.setName(title);
    j.setIPaddress(num);
    j.setActive(flag);
    cout << j.getName() << " " << j.getIPaddress() << " " << j.getActive() << endl;
    
    operator<<(cout, j);
    operator<<(cout, i);
    
    return 0;
}