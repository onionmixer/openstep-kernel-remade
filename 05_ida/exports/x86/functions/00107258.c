/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x107258. */
kern_return_t obreak()
{
  int v0; // esi
  kern_return_t result; // eax
  vm_map_t v2; // ebx
  vm_address_t address; // [esp+8h] [ebp-8h] BYREF
  int v4; // [esp+Ch] [ebp-4h] BYREF

  v0 = ~page_mask & (page_mask + **(_DWORD **)(dword_1E875C + 36)); /*0x107276*/
  result = active_u; /*0x107278*/
  if ( *(_DWORD *)(active_u + 628) >= v0 ) /*0x107283*/
  {
    v2 = *(_DWORD *)(*(_DWORD *)(active_threads + 12) + 12); /*0x107294*/
    lock_write(v2); /*0x107298*/
    ++*(_DWORD *)(v2 + 76); /*0x10729d*/
    if ( vm_map_lookup_entry(v2, v0, &v4) ) /*0x1072a9*/
    {
      return lock_done(v2); /*0x1072ed*/
    }
    else
    {
      address = *(_DWORD *)(v4 + 12); /*0x1072bb*/
      lock_done(v2); /*0x1072bf*/
      result = vm_allocate(v2, &address, v0 - address, 0); /*0x1072d1*/
      if ( result ) /*0x1072db*/
        return uprintf("could not sbrk, return = %d\n", result); /*0x1072e3*/
    }
  }
  else
  {
    *(_BYTE *)(dword_1E875C + 104) = 12; /*0x107285*/
  }
  return result; /*0x1072f5*/
}
