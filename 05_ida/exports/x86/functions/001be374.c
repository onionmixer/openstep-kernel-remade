/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1be374. */
unsigned int __cdecl audio_convertStereoToMono(char *a1, _BYTE *a2, unsigned int a3, int a4)
{
  char *v4; // ecx
  _BYTE *v5; // edi
  unsigned int result; // eax
  unsigned int v7; // ebx
  _WORD *v8; // esi
  int v9; // ebx
  int v10; // edx
  __int16 *v11; // ecx
  int v12; // edx
  unsigned int v13; // edx
  unsigned int j; // ebx
  int v15; // edx
  char *v16; // ecx
  int v17; // edx
  unsigned int v18; // edx
  unsigned __int8 *v19; // esi
  unsigned int i; // ebx
  int v21; // edx
  unsigned __int8 *v22; // esi
  int v23; // edx

  v4 = a1; /*0x1be37a*/
  v5 = a2; /*0x1be37d*/
  result = a4; /*0x1be380*/
  v7 = a3 >> 1; /*0x1be386*/
  if ( a4 == 1 )
  {
    v19 = (unsigned __int8 *)a1; /*0x1be41c*/
    for ( i = v7 - 1; i != -1; --i ) /*0x1be422*/
    {
      v21 = audio_muLaw[*v19]; /*0x1be427*/
      v22 = v19 + 1; /*0x1be42f*/
      v23 = audio_muLaw[*v22] + v21; /*0x1be43b*/
      v19 = v22 + 1; /*0x1be43d*/
      result = audio_shortToMulaw(((v23 & 1) + v23) / 2); /*0x1be454*/
      *v5++ = result; /*0x1be459*/
    }
  }
  else if ( a4 > 1 )
  {
    if ( a4 != 3 )
      return IOLog((int)"Audio: unrecognized format %d in convMono\n", a4);
    for ( j = v7 - 1; j != -1; --j ) /*0x1be3ec*/
    {
      v15 = *v4; /*0x1be3f4*/
      v16 = v4 + 1; /*0x1be3f7*/
      v17 = *v16 + v15; /*0x1be3fb*/
      v4 = v16 + 1; /*0x1be3fd*/
      v18 = (v17 & 1) + v17; /*0x1be403*/
      result = (v18 + (v18 >> 31)) >> 1; /*0x1be40c*/
      *v5++ = (int)v18 / 2; /*0x1be40e*/
    }
  }
  else
  {
    if ( a4 )
      return IOLog((int)"Audio: unrecognized format %d in convMono\n", a4);
    v8 = a2; /*0x1be3aa*/
    v9 = (a3 >> 2) - 1; /*0x1be3ac*/
    if ( a3 >> 2 ) /*0x1be3a8*/
    {
      do /*0x1be3e0*/
      {
        v10 = *(__int16 *)v4; /*0x1be3b8*/
        v11 = (__int16 *)(v4 + 2); /*0x1be3bb*/
        v12 = *v11 + v10; /*0x1be3c1*/
        v4 = (char *)(v11 + 1); /*0x1be3c3*/
        v13 = (v12 & 1) + v12; /*0x1be3cb*/
        result = (v13 + (v13 >> 31)) >> 1; /*0x1be3d4*/
        *v8++ = (int)v13 / 2; /*0x1be3d6*/
        --v9; /*0x1be3dc*/
      }
      while ( v9 != -1 ); /*0x1be3e0*/
    }
  }
  return result; /*0x1be476*/
}
