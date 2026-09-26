
/* WARNING: Removing unreachable block (ram,0xf003fc5c) */
/* WARNING: Removing unreachable block (ram,0xf003fd70) */
/* WARNING: Removing unreachable block (ram,0xf003fd24) */
/* WARNING: Removing unreachable block (ram,0xf003fce0) */
/* WARNING: Removing unreachable block (ram,0xf003fcb4) */
/* WARNING: Removing unreachable block (ram,0xf003fc74) */
/* WARNING: Removing unreachable block (ram,0xf003fc18) */
/* WARNING: Removing unreachable block (ram,0xf003fc08) */
/* WARNING: Removing unreachable block (ram,0xf003fc68) */
/* WARNING: Removing unreachable block (ram,0xf003fc88) */
/* WARNING: Removing unreachable block (ram,0xf003fcd8) */
/* WARNING: Removing unreachable block (ram,0xf003fcfc) */
/* WARNING: Removing unreachable block (ram,0xf003fd38) */
/* WARNING: Removing unreachable block (ram,0xf003fd7c) */
/* WARNING: Removing unreachable block (ram,0xf003fd88) */
/* WARNING: Removing unreachable block (ram,0xf003fbf4) */

undefined8 sub_F003FBE4(int param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  bool bVar5;
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
  iVar2 = param_1;
  _nfs_validate_caches(param_1,param_4,0);
  if (iVar2 != 0) goto locret_F003FD90;
  _rlock(*(undefined4 *)(param_1 + 0x30));
  iVar2 = param_1;
  _dnlc_lookup(param_1,param_2,param_4);
  *param_3 = iVar2;
  if (iVar2 == 0) {
    piVar1 = (int *)0x68;
    _kalloc();
    _bzero();
    _setdiropargs((undefined *)((int)register0x00000038 + -0x30),param_2,param_1);
    iVar2 = *(int *)(*(int *)(param_1 + 0x24) + 0x128);
    _rfscall(iVar2,4,_xdr_diropargs,(undefined *)((int)register0x00000038 + -0x30),_xdr_diropres,
             piVar1,param_4);
    if (iVar2 == 0) {
      iVar2 = *piVar1;
      if (iVar2 == 0x46) {
        _btrash(param_1);
        _nfs_invalidate_caches(param_1);
      }
      if (iVar2 == 0) {
        piVar3 = piVar1 + 1;
        _makenfsnode(piVar3,piVar1 + 9,*(undefined4 *)(param_1 + 0x24));
        *param_3 = (int)piVar3;
        if (_nfs_dnlc != 0) {
          _dnlc_enter(param_1,param_2,piVar3,param_4);
        }
      }
      else {
        *param_3 = 0;
      }
    }
    else {
      *param_3 = 0;
    }
    _kfree(piVar1,0x68);
    bVar5 = iVar2 == 0;
loc_F003FD44:
    if (bVar5) {
      iVar4 = *param_3;
      if ((*(int *)(iVar4 + 0x28) - 3U < 2) || (*(int *)(iVar4 + 0x28) == 8)) {
        _specvp(iVar4,(int)*(sword *)(iVar4 + 0x2c));
        _vn_rele(*param_3);
        *param_3 = iVar4;
      }
    }
  }
  else {
    *(sword *)(iVar2 + 6) = *(sword *)(iVar2 + 6) + 1;
    iVar2 = param_1;
    (**(code **)(*(int *)(param_1 + 0x1c) + 0x1c))(param_1,0x40,param_4);
    bVar5 = true;
    if (iVar2 == 0) goto loc_F003FD44;
    _vn_rele(*param_3);
  }
  _runlock(*(undefined4 *)(param_1 + 0x30));
locret_F003FD90:
  return CONCAT44(param_2,iVar2);
}

