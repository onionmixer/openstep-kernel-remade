/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x113748. */
int __cdecl syopen(int a1, int a2)
{
  if ( *(_DWORD *)(active_u + 360) ) /*0x113752*/
    return (*(&cdevsw + 11 * *(unsigned __int8 *)(active_u + 365)))(*(_WORD *)(active_u + 364), a2); /*0x11377b*/
  else
    return 6; /*0x113780*/
}
