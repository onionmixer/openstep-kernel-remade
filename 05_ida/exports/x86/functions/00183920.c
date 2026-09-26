/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x183920. */
void __cdecl sdstrategy(buf_t a1)
{
  void *v1; // edi
  vm_map_t v2; // esi
  int v3; // ecx
  int v4; // eax
  id v5; // eax

  v1 = (void *)sub_1840EC(*((_WORD *)a1 + 15)); /*0x183936*/
  if ( !v1
    || ((*(_DWORD *)a1 & 0x4000010) != 0x10
      ? (v2 = kernel_map)
      : (v2 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)a1 + 11) + 104) + 12)),
        !objc_msgSend(v1, sel_blockSize)) )
  {
    *((_WORD *)a1 + 14) = 6; /*0x183972*/
LABEL_12:
    *(_BYTE *)a1 |= 4u; /*0x1839d1*/
    biodone((int)a1); /*0x1839d5*/
    return; /*0x1839d5*/
  }
  v3 = *((_DWORD *)a1 + 9); /*0x18397c*/
  v4 = *((_DWORD *)a1 + 8); /*0x183985*/
  if ( (*(_BYTE *)a1 & 1) != 0 ) /*0x18398b*/
    v5 = objc_msgSend(v1, sel_readAsyncAt_length_buffer_pending_client_, v3, *((_DWORD *)a1 + 5), v4, a1, v2); /*0x183998*/
  else
    v5 = objc_msgSend(v1, sel_writeAsyncAt_length_buffer_pending_client_, v3, *((_DWORD *)a1 + 5), v4, a1, v2); /*0x1839ac*/
  if ( v5 ) /*0x1839b6*/
  {
    *((_WORD *)a1 + 14) = (unsigned __int16)objc_msgSend(v1, sel_errnoFromReturn_, v5); /*0x1839ca*/
    goto LABEL_12; /*0x1839ca*/
  }
}
