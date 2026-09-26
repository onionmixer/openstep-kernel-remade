/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11649c. */
void __cdecl sowakeup(int a1, int a2)
{
  int v2; // esi
  int v3; // edx
  __int16 v4; // ax
  __int16 v5; // ax
  unsigned int v6; // eax

  v2 = splimp(); /*0x1164ad*/
  v3 = *(_DWORD *)(a2 + 16); /*0x1164af*/
  if ( v3 ) /*0x1164b4*/
  {
    selwakeup(v3, *(_BYTE *)(a2 + 20) & 0x10); /*0x1164be*/
    selthreadclear((_DWORD *)(a2 + 16)); /*0x1164c7*/
    *(_BYTE *)(a2 + 20) &= ~0x10u; /*0x1164cc*/
  }
  splx(v2); /*0x1164d4*/
  v4 = *(_WORD *)(a2 + 20); /*0x1164d9*/
  if ( (v4 & 4) != 0 ) /*0x1164e2*/
  {
    LOBYTE(v4) = v4 & 0xFB; /*0x1164e4*/
    *(_WORD *)(a2 + 20) = v4; /*0x1164e6*/
    if ( nfs_wakeup_one_nfsd == 1 ) /*0x1164f1*/
      wakeup_one(a2); /*0x1164f4*/
    else
      wakeup(a2); /*0x1164fd*/
  }
  if ( (*(_BYTE *)(a1 + 7) & 2) != 0 ) /*0x116509*/
  {
    v5 = *(_WORD *)(a1 + 90); /*0x11650b*/
    if ( v5 >= 0 ) /*0x116512*/
    {
      if ( v5 > 0 ) /*0x116527*/
      {
        v6 = pfind(v5); /*0x11652b*/
        if ( v6 ) /*0x116535*/
          psignal(v6, (const char *)0x17); /*0x11653a*/
      }
    }
    else
    {
      gsignal((_DWORD *)-v5, (char *)0x17); /*0x11651a*/
    }
  }
}
