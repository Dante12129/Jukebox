#include <iostream>

#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "include/gui.hpp"
#include "include/jukebox.hpp"
#include "include/loader.hpp"

int main()
{
    //The main window for the program. The Gl states are reset so that SFGUI can render properly.
    sf::RenderWindow window({640, 480}, "Jukebox");
    window.setKeyRepeatEnabled(false); window.setVerticalSyncEnabled(true); window.resetGLStates();

    //The gui
    jb::Gui gui;

    //Load the songs
    jb::Loader song_directory("songs");
    gui.addSongs(song_directory.getSongs());

    //The jukebox manages the songs
    jb::Jukebox jukebox(song_directory.getSongs());
    gui.setSong(jukebox.playRandom());

    //Register the stop and play functionality
    gui.setCallbacks([&]{ if(gui.getSong() != jukebox.getCurrentName()) jukebox.stop(); jukebox.playSong(gui.getSong()); }, [&]{ jukebox.pause(); }, [&]{ jukebox.stop(); gui.setProgress(0); });

    //Variables for main loop
    bool running = true;
    sf::Clock frame_timer;
    sf::Time delta;

    //Main loop
    while(running)
    {
        //Calculate the frame delta
        delta = frame_timer.getElapsedTime();
        frame_timer.restart();

        //Event handling
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                running = false;
            gui.handleEvents(event);
        }

        //Logic
        gui.handleLogic(delta);
        gui.setProgress(jukebox.getCurrentElapsed() / jukebox.getCurrentTotal());

        //Rendering
        window.clear();
        gui.handleRender(window);
        window.display();
    }

    return 0;
}

