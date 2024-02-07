#pragma once

#include <bits/stdc++.h>
#include <SomeNeurons.h>
#include <NeuronLayer.h>

using namespace std;

struct Neuron : SomeNeurons<Neuron>
{
  vector<Neuron *> in, out;
  unsigned int id;

  Neuron()
  {
      static int id = 1;
      this->id = id++;
  }

  template<typename T> void connect_to(T &other)
  {
      for (Neuron &target : other)
          connect_to(target);
  }

  // legal in MSVC only
  /*template<> void connect_to<Neuron>(Neuron& other)
  {
    out.push_back(&other);
    other.in.push_back(this);
  }*/

  // connect_to(vector<Neuron>&)

  Neuron *begin()
  { return this; }
  Neuron *end()
  { return this + 1; }

  friend ostream &operator<<(ostream &os, const Neuron &obj)
  {
      for (Neuron *n : obj.in) {
          os << n->id << "\t-->\t[" << obj.id << "]" << endl;
      }

      for (Neuron *n : obj.out) {
          os << "[" << obj.id << "]\t-->\t" << n->id << endl;
      }
      return os;
  }
};