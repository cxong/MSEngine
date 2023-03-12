/* == LLASSET.HPP ========================================================== */
/* ######################################################################### */
/* ## MS-ENGINE              Copyright (c) MS-Design, All Rights Reserved ## */
/* ######################################################################### */
/* ## Defines the 'Asset' namespace and methods for the guest to use in   ## */
/* ## Lua. This file is invoked by 'lualib.hpp'.                          ## */
/* ######################################################################### */
/* ------------------------------------------------------------------------- */
#pragma once                           // Only one incursion allowed
/* ========================================================================= */
/* ######################################################################### */
/* ========================================================================= */
// % Asset
/* ------------------------------------------------------------------------- */
// ! The Asset class allows the programmer to load files from disk for personal
// ! use and manipulation of that data with codecs or manually by the
// ! programmer.
/* ========================================================================= */
LLNAMESPACEBEGIN(Asset)                // Asset namespace
/* -- Includes ------------------------------------------------------------- */
using namespace IfAsset;               // Using asset namespace
using namespace IfLuaCode;             // Using luacode namespace
/* ========================================================================= */
/* ######################################################################### */
/* ========================================================================= */
// $ Asset:WriteInt
// > Position:integer=Position to write the integer to in the array.
// > Value:integer=Integer to write to the array.
// ? Writes the specified integer at the specified position in the array.
// ?
// ? Actual functions (replace 'WriteInt' with one of the following)...
// ? - WI16   = Writes a 16-bit signed integer to the specified position.
// ? - WI16BE = Same as WI16 but forces the return value to big-endian.
// ? - WI16LE = Same as WI16 but forces the return value to little-endian.
// ? - WI32   = Writes a 32-bit signed integer to the specified position.
// ? - WI32BE = Same as WI32 but forces the return value to big-endian.
// ? - WI32LE = Same as WI32 but forces the return value to little-endian.
// ? - WI64   = Writes a 64-bit signed integer to the specified position.
// ? - WI64BE = Same as WI64 but forces the return value to big-endian.
// ? - WI64LE = Same as WI64 but forces the return value to little-endian.
// ? - WI8    = Writes an 8-bit signed integer to the specified position.
// ? - WU16   = Writes a 16-bit unsigned integer to the specified position.
// ? - WU16BE = Same as WU16 but forces the return value to big-endian.
// ? - WU16LE = Same as WU16 but forces the return value to little-endian.
// ? - WU32   = Writes a 32-bit unsigned integer to the specified position.
// ? - WU32BE = Same as WU32 but forces the return value to big-endian.
// ? - WU32LE = Same as WU32 but forces the return value to little-endian.
// ? - WU64   = Writes a 64-bit unsigned integer to the specified position.
// ? - WU64BE = Same as WU64 but forces the return value to big-endian.
// ? - WU64LE = Same as WU64 but forces the return value to little-endian.
// ? - WU8    = Writes an 8-bit unsigned integer to the specified position.
/* ------------------------------------------------------------------------- */
LLFUNCTEMPLATE(WriteI, LCGETPTR(1, Asset)->
  WriteInt<T>(LCGETINT(size_t, 2, "Position"), LCGETINT(T, 3, "Value")));
LLFUNCTEMPLATE(WI16LE, LCGETPTR(1, Asset)->
  WriteIntLE<T>(LCGETINT(size_t, 2, "Position"), LCGETINT(T, 3, "Value")));
LLFUNCTEMPLATE(WI16BE, LCGETPTR(1, Asset)->
  WriteIntBE<T>(LCGETINT(size_t, 2, "Position"), LCGETINT(T, 3, "Value")));
LLFUNCTEMPLATE(WI32LE, LCGETPTR(1, Asset)->
  WriteIntLE<T>(LCGETINT(size_t, 2, "Position"), LCGETINT(T, 3, "Value")));
LLFUNCTEMPLATE(WI32BE, LCGETPTR(1, Asset)->
  WriteIntBE<T>(LCGETINT(size_t, 2, "Position"), LCGETINT(T, 3, "Value")));
LLFUNCTEMPLATE(WI64LE, LCGETPTR(1, Asset)->
  WriteIntLE<T>(LCGETINT(size_t, 2, "Position"), LCGETINT(T, 3, "Value")));
LLFUNCTEMPLATE(WI64BE, LCGETPTR(1, Asset)->
  WriteIntBE<T>(LCGETINT(size_t, 2, "Position"), LCGETINT(T, 3, "Value")));
/* ========================================================================= */
// $ Asset:WriteNum
// > Position:integer=Position to write the number to in the array.
// > Value:number=Number to write at the specified position
// ? Writes the specified number at the specified position in the array.
// ?
// ? Actual functions (replace 'WriteNum' with one of the following)...
// ? - RF32   = Writes a 32-bit IEEE754 number to the specified position.
// ? - RF32BE = Same as RF32 but forces the specified value to big-endian.
// ? - RF32LE = Same as RF32 but forces the specified value to little-endian.
// ? - RF64   = Writes a 64-bit IEEE754 number to the specified position.
// ? - RF64BE = Same as RF64 but forces the specified value to big-endian.
// ? - RF64LE = Same as RF64 but forces the specified value to little-endian.
/* ------------------------------------------------------------------------- */
LLFUNCTEMPLATE(WriteN, LCGETPTR(1, Asset)->
  WriteInt<T>(LCGETINT(size_t, 2, "Position"), LCGETNUM(T, 3, "Value")));
LLFUNC(WF32BE, LCGETPTR(1, Asset)->
  WriteFloatBE(LCGETINT(size_t, 2, "Position"), LCGETNUM(float, 3, "Value")));
LLFUNC(WF32LE, LCGETPTR(1, Asset)->
  WriteFloatLE(LCGETINT(size_t, 2, "Position"), LCGETNUM(float, 3, "Value")));
LLFUNC(WF64BE, LCGETPTR(1, Asset)->
  WriteDoubleBE(LCGETINT(size_t, 2, "Position"),LCGETNUM(double, 3, "Value")));
LLFUNC(WF64LE, LCGETPTR(1, Asset)->
  WriteDoubleLE(LCGETINT(size_t, 2, "Position"),LCGETNUM(double, 3, "Value")));
/* ========================================================================= */
// $ Asset:ReadInt
// > Position:integer=Position to write in the array.
// < Value:integer=Integer value at the specified position.
// ? Reads the specified integer at the specified position in the array.
// ?
// ? Actual functions (replace 'ReadInt' with one of the following)...
// ? - RI16   = Reads a 16-bit signed integer from the specified position.
// ? - RI16BE = Same as RI16 but forces the return value to big-endian.
// ? - RI16LE = Same as RI16 but forces the return value to little-endian.
// ? - RI32   = Reads a 32-bit signed integer from the specified position.
// ? - RI32BE = Same as RI32 but forces the return value to big-endian.
// ? - RI32LE = Same as RI32 but forces the return value to little-endian.
// ? - RI64   = Reads a 64-bit signed integer from the specified position.
// ? - RI64BE = Same as RI64 but forces the return value to big-endian.
// ? - RI64LE = Same as RI64 but forces the return value to little-endian.
// ? - RI8    = Reads a 8-bit signed integer from the specified position.
// ? - RU16   = Reads a 16-bit unsigned integer from the specified position.
// ? - RU16BE = Same as RU16 but forces the return value to big-endian.
// ? - RU16LE = Same as RU16 but forces the return value to little-endian.
// ? - RU32   = Reads a 32-bit unsigned integer from the specified position.
// ? - RU32BE = Same as RU32 but forces the return value to big-endian.
// ? - RU32LE = Same as RU32 but forces the return value to little-endian.
// ? - RU64   = Reads a 64-bit unsigned integer from the specified position.
// ? - RU64BE = Same as RU64 but forces the return value to big-endian.
// ? - RU64LE = Same as RU64 but forces the return value to little-endian.
// ? - RU8    = Reads a 8-bit unsigned integer from the specified position.
/* ------------------------------------------------------------------------- */
LLFUNCTEMPLATEEX(ReadI, 1, LCPUSHINT(
  LCGETPTR(1, Asset)->ReadInt<T>(LCGETINT(size_t, 2, "Position"))));
LLFUNCTEMPLATEEX(RI16LE, 1, LCPUSHINT(ToI16LE(
  LCGETPTR(1, Asset)->ReadInt<T>(LCGETINT(size_t, 2, "Position")))));
LLFUNCTEMPLATEEX(RI16BE, 1, LCPUSHINT(ToI16BE(
  LCGETPTR(1, Asset)->ReadInt<T>(LCGETINT(size_t, 2, "Position")))));
LLFUNCTEMPLATEEX(RI32LE, 1, LCPUSHINT(ToI32LE(
  LCGETPTR(1, Asset)->ReadInt<T>(LCGETINT(size_t, 2, "Position")))));
LLFUNCTEMPLATEEX(RI32BE, 1, LCPUSHINT(ToI32BE(
  LCGETPTR(1, Asset)->ReadInt<T>(LCGETINT(size_t, 2, "Position")))));
LLFUNCTEMPLATEEX(RI64LE, 1, LCPUSHINT(ToI64LE(
  LCGETPTR(1, Asset)->ReadInt<T>(LCGETINT(size_t, 2, "Position")))));
LLFUNCTEMPLATEEX(RI64BE, 1, LCPUSHINT(ToI64BE(
  LCGETPTR(1, Asset)->ReadInt<T>(LCGETINT(size_t, 2, "Position")))));
/* ========================================================================= */
// $ Asset:WriteInt
// > Position:integer=Position to swap the bytes at
// ? Swaps the high/low order bits at the specified position.
// ?
// ? Actual functions (replace 'WriteInt' with one of the following)...
// ? - S8     = Swaps high/low 4-bits
// ? - S16    = Swaps high/low 8-bits
// ? - S32    = Swaps high/low 16-bits
// ? - S64    = Swaps high/low 32-bits
/* ------------------------------------------------------------------------- */
LLFUNC(S8, LCGETPTR(1, Asset)->Swap8(LCGETINT(size_t, 2, "Position")));
LLFUNC(S16, LCGETPTR(1, Asset)->Swap16(LCGETINT(size_t, 2, "Position")));
LLFUNC(S32, LCGETPTR(1, Asset)->Swap32(LCGETINT(size_t, 2, "Position")));
LLFUNC(S64, LCGETPTR(1, Asset)->Swap64(LCGETINT(size_t, 2, "Position")));
/* ========================================================================= */
// $ Asset:ReadNum
// > Position:integer=Position to write the number to in the array.
// < Value:number=Number read at the specified position
// ? Reads the specified number at the specified position in the array.
// ?
// ? Actual functions (replace 'ReadNum' with one of the following)...
// ? - RF32   = Reads a 32-bit IEEE754 number from the specified position.
// ? - RF32BE = Same as RF32 but forces the return value to big-endian.
// ? - RF32LE = Same as RF32 but forces the return value to little-endian.
// ? - RF64   = Reads a 64-bit IEEE754 number from the specified position.
// ? - RF64BE = Same as RF64 but forces the return value to big-endian.
// ? - RF64LE = Same as RF64 but forces the return value to little-endian.
/* ------------------------------------------------------------------------- */
LLFUNCTEMPLATEEX(ReadN, 1, LCPUSHNUM(static_cast<lua_Number>(
  LCGETPTR(1, Asset)->ReadInt<T>(LCGETINT(size_t, 2, "Position")))));
LLFUNCEX(RF32LE, 1, LCPUSHNUM(static_cast<lua_Number>(
  CastInt32ToFloat(ToI32LE(LCGETPTR(1, Asset)->
    ReadInt<uint32_t>(LCGETINT(size_t, 2, "Position")))))));
LLFUNCEX(RF32BE, 1, LCPUSHNUM(static_cast<lua_Number>(
  CastInt32ToFloat(ToI32BE(LCGETPTR(1, Asset)->
    ReadInt<uint32_t>(LCGETINT(size_t, 2, "Position")))))));
LLFUNCEX(RF64LE, 1, LCPUSHNUM(static_cast<lua_Number>(
  CastInt64ToDouble(ToI64LE(LCGETPTR(1, Asset)->
    ReadInt<uint64_t>(LCGETINT(size_t, 2, "Position")))))));
LLFUNCEX(RF64BE, 1, LCPUSHNUM(static_cast<lua_Number>(
  CastInt64ToDouble(ToI64BE(LCGETPTR(1, Asset)->
    ReadInt<uint64_t>(LCGETINT(size_t, 2, "Position")))))));
/* ========================================================================= */
// $ Asset:Resize
// > Size:integer=The new size of the array in bytes.
// ? Resizes the specified array.
/* ------------------------------------------------------------------------- */
LLFUNC(Resize,
  LCGETPTR(1, Asset)->Resize(LCGETINTLG(size_t, 2, 0, UINT_MAX, "Size")));
/* ========================================================================= */
// $ Asset:ResizeUp
// > Size:integer=The new size of the array in bytes.
// ? Resizes the specified array upwards, but never downwards
/* ------------------------------------------------------------------------- */
LLFUNC(ResizeUp,
  LCGETPTR(1, Asset)->ResizeUp(LCGETINTLG(size_t, 2, 0, UINT_MAX, "Size")));
/* ========================================================================= */
// $ Asset:Fill
// > Char:integer=ASCII character
// ? Fills the buffer with the specified character
/* ------------------------------------------------------------------------- */
LLFUNC(Fill,
  LCGETPTR(1, Asset)->Fill(LCGETINTLG(uint8_t, 2, 0, UCHAR_MAX, "Character")));
/* ========================================================================= */
// $ Asset:Clear
// ? Same as Asset:Fill but automatically assumes zero fill.
/* ------------------------------------------------------------------------- */
LLFUNC(Clear, LCGETPTR(1, Asset)->Fill());
/* ========================================================================= */
// $ Asset:Reverse
// ? Completely reverses all the bytes in the array.
/* ------------------------------------------------------------------------- */
LLFUNC(Reverse, LCGETPTR(1, Asset)->Reverse());
/* ========================================================================= */
// $ Asset:ToString
// < Text:string=The array converted to a string.
// ? Converts the array to a string. This is binary safe but will obviously
// ? terminate at the first null character or at the end of array, whichever
// ? comes first.
/* ------------------------------------------------------------------------- */
LLFUNCEX(ToString, 1, LCPUSHXSTR(LCGETPTR(1, Asset)->ToString()));
/* ========================================================================= */
// $ Asset:ToFile
// > Filename:string=Filename to write to.
// < Bytes:integer=Number of bytes written.
// ? Dumps the array to the specified file on disk. Useful for debugging.
/* ------------------------------------------------------------------------- */
LLFUNCEX(ToFile, 1,
  LCPUSHINT(FStream(LCGETCPPFILE(2, "File"), FStream::FM_W_B).
    FStreamWriteBlock(*LCGETPTR(1, Asset))));
/* ========================================================================= */
// $ Asset:Size
// < Size:integer=Size of the array in bytes.
// ? Returns the size of the array.
/* ------------------------------------------------------------------------- */
LLFUNCEX(Size, 1, LCPUSHINT(LCGETPTR(1, Asset)->Size()));
/* ========================================================================= */
// $ Asset:Find
// > Text:string=String to find in array.
// < Position:integer=Position of occurence.
// ? Finds the first occurence of 'Text' in array from the beginning.
/* ------------------------------------------------------------------------- */
LLFUNCEX(Find, 1, LCPUSHINT(LCGETPTR(1, Asset)->
  Find(LCGETCPPSTRINGNE(2, "String"))));
/* ========================================================================= */
// $ Asset:FindEx
// > Text:string=String to find in array.
// > Position:integer=Position to start checking for occurences.
// < Position:integer=Position of occurence.
// ? Finds the first occurence of 'Text' in array from the specified position.
/* ------------------------------------------------------------------------- */
LLFUNCEX(FindEx, 1, LCPUSHINT(LCGETPTR(1, Asset)->
  Find(LCGETCPPSTRINGNE(2, "String"), LCGETINT(size_t, 3, "Position"))));
/* ========================================================================= */
// $ Asset:Set
// > Position:integer=Position to start at.
// > Character:integer=Character to set.
// > Bytes:integer=Number of bytes to set.
// ? Fills the array with 'Character' at 'Position' for 'Bytes' bytes.
/* ------------------------------------------------------------------------- */
LLFUNC(Set, LCGETPTR(1, Asset)->FillEx(
  LCGETINT(size_t,        2, "Position"),
  LCGETINT(unsigned char, 3, "Character"),
  LCGETINT(size_t,        4, "Bytes")));
/* ========================================================================= */
// $ Asset:Crop
// > Position:integer=Position to start crop at.
// > Bytes:integer=Number of bytes to keep.
// < Output:Asset=A new asset block containing the cropped memory.
// ? Crops the specified array from the specified position and the specified
// ? number of bytes.
/* ------------------------------------------------------------------------- */
LLFUNC(Crop, LCGETPTR(1, Asset)->
  Crop(LCGETINT(size_t, 2, "Position"), LCGETINT(size_t, 3, "Bytes")));
/* ========================================================================= */
// $ Asset:BitClear
// > Position:integer=Position (in bits) to clear the bit from.
// ? Clears the bit at the specified position. Remember this is the bit
// ? position and not a byte position.
/* ------------------------------------------------------------------------- */
LLFUNC(BitClear,
  LCGETPTR(1, Asset)->BitClear(LCGETINT(size_t, 2, "Position")));
/* ========================================================================= */
// $ Asset:BitFlip
// > Position:integer=Position (in bits) to flip the bit from.
// ? Flips the bit at the specified position. Remember this is the bit
// ? position and not a byte position.
/* ------------------------------------------------------------------------- */
LLFUNC(BitFlip,
  LCGETPTR(1, Asset)->BitFlip(LCGETINT(size_t, 2, "Position")));
/* ========================================================================= */
// $ Asset:BitSet
// > Position:integer=Position (in bits) to set the bit from.
// ? Sets the bit at the specified position. Remember this is the bit
// ? position and not a byte position.
/* ------------------------------------------------------------------------- */
LLFUNC(BitSet,
  LCGETPTR(1, Asset)->BitSet(LCGETINT(size_t, 2, "Position")));
/* ========================================================================= */
// $ Asset:BitTest
// > Position:integer=Position (in bits) to set the bit from.
// < Set:boolean=Boolean to show if the bit is set or not.
// ? Sets the bit at the specified position. Remember this is the bit
// ? position and not a byte position.
/* ------------------------------------------------------------------------- */
LLFUNCEX(BitState, 1,
  LCPUSHBOOL(LCGETPTR(1, Asset)->BitTest(LCGETINT(size_t, 2, "Position"))));
/* ========================================================================= */
// $ Asset:Invert
// > Position:integer=Position to invert.
// > Bits:integer=Bits to invert (I*F functions only, all bits otherwise).
// ? Flips the specified bits at the specified position.
// ?
// ? Actual functions (Replace 'I*' with one of the following)...
// ? - I8     = Inverts bits 0-7 at the specified position.
// ? - I8F    = Inverts specified bits between 0-7 at the specified position.
// ? - I16    = Inverts bits 0-15 at the specified position.
// ? - I16F   = Inverts specified bits between 0-15 at the specified position.
// ? - I16FBE = Same as I16F but forces the specified bits to be big-endian.
// ? - I16FLE = Same as I16F but forces the specified bits to be litten-endian.
// ? - I32    = Inverts bits 0-31 at the specified position.
// ? - I32F   = Inverts specified bits between 0-32 at the specified position.
// ? - I32FBE = Same as I32F but forces the specified bits to be big-endian.
// ? - I32FLE = Same as I32F but forces the specified bits to be litten-endian.
// ? - I64    = Inverts bits 0-63 at the specified position.
// ? - I64F   = Inverts specified bits between 0-63 at the specified position.
// ? - I64FBE = Same as I64F but forces the specified bits to be big-endian.
// ? - I64FLE = Same as I64F but forces the specified bits to be litten-endian.
/* ------------------------------------------------------------------------- */
LLFUNCTEMPLATE(Invert,
  LCGETPTR(1, Asset)->Invert<T>(LCGETINT(size_t, 2, "Position")));
LLFUNCTEMPLATE(InvertEx, LCGETPTR(1, Asset)->Invert<T>(
  LCGETINT(size_t, 2, "Position"), LCGETINT(T, 3, "Bits")));
LLFUNC(I16FBE, LCGETPTR(1, Asset)->Invert<uint16_t>(LCGETINT(size_t, 2,
  "Position"), ToI16BE(LCGETINT(uint16_t, 3, "Bits"))));
LLFUNC(I16FLE, LCGETPTR(1, Asset)->Invert<uint16_t>(LCGETINT(size_t, 2,
  "Position"), ToI16LE(LCGETINT(uint16_t, 3, "Bits"))));
LLFUNC(I32FBE, LCGETPTR(1, Asset)->Invert<uint32_t>(LCGETINT(size_t, 2,
  "Position"), ToI32BE(LCGETINT(uint32_t, 3, "Bits"))));
LLFUNC(I32FLE, LCGETPTR(1, Asset)->Invert<uint32_t>(LCGETINT(size_t, 2,
  "Position"), ToI32LE(LCGETINT(uint32_t, 3, "Bits"))));
LLFUNC(I64FBE, LCGETPTR(1, Asset)->Invert<uint64_t>(LCGETINT(size_t, 2,
  "Position"), ToI64BE(LCGETINT(uint64_t, 3, "Bits"))));
LLFUNC(I64FLE, LCGETPTR(1, Asset)->Invert<uint64_t>(LCGETINT(size_t, 2,
  "Position"), ToI64LE(LCGETINT(uint64_t, 3, "Bits"))));
/* ========================================================================= */
// $ Asset:Name
// < Name:string=Name of the asset.
// ? If this asset was loaded by a filename or it was set with a custom id.
// ? This function returns that name which was assigned to it.
/* ------------------------------------------------------------------------- */
LLFUNCEX(Name, 1, LCPUSHXSTR(LCGETPTR(1, Asset)->IdentGet()));
/* ========================================================================= */
// $ Asset:Destroy
// ? Frees the internal memory allocated to the asset. The object will no
// ? longer be useable after this call and an error will be generated if
// ? accessed.
/* ------------------------------------------------------------------------- */
LLFUNC(Destroy, LCCLASSDESTROY(1, Asset));
/* ========================================================================= */
/* ######################################################################### */
/* ## Asset:* member functions structure                                  ## */
/* ######################################################################### */
/* ------------------------------------------------------------------------- */
LLRSMFBEGIN                            // Asset:* member functions begin
  LLRSFUNC  (BitClear),                // Clear the specified bit
  LLRSFUNC  (BitFlip),                 // Flip the specified bit
  LLRSFUNC  (BitSet),                  // Set the specified bit
  LLRSFUNC  (BitState),                // Return if the specified bit is set
  LLRSFUNC  (Clear),                   // Clear array with specified char
  LLRSFUNC  (Crop),                    // Crop (resize both ends) block
  LLRSFUNC  (Destroy),                 // Destroy the internal asset object
  LLRSFUNC  (Fill),                    // Fill entire array with specified char
  LLRSFUNC  (Find),                    // Find first string in array
  LLRSFUNC  (FindEx),                  //  " from the specified position
  LLRSFUNCEX(I16, Invert<uint16_t>),   // Invert 16-bit int bits
  LLRSFUNCEX(I16F, InvertEx<uint16_t>),//  " specific bits
  LLRSFUNC  (I16FLE),                  //  " " (little endian)
  LLRSFUNC  (I16FBE),                  //  " " (big endian)
  LLRSFUNCEX(I32, Invert<uint32_t>),   // Invert 32-bit int bits
  LLRSFUNCEX(I32F, InvertEx<uint32_t>),//  " specific bits
  LLRSFUNC  (I32FLE),                  //  " " (little endian)
  LLRSFUNC  (I32FBE),                  //  " " (big endian)
  LLRSFUNCEX(I64, Invert<uint64_t>),   // Invert 64-bit int bits
  LLRSFUNCEX(I64F, InvertEx<uint64_t>),//  " specific bits
  LLRSFUNC  (I64FLE),                  //  " " (little endian)
  LLRSFUNC  (I64FBE),                  //  " " (big endian)
  LLRSFUNCEX(I8, Invert<uint8_t>),     // Invert 8-bit int bits
  LLRSFUNCEX(I8F, InvertEx<uint8_t>),  //  " specific bits
  LLRSFUNC  (Name),                    // Return filename associated with this
  LLRSFUNCEX(RF32, ReadN<float>),      // Read 32-bit IEEE754 float
  LLRSFUNC  (RF32BE),                  // " 32-bit float BE
  LLRSFUNC  (RF32LE),                  // " 32-bit float LE
  LLRSFUNCEX(RF64, ReadN<double>),     // " 64-bit IEEE754 float
  LLRSFUNC  (RF64BE),                  // " 64-bit float BE
  LLRSFUNC  (RF64LE),                  // " 64-bit float LE
  LLRSFUNCEX(RI16, ReadI<int16_t>),    // " 16-bit signed integer
  LLRSFUNCEX(RI16BE, RI16BE<int16_t>), // " 16-bit signed integer BE
  LLRSFUNCEX(RI16LE, RI16LE<int16_t>), // " 16-bit signed integer LE
  LLRSFUNCEX(RI32, ReadI<int32_t>),    // " 32-bit signed integer
  LLRSFUNCEX(RI32BE, RI32BE<int32_t>), // " 32-bit signed integer BE
  LLRSFUNCEX(RI32LE, RI32LE<int32_t>), // " 32-bit signed integer LE
  LLRSFUNCEX(RI64, ReadI<int64_t>),    // " 64-bit signed integer
  LLRSFUNCEX(RI64BE, RI64BE<int64_t>), // " 64-bit signed integer BE
  LLRSFUNCEX(RI64LE, RI64LE<int64_t>), // " 64-bit signed integer LE
  LLRSFUNCEX(RI8, ReadI<int8_t>),      // " 8-bit signed integer
  LLRSFUNCEX(RU16, ReadI<uint16_t>),   // " 16-bit unsigned integer
  LLRSFUNCEX(RU16BE, RI16BE<uint16_t>),// " 16-bit unsigned integer BE
  LLRSFUNCEX(RU16LE, RI16LE<uint16_t>),// " 16-bit unsigned integer LE
  LLRSFUNCEX(RU32, ReadI<uint32_t>),   // " 32-bit unsigned integer
  LLRSFUNCEX(RU32BE, RI32BE<uint32_t>),// " 32-bit unsigned integer BE
  LLRSFUNCEX(RU32LE, RI32LE<uint32_t>),// " 32-bit unsigned integer LE
  LLRSFUNCEX(RU64, ReadI<uint64_t>),   // " 64-bit unsigned integer
  LLRSFUNCEX(RU64BE, RI64BE<uint64_t>),// " 64-bit unsigned integer BE
  LLRSFUNCEX(RU64LE, RI64LE<uint64_t>),// " 64-bit unsigned integer LE
  LLRSFUNCEX(RU8, ReadI<uint8_t>),     // " 8-bit unsigned integer
  LLRSFUNC  (Resize),                  // Resize data array
  LLRSFUNC  (ResizeUp),                // Resize data array (only upwards)
  LLRSFUNC  (Reverse),                 // Reverse data array
  LLRSFUNC  (Set),                     // Fill array with specific character
  LLRSFUNC  (Size),                    // Return size of array
  LLRSFUNC  (S8),                      // Swap high/low 4-bits of a 8-bit int
  LLRSFUNC  (S16),                     // Swap high/low 8-bits of a 16-bit int
  LLRSFUNC  (S32),                     // Swap high/low 16-bits of a 32-bit int
  LLRSFUNC  (S64),                     // Swap high/low 32-bits of a 64-bit int
  LLRSFUNC  (ToFile),                  // Dump data array to file
  LLRSFUNC  (ToString),                // Convert data array to string
  LLRSFUNCEX(WF32, WriteN<float>),     // Write 32b IEEE754 float
  LLRSFUNC  (WF32BE),                  // " 32-bit float BE
  LLRSFUNC  (WF32LE),                  // " 32-bit float LE
  LLRSFUNCEX(WF64, WriteN<double>),    // " 64-bit IEEE754 float
  LLRSFUNC  (WF64BE),                  // " 64-bit float BE
  LLRSFUNC  (WF64LE),                  // " 64-bit float LE
  LLRSFUNCEX(WI16, WriteI<int16_t>),   // " 16-bit signed integer
  LLRSFUNCEX(WI16BE, WI16BE<int16_t>), // " 16-bit signed integer BE
  LLRSFUNCEX(WI16LE, WI16LE<int16_t>), // " 16-bit signed integer LE
  LLRSFUNCEX(WI32, WriteI<int32_t>),   // " 32-bit signed integer
  LLRSFUNCEX(WI32BE, WI32BE<int32_t>), // " 32-bit signed integer BE
  LLRSFUNCEX(WI32LE, WI32LE<int32_t>), // " 32-bit signed integer LE
  LLRSFUNCEX(WI64, WriteI<int64_t>),   // " 64-bit signed integer
  LLRSFUNCEX(WI64BE, WI64BE<int64_t>), // " 64-bit signed integer BE
  LLRSFUNCEX(WI64LE, WI64LE<int64_t>), // " 64-bit signed integer LE
  LLRSFUNCEX(WI8, WriteI<int8_t>),     // " 8-bit signed integer
  LLRSFUNCEX(WU16, WriteI<uint16_t>) , // " 16-bit unsigned integer
  LLRSFUNCEX(WU16BE, WI16BE<uint16_t>),// " 16-bit unsigned integer BE
  LLRSFUNCEX(WU16LE, WI16LE<uint16_t>),// " 16-bit unsigned integer LE
  LLRSFUNCEX(WU32, WriteI<uint32_t>),  // " 32-bit unsigned integer
  LLRSFUNCEX(WU32BE, WI32BE<uint32_t>),// " 32-bit unsigned integer BE
  LLRSFUNCEX(WU32LE, WI32LE<uint32_t>),// " 32-bit unsigned integer LE
  LLRSFUNCEX(WU64, WriteI<uint64_t>),  // " 64-bit unsigned integer
  LLRSFUNCEX(WU64BE, WI64BE<uint64_t>),// " 64-bit unsigned integer BE
  LLRSFUNCEX(WU64LE, WI64LE<uint64_t>),// " 64-bit unsigned integer LE
  LLRSFUNCEX(WU8, WriteI<uint8_t>),    // " 8-bit unsigned integer
LLRSEND                                // Asset:* member functions end
/* ========================================================================= */
// $ Asset.Parse
// > Filename:string=The name of the file to parse
// > Returns:integer=The number of returns expected from the call.
// < Params...:*=The parameters the function returned
// ? Compiles and executes the specified string.
/* ------------------------------------------------------------------------- */
LLFUNCBEGIN(Parse)
LLFUNCENDEX(LuaCodeExecFileAndRets(lS,
  LCGETCPPFILE(1, "File"),
  LCGETINTLG  (int, 2, 0, numeric_limits<int>::max(), "Returns")
));
/* ========================================================================= */
// $ Asset.ParseBlock
// > Data:Asset=The data to execute
// > Returns:integer=The number of returns expected from the call.
// > Name:string=The name of the block to help identify the the source.
// < Params...:*=The parameters the function returned
// ? Compiles and executes the specified asset.
/* ------------------------------------------------------------------------- */
LLFUNCBEGIN(ParseBlock)
LLFUNCENDEX(LuaCodeExecBlockAndRets(lS,
 *LCGETPTR        (1, Asset),
  LCGETINTLG      (int, 2, 0, numeric_limits<int>::max(), "Returns"),
  LCGETCPPSTRINGNE(3, "Name")
));
/* ========================================================================= */
// $ Asset.ParseString
// > Code:string=The block of LUA code to execute.
// > Returns:integer=The number of returns expected from the call.
// > Name:string=The name of the string to help identify the the source.
// < Params...:*=The parameters the function returned
// ? Compiles and executes the specified string.
/* ------------------------------------------------------------------------- */
LLFUNCBEGIN(ParseString)
LLFUNCENDEX(LuaCodeExecStringAndRets(lS,
  LCGETCPPSTRING  (     1, "Code"),
  LCGETINTLG      (int, 2, 0, numeric_limits<int>::max(), "Returns"),
  LCGETCPPSTRINGNE(     3, "Name")
));
/* ========================================================================= */
// $ Asset.CompileFunction
// > Debug:boolean=Include debug data?
// > Function:function=The function to compile
// < Binary:Asset=The asset containing the compiled data
// ? Compiles the specified Lua function and returns the binary compiled data
/* ------------------------------------------------------------------------- */
LLFUNCEX(CompileFunction, 1, LuaCodeCompileFunction(lS));
/* ========================================================================= */
// $ Asset.Compile
// > Filename:string=The name of the file to parse
// < Params...:*=The parameters the function returned
// ? Compiles the specified file and returns the function
/* ------------------------------------------------------------------------- */
LLFUNCEX(Compile, 1, LuaCodeCompileFile(lS, LCGETCPPFILE(1, "File")));
/* ========================================================================= */
// $ Asset.CompileBlock
// > Data:Asset=The data to execute
// > Name:string=The name of the block to help identify the the source.
// < Function:function=The function
// ? Compiles the specified asset and returns the function
/* ------------------------------------------------------------------------- */
LLFUNCEX(CompileBlock, 1, LuaCodeCompileBlock(lS,
  *LCGETPTR(1, Asset),
  LCGETCPPSTRINGNE(2, "Name"))
);
/* ========================================================================= */
// $ Asset.CompileString
// > Code:string=The block of LUA code to compile.
// > Name:string=The name of the string to help identify the the source.
// < Function:function=The function
// ? Compiles the specified string and returns the function
/* ------------------------------------------------------------------------- */
LLFUNCEX(CompileString, 1, LuaCodeCompileString(lS,
  LCGETCPPSTRING(1, "Code"),
  LCGETCPPSTRINGNE(2, "Name")
));
/* ========================================================================= */
// $ Asset.FileExists
// > Filename:string=The name of the file to check
// < Status:boolean=Is the file availabe
// ? Checks if the specified file exists and is readable. The file is checked
// ? from the executable directory first and if not found or unable to open
// ? then the function traverses archives. Use this function to make sure
// ? exceptions aren't raised when loading files with any API function.
/* ------------------------------------------------------------------------- */
LLFUNCEX(FileExists, 1, LCPUSHBOOL(AssetExists(LCGETCPPFILE(1, "File"))));
/* ========================================================================= */
// $ Asset.Enumerate
// > Directory:string=The directory to scan (can only be exedir or below).
// > OnlyDir:string=Only enumerate directories.
// < Entries:table=The files or directories enumerated.
// ? Enumerates the list of files from the specified directory.
/* ------------------------------------------------------------------------- */
LLFUNCEX(Enumerate, 1, LCTOTABLE(AssetList{ LCGETCPPFILE(1, "Directory"),
  LCGETBOOL(2, "OnlyDirs") }.ToStrSet()));
/* ========================================================================= */
// $ Asset.EnumerateEx
// > Directory:string=The directory to scan (can only be exedir or below).
// > Extension:string=The extension of the files to filter.
// > OnlyDir:string=Only enumerate directories.
// < Entries:table=The files or directories enumerated.
// ? Enumerates the list of files from the specified directory.
/* ------------------------------------------------------------------------- */
LLFUNCEX(EnumerateEx, 1, LCTOTABLE(AssetList{ LCGETCPPFILE(1, "Directory"),
  LCGETCPPSTRING(2, "Extension"), LCGETBOOL(3, "OnlyDirs") }.ToStrSet()));
/* ========================================================================= */
// $ Asset.Create
// < Handle:Asset=Handle to the array cless.
// > Size:integer=Number of bytes of memory to allocate.
// ? Allocates the specified amount of system memory for you to read and write
// ? to. The memory is zero'd out after allocation for security reasons.
/* ------------------------------------------------------------------------- */
LLFUNCEX(Create, 1,
  LCCLASSCREATE(Asset)->InitSafe(LCGETINTLG(size_t, 1, 0, UINT_MAX, "Size")));
/* ========================================================================= */
// $ Asset.ArrayAsync
// > Id:string=The filename of the file load
// > Data:Asset=The data to process.
// > Flags:integer=Special operations to perform during load
// > ErrorFunc:function=The function to call when there is an error
// > ProgressFunc:function=The function to call when there is progress
// > SuccessFunc:function=The function to call when the file is laoded
// ? Loads an array off the main thread. The callback functions send an
// ? argument to the asset object that was created.
/* ------------------------------------------------------------------------- */
LLFUNC(AssetAsync, LCCLASSCREATE(Asset)->InitAsyncArray(lS));
/* ========================================================================= */
// $ Asset.StringAsync
// > Id:string=The filename of the file load
// > Text:String=The string to process.
// > Flags:integer=Special operations to perform during load
// > ErrorFunc:function=The function to call when there is an error
// > ProgressFunc:function=The function to call when there is progress
// > SuccessFunc:function=The function to call when the file is laoded
// ? Loads an array off the main thread. The callback functions send an
// ? argument to the asset object that was created.
/* ------------------------------------------------------------------------- */
LLFUNC(StringAsync, LCCLASSCREATE(Asset)->InitAsyncString(lS));
/* ========================================================================= */
// $ Asset.FileAsync
// > Filename:string=The filename of the file load
// > Flags:integer=Special operations to perform during load
// > ErrorFunc:function=The function to call when there is an error
// > ProgressFunc:function=The function to call when there is progress
// > SuccessFunc:function=The function to call when the file is laoded
// ? Loads a file off the main thread. The callback functions send an
// ? argument to the asset object that was created.
/* ------------------------------------------------------------------------- */
LLFUNC(FileAsync, LCCLASSCREATE(Asset)->InitAsyncFile(lS));
/* ========================================================================= */
// $ Asset.Exec
// > CmdLine:string=The command-line to execute
// > Flags:integer=Special operations to perform during load
// > ErrorFunc:function=The function to call when there is an error
// > ProgressFunc:function=The function to call when there is progress
// > SuccessFunc:function=The function to call when the file is laoded
// ? Executes the specified command-line, stores all the output and sends it
// ? for optional processing with the specified flags.
/* ------------------------------------------------------------------------- */
LLFUNC(Exec, LCCLASSCREATE(Asset)->InitAsyncCmdLine(lS));
/* ========================================================================= */
// $ Asset.ExecEx
// > CmdLine:string=The command-line to execute
// > Flags:integer=Special operations to perform during load
// > Input:Asset=The data to send to the application before waiting for output
// > ErrorFunc:function=The function to call when there is an error
// > ProgressFunc:function=The function to call when there is progress
// > SuccessFunc:function=The function to call when the file is laoded
// ? Executes the specified command-line, stores all the output and sends it
// ? for optional processing with the specified flags. The 'Input' is consumed
// ? by the call and sent to the applications 'stdin' on successful execution
// ? startup.
/* ------------------------------------------------------------------------- */
LLFUNC(ExecEx, LCCLASSCREATE(Asset)->InitAsyncCmdLineEx(lS));
/* ========================================================================= */
// $ Asset.Asset
// > Id:string=The filename of the file load
// > Data:Asset=The array to duplicate
// > Flags:integer=Special operations to perform during load
// < Object:Asset=The new duplicated data array
// ? Loads an array on the main thread.
/* ------------------------------------------------------------------------- */
LLFUNCEX(Asset, 1, LCCLASSCREATE(Asset)->InitArray(
  LCGETCPPSTRINGNE(1, "Identifier"), std::move(*LCGETPTR(2, Asset)),
  LCGETFLAGS(AssetFlagsConst, 3, CD_MASK, "Flags")));
/* ========================================================================= */
// $ Asset.String
// > Id:string=The filename of the file to load
// > Text:string=The string of the data to process
// > Flags:integer=Special operations to perform during load
// < Handle:Asset=The asset object
// ? Loads a file from assets in the main thread.
/* ------------------------------------------------------------------------- */
LLFUNCEX(String, 1, LCCLASSCREATE(Asset)->InitString(
  LCGETCPPSTRINGNE(1, "Identifier"),
  LCGETCPPSTRING(2, "Data"),
  LCGETFLAGS(AssetFlagsConst, 3, CD_MASK, "Flags")));
/* ========================================================================= */
// $ Asset.File
// > Filename:string=The filename of the file to load
// > Flags:integer=Special operations to perform during load
// < Handle:Asset=The asset object
// ? Loads a file from assets in the main thread.
/* ------------------------------------------------------------------------- */
LLFUNCEX(File, 1, LCCLASSCREATE(Asset)->InitFile(LCGETCPPFILE(1, "File"),
  LCGETFLAGS(AssetFlagsConst, 2, CD_MASK, "Flags")));
/* ========================================================================= */
// $ Asset.WaitAsync
// ? Halts main-thread execution until all async asset events have completed
/* ------------------------------------------------------------------------- */
LLFUNC(WaitAsync, cAssets->WaitAsync());
/* ========================================================================= */
// $ Asset:Duplicate
// < Handle:Asset=Handle to the duplicated asset
// ? Duplicates the specified asset. By default arrays will move their data
// ? across. This allows you to create a duplicate of the specified asset to
// ? not destory the original.
/* ------------------------------------------------------------------------- */
LLFUNCEX(Duplicate, 1, LCCLASSCREATE(Asset)->InitCopy(*LCGETPTR(1, Asset)));
/* ========================================================================= */
/* ######################################################################### */
/* ## Asset.* namespace functions structure                               ## */
/* ######################################################################### */
/* ------------------------------------------------------------------------- */
LLRSBEGIN                              // Asset.* namespace functions begin
  LLRSFUNC(Asset),                     // Create data array from another array
  LLRSFUNC(AssetAsync),                //  " asynchronously
  LLRSFUNC(Compile),                   // Compile LUA code
  LLRSFUNC(CompileBlock),              // Compile LUA asset
  LLRSFUNC(CompileFunction),           // COmpile LUA function
  LLRSFUNC(CompileString),             // Compile LUA string
  LLRSFUNC(Create),                    // Create data array
  LLRSFUNC(Duplicate),                 // Duplicate another array
  LLRSFUNC(Enumerate),                 // Enumerate files
  LLRSFUNC(EnumerateEx),               // Enumerate files with filter
  LLRSFUNC(Exec),                      // Execute command, output in data array
  LLRSFUNC(ExecEx),                    //  " with input sent to stdin
  LLRSFUNC(File),                      // Create data array from file
  LLRSFUNC(FileAsync),                 //  " asynchronously
  LLRSFUNC(FileExists),                // File exists?
  LLRSFUNC(Parse),                     // Parse LUA source
  LLRSFUNC(ParseBlock),                // Execute LUA asset
  LLRSFUNC(ParseString),               // Execute LUA string
  LLRSFUNC(String),                    // Create data array from string
  LLRSFUNC(StringAsync),               //  " asynchronously
  LLRSFUNC(WaitAsync),                 // Wait for asset async events
LLRSEND                                // Asset.* namespace functions end
/* ========================================================================= */
/* ######################################################################### */
/* ## Asset.* namespace constants structure                               ## */
/* ######################################################################### */
/* ========================================================================= */
// @ Asset.Flags
// < Codes:table=The table of key/value pairs of available flags
// ? A table of loading flags available. Returned as key/value pairs. The
// ? value is a unique identifier to the flag.
/* ------------------------------------------------------------------------- */
LLRSKTBEGIN(Flags)                     // Beginning of loading flags
LLRSKTITEM(CD_,NONE),                  // Load normally
LLRSKTITEM(CD_,DECODE),                // Decode a magic block
LLRSKTITEM(CD_,ENCODE_RAW),            // Copy
LLRSKTITEM(CD_,ENCODE_AES),            // Encrypt
LLRSKTITEM(CD_,ENCODE_ZLIB),           // Deflate
LLRSKTITEM(CD_,ENCODE_ZLIBAES),        // Deflate then encrypt
LLRSKTITEM(CD_,ENCODE_LZMA),           // Compress
LLRSKTITEM(CD_,ENCODE_LZMAAES),        // Compress then encrypt
LLRSKTITEM(CD_,LEVEL_FASTEST),         // Fastest compression
LLRSKTITEM(CD_,LEVEL_FAST),            // Fast compression
LLRSKTITEM(CD_,LEVEL_MODERATE),        // Moderate compression
LLRSKTITEM(CD_,LEVEL_SLOW),            // Slow compression
LLRSKTITEM(CD_,LEVEL_SLOWEST),         // Slowest compression
LLRSKTEND                              // End of loading flags
/* ========================================================================= */
// @ Asset.Progress
// < Codes:table=The table of key/value pairs of available progress commands
// ? A table of loading commands for the progress callback. The first paramter
// ? in that callback is one of these.
/* ------------------------------------------------------------------------- */
LLRSKTBEGIN(Progress)                  // Beginning of progress flags
LLRSKTITEM(APC_,EXECSTART),            // Execution started
LLRSKTITEM(APC_,EXECDATAWRITE),        // Data written to child process
LLRSKTITEM(APC_,FILESTART),            // File opened with information
LLRSKTEND                              // End of progress flags
/* ========================================================================= */
LLRSCONSTBEGIN                         // Asset.* namespace consts begin
LLRSCONST(Flags),                      // Asset loading flags
LLRSCONST(Progress),                   // Asset loading flags
LLRSCONSTEND                           // Asset.* namespace consts end
/* ========================================================================= */
LLNAMESPACEEND                         // End of Asset namespace
/* == EoF =========================================================== EoF == */
