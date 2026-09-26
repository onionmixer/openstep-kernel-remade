
/* WARNING: Removing unreachable block (ram,0xf0068964) */

undefined8 _doSwapout(uint param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  iVar2 = dword_F012F67C;
  iVar1 = dword_F012F678;
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
  iVar8 = 0;
  piVar3 = (int *)(param_1 & ~_page_mask);
  if (0 < dword_F012F67C) {
    param_1 = 0xf010f800;
    piVar6 = piVar3 + 1;
    piVar7 = piVar3;
    do {
      if (piVar6[1] == 0) {
        iVar4 = *piVar7;
        piVar5 = (int *)*piVar6;
        *(int **)(iVar4 + 4) = piVar5;
        if (piVar5 != &dword_F012F670) {
          *piVar5 = iVar4;
          iVar4 = dword_F012F670;
        }
        dword_F012F670 = iVar4;
        dword_F010FB00 = dword_F010FB00 + -1;
        iRamf013c0c8 = iRamf013c0c8 + -1;
      }
      piVar6 = (int *)((int)piVar6 + iVar1);
      iVar8 = iVar8 + 1;
      piVar7 = (int *)((int)piVar7 + iVar1);
    } while (iVar8 < iVar2);
  }
  *piVar3 = -0x1120532;
  _vm_map_pageable(_kernel_map,piVar3,(int)piVar3 + _page_mask + dword_F012F678 & ~_page_mask,1);
  iRamf013c0d0 = iRamf013c0d0 + 1;
  return CONCAT44(param_2,param_1);
}

