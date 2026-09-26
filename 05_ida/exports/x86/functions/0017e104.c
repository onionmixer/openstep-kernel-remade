/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17e104. */
_DWORD *__cdecl vnode_uncache(int a1)
{
  _DWORD *result; // eax
  int v2; // esi
  void *v3; // eax
  int v4; // edx
  __int16 v5; // ax
  int v6; // edx
  __int16 v7; // ax
  int v8; // eax

  result = *(_DWORD **)a1; /*0x17e10c*/
  if ( *(_DWORD *)a1 && *result ) /*0x17e116*/
  {
    v2 = 0; /*0x17e11b*/
    v3 = *(void **)(a1 + 28); /*0x17e11d*/
    if ( v3 == &ufs_vnodeops ) /*0x17e125*/
    {
      v4 = *(_DWORD *)(a1 + 48); /*0x17e127*/
      v5 = *(_WORD *)(v4 + 68); /*0x17e12a*/
      if ( (v5 & 1) != 0 ) /*0x17e130*/
      {
        v2 = 1; /*0x17e132*/
        LOBYTE(v5) = v5 & 0xFE; /*0x17e133*/
        *(_WORD *)(v4 + 68) = v5; /*0x17e135*/
      }
    }
    else if ( v3 == &nfs_vnodeops ) /*0x17e141*/
    {
      v6 = *(_DWORD *)(a1 + 48); /*0x17e143*/
      v7 = *(_WORD *)(v6 + 96); /*0x17e146*/
      if ( (v7 & 1) != 0 ) /*0x17e14c*/
      {
        v2 = 1; /*0x17e14e*/
        LOBYTE(v7) = v7 & 0xFE; /*0x17e153*/
        *(_WORD *)(v6 + 96) = v7; /*0x17e155*/
      }
    }
    mfs_uncache(a1); /*0x17e15a*/
    v8 = vm_object_lookup(**(_DWORD **)a1); /*0x17e166*/
    result = (_DWORD *)vm_object_cache_object(v8, 0); /*0x17e16f*/
    if ( v2 ) /*0x17e176*/
    {
      result = *(_DWORD **)(a1 + 28); /*0x17e178*/
      if ( result == (_DWORD *)&ufs_vnodeops ) /*0x17e180*/
      {
        result = *(_DWORD **)(a1 + 48); /*0x17e182*/
        *((_BYTE *)result + 68) |= 1u; /*0x17e185*/
      }
      else if ( result == (_DWORD *)&nfs_vnodeops ) /*0x17e191*/
      {
        result = *(_DWORD **)(a1 + 48); /*0x17e193*/
        *((_BYTE *)result + 96) |= 1u; /*0x17e196*/
      }
    }
  }
  return result; /*0x17e19d*/
}
