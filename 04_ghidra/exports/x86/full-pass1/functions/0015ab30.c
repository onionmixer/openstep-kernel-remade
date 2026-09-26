/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015ab30 */

void _free(void *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  if (param_1 != (void *)0x0) {
    uVar1 = *(uint *)((int)param_1 + -8);
    iVar4 = 0;
    uVar3 = uVar1;
    uVar2 = _k_zone_elemsize;
    if (uVar1 <= _k_zone_maxsize) {
      while (uVar3 = uVar2, uVar3 < uVar1) {
        iVar4 = iVar4 + 1;
        uVar2 = (&_k_zone_elemsize)[iVar4];
      }
      if (uVar3 <= _k_zone_maxsize) {
        _zfree((&_k_zone)[iVar4],(int)param_1 + -8);
        return;
      }
    }
    _kmem_free(_kalloc_map,(int)param_1 + -8,uVar3);
  }
  return;
}

