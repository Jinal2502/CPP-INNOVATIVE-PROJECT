#include "MatrixUI.h"
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <random>
#include <iomanip>
#include <vector>
#include <cstdlib>

// ANSI Color Codes for Matrix Red Theme
const std::string MatrixUI::RESET = "\033[0m";
const std::string MatrixUI::BRIGHT_RED = "\033[91m";
const std::string MatrixUI::DARK_RED = "\033[31m";
const std::string MatrixUI::RED_BG = "\033[41m";
const std::string MatrixUI::BRIGHT_WHITE = "\033[97m";
const std::string MatrixUI::DIM_RED = "\033[2;31m";
const std::string MatrixUI::CYAN = "\033[96m";
const std::string MatrixUI::YELLOW = "\033[93m";
const std::string MatrixUI::GREEN = "\033[92m";

// Clear screen with Matrix effect
void MatrixUI::clearScreen() {
    std::cout << "\033[2J\033[H"; // Clear screen and move cursor to top
}

// Print Matrix-style title with glitch effect
void MatrixUI::printMatrixTitle(const std::string& title) {
    std::cout << "\n";
    printMatrixSeparator('█', 60);
    std::cout << "\n";
    
    // Center the title
    int padding = (60 - title.length()) / 2;
    std::cout << BRIGHT_RED;
    for (int i = 0; i < padding; i++) std::cout << " ";
    std::cout << title;
    for (int i = 0; i < padding; i++) std::cout << " ";
    std::cout << "\n";
    
    printMatrixSeparator('█', 60);
    std::cout << RESET << "\n\n";
}

// Print Matrix-style box
void MatrixUI::printMatrixBox(const std::string& title, const std::string& content) {
    std::cout << "\n" << BRIGHT_RED << "╔";
    for (int i = 0; i < 58; i++) std::cout << "═";
    std::cout << "╗\n";
    
    std::cout << "║" << BRIGHT_WHITE << " " << title;
    for (int i = title.length() + 1; i < 59; i++) std::cout << " ";
    std::cout << BRIGHT_RED << " ║\n";
    
    std::cout << "╠";
    for (int i = 0; i < 58; i++) std::cout << "═";
    std::cout << "╣\n";
    
    std::cout << "║" << CYAN << " " << content << RESET;
    for (int i = content.length() + 1; i < 59; i++) std::cout << " ";
    std::cout << BRIGHT_RED << " ║\n";
    
    std::cout << "╚";
    for (int i = 0; i < 58; i++) std::cout << "═";
    std::cout << "╝\n" << RESET << "\n";
}

// Print Matrix separator
void MatrixUI::printMatrixSeparator(char ch, int width) {
    std::cout << BRIGHT_RED;
    for (int i = 0; i < width; i++) {
        std::cout << ch;
    }
    std::cout << RESET;
}

// Animate text with Matrix effect
void MatrixUI::animateMatrixText(const std::string& text, int delay) {
    std::cout << BRIGHT_RED;
    for (char c : text) {
        std::cout << c << std::flush;
        sleep(delay);
    }
    std::cout << RESET << "\n";
}

// Print Matrix rain effect
void MatrixUI::printMatrixRain(int lines) {
    std::cout << DIM_RED;
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < 60; j++) {
            if (getRandom(1, 100) < 5) {
                std::cout << getMatrixChar();
            } else {
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }
    std::cout << RESET;
}

// Print Matrix logo
void MatrixUI::printMatrixLogo() {
    std::cout << "\n";
    std::cout << BRIGHT_RED << "    ██████╗██╗  ██╗██████╗  ██████╗ ███╗   ██╗██╗ ██╗ ██████╗██╗     ██╗███████╗\n";
    std::cout << "   ██╔════╝██║  ██║██╔══██╗██╔═══██╗████╗  ██║██║ ██║██╔════╝██║     ██║██╔════╝\n";
    std::cout << "   ██║     ███████║██████╔╝██║   ██║██╔██╗ ██║██║ ██║██║     ██║     ██║███████╗\n";
    std::cout << "   ██║     ██╔══██║██╔══██╗██║   ██║██║╚██╗██║██║ ██║██║     ██║     ██║╚════██║\n";
    std::cout << "   ╚██████╗██║  ██║██║  ██║╚██████╔╝██║ ╚████║██║ ██║╚██████╗███████╗██║███████║\n";
    std::cout << "    ╚═════╝╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═══╝╚═╝ ╚═╝ ╚═════╝╚══════╝╚═╝╚══════╝\n";
    std::cout << "\n";
    std::cout << CYAN << "           ██╗███╗   ██╗    ████████╗███████╗██╗  ██╗████████╗\n";
    std::cout << "           ██║████╗  ██║    ╚══██╔══╝██╔════╝╚██╗██╔╝╚══██╔══╝\n";
    std::cout << "           ██║██╔██╗ ██║       ██║   █████╗   ╚███╔╝    ██║   \n";
    std::cout << "           ██║██║╚██╗██║       ██║   ██╔══╝   ██╔██╗    ██║   \n";
    std::cout << "           ██║██║ ╚████║       ██║   ███████╗██╔╝ ██╗   ██║   \n";
    std::cout << "           ╚═╝╚═╝  ╚═══╝       ╚═╝   ╚══════╝╚═╝  ╚═╝   ╚═╝   \n";
    std::cout << RESET << "\n";
}

// Press enter to continue with Matrix style
void MatrixUI::pressEnterToContinue() {
    std::cout << "\n" << DIM_RED << "Press Enter to continue..." << RESET;
    std::cin.ignore();
    std::cin.get();
}

// Print Matrix menu
void MatrixUI::printMatrixMenu(const std::string& title, const std::vector<std::string>& options) {
    std::cout << "\n" << BRIGHT_RED << "╔";
    for (int i = 0; i < 58; i++) std::cout << "═";
    std::cout << "╗\n";
    
    std::cout << "║" << BRIGHT_WHITE << " " << title;
    for (int i = title.length() + 1; i < 59; i++) std::cout << " ";
    std::cout << BRIGHT_RED << " ║\n";
    
    std::cout << "╠";
    for (int i = 0; i < 58; i++) std::cout << "═";
    std::cout << "╣\n";
    
    for (const std::string& option : options) {
        std::cout << "║" << CYAN << " " << option << RESET;
        for (int i = option.length() + 1; i < 59; i++) std::cout << " ";
        std::cout << BRIGHT_RED << " ║\n";
    }
    
    std::cout << "╚";
    for (int i = 0; i < 58; i++) std::cout << "═";
    std::cout << "╝\n" << RESET << "\n";
}

// Print Matrix art
void MatrixUI::printMatrixArt() {
    std::cout << "\n";
    std::cout << BRIGHT_RED << "    ╔══════════════════════════════════════════════════════════╗\n";
    std::cout << "    ║                                                              ║\n";
    std::cout << "    ║  ██████╗██╗  ██╗██████╗  ██████╗ ███╗   ██╗██╗ ██╗ ██████╗██╗     ██╗███████╗║\n";
    std::cout << "    ║ ██╔════╝██║  ██║██╔══██╗██╔═══██╗████╗  ██║██║ ██║██╔════╝██║     ██║██╔════╝║\n";
    std::cout << "    ║ ██║     ███████║██████╔╝██║   ██║██╔██╗ ██║██║ ██║██║     ██║     ██║███████╗║\n";
    std::cout << "    ║ ██║     ██╔══██║██╔══██╗██║   ██║██║╚██╗██║██║ ██║██║     ██║     ██║╚════██║║\n";
    std::cout << "    ║ ╚██████╗██║  ██║██║  ██║╚██████╔╝██║ ╚████║██║ ██║╚██████╗███████╗██║███████║║\n";
    std::cout << "    ║  ╚═════╝╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═══╝╚═╝ ╚═╝ ╚═════╝╚══════╝╚═╝╚══════╝║\n";
    std::cout << "    ║                                                              ║\n";
    std::cout << "    ║           ██╗███╗   ██╗    ████████╗███████╗██╗  ██╗████████╗║\n";
    std::cout << "    ║           ██║████╗  ██║    ╚══██╔══╝██╔════╝╚██╗██╔╝╚══██╔══╝║\n";
    std::cout << "    ║           ██║██╔██╗ ██║       ██║   █████╗   ╚███╔╝    ██║   ║\n";
    std::cout << "    ║           ██║██║╚██╗██║       ██║   ██╔══╝   ██╔██╗    ██║   ║\n";
    std::cout << "    ║           ██║██║ ╚████║       ██║   ███████╗██╔╝ ██╗   ██║   ║\n";
    std::cout << "    ║           ╚═╝╚═╝  ╚═══╝       ╚═╝   ╚══════╝╚═╝  ╚═╝   ╚═╝   ║\n";
    std::cout << "    ║                                                              ║\n";
    std::cout << "    ╚══════════════════════════════════════════════════════════╝\n";
    std::cout << RESET << "\n";
}

// Print glitch effect
void MatrixUI::printGlitchEffect(const std::string& text) {
    std::cout << BRIGHT_RED;
    for (int i = 0; i < text.length(); i++) {
        if (getRandom(1, 100) < 10) {
            std::cout << getMatrixChar();
        } else {
            std::cout << text[i];
        }
        sleep(20);
    }
    std::cout << RESET << "\n";
}

// Print loading bar
void MatrixUI::printLoadingBar(int duration) {
    std::cout << "\n" << BRIGHT_RED << "Loading: [";
    for (int i = 0; i < 30; i++) {
        std::cout << " ";
    }
    std::cout << "] 0%\r" << std::flush;
    
    for (int i = 0; i <= 30; i++) {
        sleep(duration * 1000 / 30);
        std::cout << BRIGHT_RED << "Loading: [";
        for (int j = 0; j < i; j++) {
            std::cout << "█";
        }
        for (int j = i; j < 30; j++) {
            std::cout << " ";
        }
        std::cout << "] " << (i * 100 / 30) << "%\r" << std::flush;
    }
    std::cout << "\n" << RESET;
}

// Utility functions
void MatrixUI::sleep(int milliseconds) {
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

int MatrixUI::getRandom(int min, int max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

std::string MatrixUI::getMatrixChar() {
    std::string chars = "01!@#$%^&*()_+-=[]{}|;:,.<>?/~`";
    return std::string(1, chars[getRandom(0, chars.length() - 1)]);
}
