#pragma once

struct A
{
    char a;
    double b;
};
/*
 *---*---*---*---*---*---*---*---*
 * a |  X   X   X   X   X   X  X |
 *---*---*---*---*---*---*---*---*
 *               b               |
 *---*---*---*---*---*---*---*---*
*/

struct B
{
    char a;
    int b;
};
/*
 *---*---*---*---*
 * a | X   X   X |
 *---*---*---*---*
 *       b       |
 *---*---*---*---*
*/

struct C
{
    char a;
    char b;
};
/*
 *---*
 * a |
 *---*
 * b |
 *---*
*/

struct D
{
    char a;
    double b;
    short c;
    double d;
    short e;
};
/*
 *---*---*---*---*---*---*---*---*
 * a | X   X   X   X   X   X   X |
 *---*---*---*---*---*---*---*---*
 *               b               |
 *---*---*---*---*---*---*---*---*
 *   c   |                       |
 *---*---*---*---*---*---*---*---*
 *               d               |
 *---*---*---*---*---*---*---*---*
 *   e   | X   X   X   X   X   X |
 *---*---*---*---*---*---*---*---*
*/

struct E
{
    char a;
    short c;
    short e;
    double b;
    double d;
};
/*
 *---*---*---*---*---*---*---*---*
 * a | X |   c   |   e   | X   X |
 *---*---*---*---*---*---*---*---*
 *               b               |
 *---*---*---*---*---*---*---*---*
 *               d               |
 *---*---*---*---*---*---*---*---*
*/

struct F
{
    char a;
    char f;
    short c;
    short e;
    short g;
    double b;
    double d;
};
/*
 *---*---*---*---*---*---*---*---*
 * a | f |   c   |   e   |   g   |
 *---*---*---*---*---*---*---*---*
 *               b               |
 *---*---*---*---*---*---*---*---*
 *               d               |
 *---*---*---*---*---*---*---*---*
*/

struct alignas(16) AAligned
{
    char a;
    char f;
    short c;
    short e;
    short g;
    double b;
    double d;
};
/*
 *---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*
 * a | f |   c   |   e   |   g   |               b               |
 *---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*
 *               d               | X   X   X   X   X   X   X   X |
 *---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*
*/
