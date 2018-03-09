#include <catch.hpp>
#include <sstream>

#include "matrix.hpp"

TEST_CASE("creating matrix")
{
    matrix_t matrix;
    REQUIRE( matrix.rows() == 0 );
    REQUIRE( matrix.collumns() == 0 );
}

TEST_CASE("reading matrix")
{
    std::string input
    {
        "3, 3\n"
        "1 1 1\n"
        "2 2 2\n"
        "3 3 3" 
    };
    matrix_t matrix;
    std::istringstream istream{ input };//из строки в числа
    
    REQUIRE( matrix.read( istream ) );
    REQUIRE( matrix.rows() == 3 );
    REQUIRE( matrix.collumns() == 3 );
    
    std::ostringstream ostream;
    matrix.write( ostream );// из чисел в строку
    
    REQUIRE( input == ostream.str() ); //результирующая строка
}

matrix_t matrix( std::string const & representation )
{
    matrix_t result;
    
    std::istringstream istream{ representation };
    assert( result.read( istream ) );
    
    return result;
}

std::string representation( matrix_t const & matrix ) //представление в виде строки
{
    std::ostringstream ostream;
    matrix.write( ostream );
    
    return ostream.str();
}

TEST_CASE("addings matrixs")
{
    std::string first_matrix_representation
    {
        "1, 3\n"
        "1 1 1\n"
    };
    std::string second_matrix_representation
    {
        "1, 3\n"
        "1 1 1\n"
    };
    matrix_t first_matrix = matrix( first_matrix_representation );
    matrix_t second_matrix = matrix( second_matrix_representation );
    
    matrix_t result_matrix = first_matrix + second_matrix;

    std::string expected_result_matrix_representation{
        "1, 3\n"
        "2 2 2\n"
    };
    
    REQUIRE( representation( result_matrix ) == expected_result_matrix_representation );
}

TEST_CASE("subtracting matrixs")
{
    std::string first_matrix_representation
    {
        "1, 3\n"
        "1 1 1\n"
    };
    std::string second_matrix_representation
    {
        "1, 3\n"
        "1 1 1\n"
    };
    matrix_t first_matrix = matrix( first_matrix_representation );
    matrix_t second_matrix = matrix( second_matrix_representation );
    
    matrix_t result_matrix = first_matrix - second_matrix;

    std::string expected_result_matrix_representation
    {
        "1, 3\n"
        "2 2 2\n"
    };
    REQUIRE( representation( result_matrix ) == expected_result_matrix_representation );
}
