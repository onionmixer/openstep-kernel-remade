
/* WARNING: Removing unreachable block (ram,0xf003f924) */
/* WARNING: Removing unreachable block (ram,0xf003f900) */
/* WARNING: Removing unreachable block (ram,0xf003f8b4) */
/* WARNING: Removing unreachable block (ram,0xf003f874) */
/* WARNING: Removing unreachable block (ram,0xf003f80c) */
/* WARNING: Removing unreachable block (ram,0xf003f7e4) */
/* WARNING: Removing unreachable block (ram,0xf003f7cc) */
/* WARNING: Removing unreachable block (ram,0xf003f7f8) */
/* WARNING: Removing unreachable block (ram,0xf003f840) */
/* WARNING: Removing unreachable block (ram,0xf003f888) */
/* WARNING: Removing unreachable block (ram,0xf003f8f4) */
/* WARNING: Removing unreachable block (ram,0xf003f91c) */
/* WARNING: Removing unreachable block (ram,0xf003f93c) */
/* WARNING: Removing unreachable block (ram,0xf003f75c) */

undefined8 sub_F003F758(int *param_1,int param_2,undefined4 param_3)

{
  int *piVar1;
  int *piVar2;
  undefined4 unaff_l0;
  int iVar3;
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
  piVar1 = (int *)0x48;
  _kalloc();
  if (*(sword *)(param_2 + 0x14) == -1) {
    iVar3 = 0x16;
    if ((((*(int *)(param_2 + 0x1c) != -1) || (*(sword *)(param_2 + 0x38) != -1)) ||
        (*(int *)(param_2 + 0x3c) != -1)) || (*(int *)(param_2 + 0x30) != -1)) goto loc_F003F93C;
    if (*(int *)(param_2 + 0x34) == -1) {
      _sync_vp(param_1);
      if (*(int *)(param_2 + 0x18) == -1) {
        iVar3 = *(int *)(param_2 + 0x28);
      }
      else {
        piVar2 = param_1;
        _mfs_trunc();
        if (piVar2 == (int *)0x0) {
          iVar3 = *param_1;
        }
        else {
          _sync_vp(param_1);
          iVar3 = *param_1;
        }
        *(undefined4 *)(iVar3 + 0x14) = *(undefined4 *)(param_2 + 0x18);
        _binvalfree(param_1);
        *(undefined4 *)(param_1[0xc] + 0x98) = *(undefined4 *)(param_2 + 0x18);
        iVar3 = *(int *)(param_2 + 0x28);
      }
      if ((iVar3 != -1) && (*(int *)(param_2 + 0x2c) == -1)) {
        _getthetime((undefined *)((int)register0x00000038 + -0x50));
        *(undefined4 *)(param_2 + 0x20) = *(undefined4 *)((int)register0x00000038 + -0x50);
        *(undefined4 *)(param_2 + 0x24) = *(undefined4 *)((int)register0x00000038 + -0x4c);
        *(undefined4 *)(param_2 + 0x28) = *(undefined4 *)((int)register0x00000038 + -0x50);
        *(undefined4 *)(param_2 + 0x2c) = 1000000;
      }
      _vattr_to_sattr(param_2,(undefined *)((int)register0x00000038 + -0x28));
      _bcopy(param_1[0xc] + 0x40,(undefined *)((int)register0x00000038 + -0x48),0x20);
      iVar3 = *(int *)(param_1[9] + 0x128);
      _rfscall(iVar3,2,_xdr_saargs,(undefined *)((int)register0x00000038 + -0x48),_xdr_attrstat,
               piVar1,param_3);
      if (iVar3 == 0) {
        iVar3 = *piVar1;
        if (iVar3 == 0) {
          *(int *)((int)register0x00000038 + -0x58) = piVar1[0xe];
          *(int *)((int)register0x00000038 + -0x54) = piVar1[0xf];
          _nfs_cache_check(param_1,(undefined *)((int)register0x00000038 + -0x58),piVar1[6],2);
          _nfs_attrcache(param_1,piVar1 + 1);
        }
        else {
          *(undefined4 *)(param_1[0xc] + 0xc0) = 0;
          if (iVar3 == 0x46) {
            _btrash(param_1);
            _nfs_invalidate_caches(param_1);
          }
        }
      }
      else {
        *(undefined4 *)(param_1[0xc] + 0xc0) = 0;
      }
      goto loc_F003F93C;
    }
  }
  iVar3 = 0x16;
loc_F003F93C:
  _kfree(piVar1,0x48);
  return CONCAT44(param_2,iVar3);
}

