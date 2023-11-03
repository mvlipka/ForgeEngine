#pragma once

#include <string>
#include <iostream>


class InputSystem;

class Game {
public:
    explicit Game(std::string windowTitle);
    ~Game();

    void Run();

    InputSystem* GetInputSystem();

private:
    InputSystem* inputSystem;
    std::string windowTitle;
};
