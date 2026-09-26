/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1840d0. */
u_int __cdecl f_minphys(buf_t a1)
{
  if ( *((_DWORD *)a1 + 5) > (unsigned int)dword_1E756C ) /*0x1840de*/
    *((_DWORD *)a1 + 5) = dword_1E756C; /*0x1840e0*/
  return *((_DWORD *)a1 + 5); /*0x1840e8*/
}
