/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1783d8. */
__int32 __cdecl vm_map_lookup_done(int a1, int a2)
{
  if ( (*(_BYTE *)(a2 + 24) & 1) != 0 ) /*0x1783e2*/
    lock_done(*(_DWORD *)(a2 + 16)); /*0x1783e8*/
  return lock_done(a1); /*0x1783fb*/
}
