/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x119484. */
int __cdecl dounmount(int a1)
{
  int v1; // edi
  int result; // eax
  int v3; // ebx

  v1 = *(_DWORD *)(a1 + 8); /*0x11948d*/
  result = vfs_lock(a1); /*0x119491*/
  if ( !result ) /*0x11949d*/
  {
    dnlc_purge(); /*0x11949f*/
    (*(void (__cdecl **)(int))(*(_DWORD *)(a1 + 4) + 16))(a1); /*0x1194ab*/
    v3 = (*(int (__cdecl **)(int))(*(_DWORD *)(a1 + 4) + 4))(a1); /*0x1194b6*/
    if ( v3 ) /*0x1194bd*/
    {
      vfs_unlock(a1); /*0x1194c0*/
    }
    else
    {
      if ( v1 ) /*0x1194ca*/
      {
        vn_rele(v1); /*0x1194cd*/
        vfs_remove(a1); /*0x1194d3*/
      }
      kfree(a1, 300); /*0x1194e1*/
    }
    return v3; /*0x1194e6*/
  }
  return result; /*0x1194eb*/
}
