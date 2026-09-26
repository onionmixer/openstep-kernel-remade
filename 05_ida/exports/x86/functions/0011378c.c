/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11378c. */
int __cdecl syread(int a1, int a2)
{
  if ( *(_DWORD *)(active_u + 360) ) /*0x113796*/
    return funcs_1137BF[11 * *(unsigned __int8 *)(active_u + 365)](*(__int16 *)(active_u + 364), a2); /*0x1137bf*/
  else
    return 6; /*0x1137c4*/
}
