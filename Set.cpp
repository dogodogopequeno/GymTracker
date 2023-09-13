#include "Set.h"

Set::Set() {}

Set::Set(int setID, std::vector<Rep> Reps) : setId(setID), reps(Reps) {}

Set::Set(int setId) : setId(setId) 
{
   // std::cout << "Normal set constructor" << std::endl;
}
Set::~Set()
{
   // std::cout << "Set destroyed" << std::endl;
}

Set::Set(Set&& set) noexcept : setId(std::move(set.setId)), reps(std::move(set.reps))
{
    //std::cout << "set Move constructor" << std::endl;
}

Set::Set(const Set& set) : setId(set.setId)
{
    //std::cout << "set copy constructor" << std::endl;
}

void Set::addRep(int weight, int count) 
{
    reps.push_back(Rep(weight, count));
}

int Set::getId() const 
{
    return setId;
}

std::ostream& operator<<(std::ostream& os, const Set obj)
{
    return os;
}

void Set::Print()
{
    std::cout << "Set: "<< getId() << std::endl;
}

 std::vector<Rep>& Set::getReps() 
{
    return reps;
}

 void Set::SaveReps(std::ofstream& OFS)
 {
     //boost::archive::text_oarchive ar(OFS);
     //ar& reps;
     ////for (Rep& rep : reps)
     ////{
     ////    ar& rep;
     ////}
 }

 void Set::LoadReps(std::ifstream& IFS)
 {
     //boost::archive::text_iarchive ar(IFS);
     //ar& reps;
     ////for (Rep& rep : reps)
     ////{
     ////    ar& rep;
     ////}
 }