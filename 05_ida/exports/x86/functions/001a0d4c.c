/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a0d4c. */
void __cdecl __spoils<ecx> ev_lock(volatile __int32 *a1)
{
  __int32 v1; // ecx

  v1 = 1; /*0x1a0d4e*/
  do /*0x1a0d5d*/
    v1 = _InterlockedExchange(a1, v1); /*0x1a0d57*/
  while ( v1 ); /*0x1a0d5d*/
}
