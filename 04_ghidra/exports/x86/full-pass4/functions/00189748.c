/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00189748 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _dma_buf_initialize(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uStack_24;
  uint auStack_20 [2];
  undefined4 local_c;
  undefined4 local_8;
  
  iVar1 = (int)(0x10000 / (ulonglong)_page_size) + 1;
  iVar4 = iVar1 * -8;
  iVar6 = 0;
  __dma_buf_sm = FUN_001898bc;
  _dma_buf_lg = FUN_001898ec;
  iVar5 = iVar1;
  while( true ) {
    auStack_20[iVar1 * -2 + 1] = _page_size;
    auStack_20[iVar1 * -2] = (uint)&local_c;
    (&uStack_24)[iVar1 * -2] = 0x189794;
    iVar3 = _dma_buf_alloc();
    uVar2 = local_8;
    if (iVar3 != 1) break;
    *(undefined4 *)(&stack0xffffffe8 + iVar6 * 8 + iVar4) = local_c;
    *(undefined4 *)(&stack0xffffffec + iVar6 * 8 + iVar4) = uVar2;
    iVar6 = iVar6 + 1;
    iVar5 = iVar5 + -1;
    if ((iVar5 == -1) || ((short)((short)local_c + (short)_page_size) == 0)) break;
  }
  if (iVar6 != 0) {
    iVar5 = iVar6 * 8;
    do {
      iVar5 = iVar5 + -8;
      auStack_20[iVar1 * -2 + 1] = (int)auStack_20 + iVar5 + iVar4 + 8;
      iVar6 = iVar6 + -1;
      auStack_20[iVar1 * -2] = 0x1897dd;
      _dma_buf_free();
    } while (iVar6 != 0);
  }
  auStack_20[iVar1 * -2 + 1] = 0x10000;
  auStack_20[iVar1 * -2] = (uint)&local_c;
  (&uStack_24)[iVar1 * -2] = 0x1897f2;
  iVar4 = _dma_buf_alloc();
  if (iVar4 == 1) {
    auStack_20[iVar1 * -2 + 1] = (uint)&local_c;
    auStack_20[iVar1 * -2] = 0x189800;
    _dma_buf_free();
  }
  return;
}

