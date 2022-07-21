#include <iostream>
#include <stdexcept>
#include <cstdlib>

#include "application.h"


int main() {
    try {
        Application application;
        application.run();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
