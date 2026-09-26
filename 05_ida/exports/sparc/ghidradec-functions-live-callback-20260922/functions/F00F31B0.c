
/* WARNING: Removing unreachable block (ram,0xf00f3268) */
/* WARNING: Removing unreachable block (ram,0xf00f3288) */
/* WARNING: Removing unreachable block (ram,0xf00f3220) */

undefined8 sub_F00F31B0(int *param_1,undefined4 param_2)

{
  undefined5 *puVar1;
  int iVar2;
  undefined4 uVar3;
  code *pcVar4;
  undefined4 unaff_l0;
  int *piVar5;
  undefined4 unaff_l1;
  undefined4 *puVar6;
  uint uVar7;
  int iVar8;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  int iVar9;
  undefined4 unaff_l5;
  int iVar10;
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
  bool bVar11;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  puVar1 = paLoad;
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
  iVar9 = param_1[2];
  iVar10 = param_1[1];
  if (iVar9 != 0) {
    do {
      iVar8 = *(int *)(iVar10 + 0xc);
      if (iVar8 != 0) {
        puVar6 = (undefined4 *)(iVar8 + 0xc);
        uVar7 = (uint)*(word *)(iVar8 + 8);
        if (*(word *)(iVar8 + 8) != 0) {
          do {
            piVar5 = (int *)*puVar6;
            pcVar4 = *(code **)(*piVar5 + 0x1c);
            if (pcVar4 != (code *)0x0) {
              iVar2 = *(int *)pcVar4;
              while (iVar2 != 0) {
                pcVar4 = *(code **)pcVar4;
                iVar2 = *(int *)pcVar4;
              }
              _class_lookupMethodInMethodList(pcVar4,puVar1);
              if (pcVar4 != (code *)0x0) {
                (*pcVar4)(piVar5,puVar1);
              }
            }
            bVar11 = uVar7 != 1;
            puVar6 = puVar6 + 1;
            uVar7 = uVar7 - 1;
          } while (bVar11);
        }
        param_1 = (int *)(iVar8 + (uint)*(word *)(iVar8 + 8) * 4 + 0xc);
        for (uVar7 = (uint)*(word *)(iVar8 + 10); uVar7 != 0; uVar7 = uVar7 - 1) {
          uVar3 = *(undefined4 *)(*param_1 + 4);
          _objc_getClass(uVar3);
          pcVar4 = *(code **)(*param_1 + 0xc);
          if ((pcVar4 != (code *)0x0) &&
             (_class_lookupMethodInMethodList(pcVar4,puVar1), pcVar4 != (code *)0x0)) {
            (*pcVar4)(uVar3,puVar1);
          }
          param_1 = param_1 + 1;
        }
      }
      bVar11 = iVar9 != 1;
      iVar10 = iVar10 + 0x10;
      iVar9 = iVar9 + -1;
    } while (bVar11);
  }
  return CONCAT44(param_2,param_1);
}

