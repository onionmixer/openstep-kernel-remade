/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11c028. */
int __cdecl vno_bsd_unlock(int a1, int a2)
{
  _WORD *v2; // ebx
  int v3; // esi
  __int16 v4; // di
  int result; // eax

  v2 = *(_WORD **)(a1 + 24); /*0x11c031*/
  v3 = *(_DWORD *)(a1 + 8) & a2; /*0x11c037*/
  if ( v2 && v3 ) /*0x11c044*/
  {
    v4 = v2[2]; /*0x11c04a*/
    if ( (v3 & 0x80u) != 0 ) /*0x11c052*/
    {
      if ( (v4 & 8) == 0 ) /*0x11c05a*/
        panic(aVnoBsdUnlockSh); /*0x11c061*/
      LOWORD(result) = v2[4]; /*0x11c069*/
      v2[4] = result - 1; /*0x11c071*/
      if ( (_WORD)result == 1 ) /*0x11c079*/
      {
        *((_BYTE *)v2 + 4) &= ~8u; /*0x11c07b*/
        if ( (v4 & 0x10) != 0 ) /*0x11c085*/
          result = wakeup((int)(v2 + 4)); /*0x11c08b*/
      }
      *(_DWORD *)(a1 + 8) &= ~0x80u; /*0x11c096*/
    }
    if ( (v3 & 0x100) != 0 ) /*0x11c0a3*/
    {
      if ( (v4 & 4) == 0 ) /*0x11c0ab*/
        panic(aVnoBsdUnlockEx); /*0x11c0b2*/
      LOWORD(result) = v2[5]; /*0x11c0ba*/
      v2[5] = result - 1; /*0x11c0c2*/
      if ( (_WORD)result == 1 ) /*0x11c0ca*/
      {
        *((_BYTE *)v2 + 4) &= 0xEBu; /*0x11c0cc*/
        if ( (v4 & 0x10) != 0 ) /*0x11c0d6*/
          result = wakeup((int)(v2 + 5)); /*0x11c0dc*/
      }
      *(_DWORD *)(a1 + 8) &= ~0x100u; /*0x11c0e4*/
    }
  }
  return result; /*0x11c0ee*/
}
