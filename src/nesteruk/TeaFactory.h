#pragma once
#include <memory>
#include <HotDrinkFactory.h>

struct HotDrink;

struct TeaFactory : HotDrinkFactory {
  std::unique_ptr<HotDrink> make() const override {
    return std::make_unique<Tea>();
  }
};