/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cb174. */
void __cdecl sub_1CB174(_DWORD *a1, int a2)
{
  int v2; // ebx
  int v3; // esi
  void (__stdcall *v4)(int); // edx

  v2 = a1[3]; /*0x1cb17d*/
  v3 = a1[2]; /*0x1cb180*/
  while ( --v3 != -1 ) /*0x1cb1c6*/
  {
    if ( *(_DWORD *)v2 ) /*0x1cb188*/
    {
      if ( a2 ) /*0x1cb19c*/
        v4 = *(void (__stdcall **)(int))(*a1 + 8); /*0x1cb1a0*/
      else
        v4 = (void (__stdcall *)(int))NXNoEffectFree; /*0x1cb1a8*/
      sub_1CB124(v4, *(_DWORD *)v2, *(_DWORD **)(v2 + 4), a1[4]); /*0x1cb1ae*/
      *(_DWORD *)v2 = 0; /*0x1cb1b3*/
      *(_DWORD *)(v2 + 4) = 0; /*0x1cb1b9*/
    }
    v2 += 8; /*0x1cb1c3*/
  }
}
