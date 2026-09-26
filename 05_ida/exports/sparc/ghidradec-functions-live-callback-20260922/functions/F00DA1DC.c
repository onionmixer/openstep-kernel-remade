
/* WARNING: Removing unreachable block (ram,0xf00da254) */
/* WARNING: Removing unreachable block (ram,0xf00da274) */
/* WARNING: Removing unreachable block (ram,0xf00da238) */

undefined8 -[AudioChannel initializeFreeQueue](int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  undefined4 unaff_l0;
  int iVar8;
  undefined4 unaff_l1;
  uint uVar9;
  int iVar10;
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
  piVar5 = (int *)(param_1 + 0x2c);
  if (piVar5 == *(int **)(param_1 + 0x2c)) {
    uVar1 = *(undefined4 *)(param_1 + 0x4c);
  }
  else {
    iVar10 = *(int *)(param_1 + 0x2c);
    while( true ) {
      piVar7 = *(int **)(iVar10 + 8);
      piVar6 = *(int **)(iVar10 + 0xc);
      piVar2 = piVar5;
      if (piVar5 != piVar7) {
        piVar2 = piVar7 + 2;
      }
      piVar2[1] = (int)piVar6;
      piVar2 = piVar5;
      if (piVar5 != piVar6) {
        piVar2 = piVar6 + 2;
      }
      *piVar2 = (int)piVar7;
      _IOFree(iVar10,0x10);
      if (piVar5 == *(int **)(param_1 + 0x2c)) break;
      iVar10 = *(int *)(param_1 + 0x2c);
    }
    uVar1 = *(undefined4 *)(param_1 + 0x4c);
  }
  _bzero(uVar1,*(undefined4 *)(param_1 + 0x38));
  uVar9 = 0;
  iVar10 = *(int *)(param_1 + 0x4c);
  if (*(int *)(param_1 + 0x3c) != 0) {
    iVar8 = param_1 + 0x2c;
    do {
      puVar3 = (undefined4 *)0x10;
      _IOMalloc();
      *puVar3 = 0;
      puVar3[1] = iVar10;
      iVar10 = iVar10 + *(int *)(param_1 + 0x40);
      if (iVar8 == *(int *)(param_1 + 0x2c)) {
        *(undefined4 **)(param_1 + 0x2c) = puVar3;
        *(undefined4 **)(param_1 + 0x30) = puVar3;
        puVar3[2] = iVar8;
        puVar3[3] = iVar8;
      }
      else {
        iVar4 = *(int *)(param_1 + 0x30);
        puVar3[3] = iVar4;
        puVar3[2] = iVar8;
        *(undefined4 **)(param_1 + 0x30) = puVar3;
        *(undefined4 **)(iVar4 + 8) = puVar3;
      }
      uVar9 = uVar9 + 1;
    } while (uVar9 < *(uint *)(param_1 + 0x3c));
  }
  return CONCAT44(param_2,param_1);
}

