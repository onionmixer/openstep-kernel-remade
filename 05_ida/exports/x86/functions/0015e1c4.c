/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15e1c4. */
__int16 __cdecl map_vnode(int *a1)
{
  int v1; // ebx
  __int16 result; // ax
  int v3; // esi
  int v4; // eax
  unsigned int v5; // eax

  v1 = *a1; /*0x15e1cd*/
  result = *(_WORD *)(*a1 + 4); /*0x15e1cf*/
  *(_WORD *)(*a1 + 4) = result + 1; /*0x15e1d3*/
  if ( result <= 0 && (*(_BYTE *)(v1 + 56) & 0x10) == 0 ) /*0x15e1e4*/
  {
    vmp_get(v1); /*0x15e1eb*/
    v3 = vnode_pager_setup(a1, 0, 1); /*0x15e1fa*/
    *(_DWORD *)v1 = v3; /*0x15e1fc*/
    lock_write(&vm_alloc_lock); /*0x15e203*/
    *(_DWORD *)(v1 + 36) = vm_object_lookup(v3); /*0x15e20e*/
    ++dword_1F651C; /*0x15e211*/
    if ( *(_DWORD *)(v1 + 36) ) /*0x15e21a*/
    {
      ++dword_1F6520; /*0x15e244*/
    }
    else
    {
      v4 = vm_object_allocate(0); /*0x15e222*/
      *(_DWORD *)(v1 + 36) = v4; /*0x15e227*/
      vm_object_enter(v4, v3); /*0x15e22c*/
      vm_object_setpager(*(_DWORD *)(v1 + 36), v3, 0); /*0x15e23a*/
    }
    lock_done(&vm_alloc_lock); /*0x15e24f*/
    *(_DWORD *)(v1 + 52) = 0; /*0x15e254*/
    *(_DWORD *)(v1 + 20) = vnode_size(a1); /*0x15e261*/
    *(_DWORD *)(v1 + 8) = 0; /*0x15e264*/
    *(_DWORD *)(v1 + 12) = 0; /*0x15e26b*/
    *(_DWORD *)(v1 + 16) = 0; /*0x15e272*/
    *(_BYTE *)(v1 + 56) |= 0x10u; /*0x15e279*/
    v5 = *(_DWORD *)(v1 + 20); /*0x15e280*/
    if ( v5 ) /*0x15e285*/
    {
      if ( mfs_max_window > v5 ) /*0x15e28d*/
        remap_vnode(a1, 0, *(_DWORD *)(v1 + 20)); /*0x15e293*/
    }
    return vmp_put(v1); /*0x15e29c*/
  }
  return result; /*0x15e2a4*/
}
