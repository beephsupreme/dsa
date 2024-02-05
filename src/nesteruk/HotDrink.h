#include <iostream>
#include <map>
#include <memory>
#include <string>

struct HotDrink {
    virtual ~HotDrink() = default;
    virtual void prepare() = 0;
};

struct Tea : HotDrink {
    void prepare() override
    {
        std::cout << "Take tea bag, boil water, pour 200 ml, "
                  << "add some lemon, enjoy!" << std::endl;
    }
};

struct Coffee : HotDrink {
    void prepare() override
    {
        std::cout << "Grind some beans, boil water, pour 50 ml, "
                  << "add cream, enjoy!" << std::endl;
    }
};
