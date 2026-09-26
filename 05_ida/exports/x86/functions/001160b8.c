/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1160b8. */
void __cdecl sohasoutofband(int a1)
{
  __int16 v1; // ax
  unsigned int v2; // eax
  int v3; // edx

  v1 = *(_WORD *)(a1 + 90); /*0x1160bf*/
  if ( v1 >= 0 ) /*0x1160c6*/
  {
    if ( v1 > 0 ) /*0x1160db*/
    {
      v2 = pfind(v1); /*0x1160df*/
      if ( v2 ) /*0x1160e9*/
        psignal(v2, (const char *)0x10); /*0x1160ee*/
    }
  }
  else
  {
    gsignal((_DWORD *)-v1, (char *)0x10); /*0x1160ce*/
  }
  v3 = *(_DWORD *)(a1 + 52); /*0x1160f6*/
  if ( v3 ) /*0x1160fb*/
  {
    selwakeup(v3, *(_BYTE *)(a1 + 56) & 0x10); /*0x116105*/
    selthreadclear((_DWORD *)(a1 + 52)); /*0x11610e*/
    *(_BYTE *)(a1 + 56) &= ~0x10u; /*0x116113*/
  }
}
