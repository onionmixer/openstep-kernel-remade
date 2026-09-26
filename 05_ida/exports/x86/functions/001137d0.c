/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1137d0. */
int __cdecl sywrite(int a1, int a2)
{
  if ( *(_DWORD *)(active_u + 360) ) /*0x1137da*/
    return (*(&funcs_113803 + 11 * *(unsigned __int8 *)(active_u + 365)))(*(__int16 *)(active_u + 364), a2); /*0x113803*/
  else
    return 6; /*0x113808*/
}
