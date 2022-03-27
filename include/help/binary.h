#include <vector>
#include <memory>
#include <type_traits>
#include <iomanip>

template< typename T > std::vector<uint8_t>  to_bytes( const T& object )
{
    //create buffer
    std::vector<uint8_t> bytes(sizeof(T));

    //get the start and end of the object
    const uint8_t* begin = reinterpret_cast< const uint8_t* >( std::addressof(object) ) ;
    const uint8_t* end = begin + sizeof(T) ;

    //copy the data from the object to the buffer
    std::copy( begin, end, bytes.begin() ) ;

    return bytes ;
}

template< typename T >
T from_bytes( uint8_t* bytes )
{
    //create the object
    T object;

    //get the address of the object
    uint8_t* begin_object = reinterpret_cast< uint8_t* >( std::addressof(object) ) ;
    //copy the data of the buffer into the object
    std::copy( bytes, bytes + sizeof(T), begin_object ) ;

    return object ;
}