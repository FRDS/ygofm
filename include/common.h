#ifndef COMMON_H
#define COMMON_H

#include <gccHeaders.h>
#include <scene.h>
#include <text.h>
#include <memcard.h>

enum CardType
{
    DRAGON = 0x00,
    SPELLCASTER = 0x01,
    ZOMBIE = 0x02,
    WARRIOR = 0x03,
    BEAST_WARRIOR = 0x04,
    BEAST = 0x05,
    WINGED_BEAST = 0x06,
    FIEND = 0x07,
    FAIRY = 0x08,
    INSECT = 0x09,
    DINOSAUR = 0x0A,
    REPTILE = 0x0B,
    FISH = 0x0C,
    SEA_SERPENT = 0x0D,
    MACHINE = 0x0E,
    THUNDER = 0x0F,
    AQUA = 0x10,
    PYRO = 0x11,
    ROCK = 0x12,
    PLANT = 0x13,
    MAGIC = 0x14,
    TRAP = 0x15,
    RITUAL = 0x16,
    EQUIP = 0x17
};

enum TerrainID
{
    NORMAL = 0x00,
    FOREST = 0x01,
    WASTELAND = 0x02,
    MOUNTAIN = 0x03,
    MEADOW = 0x04,
    SEA = 0x05,
    DARK = 0x06
};

enum MenuID
{
    NEW_GAME = 0x00,
    LOAD = 0x01,
    DUEL_2P_MENU = 0x02,
    TRADE = 0x03,
    OPTIONS = 0x04,
    CAMPAIGN = 0x05,
    FREE_DUEL = 0x06,
    BUILD_DECK = 0x07,
    LIBRARY = 0x08,
    PASSWORD = 0x09,
    SAVE = 0x0A,
    DEBUG_MENU = 0x0B
};

// Start at:
// USA - 8009AF08
struct global_pointer
{
    char unkFillstart[714];

    // Address: 8009B1D2
    // Description: Last Activated Magic Card ID
    short lastMagicID;

    char unkChar;

    // Address: 8009B1D5
    // Description: Duel Screen - Current Turn
    char currentTurn;

    char unkFill150[150];

    // Address: 8009B26C
    // Description: Current Scene ID
    short currentScene;

    char unkFill86[86];

    struct
    {

        // Address: 8009B2C4
        // Description: Debug Menu - last Sound ID played
        int lastSoundID;

        // Address: 8009B2C8
        // Description: Debug Menu - Scene ID or Sound ID
        int sceneOrSoundID;

    } DebugMenu;

    char unkFill6c[0x6C]; // Filler

    // Address: 8009B338
    // Description: Selected card ID
    short selectedID;

    char unkFill27[0x27]; // Filler

    // Address: 8009B360
    // Description: ? (used in Duel End function 0x218F0)
    // char unknownValue;

    // Address: 8009B361
    // Description: Opponent ID
    char opponentID;

    char unkFill3[0x2]; // Filler

    // Address: 8009B364
    // Description: Terrain type
    char terrainType;

    char unkfill2B[0x2B];

    // Address: 8009B390
    // Description: Where Player Inputs are Processed.
    struct
    {

        // Buffer for player inputs, 2 bytes per each player (P1 & P2)
        // See values in gamepad.h

        // Offset: 0x0
        u_short ButtonHeld[2];
        // Offset: 0x4
        u_short ButtonUpdateCurrFrame[2];
        // Offset: 0x8
        u_short ButtonTapped[2];

        int unk_gamepad[2]; // unknown Data
        
        // Offset: 0x14
        u_short ButtonHeldBackup[2];

    } GamePad;

    char unkFill4EC58[0x4EC58]; // Filler

    // Address: 800EA000
    // 3 structs for 3 types of duelists
    // 0: 1P (Player 1)
    // 1: COM Opponent
    // 2: 2P (Player 2)
    struct
    {
        // Offset: 0x0
        // Description: Average Defense Stat of All Monsters in deck.
        short dfd_factor;

        // Offset: 0x2
        // Description: Life Points (display)
        short LPDisplay;

        // Offset: 0x4
        // Description: Life Points (actual)
        short LPActual;

        // Offset: 0x6
        // Description: Max Life Points
        short LPCap;

        // Offset: 0x8
        // Description: Number of Cards Used.
        char cardsUsed;

        // Offset: 0x9
        // Description: Remaining Swords of Revealing Light Turns
        char remaining_SoRLt;

        // Offset: 0xA
        // 1 byte per card on hand (5 in total, left to right)
        // Description: Deck Number for this Card on hand
        char deckNumber[5];

        // Offset: 0xF (15)
        // Description: Flag for hide/show the cards on your hand.
        // -1: Hide cards
        // 0: Draw card
        // 1: Only draw card number
        char viewCard;

        // Size is 0x10 (16) bytes per player, 0x30 (48) bytes in total

    } DuelStats[3];

    char unkFillE8[0xe8];

    // Address: 800EA118
    // Description: Result of a fusion
    short fusionResult;

    char unkFill145DE[0x145DE]; // Filler

    // Address: 800FE6F8
    // Description: PRNG seed
    // (gets seeded at KONAMI screen, starts rolling at opening cutscene before title screen)
    int prngSeed;

    char unkFill79898[0x79898]; // Filler

    // Address: 80177F94
    // Description: Deck shuffle permutation (Player)
    char playerDeckShuffle[40];

    // Address: 80177FBC
    // Description: Deck shuffle permutation (CPU)
    char cpuDeckShuffle[40];

    int unkFill9;

    // Address: 80177FE8
    // Description: Shuffled deck (Player)
    char playerShuffledDeck[80];

    // Address: 80178038
    // Description: Shuffled deck (CPU)
    char cpuShuffledDeck[80];

    char unkfill150[0x150]; // Filler

    // Address: 801781D8
    // Description: CPU deck pool
    char cpuDeckPool[1444];

    char poolFill0[0x10]; // unk Pool Filler

    // Address: 8017878C
    // Description: SA-POW card drops
    char cardDrops_SA_POW[1444];

    char poolFill1[0x10]; // unk Pool Filler

    // Address: 80178D40
    // Description: BCD card drops
    char cardDrops_BCD[1444];

    char poolFill2[0x10]; // unk Pool Filler

    // Address: 801792F4
    // Description: SA-TEC card drops
    char cardDrops_SA_TEC[1444];

    char poolFill3[0x10]; // unk Pool Filler

    // Address: 801798A8
    // Description: Table of score change to rank based on statistics
    char rankTable[200];

    char unkFillA4[0xA4]; // unk Pool Filler

    // Address: 80179A14
    // Description: Card drop ID
    short cardDropID;

    char unkFill28C2[0x28C2]; // Filler

    // Address: 8017C2D8
    // Description: Fusion table
    // not 65536 or it'll overflows into Menu ID.
    // 33468 is just the assumed size, before where menu ID is.
    char fusionTable[33468];

    // Address: 80184594
    // Description: Main Menu ID
    char menuID;

    char unkFill2388B[0x2388B]; // Filler

    // Address: 801A7E20
    // Description: Current Card data on Players' Hand
    struct
    {

        // Offset: 0x0;
        // First two bytes is card ID;
        short cardId;
        // Offset: 0x2 and 0x4;
        short unkCardData[2];

        // 6 bytes per card, for a total of 5 cards.

    } PlayerHand[5];

    char unkFill1CA[0x1CA]; // Filler

    // Address: 801A8008
    // Description: Password and Cost data for each of the 722 cards.
    struct
    {
        // Offset: 0x0
        int cost;
        // Offset: 0x4
        int password;

        // 8 bytes total for each card.

    } cardPasswordsAndCosts[722];

    char unkFill26B68[0x26B68]; // Filler

    /*
    Address: 801D0200
    Description: Where Player Data is Loaded

    0 - Main Profile (Campaign)
    1 - 1P (Duel 2P)
    2 - 2P (Duel 2P)
    ... There could be more for other purposes
    */
    struct
    {
        // Offset: 0x0
        // Description: Player's deck
        short playerDeck[40];

        // Offset: 0x50 (80)
        // Description: Number of each of 722 Card in chest
        // Max per card 255 (0xFF).
        char cardsInChest[722];

        char unkPlayerFill_12[0x12];

        // Offset: 0x334 (820)
        // Description: Duelist Code
        int duelistCode;

        char blankPlayerFill[8]; // Blank Filler

        // Offset: 0x340 (832)
        // Description: Unknown Player Data
        char unkPlayerData[64];

        char unkPlayerFill_174[0x174]; // Filler

        // Offset: 0x4F4 (1268)
        // Description: Duelists unlocked in Free Duel
        // -1 (0xFFFFFFFF to unlock all)
        int freeDuelUnlocks;

        char unkPlayerFill_C4[0xC4]; // Filler

        // Offset: 0x5BC (1468)
        // Description: Last 10 cards dropped
        short last10CardsDrop[10];

        char unkPlayerFill_16[16]; // Filler

        // Offset: 0x5E0 (1504)
        // Description: Starchip count
        int numStarchips;

        char unkPlayerFill_A1C[0xA1C];

        // size per Player Profile is approximately 0x1000 (4096) bytes;

    } PlayerProfile[3];

    char unkFill24A8[0x24A8];

    // Address: 801D5608
    // int unk1d5608;

    // Address: 801D56A8
    // Description: Card drop ID
    short cardDropID2;
};

extern struct global_pointer gp_static;

// optimal use for modding
register struct global_pointer *gp asm("$gp");

#endif