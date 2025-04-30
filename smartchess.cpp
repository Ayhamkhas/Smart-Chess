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
    #include <string>
    #include <bits/stdc++.h>
    #include <unordered_map>
    #include <windows.h>


    using namespace std; 


    // FEN dedug positions
    const char* empty_board = "8/8/8/8/8/8/8/8 w - - ";
    const char* start_position = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1 ";
    const char* tricky_position = "r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w KQkq - 0 1 ";
    const char* killer_position = "rnbqkb1r/pp1p1pPp/8/2p1pP2/1P1P4/3P3P/P1P1P3/RNBQKBNR w KQkq e6 0 1";
    const char* cmk_position = "r2q1rk1/ppp2ppp/2n1bn2/2b1p3/3pP3/3P1NPP/PPP1NPB1/R1BQ1RK1 w - - 0 9 ";


    #define U64 unsigned long long // for bitbaord data type definition, it's a 64 bit unsigned integered represented in binary

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

    enum {P, N, B, R, Q , K, p, n, b, r, q, k};
    
    //side to move 
    enum { white, black, both };

    // for magic bitboards for sliding pieces
    enum {bishop, rook};

    // enum for caslting sides
    enum {wk = 1, wq = 2 , bk = 4 , bq = 8};

    // enum pieces



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


    //convert ascii to enocoded constants
    map<char, int> char_pieces = {
        {'P', P}, {'N', N}, {'B', B}, {'R', R}, {'Q', Q}, {'K', K},
        {'p', p}, {'n', n}, {'b', b}, {'r', r}, {'q', q}, {'k', k}
    };

    // promoted pieces
    unordered_map<char, char> promoted_pieces = {
        {'Q', 'q'},
        {'R', 'r'},
        {'B', 'b'},
        {'N', 'n'},
        {'q', 'q'},
        {'r', 'r'},
        {'b', 'b'},
        {'n', 'n'}
    };

    // bitboard types
    U64 bitboards[12]; // for the pieces
    U64 occupancies [3]; // for white occupanices, black occupances and both
    int side ; // side to move


    // enpassant square
    int enpassant = no_sq;

    // castling rights
    int castle;

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

            BIT MANIPULATION

    \****************************/


    #define get_bit(bitboard,square) (bitboard & (1ULL << square)) // used to get the state of a bit in a sepcifc square (either empty or not)
    #define set_bit(bitboard, square) (bitboard |= (1ULL << square)) // set a specifc square on the board 
    #define remove_bit(bitboard, square) ((bitboard) &= ~(1ULL << (square))) // remove a piece if it exists on a sepcific square on the board

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
            return count_bits((bitboard & -bitboard) - 1);
        
        }

        else 
            return -1;
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
                   if(piece == -1) 
                       file --;  

                   // adjust file counter
                   file += offset;
                   fen++; 
               }

               // match rank seperator 
               if(*fen == '/') 
                   fen++;
           }
       }

       // to check which side to move after parsing
       fen++;

       (*fen =='w') ? (side = white): (side = black);

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


    // is current given square is attacked by the current given side 
    static inline int isSquare_attacked(int square, int side)
    {
        // attacked by white pawns
        if ((side == white) && (pawn_attacks[black][square] & bitboards[P])) return 1;
        
        // attacked by black pawns
        if ((side == black) && (pawn_attacks[white][square] & bitboards[p])) return 1;
        
        // attacked by knights
        if (knight_attacks[square] & ((side == white) ? bitboards[N] : bitboards[n])) return 1;
        
        // attacked by bishops
        if (get_bishop_attacks(square, occupancies[both]) & ((side == white) ? bitboards[B] : bitboards[b])) return 1;

        // attacked by rooks
        if (get_rook_attacks(square, occupancies[both]) & ((side == white) ? bitboards[R] : bitboards[r])) return 1;    

        // attacked by bishops
        if (get_queen_attacks(square, occupancies[both]) & ((side == white) ? bitboards[Q] : bitboards[q])) return 1;
        
        // attacked by kings
        if (king_attacks[square] & ((side == white) ? bitboards[K] : bitboards[k])) return 1;

        // by default return false
        return 0;
    }   

    //print attacked squares
    void print_attacked_squares(int side)
    {
        cout << "\n";
        
        // loop over board ranks
        for (int rank = 0; rank < 8; rank++)
        {
            // loop over board files
            for (int file = 0; file < 8; file++)
            {
                // init square
                int square = rank * 8 + file;
                
                // print ranks
                if (!file)
                    cout<< 8 - rank << '\t';
                
                // check whether current square is attacked or not
                cout << isSquare_attacked(square, side) << " ";
            }
            
            // print new line every rank
            cout << "\n";
        }
        
        // print files
        cout<<"\n        a b c d e f g h \n\n";
    }

    /****************************\

            MOVE GENERATOR

    \****************************/


    // encode move
    #define encode_move(source, target, piece, promoted, capture, double, enpassant, castling) \
    (source) |          \
    (target << 6) |     \
    (piece << 12) |     \
    (promoted << 16) |  \
    (capture << 20) |   \
    (double << 21) |    \
    (enpassant << 22) | \
    (castling << 23)    \
    // extract source square
    #define get_move_source(move) (move & 0x3f)

    // extract target square
    #define get_move_target(move) ((move & 0xfc0) >> 6)

    // extract piece
    #define get_move_piece(move) ((move & 0xf000) >> 12)

    // extract promoted piece
    #define get_move_promoted(move) ((move & 0xf0000) >> 16)

    // extract capture flag
    #define get_move_capture(move) (move & 0x100000)

    // extract double pawn push flag
    #define get_move_double(move) (move & 0x200000)

    // extract enpassant flag
    #define get_move_enpassant(move) (move & 0x400000)

    // extract castling flag
    #define get_move_castling(move) (move & 0x800000)

    // move list structure
    typedef struct {
        // moves
        int moves[256];
        
        // move count
        int count;
    } moves;

    // add move to the move list
    static inline void add_move(moves *move_list, int move)
    {
        // strore move
        move_list->moves[move_list->count] = move;
        
        // increment move count
        move_list->count++;
    }


        // print move (for UCI purposes)
    void print_move(int move)
    {   

        if (get_move_promoted(move)){
            cout << coordinates[get_move_source(move)]
            << coordinates[get_move_target(move)]
            << promoted_pieces[get_move_promoted(move)];
        }
        else{
            cout << coordinates[get_move_source(move)]
            << coordinates[get_move_target(move)];

        }

    
    }


    // print move list
    void print_move_list(moves *move_list)
    {
        // if moves list is empty
        if (!move_list->count)
        {
            cout << "\n\n    No move in the list moves \n\n";
            return;
        }
        cout << "\n    Move    Piece   Capture   Double    Enpass    Castling\n\n";

        
        // loop over moves within a move list
        for (int move_count = 0; move_count < move_list->count; move_count++)
        {
            // init move
            int move = move_list->moves[move_count];
            
            cout << "    "
            << coordinates[get_move_source(move)]
            << coordinates[get_move_target(move)]
            << (get_move_promoted(move) ? promoted_pieces[get_move_promoted(move)] : ' ')<< "    "
            << ascii_pieces[get_move_piece(move)] << "        "
            << (get_move_capture(move) ? 1 : 0) << "          "
            << (get_move_double(move) ? 1 : 0) << "           "
            << (get_move_enpassant(move) ? 1 : 0) << "         "
            << (get_move_castling(move) ? 1 : 0)
            << endl;


        }
        // print total number of moves
        cout << "\n\n                   Total number of moves: " << move_list->count << "\n\n";
    }

    int get_time() // return time in milliseconds for debugging and testing purposes 
    {
        // get time in milliseconds
        return GetTickCount();
    }
    // preserve board state
    // preserve board state
    #define copy_board()                                                      \
        U64 bitboards_copy[12], occupancies_copy[3];                          \
        int side_copy, enpassant_copy, castle_copy;                           \
        memcpy(bitboards_copy, bitboards, 96);                                \
        memcpy(occupancies_copy, occupancies, 24);                            \
        side_copy = side, enpassant_copy = enpassant, castle_copy = castle;   \

    // restore board state
    #define take_back()                                                       \
        memcpy(bitboards, bitboards_copy, 96);                                \
        memcpy(occupancies, occupancies_copy, 24);                            \
        side = side_copy, enpassant = enpassant_copy, castle = castle_copy;   \

    
    // castling rights update constants
    const int castling_rights[64] = {
        7, 15, 15, 15,  3, 15, 15, 11,
        15, 15, 15, 15, 15, 15, 15, 15,
        15, 15, 15, 15, 15, 15, 15, 15,
        15, 15, 15, 15, 15, 15, 15, 15,
        15, 15, 15, 15, 15, 15, 15, 15,
        15, 15, 15, 15, 15, 15, 15, 15,
        15, 15, 15, 15, 15, 15, 15, 15,
        13, 15, 15, 15, 12, 15, 15, 14
    };

/* This will be used to extract information for a specifific move
            binary move bits                               hexidecimal constants
        
        0000 0000 0000 0000 0011 1111    source square       0x3f
        0000 0000 0000 1111 1100 0000    target square       0xfc0
        0000 0000 1111 0000 0000 0000    piece               0xf000
        0000 1111 0000 0000 0000 0000    promoted piece      0xf0000
        0001 0000 0000 0000 0000 0000    capture flag        0x100000
        0010 0000 0000 0000 0000 0000    double push flag    0x200000
        0100 0000 0000 0000 0000 0000    enpassant flag      0x400000
        1000 0000 0000 0000 0000 0000    castling flag       0x800000
    */
    
    

    // move types
    enum { all_moves, only_captures };

    // make move on chess board
    static inline int make_move(int move, int move_flag)
    {
        // handle all move types
        if (move_flag == all_moves)
        {
            copy_board();
    
            int source_square = get_move_source(move);
            int target_square = get_move_target(move);
            int piece = get_move_piece(move);
            int promoted = get_move_promoted(move);
            int capture = get_move_capture(move);
            int double_push = get_move_double(move);
            int enpass = get_move_enpassant(move);
            int castling = get_move_castling(move);
    
            // move piece
            remove_bit(bitboards[piece], source_square);
            set_bit(bitboards[piece], target_square);
    
            // handling capture moves
            if (capture)
            {
                // pick up bitboard piece index ranges depending on side
                int start_piece, end_piece;
                
                // white to move
                if (side == white)
                {
                    start_piece = p;
                    end_piece = k;
                }
                
                // black to move
                else
                {
                    start_piece = P;
                    end_piece = K;
                }
                
                // loop over bitboards opposite to the current side to move
                for (int bb_piece = start_piece; bb_piece <= end_piece; bb_piece++)
                {
                    // if there's a piece on the target square
                    if (get_bit(bitboards[bb_piece], target_square))
                    {
                        // remove it from corresponding bitboard
                        remove_bit(bitboards[bb_piece], target_square);
                        break;
                    }
                }
            }

            // handle promotion
            if (promoted)
            {
                // erase the pawn from the target square
                remove_bit(bitboards[(side == white) ? P : p], target_square);
                
                // set up promoted piece on chess board
                set_bit(bitboards[promoted], target_square);
            }
            if(enpass)
            {
                // erase the pawn depending on side to move
                (side == white) ? remove_bit(bitboards[p], target_square + 8) :
                                  remove_bit(bitboards[P], target_square - 8);
            }   

            //reset enpassant square 
            enpassant = no_sq;

            // handle double push
            if (double_push)
            {
                (side==white) ? (enpassant = target_square + 8) : (enpassant = target_square - 8);
            }

            // handle castling
            if(castling)
            {
                switch(target_square)
                {
                    case(g1) :
                        remove_bit(bitboards[R], h1);
                        set_bit(bitboards[R], f1);
                        break;
                    case(c1) :
                        remove_bit(bitboards[R], a1);
                        set_bit(bitboards[R], d1);
                        break;
                    case(g8) :    
                        remove_bit(bitboards[r], h8);
                        set_bit(bitboards[r], f8);
                        break;
                    case(c8) :       
                        remove_bit(bitboards[r], a8);
                        set_bit(bitboards[r], d8);
                        break;
                }

            }
        
            // update castling rights
            castle &= castling_rights[source_square];
            castle &= castling_rights[target_square];

            //update occupancies
            memset(occupancies, 0ULL, sizeof(occupancies)); // clear occupancies
            
            for(int bb_piece = P; bb_piece <= K; bb_piece++) // for white pieces
            {
                occupancies[white] |= bitboards[bb_piece];
            }
            for(int bb_piece = p; bb_piece <= k; bb_piece++) // for black pieces
            {
                occupancies[black] |= bitboards[bb_piece];
            }

            // update both sides occupancies
            occupancies[both] |= occupancies[white];
            occupancies[both] |= occupancies[black];

            // update side to move
            side ^= 1; // flip side to move

            //checking for king checks
            if (isSquare_attacked((side == white) ? get_least_bit(bitboards[k]) : get_least_bit(bitboards[K]), side))

            {
                // take back move
                take_back();
                return 0; // return illegal move
            }
            else
                return 1; // return legal move
        }
        // handle capture-only mode
        else
        {
            if (get_move_capture(move))
            {
                return make_move(move, all_moves); // make move and return success
            }
            else
            {
                return 0;
            }
        }
    
    }
    // generate all moves 
    static inline void generate_moves(moves *move_list)
    {
        // init move count
        move_list->count = 0;

        // def source square and target square 
        int source_square;
        int target_square;

        // def current pieces bitboard copy
        U64 bitboard;
        U64 attacks;

        // loop over all pieces on board
        for (int piece = P ; piece <= k ; piece++)
        {
            // init copy biboard
            bitboard = bitboards[piece];

            // generating white panws and white king castling moves 
            if(side == white)
            {
                // pick up white pawn bitboards index
                if (piece == P)
                {
                    // loop over white pawns within white pawn bitboard
                    while (bitboard)
                    {
                        // init source square
                        source_square = get_least_bit(bitboard);
                        
                        // init target square
                        target_square = source_square - 8;
                        
                        // generate quite pawn moves
                        if (!(target_square < a8) && !get_bit(occupancies[both], target_square))
                        {
                            // pawn promotion
                            if (source_square >= a7 && source_square <= h7)
                            {
                                add_move(move_list, encode_move(source_square, target_square, piece, Q, 0, 0, 0, 0));
                                add_move(move_list, encode_move(source_square, target_square, piece, R, 0, 0, 0, 0));
                                add_move(move_list, encode_move(source_square, target_square, piece, B, 0, 0, 0, 0));
                                add_move(move_list, encode_move(source_square, target_square, piece, N, 0, 0, 0, 0));
                            }
                            
                            else
                            {
                                // one square ahead pawn move
                                add_move(move_list, encode_move(source_square, target_square, piece, 0, 0, 0, 0, 0));
                                
                                // two squares ahead pawn move
                                if ((source_square >= a2 && source_square <= h2) && !get_bit(occupancies[both], target_square - 8))
                                    add_move(move_list, encode_move(source_square, target_square - 8, piece, 0, 0, 1, 0, 0));
                            }
                        }
                        // init pawn attacks bitboard
                        attacks = pawn_attacks[side][source_square] & occupancies[black];
                        
                        // generate pawn captures
                        while (attacks)
                        {
                            // init target square
                            target_square = get_least_bit(attacks);
                            
                            // pawn promotion
                            if (source_square >= a7 && source_square <= h7)
                            {
                                add_move(move_list, encode_move(source_square, target_square, piece, Q, 1, 0, 0, 0));
                                add_move(move_list, encode_move(source_square, target_square, piece, R, 1, 0, 0, 0));
                                add_move(move_list, encode_move(source_square, target_square, piece, B, 1, 0, 0, 0));
                                add_move(move_list, encode_move(source_square, target_square, piece, N, 1, 0, 0, 0));
                            }
                            
                            else
                                // one square ahead pawn capture
                                add_move(move_list, encode_move(source_square, target_square, piece, 0, 1, 0, 0, 0));

                            remove_bit(attacks, target_square);
                        }
                        // generate enpassant captures
                        if (enpassant != no_sq)
                        {
                            // lookup pawn attacks and bitwise AND with enpassant square (bit)
                            U64 enpassant_attacks = pawn_attacks[side][source_square] & (1ULL << enpassant);
                            
                            // make sure enpassant capture available
                            if (enpassant_attacks)
                            {
                                // init enpassant capture target square
                                int target_enpassant = get_least_bit(enpassant_attacks);
                                add_move(move_list, encode_move(source_square, target_enpassant, piece, 0, 1, 0, 1, 0));
                            }
                        }     
                        
                        // pop ls1b from piece bitboard copy
                        remove_bit(bitboard, source_square);
                    }
                }
            
                // castling moves
                if (piece == K)
                {
                    // king side castling is available
                    if (castle & wk)
                    {
                        // make sure square between king and king's rook are empty
                        if (!get_bit(occupancies[both], f1) && !get_bit(occupancies[both], g1))
                        {
                            // make sure king and the f1 squares are not under attacks
                            if (!isSquare_attacked(e1, black) && !isSquare_attacked(f1, black) && !isSquare_attacked(g1, black))
                                add_move(move_list, encode_move(e1, g1, piece, 0, 0, 0, 0, 1));
                        }
                    }
                    
                    // queen side castling is available
                    if (castle & wq)
                    {
                        // make sure square between king and queen's rook are empty
                        if (!get_bit(occupancies[both], d1) && !get_bit(occupancies[both], c1) && !get_bit(occupancies[both], b1))
                        {
                            // make sure king and the d1 squares are not under attacks
                            if (!isSquare_attacked(e1, black) && !isSquare_attacked(d1, black) && !isSquare_attacked(c1, black))
                                add_move(move_list, encode_move(e1, c1, piece, 0, 0, 0, 0, 1));
                        }
                    }
                }
            }
            //generating black panws and black king castling moves 
            else 
            {
                // pick up black pawn bitboards index
                if (piece == p)
                {
                    // loop over white pawns within white pawn bitboard
                    while (bitboard)
                    {
                        // init source square
                        source_square = get_least_bit(bitboard);
                        
                        // init target square
                        target_square = source_square + 8;
                        
                        // generate quite pawn moves
                        if (!(target_square > h1) && !get_bit(occupancies[both], target_square))
                        {
                            // pawn promotion
                            if (source_square >= a2 && source_square <= h2)
                            {
                                add_move(move_list, encode_move(source_square, target_square, piece, q, 0, 0, 0, 0));
                                add_move(move_list, encode_move(source_square, target_square, piece, r, 0, 0, 0, 0));
                                add_move(move_list, encode_move(source_square, target_square, piece, b, 0, 0, 0, 0));
                                add_move(move_list, encode_move(source_square, target_square, piece, n, 0, 0, 0, 0));
                            }
                            
                            else
                            {
                                // one square ahead pawn move
                                add_move(move_list, encode_move(source_square, target_square , piece, 0, 0, 0, 0, 0));
                                
                                // two squares ahead pawn move
                                if ((source_square >= a7 && source_square <= h7) && !get_bit(occupancies[both], target_square + 8))
                                    add_move(move_list, encode_move(source_square, target_square + 8 , piece, 0, 0, 1, 0, 0));
                            }
                        }
                        // init pawn attacks bitboard
                        attacks = pawn_attacks[side][source_square] & occupancies[white];
                        
                        // generate pawn captures
                        while (attacks)
                        {
                            // init target square
                            target_square = get_least_bit(attacks);
                            
                            // pawn promotion
                            if (source_square >= a2 && source_square <= h2)
                            {
                                add_move(move_list, encode_move(source_square, target_square, piece, q, 1, 0, 0, 0));
                                add_move(move_list, encode_move(source_square, target_square, piece, r, 1, 0, 0, 0));
                                add_move(move_list, encode_move(source_square, target_square, piece, b, 1, 0, 0, 0));
                                add_move(move_list, encode_move(source_square, target_square, piece, n, 1, 0, 0, 0));
                            }
                            
                            else
                                // one square ahead pawn capture
                                add_move(move_list, encode_move(source_square, target_square, piece, 0, 1, 0, 0, 0));

                            remove_bit(attacks, target_square);
                        }
                        // generate enpassant captures
                        if (enpassant != no_sq)
                        {
                            // lookup pawn attacks and bitwise AND with enpassant square (bit)
                            U64 enpassant_attacks = pawn_attacks[side][source_square] & (1ULL << enpassant);
                            
                            // make sure enpassant capture available
                            if (enpassant_attacks)
                            {
                                // init enpassant capture target square
                                int target_enpassant = get_least_bit(enpassant_attacks);
                                add_move(move_list, encode_move(source_square, target_enpassant, piece, 0, 1, 0, 1, 0));
                            }
                        }      

                        // pop ls1b from piece bitboard copy
                        remove_bit(bitboard, source_square);    
                    }   
                }
                
                // check for black side castling rights 
                if (piece == k)
                {
                        // king side castling is available
                        if (castle & bk)
                        {
                            // make sure square between king and king's rook are empty
                            if (!get_bit(occupancies[both], f8) && !get_bit(occupancies[both], g8))
                            {
                                // make sure king and the f8 squares are not under attacks
                                if (!isSquare_attacked(e8, white) && !isSquare_attacked(f8, white) && !isSquare_attacked(g8, white))
                                    add_move(move_list, encode_move(e8, g8, piece, 0, 0, 0, 0, 1));
                            }
                        }
                        
                        // queen side castling is available
                        if (castle & bq)
                        {
                            // make sure square between king and queen's rook are empty
                            if (!get_bit(occupancies[both], d8) && !get_bit(occupancies[both], c8) && !get_bit(occupancies[both], b8))
                            {
                                // make sure king and the d8 squares are not under attacks
                                if (!isSquare_attacked(e8, white) && !isSquare_attacked(d8, white) && !isSquare_attacked(c8, white))
                                    add_move(move_list, encode_move(e8, c8, piece, 0, 0, 0, 0, 1));
                            }
                        }
                }


            }
        
    
            // generate knight moves
            if ((side == white) ? piece == N : piece == n)
            {
                // loop over source squares of piece bitboard copy
                while (bitboard)
                {
                    // init source square
                    source_square = get_least_bit(bitboard);
                    
                    // init piece attacks in order to get set of target squares
                    attacks = knight_attacks[source_square] & ((side == white) ? ~occupancies[white] : ~occupancies[black]);
                    
                    // loop over target squares available from generated attacks
                    while (attacks)
                    {
                        // init target square
                        target_square = get_least_bit(attacks);    
                        
                        // quite move
                        if (!get_bit(((side == white) ? occupancies[black] : occupancies[white]), target_square))
                             add_move(move_list, encode_move(source_square, target_square, piece, 0, 0, 0, 0, 0));
                        
                        else
                            // capture move
                            add_move(move_list, encode_move(source_square, target_square, piece, 0, 1, 0, 0, 0));
                        
                        // pop ls1b in current attacks set
                        remove_bit(attacks, target_square);
                    }
                    
                    
                    // pop ls1b of the current piece bitboard copy
                    remove_bit(bitboard, source_square);
                }
            }

            // generate bishop moves
            if ((side == white) ? piece == B : piece == b)
            {
                // loop over source squares of piece bitboard copy
                while (bitboard)
                {
                    // init source square
                    source_square = get_least_bit(bitboard);
                    
                    // init piece attacks in order to get set of target squares
                    attacks = get_bishop_attacks(source_square, occupancies[both]) & ((side == white) ? ~occupancies[white] : ~occupancies[black]);
                    
                    // loop over target squares available from generated attacks
                    while (attacks)
                    {
                        // init target square
                        target_square = get_least_bit(attacks);    
                        
                        // quite move
                        if (!get_bit(((side == white) ? occupancies[black] : occupancies[white]), target_square))
                            add_move(move_list, encode_move(source_square, target_square, piece, 0, 0, 0, 0, 0));
                        
                        else
                            // capture move
                            add_move(move_list, encode_move(source_square, target_square, piece, 0, 1, 0, 0, 0));
                        
                        // pop ls1b in current attacks set
                        remove_bit(attacks, target_square);
                    }
                    
                    
                    // pop ls1b of the current piece bitboard copy
                    remove_bit(bitboard, source_square);
                }
            }

            // generate rook moves
            if ((side == white) ? piece == R : piece == r)
            {
                // loop over source squares of piece bitboard copy
                while (bitboard)
                {
                    // init source square
                    source_square = get_least_bit(bitboard);
                    
                    // init piece attacks in order to get set of target squares
                    attacks = get_rook_attacks(source_square, occupancies[both]) & ((side == white) ? ~occupancies[white] : ~occupancies[black]);
                    
                    // loop over target squares available from generated attacks
                    while (attacks)
                    {
                        // init target square
                        target_square = get_least_bit(attacks);    
                        
                        // quite move
                        if (!get_bit(((side == white) ? occupancies[black] : occupancies[white]), target_square))
                            add_move(move_list, encode_move(source_square, target_square, piece, 0, 0, 0, 0, 0));
                        
                        else
                            // capture move
                            add_move(move_list, encode_move(source_square, target_square, piece, 0, 1, 0, 0, 0));
                        
                        // pop ls1b in current attacks set
                        remove_bit(attacks, target_square);
                    }
                    
                    
                    // pop ls1b of the current piece bitboard copy
                    remove_bit(bitboard, source_square);
                }
            }

            // generate queen moves
            if ((side == white) ? piece == Q : piece == q)
                    {
                        // loop over source squares of piece bitboard copy
                        while (bitboard)
                        {
                            // init source square
                            source_square = get_least_bit(bitboard);
                            
                            // init piece attacks in order to get set of target squares
                            attacks = get_queen_attacks(source_square, occupancies[both]) & ((side == white) ? ~occupancies[white] : ~occupancies[black]);
                            
                            // loop over target squares available from generated attacks
                            while (attacks)
                            {
                                // init target square
                                target_square = get_least_bit(attacks);    
                                
                                // quite move
                                if (!get_bit(((side == white) ? occupancies[black] : occupancies[white]), target_square))
                                    add_move(move_list, encode_move(source_square, target_square, piece, 0, 0, 0, 0, 0));
                                
                                else
                                    // capture move
                                    add_move(move_list, encode_move(source_square, target_square, piece, 0, 1, 0, 0, 0));
                                
                                // pop ls1b in current attacks set
                                remove_bit(attacks, target_square);
                            }
                            
                            
                            // pop ls1b of the current piece bitboard copy
                            remove_bit(bitboard, source_square);
                        }
                    }

            // generate king moves
            if ((side == white) ? piece == K : piece == k)
            {
                // loop over source squares of piece bitboard copy
                while (bitboard)
                {
                    // init source square
                    source_square = get_least_bit(bitboard);
                    
                    // init piece attacks in order to get set of target squares
                    attacks = king_attacks[source_square] & ((side == white) ? ~occupancies[white] : ~occupancies[black]);
                    
                    // loop over target squares available from generated attacks
                    while (attacks)
                    {
                        // init target square
                        target_square = get_least_bit(attacks);    
                        
                        // quite move
                        if (!get_bit(((side == white) ? occupancies[black] : occupancies[white]), target_square))
                            add_move(move_list, encode_move(source_square, target_square, piece, 0, 0, 0, 0, 0));
                        
                        else
                            // capture move
                            add_move(move_list, encode_move(source_square, target_square, piece, 0, 1, 0, 0, 0));
                        
                        // pop ls1b in current attacks set
                        remove_bit(attacks, target_square);
                    }
                    
                    
                    // pop ls1b of the current piece bitboard copy
                    remove_bit(bitboard, source_square);
                }
            }        
            
        }

    }



    int material_score[12] = {
        100, 300, 350, 500, 1000, 10000, // white pieces
        -100, -300, -350, -500, -1000, -10000 // black pieces
    };
    // pawn positional score
    const int pawn_score[64] = 
    {
        90,  90,  90,  90,  90,  90,  90,  90,
        30,  30,  30,  40,  40,  30,  30,  30,
        20,  20,  20,  30,  30,  30,  20,  20,
        10,  10,  10,  20,  20,  10,  10,  10,
        5,   5,  10,  20,  20,   5,   5,   5,
        0,   0,   0,   5,   5,   0,   0,   0,
        0,   0,   0, -10, -10,   0,   0,   0,
        0,   0,   0,   0,   0,   0,   0,   0
    };

    // knight positional score
    const int knight_score[64] = 
    {
        -5,   0,   0,   0,   0,   0,   0,  -5,
        -5,   0,   0,  10,  10,   0,   0,  -5,
        -5,   5,  20,  20,  20,  20,   5,  -5,
        -5,  10,  20,  30,  30,  20,  10,  -5,
        -5,  10,  20,  30,  30,  20,  10,  -5,
        -5,   5,  20,  10,  10,  20,   5,  -5,
        -5,   0,   0,   0,   0,   0,   0,  -5,
        -5, -10,   0,   0,   0,   0, -10,  -5
    };

    // bishop positional score
    const int bishop_score[64] = 
    {
        0,   0,   0,   0,   0,   0,   0,   0,
        0,   0,   0,   0,   0,   0,   0,   0,
        0,   0,   0,  10,  10,   0,   0,   0,
        0,   0,  10,  20,  20,  10,   0,   0,
        0,   0,  10,  20,  20,  10,   0,   0,
        0,  10,   0,   0,   0,   0,  10,   0,
        0,  30,   0,   0,   0,   0,  30,   0,
        0,   0, -10,   0,   0, -10,   0,   0

    };

    // rook positional score
    const int rook_score[64] =
    {
        50,  50,  50,  50,  50,  50,  50,  50,
        50,  50,  50,  50,  50,  50,  50,  50,
        0,   0,  10,  20,  20,  10,   0,   0,
        0,   0,  10,  20,  20,  10,   0,   0,
        0,   0,  10,  20,  20,  10,   0,   0,
        0,   0,  10,  20,  20,  10,   0,   0,
        0,   0,  10,  20,  20,  10,   0,   0,
        0,   0,   0,  20,  20,   0,   0,   0

    };

    // king positional score
    const int king_score[64] = 
    {
        0,   0,   0,   0,   0,   0,   0,   0,
        0,   0,   5,   5,   5,   5,   0,   0,
        0,   5,   5,  10,  10,   5,   5,   0,
        0,   5,  10,  20,  20,  10,   5,   0,
        0,   5,  10,  20,  20,  10,   5,   0,
        0,   0,   5,  10,  10,   5,   0,   0,
        0,   5,   5,  -5,  -5,   0,   5,   0,
        0,   0,   5,   0, -15,   0,  10,   0
    };

    // mirror positional score tables for opposite side
    const int mirror_score[128] =
    {
        a1, b1, c1, d1, e1, f1, g1, h1,
        a2, b2, c2, d2, e2, f2, g2, h2,
        a3, b3, c3, d3, e3, f3, g3, h3,
        a4, b4, c4, d4, e4, f4, g4, h4,
        a5, b5, c5, d5, e5, f5, g5, h5,
        a6, b6, c6, d6, e6, f6, g6, h6,
        a7, b7, c7, d7, e7, f7, g7, h7,
        a8, b8, c8, d8, e8, f8, g8, h8
    };

    static inline int evaluate_position()
    {
        // init score
        int score = 0;
        
        U64 bitboard;
        int square, piece;
        for(int bb_piece = P; bb_piece <= k; bb_piece++)
        {
            // init copy bitboard
            bitboard = bitboards[bb_piece];
            
            // loop over pieces within the bitboard
            while (bitboard)
            {
                piece = bb_piece; // get piece index 
                // get square of the piece
                square = get_least_bit(bitboard);
                
                // add material score to the position score
                score += material_score[piece];
                switch(piece)
                {
                    //for white pieces
                    case P : score += pawn_score[square]; break;
                    case N : score += knight_score[square]; break;
                    case B : score += bishop_score[square]; break;
                    case R : score += rook_score[square]; break;
                    case K : score += king_score[square]; break;
                    
                    //for black pieces
                    case p : score -= pawn_score[mirror_score[square]]; break;
                    case n : score -= knight_score[mirror_score[square]]; break;
                    case b : score -= bishop_score[mirror_score[square]]; break;
                    case r : score -= rook_score[mirror_score[square]]; break;
                    case k : score -= king_score[mirror_score[square]]; break;
                }
                
                // pop ls1b from the current piece bitboard copy
                remove_bit(bitboard, square);
            }
        }
        return (side == white) ? score : -score; // flip score if black to move
    }
/****************************************/

                //PERFT//

/****************************************/
 
// leaf nodes (number of positions reached during the test of the move generator at a given depth)
    long nodes;

    // perft driver
static inline void perft_driver(int depth)
    {
        // reccursion escape condition
        if (depth == 0)
        {
            // increment nodes count (count reached positions)
            nodes++;
            return;
        }
        
        // create move list instance
        moves move_list[1];
        
        // generate moves
        generate_moves(move_list);
        
            // loop over generated moves
        for (int move_count = 0; move_count < move_list->count; move_count++)
        {   
            // preserve board state
            copy_board();
            
            // make move
            if (!make_move(move_list->moves[move_count], all_moves))
            {  
            // skip to the next move
                continue;
            }
            // call perft driver recursively
            perft_driver(depth - 1);
            
            // take back
            take_back();
        }
    }

    // perft test
void perft_test(int depth)
    {
        cout << "   Performance Test \n\n"; 
        // create move list instance
        moves move_list[1];
        
        // generate moves
        generate_moves(move_list);
        
        long start_time = get_time(); 

        // loop over generated moves
        for (int move_count = 0; move_count < move_list->count; move_count++)
        {   
            // preserve board state
            copy_board();
            
            // make move
            if (!make_move(move_list->moves[move_count], all_moves))
            {  
            // skip to the next move
                continue;
            }

            //cummulative nodes
            long cummulative = nodes;

            // call perft driver recursively
            perft_driver(depth - 1);

            //old nodes count
            long old_nodes = nodes - cummulative;
            
            // take back
            take_back();

            //print move
            cout << "     move: "
            << coordinates[get_move_source(move_list->moves[move_count])]
            << coordinates[get_move_target(move_list->moves[move_count])]
            << (get_move_promoted(move_list->moves[move_count]) ? promoted_pieces[get_move_promoted(move_list->moves[move_count])] : ' ')
            << "  nodes: " << old_nodes << endl;

        }
        //print results
        cout <<"\n     Depth: " << depth << endl;
        cout << "     Nodes: " << nodes << endl;
        cout << "     Time: " << get_time()-start_time << " ms" << endl;
    }


/****************************************/

                //SEARCH//

/****************************************/

// half move counter
int ply;

//best move 
int best_move;

//negamax alpha beta search
static inline int negamax(int alpha, int beta, int depth)
{
    //escape condition
    if (depth == 0)
        // return evaluation
        return evaluate_position();
    
    //increment nodes count
    nodes++;

    // check for king checks
    int king_in_check = isSquare_attacked((side == white) ? get_least_bit(bitboards[K]) : get_least_bit(bitboards[k]), side ^ 1);

    int legal_moves = 0; // legal moves count 

    //best so far (temporarily for now)
    int best_so_far;

    //old aplha
    int old_alpha = alpha;

    // create move list instance
    moves move_list[1];

    // generate moves
    generate_moves(move_list);

    // loop over generated moves
    for(int count = 0; count< move_list->count; count++)
    {
        // preserve the board state 
        copy_board();

        // increment ply
        ply++;

        //make only legal moves
        if(make_move(move_list->moves[count], all_moves) == 0)
        {
            // decrement ply
            ply--;

            continue;
            
        }

        legal_moves++; // increment legal moves count

        // call negamax recursively
        int score = -negamax(-beta, -alpha, depth-1);

        ply--; // decrement ply

        // take back
        take_back();

        // fail-hard beta cutoff
        if(score >= beta)
        {
            //node (move) fails high
            return beta;
        }
            
        // if a better move is found 
        if(score > alpha)
        {
            // PV node (principal variation) found
            alpha = score;

            if(ply == 0)
            {
                // set best move
                best_so_far = move_list->moves[count];
            }
        }
    }

    // if no legal moves are found
    if(legal_moves == 0)
    {
        // check for king in check
        if(king_in_check)
            return -49000 + ply; // return checkmate
        else
            return 0; // return stalemate
    }

    if(old_alpha != alpha)
    {
        // set best move
        best_move = best_so_far;
    }
    return alpha; // return move fails low
}

    void search_position(int depth)
{
    // find best move in a given position

    int score = negamax(-50000 , 50000, depth);

    if(best_move)
    {
        cout << "bestmove "; // placeholder for best move
        print_move(best_move); // print best move
        cout << "\n"; // new line
    }    
}

/****************************************/

                //UCI//

/****************************************/
    int parse_move(string move_string)
    {
        moves move_list[1];
        generate_moves(move_list); 

        int source_squarre = (move_string[0] - 'a') + (8 -(move_string[1]- '0')) * 8;
        int target_square = (move_string[2] - 'a') + (8 - (move_string[3]- '0')) * 8;
        for(int move_count= 0 ; move_count< move_list->count ; move_count++)
        {
            int move = move_list->moves[move_count];

                // if move is found
                if(source_squarre==get_move_source(move) && target_square==get_move_target(move))
                {
                    int promoted_piece = get_move_promoted(move); 
                    if(promoted_piece)  
                    {              

                             if((promoted_piece== Q || promoted_piece== q) && move_string[4] == 'q')
                            {
                                return move;
                            }

                            else if((promoted_piece== R || promoted_piece== r) && move_string[4] == 'r')
                            {
                                return move;
                            }
                            else if((promoted_piece== B || promoted_piece== b) && move_string[4] == 'b')
                            {
                                return move;
                            }
                            else if((promoted_piece== N || promoted_piece== n ) && move_string[4] == 'n')
                            {
                                return move;
                            }

                            continue;

                        }
                    return move;
    
                }
        }
        return 0;
    }

    //parse a uci position command (ex: posistion startpos or position fen ...) and moves to be made
    void parse_position(const char* command)
    {
        command += 9; // skip "position "
        const char *current = command;
        if(strncmp(command, "startpos", 8) == 0)
        {
            parse_fen(start_position);
        }
        else 
        {
            current= strstr(command, "fen");

            if(current== NULL)
            {
                parse_fen(start_position);
            }
            else
            {
                current += 4; // skip "fen "
                parse_fen(current);
            }    
        }

        // parsing moves
        current = strstr(command, "moves");

        if(current != NULL)
        {
            current += 6; // skip "moves "
            while(*current)
            {
                // parse move string
                int move = parse_move(current);
                if(move == 0)
                {
                    cout << "\n\n Illegal move: " << *current << endl;
                    break;
                }
                
                // make move
                make_move(move, all_moves);

                while (*current && *current != ' ')
                {
                    current++;
                }
                current++;
                
            }

        }
        print_board(); // print board after parsing moves

    }

    // parse UCI go command which is used to start the engine to a specifc depth
    void parse_go(const char* command)
    {
        //init depth
        int depth = -1;
        const char* current_depth=NULL;
        // handle fixed depth   
        if(current_depth= strstr(command, "depth"))
        {
            depth = atoi(current_depth + 6 );
        }
        else 
            depth=6; // default depth
        search_position(depth);
    }

    // main loop in UCI
    void uci_loop()
    {
        setbuf(stdout, NULL); // disable output buffering*
        // set input buffe
        setbuf(stdin, NULL); // disable input buffering*
        char input[2000];
        
        //print engine info
        cout << "id name SmartChess 0.1" << endl;
        cout << "id author Mohamed Ayham" << endl;

        //main loop
        while(1)
        {
           memset(input, 0, sizeof(input)); // clear input buffer

           fflush(stdout); // flush output buffer

           if(!fgets(input,2000 ,stdin)) continue; // read input
           
           if(input[0] == '\n') continue; // skip empty lines

           if(strncmp(input, "isready", 7) ==0) // make sure engine is ready
           {
                cout << "readyok\n"; // send readyok response
                continue;
           }
           else if(strncmp(input, "position", 8) ==0) // parse position command
           {
                parse_position(input);
           }
           else if(strncmp(input, "ucinewgame", 10) ==0)
           {
                parse_position("position startpos");
           }
           else if(strncmp(input, "go", 2)==0)
           {
                parse_go(input);
           }
           else if(strncmp(input, "quit", 4)==0)
           {
                break;
           }
           else if(strncmp(input, "uci", 3)==0)
           {
            cout << "id name SmartChess 0.1\n";
            cout << "id author Mohamed Ayham\n";
            cout << "uciok\n";                
           }        
        }
        
    }    

// analysis 
    void analyze_negamax_performance(const vector<string>& fens, int depth, const string& output_file)
    {
        ofstream log(output_file);
        log << "FEN,Depth,Nodes,Time(ms),NPS,BestMove,EvalScore\n";

        for (const auto& fen : fens)
        {
            parse_fen(fen.c_str());

            nodes = 0; // reset node counter
            auto start = chrono::high_resolution_clock::now();
            int score = negamax(-50000, 50000, depth);
            auto end = chrono::high_resolution_clock::now();

            long ms = chrono::duration_cast<chrono::milliseconds>(end - start).count();
            double nps = ms > 0 ? (nodes * 1000.0 / ms) : 0.0;

            // get move in UCI format
            string best_move_str;
            {
                int move = best_move;
                best_move_str = coordinates[get_move_source(move)];
                best_move_str += coordinates[get_move_target(move)];
                if (get_move_promoted(move))
                    best_move_str += tolower(promoted_pieces[get_move_promoted(move)]);
            }

            log << '"' << fen << '"' << ','
                << depth << ','
                << nodes << ','
                << ms << ','
                << (int)nps << ','
                << best_move_str << ','
                << score << '\n';
        }

        log.close();
        cout << "Analysis written to: " << output_file << endl;
    }



    int main()
    {
        // init all
        init_all();
        int debug = 0;
        if(debug)
        {
            parse_fen(tricky_position); // parse start position
            print_board(); // print board   
            search_position(3); // search position to a depth of 4
        }
        else 
            uci_loop(); // start uci loop
        
        vector<string> fens = {
        start_position,
        tricky_position,
        killer_position
        };    

        return 0;   
    }