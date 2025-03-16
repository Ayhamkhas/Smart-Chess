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
#include <cstring>
#include <bits/stdc++.h>
using namespace std; 


// FEN dedug positions
const char* empty_board = "8/8/8/8/8/8/8/8 w - - ";
const char* start_position = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1 ";
const char* tricky_position = "r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w KQkq - 0 1 ";
const char* killer_position = "rnbqkb1r/pp1p1pPp/8/2p1pP2/1P1P4/3P3P/P1P1P3/RNBQKBNR w KQkq e6 0 1";
const char* cmk_position = "r2q1rk1/ppp2ppp/2n1bn2/2b1p3/3pP3/3P1NPP/PPP1NPB1/R1BQ1RK1 b - - 0 9 ";

/****************************\

        BIT MANIPULATION

\****************************/

#define U64 unsigned long long // for bitbaord data type definition, it's a 64 bit unsigned integered represented in binary
#define get_bit(bitboard,square) (bitboard & (1ULL << square)) // used to get the state of a bit in a sepcifc square (either empty or not)
#define set_bit(bitboard, square) (bitboard |= (1ULL << square)) // set a specifc square on the board 
#define remove_bit(bitboard, square) (get_bit(bitboard,square) ? bitboard ^= (1ULL << square) : 0) // remove a piece if it exists on a sepcific square on the board

//side to move 
enum { white, black, both };

// for magic bitboards for sliding pieces
enum {bishop, rook};

// enum for caslting sides
enum {wk = 1, wq = 2 , bk = 4 , bq = 8};

// enum pieces
enum {P, N, B, R, Q , K, p, n, b, r, q, k};

// board squares representation
enum{
    a8, b8, c8, d8, e8, f8, g8, h8,
    a7, b7, c7, d7, e7, f7, g7, h7,
    a6, b6, c6, d6, e6, f6, g6, h6,
    a5, b5, c5, d5, e5, f5, g5, h5,
    a4, b4, c4, d4, e4, f4, g4, h4,
    a3, b3, c3, d3, e3, f3, g3, h3,
    a2, b2, c2, d2, e2, f2, g2, h2,
    a1, b1, c1, d1, e1, f1, g1, h1, no_sq
};

const char *coordinates [] = {
    "a8", "b8", "c8", "d8", "e8", "f8", "g8", "h8",
    "a7", "b7", "c7", "d7", "e7", "f7", "g7", "h7",
    "a6", "b6", "c6", "d6", "e6", "f6", "g6", "h6",
    "a5", "b5", "c5", "d5", "e5", "f5", "g5", "h5",
    "a4", "b4", "c4", "d4", "e4", "f4", "g4", "h4",
    "a3", "b3", "c3", "d3", "e3", "f3", "g3", "h3",
    "a2", "b2", "c2", "d2", "e2", "f2", "g2", "h2",
    "a1", "b1", "c1", "d1", "e1", "f1", "g1", "h1",
};

// ASCII pieces
char ascii_pieces[]="PNBRQKpnbrqk";

// unicode pieces
const char* unicode_pieces[12] = {
    u8"♙", u8"♘", u8"♗", u8"♖", u8"♕", u8"♔",
    u8"♟", u8"♞", u8"♝", u8"♜", u8"♛", u8"♚"
};


//convert ascii to enocoded constants
map<char, int> char_pieces = {
    {'P', P}, {'N', N}, {'B', B}, {'R', R}, {'Q', Q}, {'K', K},
    {'p', p}, {'n', n}, {'b', b}, {'r', r}, {'q', q}, {'k', k}
};

// bitboard types
U64 bitboards[12]; // for the pieces
U64 occupancies [3]; // for white occupanices, black occupances and both
int side ; // side to move

// enpassant square
int enpassant = no_sq;

// castling rights
int castle;

// count bits on a bitboard (will be used to calculate pieces on a board)
static inline int count_bits(U64 bitboard)
{
    int bit_counter = 0;
    
    while(bitboard)
    {
        bit_counter++;
        bitboard &= bitboard -1;
    }

    return bit_counter;
} 

// get least significant 1st bit on a board 
static inline int get_least_bit(U64 bitboard)
{
    if(bitboard)
    {
        return count_bits((bitboard & -bitboard)-1);
    
    }
    else return -1;
}

/****************************\

RADNOM MAGIC NUMBER CANDIDATES

\****************************/
//pseudo random number state generated randomly to be used in magic bitboards implementations
unsigned int random_state = 1804289383;

// generate 32-bit pseudo legal numbers 
unsigned int get_random_number_32()
{
    unsigned int number = random_state;

    //XOR shift algorithm
    number ^= number << 13;
    number ^= number >> 17;
    number ^= number << 5;

    //update state 
    random_state = number ;

    return number;
}
U64 get_random_number_64(){
    
    U64 n1, n2, n3, n4;

    // init random numbers slicing 16 bits from most significant 1st bit side
    n1 = (U64)(get_random_number_32()) & 0xFFFF;
    n2 = (U64)(get_random_number_32()) & 0xFFFF;
    n3 = (U64)(get_random_number_32()) & 0xFFFF;
    n4 = (U64)(get_random_number_32()) & 0xFFFF;

    return n1 | (n2 << 16) | (n3 << 32) | (n4 << 48);
}
// generate magic number candidate
U64 generate_magic_number(){
    return get_random_number_64() & get_random_number_64() & get_random_number_64();
}




/****************************\

        INPUT/OUTPUT

\****************************/

/*function for printing the bitboard, takes a bitboard as an argument and prints it
time complexity= O(1)
space complexity= O(1)
*/
void print_bitboard(U64 bitboard)
{
    cout << "\n";
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

// print pieces on the whole board 
void print_board()
{
    cout << "\n";
    // loop over board ranks
    for (int rank = 0 ; rank < 8; rank++)
    {
        for(int file = 0 ; file < 8; file++)
        {
            // init square variable
            int square = rank * 8 + file;

            // print ranks
            if (!file)
            {
                cout << 8 - rank << "\t";
            }

            // define piece variable
            int piece = -1;
            
            // loop over all pieces bibtboards, the idea here is to check all of them and see if there's a bit turned on on a specific square
            for (int bb_piece = P; bb_piece <= k ; bb_piece++)
            {
                if (get_bit(bitboards[bb_piece], square))
                {
                    piece = bb_piece;
                }
            }

            //
            if (piece == -1)
            {
                cout << ". ";
            }
            else cout << ascii_pieces[piece] << " ";

        }

        // print new line every rank
        cout << "\n";
    }

    // print board files
    cout<<"\n        a b c d e f g h \n\n";
    
    // print side to move 
    if( side == white)
    {
        cout << "Side to move: " << "white" << "\n";

    }
    else cout << "Side to move: " << "black" << "\n";

    // en passant square 
    cout << "Enpassant: " << ((enpassant != no_sq) ? coordinates[enpassant] : "no") << endl;
    // print castling rights 
    cout << "Castling:  "
              << ((castle & wk) ? 'K' : '-')
              << ((castle & wq) ? 'Q' : '-')
              << ((castle & bk) ? 'k' : '-')
              << ((castle & bq) ? 'q' : '-')
              << "\n\n";
    cout << "\n";
}

// pare FEN string 
void parse_fen(const char* fen)
{
    // reset board position 
    memset(bitboards, 0ULL, sizeof(bitboards));

    // reset occupancies
    memset(occupancies, 0ULL, sizeof(occupancies));

    // reset game state variables
    side = 0;
    enpassant = no_sq;
    castle = 0;

    //loop over board ranks and fike 
    for (int rank = 0 ; rank < 8; rank++)
    {
        for (int file = 0; file < 8; file ++)
        {
            int square = rank * 8 + file;

            // match ascii characters within fen strings
            if ((*fen >='a' && *fen <='z') || (*fen >='A' && *fen <='Z'))
            {
                // init piece type 
                int piece = char_pieces[*fen];

                //set piece on corresponding bitboard
                set_bit(bitboards[piece], square);

                //increment pointer to fen string
                fen++;
            }

            //match empty square numbers within fen string
            if(*fen >='0' && *fen <='9')
            {
                // init offset
                int offset = *fen -'0';

                // define piece variable
                int piece = -1;
                
                // loop over all pieces bibtboards, the idea here is to check all of them and see if there's a bit turned on on a specific square
                for (int bb_piece = P; bb_piece <= k ; bb_piece++)
                {
                    if (get_bit(bitboards[bb_piece], square))
                    {
                        piece = bb_piece;
                    }
                } 
                if(piece == -1) file --;  

                // adjust file counter
                file += offset;
                fen++; 
            }

            // match rank seperator 
            if(*fen == '/') fen++;
        }
    }

    // to check which side to move after parsing
    fen++;

    (*fen =='w') ? (side = white): side = black;

    // extract castling rights
    fen += 2;
    while(*fen != ' ')
    {
        switch (*fen)
        {
            case 'K' : castle |= wk; break;
            case 'Q' : castle |= wq; break;
            case 'k' : castle |= bk; break;
            case 'q' : castle |= bq; break;
            case '-': break;
        }

        fen++;
    }

    // go to parsing enpassant square 
    fen++;  

    // parse enpassant square
    if (*fen != '-')
    {
        // parse enpassant file & rank
        int file = fen[0] - 'a';
        int rank = 8 - (fen[1] - '0');
        
        // init enpassant square
        enpassant = rank * 8 + file;
    }
    
    // no enpassant square
    else
        enpassant = no_sq;
    
    // intit white occupancies
    // loop over white pieces
    for (int piece = P; piece <= K ; piece++)
    {   
        occupancies[white] |= bitboards[piece];
    }

    // for black occupancies
    for (int piece = p; piece <= k ; piece++)
    {   
        occupancies[black] |= bitboards[piece];
    }
    
    // for all occupancies
    occupancies[both] |= occupancies[white];
    occupancies[both] |= occupancies[black];
}

/****************************\

        ATTACK TABLES

\****************************/

/*
not_a_file is used to handle offboard attacks on a file (a column)
        
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

not_h_file is used to handle offboard attacks on h file (h column)

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

not_h_file is used to handle offboard attacks on hg files (hg columns)

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

not_ab_file is used to handle offboard attacks on ab files (ab columns)
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

//  bishop relevant occupany for every square on the board 
const int bishop_relevant_bit[64] = {
    6, 5, 5, 5, 5, 5, 5, 6, 
    5, 5, 5, 5, 5, 5, 5, 5,
    5, 5, 7, 7, 7, 7, 5, 5,
    5, 5, 7, 9, 9, 7, 5, 5,
    5, 5, 7, 9, 9, 7, 5, 5,
    5, 5, 7, 7, 7, 7, 5, 5,
    5, 5, 5, 5, 5, 5, 5, 5,
    6, 5, 5, 5, 5, 5, 5, 6 
};

//  rook relevant occupany for every square on the board
const int rook_relevant_bit[64] = {
    12, 11, 11, 11, 11, 11, 11, 12, 
    11, 10, 10, 10, 10, 10, 10, 11,
    11, 10, 10, 10, 10, 10, 10, 11,
    11, 10, 10, 10, 10, 10, 10, 11,
    11, 10, 10, 10, 10, 10, 10, 11,
    11, 10, 10, 10, 10, 10, 10, 11,
    11, 10, 10, 10, 10, 10, 10, 11,
    12, 11, 11, 11, 11, 11, 11, 12
};

//rook magic numbers 
U64 rook_magic_numbers[64] =  {
    0x8a80104000800020ULL,
    0x140002000100040ULL,
    0x2801880a0017001ULL,
    0x100081001000420ULL,
    0x200020010080420ULL,
    0x3001c0002010008ULL,
    0x8480008002000100ULL,
    0x2080088004402900ULL,
    0x800098204000ULL,
    0x2024401000200040ULL,
    0x100802000801000ULL,
    0x120800800801000ULL,
    0x208808088000400ULL,
    0x2802200800400ULL,
    0x2200800100020080ULL,
    0x801000060821100ULL,
    0x80044006422000ULL,
    0x100808020004000ULL,
    0x12108a0010204200ULL,
    0x140848010000802ULL,
    0x481828014002800ULL,
    0x8094004002004100ULL,
    0x4010040010010802ULL,
    0x20008806104ULL,
    0x100400080208000ULL,
    0x2040002120081000ULL,
    0x21200680100081ULL,
    0x20100080080080ULL,
    0x2000a00200410ULL,
    0x20080800400ULL,
    0x80088400100102ULL,
    0x80004600042881ULL,
    0x4040008040800020ULL,
    0x440003000200801ULL,
    0x4200011004500ULL,
    0x188020010100100ULL,
    0x14800401802800ULL,
    0x2080040080800200ULL,
    0x124080204001001ULL,
    0x200046502000484ULL,
    0x480400080088020ULL,
    0x1000422010034000ULL,
    0x30200100110040ULL,
    0x100021010009ULL,
    0x2002080100110004ULL,
    0x202008004008002ULL,
    0x20020004010100ULL,
    0x2048440040820001ULL,
    0x101002200408200ULL,
    0x40802000401080ULL,
    0x4008142004410100ULL,
    0x2060820c0120200ULL,
    0x1001004080100ULL,
    0x20c020080040080ULL,
    0x2935610830022400ULL,
    0x44440041009200ULL,
    0x280001040802101ULL,
    0x2100190040002085ULL,
    0x80c0084100102001ULL,
    0x4024081001000421ULL,
    0x20030a0244872ULL,
    0x12001008414402ULL,
    0x2006104900a0804ULL,
    0x1004081002402ULL
};

//bishop magic numbers
U64 bishop_magic_numbers[64] = {
    0x40040844404084ULL,
    0x2004208a004208ULL,
    0x10190041080202ULL,
    0x108060845042010ULL,
    0x581104180800210ULL,
    0x2112080446200010ULL,
    0x1080820820060210ULL,
    0x3c0808410220200ULL,
    0x4050404440404ULL,
    0x21001420088ULL,
    0x24d0080801082102ULL,
    0x1020a0a020400ULL,
    0x40308200402ULL,
    0x4011002100800ULL,
    0x401484104104005ULL,
    0x801010402020200ULL,
    0x400210c3880100ULL,
    0x404022024108200ULL,
    0x810018200204102ULL,
    0x4002801a02003ULL,
    0x85040820080400ULL,
    0x810102c808880400ULL,
    0xe900410884800ULL,
    0x8002020480840102ULL,
    0x220200865090201ULL,
    0x2010100a02021202ULL,
    0x152048408022401ULL,
    0x20080002081110ULL,
    0x4001001021004000ULL,
    0x800040400a011002ULL,
    0xe4004081011002ULL,
    0x1c004001012080ULL,
    0x8004200962a00220ULL,
    0x8422100208500202ULL,
    0x2000402200300c08ULL,
    0x8646020080080080ULL,
    0x80020a0200100808ULL,
    0x2010004880111000ULL,
    0x623000a080011400ULL,
    0x42008c0340209202ULL,
    0x209188240001000ULL,
    0x400408a884001800ULL,
    0x110400a6080400ULL,
    0x1840060a44020800ULL,
    0x90080104000041ULL,
    0x201011000808101ULL,
    0x1a2208080504f080ULL,
    0x8012020600211212ULL,
    0x500861011240000ULL,
    0x180806108200800ULL,
    0x4000020e01040044ULL,
    0x300000261044000aULL,
    0x802241102020002ULL,
    0x20906061210001ULL,
    0x5a84841004010310ULL,
    0x4010801011c04ULL,
    0xa010109502200ULL,
    0x4a02012000ULL,
    0x500201010098b028ULL,
    0x8040002811040900ULL,
    0x28000010020204ULL,
    0x6000020202d0240ULL,
    0x8918844842082200ULL,
    0x4010011029020020ULL
};


// Pawn attacks table  [side][square]
U64 pawn_attacks[2][64]; // for 2 sides and for all squares on the board 

// Knight attacks table 
U64 knight_attacks[64]; // only consider square as there are no differences between white knight attacks and black side's ones 

// King attacks table
U64 king_attacks[64];

//bishop attack masks
U64 bishop_masks[64];

//rook attack masks
U64 rook_masks[64];

//bishop attack table [square][occupancy]
U64 bishop_attacks[64][512];

//rook attack table [square][occupancy]
U64 rook_attacks[64][4096];


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
    
    return attacks;
}

// generate bishop attacks on an empty board
U64 mask_bishop_attack(int square)
{
    U64 result = 0ULL;

    int r,f; // init rank and files variables 
    int tr = square / 8; // target rank
    int tf = square % 8; // target file 

    // relevent bishop target bits 
    for (r = tr+1, f = tf+1; r <=6 && f <=6; r++, f++)
    {
        result |= (1ULL <<(r*8 + f ));
    }
    for (r = tr-1, f = tf+1; r >=1 && f <=6; r--, f++)
    {
        result |= (1ULL <<(r*8 + f ));
    }
    for (r = tr+1, f = tf-1; r <=6 && f >=1 ; r++, f--)
    {
        result |= (1ULL <<(r*8 + f ));
    }
    for (r = tr-1, f = tf-1; r >=1 && f >=1 ; r--, f--)
    {
        result |= (1ULL <<(r*8 + f ));
    }

    return result;
}

// to take care of on fly attacks with blokcing pieces on the way
U64 bishop_attack_flying(int square, U64 block)
{
    U64 result = 0ULL;

    int r,f; // init rank and files variables 
    int tr = square / 8; // target rank
    int tf = square % 8; // target file 

    // generate bishop attacks 
    for (r = tr+1, f = tf+1; r <=7 && f <=7; r++, f++)
    {
        result |= (1ULL << (r*8 + f ));
        if((1ULL <<(r*8 + f )) & block) break;
    }
    for (r = tr-1, f = tf+1; r >=0 && f <=7; r--, f++)
    {
        result |= (1ULL <<(r*8 + f ));
        if((1ULL <<(r*8 + f )) & block) break;
    }
    for (r = tr+1, f = tf-1; r <=7 && f >=0 ; r++, f--)
    {
        result |= (1ULL <<(r*8 + f ));
        if((1ULL <<(r*8 + f )) & block) break;

    }
    for (r = tr-1, f = tf-1; r >=0 && f >=0 ; r--, f--)
    {
        result |= (1ULL <<(r*8 + f ));
        if( (1ULL <<(r*8 + f )) & block) break;
    }

    return result;
}

// generate rook attacks
U64 mask_rook_attack(int square)
{
    U64 result = 0ULL;

    int r,f; // init rank and files variables 
    int tr = square / 8; // target rank
    int tf = square % 8; // target file 

    // relevent rook target bits 
    for (r= tr+1; r<= 6; r++)
    {
        result|= (1ULL << (r*8 +tf));
    }
    for (r= tr-1; r>=1; r--)
    {
        result|= (1ULL << (r*8 +tf));
    }
    for (f= tf+1; f<=6; f++)
    {
        result|= (1ULL << (tr*8 +f));
    }
    for (f= tf-1; f>=1; f--)
    {
        result|= (1ULL << (tr*8 +f));
    }

    return result;
}

// rook attacks with blockers
U64 rook_attack_flying(int square, U64 block)
{
    U64 result = 0ULL;

    int r,f; // init rank and files variables 
    int tr = square / 8; // target rank
    int tf = square % 8; // target file 

    // relevent rook target bits on fly with blocking pieces
    for (r= tr+1; r<= 7; r++)
    {
        result|= (1ULL << (r*8 +tf));
        if ((1ULL << (r*8 +tf)) & block) break;
    }
    for (r= tr-1; r>=0; r--)
    {
        result|= (1ULL << (r*8 +tf));
        if ((1ULL << (r*8 +tf)) & block) break;
    }
    for (f= tf+1; f<=7; f++)
    {
        result|= (1ULL << (tr*8 +f));
        if ((1ULL << (tr*8 +f)) & block) break;
    }
    for (f= tf-1; f>=0; f--)
    {
        result|= (1ULL << (tr*8 +f));
        if ((1ULL << (tr*8 +f)) & block) break;
    }

    return result;
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

// set occupancies within an attack on a board
U64 set_occupancy(int index, int bits_in_mask, U64 attack_mask)
{
    //occupancy board 
    U64 occupancy = 0ULL;

    //loop all over the bits within attack range
    for (int count =0 ; count < bits_in_mask; count++)
    {
        // get least significant bit 
        int square = get_least_bit(attack_mask);

        //remove the least signifcant bit 
        remove_bit(attack_mask, square);

        // make sure that the occupancy is on board 
        if(index & (1 << count))
        {
            occupancy |= (1ULL << square);
        }
    }

    return occupancy;
}

/****************************\

        MAGIC BITBOARDS

\****************************/

// find appropriate magic number
U64 find_magic_number(int square, int relevant_bits, int bishop)
{
    // init occupancies
    U64 occupancies[4096];
    
    // init attack tables
    U64 attacks[4096];
    
    // init used attacks
    U64 used_attacks[4096];
    
    // init attack mask for a current piece
    U64 attack_mask = bishop ? mask_bishop_attack(square) : mask_rook_attack(square);
    
    // init occupancy indicies
    int occupancy_indicies = 1 << relevant_bits;
    
    // loop over occupancy indicies
    for (int index = 0; index < occupancy_indicies; index++)
    {
        // init occupancies
        occupancies[index] = set_occupancy(index, relevant_bits, attack_mask);
        
        // init attacks
        attacks[index] = bishop ? bishop_attack_flying(square, occupancies[index]) :
                                    rook_attack_flying(square, occupancies[index]);
    }
    
    // test magic numbers loop
    for (int random_count = 0; random_count < 100000000; random_count++)
    {
        // generate magic number candidate
        U64 magic_number = generate_magic_number();
        
        // skip inappropriate magic numbers
        if (count_bits((attack_mask * magic_number) & 0xFF00000000000000) < 6) continue;
        
        // init used attacks
        memset(used_attacks, 0ULL, sizeof(used_attacks));
        
        // init index & fail flag
        int index, fail;
        
        // test magic index loop
        for (index = 0, fail = 0; !fail && index < occupancy_indicies; index++)
        {
            // init magic index
            int magic_index = (int)((occupancies[index] * magic_number) >> (64 - relevant_bits));
            
            // if magic index works
            if (used_attacks[magic_index] == 0ULL)
                // init used attacks
                used_attacks[magic_index] = attacks[index];
            
            // otherwise
            else if (used_attacks[magic_index] != attacks[index])
                // magic index doesn't work
                fail = 1;
        }
        
        // if magic number works
        if (!fail)
            // return it
            return magic_number;
    }
    
    // if magic number doesn't work
    cout<<"  Magic number failed!"<<endl;
    return 0ULL;
}

void init_magic_numbers()
{
    // loop over 64 board squares
    for (int square = 0; square < 64; square++)
        // init rook magic numbers
        rook_magic_numbers[square] = find_magic_number(square, rook_relevant_bit[square], rook);

    // loop over 64 board squares
    for (int square = 0; square < 64; square++)
        // init bishop magic numbers
        bishop_magic_numbers[square] = find_magic_number(square, bishop_relevant_bit[square], bishop);
}

// init slider pieces's attack tables
// init slider piece's attack tables
void init_sliders_attacks(int bishop)
{
    // loop over 64 board squares
    for (int square = 0; square < 64; square++)
    {
        // init bishop & rook masks
        bishop_masks[square] = mask_bishop_attack(square);
        rook_masks[square] = mask_rook_attack(square);
        
        // init current mask
        U64 attack_mask = bishop ? bishop_masks[square] : rook_masks[square];
        
        // init relevant occupancy bit count
        int relevant_bits_count = count_bits(attack_mask);
        
        // init occupancy indicies
        int occupancy_indicies = (1 << relevant_bits_count);
        
        // loop over occupancy indicies
        for (int index = 0; index < occupancy_indicies; index++)
        {
            // bishop
            if (bishop)
            {
                // init current occupancy variation
                U64 occupancy = set_occupancy(index, relevant_bits_count, attack_mask);
                
                // init magic index
                int magic_index = (occupancy * bishop_magic_numbers[square]) >> (64 - bishop_relevant_bit[square]);
                
                // init bishop attacks
                bishop_attacks[square][magic_index] = bishop_attack_flying(square, occupancy);
            }
            
            // rook
            else
            {
                // init current occupancy variation
                U64 occupancy = set_occupancy(index, relevant_bits_count, attack_mask);
                
                // init magic index
                int magic_index = (occupancy * rook_magic_numbers[square]) >> (64 - rook_relevant_bit[square]);
                
                // init bishop attacks
                rook_attacks[square][magic_index] = rook_attack_flying(square, occupancy);
            
            }
        }
    }
}

// get bishop attacks

static inline U64 get_bishop_attacks (int square, U64 occupancy){

    // get bishop attacks assuming current board occupancies
    occupancy &= bishop_masks[square];
    occupancy *= bishop_magic_numbers[square];
    occupancy >>= 64 - bishop_relevant_bit[square];

    return bishop_attacks[square][occupancy];
}   

// get rook attacks
static inline U64 get_rook_attacks (int square, U64 occupancy){

    // get rook attacks assuming current board occupancies
    occupancy &= rook_masks[square];
    occupancy *= rook_magic_numbers[square];
    occupancy >>= 64 - rook_relevant_bit[square];

    return rook_attacks[square][occupancy];
}  

//get queen attacks
static inline U64 get_queen_attacks (int square, U64 occupancy){

    // init result attacks bitboard
    U64 queen_attacks = 0ULL;

    // init bishop occupancies variable
    U64 bishop_occupancies = occupancy;

    // init rook occupancies variable
    U64 rook_occupancies = occupancy;

    bishop_occupancies &= bishop_masks[square];
    bishop_occupancies *= bishop_magic_numbers[square];
    bishop_occupancies >>= 64 - bishop_relevant_bit[square];
    
    // get bishop attacks
    queen_attacks = bishop_attacks[square][bishop_occupancies];

    // get rook attacks assuming current board occupancies
    rook_occupancies &= rook_masks[square];
    rook_occupancies *= rook_magic_numbers[square];
    rook_occupancies >>= 64 - rook_relevant_bit[square];

    // get rook attacks
    queen_attacks |= rook_attacks[square][rook_occupancies];

    //return queen attacks
    return queen_attacks;
}  

void init_all(){

    init_leap_attacks();
    init_sliders_attacks(bishop);
    init_sliders_attacks(rook);
}


int main()
{
    init_all();
    U64 occupancy = 0ULL;
    set_bit(occupancy, b6);
    set_bit(occupancy, c4);
    print_bitboard(get_queen_attacks(g6,occupancy));


    return 0;
}