/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10c9a8. */
int __cdecl sub_10C9A8(int a1, unsigned int a2, int a3, int a4, int a5, int a6)
{
  unsigned int v6; // eax
  _BYTE *v7; // ebx
  int v8; // et2
  int i; // esi
  int result; // eax
  _BYTE v11[12]; // [esp+10h] [ebp-Ch] BYREF

  v6 = a1; /*0x10c9b1*/
  if ( a2 == 10 && a1 < 0 ) /*0x10c9c1*/
  {
    sub_10CBAC(45, a3, a4); /*0x10c9d0*/
    v6 = -a1; /*0x10c9d8*/
  }
  v7 = v11; /*0x10c9dd*/
  do /*0x10c9ef*/
  {
    v8 = v6 % a2; /*0x10c9e2*/
    v6 /= a2; /*0x10c9e2*/
    *v7++ = byte_1DAC23[v8]; /*0x10c9ea*/
  }
  while ( v6 ); /*0x10c9ef*/
  if ( a6 ) /*0x10c9f3*/
  {
    for ( i = a6 - (v7 - v11); i > 0; --i ) /*0x10ca02*/
    {
      if ( a5 ) /*0x10ca08*/
        sub_10CBAC(48, a3, a4); /*0x10ca14*/
      else
        sub_10CBAC(32, a3, a4); /*0x10ca22*/
    }
  }
  do /*0x10ca4b*/
    result = sub_10CBAC((char)*--v7, a3, a4); /*0x10ca41*/
  while ( v7 > v11 ); /*0x10ca4b*/
  return result; /*0x10ca50*/
}
