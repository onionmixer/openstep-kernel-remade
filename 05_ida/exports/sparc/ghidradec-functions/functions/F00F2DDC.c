
/* WARNING: Removing unreachable block (ram,0xf00f3110) */
/* WARNING: Removing unreachable block (ram,0xf00f30b8) */
/* WARNING: Removing unreachable block (ram,0xf00f2fe0) */
/* WARNING: Removing unreachable block (ram,0xf00f2ec0) */
/* WARNING: Removing unreachable block (ram,0xf00f2e24) */
/* WARNING: Removing unreachable block (ram,0xf00f2f2c) */
/* WARNING: Removing unreachable block (ram,0xf00f3038) */
/* WARNING: Removing unreachable block (ram,0xf00f30d0) */
/* WARNING: Removing unreachable block (ram,0xf00f3170) */
/* WARNING: Removing unreachable block (ram,0xf00f2df8) */

undefined8 sub_F00F2DDC(int param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  uint *puVar5;
  undefined4 unaff_l0;
  int iVar6;
  int iVar7;
  undefined4 unaff_l1;
  uint uVar8;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  int *piVar9;
  undefined4 unaff_l5;
  uint uVar10;
  undefined4 unaff_l6;
  int iVar11;
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
  undefined auStackX_0 [92];
  
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
  iVar11 = *(int *)(param_1 + 4);
  iVar3 = param_1;
  _getsectdatafromheaderinfo
            (param_1,&aObjc,aMessageRefs,(undefined *)((int)register0x00000038 + -0xc));
  uVar1 = *(uint *)((int)register0x00000038 + -0xc);
  if (iVar3 != 0) {
    uVar8 = 0;
    uVar10 = 0;
    if (uVar1 >> 2 == 0) goto loc_F00F3094;
    iVar6 = 0;
    while( true ) {
      iVar2 = *(int *)(iVar3 + iVar6);
      __sel_registerName();
      if (*(int *)(iVar3 + iVar6) != iVar2) {
        *(int *)(iVar3 + iVar6) = iVar2;
      }
      uVar8 = uVar8 + 1;
      if (uVar1 >> 2 <= uVar8) break;
      iVar6 = uVar8 * 4;
    }
  }
  uVar10 = 0;
loc_F00F3094:
  while (uVar10 < *(uint *)(param_1 + 8)) {
    iVar3 = *(int *)(iVar11 + uVar10 * 0x10 + 0xc);
    if (iVar3 == 0) {
      uVar10 = uVar10 + 1;
    }
    else {
      for (uVar1 = 0; uVar1 < *(word *)(iVar3 + 8); uVar1 = uVar1 + 1) {
        piVar9 = *(int **)(uVar1 * 4 + *(int *)(iVar11 + uVar10 * 0x10 + 0xc) + 0xc);
        piVar4 = (int *)piVar9[7];
        if (piVar4 == (int *)0x0) {
          iVar3 = *piVar9;
        }
        else {
          for (; *piVar4 != 0; piVar4 = (int *)*piVar4) {
          }
          for (uVar8 = 0; uVar8 < (uint)piVar4[1]; uVar8 = uVar8 + 1) {
            iVar3 = piVar4[uVar8 * 3 + 2];
            __sel_registerName();
            if (piVar4[uVar8 * 3 + 2] != iVar3) {
              piVar4[uVar8 * 3 + 2] = iVar3;
            }
          }
          iVar3 = *piVar9;
        }
        piVar4 = *(int **)(iVar3 + 0x1c);
        if (piVar4 != (int *)0x0) {
          for (; *piVar4 != 0; piVar4 = (int *)*piVar4) {
          }
          for (uVar8 = 0; uVar8 < (uint)piVar4[1]; uVar8 = uVar8 + 1) {
            iVar3 = piVar4[uVar8 * 3 + 2];
            __sel_registerName();
            if (piVar4[uVar8 * 3 + 2] != iVar3) {
              piVar4[uVar8 * 3 + 2] = iVar3;
            }
          }
        }
        iVar3 = *(int *)(iVar11 + uVar10 * 0x10 + 0xc);
      }
      iVar3 = *(int *)(iVar11 + uVar10 * 0x10 + 0xc);
      uVar1 = (uint)*(word *)(iVar3 + 8);
      if (uVar1 < uVar1 + *(word *)(iVar3 + 10)) {
        do {
          iVar6 = *(int *)(uVar1 * 4 + *(int *)(iVar11 + uVar10 * 0x10 + 0xc) + 0xc);
          iVar3 = *(int *)(iVar6 + 8);
          if (iVar3 == 0) {
            iVar3 = *(int *)(iVar6 + 0xc);
          }
          else {
            for (uVar8 = 0; uVar8 < *(uint *)(iVar3 + 4); uVar8 = uVar8 + 1) {
              iVar7 = uVar8 * 0xc + 8;
              iVar2 = *(int *)(iVar3 + iVar7);
              __sel_registerName();
              if (*(int *)(iVar3 + iVar7) != iVar2) {
                *(int *)(iVar3 + iVar7) = iVar2;
              }
            }
            iVar3 = *(int *)(iVar6 + 0xc);
          }
          if (iVar3 != 0) {
            for (uVar8 = 0; uVar8 < *(uint *)(iVar3 + 4); uVar8 = uVar8 + 1) {
              iVar2 = uVar8 * 0xc + 8;
              iVar6 = *(int *)(iVar3 + iVar2);
              __sel_registerName();
              if (*(int *)(iVar3 + iVar2) != iVar6) {
                *(int *)(iVar3 + iVar2) = iVar6;
              }
            }
          }
          uVar1 = uVar1 + 1;
          iVar3 = *(int *)(iVar11 + uVar10 * 0x10 + 0xc);
        } while (uVar1 < (uint)*(word *)(iVar3 + 8) + (uint)*(word *)(iVar3 + 10));
        uVar10 = uVar10 + 1;
      }
      else {
        uVar10 = uVar10 + 1;
      }
    }
  }
  iVar3 = param_1;
  _getsectdatafromheaderinfo(param_1,&aObjc,aProtocol,(undefined *)((int)register0x00000038 + -0xc))
  ;
  uVar1 = 0;
  if (iVar3 != 0) {
    while( true ) {
      uVar8 = *(uint *)((int)register0x00000038 + -0xc);
      .udiv(uVar8,0x14);
      if (uVar8 <= uVar1) break;
      puVar5 = *(uint **)(iVar3 + uVar1 * 0x14 + 0xc);
      if (puVar5 != (uint *)0x0) {
        for (uVar8 = 0; uVar8 < *puVar5; uVar8 = uVar8 + 1) {
          uVar10 = puVar5[uVar8 * 2 + 1];
          __sel_registerName();
          if (puVar5[uVar8 * 2 + 1] != uVar10) {
            puVar5[uVar8 * 2 + 1] = uVar10;
          }
        }
      }
      puVar5 = *(uint **)(iVar3 + uVar1 * 0x14 + 0x10);
      if (puVar5 == (uint *)0x0) {
        uVar1 = uVar1 + 1;
      }
      else {
        for (uVar8 = 0; uVar8 < *puVar5; uVar8 = uVar8 + 1) {
          uVar10 = puVar5[uVar8 * 2 + 1];
          __sel_registerName();
          if (puVar5[uVar8 * 2 + 1] != uVar10) {
            puVar5[uVar8 * 2 + 1] = uVar10;
          }
        }
        uVar1 = uVar1 + 1;
      }
    }
  }
  return CONCAT44(param_2,param_1);
}
