#include<iostream>
#include<fstream>

int main(void)
{
    std::ofstream ofs("../20250203Sample.txt");

    ofs << "Hello World" << std::endl;

    return 0;

}