/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a1a00. */
void __cdecl PCscheduleTimers(int a1)
{
  __int64 v1; // rax
  __int64 v2; // rax

  *(_DWORD *)(a1 + 120) &= ~2u; /*0x1a1a07*/
  if ( (*(_BYTE *)(a1 + 124) & 2) != 0 ) /*0x1a1a0f*/
    calloutRemove((int)sub_1A19C8, a1); /*0x1a1a17*/
  if ( (*(_BYTE *)(a1 + 92) & 2) != 0 ) /*0x1a1a23*/
  {
    v1 = calloutDeadlineFromInterval((unsigned int)(1000 * *(_DWORD *)(a1 + 96))); /*0x1a1a38*/
    calloutDispatchDelayed((int)sub_1A19C8, a1, v1, SHIDWORD(v1)); /*0x1a1a45*/
    *(_BYTE *)(a1 + 124) |= 2u; /*0x1a1a4a*/
  }
  else
  {
    *(_DWORD *)(a1 + 124) &= ~2u; /*0x1a1a54*/
  }
  if ( (*(_BYTE *)(a1 + 120) & 4) != 0 ) /*0x1a1a5c*/
  {
    *(_BYTE *)(a1 + 116) |= 4u; /*0x1a1a5e*/
    *(_DWORD *)(a1 + 120) &= ~4u; /*0x1a1a62*/
  }
  if ( (*(_BYTE *)(a1 + 124) & 4) == 0 && (*(_BYTE *)(a1 + 92) & 4) != 0 ) /*0x1a1a70*/
  {
    v2 = calloutDeadlineFromInterval((unsigned int)(1000 * *(_DWORD *)(a1 + 100))); /*0x1a1a85*/
    calloutDispatchDelayed((int)sub_1A19E8, a1, v2, SHIDWORD(v2)); /*0x1a1a92*/
    *(_BYTE *)(a1 + 124) |= 4u; /*0x1a1a97*/
  }
}
