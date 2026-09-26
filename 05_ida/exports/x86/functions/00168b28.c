/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x168b28. */
void __cdecl stack_init(int a1)
{
  unsigned int i; // eax

  if ( stack_check_usage ) /*0x168b35*/
  {
    for ( i = 0; i <= 0x3FC; ++i ) /*0x168b37*/
      *(_DWORD *)(a1 + 4 * i) = -559038737; /*0x168b3c*/
  }
}
