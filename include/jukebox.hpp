#ifndef JUKEBOX_HPP
#define JUKEBOX_HPP

#include <map>
#include <memory>
#include <string>
#include <vector>

#include <SFML/Audio/Music.hpp>

namespace jb
{
    class Jukebox
    {
        public:
            Jukebox(const std::vector<std::string>& names);

            void playSong(const std::string& name);
            unsigned playRandom();

            void pause();
            void stop();

            float getCurrentElapsed() const;
            float getCurrentTotal() const;
            const std::string& getCurrentName() const;

        private:
            std::map<std::string, std::unique_ptr<sf::Music>> songs;

            std::string current_song;
    };
}

#endif // JUKEBOX_HPP
