/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14ddf8. */
int __cdecl ipc_right_inuse(unsigned int a1, unsigned int a2, int *a3)
{
  int v3; // esi
  int v4; // eax
  int v5; // ecx
  int v6; // ebx
  int v7; // eax

  v3 = *a3; /*0x14de01*/
  if ( (*a3 & 0x1F0000) != 0 ) /*0x14de0a*/
  {
    v4 = *a3 & 0x1F0000; /*0x14de05*/
    v5 = v4; /*0x14de10*/
    if ( (v3 & 0x400000) == 0 || v4 != 0x10000 && v4 != 0x40000 ) /*0x14de2c*/
      goto LABEL_14; /*0x14de2c*/
    v6 = a3[1]; /*0x14de2e*/
    do /*0x14de46*/
    {
      while ( *(_DWORD *)v6 ) /*0x14de34*/
        ; /*0x14de36*/
    }
    while ( _InterlockedExchange((volatile __int32 *)v6, 1) == 1 ); /*0x14de46*/
    v7 = *(_DWORD *)(v6 + 8) >> 31; /*0x14de4b*/
    _InterlockedExchange((volatile __int32 *)v6, 0); /*0x14de50*/
    if ( v7 ) /*0x14de54*/
    {
LABEL_14:
      _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x14dea9*/
      return 1; /*0x14deb1*/
    }
    if ( v5 == 0x10000 ) /*0x14de5c*/
    {
      if ( (v3 & 0x200000) != 0 ) /*0x14de64*/
        ipc_marequest_cancel(a1, a2); /*0x14de6e*/
      ipc_hash_delete(a1, v6, a2, (int)a3); /*0x14de80*/
    }
    ipc_object_release(v6); /*0x14de89*/
    a3[2] = 0; /*0x14de8e*/
    a3[1] = 0; /*0x14de95*/
    *a3 &= 0xFF800000; /*0x14de9c*/
  }
  return 0; /*0x14deb9*/
}
