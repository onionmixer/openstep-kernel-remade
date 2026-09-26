/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x185b70. */
int __cdecl kdp_exception(int a1, _DWORD *a2, _WORD *a3, int a4, int a5, int a6)
{
  int result; // eax

  *(_BYTE *)a1 = 13; /*0x185b85*/
  *(_BYTE *)(a1 + 1) = byte_1F66B6; /*0x185b8e*/
  *(_DWORD *)(a1 + 4) = 0; /*0x185b91*/
  *(_WORD *)(a1 + 2) = 12; /*0x185b98*/
  *(_DWORD *)(a1 + 8) = 1; /*0x185b9e*/
  *(_DWORD *)(a1 + 12) = 0; /*0x185ba5*/
  *(_DWORD *)(a1 + 16) = a4; /*0x185bac*/
  *(_DWORD *)(a1 + 20) = a5; /*0x185bb2*/
  *(_DWORD *)(a1 + 24) = a6; /*0x185bb5*/
  *(_WORD *)(a1 + 2) += 16 * *(_WORD *)(a1 + 8); /*0x185bbe*/
  dword_1F66B8 = 1; /*0x185bc2*/
  *a3 = word_1F66B4; /*0x185bd3*/
  result = *(unsigned __int16 *)(a1 + 2); /*0x185bd6*/
  *a2 = result; /*0x185bda*/
  return result; /*0x185bdf*/
}
