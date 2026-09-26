/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1138c8. */
int __cdecl syselect(int a1, int a2)
{
  if ( *(_DWORD *)(active_u + 360) ) /*0x1138d2*/
    return (*(&funcs_1138FB + 11 * *(unsigned __int8 *)(active_u + 365)))(*(__int16 *)(active_u + 364), a2); /*0x1138fb*/
  *(_BYTE *)(dword_1E875C + 104) = 6; /*0x113905*/
  return 0; /*0x11390b*/
}
