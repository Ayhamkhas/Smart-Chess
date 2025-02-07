/* for board representation, bitboards will be used to represent the whole board. In total we need 12 bitboards (6 for white and 6 for black) as explained below

WHITE     PAWNs             KNIGHTS         BISHOPS ROOKS QUEEN KING
8   0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0
7   0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0
6   0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0
5   0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0
4   0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0
3   0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0
2   1 1 1 1 1 1 1 1     0 0 0 0 0 0 0 0
1   0 0 0 0 0 0 0 0     0 1 0 0 0 0 1 0
 
    a b c d e f g h     a b c d e f g h



*/
#include <iostream>
using namespace std;

#define U64 unsigned long long // for bitbaord data type definition, it's a 64 bit unsigned integered represented in binary
#define get_bit(bitboard,square) (bitboard & (1ULL << square)) // used to get the state of a bit in a sepcifc square (either empty or not)
#define set_bit(bitboard, square) (bitboard |= (1ULL << square)) // set a specifc square on the board 
#define remove_bit(bitboard, square) (get_bit(bitboard,square) ? bitboard ^= (1ULL << square) : 0) // remove a piece if it exists on a sepcific square on the board

// board squares representation
enum{
    a8, b8, c8, d8, e8, f8, g8, h8,
    a7, b7, c7, d7, e7, f7, g7, h7,
    a6, b6, c6, d6, e6, f6, g6, h6,
    a5, b5, c5, d5, e5, f5, g5, h5,
    a4, b4, c4, d4, e4, f4, g4, h4,
    a3, b3, c3, d3, e3, f3, g3, h3,
    a2, b2, c2, d2, e2, f2, g2, h2,
    a1, b1, c1, d1, e1, f1, g1, h1
};






/*function for printing the bitboard, takes a bitboard as an argument and prints it
time complexity= O(1)
space complexity= O(1)
*/
void print_bitboard(U64 &bitboard)
{
    // loops over ranks in the board from 1 to 8
    for (int rank=0; rank <8; rank++)
    {
        //loops over bitboard files 
        for(int file=0; file<8; file++)
        {
            //convert file and rank into a specific square in the board
            int square= rank*8 + file;
            if(!file)
            {
                cout<< 8 - rank << '\t';
            }
            cout<< (get_bit(bitboard,square) ? 1 : 0 )<<" "; // to check if the square is empty or not, if not we print 1 otherwise we print 0
        }

        // printing a new line after each rank
        cout<<'\n';
    }
    // printing bitboard files 
    cout<<"\n        a b c d e f g h \n\n";
}



int main()
{
    U64 bitboard= 0ULL;
    set_bit(bitboard, a7);
    set_bit(bitboard, a8);
    print_bitboard(bitboard);
    remove_bit(bitboard, a7);
    print_bitboard(bitboard);
    return 0;
}