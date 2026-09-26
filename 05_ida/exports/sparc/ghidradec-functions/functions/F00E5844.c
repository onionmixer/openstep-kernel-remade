
/* WARNING: Removing unreachable block (ram,0xf00e598c) */
/* WARNING: Removing unreachable block (ram,0xf00e5964) */
/* WARNING: Removing unreachable block (ram,0xf00e58ec) */
/* WARNING: Removing unreachable block (ram,0xf00e58dc) */
/* WARNING: Removing unreachable block (ram,0xf00e5904) */
/* WARNING: Removing unreachable block (ram,0xf00e597c) */
/* WARNING: Removing unreachable block (ram,0xf00e59a4) */
/* WARNING: Removing unreachable block (ram,0xf00e58c4) */

undefined8 _sparcfbMoveRect(uint param_1,word *param_2,int param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 unaff_l0;
  undefined *puVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 unaff_l1;
  int iVar8;
  word *pwVar9;
  undefined4 unaff_l3;
  uint uVar10;
  undefined4 unaff_l4;
  uint uVar11;
  undefined4 unaff_l5;
  uint uVar12;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar13;
  undefined *puVar14;
  undefined4 *puVar15;
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
  iVar1 = param_1 * 0x44 + 8;
  iVar8 = _sparcfbs + iVar1;
  if ((param_1 < 0x10) && (*(int *)(_sparcfbs + iVar1) != 0)) {
    uVar10 = (uint)param_2[1];
    uVar12 = (uint)*param_2;
    uVar11 = (uint)param_2[2];
    param_2 = (word *)(uint)param_2[3];
    if (*(int *)(iVar8 + 0x34) == 1) {
      pwVar9 = (word *)0x0;
      uVar13 = 0;
      if (param_2 != (word *)0x0) {
        do {
          uVar4 = uVar10;
          .umul(uVar10,*(undefined4 *)(iVar8 + 0x38));
          iVar1 = *(int *)(iVar8 + 0x14);
          uVar2 = uVar12;
          .umul(uVar12,*(undefined4 *)(iVar8 + 0x34));
          puVar14 = (undefined *)(iVar1 + uVar4 + uVar2);
          iVar1 = param_4;
          .umul(param_4,*(undefined4 *)(iVar8 + 0x38));
          iVar6 = *(int *)(iVar8 + 0x14);
          iVar3 = param_3;
          .umul(param_3,*(undefined4 *)(iVar8 + 0x34));
          uVar4 = 0;
          puVar5 = (undefined *)(iVar6 + iVar1 + iVar3);
          if (uVar11 != 0) {
            do {
              uVar4 = uVar4 + 1;
              *puVar5 = *puVar14;
              puVar14 = puVar14 + 1;
              puVar5 = puVar5 + 1;
            } while (uVar4 < uVar11);
          }
          uVar10 = uVar10 + 1;
          pwVar9 = (word *)((int)pwVar9 + 1);
          param_4 = param_4 + 1;
        } while (pwVar9 < param_2);
        uVar13 = 0;
      }
    }
    else {
      pwVar9 = (word *)0x0;
      if (*(int *)(iVar8 + 0x34) == 4) {
        uVar13 = 0;
        if (param_2 != (word *)0x0) {
          do {
            uVar4 = uVar10;
            .umul(uVar10,*(undefined4 *)(iVar8 + 0x38));
            iVar1 = *(int *)(iVar8 + 0x18);
            uVar2 = uVar12;
            .umul(uVar12,*(undefined4 *)(iVar8 + 0x34));
            puVar15 = (undefined4 *)(iVar1 + uVar4 + uVar2);
            iVar1 = param_4;
            .umul(param_4,*(undefined4 *)(iVar8 + 0x38));
            iVar6 = *(int *)(iVar8 + 0x18);
            iVar3 = param_3;
            .umul(param_3,*(undefined4 *)(iVar8 + 0x34));
            uVar4 = 0;
            puVar7 = (undefined4 *)(iVar6 + iVar1 + iVar3);
            if (uVar11 != 0) {
              do {
                uVar4 = uVar4 + 1;
                *puVar7 = *puVar15;
                puVar15 = puVar15 + 1;
                puVar7 = puVar7 + 1;
              } while (uVar4 < uVar11);
            }
            uVar10 = uVar10 + 1;
            pwVar9 = (word *)((int)pwVar9 + 1);
            param_4 = param_4 + 1;
          } while (pwVar9 < param_2);
          uVar13 = 0;
        }
      }
      else {
        uVar13 = 0xfffffd39;
      }
    }
  }
  else {
    uVar13 = 0xfffffd40;
  }
  return CONCAT44(param_2,uVar13);
}
