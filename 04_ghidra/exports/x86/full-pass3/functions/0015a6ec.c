/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015a6ec */

undefined4 _kalloc_noblock(uint param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  undefined4 local_8;
  
  iVar4 = 0;
  uVar3 = param_1;
  uVar1 = _k_zone_elemsize;
  if (param_1 <= _k_zone_maxsize) {
    while (uVar3 = uVar1, uVar3 < param_1) {
      iVar4 = iVar4 + 1;
      uVar1 = (&_k_zone_elemsize)[iVar4];
    }
    if (uVar3 <= _k_zone_maxsize) {
      uVar2 = _zalloc_noblock((&_k_zone)[iVar4]);
      return uVar2;
    }
  }
  iVar4 = _kmem_alloc_zone(_kalloc_map,&local_8,uVar3,0);
  if (iVar4 != 0) {
    local_8 = 0;
  }
  return local_8;
}

