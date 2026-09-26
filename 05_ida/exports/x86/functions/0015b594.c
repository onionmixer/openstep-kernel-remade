/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15b594. */
__int32 __cdecl lock_sleepable(int a1, char a2)
{
  volatile __int32 *v2; // edx

  v2 = (volatile __int32 *)(a1 + 8); /*0x15b59a*/
  do /*0x15b5b2*/
  {
    while ( *v2 ) /*0x15b5a0*/
      ; /*0x15b5a2*/
  }
  while ( _InterlockedExchange(v2, 1) == 1 ); /*0x15b5b2*/
  *(_BYTE *)(a1 + 6) = (8 * (a2 & 1)) | *(_BYTE *)(a1 + 6) & 0xF7; /*0x15b5c4*/
  return _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x15b5ce*/
}
