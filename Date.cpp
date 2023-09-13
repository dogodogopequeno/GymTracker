
#define _CRT_SECURE_NO_WARNINGS

#include "Date.h"

Date::Date() 
{
	timePoint_ = std::chrono::system_clock::now();

	// Convert the system clock time_point to time_t
	std::time_t time = std::chrono::system_clock::to_time_t(timePoint_);

	// Convert time_t to std::tm
	std::tm tm = *std::localtime(&time);

	// Extract the year, month, and day components
	std::chrono::year year = std::chrono::year{ tm.tm_year + 1900 }; // Adjust for tm's year offset
	std::chrono::month month = std::chrono::month{ static_cast<unsigned>(tm.tm_mon + 1) }; // Adjust for tm's month offset
	std::chrono::day day = std::chrono::day{ static_cast<unsigned>(tm.tm_mday) };

	// Create a year_month_day object
	ymd = std::chrono::year_month_day(year, month, day);


}

Date::Date(std::chrono::system_clock::time_point timePoint) : timePoint_(timePoint) 
{
	// Convert the time point to std::chrono::year_month_day
	auto t_ymd = std::chrono::year_month_day{ std::chrono::floor<std::chrono::days>(timePoint_) };

	ymd = t_ymd;

	// Extract the year, month, and day components
	year = static_cast<int>(t_ymd.year());
	month = static_cast<unsigned>(t_ymd.month());
	day = static_cast<unsigned>(t_ymd.day());
}

Date::Date(int Year, int Month, int Day) : year(Year), month(Month), day(Day)
{
	ymd = std::chrono::year_month_day(std::chrono::year(year), std::chrono::month(month), std::chrono::day(day));

	// Convert to a system_clock::time_point

}


Date::Date(Date&& other) noexcept : timePoint_(std::move((other.timePoint_))), meals(std::move(other.meals)), day(std::move(other.day)), month(std::move(other.month)), year(std::move(other.year))
{
}

Date::Date(const Date& other) : timePoint_((other.timePoint_)), meals(other.meals), day(other.day), month(other.month), year(other.year)
{
}

void Date::Print()
{
	for (Meal& meal : meals)
	{
		meal.Print();
	}
}

void Date::PrintDay()
{
	//if (this->getDateID() != 1)
	//{
	//	std::cout << "not this time" << std::endl;
	//}
	//else
	//{
	//	std::cout << "finally" << std::endl;

		// Print the time_t value (seconds since epoch)
		std::cout << "Time_t: " << timePoint_ << std::endl;

		// Print the local date
		std::cout << "Date: " << year << "-" << month << "-" << day << std::endl;

}

void Date::AddMeal(double calories)
{
	meals.push_back(Meal(calories));
}

auto Date::getID()
{
	return timePoint_;
}

std::ostream& operator<<(std::ostream& os, const Date obj)
{
	return os;
}

std::chrono::system_clock::time_point Date::getDateTP()
{
	return timePoint_;
}