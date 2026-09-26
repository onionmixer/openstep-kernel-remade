
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _pmap_remove(int param_1,uint param_2,uint param_3)

{
  undefined4 uVar1;
  uint uVar2;
  int in_FS_OFFSET;
  
  if (param_1 != 0) {
    uVar1 = _splvm();
    if (((param_1 == _kernel_pmap) || (*(int *)(param_1 + 0x18) != 0)) &&
       (__tlb_stat = __tlb_stat + 1, uVar2 = param_2, param_3 - param_2 <= _page_size)) {
      for (; uVar2 < param_3; uVar2 = uVar2 + 0x1000) {
        if (param_1 == _kernel_pmap) {
          invlpg(uVar2);
        }
        else {
          invlpg(in_FS_OFFSET + uVar2);
        }
      }
      _DAT_001f7af4 = _DAT_001f7af4 + 1;
    }
    while (param_2 < param_3) {
      uVar2 = _section_size + -1 + param_2 + _page_size & -_section_size;
      if (param_3 < uVar2) {
        uVar2 = param_3;
      }
      FUN_0018f7f8(param_1,param_2,uVar2,1);
      param_2 = uVar2;
    }
    _splx(uVar1);
  }
  return;
}

