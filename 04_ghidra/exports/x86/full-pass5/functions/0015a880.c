/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015a880 */

void * _malloc(size_t param_1)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  uint *local_8;
  
  uVar5 = param_1 + 8;
  iVar4 = 0;
  uVar2 = uVar5;
  uVar1 = _k_zone_elemsize;
  if (uVar5 <= _k_zone_maxsize) {
    while (uVar2 = uVar1, uVar2 < uVar5) {
      iVar4 = iVar4 + 1;
      uVar1 = (&_k_zone_elemsize)[iVar4];
    }
  }
  if (_k_zone_maxsize < uVar2) {
    iVar4 = _kmem_alloc_wired(_kalloc_map,&local_8,uVar2);
    if (iVar4 != 0) {
      local_8 = (uint *)0x0;
    }
  }
  else {
    local_8 = (uint *)_zalloc((&_k_zone)[iVar4]);
  }
  puVar3 = local_8;
  if (local_8 == (uint *)0x0) {
    puVar3 = (uint *)0x0;
  }
  else {
    _bzero(local_8,uVar5);
    *puVar3 = uVar5;
    puVar3 = puVar3 + 2;
  }
  return puVar3;
}

