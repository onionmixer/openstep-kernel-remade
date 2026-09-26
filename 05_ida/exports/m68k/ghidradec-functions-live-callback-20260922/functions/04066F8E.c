
void _dma_cleanup(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  _dma_abort(param_1);
  if (param_2 < 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aDmaCleanupNega);
  }
  if ((sword)*(undefined4 *)(param_1 + 0x2c) < 0) {
    iVar2 = *(int *)(param_1 + 0xf0) + *(int *)(param_1 + 0xec);
    if (*(int *)(param_1 + 0x20) != 0) {
      iVar2 = iVar2 - param_2;
    }
    uVar1 = _min(*(int *)(param_1 + 0xec),iVar2);
    _vcopy(*(int *)(param_1 + 0xe8) + *(int *)(param_1 + 0xe4),*(undefined4 *)(param_1 + 0xf4),
           *(undefined4 *)(param_1 + 0xe4),*(undefined4 *)(param_1 + 0xf4),uVar1);
    iVar2 = iVar2 - *(int *)(param_1 + 0xec);
    if (0 < iVar2) {
      uVar1 = _pmap_kernel(*(int *)(param_1 + 0xe4) + *(int *)(param_1 + 0xec),
                           *(undefined4 *)(param_1 + 0xf4),iVar2);
      _vcopy(*(undefined4 *)(param_1 + 0x3c),uVar1);
    }
    *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) & 0xffff7fff;
  }
  else if (param_2 < *(int *)(param_1 + 0x34)) {
    _bcopy(*(undefined4 *)(param_1 + 0x3c),*(undefined4 *)(param_1 + 0x30),
           *(int *)(param_1 + 0x34) - param_2);
  }
  return;
}

