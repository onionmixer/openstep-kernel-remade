/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1d00e8. */
char *__cdecl _sel_registerName(char *__s1)
{
  char *v2; // ebx
  unsigned int v3; // ecx
  _BYTE *v4; // ebx
  _BYTE *v5; // ebx
  int v6; // eax
  _BYTE *v7; // ebx
  _DWORD *v8; // esi
  int **v9; // ebx
  int v10; // ebx
  _DWORD *v11; // edx
  int v12; // [esp+Ch] [ebp-Ch]
  unsigned int v13; // [esp+14h] [ebp-4h]

  if ( !__s1 ) /*0x1d00f5*/
    return nullptr; /*0x1d00f7*/
  v2 = __s1; /*0x1d0100*/
  v3 = 0; /*0x1d0103*/
  while ( *v2 ) /*0x1d0108*/
  {
    v3 ^= (unsigned __int8)*v2; /*0x1d0110*/
    v4 = v2 + 1; /*0x1d0112*/
    if ( !*v4 ) /*0x1d0113*/
      break; /*0x1d0113*/
    v3 ^= (unsigned __int8)*v4 << 8; /*0x1d011e*/
    v5 = v4 + 1; /*0x1d0120*/
    if ( !*v5 ) /*0x1d0121*/
      break; /*0x1d0121*/
    v6 = (unsigned __int8)*v5 << 16; /*0x1d0129*/
    v3 ^= v6; /*0x1d012c*/
    v7 = v5 + 1; /*0x1d012e*/
    if ( !*v7 ) /*0x1d012f*/
      break; /*0x1d012f*/
    LOBYTE(v6) = *v7; /*0x1d0134*/
    v3 ^= v6 << 24; /*0x1d0139*/
    v2 = v7 + 1; /*0x1d013b*/
  }
  v13 = v3; /*0x1d0140*/
  v8 = off_1E5640; /*0x1d0143*/
  if ( !off_1E5640 ) /*0x1d014b*/
LABEL_24:
    abort(); /*0x1d026b*/
  while ( 1 ) /*0x1d0154*/
  {
    if ( v8[3] <= (unsigned int)__s1 && v8[4] > (unsigned int)__s1 ) /*0x1d015f*/
      return __s1; /*0x1d015f*/
    v12 = v13 % v8[1]; /*0x1d016d*/
    v9 = *(int ***)(v8[5] + 4 * v12); /*0x1d0173*/
    if ( v9 ) /*0x1d0178*/
      break; /*0x1d0178*/
LABEL_16:
    if ( v8 == (_DWORD *)&unk_1E5624 ) /*0x1d01a6*/
    {
      ++dword_1E562C; /*0x1d01ac*/
      if ( off_1E5638 == &unk_1D6750 ) /*0x1d01bc*/
      {
        dword_1E5628 = 821; /*0x1d01be*/
        off_1E5638 = (_UNKNOWN *)sub_1CFFEC(3284); /*0x1d01d4*/
        memset(off_1E5638, 0, 4 * dword_1E5628); /*0x1d01eb*/
        v12 = v13 % v8[1]; /*0x1d01f8*/
      }
      v10 = *(_DWORD *)(v8[5] + 4 * v12); /*0x1d0204*/
      if ( !dword_1E5648 || dword_1E564C > 39 ) /*0x1d0217*/
      {
        dword_1E5648 = sub_1CFFEC(320); /*0x1d0223*/
        dword_1E564C = 0; /*0x1d0228*/
      }
      v11 = (_DWORD *)(dword_1E5648 + 8 * dword_1E564C++); /*0x1d023e*/
      *v11 = v10; /*0x1d024a*/
      v11[1] = __s1; /*0x1d024f*/
      *(_DWORD *)(v8[5] + 4 * v12) = v11; /*0x1d0258*/
      return __s1; /*0x1d0278*/
    }
    v8 = (_DWORD *)v8[6]; /*0x1d0260*/
    if ( !v8 ) /*0x1d0265*/
      goto LABEL_24; /*0x1d0265*/
  }
  while ( *(_BYTE *)v9[1] != *__s1 || strcmp(__s1, (const char *)v9[1]) ) /*0x1d0194*/
  {
    v9 = (int **)*v9; /*0x1d019a*/
    if ( !v9 ) /*0x1d019e*/
      goto LABEL_16; /*0x1d019e*/
  }
  return (char *)v9[1]; /*0x1d027e*/
}
