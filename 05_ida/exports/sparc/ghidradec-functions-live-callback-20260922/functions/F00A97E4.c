
/* WARNING: Removing unreachable block (ram,0xf00a9af4) */
/* WARNING: Removing unreachable block (ram,0xf00a9a18) */
/* WARNING: Removing unreachable block (ram,0xf00a9a68) */
/* WARNING: Removing unreachable block (ram,0xf00a9c1c) */
/* WARNING: Removing unreachable block (ram,0xf00a9bd8) */
/* WARNING: Removing unreachable block (ram,0xf00a9bac) */
/* WARNING: Removing unreachable block (ram,0xf00a9b58) */
/* WARNING: Removing unreachable block (ram,0xf00a9998) */
/* WARNING: Removing unreachable block (ram,0xf00a9944) */
/* WARNING: Removing unreachable block (ram,0xf00a98f4) */
/* WARNING: Removing unreachable block (ram,0xf00a985c) */
/* WARNING: Removing unreachable block (ram,0xf00a988c) */
/* WARNING: Removing unreachable block (ram,0xf00a9914) */
/* WARNING: Removing unreachable block (ram,0xf00a9960) */
/* WARNING: Removing unreachable block (ram,0xf00a99cc) */
/* WARNING: Removing unreachable block (ram,0xf00a9b14) */
/* WARNING: Removing unreachable block (ram,0xf00a9bc0) */
/* WARNING: Removing unreachable block (ram,0xf00a9bf4) */
/* WARNING: Removing unreachable block (ram,0xf00a9a38) */
/* WARNING: Removing unreachable block (ram,0xf00a9a00) */
/* WARNING: Removing unreachable block (ram,0xf00a9ac4) */
/* WARNING: Removing unreachable block (ram,0xf00a9ae0) */
/* WARNING: Removing unreachable block (ram,0xf00a97ec) */

qword _do_unaligned(int param_1,int param_2,int *param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined3 *puVar4;
  undefined *puVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar6;
  int iVar7;
  undefined4 unaff_l3;
  uint uVar8;
  undefined4 unaff_l4;
  int iVar9;
  undefined4 unaff_l5;
  int iVar10;
  undefined4 unaff_l6;
  uint uVar11;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar12;
  undefined4 unaff_i1;
  uint uVar13;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar14;
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
  iVar9 = 0;
  uVar1 = *(uint *)(param_1 + 4);
  _fuword();
  uVar3 = uVar1 >> 0x13 & 3;
  uVar8 = uVar1 >> 0x19 & 0x1f;
  uVar6 = uVar1 >> 0xe & 0x1f;
  uVar13 = uVar1 >> 0x18 & 1;
  uVar11 = uVar1 >> 0xd & 1;
  if (uVar3 == 1) {
    _printf(aAlignmentBotch);
    uVar12 = 0;
    goto locret_F00A9C3C;
  }
  if (uVar3 < 2) {
    iVar9 = 4;
  }
  else if (uVar3 == 2) {
    iVar9 = 2;
  }
  else if (uVar3 == 3) {
    iVar9 = 8;
  }
  if (_aligndebug != 0) {
    _printf(aUnalignedAcces,*(undefined4 *)(param_1 + 4),uVar1);
    if ((uVar1 >> 0x15 & 1) == 0) {
      puVar4 = &aLd;
    }
    else {
      puVar4 = &aSt;
    }
    if ((uVar1 >> 0x16 & 1) == 0) {
      puVar5 = aUnsigned;
    }
    else {
      puVar5 = (undefined *)&aSigned;
    }
    _printf(aTypeSSS,puVar4,puVar5,*(undefined4 *)(_sizestr + (uVar1 >> 0x11 & 0xc)));
    _printf(aRdDRs1DRs2DImm,uVar8,uVar6,uVar1 & 0x1f,uVar1 & 0x1fff);
  }
  if (uVar1 >> 0x1e != 3) {
    uVar12 = 0;
    goto locret_F00A9C3C;
  }
  if ((uVar11 == 0) && ((uVar1 >> 5 & 0xff) != 0)) {
    uVar12 = 0;
    goto locret_F00A9C3C;
  }
  iVar10 = param_1 + 0xc;
  _flush_user_windows_to_stack();
  uVar12 = *(undefined4 *)(param_1 + 0x44);
  iVar7 = iVar10;
  sub_F00A96F0(iVar10,uVar12,uVar6,(undefined *)((int)register0x00000038 + -0xc));
  if (iVar7 != 0) {
    uVar12 = 0xffffffff;
    goto locret_F00A9C3C;
  }
  iVar7 = *(int *)((int)register0x00000038 + -0xc);
  if (uVar11 == 0) {
    iVar2 = iVar10;
    sub_F00A96F0(iVar10,uVar12,uVar1 & 0x1f,(undefined *)((int)register0x00000038 + -0xc));
    if (iVar2 != 0) {
      uVar12 = 0xffffffff;
      goto locret_F00A9C3C;
    }
    iVar2 = *(int *)((int)register0x00000038 + -0xc);
  }
  else {
    iVar2 = (int)(uVar1 << 0x13) >> 0x13;
  }
  iVar7 = iVar7 + iVar2;
  if (_aligndebug != 0) {
    _printf(aAddr0xX_0,iVar7);
  }
  if (param_3 != (int *)0x0) {
    *param_3 = iVar7;
  }
  if (param_2 == 0) {
    uVar12 = 1;
    goto locret_F00A9C3C;
  }
  if ((uVar1 >> 0x15 & 1) == 0) {
    if (iVar9 == 2) {
      _copyin(iVar7,(undefined *)((int)register0x00000038 + -0x16),2);
      if (iVar7 != -1) {
        if (((uVar1 >> 0x16 & 1) == 0) || (-1 < *(sword *)((int)register0x00000038 + -0x16))) {
          *(undefined2 *)((int)register0x00000038 + -0x18) = 0;
        }
        else {
          *(undefined2 *)((int)register0x00000038 + -0x18) = 0xffff;
        }
        goto loc_F00A9B6C;
      }
    }
    else {
      _copyin(iVar7,(undefined *)((int)register0x00000038 + -0x18),iVar9);
      if (iVar7 == -1) {
        uVar12 = 0xffffffff;
        goto locret_F00A9C3C;
      }
loc_F00A9B6C:
      if (_aligndebug != 0) {
        _printf(aDataXXXXXXXX_0,*(undefined *)((int)register0x00000038 + -0x18),
                *(undefined *)((int)register0x00000038 + -0x17),
                *(undefined *)((int)register0x00000038 + -0x16),
                *(undefined *)((int)register0x00000038 + -0x15),
                *(undefined *)((int)register0x00000038 + -0x14),
                *(undefined *)((int)register0x00000038 + -0x13),
                *(undefined *)((int)register0x00000038 + -0x12),
                *(undefined *)((int)register0x00000038 + -0x11));
      }
      if (uVar13 != 0) {
        __fp_write_pfreg((undefined *)((int)register0x00000038 + -0x18),uVar8);
        uVar12 = 1;
        if (iVar9 == 8) {
          __fp_write_pfreg((undefined *)((int)register0x00000038 + -0x14),uVar8 + 1);
          uVar12 = 1;
        }
        goto locret_F00A9C3C;
      }
      iVar7 = *(int *)((int)register0x00000038 + -0x18);
      sub_F00A975C(iVar7,iVar10,uVar12,uVar8);
      if (iVar7 != -1) {
        if (iVar9 != 8) {
          uVar12 = 1;
          goto locret_F00A9C3C;
        }
        iVar9 = *(int *)((int)register0x00000038 + -0x14);
        sub_F00A975C(iVar9,iVar10,uVar12,uVar8 + 1);
        bVar14 = iVar9 == -1;
        goto loc_F00A9C28;
      }
    }
  }
  else {
    if (uVar13 == 0) {
      iVar2 = iVar10;
      sub_F00A96F0(iVar10,uVar12,uVar8,(undefined *)((int)register0x00000038 + -0xc));
      if (iVar2 != 0) {
        uVar12 = 0xffffffff;
        goto locret_F00A9C3C;
      }
      *(undefined4 *)((int)register0x00000038 + -0x18) =
           *(undefined4 *)((int)register0x00000038 + -0xc);
      if (iVar9 == 8) {
        sub_F00A96F0(iVar10,uVar12,uVar8 + 1,(undefined *)((int)register0x00000038 + -0xc));
        uVar12 = 0xffffffff;
        if (iVar10 != 0) goto locret_F00A9C3C;
        *(undefined4 *)((int)register0x00000038 + -0x14) =
             *(undefined4 *)((int)register0x00000038 + -0xc);
      }
    }
    else {
      __fp_read_pfreg((undefined *)((int)register0x00000038 + -0x18),uVar8);
      if (iVar9 == 8) {
        __fp_read_pfreg((undefined *)((int)register0x00000038 + -0x14),uVar8 + 1);
      }
    }
    if (_aligndebug != 0) {
      _printf(aDataXXXXXXXX,*(undefined *)((int)register0x00000038 + -0x18),
              *(undefined *)((int)register0x00000038 + -0x17),
              *(undefined *)((int)register0x00000038 + -0x16),
              *(undefined *)((int)register0x00000038 + -0x15),
              *(undefined *)((int)register0x00000038 + -0x14),
              *(undefined *)((int)register0x00000038 + -0x13),
              *(undefined *)((int)register0x00000038 + -0x12),
              *(undefined *)((int)register0x00000038 + -0x11));
    }
    puVar5 = (undefined *)((int)register0x00000038 + -0x18);
    if (iVar9 == 2) {
      puVar5 = (undefined *)((int)register0x00000038 + -0x16);
      _copyout(puVar5,iVar7,2);
      bVar14 = puVar5 == (undefined *)0xffffffff;
    }
    else {
      _copyout(puVar5,iVar7,iVar9);
      bVar14 = puVar5 == (undefined *)0xffffffff;
    }
loc_F00A9C28:
    uVar12 = 1;
    if (!bVar14) goto locret_F00A9C3C;
  }
  uVar12 = 0xffffffff;
locret_F00A9C3C:
  return CONCAT44(uVar1 >> 0x18,uVar12) & 0x1ffffffff;
}

