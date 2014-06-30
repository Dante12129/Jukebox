#ifndef GUI_HPP
#define GUI_HPP

#include <functional>
#include <string>
#include <vector>

#include <SFGUI/SFGUI.hpp>

namespace sf { class Event; class Time; class RenderWindow; }

namespace jb
{
    class Gui
    {
        public:
            Gui();

            void handleEvents(const sf::Event& event);
            void handleLogic(const sf::Time& time);
            void handleRender(sf::RenderWindow& window);

            void addSong(const std::string& name);
            void addSongs(const std::vector<std::string>& names);

            void setSong(sfg::ComboBox::IndexType index = 0);
            std::string getSong() const;

            void setProgress(float percent);

            void setCallbacks(std::function<void()> playfunc, std::function<void()> pausefunc, std::function<void()> stopfunc);

        private:
            sfg::SFGUI sfgui;
            sfg::Desktop desktop;

            sfg::Window::Ptr main_window;
            sfg::Box::Ptr main_box;

            sfg::Button::Ptr play_button;
            sfg::Button::Ptr pause_button;
            sfg::Button::Ptr stop_button;
            sfg::Box::Ptr button_box;

            sfg::ComboBox::Ptr song_options;
            sfg::ProgressBar::Ptr song_progress;

            std::string last_selection;
    };
}

#endif // GUI_HPP
