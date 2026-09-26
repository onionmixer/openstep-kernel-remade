/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x174744. */
int __cdecl _vm_map_entry_create(int a1)
{
  int v1; // eax
  int result; // eax

  if ( *(_DWORD *)(a1 + 20) ) /*0x17474b*/
    v1 = vm_map_entry_zone; /*0x174751*/
  else
    v1 = vm_map_kentry_zone; /*0x174758*/
  result = zalloc(v1); /*0x17475e*/
  if ( !result ) /*0x17476a*/
    panic(aVmMapEntryCrea); /*0x174771*/
  return result; /*0x174778*/
}
