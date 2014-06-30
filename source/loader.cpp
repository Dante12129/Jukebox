#include "include/loader.hpp"

namespace jb
{
    Loader::Loader(const std::string& directory) : dir(directory)
    {
        if(boost::filesystem::exists(dir))
        {
            if(boost::filesystem::is_directory(dir))
            {
                for(auto song = boost::filesystem::directory_iterator(dir); song != boost::filesystem::directory_iterator(); ++song)
                {
                    files.push_back(song->path().string<std::string>());
                }
            }
        }
    }

    boost::filesystem::path Loader::getDirectory() const
    {
        return dir;
    }
    const std::vector<std::string>& Loader::getSongs()
    {
        return files;
    }
}
