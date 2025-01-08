#include <iostream>
#include <sstream> 
#include <istream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>

#include "string.h"
#include "reverse_tool.h"

using namespace std;

Hex_Value Reverse_Tool::convert_hex(std::string hex_value){ 
    int length = hex_value.length(); 
    Hex_Value newHex;
    int index = 0; 
    while(index < length){ 
        char c = hex_value.at(index); 
        if(c == ' '){ 
            index++;
        }else if(hex_value.substr(index, 2) == "0x") { 
            index +=2; 
        }else{ 
            int _8bit_hex; 
            
            std::istringstream(hex_value.substr(index, 2)) >> std::hex >> _8bit_hex; 
            newHex.values.push_back(_8bit_hex); 
            index = index + 2; 
        }
    }
    newHex.char_count = newHex.values.size(); 
    return newHex; 
}

Hex_Value Reverse_Tool::get_value(){ 
    cout << "Please enter your hex value: \n" << endl; 
    std::string hex_value; 
    getline(cin, hex_value);  

    cout << "you entered: " << hex_value << endl; 

    Hex_Value ret = convert_hex(hex_value);
    return ret;  
}

void Reverse_Tool::print_hex(Hex_Value hex){ 
    cout << "printing values" << endl; 
    for(int i = 0; i < hex.values.size(); i++){ 
        cout << std::hex << hex.values[i] << " "; 
    }
    cout << endl; 
}
Hex_Value Reverse_Tool::sort_hex(Hex_Value myHex){  
    std::sort(myHex.values.begin(), myHex.values.end()); 
    return myHex; 
}

Hex_Value Reverse_Tool::reverse_hex(Hex_Value myHex){ 
    std::reverse(myHex.values.begin(), myHex.values.end());
    return myHex;
}

Hex_Value Reverse_Tool::xor_hex(Hex_Value hex_orig, Hex_Value hex_2){
    for(int i = 0; i < hex_orig.char_count; i++){ 
        int xor_idx; 
        int result; 
        xor_idx = i % hex_2.char_count; 
        result = hex_orig.values[i] ^ hex_2.values[xor_idx]; 
        hex_orig.values[i] = result;  
    }
    return hex_orig; 
}

Hex_Value Reverse_Tool::mix_hex(Hex_Value hex_orig, int s){ 
    int max = hex_orig.char_count -1 ; 
    for(int i = 0; i <= s && i <= max/2; i++){ 
        int temp = hex_orig.values[i]; 
        hex_orig.values[i] = hex_orig.values[max - i]; 
        hex_orig.values[max - i] = temp; 
    }
    return hex_orig; 
}

Hex_Value Reverse_Tool::swap_hex(Hex_Value hex_orig, int a, int b){ 
    int temp = hex_orig.values[a]; 
    hex_orig.values[a] = hex_orig.values[b]; 
    hex_orig.values[b] = temp; 
    return hex_orig; 
}

int main(){ 
    Reverse_Tool mytool; 
    Hex_Value mainVal; 
    mainVal = mytool.get_value();
    Hex_Value xor_val; 

    char myChar; 
    cout << "Welcome to your reverse engineering helper!\n" << 
            "Options: \n" << 
            "p : print hex\n" << 
            "s : sort hex \n" << 
            "r : reverse hex \n" << 
            "x : xor hex \n" << 
            "q : quit \n" << endl;
    cin >> myChar; 
    while(myChar != 'q'){ 
        if (myChar == 'q'){ 
            break; 
        }
        switch(myChar){ 
            case 'p': {
                mytool.print_hex(mainVal);
                cout << "hex value printed! " << endl; 
                break; 
            }
            case 's': {
                mainVal = mytool.sort_hex(mainVal); 
                cout << "hex value has been sorted!" << endl; 
                break; 
            }
            case 'r': { 
                mainVal = mytool.reverse_hex(mainVal);
                cout << "hex value has been reversed!" << endl;
                break; 
            }
            case 'm': { 
                int val; 
                cin >> val;  
                mainVal = mytool.mix_hex(mainVal, val); 
                cout << "hex value was mixed with key: " << val << endl;
                break;
            }case 'w': { 
                int a, b; 
                cin >> a; 
                cin >> b; 
                mainVal = mytool.swap_hex(mainVal, a, b); 
                cout << "hex value was swapped using values: " << a << " " << b << endl;
                break; 
            }
            case 'x': {
                std::string val;
                getline(cin, val); 
                xor_val = mytool.convert_hex(val); 
                if (xor_val.char_count == 0) {
                    std::cerr << "Error: No valid XOR value entered." << std::endl;
                    break;
                }
                cout << "Operating on value..." << endl;
                mainVal = mytool.xor_hex(mainVal, xor_val);
                cout << "XOR operation complete!" << endl;
                break;
            }
            default: {
                cout << "unknown operation, try again " << endl; 
                break;
            }
        }
        cin >> myChar; 
        }
        return 0; 
    }