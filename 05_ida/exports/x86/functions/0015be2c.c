/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15be2c. */
int __cdecl reset_timeout(int a1)
{
  int v1; // esi

  v1 = splsched(); /*0x15be39*/
  do /*0x15be55*/
  {
    while ( dword_1E5BA8 ) /*0x15be43*/
      ; /*0x15be41*/
  }
  while ( _InterlockedExchange(&dword_1E5BA8, 1) == 1 ); /*0x15be55*/
  if ( *(_DWORD *)(a1 + 44) ) /*0x15be57*/
  {
    calloutEntryRemove(a1); /*0x15be5e*/
    *(_DWORD *)(a1 + 44) = 0; /*0x15be63*/
    _InterlockedExchange(&dword_1E5BA8, 0); /*0x15be6f*/
    splx(v1); /*0x15be76*/
    return 1; /*0x15be7b*/
  }
  else
  {
    _InterlockedExchange(&dword_1E5BA8, 0); /*0x15be86*/
    splx(v1); /*0x15be8d*/
    return 0; /*0x15be92*/
  }
}
