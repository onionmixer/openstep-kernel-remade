/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1be874. */
unsigned int __cdecl audio_linear8_peak(int a1, char *a2, unsigned int a3, _DWORD *a4, _DWORD *a5)
{
  unsigned int v6; // ebx
  unsigned int result; // eax
  char v8; // al
  _BYTE *v9; // ecx
  unsigned int v10; // ebx
  char v11; // al
  char *v12; // ecx
  char v13; // al
  char v14; // al

  *a5 = 0; /*0x1be889*/
  *a4 = 0; /*0x1be892*/
  if ( a1 == 1 ) /*0x1be89b*/
  {
    v6 = 0; /*0x1be89d*/
    for ( result = a3 >> 1; a3 >> 1 > v6; ++v6 ) /*0x1be8a1*/
    {
      v8 = *a2; /*0x1be8ac*/
      v9 = a2 + 1; /*0x1be8ae*/
      LOBYTE(result) = v8 ^ 0x80 | v8 & 0x7F; /*0x1be8b6*/
      if ( (result & 0x80u) != 0 ) /*0x1be8b8*/
        LOBYTE(result) = -(char)result; /*0x1be8ba*/
      result = (char)result; /*0x1be8bc*/
      if ( *a4 < (unsigned int)(char)result ) /*0x1be8c4*/
        *a4 = (char)result; /*0x1be8c6*/
      a2 = v9 + 1; /*0x1be8c8*/
    }
    *a5 = *a4; /*0x1be8d7*/
  }
  else
  {
    v10 = 0; /*0x1be8dc*/
    for ( result = a3 >> 1; a3 >> 1 > v10; ++v10 ) /*0x1be8e0*/
    {
      v11 = *a2; /*0x1be8ec*/
      v12 = a2 + 1; /*0x1be8ee*/
      v13 = v11 ^ 0x80 | v11 & 0x7F; /*0x1be8f6*/
      if ( v13 < 0 ) /*0x1be8f8*/
        v13 = -v13; /*0x1be8fa*/
      if ( *a4 < (unsigned int)v13 ) /*0x1be904*/
        *a4 = v13; /*0x1be906*/
      v14 = *v12; /*0x1be908*/
      a2 = v12 + 1; /*0x1be90a*/
      LOBYTE(result) = v14 ^ 0x80 | v14 & 0x7F; /*0x1be912*/
      if ( (result & 0x80u) != 0 ) /*0x1be914*/
        LOBYTE(result) = -(char)result; /*0x1be916*/
      result = (char)result; /*0x1be918*/
      if ( *a5 < (unsigned int)(char)result ) /*0x1be920*/
        *a5 = (char)result; /*0x1be922*/
    }
  }
  *a5 <<= 8; /*0x1be92d*/
  *a4 <<= 8; /*0x1be933*/
  return result; /*0x1be939*/
}
