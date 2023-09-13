#include "app.h"

app::app()
{
}

app::app(std::vector<Workout> Workouts, std::vector<Date> Dates) : workouts(Workouts), dates(Dates) {}

app::~app() {}

std::string& app::getFilename()
{
	return filename;
}

void app::SaveData(std::ofstream& OFS)
{
	//boost::archive::text_oarchive ar(OFS);
	//ar& workouts;
	//for (Workout& workout : workouts)
	//{
	//	
	//	//ar& workout;
	//	workout.SaveExercises(OFS);
	//}

	////for (Date& date : dates)
	////{
	////	ar& date;
	////}


}

void app::LoadData(std::ifstream& IFS)
{
	//boost::archive::text_iarchive ar(IFS);
	//ar& workouts;
	//for (Workout& workout : workouts)
	//{
	//	//ar& workout;
	//	workout.LoadExercises(IFS);
	//}

	//ar& dates;
	//for (Date& date : dates)
	//{
	//	ar& date;
	//}


}

std::ostream& operator<<(std::ostream& os, const app obj)
{
	return os;
}

void app::Print()
{
	for (Workout& workout : workouts)
	{
		std::cout << "Workout: " << workout.getName() << '\n' << std::endl;
		workout.Print();
	}
}

std::vector<Workout>& app::getWorkouts()
{
	return workouts;
}

Workout& app::getWorkout(std::string& WorkoutName)
{
	for (Workout& workout : workouts)
	{
		if (WorkoutName == workout.getName())
		{
			return workout;
		}
	}
	std::cout << "Didn't find workout" << std::endl;
}

void app::addWorkout(Workout& workout)
{
	workouts.push_back(workout);
}

void app::addWorkout(std::string name)
{
	workouts.push_back(Workout(name));
}

void app::addDate(Date& date)
{
	dates.push_back(date);
}


void app::addDate(std::chrono::system_clock::time_point timePoint)
{
	dates.push_back(Date(timePoint));
}

Date& app::getDateObj(int ID)
{
	for (Date& date : dates)
	{
		if (date.day == 1 /*replace with day month year*/)
		{
			return date;
		}
	}
	throw std::runtime_error("No valid date found");  // Throw an exception
	std::cout << "date not found" << std::endl;

}

Date& app::getDateObj(std::chrono::system_clock::time_point timePoint)
{
	for (Date& date : dates)
	{
		if (date.getDateTP() == timePoint)
		{
			return date;
		}
	}
	throw std::runtime_error("No valid date found");  // Throw an exception
	std::cout << "date not found" << std::endl;
}

