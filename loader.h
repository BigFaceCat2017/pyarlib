/* Copyright 2011 Pyarelal Knowles, under GNU LGPL (see LICENCE.txt) */


#ifndef LOADER_FACTORY_H
#define LOADER_FACTORY_H

#include <iostream>

#include "fileutil.h"
#include "findfile.h"

template <class T>
class Loader
{
public:
	typedef bool (*LoaderFunction)(T&, const char*);
private:
	typedef std::map<std::string, LoaderFunction> HandlerMap;
	static HandlerMap* handlers;
	static bool registerCastLoader(const char* extension, LoaderFunction func)
	{
		if (func == NULL)
		{
			std::cout << "Error: null handler function for " << extension << std::endl;
			return false;
		}
		if (handlers == NULL)
			handlers = new HandlerMap();
		if (handlers->find(extension) != handlers->end())
			return false;
		(*handlers)[extension] = func;
		return true;
	}
public:
	virtual bool load(const char* filename)
	{
		std::string fname(filename);
		
		//search for file if it doesn't exist
		if (!fileExists(filename))
		{
			std::string result = FileFinder::find(filename);
			if (result.size())
			{
				//std::cout << "Found " << filename << " at " << result << std::endl;
				fname = result;
			}
		}
		
		size_t lp = fname.find_last_of(".");
		if ((int)lp < 0)
		{
			std::cout << "Error: " << filename << " has no extension" << std::endl;
			return false;
		}
		std::string extension = fname.substr(lp);
		typename HandlerMap::iterator found;
		if (handlers)
			found = handlers->find(extension);
		if (handlers && found != handlers->end())
		{
			T* instance = dynamic_cast<T*>(this);
			return found->second(*instance, fname.c_str());
		}
		else
		{
			std::cout << "Error: No handlers for " << extension << std::endl;
			return false;
		}
	}
	static bool registerLoader(const char* extension, LoaderFunction func)
	{
		return registerCastLoader(extension, func);
	}
};

template <class T> typename Loader<T>::HandlerMap* Loader<T>::handlers = NULL;

#endif
