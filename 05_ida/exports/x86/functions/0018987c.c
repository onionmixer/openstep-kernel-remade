/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18987c. */
void __cdecl dma_buf_free(int a1)
{
  _DWORD *v1; // esi
  int v2; // ebx
  int v3; // eax

  v1 = *(_DWORD **)a1; /*0x189885*/
  if ( *(_DWORD *)a1 ) /*0x189885*/
  {
    v2 = *(_DWORD *)(a1 + 4); /*0x18988b*/
    v3 = spldma(); /*0x18988e*/
    *v1 = *(_DWORD *)(v2 + 4); /*0x189896*/
    *(_DWORD *)(v2 + 4) = v1; /*0x189898*/
    ++*(_DWORD *)(v2 + 8); /*0x18989b*/
    splx(v3); /*0x18989f*/
    *(_DWORD *)a1 = 0; /*0x1898a4*/
    *(_DWORD *)(a1 + 4) = 0; /*0x1898aa*/
  }
}
