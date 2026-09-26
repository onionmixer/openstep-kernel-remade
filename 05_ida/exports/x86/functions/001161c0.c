/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1161c0. */
int __cdecl soisdisconnecting(int a1)
{
  __int16 v2; // ax

  v2 = *(_WORD *)(a1 + 6); /*0x1161c7*/
  LOBYTE(v2) = v2 & 0xC3 | 0x38; /*0x1161cd*/
  *(_WORD *)(a1 + 6) = v2; /*0x1161cf*/
  wakeup(a1 + 84); /*0x1161d7*/
  sowakeup(a1, a1 + 60); /*0x1161e1*/
  return sowakeup(a1, a1 + 36); /*0x1161f0*/
}
