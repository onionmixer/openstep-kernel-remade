/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11e474. */
int __cdecl vn_close(_DWORD *a1, int a2, int a3)
{
  int v3; // ebx
  int v4; // eax
  int v5; // edx

  if ( a1[10] == 1 ) /*0x11e484*/
    unmap_vnode(a1); /*0x11e487*/
  v3 = (*(int (__cdecl **)(_DWORD *, int, int, _DWORD))(a1[7] + 4))(a1, a2, a3, *(_DWORD *)(active_u + 28)); /*0x11e4a7*/
  v4 = *a1; /*0x11e4ac*/
  if ( *a1 ) /*0x11e4ac*/
  {
    v5 = *(_DWORD *)(v4 + 52); /*0x11e4b2*/
    if ( v5 ) /*0x11e4b7*/
    {
      v3 = *(_DWORD *)(v4 + 52); /*0x11e4b9*/
      *(_DWORD *)(v4 + 52) = 0; /*0x11e4bb*/
      *(_BYTE *)(dword_1E875C + 104) = v5; /*0x11e4c7*/
      do /*0x11e4ff*/
      {
        if ( !fspause(a2 & 0x1000) ) /*0x11e4d4*/
          break; /*0x11e4de*/
        v3 = *(_DWORD *)(*a1 + 52); /*0x11e4e2*/
        *(_DWORD *)(*a1 + 52) = 0; /*0x11e4e5*/
        *(_BYTE *)(dword_1E875C + 104) = v3; /*0x11e4f1*/
        mfs_fsync(a1); /*0x11e4f5*/
      }
      while ( v3 ); /*0x11e4ff*/
    }
  }
  return v3; /*0x11e506*/
}
