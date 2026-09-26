/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15ba2c. */
int __cdecl lock_try_write(int a1)
{
  volatile __int32 *v1; // edx
  __int16 v2; // ax

  v1 = (volatile __int32 *)(a1 + 8); /*0x15ba32*/
  do /*0x15ba4a*/
  {
    while ( *v1 ) /*0x15ba38*/
      ; /*0x15ba3a*/
  }
  while ( _InterlockedExchange(v1, 1) == 1 ); /*0x15ba4a*/
  if ( *(_DWORD *)a1 == active_threads ) /*0x15ba53*/
  {
    v2 = *(_WORD *)(a1 + 6); /*0x15ba55*/
    *(_WORD *)(a1 + 6) = ((v2 & 0xFFF0) + 16) | v2 & 0xF; /*0x15ba69*/
LABEL_6:
    _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x15ba6d*/
    return 1; /*0x15ba7a*/
  }
  if ( (*(_DWORD *)(a1 + 4) & 0x3FFFF) == 0 ) /*0x15ba83*/
  {
    *(_BYTE *)(a1 + 6) |= 2u; /*0x15ba85*/
    goto LABEL_6; /*0x15ba89*/
  }
  _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x15ba8e*/
  return 0; /*0x15ba79*/
}
