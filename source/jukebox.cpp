#include "include\jukebox.hpp"

#include <exception>
#include <iostream>
#include <utility>

#include <Dte/Utilities.hpp>

#include "include/randomgenerator.hpp"

namespace jb
{
    Jukebox::Jukebox(const std::vector<std::string>& names)
    {
        for(const auto& name : names)
        {
            auto new_song = dte::make_unique<sf::Music>();
            if(!new_song->openFromFile(name))
                throw std::runtime_error("Couldn't load a song");

            songs.insert(std::make_pair(name, std::move(new_song)));
        }
    }

    void Jukebox::playSong(const std::string& name)
    {
        current_song = name;
        songs[current_song]->play();
    }
    unsigned Jukebox::playRandom()
    {
        RandomGenerator gen;
        int choice = gen.generateInt(0, songs.size() - 1);

        int i = 0;
        for(const auto& song : songs)
        {
            if(i == choice)
            {
                playSong(song.first);
                break;
            }
            ++i;
        }

        return choice;
    }

    void Jukebox::pause()
    {
        if(!current_song.empty())
            songs[current_song]->pause();
    }

    void Jukebox::stop()
    {
        if(!current_song.empty())
            songs[current_song]->stop();
    }

    float Jukebox::getCurrentElapsed() const
    {
        return songs.at(current_song)->getPlayingOffset().asSeconds();
    }
    float Jukebox::getCurrentTotal() const
    {
        return songs.at(current_song)->getDuration().asSeconds();
    }
    const std::string& Jukebox::getCurrentName() const
    {
        return current_song;
    }
}
