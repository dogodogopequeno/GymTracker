#include "Header.h"
#include "Meal.h"
#pragma once
class Date
{
	public:
	int date {};
	std::vector<Meal> meals{};
	std::chrono::system_clock::time_point now;
	std::chrono::system_clock::time_point timePoint_{};
	std::chrono::year_month_day ymd{};
	int year {};
	int month{};
	int day{};

public:
	Date();
	Date(int Year, int Month, int Day);
	Date(Date&& other) noexcept;
	Date(const Date& other);
	Date(std::chrono::system_clock::time_point timePoint);
	void Print();
	void PrintDay();
	void AddMeal(double calories);
	auto getID();
	std::chrono::system_clock::time_point getDateTP();
	friend std::ostream& operator<<(std::ostream& os, const Meal obj);
	friend class boost::serialization::access;

	template<class Archive>
	void serialize(Archive& ar, const unsigned int version)
	{
		std::cout << "Serializing Date: year=" << year << " month=" << month << " day=" << day << std::endl;

		ar& meals;
		ar& year;
		ar& month;
		ar& day;
	}
};

