#include "fetch.h"
#include "color.h"

string exec(string command)
{
    char buffer[128];
    string result = "";
    FILE *pipe = popen(command.c_str(), "r");
    if (!pipe)
    {
        throw runtime_error("popen failed: \"" + command + "\"");
    }
    while (!feof(pipe))
    {
        if (fgets(buffer, 128, pipe) != NULL)
            result += buffer;
    }

    pclose(pipe);
    return result;
}

string getColor(string line)
{
    string color;
    if (line.substr(0, line.find(" ")) == "RED")
    {
        color = RED;
    }
    else if (line.substr(0, line.find(" ")) == "BLACK")
    {
        color = BLACK;
    }
    else if (line.substr(0, line.find(" ")) == "GREEN")
    {
        color = GREEN;
    }
    else if (line.substr(0, line.find(" ")) == "YELLOW")
    {
        color = YELLOW;
    }
    else if (line.substr(0, line.find(" ")) == "BLUE")
    {
        color = BLUE;
    }
    else if (line.substr(0, line.find(" ")) == "MAGENTA")
    {
        color = MAGENTA;
    }
    else if (line.substr(0, line.find(" ")) == "CYAN")
    {
        color = CYAN;
    }
    else if (line.substr(0, line.find(" ")) == "WHITE")
    {
        color = WHITE;
    }
    else if (line.substr(0, line.find(" ")) == "BBLACK")
    {
        color = BBLACK;
    }
    else if (line.substr(0, line.find(" ")) == "BGRAY")
    {
        color = BGRAY;
    }
    else if (line.substr(0, line.find(" ")) == "BRED")
    {
        color = BRED;
    }
    else if (line.substr(0, line.find(" ")) == "BGREEN")
    {
        color = BGREEN;
    }
    else if (line.substr(0, line.find(" ")) == "BYELLOW")
    {
        color = BYELLOW;
    }
    else if (line.substr(0, line.find(" ")) == "BBLUE")
    {
        color = BBLUE;
    }
    else if (line.substr(0, line.find(" ")) == "BMAGENTA")
    {
        color = BMAGENTA;
    }
    else if (line.substr(0, line.find(" ")) == "BCYAN")
    {
        color = BCYAN;
    }
    else if (line.substr(0, line.find(" ")) == "BWHITE")
    {
        color = BWHITE;
    }

    return color;
}

static void test_exec() {
    string result = exec("echo \"hello, world\""s);
    expect("hello, world\n"s, result, "exec() returns"s);
}

static void test_Path() {
    auto dir = Path::of("/etc"s);
    expect(false, dir.is_regular_fie(), "[ -f dir ]");
    expect(true,  dir.is_directory(),   "[ -d dir ]");

    auto reg = Path::of("/etc/os-release"s);
    expect(true,  reg.is_regular_fie(), "[ -f reg ]");
    expect(false, reg.is_directory(),   "[ -d reg ]");
}

void test_util() {
    test_exec();
    test_Path();
}
