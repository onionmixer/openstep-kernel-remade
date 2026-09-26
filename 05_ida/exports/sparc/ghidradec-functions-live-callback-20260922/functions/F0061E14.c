
/* WARNING: Removing unreachable block (ram,0xf0061e40) */

undefined8
_mach_port_names_helper
          (int param_1,uint *param_2,undefined4 param_3,int param_4,int param_5,int *param_6)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 unaff_l0;
  uint uVar6;
  undefined4 unaff_l1;
  uint uVar7;
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
  uVar6 = *param_2;
  uVar7 = param_2[2];
  if ((uVar6 & 0x50000) != 0) {
    param_2 = (uint *)param_2[1];
    do {
      do {
      } while (*param_2 != 0);
      puVar1 = param_2;
      _simple_lock_try();
    } while (puVar1 == (uint *)0x0);
    uVar3 = 0;
    if (-1 < (int)param_2[2]) {
      uVar3 = param_2[3] - param_1 >> 0x1f;
    }
    *param_2 = 0;
    if (uVar3 != 0) {
      if ((uVar6 & 0x400000) != 0) goto locret_F0061EFC;
      uVar6 = uVar6 & 0xffc0ffff | 0x100000;
      if (uVar7 != 0) {
        uVar6 = uVar6 + 1;
      }
      uVar7 = 0;
    }
  }
  uVar5 = uVar6 & 0x1f0000;
  uVar3 = 0x20000000;
  if (((uVar6 & 0x400000) != 0) || (uVar3 = 0x80000000, uVar7 != 0)) {
    uVar5 = uVar5 | uVar3;
  }
  if ((uVar6 & 0x200000) != 0) {
    uVar5 = uVar5 | 0x40000000;
  }
  iVar2 = *param_6;
  iVar4 = iVar2 * 4;
  *(undefined4 *)(param_4 + iVar4) = param_3;
  *(uint *)(param_5 + iVar4) = uVar5;
  *param_6 = iVar2 + 1;
locret_F0061EFC:
  return CONCAT44(param_2,param_1);
}

