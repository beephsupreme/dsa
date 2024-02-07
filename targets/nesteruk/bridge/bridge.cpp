#include <bits/stdc++.h>
#include <boost/lexical_cast.hpp>
#include <gtest/gtest.h>

using namespace std;

struct Renderer {
  virtual void render_circle(float x, float radius) = 0;
};

struct VectorRenderer : Renderer {
  void render_circle(float x, float radius) override {
    cout << "Rasterizing a circle of radius" << radius << endl;
  }
};

struct RasterRenderer : Renderer {
  void render_circle(float x, float radius) override {
    cout << "Drawing a vector circle of radius" << radius << endl;
  }
};

struct Shape {
 protected:
  Renderer &renderer;
  Shape(Renderer &renderer) : renderer(renderer) {}
 public:

};

TEST(BridgeTestSuite, BasicTests) {
  cout << "Ready To Test!" << endl;
}

int main(int ac, char *av[]) {
  testing::InitGoogleTest(&ac, av);
  return RUN_ALL_TESTS();
}
