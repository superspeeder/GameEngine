#include <stdexcept>
#include <eng/Engine.h>

void run()
{
    
}

int main()
{
    try
    {
        eng::init();
        run();
        eng::terminate();
    } catch (std::exception& e)
    {
        spdlog::critical("Application crashed: {}", e.what());
    }

}
