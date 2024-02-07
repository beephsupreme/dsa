#include <Point.h>
#include <cmath>

Point::Point(double x, double y) : x(x), y(y) {
}
std::ostream &operator<<(std::ostream &os, const Point &point) {
  os << "x: " << point.x << " y: " << point.y;
  return os;
}
Point Point::PointFactory::NewPolar(double r, double theta) {
  return Point{r * cos(theta), r * sin(theta)};
}
Point Point::PointFactory::NewCartesian(double x, double y) {
  return Point{x, y};
}
