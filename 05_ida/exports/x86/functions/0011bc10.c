/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11bc10. */
int __cdecl vno_select(int a1, int a2)
{
  int v2; // edx
  unsigned int v3; // eax

  v2 = *(_DWORD *)(a1 + 24); /*0x11bc17*/
  v3 = *(_DWORD *)(v2 + 40); /*0x11bc1a*/
  if ( v3 == 4 || v3 >= 4 && v3 <= 9 && v3 >= 8 ) /*0x11bc2c*/
    return (*(int (__stdcall **)(int, int, _DWORD))(*(_DWORD *)(v2 + 28) + 16))(v2, a2, *(_DWORD *)(a1 + 32)); /*0x11bc3d*/
  else
    return 1; /*0x11bc44*/
}
