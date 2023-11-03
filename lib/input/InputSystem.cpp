#include <iostream>
#include "InputSystem.h"

InputSystem::InputSystem() = default;

InputSystem::~InputSystem() {
    delete receivedEvent;

}

Event *InputSystem::PollEvent() {
    return receivedEvent;
}

void InputSystem::ReceiveEvent(Event polledEvent) {
    std::cout << "InputSystem::ReceiveEvent Event type: " << polledEvent.GetEventType() << std::endl;
    if (callback) callback(polledEvent);
    std::cout << "HandledCallback" << std::endl;
}


Event::Event(sf::Event::EventType eventType) {
    this->eventType = eventType;
}


sf::Event::EventType Event::GetEventType() {
    return eventType;
}


extern "C" {
__declspec(dllexport) void *inputsystem_pollevent(void *inputSystem) {
    if (inputSystem == nullptr) {
        std::cerr << "Error calling pollevent_inputsystem inputSystem null" << std::endl;
        return nullptr;
    }

    return static_cast<InputSystem *>(inputSystem)->PollEvent();
}

__declspec(dllexport) void inputsystem_registercallback(void *inputSystem, EventCallback callback) {
    if (inputSystem == nullptr) {
        std::cerr << "Error calling game_registercallback game null" << std::endl;
        return;
    }
    if(callback == nullptr) {
        std::cerr << "Error calling game_registercallback callback null" << std::endl;
        return;
    }

    std::cout << "InputSystem::RegisterCallback" << std::endl;

    static_cast<InputSystem *>( inputSystem)->RegisterCallback(callback);
}

__declspec(dllexport) int event_geteventtype(void *event) {
    if (event == nullptr) {
        return -1; // Assuming -1 is not a valid EventType
    }
    return static_cast<Event *>(event)->GetEventType();
}

} //extern "C"