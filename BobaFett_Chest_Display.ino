/*
  Boba Fett Chest Display Circuit
  This is the software for the display on Boba Fett’s chest plate.
  Arduino IDE.

  Last Modified: Dec 18, 2020

  Authors: Joshua Kane, Dustin Westaby

  Video Demo:
  https://www.flickr.com/photos/dwest2/23788341410

  Part List:
  http://www.mouser.com/ProjectManager/ProjectDetail.aspx?AccessID=7c6a316116

  PCB Main Board:
  https://www.oshpark.com/shared_projects/ml5VjhuM

  PCB Bargraph Board:
  https://www.oshpark.com/shared_projects/E4qjCF4r

  Usage: 
   - Some example sequences are given below. Comment / Uncomment the sequence you want to use.
   - For a customized sequence, use the sequence_builder.xlsx
   - To synch the bargraph and character animations, use the same divider and the same number of sequence steps.
*/

 /* =========================
      Structure Constants
   ========================= */

/* START: Mandalorian Animation */

#define BAR_SEQ_SIZE 8
#define CHAR_SEQUENCE_SIZE 10

//higher = slower
#define CHAR_ANIMATION_SPEED_DIVIDER 9  // Sets divider, NUM_LOOPS_PER_WORD / 2^X
#define BAR_ANIMATION_SPEED_DIVIDER  7  // Sets divider, NUM_LOOPS_PER_WORD / 2^X

const byte char_sequence[10][5] =
{
    //  DIGIT 1     DIGIT 2     DIGIT 3     DIGIT 4     DIGIT 5  
    //  GFEDCBA     GFEDCBA     GFEDCBA     GFEDCBA     GFEDCBA         
    {0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111},            // 0
    {0b10001001, 0b11000010, 0b10100100, 0b10000000, 0b11001110}, //HG28|    // 1
    {0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000}, //88888    // 2
    {0b10111101, 0b11011011, 0b11110110, 0b11001111, 0b10111110}, // -'',_|- // 3
    {0b10100001, 0b11000001, 0b10000110, 0b10001100, 0b11111101},  //dUEP'   // 4
    {0b10001001, 0b10010011, 0b10100100, 0b10011000, 0b11001111}, //H5291    // 5
    {0b10001010, 0b10000110, 0b10101000, 0b11100000, 0b10001111}, //hEaJt    // 6
    {0b10000110, 0b10000110, 0b10101100, 0b11110000, 0b10011111}, //EE2Cl    // 7
    {0b10111001, 0b11010111, 0b11111110, 0b11001111, 0b10111110}, //t,-|_    // 8
    {0b10011010, 0b10000110, 0b10111101, 0b11100000, 0b10011111}, //5E-J-    // 9
};

const byte bar_sequence[8] =
{           //  BARGRAPH
            //   12345
    0x00, //  0 |    =|
    0x01, //  1 |   = |
    0x02, //  2 |  =  |
    0x03, //  3 | =   |
    0x04, //  4 |=    |
    0x03, //  5 | =   |
    0x02, //  6 |  =  |
    0x01, //  7 |   = |
};
/* // END: Mandalorian Animation */

/* START: ESB Animation 
 
//higher = slower (max = 10)
#define CHAR_ANIMATION_SPEED_DIVIDER  10
#define BAR_ANIMATION_SPEED_DIVIDER   10

const byte char_sequence[11][5] =
{
    //  DIGIT 1     DIGIT 2     DIGIT 3     DIGIT 4     DIGIT 5  
    //  GFEDCBA     GFEDCBA     GFEDCBA     GFEDCBA     GFEDCBA         
    {0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111},  //      // 0
    {0b10100001, 0b11000001, 0b10000110, 0b10001100, 0b11111101},  //dUEP' // 1
    {0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000},  //88888 // 2
    {0b10100001, 0b11000001, 0b10000110, 0b10001100, 0b11111101},  //dUEP' // 3
    {0b10001011, 0b10000110, 0b10001000, 0b10100001, 0b10001001},  //hEADH // 4
    {0b10111101, 0b11011011, 0b11110110, 0b11001111, 0b10111110},  //'.=¦= // 5
    {0b10100001, 0b11000001, 0b10000110, 0b10001100, 0b11111101},  //dUEP' // 6
    {0b10001001, 0b10010010, 0b10100100, 0b10011000, 0b11111001},  //H5291 // 7
    {0b10111101, 0b11011011, 0b11110110, 0b11001111, 0b10111110},  //'.=¦= // 8
    {0b10100001, 0b11000001, 0b10000110, 0b10001100, 0b11111101},  //dUEP' // 9
    {0b10001001, 0b11000010, 0b10100100, 0b10000000, 0b11001110},  //H{E8¬ // 10
};

const byte bar_sequence[11] =
{           //  BARGRAPH
            //   12345
    0xFF, //  0 |     |
    0x01, //  1 | =   |
    0x03, //  2 |   = |
    0x02, //  3 |  =  |
    0x04, //  4 |    =|
    0xFF, //  5 |     |
    0x01, //  6 | =   |
    0x00, //  7 |=    |
    0xFF, //  8 |     |
    0x01, //  9 | =   |
    0xFF, // 10 |     |
};
// END: ESB Animation */


/* START: ROTJ Animation 
 
//higher = slower
#define CHAR_ANIMATION_SPEED_DIVIDER  10
#define BAR_ANIMATION_SPEED_DIVIDER   10

const byte char_sequence[8][5] =
{
    //  DIGIT 1     DIGIT 2     DIGIT 3     DIGIT 4     DIGIT 5  
    //  GFEDCBA     GFEDCBA     GFEDCBA     GFEDCBA     GFEDCBA         
    {0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000},  //88888 // 0
    {0b10111101, 0b11011011, 0b11110110, 0b11001111, 0b10111110},  //'.=¦= // 1
    {0b10100001, 0b11000001, 0b10000110, 0b10001100, 0b11111101},  //dUEP' // 2
    {0b10001001, 0b11000010, 0b10100100, 0b10000000, 0b11001110},  //HG28r // 3
    {0b10001001, 0b10010010, 0b10100100, 0b10011000, 0b11111001},  //H5291 // 4
    {0b10111101, 0b11011011, 0b11110110, 0b11001111, 0b10111110},  //'.=¦= // 5
    {0b10001011, 0b10000110, 0b10001000, 0b10100001, 0b10001001},  //hEADH // 6
    {0b10001001, 0b11000010, 0b10100100, 0b10000000, 0b11001110},  //HG28r // 7
};

const byte bar_sequence[8] =
{           //  BARGRAPH
            //   12345
    0x03, //  0 |   = |
    0xFF, //  1 |     |
    0x02, //  2 |  =  |
    0xFF, //  3 |     |
    0x00, //  4 |=    |
    0xFF, //  5 |     |
    0x04, //  6 |    =|
    0xFF, //  7 |     |
};
// END: ROTJ Animation */


/* *************************************************** */
/* DO NOT EDIT BELOW THIS LINE */
/* *************************************************** */

// This section contains speed calculations

#define ANIMATION_SPEED_MULTIPLIER 100  // Sets multiplier, CHAR_SEQUENCE_SIZE * BAR_SEQ_SIZE * X

//NUM_LOOPS_PER_WORD needs to be divisible by bar_sequence and char_sequence's size
#define NUM_LOOPS_PER_WORD (CHAR_SEQUENCE_SIZE*BAR_SEQ_SIZE*CHAR_ANIMATION_SPEED_DIVIDER*ANIMATION_SPEED_MULTIPLIER) 

/* ********** Example speed calc **********
     speed multipler = 100
     char speed divider = 9   //2^9 = 512
     bar speed divider  = 6   //2^6 = 64
     
     NUM_LOOPS_PER_WORD = (CHAR_SEQUENCE_SIZE*BAR_SEQ_SIZE*ANIMATION_SPEED_MULTIPLIER*CHAR_ANIMATION_SPEED_DIVIDER*BAR_ANIMATION_SPEED_DIVIDER) = (10*8*9*100) = 72000
     
     for ( NUM_LOOPS_PER_WORD )
        charIdx = (i >> CHAR_ANIMATION_SPEED_DIVIDER) % CHAR_SEQ_SIZE = (i / 64) % 10
        barIdx  = (i >> BAR_ANIMATION_SPEED_DIVIDER)  % BAR_SEQ_SIZE  = (i / 64) % 8

     // Every 512th, the character will update, sending an index of 0-9 to word_test
     // Every 64th loop, the bar will update, sending an index of 0-7 to bar_test
     
********** ********** ********** ********** */

// This section contains board specific information

#define NUM_BARS       5
#define NUM_DIGITS     5
#define NUM_SEGMENTS   7

#define BAR_ON      LOW
#define BAR_OFF     HIGH

const byte pinmap_bars[NUM_BARS] =
{
	11,   // Bar 1
	12,   // Bar 2
	13,   // Bar 3
	2,    // Bar 4
	3,    // Bar 5
};

const byte pinmap_segments[NUM_SEGMENTS] =
{
	0,   // Segment A
	1,   // Segment B
	4,   // Segment C
	5,   // Segment D
	6,   // Segment E
	7,   // Segment F
	8,   // Segment G
};

const byte pinmap_digits[NUM_DIGITS] =
{
	9,    // Digit 1
	10,   // Digit 2
	14,   // Digit 3
	15,   // Digit 4
	16,   // Digit 5
};

/* *************************************************** */
/* CODE */
/* *************************************************** */

// the setup routine runs once when you press reset:
void setup()
{
  // Setup external pins for the BARs across the top
  for (int i = 0; i < 5; i++)
  {
    pinMode( pinmap_bars[i], OUTPUT);
    digitalWrite(pinmap_bars[i], HIGH);
  }

  // Setup external pins for the segemnt data
  for (int i = 0; i < 7; i++)
  {
    pinMode( pinmap_segments[i], OUTPUT);
    digitalWrite(pinmap_segments[i], HIGH);
  }

  // Setup external pins for the segment selector
  for (int i = 0; i < 5; i++)
  {
    pinMode( pinmap_digits[i], OUTPUT);
    digitalWrite(pinmap_digits[i], LOW);
  }
}

// Walks through the entire sentence, word by word, repeating each word
//   multiple times so that they mind perceives a roughly two second delay
//   between each new word before the loop starts again.
void loop()
{
  uint16_t charIdx = 0;
  uint16_t barIdx = 0;

  // Repeat each word to meet the desired update frequency (300 = ~2 seconds)
  for ( uint32_t idxDelay = 0; idxDelay < NUM_LOOPS_PER_WORD; idxDelay++)
  {
    barIdx  = (idxDelay>>BAR_ANIMATION_SPEED_DIVIDER)  % BAR_SEQ_SIZE;
    charIdx = (idxDelay>>CHAR_ANIMATION_SPEED_DIVIDER) % CHAR_SEQUENCE_SIZE;
    
    bar_test ( barIdx  );
    word_test( charIdx ) ;
  }
}

// Walks through each character in the specified word index, delaying
//   only 1/10th of a second between characters as to allow the mind
//   to see the letter even though it's on only 1/5 of the time.
void word_test(int idxWord )
{
  // Now, let's work on the word we would like to display
  for( int character = 0 ; character < NUM_DIGITS; character++ )
  {
    int charValue = char_sequence[idxWord][character] ;

    // Setup the character on the data lines first
    for( int segment = 0 ; segment < NUM_SEGMENTS; segment++ )
      digitalWrite( pinmap_segments[segment], ( charValue >> segment ) & 1 ) ;

    // Turn the character on
    digitalWrite( pinmap_digits[character],   HIGH);

    delay(0);

    // Turn the character off
    digitalWrite( pinmap_digits[character],   LOW);
  }

}

void bar_test(int index)
{
  static int old_index = 0;
  if(index != old_index)
  {
    digitalWrite( pinmap_bars[bar_sequence[old_index]], BAR_OFF);
    digitalWrite( pinmap_bars[bar_sequence[index]],     BAR_ON);
    old_index = index;
  }
}
