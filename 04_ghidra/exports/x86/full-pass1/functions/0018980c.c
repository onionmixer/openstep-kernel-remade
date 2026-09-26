/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018980c */

undefined4 _dma_buf_alloc(undefined4 *param_1,uint param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (param_2 < 0x10001) {
    puVar3 = (undefined4 *)&_dma_buf_sm;
    if (_page_size < param_2) {
      puVar3 = &_dma_buf_lg;
    }
    uVar1 = _spldma();
    puVar2 = (undefined4 *)puVar3[1];
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)(*(code *)*puVar3)();
      if (puVar2 != (undefined4 *)0x0) {
        puVar3[3] = puVar3[3] + 1;
      }
    }
    else {
      puVar3[1] = *puVar2;
      puVar3[2] = puVar3[2] + -1;
    }
    _splx(uVar1);
    if (puVar2 != (undefined4 *)0x0) {
      *param_1 = puVar2;
      param_1[1] = puVar3;
      return 1;
    }
  }
  return 0;
}

