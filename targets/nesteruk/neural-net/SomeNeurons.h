#pragma once

#include <bits/stdc++.h>
#include <Neuron.h>
#include <NeuronLayer.h>

using namespace std;

template<typename Self>
struct SomeNeurons
{
  template<typename T> void connect_to(T &other)
  {
      for (Neuron &from : *static_cast<Self *>(this)) {
          for (Neuron &to : other) {
              from.out.push_back(&to);
              to.in.push_back(&from);
          }
      }
  }
};
