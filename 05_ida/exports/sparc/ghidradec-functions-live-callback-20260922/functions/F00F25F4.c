
/* WARNING: Removing unreachable block (ram,0xf00f2674) */
/* WARNING: Removing unreachable block (ram,0xf00f266c) */
/* WARNING: Removing unreachable block (ram,0xf00f26ac) */
/* WARNING: Removing unreachable block (ram,0xf00f264c) */

undefined8 sub_F00F25F4(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  uint uVar4;
  undefined4 unaff_l4;
  uint uVar5;
  undefined4 unaff_l5;
  int iVar6;
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
  iVar6 = *(int *)(param_2 + 4);
  uVar5 = 0;
  while (uVar5 < *(uint *)(param_2 + 8)) {
    iVar1 = *(int *)(iVar6 + uVar5 * 0x10 + 0xc);
    if (iVar1 == 0) {
      uVar5 = uVar5 + 1;
    }
    else {
      uVar4 = 0;
      if (*(sword *)(iVar1 + 8) == 0) {
        uVar5 = uVar5 + 1;
      }
      else {
        do {
          iVar1 = iVar6 + uVar5 * 0x10;
          piVar2 = param_1;
          _NXHashInsert(param_1,*(undefined4 *)(uVar4 * 4 + *(int *)(iVar1 + 0xc) + 0xc));
          if (piVar2 == (int *)0x0) {
            piVar3 = *(int **)(uVar4 * 4 + *(int *)(iVar6 + uVar5 * 0x10 + 0xc) + 0xc);
          }
          else {
            sub_F00F2510(param_1,piVar2,*(undefined4 *)(uVar4 * 4 + *(int *)(iVar1 + 0xc) + 0xc));
            piVar3 = (int *)piVar2[2];
            _objc_lookUpClass();
          }
          if (piVar3 != piVar2) {
            *(undefined4 *)(*piVar3 + 0xc) = *(undefined4 *)(iVar6 + uVar5 * 0x10);
          }
          sub_F00F21E4(piVar3);
          uVar4 = uVar4 + 1;
        } while (uVar4 < *(word *)(*(int *)(iVar6 + uVar5 * 0x10 + 0xc) + 8));
        uVar5 = uVar5 + 1;
      }
    }
  }
  return CONCAT44(param_2,param_1);
}

