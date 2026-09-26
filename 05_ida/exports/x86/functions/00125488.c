/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x125488. */
_DWORD *__cdecl in_pcblookup(_DWORD *a1, int a2, __int16 a3, int a4, __int16 a5, char a6)
{
  int v6; // esi
  _DWORD *v7; // ebx
  int v8; // ecx
  int v9; // eax
  unsigned int v10; // edx
  _DWORD *v12; // [esp+Ch] [ebp-Ch]

  v12 = nullptr; /*0x1254a1*/
  v6 = 3; /*0x1254a8*/
  v7 = (_DWORD *)*a1; /*0x1254b0*/
  if ( (_DWORD *)*a1 != a1 ) /*0x1254b4*/
  {
    while ( 1 ) /*0x1254bc*/
    {
      if ( *((_WORD *)v7 + 12) != a5 ) /*0x1254c4*/
        goto LABEL_21; /*0x1254c4*/
      v8 = 0; /*0x1254c6*/
      v9 = v7[5]; /*0x1254c8*/
      if ( !v9 ) /*0x1254cd*/
        break; /*0x1254cd*/
      if ( !a4 ) /*0x1254d3*/
        goto LABEL_8; /*0x1254d3*/
      if ( a4 != v9 ) /*0x1254d8*/
        goto LABEL_21; /*0x1254d8*/
LABEL_9:
      v10 = v7[3]; /*0x1254e7*/
      if ( v10 ) /*0x1254ec*/
      {
        if ( a2 ) /*0x1254f2*/
        {
          if ( *((_WORD *)v7 + 8) != a3 || (_byteswap_ulong(v10) & 0xF0000000) == 0xE0000000 || a2 != v10 ) /*0x125511*/
            goto LABEL_21; /*0x125511*/
          goto LABEL_17; /*0x125511*/
        }
      }
      else if ( !a2 ) /*0x12551c*/
      {
        goto LABEL_17; /*0x12551c*/
      }
      ++v8; /*0x12551e*/
LABEL_17:
      if ( (!v8 || (a6 & 1) != 0) && v8 < v6 ) /*0x125530*/
      {
        v12 = v7; /*0x125532*/
        v6 = v8; /*0x125535*/
        if ( !v8 ) /*0x125539*/
          return v12; /*0x125539*/
      }
LABEL_21:
      v7 = (_DWORD *)*v7; /*0x12553b*/
      if ( a1 == v7 ) /*0x125540*/
        return v12; /*0x125540*/
    }
    if ( !a4 ) /*0x1254e0*/
      goto LABEL_9; /*0x1254e0*/
LABEL_8:
    v8 = 1; /*0x1254e2*/
    goto LABEL_9; /*0x1254e2*/
  }
  return v12; /*0x12554c*/
}
