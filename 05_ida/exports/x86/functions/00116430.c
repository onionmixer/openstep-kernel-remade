/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x116430. */
__int16 __cdecl sbwakeup(int a1)
{
  int v1; // esi
  int v2; // edx
  __int16 result; // ax

  v1 = splimp(); /*0x11643d*/
  v2 = *(_DWORD *)(a1 + 16); /*0x11643f*/
  if ( v2 ) /*0x116444*/
  {
    selwakeup(v2, *(_BYTE *)(a1 + 20) & 0x10); /*0x11644e*/
    selthreadclear((_DWORD *)(a1 + 16)); /*0x116457*/
    *(_BYTE *)(a1 + 20) &= ~0x10u; /*0x11645c*/
  }
  splx(v1); /*0x116464*/
  result = *(_WORD *)(a1 + 20); /*0x116469*/
  if ( (result & 4) != 0 ) /*0x116472*/
  {
    LOBYTE(result) = result & 0xFB; /*0x116474*/
    *(_WORD *)(a1 + 20) = result; /*0x116476*/
    if ( nfs_wakeup_one_nfsd == 1 ) /*0x116481*/
      return wakeup_one(a1); /*0x116484*/
    else
      return wakeup(a1); /*0x11648d*/
  }
  return result; /*0x116495*/
}
