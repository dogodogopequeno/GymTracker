#include "app.h"

void app::Run()
{
	do {
		MainMenu(input);
		std::stringstream ss{ input };
		if (ss >> value)
		{
			switch (value)
			{
			case 1:
				WorkoutMenu();
				break;
			case 2:
				CalorieMenu(calories, valueCalories);
				break;
			case 3:
				WeightMenu(weight, valueWeight);
				break;
			case 4:
				DisplayCalories(dates);
				break;
			case 5:
				DisplayWorkouts();
				break;
			case 6:
				running = false;
				break;
			default:
				MainMenu(input);
				break;
			}
		}
		else
		{
			std::cout << "Enter 1, 2, 3 or 4." << std::endl;
			MainMenu(input);
		}
	} while (running);
}

std::string app::MainMenu(std::string& input)
{
	std::cout << "What would you like to do? " << std::endl;
	std::cout << "1. Add workout" << std::endl <<
		"2. Add calories tracked" << std::endl <<
		"3. Add weight" << std::endl <<
		"4. Display your calories on a given Date." << std::endl <<
		"5. Display your workouts." << std::endl <<
		"6. Quit" << std::endl;
	std::cin >> input;

	return input;
}

void app::WorkoutMenu()
{
    Menu1:
	std::string workoutName{};
	std::cout << "What would you like to name this workout?" << std::endl;
	std::cin >> workoutName;
	bool running1{ true };
	do {
		if (workoutName == "")
		{
			goto Menu1;
		}
		else
		{
			std::cout << "You entered: " << workoutName << std::endl;
			running1 = false;
		}
	} while (running1);


	bool running2{ true };
	std::string Winput;
	int value{};
	Menu2:
	do {
		WorkoutOptions(Winput);
		{
			std::stringstream ss{ Winput };
			if (ss >> value)
			{
				switch (value)
				{
				case 1:
				{
					std::string BCP = "Barbell Chest Press";
					addWorkout(workoutName);
					getWorkout(workoutName).addExercise(BCP);
					WorkoutResult(getWorkout(workoutName).getExercise(BCP));
				}
				break;
				case 2:
				{
					std::string BS = "Barbell Squat";
					addWorkout(workoutName);
					getWorkout(workoutName).addExercise(BS);
					WorkoutResult(getWorkout(workoutName).getExercise(BS));
				}
				break;
				case 3:
				{
					std::string BR = "Barbell Row";
					addWorkout(workoutName);
					getWorkout(workoutName).addExercise(BR);
					WorkoutResult(getWorkout(workoutName).getExercise(BR));
				}
				break;
				case 4:
				{
					running2 = false;
				}
				break;
				default:
					WorkoutMenu();
					break;
				}
			}
			else
			{
				std::cout << "Enter 1, 2, 3 or 4." << std::endl;
				goto Menu2;
			}
		}
	} while (running2);

}

std::string app::WorkoutOptions(std::string& Winput)
{
	std::cout << "What would you like to add? " << std::endl;
	std::cout << "1. Barbell Chest Press." << std::endl;
	std::cout << "2. Barbell Squat." << std::endl;
	std::cout << "3. Barbell Row" << std::endl;
	std::cout << "4. Exit" << std::endl;
	std::cin >> Winput;

	return Winput;
}

void app::WorkoutResult(Exercise& exercise)
{
	exercise.Print();
	int i_set = sets(exercise);
	std::vector<Set>& sets = exercise.getSets();
	for (Set& set : sets)
	{
		reps(i_set, set);
		std::vector<Rep>& reps = set.getReps();
		DisplayWorkoutResult(exercise, set, reps);
	}
}

void app::DisplayWorkoutResult(Exercise& exercise, Set& set, std::vector<Rep>& reps)
{
	exercise.Print();
	for (Rep& rep : reps)
	{
		set.Print();
		rep.Print();
	}
}

int app::reps(int sets, Set& obj)
{
	bool running = true;
	std::string inputR{};	std::string inputW{};
	int reps;
	int weight;
	bool b_reps = false;
	bool b_weight = false;
	do
	{
		std::cout << "Enter the reps you did for set " << obj.getId() << ": " << std::endl;
		std::cin >> inputR;
		std::stringstream ssR{ inputR };
		if (ssR >> reps)
		{
			std::cout << "You entered " << reps << std::endl;
			b_reps = true;
		}
		else
		{
			std::cout << "Enter a valid number." << std::endl;
		}
		std::cout << "Enter the weight you did for set " << obj.getId() << ": " << std::endl;
		std::cin >> inputW;
		std::stringstream ssW{ inputW };
		if (ssW >> weight)
		{
			std::cout << "You entered " << reps << std::endl;
			b_weight = true;
		}
		else
		{
			std::cout << "Enter a valid number." << std::endl;
		}

		if (b_weight && b_reps)
		{
			obj.addRep(weight, reps);
		}
		running = false;
		return reps;
	} while (running);

}

int app::sets(Exercise& obj)
{
	bool running = true;
	std::string input{};
	int sets{};
	do
	{
		std::cout << "Enter the sets you did for this exercise: " << std::endl;
		std::cin >> input;
		std::stringstream ss{ input };
		if (ss >> sets)
		{
			std::cout << "You entered " << sets << std::endl;
			for (int i = 1; i <= sets; i++)
			{
				obj.addSet(i);
			}
			running = false;
		}
		else
		{
			std::cout << "Enter a valid number." << std::endl;
		}
	} while (running);
	return sets;
}

std::string app::CalorieMenu(std::string& calories, int& valueCalories)
{
	bool runningChoice{};
	int choice{};
	std::string s_choice{};
	menuChoice:
	do
	{
		std::cout << "Would you like to add a meal today or another day? 1 / 2" << std::endl;
		std::cin >> s_choice;

		std::stringstream ss_Choice{ s_choice };

		if (ss_Choice >> choice)
		{
			if (choice == 1)
			{
				std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
				double valueCaloriesToday{};
				std::string caloriesToday{};
				bool runningToday{ true };
				std::cout << "Add the calories you've consumed today: " << std::endl;
				std::cin >> caloriesToday;

				std::stringstream ssToday{ caloriesToday };
				do {
					if (ssToday >> valueCaloriesToday)
					{
						std::cout << "You entered: " << valueCaloriesToday << std::endl;
						addDate(now);
						getDateObj(now).AddMeal(valueCaloriesToday);
						getDateObj(now).PrintDay();


						return caloriesToday;
					}
					else
					{
						std::cout << "Enter a valid number for your calories." << std::endl;
						break;
					}
				} while (runningToday);
			}
			else if (choice == 2)
			{
				goto menuOtherDay;
			}
			else
			{
				std::cout << "Enter a 1 or 2" << std::endl;
				goto menuChoice;
			}
		}
	} while (runningChoice);

	menuOtherDay:

	bool runningC = true;
	bool runningD = true;
	bool b_Date = false;
	bool b_calorie = false;
	std::string s_Date{};
	std::tm tm = {};
	do {
		std::cout << "On which Date did you have this meal? YYYY-MM-DD format" << std::endl;
		std::cin >> s_Date;

		std::stringstream ssDate{ s_Date };
		ssDate >> std::get_time(&tm, "%Y-%m-%d");

		if (ssDate.fail())
		{
			std::cout << "Enter a valid format for your date." << std::endl;
			goto menuOtherDay;
		}
		else
		{
			std::time_t time_t_value = std::mktime(&tm);
			p_tp = std::chrono::system_clock::from_time_t(time_t_value);
			std::cout << "You entered: " << std::chrono::system_clock::time_point(p_tp) << std::endl;
			b_Date = true;
			runningD = false;
		}

		caloriesInput:

		std::cout << "Add the calories you've consumed: " << std::endl;
		std::cin >> calories;

		std::stringstream ssCalories{ calories };

		if (ssCalories >> valueCalories)
		{
			std::cout << "You entered: " << valueCalories << std::endl;
			b_calorie = true;
			runningC = false;
		}
		else
		{
			std::cout << "Enter a valid number for your calories." << std::endl;
			goto caloriesInput;
		}

		if (b_Date && b_calorie)
		{
			addDate(p_tp);
			getDateObj(p_tp).AddMeal(valueCalories);
			getDateObj(p_tp).PrintDay();
		}
	} while (runningC && runningD);
	return calories;
}

std::string app::WeightMenu(std::string& weight, double& valueWeight)
{
	std::cout << "Add your weight: " << std::endl;
	std::cin >> weight;

	std::stringstream ssWeight{ weight };

	if (ssWeight >> valueWeight)
	{
		std::cout << "You entered: " << valueWeight << std::endl;
	}
	else
	{
		std::cout << "Enter a valid number for your weight." << std::endl;
		WeightMenu(weight, valueWeight);
	}
	return weight;
}

void app::DisplayWorkout(Workout& workout)
{
	workout.Print();
}

void app::DisplayWorkouts()
{
	Print();
}

void app::DisplayCalories(std::vector<Date>& dates)
{
	for (int i = 0; i < dates.size(); i++)
	{
		dates.at(i).PrintDay();
		dates.at(i).Print();
	}
}