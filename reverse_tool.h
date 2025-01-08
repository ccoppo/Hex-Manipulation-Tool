#ifndef __hex_value_h__
#define __hex_value_h__

#include <vector> 
#include <string>

class Hex_Value{ 
    public: 
        std::vector<int> values; 
        int char_count; 
};


class Reverse_Tool{ 
    public: 
    std::vector<Hex_Value> myvalues; 
    std::string mainValue; 
    Hex_Value convert_hex(Hex_Value hex_value); 
    Hex_Value convert_hex(std::string value);
    Hex_Value mix_hex(Hex_Value hex_value, int s); 
    Hex_Value swap_hex(Hex_Value hex_value, int a, int b); 
    Hex_Value reverse_hex(Hex_Value hex_value);
    Hex_Value sort_hex(Hex_Value hex_value); 
    Hex_Value xor_hex(Hex_Value hex_value, Hex_Value hex_2); 
    Hex_Value get_value(); 
    void print_hex(Hex_Value hex_value); 

};

#endif