
/* WARNING: Removing unreachable block (ram,0xf00e66fc) */
/* WARNING: Removing unreachable block (ram,0xf00e6690) */
/* WARNING: Removing unreachable block (ram,0xf00e6644) */
/* WARNING: Removing unreachable block (ram,0xf00e64c8) */
/* WARNING: Removing unreachable block (ram,0xf00e6458) */
/* WARNING: Removing unreachable block (ram,0xf00e6398) */
/* WARNING: Removing unreachable block (ram,0xf00e62f0) */
/* WARNING: Removing unreachable block (ram,0xf00e6420) */
/* WARNING: Removing unreachable block (ram,0xf00e6470) */
/* WARNING: Removing unreachable block (ram,0xf00e64e0) */
/* WARNING: Removing unreachable block (ram,0xf00e6678) */
/* WARNING: Removing unreachable block (ram,0xf00e66e4) */
/* WARNING: Removing unreachable block (ram,0xf00e67a4) */
/* WARNING: Removing unreachable block (ram,0xf00e62e8) */

undefined8 _sparcfbInvertRect(uint param_1,word *param_2)

{
  word wVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  word *pwVar9;
  uint uVar10;
  int iVar11;
  uint *puVar12;
  int iVar13;
  undefined4 unaff_l0;
  undefined *puVar14;
  int iVar15;
  undefined4 *puVar16;
  undefined4 unaff_l1;
  word *pwVar17;
  undefined *puVar18;
  undefined4 *puVar19;
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
  bool bVar20;
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
  uVar2 = (uint)*param_2;
  uVar6 = (uint)param_2[1];
  uVar10 = (uint)param_2[2];
  uVar3 = (uint)param_2[3];
  iVar7 = param_1 * 0x44 + 8;
  iVar13 = _sparcfbs + iVar7;
  if ((0xf < param_1) || (*(int *)(_sparcfbs + iVar7) == 0)) {
    iVar7 = -0x2c0;
    goto locret_F00E67CC;
  }
  if (*(int *)(_sparcfbs + iVar7) == 0) {
    iVar7 = -0x2c0;
  }
  else {
    uVar4 = uVar10;
    .umul(uVar10,*(undefined4 *)(iVar13 + 0x34));
    .umul();
    iVar15 = uVar4 + 4;
    *(word **)((int)register0x00000038 + -0xc) = dword_F012EF6C;
    iVar7 = 0;
    pwVar9 = dword_F012EF6C;
    while (pwVar9 != (word *)0x0) {
      iVar8 = *(int *)((int)register0x00000038 + -0xc);
      iVar11 = *(int *)((int)register0x00000038 + -0xc);
      if (iVar15 <= *(int *)(iVar8 + 0x18)) goto loc_F00E6340;
      pwVar9 = *(word **)(iVar8 + 8);
      *(word **)((int)register0x00000038 + -0xc) = pwVar9;
      iVar7 = iVar8;
    }
    iVar11 = *(int *)((int)register0x00000038 + -0xc);
loc_F00E6340:
    if (iVar11 == 0) {
      if (dword_F012EF78 < iVar15) {
        iVar7 = _kernel_map;
        _kmem_alloc_wired(_kernel_map,(undefined *)((int)register0x00000038 + -0xc),uVar4 + 0x20);
        if (iVar7 != 0) {
          iVar7 = -1;
          goto loc_F00E6534;
        }
      }
      else {
        *(undefined **)((int)register0x00000038 + -0xc) = unk_F01330E4;
        dword_F012EF78 = 0;
      }
    }
    else {
      dword_F012EF74 = dword_F012EF74 + -1;
      if (iVar7 == 0) {
        dword_F012EF6C = *(word **)(iVar11 + 8);
      }
      else {
        *(undefined4 *)(iVar7 + 8) = *(undefined4 *)(iVar11 + 8);
      }
    }
    pwVar9 = *(word **)((int)register0x00000038 + -0xc);
    DAT_f012ef70 = DAT_f012ef70 + 1;
    *(int *)pwVar9 = DAT_f012ef70;
    *(int *)(pwVar9 + 0xc) = iVar15;
    *(uint *)(pwVar9 + 2) = param_1;
    *(word **)(pwVar9 + 4) = dword_F012EF68;
    *(undefined4 *)(pwVar9 + 6) = *(undefined4 *)(iVar13 + 0x34);
    pwVar9[8] = *param_2;
    pwVar9[9] = param_2[1];
    pwVar9[10] = param_2[2];
    pwVar9[0xb] = param_2[3];
    iVar7 = *(int *)(iVar13 + 0x38);
    dword_F012EF68 = pwVar9;
    .div(iVar7,*(undefined4 *)(iVar13 + 0x34));
    if (*(int *)(iVar13 + 0x34) == 1) {
      puVar18 = (undefined *)(*(int *)((int)register0x00000038 + -0xc) + 0x1c);
      .umul(uVar6,*(undefined4 *)(iVar13 + 0x38));
      iVar15 = *(int *)(iVar13 + 0x14);
      .umul(uVar2,*(undefined4 *)(iVar13 + 0x34));
      puVar14 = (undefined *)(iVar15 + uVar6 + uVar2);
      iVar13 = uVar3 - 1;
      if ((int)(uVar3 - 1) < 0) goto loc_F00E652C;
      do {
        uVar3 = (uint)param_2[2];
        while (uVar3 = uVar3 - 1, -1 < (int)uVar3) {
          *puVar18 = *puVar14;
          puVar14 = puVar14 + 1;
          puVar18 = puVar18 + 1;
        }
        iVar15 = iVar13 + -1;
        puVar14 = puVar14 + (iVar7 - uVar10);
        iVar13 = iVar13 + -1;
      } while (-1 < iVar15);
      piVar5 = *(int **)((int)register0x00000038 + -0xc);
    }
    else if (*(int *)(iVar13 + 0x34) == 4) {
      puVar19 = (undefined4 *)(*(int *)((int)register0x00000038 + -0xc) + 0x1c);
      .umul(uVar6,*(undefined4 *)(iVar13 + 0x38));
      iVar15 = *(int *)(iVar13 + 0x18);
      .umul(uVar2,*(undefined4 *)(iVar13 + 0x34));
      puVar16 = (undefined4 *)(iVar15 + uVar6 + uVar2);
      while (uVar3 = uVar3 - 1, -1 < (int)uVar3) {
        uVar6 = (uint)param_2[2];
        while (uVar6 = uVar6 - 1, -1 < (int)uVar6) {
          *puVar19 = *puVar16;
          puVar16 = puVar16 + 1;
          puVar19 = puVar19 + 1;
        }
        puVar16 = puVar16 + (iVar7 - uVar10);
      }
loc_F00E652C:
      piVar5 = *(int **)((int)register0x00000038 + -0xc);
    }
    else {
      piVar5 = *(int **)((int)register0x00000038 + -0xc);
    }
    iVar7 = *piVar5;
  }
loc_F00E6534:
  if (-1 < iVar7) {
    uVar3 = uRam00000018;
    pwVar9 = dword_F012EF68;
    if (dword_F012EF68 != (word *)0x0) {
      iVar7 = *(int *)dword_F012EF68;
      while (iVar7 == 0) {
        pwVar9 = *(word **)(pwVar9 + 4);
        if (pwVar9 == (word *)0x0) goto loc_F00E6574;
        iVar7 = *(int *)pwVar9;
      }
      uVar3 = *(uint *)(pwVar9 + 0xc);
    }
loc_F00E6574:
    puVar12 = (uint *)(pwVar9 + 0xe);
    iVar7 = (uVar3 >> 2) - 1;
    iVar13 = param_1 - 0xf;
    while (-1 < iVar13) {
      *puVar12 = ~*puVar12;
      puVar12 = puVar12 + 1;
      iVar7 = iVar7 + -1;
      iVar13 = iVar7;
    }
    iVar7 = param_1 * 0x44 + 8;
    iVar13 = _sparcfbs + iVar7;
    if ((param_1 < 0x10) && (*(int *)(_sparcfbs + iVar7) != 0)) {
      bVar20 = dword_F012EF68 == (word *)0x0;
      pwVar9 = (word *)0x0;
      param_2 = dword_F012EF68;
      if (!bVar20) {
        iVar7 = *(int *)dword_F012EF68;
        pwVar17 = dword_F012EF68;
        while (bVar20 = pwVar17 == (word *)0x0, param_2 = pwVar17, iVar7 == 0) {
          param_2 = *(word **)(pwVar17 + 4);
          pwVar9 = pwVar17;
          if (param_2 == (word *)0x0) {
            bVar20 = true;
            break;
          }
          pwVar17 = param_2;
          iVar7 = *(int *)param_2;
        }
      }
      iVar7 = -0x2c2;
      if ((!bVar20) && (*(int *)(param_2 + 6) == *(int *)(iVar13 + 0x34))) {
        wVar1 = param_2[10];
        uVar3 = (uint)param_2[0xb];
        iVar7 = *(int *)(iVar13 + 0x38);
        uVar6 = (uint)param_2[9];
        uVar2 = (uint)param_2[8];
        .div(iVar7,*(undefined4 *)(iVar13 + 0x34));
        if (*(int *)(iVar13 + 0x34) == 1) {
          pwVar17 = param_2 + 0xe;
          .umul(uVar6,*(undefined4 *)(iVar13 + 0x38));
          iVar15 = *(int *)(iVar13 + 0x14);
          .umul(uVar2,*(undefined4 *)(iVar13 + 0x34));
          puVar14 = (undefined *)(iVar15 + uVar6 + uVar2);
          while (uVar3 = uVar3 - 1, -1 < (int)uVar3) {
            uVar6 = (uint)param_2[10];
            while (uVar6 = uVar6 - 1, -1 < (int)uVar6) {
              *puVar14 = *(undefined *)pwVar17;
              pwVar17 = (word *)((int)pwVar17 + 1);
              puVar14 = puVar14 + 1;
            }
            puVar14 = puVar14 + (iVar7 - (uint)wVar1);
          }
        }
        else {
          pwVar17 = param_2 + 0xe;
          if (*(int *)(iVar13 + 0x34) == 4) {
            .umul(uVar6,*(undefined4 *)(iVar13 + 0x38));
            iVar15 = *(int *)(iVar13 + 0x18);
            .umul(uVar2,*(undefined4 *)(iVar13 + 0x34));
            puVar16 = (undefined4 *)(iVar15 + uVar6 + uVar2);
            while (uVar3 = uVar3 - 1, -1 < (int)uVar3) {
              uVar6 = (uint)param_2[10];
              while (uVar6 = uVar6 - 1, -1 < (int)uVar6) {
                *puVar16 = *(undefined4 *)pwVar17;
                pwVar17 = pwVar17 + 2;
                puVar16 = puVar16 + 1;
              }
              puVar16 = puVar16 + (iVar7 - (uint)wVar1);
            }
          }
        }
        if (pwVar9 == (word *)0x0) {
          dword_F012EF68 = *(word **)(param_2 + 4);
        }
        else {
          *(undefined4 *)(pwVar9 + 4) = *(undefined4 *)(param_2 + 4);
        }
        if (dword_F012EF74 < 10) {
          dword_F012EF74 = dword_F012EF74 + 1;
          *(word **)(param_2 + 4) = dword_F012EF6C;
          dword_F012EF6C = param_2;
        }
        else {
          if (param_2 != (word *)unk_F01330E4) {
            _kmem_free(_kernel_map,param_2);
            iVar7 = 0;
            goto locret_F00E67CC;
          }
          dword_F012EF78 = 0xc04;
        }
        iVar7 = 0;
      }
    }
    else {
      iVar7 = -0x2c0;
    }
  }
locret_F00E67CC:
  return CONCAT44(param_2,iVar7);
}
