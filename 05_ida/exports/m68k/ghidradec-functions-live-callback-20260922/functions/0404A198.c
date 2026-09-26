
undefined4 _kalloc_noblock(uint param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  undefined *puVar4;
  undefined4 uStack_8;
  
  iVar3 = 0;
  uVar2 = param_1;
  if (param_1 <= _k_zone_maxsize) {
    for (puVar4 = _k_zone_elemsize; uVar2 = *(uint *)puVar4, uVar2 < param_1;
        puVar4 = (undefined *)((int)puVar4 + 4)) {
      iVar3 = iVar3 + 1;
    }
    if (uVar2 <= _k_zone_maxsize) {
      uVar1 = _zalloc_noblock(*(undefined4 *)(_k_zone + iVar3 * 4));
      return uVar1;
    }
  }
  iVar3 = _kmem_alloc_zone(_kalloc_map,&uStack_8,uVar2,0);
  if (iVar3 != 0) {
    uStack_8 = 0;
  }
  return uStack_8;
}

