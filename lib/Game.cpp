#include "Game.h"
#include <input/InputSystem.h>
#include <iostream>
#include <utility>
#include <SFML/Graphics.hpp>


Game::Game(std::string windowTitle) {
    this->windowTitle = std::move(windowTitle);
    inputSystem = new InputSystem();
}

Game::~Game() {
    delete inputSystem;
}


void Game::Run() {
    sf::RenderWindow window(sf::VideoMode(800, 600), this->windowTitle);

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed: {
                    window.close();
                }
                default:
                    inputSystem->ReceiveEvent(Event(event.type));
            }
        }

        window.clear();
        window.display();
    }
}

InputSystem *Game::GetInputSystem() {
    return inputSystem;
}

extern "C" {

__declspec(dllexport) void game_destroy(void *game) {
    if (game == nullptr) {
        std::cerr << "Error calling destroy_game nullptr game" << std::endl;
        return;
    }

    delete static_cast<Game *>(game);
}

__declspec(dllexport) void *game_create(const char *windowTitle) {
    if (windowTitle == nullptr) {
        std::cerr << "Error calling create_game nullptr windowTitle" << std::endl;
        return nullptr;
    }
    return new Game(windowTitle);
}

__declspec(dllexport) void game_run(void *game) {
    if (game == nullptr) {
        std::cerr << "Error calling run_game nullptr game" << std::endl;
        return;
    }
    static_cast<Game *>(game)->Run();
}

__declspec(dllexport) void *game_get_inputsystem(void *game) {
    if (game == nullptr) {
        std::cerr << "Error calling get_inputsystem nullptr game" << std::endl;
        return nullptr;
    }

    return static_cast<Game *>(game)->GetInputSystem();
}
}
