#include "evalConfig.hpp"

#include "bitboard.hpp"
#include "position.hpp"

namespace EvalConfig {

CONST_TEXEL_TUNING EvalScore imbalance_mines[5][5] = {
    // pawn knight bishop rook queen
    {  {   -5,   84},  }, // Pawn
    {  {  122,  305}, { -125, -263},  }, // Knight
    {  {  267,  249}, { -229, -244}, { -184, -293},  }, // Bishop
    {  {  305,  527}, { -194, -203}, { -229, -429}, { -170, -442},  }, // Rook
    {  {  544,  573}, { -484, -354}, { -701, -525}, {-1205,-1133}, { -417, -413}, }  // Queen
};

CONST_TEXEL_TUNING EvalScore imbalance_theirs[5][5] = {
    // pawn knight bishop rook queen
    {  { -150, -231},  }, // Pawn
    {  {  281,  325}, {    9,  -41},  }, // Knight
    {  {  212,  475}, {   29,  -72}, {   14,  -45},  }, // Bishop
    {  {  217,  610}, {  103,  -67}, {   -9, -201}, {  -32, -188},  }, // Rook
    {  {  731,  878}, {  442,  347}, {  487,  300}, {  386,  329}, {   34,   13}, }  // Queen
};

CONST_TEXEL_TUNING EvalScore PST[6][64] = {
    {
       {   0,   0},{   0,   0},{   0,   0},{   0,   0},{   0,   0},{   0,   0},{   0,   0},{   0,   0},
       {  98,  88},{ 133,  73},{  60,  78},{  95,  53},{  68,  91},{ 126,  65},{  34, 129},{ -11, 137},
       {  -4,  73},{   7,  44},{  23,  21},{  28,  -7},{  65, -30},{  56,   9},{  25,  41},{ -20,  45},
       {  10,  51},{  13,  33},{   7,  23},{  21,   0},{  17,  11},{  20,  25},{  17,  30},{  -3,  38},
       {  -8,  31},{ -13,  29},{   8,   6},{  25, -12},{  28,  -6},{  30,  -6},{   8,   9},{  -1,   8},
       {   1,  19},{ -17,  24},{   9,   5},{   5,   6},{  17,   6},{  29,   2},{  41,  -5},{  15,  -5},
       { -16,  27},{  -7,  18},{  -2,  19},{  -4,   7},{   0,  17},{  42,   2},{  44,  -4},{   4, -13},
       {   0,   0},{   0,   0},{   0,   0},{   0,   0},{   0,   0},{   0,   0},{   0,   0},{   0,   0},
    },
    {
       {-167, -58},{ -89, -38},{ -34, -13},{ -49, -28},{  61, -31},{ -97, -27},{ -15, -63},{-107, -99},
       { -73, -79},{ -42, -46},{  71, -69},{  36, -35},{  23, -54},{  62, -77},{   7, -59},{ -17, -57},
       { -47, -32},{  60, -43},{  32, -13},{  59, -21},{  83, -32},{ 129, -36},{  73, -41},{  44, -48},
       {  -9, -19},{  32, -10},{   2,  10},{  61,   4},{  44,  -1},{  60,  -1},{  35, -11},{  24, -19},
       {  -4, -18},{   4,  -8},{  16,   1},{  12,   9},{  35,   1},{  26,   1},{  20,   1},{  -1, -23},
       {  -5, -28},{   4, -12},{  16, -23},{  12,   5},{  22,  -5},{  25, -25},{  31, -35},{ -12, -24},
       { -29, -42},{ -53, -20},{  -8, -18},{   7, -26},{   6, -18},{  16, -28},{ -14, -21},{ -20, -44},
       {-105, -29},{ -14, -58},{ -58, -24},{ -36, -15},{ -16, -17},{ -29, -17},{ -35, -46},{ -23, -64},
    },
    {
       { -29, -14},{   4, -21},{ -82, -11},{ -37,  -8},{ -25,  -7},{ -42,  -9},{   7, -17},{  -8, -24},
       { -26,  -6},{  14,  -5},{ -18,   6},{ -13, -11},{  30,  -3},{  59, -15},{  18,  -5},{ -48, -14},
       { -12,   1},{  37,  -7},{  42,  -5},{  40,  -4},{  35,  -1},{  50,   5},{  37,   2},{   6,   4},
       {  -4,   5},{   3,   9},{  19,  11},{  45,   4},{  26,   6},{  37,   6},{  10,  -1},{   9,   3},
       {  -6,  -4},{  16,   7},{  26,   6},{  21,  17},{  38,  -3},{  20,  10},{  18,  -5},{   4,  -9},
       {  16, -11},{  41, -11},{  35,   9},{  28,   7},{  31,  14},{  56, -11},{  39,  -9},{  27, -12},
       {   4, -14},{  37, -23},{  38, -14},{  22,   1},{  33,  -1},{  29,  -1},{  61, -26},{   1, -27},
       { -33, -22},{  -3,  -9},{   9,  -5},{  -6,   4},{  -5,   7},{   1,   3},{ -39,  -5},{ -21, -18}
    },
    {
       {  32,  12},{  42,   8},{  32,  12},{  51,   8},{  63,  10},{   9,  16},{  31,  13},{  43,   7},
       {  28,   3},{  30,   4},{  58,  -8},{  62,  -7},{  79, -16},{  67,  -2},{  26,  13},{  44,   4},
       {  -6,  10},{  19,   5},{  25,  -8},{  36,  -4},{  16,  -3},{  45,  -9},{  61,  -5},{  16,  -6},
       { -25,  11},{ -12,   9},{   6,  12},{  25,   0},{  25,   3},{  35,   4},{  -8,   8},{ -19,  10},
       { -34,  14},{ -25,  19},{ -14,  16},{  -3,   7},{   8,   1},{  -6,   1},{   6,  -3},{ -24,  -5},
       { -31,   2},{ -19,  13},{ -16,   1},{ -16,   3},{   5,  -7},{   6,  -4},{  -3,   3},{ -25,  -5},
       { -27,  -1},{ -10,   4},{ -17,   6},{  -6,   6},{   6,   1},{  23, -10},{  -3,  -8},{ -51,  -1},
       {   8,  -4},{   6,   6},{  17,   1},{  27, -10},{  31,  -9},{  34,  -2},{ -13,   6},{   9, -29}
    },
    {
       { -28, -10},{   0,  23},{  29,  22},{  11,  22},{  59,  27},{  44,  19},{  43,  10},{  45,  20},
       { -28, -15},{ -54,  20},{ -13,  29},{   1,  42},{ -19,  58},{  52,  21},{  28,  30},{  53,   0},
       {   0, -20},{ -16,   5},{  -8,   3},{   0,  48},{  25,  43},{  56,  32},{  44,  19},{  49,   5},
       { -17,   7},{ -28,  25},{ -23,  19},{ -33,  44},{ -18,  56},{   7,  38},{   2,  57},{   7,  39},
       {  -3, -12},{ -27,  29},{  -5,  16},{ -19,  44},{   2,  29},{  -3,  34},{  16,  39},{   6,  28},
       {   0, -16},{  27, -32},{  -9,  13},{  13,  -4},{  10,   5},{  22,  15},{  32,  13},{  20,   8},
       { -12, -15},{  -1, -16},{  26, -31},{  27, -30},{  41, -26},{  37, -24},{   4, -35},{   1, -32},
       {  11, -33},{  14, -29},{  22, -22},{  34, -37},{  18,  -2},{  -2, -26},{ -31, -20},{ -50, -41}
    },
    {
       { -65, -74},{  23, -35},{  16, -17},{ -15,  -4},{ -56, -12},{ -34,  20},{   2,   4},{  13, -17},
       {  29, -12},{  -1,  17},{ -20,  14},{  -7,  31},{  -8,  20},{  -4,  38},{ -38,  23},{ -29,  11},
       {  -9,  10},{  24,  28},{   2,  29},{ -16,  15},{ -20,  21},{   6,  44},{  22,  46},{ -22,  10},
       { -17,  -8},{ -20,  22},{ -12,  34},{ -27,  33},{ -30,  34},{ -25,  35},{ -14,  30},{ -36,   0},
       { -49, -18},{  -1,  -2},{ -27,  28},{ -39,  27},{ -47,  35},{ -43,  20},{ -34,   5},{ -51, -12},
       { -14, -19},{ -14,  -3},{ -24,  21},{ -47,  28},{ -44,  30},{ -30,  18},{ -14,  13},{ -28,  -6},
       {   1, -30},{   7,  -6},{  -8,   9},{ -65,  22},{ -53,  30},{ -28,  17},{  22,  -4},{  14, -20},
       { -15, -55},{  64, -57},{  31, -29},{ -66,  -4},{  20, -37},{ -26, -11},{  49, -39},{  40, -65}
    }
};

///@todo make more things depend on rank/file ???

CONST_TEXEL_TUNING EvalScore   pawnShieldBonus         = {5, -2};
CONST_TEXEL_TUNING EvalScore   pawnFawnMalusKS         = {15, -5};
CONST_TEXEL_TUNING EvalScore   pawnFawnMalusQS         = {-5,  0};
// this depends on rank
CONST_TEXEL_TUNING EvalScore   passerBonus[8]          = { { 0, 0 }, {16, -33} , { 2, -9}, {-6, 20}, {7, 40}, {31, 40}, {51, 61}, {0, 0}};

CONST_TEXEL_TUNING EvalScore   rookBehindPassed        = {-10,53};
CONST_TEXEL_TUNING EvalScore   kingNearPassedPawn      = { -9,16};

// this depends on rank (shall try file also ??)
CONST_TEXEL_TUNING EvalScore   doublePawnMalus[8][2]   = { {{  0,  0},{  0,  0}}, {{  0,  0},{  0,  0}}, {{ 34, 12},{  7, 40}}, {{ 24, 24},{-11, 35}}, {{ 23, 12},{  5, 20}}, {{ -8, -1},{ -4, 26}}, {{ 23, 13},{ 22, 18}}, {{  0,  0},{  0,  0}} }; // close semiopenfile
CONST_TEXEL_TUNING EvalScore   isolatedPawnMalus[8][2] = { {{  0,  0},{  0,  0}}, {{ -9,  8},{  4,  4}}, {{ 12,  6},{ 16, 11}}, {{ -8, 11},{  8, 14}}, {{  3, 23},{ -3, 18}}, {{  6, 18},{-36, 14}}, {{  9,  7},{ 10, 18}}, {{  0,  0},{  0,  0}} }; // close semiopenfile
CONST_TEXEL_TUNING EvalScore   backwardPawnMalus[8][2] = { {{  0,  0},{  0,  0}}, {{  2, -7},{ 24,  6}}, {{  9,  1},{ 28,  5}}, {{ 17,  5},{ 29, -2}}, {{ -9,  4},{ 15,  0}}, {{  0,  0},{  0,  0}}, {{  0,  0},{  0,  0}}, {{  0,  0},{  0,  0}} }; // close semiopenfile

CONST_TEXEL_TUNING EvalScore   detachedPawnMalus[2]    = { { -15, 2}, { -15, -5} };

CONST_TEXEL_TUNING EvalScore   holesMalus              = { -4, 2};
CONST_TEXEL_TUNING EvalScore   pieceFrontPawn          = {-24,15};
CONST_TEXEL_TUNING EvalScore   outpost                 = { 15,19};
CONST_TEXEL_TUNING EvalScore   centerControl           = {  5, 0};
CONST_TEXEL_TUNING EvalScore   knightTooFar[8]         = { {0,0}, {15,-8}, {17,-4}, { 3,9}, {-5,6}, {-10,-8}, {-8,-1}, {0,0} };

// this depends on rank
CONST_TEXEL_TUNING EvalScore   candidate[8]            = { {0, 0}, {-12, -2}, {-16,  5}, { -1, 25}, { 19, 76}, { 34, 64}, { 34, 64}, { 0, 0} };
CONST_TEXEL_TUNING EvalScore   protectedPasserBonus[8] = { {0, 0}, { 24, -8}, {  9, -8}, { 22,-17}, { 10, 13}, { 36, 59}, {  7,  9}, { 0, 0} };
CONST_TEXEL_TUNING EvalScore   freePasserBonus[8]      = { {0, 0}, { 12,  3}, { -6, 10}, { -9, 22}, { -3, 42}, {  3,135}, { 51,150}, { 0, 0} };

CONST_TEXEL_TUNING EvalScore   pawnMobility            = { -7, 15};
CONST_TEXEL_TUNING EvalScore   pawnSafeAtt             = { 47, 17};
CONST_TEXEL_TUNING EvalScore   pawnSafePushAtt         = { 21, 11};
CONST_TEXEL_TUNING EvalScore   pawnlessFlank           = {-18,-20};
CONST_TEXEL_TUNING EvalScore   pawnStormMalus          = { 15,-27};
CONST_TEXEL_TUNING EvalScore   rookOnOpenFile          = { 61,  6};
CONST_TEXEL_TUNING EvalScore   rookOnOpenSemiFileOur   = { 16, -1};
CONST_TEXEL_TUNING EvalScore   rookOnOpenSemiFileOpp   = { 39, -2};

CONST_TEXEL_TUNING EvalScore   rookQueenSameFile       = {  2, 13};
CONST_TEXEL_TUNING EvalScore   rookFrontQueenMalus     = { -7,-29};
CONST_TEXEL_TUNING EvalScore   rookFrontKingMalus      = {-14,  6};
CONST_TEXEL_TUNING EvalScore   minorOnOpenFile         = {  9,  6};

CONST_TEXEL_TUNING EvalScore   pinnedKing [5]          = { { -9, -7}, { 23, 58}, {-17, 72}, {-10, 67}, {-13, 11} };
CONST_TEXEL_TUNING EvalScore   pinnedQueen[5]          = { {  5, -6}, {-29,  7}, { -2, 13}, { -3,  6}, { 33, 25} };

CONST_TEXEL_TUNING EvalScore   hangingPieceMalus       = {-27,-4};
   
CONST_TEXEL_TUNING EvalScore   threatByMinor[6]        = { {  -9,-17 },{ -18,-38 },{ -21, -21 },{ -39,  1 },{ -34, -6 },{ -60, -23 } };
CONST_TEXEL_TUNING EvalScore   threatByRook[6]         = { {  -4,-19 },{ -18, -7 },{  -8, -25 },{ -14, 15 },{ -65,  5 },{ -19, -24 } };
CONST_TEXEL_TUNING EvalScore   threatByQueen[6]        = { {  -6, 15 },{   0, 18 },{  19, -16 },{  30, -5 },{  43, 23 },{ -29, -47 } };
CONST_TEXEL_TUNING EvalScore   threatByKing[6]         = { {  16,-40 },{  -4,-13 },{  45, -53 },{  17,-41 },{   0,  0 },{   0,   0 } };
   
// this depends on number of pawn
CONST_TEXEL_TUNING EvalScore   adjKnight[9]            = { {-26,-20}, { -10,-4}, {  1, -2}, {  7,  0}, {  1,  9}, {  1, 25}, {  7, 39}, { 26, 50}, { 47, 27} };
CONST_TEXEL_TUNING EvalScore   adjRook[9]              = { { 24, -8}, {  15, 4}, {-26, 13}, {-49, 16}, {-47,  9}, {-44, -1}, {-37, -5}, {-37, -3}, {-42, 38} };
CONST_TEXEL_TUNING EvalScore   badBishop[9]            = { { -2,  3}, {  -2,11}, { -5, 25}, {  2, 31}, {  6, 39}, { 10, 52}, { 18, 39}, { 21, 50}, { 39, 65} };
CONST_TEXEL_TUNING EvalScore   bishopPairBonus[9]      = { { 29, 56}, { 28, 58}, { 30, 72}, { 16, 86}, { 35, 69}, { 39, 78}, { 32, 94}, { 43, 83}, { 58, 69} };

CONST_TEXEL_TUNING EvalScore   knightPairMalus         = {14,  9};
CONST_TEXEL_TUNING EvalScore   rookPairMalus           = {20,-15};
CONST_TEXEL_TUNING EvalScore   queenNearKing           = { 5,  0};

//N B R QB QR K
CONST_TEXEL_TUNING EvalScore MOB[6][15] = { { { 13,-42},{ 22,  0},{ 28, 10},{ 31, 19},{ 36, 20},{ 39, 24},{ 42, 28},{ 35, 46},{ 29, 47},{  0,  0},{  0,  0},{  0,  0},{  0,  0},{  0,  0},{  0,  0} },
                                            { {-15,-24},{  0,  0},{  7, 12},{ 14, 19},{ 17, 23},{ 16, 29},{ 19, 28},{ 21, 30},{ 41, 25},{ 45, 36},{ 55, 37},{ 71, 65},{ 71, 56},{120, 95},{  0,  0} },
                                            { { 14,-40},{ 16, 16},{ 18, 36},{ 20, 44},{ 19, 50},{ 25, 53},{ 28, 58},{ 36, 60},{ 37, 65},{ 45, 69},{ 57, 71},{ 56, 73},{ 48, 76},{ 57, 69},{ 72, 56} },
                                            { {-12,-40},{ -5,-22},{  1,-17},{  3, -3},{  9,  0},{  8, 11},{  8, 22},{ 17, 41},{ 13, 13},{ 23, 47},{ 28, 50},{ 34, 24},{ 16, 32},{ 24, 87},{  0,  0} },
                                            { { -3,-64},{ -5,-25},{ -2,-12},{ -2,-12},{  2, -8},{  0,  2},{  2, 13},{  7, 14},{ 13, 15},{ 21, 26},{  8, 37},{ 21, 43},{ 25, 48},{ 19, 45},{ 24, 54} },
                                            { { -3,-16},{-15, 31},{-19, 41},{-21, 51},{-26, 50},{-28, 41},{-29, 44},{-30, 38},{-40, 19},{  0,  0},{  0,  0},{  0,  0},{  0,  0},{  0,  0},{  0,  0} }};

CONST_TEXEL_TUNING EvalScore initiative[4] = {{1,6}, {59,40}, {115,65}, {71,88}};

CONST_TEXEL_TUNING ScoreType kingAttMax    = 428;
CONST_TEXEL_TUNING ScoreType kingAttTrans  = 46;
CONST_TEXEL_TUNING ScoreType kingAttScale  = 13;
CONST_TEXEL_TUNING ScoreType kingAttOffset =  9;
CONST_TEXEL_TUNING ScoreType kingAttWeight[2][6]    = { { 135, 234, 242, 219, 321, -34}, { 226, 167, 151, 19, -16, 0} };
CONST_TEXEL_TUNING ScoreType kingAttSafeCheck[6]    = {   128, 1184, 1152, 1056, 1024, 0};
CONST_TEXEL_TUNING ScoreType kingAttOpenfile        = 119;
CONST_TEXEL_TUNING ScoreType kingAttSemiOpenfileOpp = 84;
CONST_TEXEL_TUNING ScoreType kingAttSemiOpenfileOur = 102;
ScoreType kingAttTable[64]       = {0};

CONST_TEXEL_TUNING EvalScore tempo = {0,0}; //{20, 20};

// slow application of factor depending on materialFactor around 1 (meaning equal material)
inline void scaleShashin(EvalScore & score, const float materialFactor, const float factor){
   return score = EvalScore{ScoreType(materialFactor*score[MG]*factor+(1-materialFactor)*score[MG]),
                            ScoreType(materialFactor*score[EG]*factor+(1-materialFactor)*score[EG])};
}

//-------------------------------------------
// if more or less even in material
// if mobility is already high
//    * attack ++
//    * positional ++
//    * try sac ?
// if mobility is even
//    * positional ++
//    * exchange ++
//    * push pawn ++
// if mobility is too small
//    * go back
//    * mobility ++
//-------------------------------------------
void applyShashinCorrection(const Position & p, const EvalData & data, EvalScore & materialScore, EvalScore & developmentScore, EvalScore & positionalScore, EvalScore & mobilityScore, EvalScore & pawnStructScore, EvalScore & attackScore){
    
    return;

/*
    const ShashinType stype = data.shashinMobRatio  < 0.8 ? Shashin_Petrosian :
                              data.shashinMobRatio == 0.8 ? Shashin_Capablanca_Petrosian :
                              data.shashinMobRatio  < 1.2 ? Shashin_Capablanca :
                              data.shashinMobRatio == 1.2 ? Shashin_Tal_Capablanca :
                              Shashin_Tal; // data.shashinMobRatio > 1.2

    // material
    materialScore = materialScore;

    // take forwardness into account if Petrosian
    if ( stype >= Shashin_Capablanca_Petrosian ) materialScore += EvalConfig::forwardnessMalus * (p.c==Co_White?-1:+1) * (data.shashinForwardness[p.c] - data.shashinForwardness[~p.c]);

    // positional
    //positionalScore = positionalScore;
    scaleShashin(positionalScore,data.shashinMaterialFactor,data.shashinMobRatio);

    // development
    //developmentScore = developmentScore;
    scaleShashin(developmentScore,data.shashinMaterialFactor,1.f/data.shashinMobRatio);

    // mobility
    //mobilityScore = mobilityScore;
    scaleShashin(mobilityScore,data.shashinMaterialFactor,1.f/data.shashinMobRatio);

    // pawn structure
    pawnStructScore = pawnStructScore;

    // attack
    //attackScore = attackScore;
    scaleShashin(attackScore,data.shashinMaterialFactor,data.shashinMobRatio);
*/
}

} // EvalConfig
