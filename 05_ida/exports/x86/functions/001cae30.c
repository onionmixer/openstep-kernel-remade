/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cae30. */
__int32 __cdecl NXAllocErrorData(int a1, _DWORD *a2)
{
  signed __int32 v2; // ebx

  do /*0x1cae51*/
  {
    while ( dword_1E5540 ) /*0x1cae3f*/
      ; /*0x1cae38*/
  }
  while ( _InterlockedExchange(&dword_1E5540, 1) == 1 ); /*0x1cae51*/
  v2 = dword_1E553C + a1 + 7; /*0x1cae5c*/
  LOBYTE(v2) = v2 & 0xF8; /*0x1cae5f*/
  if ( dword_1E5454 < v2 ) /*0x1cae68*/
  {
    _ptr = realloc(_ptr, v2); /*0x1cae77*/
    dword_1E5454 = v2; /*0x1cae7c*/
  }
  *a2 = (char *)_ptr + dword_1E553C; /*0x1cae8e*/
  dword_1E553C = v2; /*0x1cae90*/
  return _InterlockedExchange(&dword_1E5540, 0); /*0x1caea1*/
}
