/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11de44. */
int __cdecl getvnodefp(unsigned int a1, int *a2)
{
  int v2; // eax

  v2 = getf(a1); /*0x11de4f*/
  if ( !v2 ) /*0x11de56*/
    return 9; /*0x11de58*/
  if ( *(_WORD *)(v2 + 12) != 1 ) /*0x11de65*/
    return 22; /*0x11de70*/
  *a2 = v2; /*0x11de67*/
  return 0; /*0x11de75*/
}
