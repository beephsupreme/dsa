#pragma once

#include <boost/serialization/serialization.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <Address.h>
#include <string>
#include <utility>

struct Contact {
    std::string name;
    Address* address;

    Contact& operator=(const Contact& other)
    {
        if (this == &other)
            return *this;
        name = other.name;
        address = other.address;
        return *this;
    }

    Contact() = default;

    Contact(std::string name, Address* address)
        : name{std::move(name)}, address{address}
    {
        //this->address = new Address{ *address };
    }

    Contact(const Contact& other) : name{other.name}
    {
        address = new Address(
            other.address->street,
            other.address->city,
            other.address->suite
        );
    }

private:
    friend class boost::serialization::access;

    template<class archive>
    void save(archive& ar, const unsigned version) const
    {
        ar << name;
        ar << address;
    }

    template<class archive>
    void load(archive& ar, const unsigned version)
    {
        ar >> name;
        ar >> address;
    }

    BOOST_SERIALIZATION_SPLIT_MEMBER()

public:
    ~Contact()
    {
        delete address;
    }

    friend std::ostream& operator<<(std::ostream& os, const Contact& obj)
    {
        return os
            << obj.name
            << ": " << *obj.address; // note the star here
    }
};