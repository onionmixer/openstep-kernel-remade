/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x114f6c. */
int __cdecl soconnect(int a1, int a2)
{
  int v3; // edi
  int v4; // ebx

  if ( (*(_BYTE *)(a1 + 2) & 2) != 0 ) /*0x114f79*/
    return 45; /*0x114f7b*/
  v3 = splnet(); /*0x114f89*/
  if ( (*(_BYTE *)(a1 + 6) & 6) != 0 && ((*(_BYTE *)(*(_DWORD *)(a1 + 12) + 10) & 4) != 0 || sodisconnect(a1)) ) /*0x114f9b*/
    v4 = 56; /*0x114fa9*/
  else
    v4 = (*(int (__cdecl **)(int, int, _DWORD, int, _DWORD))(*(_DWORD *)(a1 + 12) + 28))(a1, 4, 0, a2, 0); /*0x114fc3*/
  splx(v3); /*0x114fc9*/
  return v4; /*0x114fd3*/
}
