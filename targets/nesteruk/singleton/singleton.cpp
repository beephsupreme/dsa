#include <bits/stdc++.h>
#include <boost/lexical_cast.hpp>

using namespace std;
using namespace boost;

class SingletonDatabase {
    SingletonDatabase()
    {
        cout << "Initializing...\n";
        ifstream ifs("/Users/michael/projects/dsa/targets/nesteruk/singleton/capitals.txt");
        if (ifs.is_open()) {
            string s, s2;
            while (getline(ifs, s)) {
                getline(ifs, s2);
                int pop = lexical_cast<int>(s2);
                capitals[s] = pop;
            }
            ifs.close();
        } else {
            cout << "Unable to open file..." << endl;
        }
    }
    map<string, int> capitals;
public:
    SingletonDatabase(SingletonDatabase const&) = delete;
    void operator=(SingletonDatabase const&) = delete;
    static SingletonDatabase& get()
    {
        static SingletonDatabase db;
        return db;
    }
    int get_population(const string& name)
    {
        return capitals[name];
    }
};
int main()
{
    string city1 = "Tokyo";
    string city2 = "Mexico City";
    cout << city1 << ": " << SingletonDatabase::get().get_population(city1) << endl;
    cout << city2 << ": " << SingletonDatabase::get().get_population(city2) << endl;
    return EXIT_SUCCESS;
}
