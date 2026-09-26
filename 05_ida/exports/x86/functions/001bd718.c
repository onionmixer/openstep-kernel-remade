/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bd718. */
void __cdecl put_partition(int a1, int a2)
{
  *(_DWORD *)a2 = _byteswap_ulong(*(_DWORD *)a1); /*0x1bd727*/
  *(_DWORD *)(a2 + 4) = _byteswap_ulong(*(_DWORD *)(a1 + 4)); /*0x1bd72e*/
  *(_WORD *)(a2 + 8) = __ROR2__(*(_WORD *)(a1 + 8), 8); /*0x1bd739*/
  *(_WORD *)(a2 + 10) = __ROR2__(*(_WORD *)(a1 + 10), 8); /*0x1bd745*/
  *(_BYTE *)(a2 + 12) = *(_BYTE *)(a1 + 12); /*0x1bd74c*/
  *(_WORD *)(a2 + 14) = __ROR2__(*(_WORD *)(a1 + 14), 8); /*0x1bd757*/
  *(_WORD *)(a2 + 16) = __ROR2__(*(_WORD *)(a1 + 16), 8); /*0x1bd763*/
  *(_BYTE *)(a2 + 18) = *(_BYTE *)(a1 + 18); /*0x1bd76a*/
  *(_BYTE *)(a2 + 19) = *(_BYTE *)(a1 + 19); /*0x1bd770*/
  bcopy((const void *)(a1 + 20), (void *)(a2 + 20), 0x10u); /*0x1bd77d*/
  *(_BYTE *)(a2 + 36) = *(_BYTE *)(a1 + 36); /*0x1bd788*/
  bcopy((const void *)(a1 + 37), (void *)(a2 + 37), 8u); /*0x1bd795*/
}
