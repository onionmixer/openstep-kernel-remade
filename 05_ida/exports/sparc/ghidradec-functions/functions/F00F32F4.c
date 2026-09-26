
/* WARNING: Removing unreachable block (ram,0xf00f34c0) */
/* WARNING: Removing unreachable block (ram,0xf00f3468) */
/* WARNING: Removing unreachable block (ram,0xf00f33b8) */
/* WARNING: Removing unreachable block (ram,0xf00f3354) */
/* WARNING: Removing unreachable block (ram,0xf00f3304) */
/* WARNING: Removing unreachable block (ram,0xf00f3318) */
/* WARNING: Removing unreachable block (ram,0xf00f339c) */
/* WARNING: Removing unreachable block (ram,0xf00f342c) */
/* WARNING: Removing unreachable block (ram,0xf00f3474) */
/* WARNING: Removing unreachable block (ram,0xf00f3508) */
/* WARNING: Removing unreachable block (ram,0xf00f32f8) */

undefined8 __objcInit(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 unaff_l0;
  uint uVar4;
  int iVar5;
  undefined4 unaff_l1;
  undefined4 *puVar6;
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
  bool bVar7;
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
  iVar3 = param_1;
  sub_F00F25A4();
  dword_F012F12C = iVar3;
  _getmachheaders();
  if (iVar3 != 0) {
    uVar4 = 0;
    iVar1 = iVar3;
    __objc_headerVector();
    dword_F012F124 = iVar1;
    if (dword_F012F128 != 0) {
      iVar1 = 0;
      do {
        sub_F00F2D6C((iVar1 + uVar4) * 8 + dword_F012F124);
        uVar4 = uVar4 + 1;
        iVar1 = uVar4 * 2;
      } while (uVar4 < dword_F012F128);
    }
    uVar4 = 0;
    if (dword_F012F128 != 0) {
      iVar1 = 0;
      do {
        sub_F00F352C((iVar1 + uVar4) * 8 + dword_F012F124);
        uVar4 = uVar4 + 1;
        iVar1 = uVar4 * 2;
      } while (uVar4 < dword_F012F128);
    }
    _free(iVar3);
  }
  uVar4 = 0;
  if (dword_F012F128 != 0) {
    do {
      iVar1 = dword_F012F124 + uVar4 * 0x18;
      iVar3 = *(int *)(iVar1 + 8);
      puVar6 = *(undefined4 **)(iVar1 + 4);
      if (iVar3 != 0) {
        do {
          iVar5 = 0;
          iVar1 = puVar6[3];
          if (*(sword *)(iVar1 + 8) != 0) {
            iVar2 = 0;
            do {
              __class_install_relationships(*(undefined4 *)(iVar2 + iVar1 + 0xc),*puVar6);
              iVar5 = iVar5 + 1;
              iVar1 = puVar6[3];
              iVar2 = iVar5 * 4;
            } while (iVar5 < (int)(uint)*(word *)(iVar1 + 8));
          }
          bVar7 = iVar3 != 1;
          puVar6 = puVar6 + 4;
          iVar3 = iVar3 + -1;
        } while (bVar7);
      }
      sub_F00F26F0(uVar4 * 0x18 + dword_F012F124);
      sub_F00F276C(uVar4 * 0x18 + dword_F012F124);
      uVar4 = uVar4 + 1;
    } while (uVar4 < dword_F012F128);
  }
  uVar4 = 0;
  if (dword_F012F128 != 0) {
    iVar3 = 0;
    do {
      sub_F00F27CC((iVar3 + uVar4) * 8 + dword_F012F124);
      uVar4 = uVar4 + 1;
      iVar3 = uVar4 * 2;
    } while (uVar4 < dword_F012F128);
  }
  uVar4 = 0;
  if (dword_F012F128 != 0) {
    iVar3 = 0;
    do {
      sub_F00F31B0((iVar3 + uVar4) * 8 + dword_F012F124);
      uVar4 = uVar4 + 1;
      iVar3 = uVar4 * 2;
    } while (uVar4 < dword_F012F128);
  }
  return CONCAT44(param_2,param_1);
}
