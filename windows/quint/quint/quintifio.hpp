#ifndef QUINTIFIO_HPP
#define QUINTIFIO_HPP
//
// A "quintifio" is a way to represent each folder/file or "tree node"
//

// TODO: Add more personality to the quintifio
// Possible options to add:
// + extension or type [folder|file|include statement]
// + color
// + connections?
struct quintifio
{
	const char* name; /// < mostly file or folder name

	/// @brief ctor
	quintifio(const char* n) : name(n)
	{

	}

	/// @brief A way to print the quintifio
	friend std::ostream& operator<< (std::ostream& os, const quintifio quin) 
	{
		os << quin.name;
		return os;
	}
};


#endif // QUINTIFIO_HPP
