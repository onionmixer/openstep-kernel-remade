
undefined4 sub_4032F00(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
  iVar1 = *(int *)(param_1 + 0x2e);
  uVar4 = _page_size * (*(int *)(iVar1 + 0x42) + 1);
  iVar2 = _kmem_mb_alloc(_swapfs_rem_map,_page_size);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    if (*(int *)(iVar1 + 0x3e) + _page_size * *(int *)(iVar1 + 0x42) != iVar2) {
                    /* WARNING: Subroutine does not return */
      _panic(aSwapfsGrowBadR);
    }
    *(uint *)(iVar1 + 0x36) = uVar4 >> 2;
    *(int *)(iVar1 + 0x42) = *(int *)(iVar1 + 0x42) + 1;
    if ((uint)(_page_size * *(int *)(iVar1 + 0x4a)) < *(uint *)(iVar1 + 0x36)) {
      iVar2 = _kmem_mb_alloc(_swapfs_bit_map,_page_size);
      if (iVar2 == 0) {
        iVar2 = *(int *)(iVar1 + 0x42);
        *(int *)(iVar1 + 0x42) = iVar2 + -1;
        *(uint *)(iVar1 + 0x36) = (uint)(_page_size * (iVar2 + -1)) >> 2;
        return 0;
      }
      if (*(int *)(iVar1 + 0x46) + *(int *)(iVar1 + 0x4a) * _page_size != iVar2) {
                    /* WARNING: Subroutine does not return */
        _panic(aSwapfsGrowBadF);
      }
      *(int *)(iVar1 + 0x4a) = *(int *)(iVar1 + 0x4a) + 1;
    }
    uVar3 = 1;
  }
  return uVar3;
}
