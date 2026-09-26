
/* WARNING: Removing unreachable block (ram,0xf0068aac) */
/* WARNING: Removing unreachable block (ram,0xf0068a44) */
/* WARNING: Removing unreachable block (ram,0xf0068ad4) */
/* WARNING: Removing unreachable block (ram,0xf0068a34) */

undefined8 _swapinStack(uint param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  int *piVar1;
  int iVar2;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar3;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  piVar1 = (int *)(param_1 & ~_page_mask);
  iRamf013c0cc = iRamf013c0cc + -1;
  _vm_map_pageable(_kernel_map,piVar1,(int)piVar1 + _page_mask + dword_F012F678 & ~_page_mask,0);
  _lock_write(_stack_queue_lock);
  *(undefined4 *)(param_1 - 4) = 2;
  piVar3 = (int *)(param_1 - 0xc);
  if (*piVar1 == -0x1120532) {
    *piVar1 = 0;
    iVar2 = 0;
    iRamf013c0d0 = iRamf013c0d0 + -1;
    piVar3 = piVar1;
    if (0 < dword_F012F67C) {
      do {
        if (piVar1[2] == 0) {
          sub_F0068384(piVar1);
        }
        iVar2 = iVar2 + 1;
        piVar1 = (int *)((int)piVar1 + dword_F012F678);
        piVar3 = piVar1;
      } while (iVar2 < dword_F012F67C);
    }
  }
  _lock_done(_stack_queue_lock);
  return CONCAT44(param_2,piVar3);
}

