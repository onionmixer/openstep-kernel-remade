/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x168afc. */
int __cdecl stack_usage(int a1)
{
  unsigned int i; // eax

  for ( i = 0; i <= 0x3FC; ++i ) /*0x168b02*/
  {
    if ( *(_DWORD *)(a1 + 4 * i) != -559038737 ) /*0x168b0b*/
      break; /*0x168b0b*/
  }
  return 4084 - 4 * i; /*0x168b23*/
}
