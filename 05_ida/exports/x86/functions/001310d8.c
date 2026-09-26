/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1310d8. */
_BYTE *__cdecl sub_1310D8(unsigned __int8 *a1, _BYTE *a2)
{
  unsigned __int16 v2; // ax
  _BYTE *v4; // ecx
  unsigned __int16 v5; // ax
  _BYTE *v6; // esi
  _BYTE *v7; // ecx
  unsigned __int16 v8; // ax
  _BYTE *v9; // esi
  _BYTE *v10; // ecx
  unsigned __int16 v11; // ax
  _BYTE *v12; // esi
  _BYTE *v13; // ecx
  unsigned __int16 v14; // tt
  _BYTE *result; // eax
  _BYTE v16[12]; // [esp+10h] [ebp-Ch] BYREF

  v2 = a1[7]; /*0x1310e4*/
  v4 = v16; /*0x1310ec*/
  do /*0x131112*/
  {
    *v4++ = byte_1DCA0F[v2 % 0xAu]; /*0x131108*/
    v2 /= 0xAu; /*0x13110b*/
  }
  while ( v2 ); /*0x131112*/
  do /*0x131120*/
    *a2++ = *--v4; /*0x13111b*/
  while ( v4 > v16 ); /*0x131120*/
  *a2 = 46; /*0x131124*/
  v5 = a1[6]; /*0x131127*/
  v6 = a2 + 1; /*0x13112c*/
  v7 = v16; /*0x13112f*/
  do /*0x131156*/
  {
    *v7++ = byte_1DCA0F[v5 % 0xAu]; /*0x13114c*/
    v5 /= 0xAu; /*0x13114f*/
  }
  while ( v5 ); /*0x131156*/
  do /*0x131164*/
    *v6++ = *--v7; /*0x13115f*/
  while ( v7 > v16 ); /*0x131164*/
  *v6 = 46; /*0x131168*/
  v8 = a1[5]; /*0x13116b*/
  v9 = v6 + 1; /*0x131170*/
  v10 = v16; /*0x131173*/
  do /*0x13119a*/
  {
    *v10++ = byte_1DCA0F[v8 % 0xAu]; /*0x131190*/
    v8 /= 0xAu; /*0x131193*/
  }
  while ( v8 ); /*0x13119a*/
  do /*0x1311a8*/
    *v9++ = *--v10; /*0x1311a3*/
  while ( v10 > v16 ); /*0x1311a8*/
  *v9 = 46; /*0x1311ac*/
  v11 = a1[4]; /*0x1311af*/
  v12 = v9 + 1; /*0x1311b4*/
  v13 = v16; /*0x1311b7*/
  do /*0x1311da*/
  {
    v14 = v11; /*0x1311c4*/
    v11 /= 0xAu; /*0x1311c4*/
    *v13++ = byte_1DCA0F[v14 % 0xAu]; /*0x1311d2*/
  }
  while ( v11 ); /*0x1311da*/
  result = v16; /*0x1311dc*/
  do /*0x1311e8*/
    *v12++ = *--v13; /*0x1311e3*/
  while ( v13 > v16 ); /*0x1311e8*/
  *v12 = 0; /*0x1311ea*/
  return result; /*0x1311f0*/
}
