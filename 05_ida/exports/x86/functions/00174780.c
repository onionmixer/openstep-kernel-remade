/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x174780. */
__int32 __cdecl _vm_map_entry_dispose(int a1, _DWORD *a2)
{
  int v2; // eax

  if ( *(_DWORD *)(a1 + 20) ) /*0x174786*/
    v2 = vm_map_entry_zone; /*0x17478c*/
  else
    v2 = vm_map_kentry_zone; /*0x174794*/
  return zfree(v2, a2); /*0x1747a5*/
}
