// queryMovieInfo.cpp : Defines the entry point for the console application.
//

#include "queryMovieInfo.hpp"


int main()
{
	// Do a Google search for 'Kurt Russell' and output what comes back
	std::string output = exec("curl -e http://www.my-aja-site.com \"http://ajax.googleapis.com/ajax/services/search/web?v=1.0&q=Kurt%20Russell\"");
	std::cout << output << std::endl;
    return 0;
}

// Runs a terminal command and returns the output
std::string exec(const char* cmd) {
    std::shared_ptr<FILE> pipe(_popen(cmd, "r"), _pclose);
    if (!pipe) return "ERROR";
    char buffer[128];
    std::string result = "";
    while (!feof(pipe.get())) {
        if (fgets(buffer, 128, pipe.get()) != NULL)
            result += buffer;
    }
    return result;
}
