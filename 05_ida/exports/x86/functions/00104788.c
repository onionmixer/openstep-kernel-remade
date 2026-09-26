/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x104788. */
int ufavail()
{
  int v0; // ecx
  int i; // edx

  v0 = 0; /*0x10478d*/
  for ( i = 0; i <= 255; ++i ) /*0x10478f*/
  {
    if ( i < *(_DWORD *)(active_u + 348) && !*(_DWORD *)(*(_DWORD *)(active_u + 336) + 4 * i) ) /*0x1047aa*/
      ++v0; /*0x1047b0*/
  }
  return v0; /*0x1047bf*/
}
