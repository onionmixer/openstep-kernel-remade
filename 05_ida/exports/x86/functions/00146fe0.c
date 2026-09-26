/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x146fe0. */
char __cdecl ipc_kmsg_destroy(_DWORD *a1)
{
  _DWORD *v1; // esi
  int v2; // edx
  _DWORD *v3; // eax
  _DWORD *v4; // eax
  _DWORD *v5; // edx
  _DWORD *v6; // ebx

  v1 = (_DWORD *)(active_threads + 164); /*0x146fef*/
  v2 = *(_DWORD *)(active_threads + 164); /*0x146ff5*/
  LOBYTE(v3) = v2 == 0; /*0x146ffd*/
  if ( v2 ) /*0x147005*/
  {
    v3 = *(_DWORD **)(v2 + 4); /*0x147014*/
    *a1 = v2; /*0x147017*/
    a1[1] = v3; /*0x147019*/
    *(_DWORD *)(v2 + 4) = a1; /*0x14701c*/
    *v3 = a1; /*0x14701f*/
  }
  else
  {
    *(_DWORD *)(active_threads + 164) = a1; /*0x147007*/
    *a1 = a1; /*0x14700d*/
    a1[1] = a1; /*0x14700f*/
  }
  if ( !v2 ) /*0x147023*/
  {
    while ( 1 ) /*0x14706b*/
    {
      v6 = (_DWORD *)*v1; /*0x14706b*/
      if ( !*v1 ) /*0x14706b*/
        break; /*0x14706b*/
      ipc_kmsg_clean(*v1); /*0x147029*/
      v4 = (_DWORD *)*v6; /*0x147031*/
      v5 = (_DWORD *)v6[1]; /*0x147033*/
      if ( (_DWORD *)*v6 == v6 ) /*0x147038*/
      {
        *v1 = 0; /*0x14703a*/
      }
      else
      {
        if ( (_DWORD *)*v1 == v6 ) /*0x147052*/
          *v1 = v4; /*0x147054*/
        v4[1] = v5; /*0x147056*/
        *v5 = v4; /*0x147059*/
      }
      if ( (int)v6[2] > 0 ) /*0x147060*/
        LOBYTE(v3) = kfree((int)v6, v6[2]); /*0x147046*/
      else
        LOBYTE(v3) = ipc_kmsg_free(v6); /*0x147063*/
    }
  }
  return (char)v3; /*0x147074*/
}
