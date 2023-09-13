#include "Header.h"
#include "workout.h"
#include "Exercise.h"
#include "Set.h"
#include "Rep.h"
#include "Date.h"
#include "Meal.h"
#pragma once
class app
{
public:
    app();
    app(std::vector<Workout> Workouts, std::vector<Date> Dates);
    ~app();

    //friend 
    friend std::ostream& operator<<(std::ostream& os, const app obj);

    //Boost
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive& ar, const unsigned int version)
    {
        ar& workouts;
        ar& dates;
    }

    void SaveData(std::ofstream& OFS);
    void LoadData(std::ifstream& IFS);

    // workout functionality
    void Print();
    std::vector<Workout>& getWorkouts();
    Workout& getWorkout(std::string& WorkoutName);
    void addWorkout(Workout& workout);
    void addWorkout(std::string name);

    // Init
    void Run();

    std::string MainMenu(std::string& input);

    void WorkoutMenu();
    std::string WorkoutOptions(std::string& Winput);
    void WorkoutResult(Exercise& exercise);
    void DisplayWorkoutResult(Exercise& exercise, Set& set, std::vector<Rep>& reps);
    void DisplayWorkout(Workout& workout);
    void DisplayWorkouts();

    // helper functions
    int sets(Exercise& obj);
    int reps(int sets, Set& obj);
    std::string& getFilename();

    // Calorie functions
    std::string CalorieMenu(std::string& calories, int& valueCalories);
    void DisplayCalories(std::vector<Date>& dates);

    // Weight functions
    std::string WeightMenu(std::string& weight, double& valueWeight);

    // Date functions
    void addDate(Date& date);
    void addDate(std::chrono::system_clock::time_point timePoint);

    Date& getDateObj(int ID);
    Date& getDateObj(std::chrono::system_clock::time_point timePoint);



    std::string id{};
    std::vector<Workout> workouts;
    int value{};
    std::string input{};
    bool running = true;

    std::string filename {"Text.txt"};

    std::string weight{};
    std::string calories{};
    double valueWeight {};
    int valueCalories {};

    int day{};
    std::vector<Date> dates{};
    std::chrono::system_clock::time_point p_tp;
};

