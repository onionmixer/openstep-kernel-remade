/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00188edc */

undefined4 _dma_xfer(uint *param_1,uint *param_2)

{
  void *pvVar1;
  uint uVar2;
  int iVar3;
  
  if ((((param_1[5] & 0x10) == 0) || (*param_1 < 0x1000000)) || ((param_1[5] & 2) != 0)) {
    *param_2 = *param_1;
  }
  else {
    iVar3 = _dma_buf_alloc(param_1 + 3,param_1[1]);
    if (iVar3 == 0) {
      return 0;
    }
    uVar2 = param_1[5];
    *(byte *)(param_1 + 5) = (byte)uVar2 | 2;
    pvVar1 = (void *)param_1[3];
    if (((byte)uVar2 & 8) == 0) {
      _bcopy((void *)*param_1,pvVar1,param_1[1]);
    }
    *param_2 = (uint)pvVar1;
  }
  *(byte *)(param_1 + 5) = (byte)param_1[5] | 1;
  return 1;
}

