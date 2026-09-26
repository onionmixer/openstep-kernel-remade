/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10d7e4. */
void __cdecl selwakeup(int a1, int a2)
{
  int v2; // esi
  int v3; // eax

  if ( a2 ) /*0x10d7f0*/
  {
    ++nselcoll; /*0x10d7f2*/
    wakeup((int)&selwait); /*0x10d7fd*/
  }
  if ( a1 && *(_DWORD *)(a1 + 376) ) /*0x10d809*/
  {
    v2 = splhigh(); /*0x10d817*/
    if ( *(_UNKNOWN **)(a1 + 60) == &selwait ) /*0x10d820*/
      clear_wait(a1, 0, 1); /*0x10d827*/
    v3 = *(_DWORD *)(*(_DWORD *)(a1 + 12) + 60); /*0x10d832*/
    if ( v3 ) /*0x10d837*/
      *(_DWORD *)(v3 + 40) &= ~0x400000u; /*0x10d839*/
    splx(v2); /*0x10d841*/
  }
}
