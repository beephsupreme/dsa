#include <bits/stdc++.h>

#include <utility>

using namespace std;

struct GraphicObject {
  virtual void draw() = 0;
};

struct Circle : GraphicObject {
  void draw() override {
    cout << "circle" << endl;
  }
};

struct Group : GraphicObject {
  string name;
  vector<GraphicObject *> objects;

  explicit Group(string name) : name(std::move(name)) {}

  void draw() override {
    cout << "Group " << name.c_str() << " contains: " << endl;
    for (auto &&o : objects) {
      o->draw();
    }
  }
};

using namespace std;

int main() {
  Group root("root");
  Circle c1;
  Circle c2;
  root.objects.push_back(&c1);
  root.objects.push_back(&c2);

  Group subgroup("sub");
  Circle c3;
  subgroup.objects.push_back(&c3);

  root.objects.push_back(&subgroup);
  root.draw();
  return EXIT_SUCCESS;
}
