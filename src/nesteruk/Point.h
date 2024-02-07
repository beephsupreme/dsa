#pragma once

#include <ostream>

class Point {
private:
    Point(double x, double y);
    class PointFactory {
    private:
        PointFactory() = default;
    public:
        static Point NewPolar(double r, double theta);
        static Point NewCartesian(double x, double y);
    };
public:
    static PointFactory Factory;
    double x;
    double y;
    friend std::ostream &operator<<(std::ostream &os, const Point &point);

};
