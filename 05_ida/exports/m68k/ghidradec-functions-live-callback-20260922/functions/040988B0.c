
void _pmap_expand_kernel(uint param_1,int param_2)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  puVar1 = (uint *)(*(int *)(_kernel_pmap + 8) +
                   ((_m68k_pt1_mask & param_1) >> (_m68k_pt1_shift & 0x3f)) * 4);
  if (param_2 == -4) {
    uVar2 = 1 << (_m68k_pt1_l2ptr & 0x3f);
    iVar4 = (uVar2 + _avail_kernel_map + -1) / uVar2 << (_m68k_pt1_l2ptr & 0x3f);
    _avail_kernel_map = iVar4;
    _bzero(iVar4,_m68k_pt2_size);
    _avail_kernel_map = _m68k_pt2_size + _avail_kernel_map;
    *puVar1 = (iVar4 >> (_m68k_pt1_l2ptr & 0x3f)) << 9 | *puVar1 & 0x1ff;
    *(byte *)((int)puVar1 + 3) = (byte)*puVar1 & 0xfb | 8;
    *(byte *)((int)puVar1 + 3) = (byte)*puVar1 & 0xf8 | 8 | (byte)_m68k_pt1_desctype & 3;
  }
  else {
    iVar4 = (*puVar1 >> 9) << (_m68k_pt1_l2ptr & 0x3f);
  }
  uVar2 = 1 << (_m68k_pt2_l3ptr & 0x3f);
  iVar3 = (uVar2 + _avail_kernel_map + -1) / uVar2 << (_m68k_pt2_l3ptr & 0x3f);
  _avail_kernel_map = _m68k_pte_size + iVar3;
  if (_max_kernel_map < _avail_kernel_map) {
                    /* WARNING: Subroutine does not return */
    _panic(aNoMoreRoomInKe);
  }
  _bzero(iVar3,_m68k_pte_size);
  puVar1 = (uint *)(iVar4 + ((_m68k_pt2_mask & param_1) >> (_m68k_pt2_shift & 0x3f)) * 4);
  *puVar1 = (iVar3 >> (_m68k_pt2_l3ptr & 0x3f)) << 7 | *puVar1 & 0x7f;
  *(byte *)((int)puVar1 + 3) = (byte)*puVar1 & 0xfb | 8;
  *(byte *)((int)puVar1 + 3) = bRam040c97cf & 3 | (byte)*puVar1 & 0xf8 | 8;
  return;
}

