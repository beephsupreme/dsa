#pragma once
#include <bits/stdc++.h>
#include <Neuron.h>

using namespace std;

struct NeuronLayer : vector<Neuron>, SomeNeurons<NeuronLayer> {
    explicit NeuronLayer(int count) {
        while (count-- > 0) {
            emplace_back(Neuron{});
        }
    }

    friend ostream &operator<<(ostream &os, const NeuronLayer &obj) {
        for (auto &n : obj) {
            os << n;
        }
        return os;
    }
};