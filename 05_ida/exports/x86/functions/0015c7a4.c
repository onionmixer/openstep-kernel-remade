/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15c7a4. */
unsigned int __cdecl sub_15C7A4(int a1)
{
  unsigned int v1; // esi
  _DWORD *v2; // edx
  int v3; // ecx
  unsigned int v4; // ebx
  _DWORD *v5; // ebx
  _DWORD *v6; // edx
  unsigned int v7; // ecx
  unsigned int v8; // eax
  unsigned int v9; // eax

  v1 = 0; /*0x15c7ad*/
  v2 = (_DWORD *)(a1 + 28); /*0x15c7af*/
  v3 = 0; /*0x15c7b2*/
  v4 = *(_DWORD *)(a1 + 16); /*0x15c7b4*/
  if ( v4 ) /*0x15c7b9*/
  {
    while ( *v2 != 1 ) /*0x15c7bf*/
    {
      v2 = (_DWORD *)((char *)v2 + v2[1]); /*0x15c7c1*/
      if ( ++v3 >= v4 ) /*0x15c7c7*/
        return v1; /*0x15c7c7*/
    }
    while ( v2 ) /*0x15c819*/
    {
      if ( v2[9] + v2[8] > v1 ) /*0x15c7d8*/
        v1 = v2[9] + v2[8]; /*0x15c7da*/
      v5 = v2; /*0x15c7dc*/
      v6 = (_DWORD *)(a1 + 28); /*0x15c7de*/
      v7 = 0; /*0x15c7e1*/
      v8 = *(_DWORD *)(a1 + 16); /*0x15c7e3*/
      if ( v8 ) /*0x15c7e8*/
      {
        do /*0x15c7f6*/
        {
          if ( v6 == v5 ) /*0x15c7ee*/
            break; /*0x15c7ee*/
          v6 = (_DWORD *)((char *)v6 + v6[1]); /*0x15c7f0*/
          ++v7; /*0x15c7f3*/
        }
        while ( v7 < v8 ); /*0x15c7f6*/
      }
      v9 = *(_DWORD *)(a1 + 16); /*0x15c7f8*/
      if ( v7 == v9 ) /*0x15c7fd*/
        break; /*0x15c7fd*/
      v2 = (_DWORD *)((char *)v6 + v6[1]); /*0x15c7ff*/
      if ( v7 >= v9 ) /*0x15c804*/
      {
LABEL_14:
        v2 = nullptr; /*0x15c815*/
      }
      else
      {
        while ( *v2 != 1 ) /*0x15c80b*/
        {
          v2 = (_DWORD *)((char *)v2 + v2[1]); /*0x15c80d*/
          if ( ++v7 >= v9 ) /*0x15c813*/
            goto LABEL_14; /*0x15c813*/
        }
      }
    }
  }
  return v1; /*0x15c820*/
}
