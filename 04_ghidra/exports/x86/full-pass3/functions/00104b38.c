/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00104b38 */

void _expand_fdlist(int param_1,int param_2)

{
  size_t sVar1;
  size_t sVar2;
  size_t sVar3;
  void *pvVar4;
  void *pvVar5;
  
  if (*(int *)(param_1 + 0x15c) <= param_2) {
    sVar1 = param_2 + 1;
    sVar2 = sVar1 * 4;
    pvVar4 = (void *)_kalloc(sVar2);
    pvVar5 = (void *)_kalloc(sVar1);
    sVar3 = *(size_t *)(param_1 + 0x15c);
    if (param_2 < (int)sVar3) {
      _kfree(pvVar4,sVar2);
      _kfree(pvVar5,sVar1);
    }
    else {
      _bzero(pvVar4,sVar2);
      _bzero(pvVar5,sVar1);
      if (sVar3 != 0) {
        _bcopy(*(void **)(param_1 + 0x150),pvVar4,sVar3 * 4);
        _bcopy(*(void **)(param_1 + 0x154),pvVar5,sVar3);
        _kfree(*(undefined4 *)(param_1 + 0x150),sVar3 * 4);
        _kfree(*(undefined4 *)(param_1 + 0x154),sVar3);
      }
      *(void **)(param_1 + 0x150) = pvVar4;
      *(void **)(param_1 + 0x154) = pvVar5;
      *(size_t *)(param_1 + 0x15c) = sVar1;
    }
  }
  return;
}

