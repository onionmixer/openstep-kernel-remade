
/* WARNING: Removing unreachable block (ram,0xf0069f3c) */
/* WARNING: Removing unreachable block (ram,0xf0069f14) */
/* WARNING: Removing unreachable block (ram,0xf0069ef4) */
/* WARNING: Removing unreachable block (ram,0xf0069ea0) */
/* WARNING: Removing unreachable block (ram,0xf0069e48) */
/* WARNING: Removing unreachable block (ram,0xf0069dc4) */
/* WARNING: Removing unreachable block (ram,0xf0069e58) */
/* WARNING: Removing unreachable block (ram,0xf0069eb8) */
/* WARNING: Removing unreachable block (ram,0xf0069f04) */
/* WARNING: Removing unreachable block (ram,0xf0069f2c) */
/* WARNING: Removing unreachable block (ram,0xf0069f4c) */
/* WARNING: Removing unreachable block (ram,0xf0069d7c) */

undefined8 _compute_mach_factor(undefined4 param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 unaff_l0;
  int *piVar7;
  undefined4 unaff_l1;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined *puVar11;
  undefined4 unaff_l5;
  undefined *puVar12;
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
  do {
    do {
    } while (_all_psets_lock != 0);
    puVar10 = &_all_psets_lock;
    _simple_lock_try();
  } while (puVar10 == (undefined4 *)0x0);
  if ((undefined4 **)_all_psets != &_all_psets) {
    piVar7 = _all_psets + 0x56;
    puVar10 = _all_psets;
    do {
      do {
        do {
        } while (*piVar7 != 0);
        piVar1 = piVar7;
        _simple_lock_try();
      } while (piVar1 == (int *)0x0);
      iVar8 = puVar10[0x49];
      if (0 < iVar8) {
        param_2 = puVar10[0x42];
        for (puVar6 = (undefined4 *)puVar10[0x47]; puVar10 + 0x47 != puVar6;
            puVar6 = (undefined4 *)puVar6[0x4d]) {
          param_2 = param_2 + puVar6[0x42];
        }
        param_2 = param_2 + (iVar8 - puVar10[0x45]);
        if (puVar10 == (undefined4 *)_default_pset) {
          param_2 = param_2 + -1;
        }
        if (iVar8 < param_2) {
          iVar2 = iVar8 * 1000;
          .div(iVar2,param_2 + 1);
          iVar3 = param_2 << 7;
          .div(iVar3,iVar8);
        }
        else {
          iVar2 = (iVar8 - param_2) * 1000;
          iVar3 = 0x80;
        }
        param_2 = param_2 * 1000;
        iVar8 = puVar10[0x5c] * 4 + iVar2;
        .div(iVar8,5);
        puVar10[0x5c] = iVar8;
        iVar8 = puVar10[0x5d] * 4 + param_2;
        .div(iVar8,5);
        puVar10[0x5d] = iVar8;
        if (puVar10 == (undefined4 *)_default_pset) {
          iVar8 = 0;
          param_1 = 1000;
          puVar12 = _avenrun;
          puVar11 = unk_F010FC34;
          piVar7 = (int *)_mach_factor;
          do {
            iVar9 = *(int *)puVar11;
            iVar8 = iVar8 + 1;
            iVar4 = *piVar7;
            .umul(iVar4,iVar9);
            iVar5 = iVar2;
            .umul(iVar2,1000 - iVar9);
            iVar4 = iVar4 + iVar5;
            .div(iVar4,1000);
            *piVar7 = iVar4;
            iVar9 = *(int *)puVar11;
            piVar7 = piVar7 + 1;
            iVar4 = *(int *)puVar12;
            .umul(iVar4,iVar9);
            iVar5 = param_2;
            .umul(param_2,1000 - iVar9);
            iVar4 = iVar4 + iVar5;
            .div(iVar4,1000);
            *(int *)puVar12 = iVar4;
            puVar12 = (undefined *)((int)puVar12 + 4);
            puVar11 = (undefined *)((int)puVar11 + 4);
          } while (iVar8 < 3);
        }
        puVar10[0x5e] = puVar10[0x5e] + iVar3 >> 1;
      }
      puVar10[0x56] = 0;
      puVar10 = (undefined4 *)puVar10[0x53];
      piVar7 = puVar10 + 0x56;
    } while ((undefined4 **)puVar10 != &_all_psets);
  }
  _all_psets_lock = 0;
  return CONCAT44(param_2,param_1);
}
