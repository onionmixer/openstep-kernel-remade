/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x189748. */
void dma_buf_initialize()
{
  vm_size_t v0; // ebx
  void *v1; // esp
  int v2; // esi
  int *v3; // ecx
  int v4; // ebx
  _BYTE *v5; // [esp-4h] [ebp-18h]
  _BYTE v6[12]; // [esp+0h] [ebp-14h] BYREF
  int *v7[2]; // [esp+Ch] [ebp-8h] BYREF

  v0 = 0x10000 / page_size + 1; /*0x18975e*/
  v1 = alloca(8 * v0); /*0x189768*/
  v2 = 0; /*0x18976c*/
  dma_buf_sm = (int)sub_1898BC; /*0x18976e*/
  dma_buf_lg = (int)sub_1898EC; /*0x189778*/
  do /*0x1897b3*/
  {
    if ( dma_buf_alloc(v7, page_size) != 1 ) /*0x18979a*/
      break; /*0x18979a*/
    v3 = v7[1]; /*0x18979f*/
    *(int **)&v6[8 * v2] = v7[0]; /*0x1897a2*/
    *(_DWORD *)&v6[8 * v2++ + 4] = v3; /*0x1897a5*/
    if ( --v0 == -1 ) /*0x1897ae*/
      break; /*0x1897ae*/
  }
  while ( (_WORD)page_size + LOWORD(v7[0]) ); /*0x1897b3*/
  if ( v2 ) /*0x1897c6*/
  {
    v4 = 8 * v2 - 8; /*0x1897c8*/
    do /*0x1897e2*/
    {
      v5 = &v6[v4]; /*0x1897d3*/
      v4 -= 8; /*0x1897d4*/
      --v2; /*0x1897d7*/
      dma_buf_free((int)v5); /*0x1897d8*/
    }
    while ( v2 ); /*0x1897e2*/
  }
  if ( dma_buf_alloc(v7, 0x10000u) == 1 ) /*0x1897f8*/
    dma_buf_free((int)v7); /*0x1897fb*/
}
