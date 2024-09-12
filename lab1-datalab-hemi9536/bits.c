/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 *  Henry Miller, hemi9536
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically and a negative shift value results in zero.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES, FOLLOW THE DIRECTIONS in README.md
 */


#endif
/* Copyright (C) 1991-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
  return ~(~x | ~y); // De Morgan Law, flip both inputs and | them together, and then flip that number to equate to the & operation
}
/* 
 * evenBits - return word with all even-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int evenBits(void) {
  int a = 0x55; // creates 8 bit even number
  int b;
  a = a << 8; // shift by 8 makes it a 16 bit number
  a += 0x55; // now its a 16 bit all even bit number (0x5555)
  b = a;
  a = a << 16; // similar process, now a 32 bit number
  return a + b; // adding 16 bit even bit number ontop of 32 bit number, returns 0x55555555
}
/*
 * isTmin - returns 1 if x is the minimum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmin(int x) {
  // !!x reduces to either 1 (if x was nonzero) or 0 (if x was 0)
  // ~x inverts x (0x7FFFFFFF <-> 0x80000000, 0x00000000 <-> 0xFFFFFFFF)
  // 0x7FFFFFFF: ~0x7FFFFFFF + !!0x7FFFFFFF = 0x80000000 + 1 = 0x80000001, 0x7FFFFFFF ^ 0x80000001 = 0xFFFFFFFE, !0xFFFFFFFE = 0 (false)
  // 0x80000000: ~0x80000000 + !!0x80000000 = 0x7FFFFFFF + 1 = 0x80000000, 0x80000000 ^ 0x80000000 = 0x00000000, !0x00000000 = 1 (true)
  // 0x00000000: ~0x00000000 + !!0x00000000 = 0xFFFFFFFF + 0 = 0xFFFFFFFF, 0x00000000 ^ 0xFFFFFFFF = 0xFFFFFFFF, !0xFFFFFFFF = 0 (false)  
  // The only reason we add !!x is so we don't add 1 in the case where 0 is passed in.
  // Anytime the result from (~x + !!x) equals the value passed into us, we have the minimum integer.
  // !(x ^ y) is the same as saying (x == y). Returning (x == (~x + !!x)) would also work.
  return !(x ^ (~x + !!x)); 
}
/* 
 * allEvenBits - return 1 if all even-numbered bits in word set to 1
 *   Examples allEvenBits(0xFFFFFFFE) = 0, allEvenBits(0x55555555) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allEvenBits(int x) {
  int a = 0x55;
  int b;
  a = a << 8;
  a += 0x55;
  b = a;
  a = a << 16;
  a += b; // same process as evenBits, making a 32 bit all even number

  x = x & a; // gets rid of excess odd bits
  x = x ^ a; // if all even bits are 1, xor will set them to 0 and get a number that is 0,
  // any even bit that isn't 1 will pass through xor and final number will not be 0.

  return !(x); // return logical not of x so if any bits got through xor it wil return 0.
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
  n = n << 3; // shifting left by 3 is equivalent to multiplying by 8
  x = x >> n; // moving n * 3 number of bits to the right to put the byte at the rightmost spot
  return x & 0xff; // masking the bits we are at because it cuts off after checking 8 bits
}
/* 
 * isNegative - return 1 if x < 0, return 0 otherwise 
 *   Example: isNegative(-1) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNegative(int x) {
  x = x >> 31; // brings the 32nd bit to the right
  return x & 0x1; // mask the 32nd bit to see if its negative or positive 
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  // use ! so that if x is 0 it will change to 1, and if its nonzero it will change to 0.
  // Then get the rightmost digit and move it back to the leftmost spot, replacing all 1's with 0's.
  // >> is sign-extended, so it fills the integer with 1's if the high bit was a 1.
  // When done, if x was 0 it will change to 0xFFFFFFFF, and if it was nonzero it will change to 0x00000000.
  x = (!x << 31) >> 31;
  // Then, if x is non zero, it will be 0, so flip it to 1 and use & to repeat the number y.
  // Otherwise, if x is 0, the value will be 1 so you & with z to return only what z is.
  return (~x & y) | (x & z);
}
/*
 * ezThreeFourths - multiplies by 3/4 rounding toward 0,
 *   Should exactly duplicate effect of C expression (x*3/4),
 *   including overflow behavior.
 *   Examples: ezThreeFourths(11) = 8
 *             ezThreeFourths(-9) = -6
 *             ezThreeFourths(1073741824) = -268435456 (overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 3
 */
int ezThreeFourths(int x) {

  int a;
  x += x + x;
  a = (x >> 31) & 0x3; // Include bias if negative so it rounds towards 0
  // The bias should always be 1 less than what you are dividing by, that way you are adding just under 1 to the final result.
  return ((x + a) >> 2); // divide total by 4
}
/* 
 * isNonNegative - return 1 if x >= 0, return 0 otherwise 
 *   Example: isNonNegative(-1) = 0.  isNonNegative(0) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 3
 */
int isNonNegative(int x) {
  x = x >> 31; // get the sign bit - all negative numbers will get 0xFFFFFFFF
  return !(x & 1); // mask with 1, if it is negative then return 0 if positive return 1
}
/* 
 * isNonZero - Check whether x is nonzero using
 *              the legal operators except !
 *   Examples: isNonZero(3) = 1, isNonZero(0) = 0
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4 
 */
int isNonZero(int x) {
  // If x is 0, then (~x + 1) will overflow it to 0, while if x is non-zero, (~x + 1) will just add 1 to the number.
  // When you | x and ~x, any nonzero number will be mostly 1's, with the sign bit always being 1. The only case where
  // the sign bit isn't 1 is when x = 0 because adding 1 to ~x will overflow back to 0. Then you take the sign bit and mask with
  // 1, so if x is 0 it will return 0, otherwise it will return 1.
  return ((x | (~x + 1)) >> 31) & 1;
}
/*
 * leftBitCount - returns count of number of consective 1's in
 *     left-hand (most significant) end of word.
 *   Examples: leftBitCount(-1) = 32, leftBitCount(0xFFF0F0F0) = 12
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 50
 *   Rating: 4
 */
int leftBitCount(int x) {
  int a = 0;
  int check;
  int shift;

  // Check to see if the top 16 bits are set. If so, we add 16 to our tally and shift them off.
  check = !((x >> 16) + 1); // Check will be 1 if 0xFFFF....
  shift = check << 4;       // shift will be 16 (if 0xFFFF....) or 0
  x = x << shift;           // x will be 0x....0000 (if 0xFFFF....) or unchanged
  a += shift;               // Add 16 to a (if 0xFFFF....) or add 0

  // Check to see if the top 8 bits are set. If so, we add 8 to our tally and shift them off.
  check = !((x >> 24) + 1);
  shift = check << 3;
  x = x << shift;
  a += shift;

  // Check to see if the top 4 bits are set. If so, we add 4 to our tally and shift them off.
  check = !((x >> 28) + 1);
  shift = check << 2;
  x = x << shift;
  a += shift;

  // Check to see if the top 2 bits are set. If so, we add 2 to our tally and shift them off.
  check = !((x >> 30) + 1);
  shift = check << 1;
  x = x << shift;
  a += shift;

  // Check to see if the top 1 bit is set. If so, we add 1 to our tally and shift it off.
  check = !((x >> 31) + 1);
  shift = check;
  x = x << shift;
  a += shift;

  // Return our tally plus 1 more if the last bit is set.
  return (a + ((x >> 31) & 1));
}
/*
 * trueThreeFourths - multiplies by 3/4 rounding toward 0,
 *   avoiding errors due to overflow
 *   Examples: trueThreeFourths(11) = 8
 *             trueThreeFourths(-9) = -6
 *             trueThreeFourths(1073741824) = 805306368 (no overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int trueThreeFourths(int x)
{
  int sign = x >> 31; // 1 for negative, 0 for positive
  int edge = x & 0x3; // Capture the rightmost two bits (before we chop them off when we divide)

  // Divide x by 4 first (to help prevent overflow when multiplying by 3)
  x = x >> 2;

  // Multiple x by 3
  x = x + (x << 1);

  // Let's not forget the two bits we chopped off.
  // Multiple the 2 edge bits we chopped off by 3: edge + (edge << 1)
  // Add in the sign bias to ensure we round towards 0
  // Divide all that by 4 and add it to x.
  return x + ((edge + (edge << 1) + (sign & 0x3)) >> 2);

  // Tmax: 0111 1111
  //     + 0000 0001
  //     = 1000 0000
}
/*
 * Extra credit
 */
/* 
 * float_abs - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_abs(unsigned uf) {
  
  return 2;
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
  return 2;
}
