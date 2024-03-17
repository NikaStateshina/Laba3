#include <iostream>
#include <string>

// Legacy Printer (Adaptee)
class LegacyPrinter {
public:
    void printnewline(const std::string& text)
    {
        std::cout << "Printing: " << text << std::endl;
    }
};

// Modern Computer (Client)
class ModernComputer {
public:
    void sendCommand(const std::string& command)
    {
        std::cout << "Sending command: " << command
            << std::endl;
    }
};

// Adapter class to make the LegacyPrinter compatible with
// ModernComputer
class PrinterAdapter {
private:
    LegacyPrinter legacyPrinter;

public:
    void sendCommand(const std::string& command)
    {
        // Delete all "a" from command
        // the LegacyPrinter
        std::string newCommand = command;
        std::string to_delete{ "a" };  
        size_t start{ newCommand.find(to_delete) };
        while (start != std::string::npos) 
        {
            newCommand.erase(start, to_delete.length());
            start = newCommand.find(to_delete, start + to_delete.length());
        }
        legacyPrinter.printnewline(newCommand);
    }
};

int main()
{
    ModernComputer computer;
    PrinterAdapter adapter;

    computer.sendCommand("abacadaeaf");
    adapter.sendCommand("abacadaeaf");

    return 0;
}