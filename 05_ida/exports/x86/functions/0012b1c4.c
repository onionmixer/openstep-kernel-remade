/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12b1c4. */
int __cdecl tcp_disconnect(int a1)
{
  int v1; // eax
  int v2; // esi
  int v3; // ebx
  int v4; // eax

  v1 = *(_DWORD *)(a1 + 32); /*0x12b1cc*/
  v2 = *(_DWORD *)(v1 + 28); /*0x12b1cf*/
  if ( *(__int16 *)(a1 + 8) <= 3 ) /*0x12b1d7*/
    return tcp_close((_DWORD *)a1); /*0x12b1df*/
  if ( *(char *)(v2 + 2) < 0 && !*(_WORD *)(v2 + 4) ) /*0x12b1ea*/
    return tcp_drop(a1, 0); /*0x12b1f9*/
  soisdisconnecting(*(_DWORD *)(v1 + 28)); /*0x12b201*/
  sbflush((unsigned __int16 *)(v2 + 36)); /*0x12b20a*/
  v4 = tcp_usrclosed(a1); /*0x12b210*/
  v3 = v4; /*0x12b215*/
  if ( v4 ) /*0x12b21c*/
    tcp_output(v4); /*0x12b21f*/
  return v3; /*0x12b229*/
}
