#include "first_app.hpp"

#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <locale>

int main()
{
    setlocale(LC_ALL,"");
    lve::FirstApp app{};

    try
    {
        app.run();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}