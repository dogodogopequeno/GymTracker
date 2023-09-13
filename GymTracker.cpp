
#include "Header.h"
#include "app.h"

#pragma warning(disable : 4996)

void saveData(std::ofstream& OFS, app& application);
void loadData(std::ifstream& IFS, app& application);
bool IsEmpty(std::ifstream& IFS);


int main()
{

	app App;

	std::string filename = App.getFilename();

	std::ifstream ifs(filename);

	if (IsEmpty(ifs))
	{
		std::cout << std::endl;
	}
	else
	{
		loadData(ifs, App);
	}


	ifs.close();

	App.Run();

	std::ofstream ofs(filename);

	saveData(ofs, App);

	ofs.close();

	return 0;

}

void saveData(std::ofstream& OFS, app& application)
{
	boost::archive::text_oarchive ar(OFS);
	ar& application;

	application.SaveData(OFS);
}

//void loadData(std::ifstream& IFS, app& application)
//{
//	boost::archive::text_iarchive ar(IFS);
//	ar& application;
//
//	application.LoadData(IFS);
//}

bool IsEmpty(std::ifstream& IFS)
{
	// Check if the file is open and not empty
	if (IFS.is_open() && IFS.peek() == std::ifstream::traits_type::eof()) 
	{
		//std::cout << "File is empty." << std::endl;
		return true;
	}
	else 
	{
		//std::cout << "File is not empty." << std::endl;
		return false;
	}
}

void loadData(std::ifstream& ifs, app& application)
{
	try {
		boost::archive::text_iarchive ar(ifs);
		ar& application;

		application.LoadData(ifs);
	}
	catch (const std::exception& e) {
		//std::cerr << "error loading data: " << e.what() << std::endl;
		std::cout << std::endl;
	}
}
