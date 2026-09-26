/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1161f8. */
int __cdecl soisdisconnected(int a1)
{
  __int16 v2; // ax

  v2 = *(_WORD *)(a1 + 6); /*0x1161ff*/
  LOBYTE(v2) = v2 & 0xC1 | 0x30; /*0x116205*/
  *(_WORD *)(a1 + 6) = v2; /*0x116207*/
  wakeup(a1 + 84); /*0x11620f*/
  sowakeup(a1, a1 + 60); /*0x116219*/
  return sowakeup(a1, a1 + 36); /*0x116228*/
}
