
/* WARNING: Removing unreachable block (ram,0xf00f1e9c) */
/* WARNING: Removing unreachable block (ram,0xf00f1ed0) */
/* WARNING: Removing unreachable block (ram,0xf00f1e94) */

undefined8 _objc_getModules(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
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
  if (dword_F0133CEC == (int *)0x0) {
    uVar5 = 0;
    piVar1 = (int *)0x0;
    if (dword_F012F128 != 0) {
      do {
        piVar1 = *(int **)(dword_F012F124 + uVar5 * 0x18 + 8);
        dword_F0133CE8 = dword_F0133CE8 + (int)piVar1;
        uVar5 = uVar5 + 1;
      } while (uVar5 < dword_F012F128);
    }
    __objc_create_zone();
    piVar2 = piVar1;
    __objc_create_zone();
    (*(code *)piVar1[1])();
    dword_F0133CEC = piVar2;
    if (piVar2 == (int *)0x0) {
      __objc_fatal(aUnableToAlloca_0);
    }
    uVar5 = 0;
    piVar1 = dword_F0133CEC;
    if (dword_F012F128 == 0) {
      *dword_F0133CEC = 0;
    }
    else {
      do {
        iVar3 = dword_F012F124 + uVar5 * 0x18;
        iVar6 = *(int *)(iVar3 + 4);
        uVar4 = 0;
        if (*(int *)(iVar3 + 8) != 0) {
          do {
            *piVar1 = iVar6 + uVar4 * 0x10;
            uVar4 = uVar4 + 1;
            piVar1 = piVar1 + 1;
          } while (uVar4 < *(uint *)(dword_F012F124 + uVar5 * 0x18 + 8));
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < dword_F012F128);
      *piVar1 = 0;
    }
  }
  return CONCAT44(param_2,dword_F0133CEC);
}

