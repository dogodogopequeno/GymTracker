#include "Header.h"
#include "Exercise.h"
#include "Set.h"
#include "Rep.h"
#pragma once
class Workout
{
public:
    Workout();
    Workout(std::vector<Exercise> Exercises, std::string Name);
    Workout(std::string Name);
    Workout(const Workout& other);
    Workout(Workout&& other) noexcept;
    ~Workout();

    friend class boost::serialization::access;
    friend std::ostream& operator<<(std::ostream& os, const Workout obj);
    void SaveExercises(std::ofstream& OFS);
    void LoadExercises(std::ifstream& IFS);

    void Print();
    std::vector<Exercise>& getExercises();
    Exercise& getExercise(std::string& ExerciseName);
    std::string& getName();
    void deleteName();
    void addExercise(std::string& Name);
    void addExercise(Exercise& exercise);

    template<class Archive>
    void serialize(Archive& ar, const unsigned int version)
    {
        ar& exercises;
        ar& name;
    }

    std::string id{};
    std::vector<Exercise> exercises{};
    std::string name {};
    size_t size = exercises.size();
};

