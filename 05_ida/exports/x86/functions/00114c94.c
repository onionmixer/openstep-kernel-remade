/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x114c94. */
int __cdecl sobind(int a1, int a2)
{
  int v2; // edi
  int v3; // ebx

  v2 = splnet(); /*0x114ca5*/
  v3 = (*(int (__cdecl **)(int, int, _DWORD, int, _DWORD))(*(_DWORD *)(a1 + 12) + 28))(a1, 2, 0, a2, 0); /*0x114cb7*/
  splx(v2); /*0x114cba*/
  return v3; /*0x114cc4*/
}
