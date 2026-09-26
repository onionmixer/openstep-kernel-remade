/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x114f20. */
int __cdecl soaccept(int a1, int a2)
{
  int v2; // esi
  int v3; // ebx
  int v5; // [esp+0h] [ebp-8h]

  v2 = splnet(); /*0x114f2d*/
  if ( (*(_BYTE *)(a1 + 6) & 1) == 0 ) /*0x114f33*/
    panic(aSoacceptNofdre); /*0x114f3a*/
  *(_BYTE *)(a1 + 6) &= ~1u; /*0x114f42*/
  v3 = (*(int (__stdcall **)(int, int, _DWORD, int, _DWORD, int))(*(_DWORD *)(a1 + 12) + 28))(a1, 5, 0, a2, 0, v5); /*0x114f59*/
  splx(v2); /*0x114f5c*/
  return v3; /*0x114f66*/
}
