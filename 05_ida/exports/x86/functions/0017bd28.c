/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17bd28. */
int __cdecl useracc(int a1, int a2, int a3)
{
  int v3; // eax

  v3 = 2; /*0x17bd2e*/
  if ( a3 == 1 ) /*0x17bd37*/
    v3 = 1; /*0x17bd39*/
  return vm_map_check_protection( /*0x17bd66*/
           *(_DWORD *)(*(_DWORD *)(active_threads + 12) + 12),
           a1 & ~page_mask,
           ~page_mask & (page_mask + a2 + a1),
           v3);
}
