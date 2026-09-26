/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x116120. */
int __cdecl soisconnecting(int a1)
{
  __int16 v1; // dx

  v1 = *(_WORD *)(a1 + 6); /*0x116126*/
  LOBYTE(v1) = v1 & 0xF1 | 4; /*0x11612d*/
  *(_WORD *)(a1 + 6) = v1; /*0x116130*/
  return wakeup(a1 + 84); /*0x11613f*/
}
