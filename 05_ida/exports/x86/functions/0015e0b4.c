/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15e0b4. */
int __cdecl vm_info_init(int *a1)
{
  int v1; // ebx
  int result; // eax

  v1 = *a1; /*0x15e0bc*/
  if ( !*a1 ) /*0x15e0bc*/
    v1 = zalloc(vm_info_zone); /*0x15e0ce*/
  *(_DWORD *)v1 = 0; /*0x15e0d3*/
  *(_WORD *)(v1 + 4) = 0; /*0x15e0d9*/
  *(_WORD *)(v1 + 6) = 0; /*0x15e0df*/
  *(_DWORD *)(v1 + 8) = 0; /*0x15e0e5*/
  *(_DWORD *)(v1 + 12) = 0; /*0x15e0ec*/
  *(_DWORD *)(v1 + 16) = 0; /*0x15e0f3*/
  *(_DWORD *)(v1 + 48) = 0; /*0x15e0fa*/
  *(_DWORD *)(v1 + 52) = 0; /*0x15e101*/
  *(_BYTE *)(v1 + 56) = *(_BYTE *)(v1 + 56) & 0xE8 | 4; /*0x15e10f*/
  *(_DWORD *)(v1 + 20) = 0; /*0x15e112*/
  result = lock_init((void *)(v1 + 24), 1); /*0x15e11f*/
  *(_DWORD *)(v1 + 36) = 0; /*0x15e124*/
  *a1 = v1; /*0x15e12b*/
  return result; /*0x15e130*/
}
