/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17a6f4. */
__int32 __cdecl sub_17A6F4(int a1, unsigned int a2, unsigned int a3, int a4)
{
  int i; // ebx
  int j; // eax

  lock_read(a1); /*0x17a701*/
  for ( i = *(_DWORD *)(a1 + 16); i != a1 + 12; i = *(_DWORD *)(i + 4) ) /*0x17a706*/
  {
    if ( (*(_BYTE *)(i + 24) & 5) != 0 ) /*0x17a714*/
    {
      sub_17A6F4(*(_DWORD *)(i + 16), a2, a3, a4); /*0x17a723*/
    }
    else if ( *(_DWORD *)(i + 8) <= a3 && *(_DWORD *)(i + 12) > a2 ) /*0x17a73e*/
    {
      for ( j = *(_DWORD *)(i + 16); j; j = *(_DWORD *)(j + 32) ) /*0x17a745*/
        *(_WORD *)(j + 72) = a4; /*0x17a748*/
    }
  }
  return lock_done(a1); /*0x17a766*/
}
