#include <sentinel/application.hpp>
#include <sentinel/logger.hpp>

int main() {
    sentinel::Logger::init();

    sentinel::Application app;

    app.run();

    return 0;
}
