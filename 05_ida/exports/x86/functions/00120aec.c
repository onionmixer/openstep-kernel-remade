/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x120aec. */
int __cdecl nb_write(int a1, int a2, size_t a3, void *a4)
{
  if ( a3 + a2 > *(__int16 *)(a1 + 8) ) /*0x120b04*/
    return -1; /*0x120b1c*/
  bcopy(a4, (void *)(a2 + *(_DWORD *)(a1 + 4) + a1), a3); /*0x120b13*/
  return 0; /*0x120b24*/
}
