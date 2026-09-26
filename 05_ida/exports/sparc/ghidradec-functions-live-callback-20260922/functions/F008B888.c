
/* WARNING: Removing unreachable block (ram,0xf008b9e8) */
/* WARNING: Removing unreachable block (ram,0xf008b9a8) */
/* WARNING: Removing unreachable block (ram,0xf008b8ec) */
/* WARNING: Removing unreachable block (ram,0xf008b928) */
/* WARNING: Removing unreachable block (ram,0xf008b9b8) */
/* WARNING: Removing unreachable block (ram,0xf008ba60) */
/* WARNING: Removing unreachable block (ram,0xf008b894) */

undefined8 _vnode_pager_file_init(undefined4 *param_1,int *param_2,uint param_3,uint param_4)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  undefined4 unaff_l0;
  undefined *puVar6;
  undefined4 unaff_l1;
  uint uVar7;
  sword *psVar8;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar9;
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
  *param_1 = 0;
  _mfs_uncache(param_2);
  piVar9 = (int *)0x10;
  if ((*(uint *)(*param_2 + 0x38) & 0x8000000) == 0) {
    puVar6 = (undefined *)((int)register0x00000038 + -0x48);
    psVar8 = *(sword **)(_active_u + 0x1c);
    (**(code **)(param_2[7] + 0x14))(param_2,puVar6,psVar8);
    if (param_3 < *(uint *)((int)register0x00000038 + -0x30)) {
      _vattr_null(puVar6);
      *(uint *)((int)register0x00000038 + -0x30) = param_3;
      piVar9 = param_2;
      (**(code **)(param_2[7] + 0x18))(param_2,puVar6,psVar8);
      if (piVar9 != (int *)0x0) goto locret_F008BAC8;
      iVar4 = *param_2;
      uVar7 = param_3;
    }
    else {
      iVar4 = *param_2;
      uVar7 = *(uint *)((int)register0x00000038 + -0x30);
    }
    puVar3 = (undefined4 *)0x40;
    *(uint *)(iVar4 + 0x14) = uVar7;
    _kalloc();
    *(sword *)((int)param_2 + 6) = *(sword *)((int)param_2 + 6) + 1;
    puVar3[2] = param_2;
    *psVar8 = *psVar8 + 1;
    uVar1 = _page_shift;
    *(sword **)(*param_2 + 0x30) = psVar8;
    puVar3[3] = 0;
    uVar7 = _page_mask;
    puVar3[9] = 0;
    puVar3[7] = (param_3 + uVar7 & ~uVar7) >> ((byte)uVar1 & 0x1f);
    if (param_4 == 0) {
      piVar9 = (int *)param_2[9];
      (**(code **)(piVar9[1] + 0xc))(piVar9,(undefined *)((int)register0x00000038 + -0x88));
      if (piVar9 != (int *)0x0) {
        _kfree(puVar3,0x40);
        goto locret_F008BAC8;
      }
      param_4 = *(uint *)((int)register0x00000038 + -0x80);
      umul(param_4,*(undefined4 *)((int)register0x00000038 + -0x84));
    }
    param_4 = param_4 >> ((byte)_page_shift & 0x1f);
    puVar3[5] = param_4;
    puVar3[6] = param_4;
    iVar4 = puVar3[5] + 7;
    if (iVar4 < 0) {
      iVar4 = puVar3[5] + 0xe;
    }
    iVar4 = iVar4 >> 3;
    _kalloc();
    puVar3[4] = iVar4;
    iVar4 = 0;
    if (0 < (int)puVar3[5]) {
      do {
        iVar5 = iVar4;
        if (iVar4 < 0) {
          iVar5 = iVar4 + 7;
        }
        iVar5 = iVar5 >> 3;
        *(byte *)(puVar3[4] + iVar5) =
             *(byte *)(puVar3[4] + iVar5) & ~(byte)(1 << ((char)iVar4 + (char)iVar5 * -8 & 0x1fU));
        iVar4 = iVar4 + 1;
      } while (iVar4 < (int)puVar3[5]);
    }
    puVar3[8] = 0xffffffff;
    puVar3[0xb] = 0;
    _lock_init(puVar3 + 0xd,1);
    puVar2 = puVar3;
    if ((undefined4 **)dword_F0130F68 != &dword_F0130F64) {
      *dword_F0130F68 = puVar3;
      puVar2 = dword_F0130F64;
    }
    dword_F0130F64 = puVar2;
    puVar3[1] = dword_F0130F68;
    *puVar3 = &dword_F0130F64;
    piVar9 = (int *)0x0;
    iVar4 = dword_F0130F6C + 1;
    dword_F0130F68 = puVar3;
    dword_F0130F6C = iVar4;
    puVar3[0xc] = iVar4;
    *(undefined4 **)(unk_F0130F70 + iVar4 * 4) = puVar3;
    *param_1 = puVar3;
  }
locret_F008BAC8:
  return CONCAT44(param_2,piVar9);
}

