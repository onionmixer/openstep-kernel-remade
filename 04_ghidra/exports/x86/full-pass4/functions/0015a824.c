/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015a824 */

void _kfree(undefined4 param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = 0;
  uVar2 = param_2;
  uVar1 = _k_zone_elemsize;
  if (param_2 <= _k_zone_maxsize) {
    while (uVar2 = uVar1, uVar2 < param_2) {
      iVar3 = iVar3 + 1;
      uVar1 = (&_k_zone_elemsize)[iVar3];
    }
    if (uVar2 <= _k_zone_maxsize) {
      _zfree((&_k_zone)[iVar3],param_1);
      return;
    }
  }
  _kmem_free(_kalloc_map,param_1,uVar2);
  return;
}

