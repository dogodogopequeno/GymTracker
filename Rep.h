#include "Header.h"
#pragma once
class Rep
{
public:
    Rep();
    Rep(int Weight, int Count);
    Rep(const Rep& Rep);
    Rep(Rep&& Rep) noexcept;
    ~Rep();
    friend std::ostream& operator<<(std::ostream& os, const Rep obj);
    void Print();
    int getWeight() const;
    int getCount() const;

    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive& ar, const unsigned int version)
    {
       // std::cout << "Serializing Rep: weight=" << weight << " count=" << count << std::endl;
        ar& weight;
        ar& count;
    }

    int weight {};
    int count {};
}; 

