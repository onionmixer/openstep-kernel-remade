/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018987c */

void _dma_buf_free(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  puVar1 = (undefined4 *)*param_1;
  if (puVar1 != (undefined4 *)0x0) {
    iVar2 = param_1[1];
    uVar3 = _spldma();
    *puVar1 = *(undefined4 *)(iVar2 + 4);
    *(undefined4 **)(iVar2 + 4) = puVar1;
    *(int *)(iVar2 + 8) = *(int *)(iVar2 + 8) + 1;
    _splx(uVar3);
    *param_1 = 0;
    param_1[1] = 0;
  }
  return;
}

