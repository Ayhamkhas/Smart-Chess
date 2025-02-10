/* for board representation, bitboards will be used to represent the whole board. In total we need 12 bitboards (6 for white and 6 for black) as explained below

WHITE     PAWNs             KNIGHTS             BISHOPS              ROOKS               QUEEN               KING
8   0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0
7   0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0
6   0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0
5   0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0
4   0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0
3   0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0
2   1 1 1 1 1 1 1 1     0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0
1   0 0 0 0 0 0 0 0     0 1 0 0 0 0 1 0     0 0 1 0 0 1 0 0     1 0 0 0 0 0 0 1     0 0 0 1 0 0 0 0     0 0 0 0 1 0 0 0
 
    a b c d e f g h     a b c d e f g h     a b c d e f g h     a b c d e f g h     a b c d e f g h     a b c d e f g h

BLACK     PAWNs             KNIGHTS             BISHOPS              ROOKS               QUEEN               KING
8   0 0 0 0 0 0 0 0     0 1 0 0 0 0 1 0     0 0 1 0 0 1 0 0     1 0 0 0 0 0 0 1     0 0 0 1 0 0 0 0     0 0 0 0 1 0 0 0
7   1 1 1 1 1 1 1 1     0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0
6   0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0
5   0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0
4   0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0
3   0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0
2   0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0
1   0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0
 
    a b c d e f g h     a b c d e f g h     a b c d e f g h     a b c d e f g h     a b c d e f g h     a b c d e f g h
*/


#include <iostream>
using namespace std; 

/****************************\

        BIT MANIPULATION

\****************************/

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

//side to move 
enum { white, black };



/****************************\

        INPUT/OUTPUT

\****************************/

/*function for printing the bitboard, takes a bitboard as an argument and prints it
time complexity= O(1)
space complexity= O(1)
*/
void print_bitboard(U64 bitboard)
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


/****************************\

        ATTACK TABLES

\****************************/

/*
not_a_file is used to handle offboard pawn attacks on a file (a column)
        
          NOT_A_File

8       0 1 1 1 1 1 1 1 
7       0 1 1 1 1 1 1 1
6       0 1 1 1 1 1 1 1
5       0 1 1 1 1 1 1 1
4       0 1 1 1 1 1 1 1
3       0 1 1 1 1 1 1 1
2       0 1 1 1 1 1 1 1
1       0 1 1 1 1 1 1 1

        a b c d e f g h

not_h_file is used to handle offboard pawn attacks on h file (h column)

            NOT_H_FILE
8       1 1 1 1 1 1 1 0 
7       1 1 1 1 1 1 1 0
6       1 1 1 1 1 1 1 0
5       1 1 1 1 1 1 1 0
4       1 1 1 1 1 1 1 0
3       1 1 1 1 1 1 1 0
2       1 1 1 1 1 1 1 0
1       1 1 1 1 1 1 1 0

        a b c d e f g h

not_h_file is used to handle offboard pawn attacks on hg files (hg columns)

            NOT_HG_FILE
8       1 1 1 1 1 1 0 0 
7       1 1 1 1 1 1 0 0
6       1 1 1 1 1 1 0 0
5       1 1 1 1 1 1 0 0
4       1 1 1 1 1 1 0 0
3       1 1 1 1 1 1 0 0
2       1 1 1 1 1 1 0 0
1       1 1 1 1 1 1 0 0

        a b c d e f g h

           NOT_AB_FILE
8       0 0 1 1 1 1 1 1 
7       0 0 1 1 1 1 1 1
6       0 0 1 1 1 1 1 1
5       0 0 1 1 1 1 1 1
4       0 0 1 1 1 1 1 1
3       0 0 1 1 1 1 1 1
2       0 0 1 1 1 1 1 1
1       0 0 1 1 1 1 1 1

        a b c d e f g h
*/

// not A file
const U64 not_a_file= 18374403900871474942ULL;

// not H file
const U64 not_h_file=9187201950435737471ULL; 

// not HG file
const U64 not_hg_file=4557430888798830399ULL;

// not AB file
const U64 not_ab_file= 18229723555195321596ULL;

// Pawn attacks table  [side][square]
U64 pawn_attacks[2][64]; // for 2 sides and for all squares on the board 

// Knight attacks table 
U64 knight_attacks[64]; // only consider square as there are no differences between white knight attacks and black side's ones 

// King attacks table
U64 king_attacks[64];

//pawn attack generation

U64 pawn_attack(int side_tomove, int square)
{
    // result bitboard
    U64 attacks= 0ULL;

    //current bitboard
    U64 bitboard = 0ULL;

    set_bit(bitboard,square);

    //for white side
    if(!side_tomove)
    {   
        // generate pawn attacks
        if((bitboard >> 7) & not_a_file) attacks |= (bitboard >> 7); // when white pawns attack, the piece is shifted 7 or 9 squares ahead 
        if((bitboard >> 9) & not_h_file) attacks |= (bitboard >> 9);
    }   

    //for black side 
    else
    {
        if((bitboard << 7) & not_h_file) attacks |= (bitboard << 7); // when black pawns attack, the piece is shifted 7 or 9 squares backword 
        if((bitboard << 9) & not_a_file) attacks |= (bitboard << 9);
    }
    
    return attacks;
}

// generate knight attacks 
U64 knight_attack(int square)
{
    // result bitboard
    U64 attacks= 0ULL;

    //current bitboard
    U64 bitboard = 0ULL;

    set_bit(bitboard,square); 

    // generate knight attacks
    if ((bitboard >> 17) & not_h_file) attacks |= (bitboard >> 17);  // the condition is to take care of knight offside attacks, if the knight is on a file it shouldnt go to h and the move should not be allowed 
    if ((bitboard >> 15) & not_a_file) attacks |= (bitboard >> 15);
    if ((bitboard >> 10) & not_hg_file) attacks |= (bitboard >> 10);
    if ((bitboard >> 6) & not_ab_file) attacks |= (bitboard >> 6);

    if ((bitboard << 17) & not_a_file) attacks |= (bitboard << 17);  // same thing but for opposite direction 
    if ((bitboard << 15) & not_h_file) attacks |= (bitboard << 15);
    if ((bitboard << 10) & not_ab_file) attacks |= (bitboard << 10);
    if ((bitboard << 6) & not_hg_file) attacks |= (bitboard << 6);
    
    
    return attacks;
}

// generate king attacks 
U64 king_attack(int square)
{
    // result bitboard
    U64 attacks= 0ULL;

    //current bitboard
    U64 bitboard = 0ULL;

    set_bit(bitboard,square); 
    
    //generate king attacks/movements 
    if (bitboard >> 8) attacks |= (bitboard >> 8);
    if ((bitboard >> 9) & not_h_file) attacks |= (bitboard >> 9);
    if ((bitboard >> 7) & not_a_file) attacks |= (bitboard >> 7);
    if ((bitboard >> 1) & not_h_file) attacks |= (bitboard >> 1);

    if (bitboard << 8) attacks |= (bitboard << 8);
    if ((bitboard << 9) & not_a_file) attacks |= (bitboard << 9);
    if ((bitboard << 7) & not_h_file) attacks |= (bitboard << 7);   
    if ((bitboard << 1) & not_a_file) attacks |= (bitboard << 1);


    // generate king attacks

    
    
    return attacks;

}

//initialize leaper pieces attacks on the whole board 
void init_leap_attacks()
{
    for(int square = 0; square < 64; square++)
    {
        // init pawns attacks
        pawn_attacks[white][square]= pawn_attack(white,square);
        pawn_attacks[black][square]= pawn_attack(black,square); 

        // init knight attacks 
        knight_attacks[square]= knight_attack(square);

        // init king attacks
        king_attacks[square]= king_attack(square);
    }
}



int main()
{
    init_leap_attacks();
    for(int square=0; square<64; square++)
    {
       print_bitboard(king_attack(square));
    }
    return 0;
}