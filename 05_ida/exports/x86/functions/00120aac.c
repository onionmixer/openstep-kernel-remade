/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x120aac. */
int __cdecl nb_read(int a1, int a2, size_t a3, void *a4)
{
  if ( a3 + a2 > *(__int16 *)(a1 + 8) ) /*0x120ac4*/
    return -1; /*0x120adc*/
  bcopy((const void *)(a2 + *(_DWORD *)(a1 + 4) + a1), a4, a3); /*0x120ad3*/
  return 0; /*0x120ae4*/
}
