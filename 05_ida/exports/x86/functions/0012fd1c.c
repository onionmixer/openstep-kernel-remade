/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12fd1c. */
int __cdecl rlock_timeout(unsigned int a1)
{
  int v2; // esi
  __int16 v3; // dx

  while ( 1 ) /*0x12fda5*/
  {
    v3 = *(_WORD *)(a1 + 96); /*0x12fda5*/
    if ( (v3 & 1) == 0 || *(_DWORD *)(a1 + 104) == active_threads ) /*0x12fd34*/
      break; /*0x12fd34*/
    if ( (v3 & 0x20) != 0 ) /*0x12fd39*/
    {
      ++rlockretimeout; /*0x12fd3b*/
      return 1; /*0x12fd46*/
    }
    LOBYTE(v3) = v3 | 2; /*0x12fd48*/
    *(_WORD *)(a1 + 96) = v3; /*0x12fd4b*/
    v2 = splhigh(); /*0x12fd54*/
    timeout((int)sub_12FDD0); /*0x12fd66*/
    sleep(a1); /*0x12fd6e*/
    if ( !untimeout((int)sub_12FDD0, a1) ) /*0x12fd79*/
    {
      ++rlocktimeout; /*0x12fd85*/
      *(_BYTE *)(a1 + 96) |= 0x20u; /*0x12fd8b*/
      splx(v2); /*0x12fd90*/
      return 1; /*0x12fd9a*/
    }
    splx(v2); /*0x12fd9d*/
  }
  *(_DWORD *)(a1 + 104) = active_threads; /*0x12fdb8*/
  ++*(_WORD *)(a1 + 108); /*0x12fdbb*/
  *(_BYTE *)(a1 + 96) |= 1u; /*0x12fdbf*/
  return 0; /*0x12fdc8*/
}
