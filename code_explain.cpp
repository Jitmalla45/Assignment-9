#include <iostream>
#include <fstream>
#include <bitset>

void printBitSequenceFromFile(std::string filename) {
    std::fstream fhand(filename, std::ios::binary | std::ios::in); // Corrected flags

    char c;
    while (fhand.read(reinterpret_cast<char*>(&c), sizeof(c))) {
        std::cout << std::bitset<8>(c) << " "; // Print each byte as an 8-bit binary sequence
    }
    std::cout << std::endl;
    fhand.close();
}

int main() {
    std::string filename = "data.bin";
    signed int a = -10000;
    unsigned short b = 100;
    const char c[] = "WE";
    const size_t str_size = sizeof(c);

    std::cout << "Encoding values:" << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;

    std::fstream fhand;
    fhand.open(filename, std::ios::binary | std::ios::trunc | std::ios::out); // Corrected flags
    fhand.write(reinterpret_cast<char*>(&a), sizeof(a));
    fhand.write(reinterpret_cast<char*>(&b), sizeof(b));
    fhand.write(c, str_size);
    fhand.close();

    std::cout << "Bit sequence in the file: " << std::endl;
    printBitSequenceFromFile(filename);

    signed int d;
    unsigned short e;
    char f[str_size];
    fhand.open(filename, std::ios::binary | std::ios::in); // Corrected flags
    fhand.read(reinterpret_cast<char*>(&d), sizeof(d));
    fhand.read(reinterpret_cast<char*>(&e), sizeof(e));
    fhand.read(f, str_size);

    std::cout << "Decoded values:" << std::endl;
    std::cout << d << std::endl;
    std::cout << e << std::endl;
    std::cout << f << std::endl;
    fhand.close();
}

/* This code demonstrates writing and reading raw binary data to and from a file, 
treating each variable’s in-memory representation directly. By using binary mode, 
it preserves the exact byte structure of each variable, making it useful for applications
where precise data fidelity is required.

- In the main function, three variables are defined: a (a signed integer with the value -10000),
b (an unsigned short with the value 100), and c (a constant character array containing the string "WE").
These values are displayed on the console to show the original encoded values before they’re written to the file.

- A std::fstream object named fhand is opened in binary mode with the trunc flag, which clears any previous
content in the file before writing.The values of a, b, and c are written to data.bin in binary form, meaning each
variable's raw byte representation is written exactly as stored in memory.

- The printBitSequenceFromFile function opens data.bin in binary read mode and reads each byte individually.
Each byte is printed as an 8-bit binary sequence using std::bitset<8>. This shows the raw binary content of the file byte-by-byte.

- After displaying the bit sequence, the code reopens the file in binary read mode and reads the contents back into new variables d, e, and f.
These variables receive the values from the file in the exact same order they were written.
Finally, the values of d, e, and f are printed to verify that they match the original values.
*/