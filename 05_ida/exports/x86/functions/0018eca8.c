/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18eca8. */
int __cdecl pmap_pd_entry(_DWORD *a1, unsigned int a2)
{
  return *a1 + 4 * (a2 >> 22); /*0x18ecbb*/
}
