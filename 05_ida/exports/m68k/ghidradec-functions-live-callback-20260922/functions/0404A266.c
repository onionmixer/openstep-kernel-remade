
undefined4 _kget(uint param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined *puVar4;
  
  if (param_1 <= _k_zone_maxsize) {
    puVar4 = _k_zone_elemsize;
    iVar3 = 0;
    uVar1 = _k_zone_elemsize._0_4_;
    while (uVar1 < param_1) {
      puVar4 = (undefined *)((int)puVar4 + 4);
      iVar3 = iVar3 + 1;
      uVar1 = *(uint *)puVar4;
    }
    if (uVar1 <= _k_zone_maxsize) {
      uVar2 = _zget(*(undefined4 *)(_k_zone + iVar3 * 4));
      return uVar2;
    }
  }
                    /* WARNING: Subroutine does not return */
  _panic(&aKget);
}

