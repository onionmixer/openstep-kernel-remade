/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x185b1c. */
int __cdecl kdp_setstate(int a1)
{
  int result; // eax

  result = dword_1F66AC; /*0x185b22*/
  *(_DWORD *)(dword_1F66AC + 44) = *(_DWORD *)a1; /*0x185b29*/
  *(_DWORD *)(result + 32) = *(_DWORD *)(a1 + 4); /*0x185b2f*/
  *(_DWORD *)(result + 40) = *(_DWORD *)(a1 + 8); /*0x185b35*/
  *(_DWORD *)(result + 36) = *(_DWORD *)(a1 + 12); /*0x185b3b*/
  *(_DWORD *)(result + 16) = *(_DWORD *)(a1 + 16); /*0x185b41*/
  *(_DWORD *)(result + 20) = *(_DWORD *)(a1 + 20); /*0x185b47*/
  *(_DWORD *)(result + 24) = *(_DWORD *)(a1 + 24); /*0x185b4d*/
  *(_DWORD *)(result + 64) = *(_DWORD *)(a1 + 36); /*0x185b53*/
  *(_DWORD *)(result + 56) = *(_DWORD *)(a1 + 40); /*0x185b59*/
  *(_WORD *)(result + 4) = *(_WORD *)(a1 + 56); /*0x185b60*/
  *(_WORD *)result = *(_WORD *)(a1 + 60); /*0x185b68*/
  return result; /*0x185b6d*/
}
