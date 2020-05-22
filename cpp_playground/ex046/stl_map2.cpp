#include <string>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    map<int, string> employees{{100, "orestis"}};
    employees.insert(pair<int, string>(101, "maria")); //α τρόπος προσθήκης στοιχείου
    employees.insert(pair<int, string>(102, "nikos"));
    employees.insert(pair<int, string>(201, "sofia"));
    employees.insert(pair<int, string>(301, "petros"));
    employees.insert({302, "ioanna"}); //β τρόπος προσθήκης στοιχείου
    employees[401] = "christos";       //γ τρόπος προσθήκης στοιχείου


    // α τρόπος διάσχισης του map
    // for (map<int, string>::iterator itr = employees.begin(); itr != employees.end(); itr++)
    for (auto itr = employees.begin(); itr != employees.end(); itr++)
    {
        cout << itr->first << " " << itr->second << endl;
    }
    cout << "Number of employess: " << employees.size() << endl;

    // β τρόπος διάσχισης του map
    for (auto kv : employees)
    {
        cout << kv.first << " " << kv.second << endl;
    }
    cout << "Number of employess: " << employees.size() << endl;

    // εύρεση στοιχείου και διαγραφή στου στοιχείου στο οποίο δείχνει ο iterator
    auto it = employees.find(201);
    if (it != employees.end())
    {
        cout << "Found " << it->second;
        employees.erase(it);
        cout << " and delete" << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }

    // διαγραφή με βάση τιμή κλειδιού
    employees.erase(401);
    for_each(employees.begin(), employees.end(), [](pair<int, string> kv) { cout << kv.first << " " << kv.second << endl; });
    cout << "Number of employess: " << employees.size() << endl;
}

/*
100 orestis
101 maria  
102 nikos  
201 sofia  
301 petros 
302 ioanna
401 christos
Number of employess: 7
100 orestis
101 maria
102 nikos
201 sofia
301 petros
302 ioanna
401 christos
Number of employess: 7
Found sofia and delete
100 orestis
101 maria
102 nikos
301 petros
302 ioanna
Number of employess: 5
*/