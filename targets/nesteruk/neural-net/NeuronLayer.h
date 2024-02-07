#pragma once

#include <bits/stdc++.h>
#include <Neuron.h>
#include <SomeNeurons.h>

using namespace std;

struct Neuron;

struct NeuronLayer : vector<Neuron>, SomeNeurons<NeuronLayer>
{
  NeuronLayer(int count)
  {
      while (count-- > 0)
          emplace_back(Neuron{});
  }

  friend ostream &operator<<(ostream &os, NeuronLayer &obj)
  {
      for (auto &n : obj)
          os << n;
      return os;
  }
};