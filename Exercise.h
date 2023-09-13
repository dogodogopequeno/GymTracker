#include "Header.h"
#include "Set.h"
#pragma once
class Exercise
{
public:
    Exercise();
    Exercise(std::string Name, std::vector<Set> Sets);
    Exercise(const std::string& name);
    Exercise(const Exercise& exercise);
    Exercise(Exercise&& exercise) noexcept;
    ~Exercise();
    void addSet(int setId);
    void addRepToSet(int setId, int weight, int count);
    void Print();
    std::string GetName() const;
    friend std::ostream& operator<<(std::ostream& os, const Exercise obj);
    friend class boost::serialization::access;
    std::vector<Set>& getSets();

    template<class Archive>
    void serialize(Archive& ar, const unsigned int version)
    {
        ar& name;
        ar& sets;
    }

    void SaveSets(std::ofstream& OFS);
    void LoadSets(std::ifstream& IFS);

    std::string name {};
    std::vector<Set> sets{};
};

