/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x114fdc. */
int __cdecl soconnect2(int a1, int a2)
{
  int v2; // edi
  int v3; // ebx

  v2 = splnet(); /*0x114fed*/
  v3 = (*(int (__cdecl **)(int, int, _DWORD, int, _DWORD))(*(_DWORD *)(a1 + 12) + 28))(a1, 17, 0, a2, 0); /*0x114fff*/
  splx(v2); /*0x115002*/
  return v3; /*0x11500c*/
}
