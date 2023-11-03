#ifndef FORGEENGINE_INPUTSYSTEM_H
#define FORGEENGINE_INPUTSYSTEM_H

#include "SFML/Window/Event.hpp"


class Event {
public:
    explicit Event(sf::Event::EventType eventType);

    sf::Event::EventType GetEventType();

    Event &operator=(const Event &other) = default;

private:
    sf::Event::EventType eventType;
};

typedef void (*EventCallback)(const Event&);

class InputSystem {
public:
    InputSystem();

    ~InputSystem();

    void ReceiveEvent(Event polledEvent);
    void RegisterCallback(EventCallback new_callback) {
        this->callback = new_callback;
    }

    Event *PollEvent();

private:
    Event *receivedEvent;
    EventCallback callback = nullptr;
};


#endif //FORGEENGINE_INPUTSYSTEM_H
