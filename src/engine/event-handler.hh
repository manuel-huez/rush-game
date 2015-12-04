#pragma once

#include "engine.hh"

namespace Engine
{

    class EventHandler
    {
    public:
        EventHandler(Engine& engine);

        void handle();
    private:
        Engine& engine_;
    }
}
