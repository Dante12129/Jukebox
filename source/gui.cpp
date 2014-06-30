#include "include\gui.hpp"

#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

namespace jb
{
    Gui::Gui() : main_window(sfg::Window::Create()), main_box(sfg::Box::Create(sfg::Box::Orientation::VERTICAL, 5)),
        play_button(sfg::Button::Create("Play")), pause_button(sfg::Button::Create("Pause")), stop_button(sfg::Button::Create("Stop")), button_box(sfg::Box::Create()),
        song_options(sfg::ComboBox::Create()), song_progress(sfg::ProgressBar::Create())
    {        
        button_box->Pack(play_button);
        button_box->Pack(pause_button);
        button_box->Pack(stop_button);

        main_box->Pack(button_box);
        main_box->Pack(song_options);
        main_box->Pack(song_progress);

        main_window->SetTitle("Jukebox");
        main_window->SetRequisition({320, 50});
        main_window->Add(main_box);

        desktop.Add(main_window);
    }

    void Gui::handleEvents(const sf::Event& event)
    {
        desktop.HandleEvent(event);
    }
    void Gui::handleLogic(const sf::Time& time)
    {
        desktop.Update(time.asSeconds());

        if(song_options->GetSelectedText() != last_selection)
        {
            play_button->GetSignal(sfg::Button::OnLeftClick)();
            last_selection = song_options->GetSelectedText();
        }
    }
    void Gui::handleRender(sf::RenderWindow& window)
    {
        sfgui.Display(window);
    }

    void Gui::addSong(const std::string& name)
    {
        song_options->AppendItem(name);
    }
    void Gui::addSongs(const std::vector<std::string>& names)
    {
        for(const auto& song_name : names)
        {
            addSong(song_name);
        }
    }

    void Gui::setSong(sfg::ComboBox::IndexType index)
    {
        song_options->SelectItem(index);
    }
    std::string Gui::getSong() const
    {
        return std::move(song_options->GetSelectedText());
    }

    void Gui::setProgress(float percent)
    {
        song_progress->SetFraction(percent);
    }

    void Gui::setCallbacks(std::function<void()> playfunc, std::function<void()> pausefunc, std::function<void()> stopfunc)
    {
        play_button->GetSignal(sfg::Button::OnLeftClick).Connect(playfunc);
        pause_button->GetSignal(sfg::Button::OnLeftClick).Connect(pausefunc);
        stop_button->GetSignal(sfg::Button::OnLeftClick).Connect(stopfunc);
    }
}
