///
/// Use this website as reference:
///		http://www.boost.org/doc/libs/1_64_0/libs/filesystem/doc/reference.html#class-path
///


#include <iostream>
#include <boost/filesystem.hpp>

using namespace boost::filesystem;

int main(int argc, char** argv)
{
	if (argc < 2)
	{///If no directory was provided, start from the current directory
		std::cout << "Starting from root" << std::endl; // TODO: delete, Have logic to start tree here
		return 0; // TODO: Have a better return statement
	}
	
	// TODO: Maybe allow options in the future, do logic here

	// TODO: Move directory traversal logic to another file
	/// Start with the given directory
	directory_entry start_directory(argv[argc - 1]);
	
	/// Check to see if it is a valid directory
	if (is_directory(start_directory.status()))
	{
		std::cout << "It is a directory!" << std::endl;
	}
	else
	{ 
		std::cout << "It is not a directory!" << std::endl;
		return 1;
	}
	
	/// Create a directory iterator to start traversing
	recursive_directory_iterator file_iterator(start_directory.path());
	/* Learning on recursive directory iterators!*/
	std::cout << "Folder: " << *file_iterator << std::endl;
	std::cout << "level: " << file_iterator.level() << std::endl;

	file_iterator++;

	std::cout << "level: " << *file_iterator << std::endl;

	file_iterator++;

	std::cout << "level: " << *file_iterator << std::endl;

	/// Check to see if it is a valid file/*Learning*/
	if (is_regular_file((*file_iterator).status()))
	{
		std::cout << "It is not a directory!" << std::endl;
	}
	

	return 0;
}