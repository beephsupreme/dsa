#include <bits/stdc++.h>
#include <boost/lexical_cast.hpp>
#include <gtest/gtest.h>

using namespace std;
using namespace boost;

class Database {
 public:
  virtual int get_population(const string &name) = 0;
};

class SingletonDatabase : public Database {
  SingletonDatabase() {
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
  SingletonDatabase(SingletonDatabase const &) = delete;
  void operator=(SingletonDatabase const &) = delete;
  static SingletonDatabase &get() {
    static SingletonDatabase db;
    return db;
  }
  int get_population(const string &name) override {
    return capitals[name];
  }
};

struct SingletonRecordFinder {
  static int total_population(const vector<string> &names) {
    int result{0};
    for (auto &name : names) {
      result += SingletonDatabase::get().get_population(name);
    }
    return result;
  }
};

class DummyDatabase : public Database {
  map<string, int> capitals;
 public:
  DummyDatabase() {
    capitals["alpha"] = 1;
    capitals["beta"] = 2;
    capitals["gamma"] = 3;
  }
  int get_population(const string &name) override {
    return capitals[name];
  }
};

struct ConfigurableRecordFinder {
  Database& db;
  explicit ConfigurableRecordFinder(Database& db) : db(db) {}
  int total_population(const vector<string> &names) {
    int result{0};
    for (auto &name : names) {
      result += db.get_population(name);
    }
    return result;
  }
};

TEST(RecordFinderTests, SingletonPopulationTest) {
  vector<string> names{"Seoul", "Mexico City", "Tokyo"};
  int tp = SingletonRecordFinder::total_population(names);
  EXPECT_EQ(17500000 + 17400000 + 33200000, tp);
}

TEST(RecordFinderTests, DependentPopulationTest) {
  DummyDatabase db;
  ConfigurableRecordFinder rf{db};
  vector<string> names{"alpha", "beta", "gamma"};
  int tp = rf.total_population(names);
  EXPECT_EQ(1+2+3, tp);
}

int main(int ac, char *av[]) {
  testing::InitGoogleTest(&ac, av);
  return RUN_ALL_TESTS();
}
