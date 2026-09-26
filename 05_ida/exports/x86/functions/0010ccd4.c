/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10ccd4. */
int nosys()
{
  int v0; // eax

  v0 = *(_DWORD *)(active_u + 96); /*0x10ccdc*/
  if ( v0 == 1 || v0 == 3 ) /*0x10cce7*/
    *(_BYTE *)(dword_1E875C + 104) = 22; /*0x10ccee*/
  return exception_from_kernel(5, (exception_data_t)0x10000, 0); /*0x10cd02*/
}
