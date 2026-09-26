/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x192e28. */
int __cdecl sub_192E28(int a1)
{
  int v1; // ecx
  unsigned int *v2; // edx
  unsigned int v3; // esi
  int v4; // ebx
  int result; // eax

  *(_DWORD *)(a1 + 48) = _byteswap_ulong(*(_DWORD *)(a1 + 48)); /*0x192e36*/
  *(_DWORD *)(a1 + 52) = _byteswap_ulong(*(_DWORD *)(a1 + 52)); /*0x192e3e*/
  *(_DWORD *)(a1 + 56) = _byteswap_ulong(*(_DWORD *)(a1 + 56)); /*0x192e46*/
  *(_DWORD *)(a1 + 60) = _byteswap_ulong(*(_DWORD *)(a1 + 60)); /*0x192e4e*/
  *(_DWORD *)(a1 + 64) = _byteswap_ulong(*(_DWORD *)(a1 + 64)); /*0x192e56*/
  *(_WORD *)(a1 + 68) = __ROR2__(*(_WORD *)(a1 + 68), 8); /*0x192e61*/
  *(_WORD *)(a1 + 70) = __ROR2__(*(_WORD *)(a1 + 70), 8); /*0x192e6d*/
  *(_WORD *)(a1 + 72) = __ROR2__(*(_WORD *)(a1 + 72), 8); /*0x192e79*/
  *(_WORD *)(a1 + 74) = __ROR2__(*(_WORD *)(a1 + 74), 8); /*0x192e85*/
  *(_WORD *)(a1 + 76) = __ROR2__(*(_WORD *)(a1 + 76), 8); /*0x192e91*/
  *(_WORD *)(a1 + 78) = __ROR2__(*(_WORD *)(a1 + 78), 8); /*0x192e9d*/
  v1 = 0; /*0x192ea1*/
  v2 = (unsigned int *)(a1 + 80); /*0x192ea3*/
  do /*0x192eb5*/
  {
    *v2 = _byteswap_ulong(*v2); /*0x192eac*/
    ++v2; /*0x192eae*/
    ++v1; /*0x192eb1*/
  }
  while ( v1 < 2 ); /*0x192eb5*/
  v3 = 0; /*0x192eb7*/
  v4 = 148; /*0x192eb9*/
  do /*0x192ed3*/
  {
    result = byte_swap_partition(v4 + a1); /*0x192ec4*/
    v4 += 48; /*0x192ecc*/
    ++v3; /*0x192ecf*/
  }
  while ( v3 <= 7 ); /*0x192ed3*/
  return result; /*0x192ed8*/
}
