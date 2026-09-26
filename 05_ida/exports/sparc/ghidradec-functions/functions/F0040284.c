
/* WARNING: Removing unreachable block (ram,0xf004038c) */
/* WARNING: Removing unreachable block (ram,0xf0040370) */
/* WARNING: Removing unreachable block (ram,0xf0040330) */
/* WARNING: Removing unreachable block (ram,0xf0040304) */
/* WARNING: Removing unreachable block (ram,0xf004034c) */
/* WARNING: Removing unreachable block (ram,0xf0040378) */
/* WARNING: Removing unreachable block (ram,0xf0040394) */
/* WARNING: Removing unreachable block (ram,0xf00402fc) */

undefined8 sub_F0040284(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
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
  iVar1 = param_1;
  (**(code **)(*(int *)(param_1 + 0x1c) + 0x70))
            (param_1,(undefined *)((int)register0x00000038 + -0x54));
  if (iVar1 == 0) {
    param_1 = *(int *)((int)register0x00000038 + -0x54);
  }
  iVar1 = *(int *)(param_1 + 0x30);
  *(undefined4 *)((int)register0x00000038 + -0x50) = *(undefined4 *)(iVar1 + 0x40);
  *(undefined4 *)((int)register0x00000038 + -0x4c) = *(undefined4 *)(iVar1 + 0x44);
  *(undefined4 *)((int)register0x00000038 + -0x48) = *(undefined4 *)(iVar1 + 0x48);
  *(undefined4 *)((int)register0x00000038 + -0x44) = *(undefined4 *)(iVar1 + 0x4c);
  *(undefined4 *)((int)register0x00000038 + -0x40) = *(undefined4 *)(iVar1 + 0x50);
  *(undefined4 *)((int)register0x00000038 + -0x3c) = *(undefined4 *)(iVar1 + 0x54);
  *(undefined4 *)((int)register0x00000038 + -0x38) = *(undefined4 *)(iVar1 + 0x58);
  *(undefined4 *)((int)register0x00000038 + -0x34) = *(undefined4 *)(iVar1 + 0x5c);
  _setdiropargs((undefined *)((int)register0x00000038 + -0x30),param_3,param_2);
  _rlock(*(undefined4 *)(param_2 + 0x30));
  iVar1 = *(int *)(*(int *)(param_1 + 0x24) + 0x128);
  _rfscall(iVar1,0xc,_xdr_linkargs,(undefined *)((int)register0x00000038 + -0x50),_xdr_enum,
           (undefined *)((int)register0x00000038 + -0x58),param_4);
  *(undefined4 *)(*(int *)(param_2 + 0x30) + 0xc0) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x30) + 0xc0) = 0;
  _runlock(*(undefined4 *)(param_2 + 0x30));
  if ((iVar1 == 0) && (iVar1 = *(int *)((int)register0x00000038 + -0x58), iVar1 == 0x46)) {
    _btrash(param_1);
    _nfs_invalidate_caches(param_1);
    _btrash(param_2);
    _nfs_invalidate_caches(param_2);
  }
  return CONCAT44(param_2,iVar1);
}
