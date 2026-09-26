/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x151618. */
int __cdecl ipc_splay_traverse_start(int a1)
{
  int v1; // ecx
  _DWORD *v2; // edx
  int v3; // edx
  int v4; // eax

  v1 = *(_DWORD *)(a1 + 4); /*0x151620*/
  if ( v1 ) /*0x151625*/
  {
    v2 = *(_DWORD **)(a1 + 20); /*0x15162a*/
    **(_DWORD **)(a1 + 12) = *(_DWORD *)(v1 + 24); /*0x151630*/
    *v2 = *(_DWORD *)(v1 + 28); /*0x151635*/
    *(_DWORD *)(v1 + 24) = *(_DWORD *)(a1 + 8); /*0x15163a*/
    *(_DWORD *)(v1 + 28) = *(_DWORD *)(a1 + 16); /*0x151640*/
    v3 = 0; /*0x151643*/
    if ( *(_DWORD *)(v1 + 24) ) /*0x151645*/
    {
      do /*0x151656*/
      {
        v4 = *(_DWORD *)(v1 + 24); /*0x15164c*/
        *(_DWORD *)(v1 + 24) = v3; /*0x15164f*/
        v3 = v1; /*0x151652*/
        v1 = v4; /*0x151654*/
      }
      while ( *(_DWORD *)(v4 + 24) ); /*0x151656*/
    }
    *(_DWORD *)(a1 + 8) = v1; /*0x15165c*/
    *(_DWORD *)(a1 + 16) = v3; /*0x15165f*/
  }
  return v1; /*0x151667*/
}
