/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12dbdc. */
int __cdecl sub_12DBDC(int a1, int a2)
{
  int result; // eax

  vattr_null((_BYTE *)a2); /*0x12dbe8*/
  *(_WORD *)(a2 + 4) = *(_WORD *)a1; /*0x12dbf0*/
  *(_WORD *)(a2 + 6) = *(_WORD *)(a1 + 4); /*0x12dbf8*/
  *(_WORD *)(a2 + 8) = *(_WORD *)(a1 + 8); /*0x12dc00*/
  *(_DWORD *)(a2 + 24) = *(_DWORD *)(a1 + 12); /*0x12dc07*/
  *(_DWORD *)(a2 + 32) = *(_DWORD *)(a1 + 16); /*0x12dc0d*/
  *(_DWORD *)(a2 + 36) = *(_DWORD *)(a1 + 20); /*0x12dc13*/
  result = *(_DWORD *)(a1 + 24); /*0x12dc16*/
  *(_DWORD *)(a2 + 40) = result; /*0x12dc19*/
  *(_DWORD *)(a2 + 44) = *(_DWORD *)(a1 + 28); /*0x12dc1f*/
  return result; /*0x12dc25*/
}
