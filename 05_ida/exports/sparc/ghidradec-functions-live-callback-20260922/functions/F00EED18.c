
/* WARNING: Removing unreachable block (ram,0xf00eef9c) */
/* WARNING: Removing unreachable block (ram,0xf00eee8c) */
/* WARNING: Removing unreachable block (ram,0xf00eee78) */
/* WARNING: Removing unreachable block (ram,0xf00eef5c) */
/* WARNING: Removing unreachable block (ram,0xf00eef78) */
/* WARNING: Removing unreachable block (ram,0xf00eed60) */

undefined8 _NXMapRemove(int *param_1,int param_2)

{
  uint uVar1;
  int *piVar2;
  uint uVar3;
  undefined *puVar4;
  int iVar5;
  uint uVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int *piVar7;
  undefined4 *puVar8;
  int iVar9;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  int iVar10;
  undefined4 unaff_l6;
  uint uVar11;
  undefined4 unaff_l7;
  int iVar12;
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
  iVar10 = param_1[3];
  piVar7 = param_1;
  (**(code **)*param_1)(param_1,param_2);
  uVar1 = ((uint)piVar7 & 0xffff ^ (uint)piVar7 >> 0x10) * 0xfff1 + (int)piVar7;
  urem(uVar1,param_1[2]);
  piVar7 = (int *)(iVar10 + uVar1 * 8);
  uVar11 = 1;
  iVar9 = 0;
  iVar12 = 0;
  if (*(int *)(iVar10 + uVar1 * 8) != -1) {
    dword_F012F0CC = dword_F012F0CC + 1;
    iVar5 = *piVar7;
    if (iVar5 == param_2) {
      piVar2 = (int *)0x1;
    }
    else {
      piVar2 = param_1;
      (**(code **)(*param_1 + 4))(param_1,iVar5,param_2);
    }
    uVar3 = uVar1;
    if (piVar2 != (int *)0x0) {
      iVar9 = 1;
      iVar12 = piVar7[1];
    }
    while( true ) {
      uVar6 = uVar3 + 1;
      uVar3 = 0;
      if (uVar6 < (uint)param_1[2]) {
        uVar3 = uVar6;
      }
      if (uVar3 == uVar1) break;
      iVar5 = *(int *)(iVar10 + uVar3 * 8);
      if (iVar5 == -1) break;
      if (iVar5 == param_2) {
        piVar7 = (int *)0x1;
      }
      else {
        piVar7 = param_1;
        (**(code **)(*param_1 + 4))(param_1,iVar5,param_2);
      }
      uVar11 = uVar11 + 1;
      if (piVar7 != (int *)0x0) {
        iVar9 = iVar9 + 1;
        iVar12 = *(int *)(iVar10 + uVar3 * 8 + 4);
      }
    }
    if (iVar9 != 0) {
      if (iVar9 != 1) {
        __NXLogError(aNxmapremoveInc);
      }
      if (uVar11 < 0x11) {
        puVar4 = (undefined *)((int)register0x00000038 + -0x88);
      }
      else {
        puVar4 = (undefined *)((uVar11 - 1) * 8);
        _malloc();
      }
      iVar9 = 0;
      uVar3 = uVar11;
      while (uVar3 = uVar3 - 1, uVar3 != 0xffffffff) {
        iVar5 = *(int *)(iVar10 + uVar1 * 8);
        puVar8 = (undefined4 *)(iVar10 + uVar1 * 8);
        if (iVar5 == param_2) {
          piVar7 = (int *)0x1;
        }
        else {
          piVar7 = param_1;
          (**(code **)(*param_1 + 4))(param_1,iVar5,param_2);
        }
        if (piVar7 == (int *)0x0) {
          *(undefined4 *)(puVar4 + iVar9 * 8) = *puVar8;
          *(undefined4 *)(puVar4 + iVar9 * 8 + 4) = puVar8[1];
          iVar9 = iVar9 + 1;
          *puVar8 = 0xffffffff;
        }
        else {
          *puVar8 = 0xffffffff;
        }
        puVar8[1] = 0;
        uVar6 = uVar1 + 1;
        uVar1 = 0;
        if (uVar6 < (uint)param_1[2]) {
          uVar1 = uVar6;
        }
      }
      param_1[1] = param_1[1] - uVar11;
      if (iVar9 != uVar11 - 1) {
        __NXLogError(aNxmapremoveBug);
      }
      while( true ) {
        iVar9 = iVar9 + -1;
        if (iVar9 == -1) break;
        _NXMapInsert(param_1,*(undefined4 *)(puVar4 + iVar9 * 8),
                     *(undefined4 *)(puVar4 + iVar9 * 8 + 4));
      }
      if (0x10 < uVar11) {
        _free(puVar4);
      }
      goto locret_F00EEFA8;
    }
  }
  iVar12 = 0;
locret_F00EEFA8:
  return CONCAT44(param_2,iVar12);
}

