# Hex Manipulation Tool (CSE365)
A comprehensive C++ command-line tool designed for hex value manipulation and reverse engineering tasks.

## Features
- Convert and manipulate hexadecimal values
- XOR operations with custom keys
- Sort and reverse hex sequences
- Custom mixing algorithms
- Swap operations for detailed manipulation

## Technical Stack
- C++
- Object-Oriented Design
- Command Line Interface

## Code Examples

### Basic Usage
```cpp
Reverse_Tool mytool;
Hex_Value mainVal = mytool.get_value();
mytool.print_hex(mainVal);  // Prints the hex values
```

### XOR Operation
```cpp
Hex_Value original = mytool.convert_hex("0x41 0x42 0x43");
Hex_Value key = mytool.convert_hex("0xFF");
Hex_Value result = mytool.xor_hex(original, key);
```

### Custom Mixing
```cpp
// Mix first 3 positions with last 3 positions
Hex_Value hex = mytool.convert_hex("0x41 0x42 0x43 0x44 0x45 0x46");
hex = mytool.mix_hex(hex, 3);
```

## Installation
```bash
# Clone the repository
git clone [your-repo-url]
cd hex-manipulation-tool

# Compile the program
g++ -o reverse_tool reverse_tool.cpp -std=c++11
```

## Usage
```bash
./reverse_tool
```

### Available Commands
- `p`: Print hex values
- `s`: Sort hex sequence
- `r`: Reverse hex sequence
- `x`: XOR operation
- `m`: Mix hex values
- `w`: Swap hex values
- `q`: Quit program

### Example Session
```
Please enter your hex value:
0x41 0x42 0x43

you entered: 0x41 0x42 0x43

Welcome to your reverse engineering helper!
Options:
p : print hex
s : sort hex
r : reverse hex
x : xor hex
q : quit

> p
printing values
41 42 43
```

## Project Structure
```
hex-manipulation-tool/
├── src/
│   ├── reverse_tool.cpp
│   └── reverse_tool.h
├── LICENSE
├── README.md
└── .gitignore
```

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
