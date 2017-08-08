#ifndef SEEKER_HPP
#define SEEKER_HPP
//
// Since seeker won't be that big, it will be define in the header file.
//
#include <iostream>
#include <boost/filesystem.hpp>
#include "quintifio.hpp"

///
/// The seeker class is tasked with searching for all
/// files/folders.
///
class seeker
{
public:
	/// @brief ctor
	seeker(const char* loc) 
	{
		starting_location = boost::filesystem::directory_entry(loc);
	}

	/// @brief Returns a @TODO: boost::graph??
	void get_tree()
	{
		/// Nothing for now
	}

	/// @brief Checks if the starting point is a folder
	bool valid_start() 
	{ 
		return boost::filesystem::is_directory(starting_location); 
	}

	/// @brief Print the found tree structure
	void print_find()
	{
		// TODO: Maybe another method that is faster, or after the tree is created

		/// TEMP
		std::cout << starting_location.path() << std::endl;

		/// Create an iterator and traverse through each entry
		auto entry_iterator = ///< Has to outside to be able to access level()
			boost::filesystem::recursive_directory_iterator(starting_location.path()); 

		for (const auto &entry : entry_iterator)
		{/// For every entry, print the name
			for (size_t i = 0; i < entry_iterator.level() + 1; i++)
			{
				std::cout << "  ";
			}
			std::cout << entry.path().filename() << std::endl;
		} /// end for
	}

	/// @brief Return the starting location
	boost::filesystem::directory_entry get_start() const
	{
		return this->starting_location;
	}

private:
	boost::filesystem::directory_entry starting_location; ///< Starting foler location
};


#endif // SEEKER_HPP
