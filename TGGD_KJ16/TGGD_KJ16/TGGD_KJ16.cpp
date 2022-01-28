#include "Terminal.h"
#include "Menu.h"

int main()
{
    bool done = false;
    while (!done)
    {
        Menu::Clear();
        Menu::Add("Quit", [&done]() { done = true; });
        Menu::Prompt(
            []() 
            {
                Terminal::WriteLine();
                Terminal::WriteLine("<TODO: Make Better Game Title>");
            });
    }
}
