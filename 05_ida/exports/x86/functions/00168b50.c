/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x168b50. */
void __cdecl stack_finalize(int a1)
{
  unsigned int i; // eax

  if ( stack_check_usage ) /*0x168b5d*/
  {
    for ( i = 0; i <= 0x3FC; ++i ) /*0x168b5f*/
    {
      if ( *(_DWORD *)(a1 + 4 * i) != -559038737 ) /*0x168b6b*/
        break; /*0x168b6b*/
    }
    do /*0x168b9c*/
    {
      while ( stack_usage_lock ) /*0x168b8a*/
        ; /*0x168b88*/
    }
    while ( _InterlockedExchange(&stack_usage_lock, 1) == 1 ); /*0x168b9c*/
    if ( stack_max_usage < 4084 - 4 * i ) /*0x168ba4*/
      stack_max_usage = 4084 - 4 * i; /*0x168ba6*/
    _InterlockedExchange(&stack_usage_lock, 0); /*0x168bae*/
  }
}
