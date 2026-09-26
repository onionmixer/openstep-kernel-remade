/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c87e0 */

undefined4 _IOMallocLow(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  
  puVar2 = (undefined4 *)_IOMalloc(8);
  iVar3 = _dma_buf_alloc(puVar2,param_1);
  if (iVar3 == 0) {
    _IOFree(puVar2,8);
    uVar4 = 0;
  }
  else {
    puVar5 = (undefined4 *)_IOMalloc(0xc);
    *puVar5 = puVar2;
    if ((undefined4 **)_dmaBufQueue == &_dmaBufQueue) {
      _dmaBufQueue = puVar5;
      DAT_001f7494 = puVar5;
      puVar5[1] = &_dmaBufQueue;
      puVar5[2] = &_dmaBufQueue;
    }
    else {
      puVar5[2] = DAT_001f7494;
      puVar5[1] = &_dmaBufQueue;
      puVar1 = DAT_001f7494 + 1;
      DAT_001f7494 = puVar5;
      *puVar1 = puVar5;
    }
    uVar4 = *puVar2;
  }
  return uVar4;
}

