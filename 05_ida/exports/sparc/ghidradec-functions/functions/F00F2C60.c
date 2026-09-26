
/* WARNING: Removing unreachable block (ram,0xf00f2d38) */
/* WARNING: Removing unreachable block (ram,0xf00f2d30) */

undefined8 __objc_removeHeader(int param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
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
  
  iVar1 = (int)dword_F012F124;
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
  uVar7 = 0;
  if (dword_F012F128 != (undefined4 *)0x0) {
    uVar8 = (int)dword_F012F128 - 1;
    iVar3 = 0;
    do {
      if ((*(int *)(iVar1 + (iVar3 + uVar7) * 8) == param_1) && (uVar7 < uVar8)) {
        uVar2 = (int)dword_F012F128 - 1;
        uVar6 = uVar7;
        do {
          iVar3 = uVar6 * 0x18 + iVar1;
          *(undefined4 *)(iVar1 + uVar6 * 0x18) = *(undefined4 *)(iVar3 + 0x18);
          *(undefined4 *)(iVar3 + 4) = *(undefined4 *)(iVar3 + 0x1c);
          *(undefined4 *)(iVar3 + 8) = *(undefined4 *)(iVar3 + 0x20);
          *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(iVar3 + 0x24);
          *(undefined4 *)(iVar3 + 0x10) = *(undefined4 *)(iVar3 + 0x28);
          uVar6 = uVar6 + 1;
          *(undefined4 *)(iVar3 + 0x14) = *(undefined4 *)(iVar3 + 0x2c);
        } while (uVar6 < uVar2);
      }
      uVar7 = uVar7 + 1;
      iVar3 = uVar7 * 2;
    } while (uVar7 < dword_F012F128);
  }
  puVar4 = (undefined4 *)((int)dword_F012F128 - 1);
  dword_F012F128 = puVar4;
  __objc_create_zone();
  puVar5 = puVar4;
  __objc_create_zone();
  (*(code *)*puVar4)();
  dword_F012F124 = puVar5;
  return CONCAT44(param_2,param_1);
}
