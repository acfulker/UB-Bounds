//https://stackoverflow.com/questions/19262032/where-is-glibmmconfig-h-in-ubuntu-12-04
//g++ -I/usr/include/libxml2 -I/usr/include/glibmm-2.4 -I/usr/lib/i386-linux-gnu/glibmm-2.4/include -I/usr/include/sigc++-2.0 -I/usr/lib/i386-linux-gnu/sigc++-2.0/include -I/usr/include/glib-2.0 -I/usr/lib/i386-linux-gnu/glib-2.0/include -I/usr/include/libxml++-2.6 -I/usr/lib/libxml++-2.6/include -lxml++-2.6 -lxml2 -lglibmm-2.4 -lgobject-2.0 -lsigc-2.0 -lglib-2.0  testxml.cpp

//pkg-config --cflags --libs libxml++-2.6
//Copy paste result and then run
//g++ <result> testxml.cpp 
//./a.out


#include <iostream>
#include <stdlib.h>
#include "libxml++/libxml++.h"
#include <libxml++/parsers/textreader.h>

struct indent {
    int depth_;
    indent(int depth): depth_(depth) {};
};

std::ostream & operator<<(std::ostream & o, indent const & in)
{
    for(int i = 0; i != in.depth_; ++i)
    {
        o << "  ";
    }
    return o;
}

int main(int /* argc */, char** /* argv */) {
    std::cout << "Hello, World!" << std::endl;
    
    std::locale::global(std::locale(""));
    
    try
    {
        xmlpp::TextReader reader("boxes.xml");
        
        while(reader.read())
        {
            int depth = reader.get_depth();
            std::cout << indent(depth) << "--- node ---" << std::endl;
            std::cout << indent(depth) << "name: " << reader.get_name() << std::endl;
            std::cout << indent(depth) << "depth: " << reader.get_depth() << std::endl;
            
            if(reader.has_attributes())
            {
                std::cout << indent(depth) << "attributes: " << std::endl;
                reader.move_to_first_attribute();
                do
                {
                    std::cout << indent(depth) << "  " << reader.get_name() << ": " << reader.get_value() << std::endl;
                } while(reader.move_to_next_attribute());
                reader.move_to_element();
            }
            else
            {
                std::cout << indent(depth) << "no attributes" << std::endl;
            }
            
            if(reader.has_value())
                std::cout << indent(depth) << "value: '" << reader.get_value() << "'" << std::endl;
            else
                std::cout << indent(depth) << "novalue" << std::endl;
            
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
