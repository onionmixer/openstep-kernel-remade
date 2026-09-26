/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015a9a8 */

void * _realloc(void *param_1,size_t param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  uint *puVar5;
  uint uVar6;
  uint *local_8;
  
  puVar5 = (uint *)((int)param_1 + -8);
  if (param_1 == (void *)0x0) {
    uVar6 = param_2 + 8;
    iVar3 = 0;
    uVar1 = uVar6;
    if (uVar6 <= _k_zone_maxsize) {
      iVar3 = 0;
      uVar1 = _k_zone_elemsize;
      while (uVar1 < uVar6) {
        iVar3 = iVar3 + 1;
        uVar1 = (&_k_zone_elemsize)[iVar3];
      }
    }
    if (_k_zone_maxsize < uVar1) {
      iVar3 = _kmem_alloc_wired(_kalloc_map,&local_8,uVar1);
      if (iVar3 != 0) {
        local_8 = (uint *)0x0;
      }
    }
    else {
      local_8 = (uint *)_zalloc((&_k_zone)[iVar3]);
    }
    puVar4 = local_8;
    if (local_8 == (uint *)0x0) {
      return (void *)0x0;
    }
    _bzero(local_8,uVar6);
    *puVar4 = uVar6;
    goto LAB_0015ab22;
  }
  uVar2 = param_2 + 8;
  iVar3 = 0;
  uVar1 = uVar2;
  uVar6 = _k_zone_elemsize;
  if (_k_zone_maxsize < uVar2) {
LAB_0015aa84:
    iVar3 = _kmem_alloc_wired(_kalloc_map,&local_8,uVar1);
    if (iVar3 != 0) {
      local_8 = (uint *)0x0;
    }
  }
  else {
    while (uVar1 = uVar6, uVar1 < uVar2) {
      iVar3 = iVar3 + 1;
      uVar6 = (&_k_zone_elemsize)[iVar3];
    }
    if (_k_zone_maxsize < uVar1) goto LAB_0015aa84;
    local_8 = (uint *)_zalloc((&_k_zone)[iVar3]);
  }
  puVar4 = local_8;
  if (local_8 == (uint *)0x0) {
    return (void *)0x0;
  }
  *local_8 = param_2 + 8;
  uVar1 = *puVar5;
  if (param_2 < uVar1) {
    uVar1 = param_2;
  }
  _bcopy(param_1,local_8 + 2,uVar1);
  uVar1 = *puVar5;
  iVar3 = 0;
  uVar6 = uVar1;
  uVar2 = _k_zone_elemsize;
  if (uVar1 <= _k_zone_maxsize) {
    while (uVar6 = uVar2, uVar6 < uVar1) {
      iVar3 = iVar3 + 1;
      uVar2 = (&_k_zone_elemsize)[iVar3];
    }
    if (uVar6 <= _k_zone_maxsize) {
      _zfree((&_k_zone)[iVar3],puVar5);
      goto LAB_0015ab22;
    }
  }
  _kmem_free(_kalloc_map,puVar5,uVar6);
LAB_0015ab22:
  return puVar4 + 2;
}

