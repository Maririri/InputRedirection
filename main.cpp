#include <iostream>
#include <fstream>

int main() {
    // Save original std::cin, std::cout
    std::streambuf *coutbuf = std::cout.rdbuf();
    std::streambuf *cinbuf = std::cin.rdbuf();

    std::ofstream out("outfile.txt", std::ofstream::out);
//    std::ifstream in(R"(C:\Users\mari\Documents\input-redirection.txt)");

    //Read from infile.txt using std::cin
//    std::cin.rdbuf(in.rdbuf());

    //Write to outfile.txt through std::cout
    std::cout.rdbuf(out.rdbuf());

    std::string test;
    std::cin >> test;           //from infile.txt
    std::cout << test << "  "; //to outfile.txt

    //Restore back.
    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);

    std::cerr << "err\n";
    return 0;
}
