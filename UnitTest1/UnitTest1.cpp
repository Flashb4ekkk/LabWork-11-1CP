#include "pch.h"
#include "CppUnitTest.h"
#include <fstream>
#include <string>
#include "../LabWork-11-1CP/LabWork-11-1CP.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;



TEST_CLASS(UnitTest1)
{
public:

    TEST_METHOD(TestMethod1)
    {
        std::string input_fname = "test_input.bin";
        std::string output_fname = "test_output.bin";
        std::ofstream input_file(input_fname, std::ios::binary);
        input_file << "a1b2c3d4";
        input_file.close();

        
        ProcessBIN(const_cast<char*>(input_fname.c_str()), const_cast<char*>(output_fname.c_str()));

        
        std::ifstream output_file(output_fname, std::ios::binary);
        std::string output((std::istreambuf_iterator<char>(output_file)), std::istreambuf_iterator<char>());
        Assert::AreEqual(string("abcd"), output);
    }
};
