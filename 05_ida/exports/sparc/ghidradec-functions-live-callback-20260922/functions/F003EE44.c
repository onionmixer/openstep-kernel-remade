
/* WARNING: Removing unreachable block (ram,0xf003eecc) */
/* WARNING: Removing unreachable block (ram,0xf003ee84) */
/* WARNING: Removing unreachable block (ram,0xf003ee78) */

undefined8 sub_F003EE44(int param_1,uint param_2,int param_3)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar1;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  int iVar2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar3;
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
  if (param_3 < 2) {
    iVar2 = *(int *)(param_1 + 0x30);
    if ((*(int *)(iVar2 + 0x7c) == 0) && (*(sword *)(iVar2 + 0x62) == 0)) {
      bVar3 = (param_2 & 2) == 0;
      if (((param_2 & 2) != 0) &&
         ((_nfs_cto != 0 ||
          (bVar3 = (param_2 & 2) == 0,
          (*(uint *)(*(int *)(*(int *)(param_1 + 0x24) + 0x128) + 0x14) & 0x4000000) == 0)))) {
        _sync_vp(param_1);
        bVar3 = (param_2 & 2) == 0;
      }
    }
    else {
      _sync_vp(param_1);
      _nfs_purge_caches(param_1,param_2);
      bVar3 = (param_2 & 2) == 0;
    }
    iVar1 = 0;
    if (!bVar3) {
      iVar1 = (int)*(sword *)(iVar2 + 0x62);
    }
  }
  else {
    iVar1 = 0;
  }
  return CONCAT44(param_2,iVar1);
}

