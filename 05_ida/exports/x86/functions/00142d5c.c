/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x142d5c. */
int __cdecl setblock(int a1, int a2, int a3)
{
  int result; // eax
  char v4; // cl
  int v5; // edx

  result = *(_DWORD *)(a1 + 56); /*0x142d69*/
  if ( result == 2 ) /*0x142d6f*/
  {
    result = a3 >> 2; /*0x142da6*/
    v4 = 2 * (a3 & 3); /*0x142db0*/
    v5 = 3; /*0x142db2*/
    goto LABEL_10; /*0x142db2*/
  }
  if ( result > 2 ) /*0x142d71*/
  {
    if ( result != 4 ) /*0x142d7f*/
    {
      if ( result != 8 ) /*0x142d84*/
        goto LABEL_12; /*0x142d84*/
      *(_BYTE *)(a3 + a2) = -1; /*0x142d86*/
      return result; /*0x142d8a*/
    }
    result = a3 >> 1; /*0x142d8e*/
    v4 = 4 * (a3 & 1); /*0x142d95*/
    v5 = 15; /*0x142d9c*/
LABEL_10:
    *(_BYTE *)(result + a2) |= v5 << v4; /*0x142db7*/
    return result; /*0x142dbc*/
  }
  if ( result != 1 ) /*0x142d76*/
LABEL_12:
    panic(aSetblock); /*0x142dd4*/
  result = 1 << (a3 & 7); /*0x142dcd*/
  *(_BYTE *)((a3 >> 3) + a2) |= result; /*0x142dcf*/
  return result; /*0x142dde*/
}
