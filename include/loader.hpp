#ifndef LOADER_HPP
#define LOADER_HPP

#include <string>
#include <vector>

#include <boost/filesystem.hpp>

namespace jb
{
    class Loader
    {
        public:
            Loader(const std::string& directory);

            boost::filesystem::path getDirectory() const;
            const std::vector<std::string>& getSongs();

        private:
            boost::filesystem::path dir;

            std::vector<std::string> files;
    };
}

#endif // LOADER_HPP
