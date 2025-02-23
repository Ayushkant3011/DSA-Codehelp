#include<iostream>
#include<unordered_map>
using namespace std;




int main(){
    
    // creation
    unordered_map<string,int> mapping;

    // insertion
    pair<string, int> p = make_pair("love", 25);
    pair<string, int> q("ayush", 21);

    pair<string, int> r;
    r.first= "MS";
    r.second = 21;

    mapping.insert(p);
    mapping.insert(q);
    mapping.insert(r);
    mapping["babbar"] = 25;

    cout << "Size of map: " << mapping.size() << endl;
    
    // Accesss
    cout << mapping.at("ayush") << endl;
    cout << mapping["love"] << endl;

    // searching
    cout << mapping.count("love") << endl;
    cout << mapping.count("kant") << endl;

    if(mapping.find("babbar") != mapping.end()){ //find function will return iterator
        cout << "Found" << endl;
    } 
    else{
        cout << "Not Found" << endl; 
    }

    cout << "Size of Map: " << mapping.size() << endl;
    
    cout << mapping["kant"] << endl;

    cout << "Size of Map: " << mapping.size() << endl;

    return 0;
}