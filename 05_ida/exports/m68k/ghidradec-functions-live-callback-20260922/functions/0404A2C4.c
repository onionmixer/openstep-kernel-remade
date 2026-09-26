
void _kfree(undefined4 param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  undefined *puVar3;
  
  iVar2 = 0;
  uVar1 = param_2;
  if (param_2 <= _k_zone_maxsize) {
    for (puVar3 = _k_zone_elemsize; uVar1 = *(uint *)puVar3, uVar1 < param_2;
        puVar3 = (undefined *)((int)puVar3 + 4)) {
      iVar2 = iVar2 + 1;
    }
    if (uVar1 <= _k_zone_maxsize) {
      _zfree(*(undefined4 *)(_k_zone + iVar2 * 4),param_1);
      return;
    }
  }
  _kmem_free(_kalloc_map,param_1,uVar1);
  return;
}

