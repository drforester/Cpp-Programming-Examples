#include <iostream>

  
// To handle base case of below recursive variadic function Template 
void print() 
{ 
    std::cout << "--- end of debug print ---\n" ; 
} 
  
// Variadic function Template that prints all the values of
// all the inputs
template <typename T, typename... Types>
void print(T var1, Types... var2) {
    std::cout << var1 << "\n" ; 
    print(var2...) ; 
}
