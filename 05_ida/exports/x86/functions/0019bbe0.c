/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x19bbe0. */
_DWORD *__cdecl sub_19BBE0(_DWORD *a1)
{
  _DWORD *result; // eax
  _DWORD *i; // esi
  unsigned int v3; // eax
  int m; // edx
  _WORD *v5; // edi
  int k; // edx
  int j; // edx
  int v8; // [esp+Ch] [ebp-Ch]
  _DWORD *v9; // [esp+14h] [ebp-4h]

  result = (_DWORD *)(a1[36] + 12 * a1[41]); /*0x19bbfb*/
  v9 = result + 3; /*0x19bc01*/
  v8 = a1[35] + 8 * a1[42]; /*0x19bc17*/
  for ( i = result; (int)v9 > (int)i; i = (_DWORD *)((char *)i + 1) ) /*0x19bc1f*/
  {
    v3 = a1[7]; /*0x19bc28*/
    if ( v3 > 3 ) /*0x19bc2e*/
    {
      if ( v3 != 4 ) /*0x19bc43*/
LABEL_17:
        panic(aFbconsoleErase); /*0x19bd18*/
      result = (_DWORD *)(a1[6] + a1[4] * (_DWORD)i + 4 * v8); /*0x19bd00*/
      for ( j = 7; j >= 0; --j ) /*0x19bd03*/
        *result++ = a1[44]; /*0x19bd0e*/
    }
    else if ( v3 >= 2 ) /*0x19bc33*/
    {
      result = (_DWORD *)(a1[6] + a1[4] * (_DWORD)i); /*0x19bcaa*/
      v5 = (_WORD *)result + v8; /*0x19bcb0*/
      for ( k = 7; k >= 0; --k ) /*0x19bcd9*/
        *v5++ = *((_WORD *)a1 + 88); /*0x19bce7*/
    }
    else
    {
      if ( v3 != 1 ) /*0x19bc38*/
        goto LABEL_17; /*0x19bc38*/
      result = (_DWORD *)(v8 + a1[6] + a1[4] * (_DWORD)i); /*0x19bc59*/
      for ( m = 7; m >= 0; --m ) /*0x19bc5c*/
      {
        *(_BYTE *)result = *((_BYTE *)a1 + 176); /*0x19bc6a*/
        result = (_DWORD *)((char *)result + 1); /*0x19bc6c*/
      }
    }
  }
  return result; /*0x19bd32*/
}
