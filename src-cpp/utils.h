#pragma once

#include <list>
#include <string>
#include <map>

namespace utils {
	class Storage {
	public:
	static std::list<std::pair<std::string,std::string>> ConfigurationOptions;
	static std::list<std::pair<std::string,std::string>> MetadataList;
	void reset() {
		ConfigurationOptions.clear();
	}
	
	};
}