/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x114db8. */
int __cdecl soclose(int a1)
{
  int v1; // edi
  __int16 v2; // ax
  __int16 v3; // dx
  int v4; // eax
  __int16 v5; // ax
  int v6; // eax
  int v8; // [esp+Ch] [ebp-4h]

  v8 = splnet(); /*0x114dc9*/
  v1 = 0; /*0x114dcc*/
  if ( (*(_BYTE *)(a1 + 2) & 2) != 0 ) /*0x114dd2*/
  {
    while ( *(_DWORD *)(a1 + 20) != a1 ) /*0x114dd7*/
      soabort(*(_DWORD *)(a1 + 20)); /*0x114de0*/
    while ( *(_DWORD *)(a1 + 28) != a1 ) /*0x114dff*/
      soabort(*(_DWORD *)(a1 + 28)); /*0x114df4*/
  }
  if ( *(_DWORD *)(a1 + 8) ) /*0x114e01*/
  {
    v2 = *(_WORD *)(a1 + 6); /*0x114e07*/
    if ( (v2 & 2) != 0 && ((v2 & 8) != 0 || (v1 = sodisconnect(a1)) == 0) && *(char *)(a1 + 2) < 0 ) /*0x114e26*/
    {
      v3 = *(_WORD *)(a1 + 6); /*0x114e28*/
      if ( (v3 & 0x108) != 0x108 && (v3 & 2) != 0 ) /*0x114e3b*/
      {
        do /*0x114e4f*/
          sleep(a1 + 84); /*0x114e43*/
        while ( (*(_BYTE *)(a1 + 6) & 2) != 0 ); /*0x114e4f*/
      }
    }
    if ( *(_DWORD *)(a1 + 8) ) /*0x114e51*/
    {
      v4 = (*(int (__cdecl **)(int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)(a1 + 12) + 28))(a1, 1, 0, 0, 0); /*0x114e66*/
      if ( !v1 ) /*0x114e6d*/
        v1 = v4; /*0x114e6f*/
    }
  }
  if ( (*(_BYTE *)(a1 + 6) & 1) != 0 ) /*0x114e75*/
    panic(aSocloseNofdref); /*0x114e7c*/
  v5 = *(_WORD *)(a1 + 6); /*0x114e84*/
  LOBYTE(v5) = v5 | 1; /*0x114e88*/
  *(_WORD *)(a1 + 6) = v5; /*0x114e8a*/
  if ( !*(_DWORD *)(a1 + 8) && (v5 & 1) != 0 ) /*0x114e96*/
  {
    if ( *(_DWORD *)(a1 + 16) ) /*0x114e98*/
    {
      if ( !soqremque(a1, 0) && !soqremque(a1, 1) ) /*0x114eb0*/
        panic(aSofreeDq); /*0x114ec1*/
      *(_DWORD *)(a1 + 16) = 0; /*0x114ec9*/
    }
    sbrelease(a1 + 60); /*0x114ed4*/
    sorflush(a1); /*0x114eda*/
    v6 = a1; /*0x114edf*/
    LOBYTE(v6) = a1 & 0x80; /*0x114ee1*/
    m_free(v6); /*0x114ee4*/
  }
  splx(v8); /*0x114ef0*/
  return v1; /*0x114efa*/
}
