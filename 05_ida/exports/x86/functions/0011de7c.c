/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11de7c. */
int __cdecl vn_rdwr(int a1, int *a2, int a3, int a4, int a5, int a6, int a7, _DWORD *a8)
{
  int v9; // ebx
  _DWORD v10[2]; // [esp+Ch] [ebp-20h] BYREF
  _DWORD v11[5]; // [esp+14h] [ebp-18h] BYREF
  int v12; // [esp+28h] [ebp-4h]

  if ( a1 == 1 && (*(_BYTE *)(a2[9] + 12) & 1) != 0 ) /*0x11de9a*/
    return 30; /*0x11de9c*/
  v10[0] = a3; /*0x11deab*/
  v10[1] = a4; /*0x11deae*/
  v11[0] = v10; /*0x11deb4*/
  v11[1] = 1; /*0x11deb7*/
  v11[2] = a5; /*0x11dec1*/
  v11[3] = a6; /*0x11dec7*/
  v12 = a4; /*0x11deca*/
  if ( a2[10] != 1 || (*(_BYTE *)(*(_DWORD *)active_u + 22) & 2) != 0 ) /*0x11dede*/
  {
    v9 = (*(int (__cdecl **)(int *, _DWORD *, int, int, _DWORD))(a2[7] + 8))( /*0x11df23*/
           a2,
           v11,
           a1,
           a7,
           *(_DWORD *)(active_u + 28));
  }
  else
  {
    map_vnode(a2); /*0x11dee1*/
    v9 = mfs_io(a2, v11, a1, a7, *(_WORD **)(active_u + 28)); /*0x11defe*/
    unmap_vnode(a2); /*0x11df01*/
  }
  if ( a8 ) /*0x11df29*/
  {
    *a8 = v12; /*0x11df31*/
  }
  else if ( v12 ) /*0x11df3c*/
  {
    if ( !v9 ) /*0x11df40*/
      return 5; /*0x11df42*/
  }
  return v9; /*0x11df4c*/
}
