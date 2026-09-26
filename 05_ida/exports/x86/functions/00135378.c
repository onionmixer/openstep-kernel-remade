/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x135378. */
int __cdecl clntkudp_realloc(int a1, void *a2)
{
  int v2; // ebx
  int result; // eax

  v2 = *(_DWORD *)(a1 + 8); /*0x135383*/
  bcopy(*(const void **)(v2 + 104), a2, 0x2260u); /*0x135390*/
  result = kfree(*(_DWORD *)(v2 + 104), 0x2260u); /*0x13539e*/
  *(_DWORD *)(v2 + 104) = a2; /*0x1353a3*/
  return result; /*0x1353a9*/
}
