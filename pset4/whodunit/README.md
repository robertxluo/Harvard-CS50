# Questions

## What's `stdint.h`?

`stdint.h` is a header file in the C standard library that allows programmers to write more portable code by providing a set of typedefs that specify exact-width integer types, together with the defined minimum and maximum allowable values for each type, using macros.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

It makes it clear you want to use a data a specific way. Using well-defined types
`uint8_t` is the same as a byte: an unsigned type of integer of length 8 bits.
`uint32_t` is an unsigned type of integer of 32 bits.
`int32_t` is a signed type of integer of 32 bits
`uint16_t` is an unsigned integer of 32 bits.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

1 byte in a `BYTE` (8 bits)
4 bytes in a `DWORD` (32 bits)
4 bytes in a `LONG` (32 bits)
2 bytes in a `WORD` (16 bits)

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

ASCII: "BM"
Decimal: 66 77
Hexadecimal: 0x42 0x4D

## What's the difference between `bfSize` and `biSize`?

`bfSize` is the size of the whole bmp file, which includes the headerfiles in bytes.
`biSize` is the number of bytes required by the structure.

## What does it mean if `biHeight` is negative?

If `biHeight` is negative, the bitmap is a top-down DIB and its origin is the upper-left corner.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

`biBitCount`

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

A reason would be that it cannnot find the file.

## Why is the third argument to `fread` always `1` in our code?

Because it specifies how many elements to be read and it's always reading one struct.

## What value does line 63 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

`int padding = (4 - (3 * (3 % 4)) % 4;`
The padding would be 3.

## What does `fseek` do?

`fseek` is used to move file pointer associated with a given file to a specific position.

## What is `SEEK_CUR`?

`SEEK_CUR` denotes file pointer's current position.
