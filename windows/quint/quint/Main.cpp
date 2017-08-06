///
/// Use this website as reference:
///		http://www.boost.org/doc/libs/1_64_0/libs/filesystem/doc/reference.html
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
	if (!is_directory(start_directory.status()))
	{
		std::cout << argv[argc - 1] <<  " is not a valid directory" << std::endl;
		return 1;
	}
	
	/// TEMP
	std::cout << start_directory.path() << std::endl;

	/// Create an iterator and traverse through each entry
	auto entry_iterator = recursive_directory_iterator(start_directory.path()); /// Has to outside to be able to access level()

	for (const auto &entry : entry_iterator)
	{/// For every entry, print the lvl and name

		// For looks
		std::cout << "|";

		for (size_t i = 0; i < entry_iterator.level() + 1; i++)
		{
			std::cout << "--";
		}
		std::cout << entry.path().filename();

		// Can also check if the entry is a file
		if (is_regular_file(entry.status()))
		{
			std::cout << "\t\t\t-->  is a file" << std::endl;
		}
		// Or check if the entry is a directory
		if (is_directory(entry.status()))
		{
			std::cout << "\t\t\t-->  is a file" << std::endl;
		}
	}

	// TODO: Create a data structure to hold the data
	// Structure should hold:
	// + The level <- Might not be necessary if saved correctly in graph
	// + The type (directory or file)
	// + **Color, depending if file, directory, and extension
	// + Maybe other information depending on how complex we need this to be

	// TODO: Save all data structure entry in a graph

	// TODO: Traverse the graph 

	return 0;
}