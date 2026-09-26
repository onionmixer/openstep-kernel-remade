/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17bfc0. */
_BOOL4 __cdecl chgprot(int a1, int a2)
{
  return vm_map_protect( /*0x17bffa*/
           *(_DWORD *)(*(_DWORD *)(active_threads + 12) + 12),
           ~page_mask & a1,
           ~page_mask & (a1 + page_mask + 1),
           a2,
           0) == 0;
}
