/* GHIDRADEC_FUNCTION index=1050 start=0xf00506a0 */

undefined8 _locc(uint param_1,int param_2,byte *param_3)

{
  byte bVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  byte *pbVar2;
  int iVar3;
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
  pbVar2 = param_3 + param_2;
  if (param_3 < pbVar2) {
    bVar1 = *param_3;
    while ((uint)bVar1 != (param_1 & 0xff)) {
      param_3 = param_3 + 1;
      if (pbVar2 <= param_3) {
        iVar3 = (int)pbVar2 - (int)param_3;
        goto locret_F00506E0;
      }
      bVar1 = *param_3;
    }
    iVar3 = (int)pbVar2 - (int)param_3;
  }
  else {
    iVar3 = (int)pbVar2 - (int)param_3;
  }
locret_F00506E0:
  return CONCAT44(param_2,iVar3);
}
/* GHIDRADEC_FUNCTION index=1051 start=0xf00510fc */

/* WARNING: Removing unreachable block (ram,0xf00511fc) */
/* WARNING: Removing unreachable block (ram,0xf00511c8) */
/* WARNING: Removing unreachable block (ram,0xf005117c) */
/* WARNING: Removing unreachable block (ram,0xf0051138) */
/* WARNING: Removing unreachable block (ram,0xf005114c) */
/* WARNING: Removing unreachable block (ram,0xf0051198) */
/* WARNING: Removing unreachable block (ram,0xf00511e8) */
/* WARNING: Removing unreachable block (ram,0xf0051204) */
/* WARNING: Removing unreachable block (ram,0xf0051128) */

undefined8 _sbupdate(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar4;
  int iVar5;
  undefined4 unaff_l3;
  int iVar6;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  int iVar7;
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
  iVar1 = *(int *)(param_1 + 8);
  iVar6 = *(int *)(*(int *)(param_1 + 0xc) + 0x20);
  (**(code **)(*(int *)(iVar1 + 0x1c) + 0x80))();
  uVar2 = 0x2000;
  if (-1 < iVar1) {
    .div(0x2000,iVar1);
    iVar1 = *(int *)(param_1 + 8);
    _getblk(iVar1,uVar2,*(undefined4 *)(iVar6 + 0x68));
    _bcopy(iVar6,*(undefined4 *)(iVar1 + 0x20),*(undefined4 *)(iVar6 + 0x68));
    *(undefined4 *)(*(int *)(iVar1 + 0x20) + 0x8c) = 0;
    *(undefined4 *)(*(int *)(iVar1 + 0x20) + 0x88) = 0;
    *(undefined4 *)(*(int *)(iVar1 + 0x20) + 0x94) = 0;
    *(undefined4 *)(*(int *)(iVar1 + 0x20) + 0x90) = 0;
    *(undefined *)(*(int *)(iVar1 + 0x20) + 0xd3) = 0;
    _bwrite(iVar1);
    iVar7 = *(int *)(iVar6 + 0x2d8);
    iVar5 = 0;
    iVar1 = *(int *)(iVar6 + 0x9c) + -1 + *(int *)(iVar6 + 0x34);
    .div();
    if (0 < iVar1) {
      iVar3 = *(int *)(iVar6 + 0x38);
      do {
        iVar4 = *(int *)(iVar6 + 0x30);
        if (iVar1 < iVar5 + iVar3) {
          iVar4 = iVar1 - iVar5;
          .umul(iVar4,*(undefined4 *)(iVar6 + 0x34));
        }
        iVar3 = *(int *)(param_1 + 8);
        _getblk(iVar3,*(int *)(iVar6 + 0x98) + iVar5 << ((byte)*(undefined4 *)(iVar6 + 100) & 0x1f),
                iVar4);
        _bcopy(iVar7,*(undefined4 *)(iVar3 + 0x20),iVar4);
        _bwrite(iVar3);
        iVar3 = *(int *)(iVar6 + 0x38);
        iVar5 = iVar5 + iVar3;
        iVar7 = iVar7 + iVar4;
      } while (iVar5 < iVar1);
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1052 start=0xf0052ffc */

/* WARNING: Removing unreachable block (ram,0xf0053038) */

undefined8
_rdwri(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
      undefined4 param_6)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 *puVar1;
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
  *(qword *)((int)register0x00000038 + -0x28) = CONCAT44(param_3,param_4);
  *(undefined **)((int)register0x00000038 + -0x20) = (undefined *)((int)register0x00000038 + -0x28);
  *(undefined4 *)((int)register0x00000038 + -0x1c) = 1;
  *(qword *)((int)register0x00000038 + -0x18) = CONCAT44(param_5,param_6);
  *(undefined4 *)((int)register0x00000038 + -0xc) = param_4;
  param_2 = param_2 + 0xc;
  puVar1 = *(undefined4 **)((int)register0x00000038 + 0x5c);
  sub_F0051444(param_2,(undefined *)((int)register0x00000038 + -0x20),param_1,0,
               *(undefined4 *)(_active_u + 0x1c));
  if (puVar1 == (undefined4 *)0x0) {
    if (*(int *)((int)register0x00000038 + -0xc) != 0) {
      param_2 = 5;
    }
  }
  else {
    *puVar1 = *(undefined4 *)((int)register0x00000038 + -0xc);
  }
  return CONCAT44(puVar1,param_2);
}
/* GHIDRADEC_FUNCTION index=1053 start=0xf00539c4 */

sqword _ufs_nlinks(int param_1,int *param_2)

{
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
  *param_2 = (int)*(sword *)(*(int *)(param_1 + 0x30) + 0x66);
  return ZEXT48(param_2) << 0x20;
}
/* GHIDRADEC_FUNCTION index=1054 start=0xf00539dc */

/* WARNING: Removing unreachable block (ram,0xf00539ec) */

undefined8 _ipc_entry_tree_collision(int param_1,uint param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar1;
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
  _ipc_splay_tree_bounds
            (param_1 + 0x20,param_2,(undefined *)((int)register0x00000038 + -0xc),
             (undefined *)((int)register0x00000038 + -0x10));
  uVar1 = 0;
  param_2 = param_2 >> 8;
  if ((*(uint *)((int)register0x00000038 + -0xc) == 0xffffffff) ||
     (*(uint *)((int)register0x00000038 + -0xc) >> 8 != param_2)) {
    if ((*(uint *)((int)register0x00000038 + -0x10) != 0) &&
       (*(uint *)((int)register0x00000038 + -0x10) >> 8 == param_2)) {
      uVar1 = 1;
    }
  }
  else {
    uVar1 = 1;
  }
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=1055 start=0xf0053a3c */

/* WARNING: Removing unreachable block (ram,0xf0053aac) */

undefined8 _ipc_entry_lookup(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
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
  iVar1 = (param_2 >> 8) * 0x10;
  if (param_2 >> 8 < *(uint *)(param_1 + 0x18)) {
    uVar2 = *(uint *)(*(int *)(param_1 + 0x14) + iVar1);
    iVar1 = *(int *)(param_1 + 0x14) + iVar1;
    if ((uVar2 & 0xff000000) + param_2 * -0x1000000 != 0) {
      uVar2 = uVar2 & 0x800000;
      goto loc_F0053AA4;
    }
    if ((uVar2 & 0x1f0000) != 0) goto locret_F0053AB8;
  }
  else {
    uVar2 = *(uint *)(param_1 + 0x38);
loc_F0053AA4:
    iVar1 = param_1 + 0x20;
    if (uVar2 != 0) {
      _ipc_splay_tree_lookup(iVar1,param_2);
      goto locret_F0053AB8;
    }
  }
  iVar1 = 0;
locret_F0053AB8:
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=1056 start=0xf0053ac0 */

undefined8 _ipc_entry_get(int param_1,uint *param_2,int *param_3)

{
  uint uVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar2;
  undefined4 unaff_i1;
  uint *puVar3;
  undefined4 unaff_i2;
  int iVar4;
  undefined4 unaff_i3;
  int iVar5;
  undefined4 unaff_i4;
  int iVar6;
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
  iVar5 = *(int *)(param_1 + 0x14);
  iVar6 = *(int *)(iVar5 + 8);
  if (iVar6 == 0) {
    uVar2 = 3;
  }
  else {
    puVar3 = (uint *)(iVar6 * 0x10);
    iVar4 = iVar5 + (int)puVar3;
    uVar2 = 0;
    *(undefined4 *)(iVar5 + 8) = *(undefined4 *)(iVar4 + 8);
    uVar1 = *(int *)(iVar5 + (int)puVar3) + 0x1000000;
    *(uint *)(iVar5 + (int)puVar3) = uVar1;
    *(undefined4 *)(iVar4 + 8) = 0;
    *param_2 = iVar6 << 8 | uVar1 >> 0x18;
    *param_3 = iVar4;
    param_2 = puVar3;
  }
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=1057 start=0xf0053b28 */

/* WARNING: Removing unreachable block (ram,0xf0053b74) */
/* WARNING: Removing unreachable block (ram,0xf0053b88) */
/* WARNING: Removing unreachable block (ram,0xf0053b40) */

undefined8 _ipc_entry_alloc(int param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
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
    } while (*(int *)(param_1 + 8) != 0);
    piVar1 = (int *)(param_1 + 8);
    _simple_lock_try();
  } while (piVar1 == (int *)0x0);
  iVar2 = *(int *)(param_1 + 0xc);
  do {
    if (iVar2 == 0) {
      *(undefined4 *)(param_1 + 8) = 0;
      iVar2 = 0x10;
locret_F0053BA0:
      return CONCAT44(param_2,iVar2);
    }
    iVar2 = param_1;
    _ipc_entry_get(param_1,param_2,param_3);
    if (iVar2 == 0) {
      iVar2 = 0;
      goto locret_F0053BA0;
    }
    iVar2 = param_1;
    _ipc_entry_grow_table();
    if (iVar2 != 0) goto locret_F0053BA0;
    iVar2 = *(int *)(param_1 + 0xc);
  } while( true );
}
/* GHIDRADEC_FUNCTION index=1058 start=0xf0053ba8 */

/* WARNING: Removing unreachable block (ram,0xf0053e28) */
/* WARNING: Removing unreachable block (ram,0xf0053dd8) */
/* WARNING: Removing unreachable block (ram,0xf0053d5c) */
/* WARNING: Removing unreachable block (ram,0xf0053cf0) */
/* WARNING: Removing unreachable block (ram,0xf0053cd0) */
/* WARNING: Removing unreachable block (ram,0xf0053c04) */
/* WARNING: Removing unreachable block (ram,0xf0053c64) */
/* WARNING: Removing unreachable block (ram,0xf0053d10) */
/* WARNING: Removing unreachable block (ram,0xf0053d7c) */
/* WARNING: Removing unreachable block (ram,0xf0053e00) */
/* WARNING: Removing unreachable block (ram,0xf0053e54) */
/* WARNING: Removing unreachable block (ram,0xf0053bcc) */

undefined8 _ipc_entry_alloc_name(int param_1,uint param_2,int *param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  int *piVar7;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 *puVar8;
  uint uVar9;
  undefined4 unaff_l3;
  int iVar10;
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
  uVar9 = param_2 >> 8;
  do {
    do {
    } while (*(int *)(param_1 + 8) != 0);
    piVar7 = (int *)(param_1 + 8);
    _simple_lock_try();
  } while (piVar7 == (int *)0x0);
  iVar10 = uVar9 * 0x10;
  iVar3 = *(int *)(param_1 + 0xc);
  puVar8 = (undefined4 *)0x0;
loc_F0053BE8:
  if (iVar3 == 0) goto loc_f0053bf4;
  if (uVar9 == 0) {
    iVar3 = *(int *)(param_1 + 0x38);
  }
  else if (uVar9 < *(uint *)(param_1 + 0x18)) {
    iVar3 = *(int *)(param_1 + 0x14);
    piVar7 = (int *)(iVar3 + iVar10);
    if ((*(uint *)(iVar3 + iVar10) & 0x1f0000) == 0) {
      uVar2 = *(uint *)(iVar3 + 8);
      uVar6 = 0;
      while (uVar1 = uVar2, uVar1 != uVar9) {
        uVar6 = uVar1;
        uVar2 = *(uint *)(iVar3 + uVar1 * 0x10 + 8);
      }
      *(undefined4 *)(iVar3 + uVar6 * 0x10 + 8) = *(undefined4 *)(iVar3 + uVar1 * 0x10 + 8);
      *piVar7 = param_2 * 0x1000000;
      piVar7[2] = 0;
      *param_3 = (int)piVar7;
      if (puVar8 == (undefined4 *)0x0) {
loc_F0053E1C:
        iVar3 = 0;
        goto locret_F0053E70;
      }
      _zfree(_ipc_tree_entry_zone,puVar8);
      iVar3 = 0;
      goto locret_F0053E70;
    }
    if ((*(uint *)(iVar3 + iVar10) & 0xff000000) + param_2 * -0x1000000 == 0) {
      *param_3 = (int)piVar7;
      if (puVar8 == (undefined4 *)0x0) goto loc_F0053E1C;
      _zfree(_ipc_tree_entry_zone,puVar8);
      iVar3 = 0;
      goto locret_F0053E70;
    }
    iVar3 = *(int *)(param_1 + 0x38);
  }
  else {
    iVar3 = *(int *)(param_1 + 0x38);
  }
  iVar4 = param_1 + 0x20;
  if (iVar3 != 0) {
    _ipc_splay_tree_lookup(iVar4,param_2);
    if (iVar4 != 0) {
      *param_3 = iVar4;
      if (puVar8 == (undefined4 *)0x0) goto loc_F0053E1C;
      _zfree(_ipc_tree_entry_zone,puVar8);
      iVar3 = 0;
      goto locret_F0053E70;
    }
  }
  puVar5 = _ipc_tree_entry_zone;
  if (((uVar9 < *(uint *)(param_1 + 0x18)) || (uVar6 = **(uint **)(param_1 + 0x1c), uVar6 <= uVar9))
     || ((uint)((*(int *)(param_1 + 0x3c) + 1) * 0x20) <= (uVar6 - *(uint *)(param_1 + 0x18)) * 0x10
        )) {
    if (puVar8 != (undefined4 *)0x0) {
      *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + 1;
      if (uVar9 < *(uint *)(param_1 + 0x18)) {
        *(uint *)(*(int *)(param_1 + 0x14) + iVar10) =
             *(uint *)(*(int *)(param_1 + 0x14) + iVar10) | 0x800000;
      }
      else if ((uVar9 < **(uint **)(param_1 + 0x1c)) &&
              (iVar3 = param_1, _ipc_entry_tree_collision(param_1,param_2), iVar3 == 0)) {
        *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + 1;
      }
      _ipc_splay_tree_insert(param_1 + 0x20,param_2,puVar8);
      *puVar8 = 0;
      puVar8[1] = 0;
      puVar8[2] = 0;
      puVar8[5] = param_1;
      *param_3 = (int)puVar8;
      goto loc_F0053E1C;
    }
    *(undefined4 *)(param_1 + 8) = 0;
    _zalloc();
    if (puVar5 == (undefined4 *)0x0) {
      iVar3 = 6;
      goto locret_F0053E70;
    }
    do {
      do {
      } while (*(int *)(param_1 + 8) != 0);
      piVar7 = (int *)(param_1 + 8);
      _simple_lock_try();
    } while (piVar7 == (int *)0x0);
    iVar3 = *(int *)(param_1 + 0xc);
    puVar8 = puVar5;
  }
  else {
    iVar3 = param_1;
    _ipc_entry_grow_table();
    if (iVar3 != 0) {
      if (puVar8 != (undefined4 *)0x0) {
        _zfree(_ipc_tree_entry_zone,puVar8);
      }
      goto locret_F0053E70;
    }
    iVar3 = *(int *)(param_1 + 0xc);
  }
  goto loc_F0053BE8;
loc_f0053bf4:
  *(undefined4 *)(param_1 + 8) = 0;
  if (puVar8 != (undefined4 *)0x0) {
    _zfree(_ipc_tree_entry_zone,puVar8);
  }
  iVar3 = 0x10;
locret_F0053E70:
  return CONCAT44(param_2,iVar3);
}
/* GHIDRADEC_FUNCTION index=1059 start=0xf0053e78 */

/* WARNING: Removing unreachable block (ram,0xf0054038) */
/* WARNING: Removing unreachable block (ram,0xf0053fac) */
/* WARNING: Removing unreachable block (ram,0xf0053f80) */
/* WARNING: Removing unreachable block (ram,0xf0053f54) */
/* WARNING: Removing unreachable block (ram,0xf0053ef4) */
/* WARNING: Removing unreachable block (ram,0xf0053edc) */
/* WARNING: Removing unreachable block (ram,0xf0053f40) */
/* WARNING: Removing unreachable block (ram,0xf0053f64) */
/* WARNING: Removing unreachable block (ram,0xf0053fa0) */
/* WARNING: Removing unreachable block (ram,0xf0053fdc) */
/* WARNING: Removing unreachable block (ram,0xf0053ffc) */
/* WARNING: Removing unreachable block (ram,0xf0053ec8) */

undefined8 _ipc_entry_dealloc(int param_1,uint param_2,int param_3)

{
  undefined *puVar1;
  uint *puVar2;
  int iVar3;
  undefined4 unaff_l0;
  uint uVar4;
  undefined4 unaff_l1;
  int iVar5;
  uint uVar6;
  undefined *puVar7;
  undefined4 unaff_l3;
  int iVar8;
  undefined4 unaff_l4;
  int iVar9;
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
  bool bVar10;
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
  uVar6 = *(uint *)(param_1 + 0x18);
  uVar4 = param_2 >> 8;
  iVar5 = *(int *)(param_1 + 0x14);
  if ((uVar4 < uVar6) && (iVar8 = uVar4 * 0x10, param_3 == iVar5 + iVar8)) {
    iVar9 = param_1 + 0x20;
    if ((*(uint *)(iVar5 + iVar8) & 0x800000) == 0) {
      *(uint *)(iVar5 + iVar8) = *(uint *)(iVar5 + iVar8) & 0xff000000;
      *(undefined4 *)(param_3 + 8) = *(undefined4 *)(iVar5 + 8);
      *(uint *)(iVar5 + 8) = uVar4;
    }
    else {
      puVar7 = (undefined *)((int)register0x00000038 + -0x38);
      _ipc_splay_tree_split(iVar9,(uVar4 + 1) * 0x100,puVar7);
      _ipc_splay_tree_split(puVar7,uVar4 << 8,(undefined *)((int)register0x00000038 + -0x20));
      _ipc_splay_tree_pick
                (puVar7,(undefined *)((int)register0x00000038 + -0x3c),
                 (undefined *)((int)register0x00000038 + -0x40));
      puVar2 = *(uint **)((int)register0x00000038 + -0x40);
      iVar3 = *(int *)((int)register0x00000038 + -0x3c);
      uVar6 = *puVar2;
      *(uint *)(iVar5 + iVar8) = uVar6 | iVar3 << 0x18;
      param_2 = puVar2[1];
      *(uint *)(param_3 + 4) = param_2;
      *(uint *)(param_3 + 8) = puVar2[2];
      if ((uVar6 & 0x1f0000) == 0x10000) {
        _ipc_hash_global_delete(param_1,param_2,iVar3);
        _ipc_hash_local_insert(param_1,param_2,uVar4,param_3);
      }
      _ipc_splay_tree_delete
                (puVar7,*(undefined4 *)((int)register0x00000038 + -0x3c),
                 *(undefined4 *)((int)register0x00000038 + -0x40));
      *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + -1;
      puVar1 = puVar7;
      _ipc_splay_tree_pick
                (puVar7,(undefined *)((int)register0x00000038 + -0x3c),
                 (undefined *)((int)register0x00000038 + -0x40));
      if (puVar1 != (undefined *)0x0) {
        *(uint *)(iVar5 + iVar8) = *(uint *)(iVar5 + iVar8) | 0x800000;
        _ipc_splay_tree_join(iVar9,puVar7);
      }
      _ipc_splay_tree_join(iVar9,(undefined *)((int)register0x00000038 + -0x20));
    }
  }
  else {
    _ipc_splay_tree_delete(param_1 + 0x20,param_2,param_3);
    *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + -1;
    if (uVar4 < uVar6) {
      _ipc_entry_tree_collision(param_1,param_2);
      bVar10 = param_1 == 0;
      param_1 = uVar4 * 0x10;
      if (bVar10) {
        *(uint *)(iVar5 + param_1) = *(uint *)(iVar5 + param_1) & 0xff7fffff;
      }
    }
    else if ((uVar4 < **(uint **)(param_1 + 0x1c)) &&
            (iVar5 = param_1, _ipc_entry_tree_collision(param_1,param_2), iVar5 == 0)) {
      *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + -1;
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1060 start=0xf0054060 */

/* WARNING: Removing unreachable block (ram,0xf0054484) */
/* WARNING: Removing unreachable block (ram,0xf0054410) */
/* WARNING: Removing unreachable block (ram,0xf00543f8) */
/* WARNING: Removing unreachable block (ram,0xf00543cc) */
/* WARNING: Removing unreachable block (ram,0xf0054390) */
/* WARNING: Removing unreachable block (ram,0xf0054360) */
/* WARNING: Removing unreachable block (ram,0xf00542e0) */
/* WARNING: Removing unreachable block (ram,0xf00542c8) */
/* WARNING: Removing unreachable block (ram,0xf0054288) */
/* WARNING: Removing unreachable block (ram,0xf0054214) */
/* WARNING: Removing unreachable block (ram,0xf00541bc) */
/* WARNING: Removing unreachable block (ram,0xf005417c) */
/* WARNING: Removing unreachable block (ram,0xf0054134) */
/* WARNING: Removing unreachable block (ram,0xf00540a8) */
/* WARNING: Removing unreachable block (ram,0xf0054154) */
/* WARNING: Removing unreachable block (ram,0xf00541a8) */
/* WARNING: Removing unreachable block (ram,0xf00541d4) */
/* WARNING: Removing unreachable block (ram,0xf005424c) */
/* WARNING: Removing unreachable block (ram,0xf00542b4) */
/* WARNING: Removing unreachable block (ram,0xf00542d8) */
/* WARNING: Removing unreachable block (ram,0xf005434c) */
/* WARNING: Removing unreachable block (ram,0xf0054378) */
/* WARNING: Removing unreachable block (ram,0xf00543a0) */
/* WARNING: Removing unreachable block (ram,0xf00543e4) */
/* WARNING: Removing unreachable block (ram,0xf0054404) */
/* WARNING: Removing unreachable block (ram,0xf0054470) */
/* WARNING: Removing unreachable block (ram,0xf005449c) */
/* WARNING: Removing unreachable block (ram,0xf0054124) */
/* WARNING: Removing unreachable block (ram,0xf005408c) */
/* WARNING: Removing unreachable block (ram,0xf0054080) */

undefined8 _ipc_entry_grow_table(int param_1,uint *param_2)

{
  int iVar1;
  int *piVar2;
  undefined *puVar3;
  uint *puVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 unaff_l0;
  uint uVar7;
  uint *puVar8;
  uint uVar9;
  undefined4 unaff_l1;
  uint *puVar10;
  uint *puVar11;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  uint uVar12;
  undefined4 unaff_l5;
  uint uVar13;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined *puVar14;
  undefined4 unaff_i0;
  undefined4 uVar15;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  uint uVar16;
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
  puVar14 = (undefined *)((int)register0x00000038 + -0x50);
  iVar1 = *(int *)(param_1 + 0x10);
  do {
    if (iVar1 != 0) {
      _assert_wait(param_1,0);
      *(undefined4 *)(param_1 + 8) = 0;
      _thread_block_with_continuation(0);
      do {
        do {
        } while (*(int *)(param_1 + 8) != 0);
        piVar2 = (int *)(param_1 + 8);
        _simple_lock_try();
        uVar15 = 0;
      } while (piVar2 == (int *)0x0);
locret_F00544F8:
      return CONCAT44(param_2,uVar15);
    }
    puVar10 = *(uint **)(param_1 + 0x1c);
    uVar15 = *(undefined4 *)(param_1 + 0x14);
    uVar13 = *puVar10;
    param_2 = puVar10 + -1;
    uVar12 = puVar10[-1];
    uVar16 = puVar10[1];
    if (uVar12 == uVar13) {
      *(undefined4 *)(param_1 + 8) = 0;
      uVar15 = 3;
      goto locret_F00544F8;
    }
    *(undefined4 *)(param_1 + 0x10) = 1;
    *(undefined4 *)(param_1 + 8) = 0;
    puVar4 = (uint *)(puVar10[-1] << 4);
    if (puVar4 < _page_size) {
      puVar4 = (uint *)(*puVar10 << 4);
      _ipc_table_alloc();
    }
    else {
      _ipc_table_realloc(puVar4,uVar15,*puVar10 << 4);
    }
    do {
      do {
      } while (*(int *)(param_1 + 8) != 0);
      piVar2 = (int *)(param_1 + 8);
      _simple_lock_try();
    } while (piVar2 == (int *)0x0);
    *(undefined4 *)(param_1 + 0x10) = 0;
    if (puVar4 == (uint *)0x0) {
      *(undefined4 *)(param_1 + 8) = 0;
      _thread_wakeup_prim(param_1,0,0);
      uVar15 = 6;
      goto locret_F00544F8;
    }
    if (*(int *)(param_1 + 0xc) == 0) {
      *(undefined4 *)(param_1 + 8) = 0;
      _thread_wakeup_prim(param_1,0,0);
      _ipc_table_free(*puVar10 << 4,puVar4);
      do {
        do {
        } while (*(int *)(param_1 + 8) != 0);
        piVar2 = (int *)(param_1 + 8);
        _simple_lock_try();
        uVar15 = 0;
      } while (piVar2 == (int *)0x0);
      goto locret_F00544F8;
    }
    *(uint **)(param_1 + 0x14) = puVar4;
    *(uint *)(param_1 + 0x18) = uVar13;
    *(uint **)(param_1 + 0x1c) = puVar10 + 1;
    if ((uint *)(*param_2 << 4) < _page_size) {
      _bcopy(uVar15,puVar4,uVar12 << 4);
    }
    uVar7 = 0;
    puVar8 = puVar4;
    if (uVar12 != 0) {
      do {
        puVar8[3] = 0;
        uVar7 = uVar7 + 1;
        puVar8 = puVar8 + 4;
      } while (uVar7 < uVar12);
    }
    _bzero(puVar4 + uVar12 * 4,(uVar13 - uVar12) * 0x10);
    uVar7 = 0;
    puVar8 = puVar4;
    if (uVar12 == 0) {
      iVar1 = *(int *)(param_1 + 0x38);
    }
    else {
      do {
        if ((*puVar8 & 0x1f0000) == 0x10000) {
          _ipc_hash_local_insert(param_1,puVar8[1],uVar7,puVar8);
        }
        uVar7 = uVar7 + 1;
        puVar8 = puVar8 + 4;
      } while (uVar7 < uVar12);
      iVar1 = *(int *)(param_1 + 0x38);
    }
    if (iVar1 != 0) {
      _ipc_splay_tree_split(param_1 + 0x20,uVar16 << 8,puVar14);
      puVar8 = (uint *)((int)register0x00000038 + -0x38);
      _ipc_splay_tree_split(puVar14,uVar13 << 8,puVar8);
      _ipc_splay_tree_split(puVar8,uVar12 << 8,(undefined *)((int)register0x00000038 + -0x20));
      _ipc_splay_traverse_start();
      while (puVar8 != (uint *)0x0) {
        uVar7 = puVar8[4] >> 8;
        puVar11 = puVar4 + uVar7 * 4;
        if (puVar4[uVar7 * 4] == 0) {
          uVar6 = *puVar8;
          puVar4[uVar7 * 4] = uVar6 | puVar8[4] << 0x18;
          uVar9 = puVar8[1];
          puVar11[1] = uVar9;
          puVar11[2] = puVar8[2];
          if ((uVar6 & 0x1f0000) == 0x10000) {
            _ipc_hash_global_delete(param_1,uVar9);
            _ipc_hash_local_insert(param_1,uVar9,uVar7,puVar11);
          }
          uVar5 = 1;
          *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + -1;
        }
        else {
          puVar4[uVar7 * 4] = puVar4[uVar7 * 4] | 0x800000;
          uVar5 = 0;
        }
        puVar8 = (uint *)((int)register0x00000038 + -0x38);
        _ipc_splay_traverse_next(puVar8,uVar5);
      }
      _ipc_splay_traverse_finish((undefined *)((int)register0x00000038 + -0x38));
      iVar1 = 0;
      uVar7 = 0;
      puVar3 = (undefined *)((int)register0x00000038 + -0x50);
      _ipc_splay_traverse_start();
      while (puVar3 != (undefined *)0x0) {
        if (*(uint *)(puVar3 + 0x10) >> 8 != uVar7) {
          iVar1 = iVar1 + 1;
          uVar7 = *(uint *)(puVar3 + 0x10) >> 8;
        }
        puVar3 = (undefined *)((int)register0x00000038 + -0x50);
        _ipc_splay_traverse_next(puVar3,0);
      }
      _ipc_splay_traverse_finish(puVar14);
      *(int *)(param_1 + 0x3c) = iVar1;
      iVar1 = param_1 + 0x20;
      _ipc_splay_tree_join(iVar1,puVar14);
      _ipc_splay_tree_join(iVar1,(undefined *)((int)register0x00000038 + -0x38));
      _ipc_splay_tree_join(iVar1,(undefined *)((int)register0x00000038 + -0x20));
    }
    uVar6 = uVar13 - 1;
    uVar7 = puVar4[2];
    if (uVar12 <= uVar6) {
      puVar8 = puVar4 + uVar6 * 4;
      do {
        if (*puVar8 == 0) {
          *puVar8 = 0xff000000;
          puVar8[2] = uVar7;
          uVar7 = uVar6;
        }
        uVar6 = uVar6 - 1;
        puVar8 = puVar8 + -4;
      } while (uVar12 <= uVar6);
    }
    puVar4[2] = uVar7;
    *(undefined4 *)(param_1 + 8) = 0;
    _thread_wakeup_prim(param_1,0,0);
    _ipc_table_free(*param_2 << 4,uVar15);
    do {
      do {
      } while (*(int *)(param_1 + 8) != 0);
      piVar2 = (int *)(param_1 + 8);
      _simple_lock_try();
    } while (piVar2 == (int *)0x0);
    if (*(int *)(param_1 + 0xc) == 0) {
      uVar15 = 0;
      goto locret_F00544F8;
    }
    if (*(uint **)(param_1 + 0x1c) != puVar10 + 1) {
      uVar15 = 0;
      goto locret_F00544F8;
    }
    if ((*(int *)(param_1 + 0x3c) == 0) ||
       ((uint)(*(int *)(param_1 + 0x3c) << 5) <= (uVar16 - uVar13) * 0x10)) {
      uVar15 = 0;
      goto locret_F00544F8;
    }
    iVar1 = *(int *)(param_1 + 0x10);
  } while( true );
}
/* GHIDRADEC_FUNCTION index=1061 start=0xf0054500 */

/* WARNING: Removing unreachable block (ram,0xf0054540) */
/* WARNING: Removing unreachable block (ram,0xf0054514) */

undefined8 _ipc_hash_lookup(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 uVar2;
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
  uVar2 = 0;
  iVar1 = param_1;
  _ipc_hash_local_lookup(param_1,param_2,param_3,param_4);
  if (iVar1 == 0) {
    if ((*(int *)(param_1 + 0x40) != 0) &&
       (_ipc_hash_global_lookup(param_1,param_2,param_3,param_4), param_1 != 0)) {
      uVar2 = 1;
    }
  }
  else {
    uVar2 = 1;
  }
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=1062 start=0xf005455c */

/* WARNING: Removing unreachable block (ram,0xf00545a0) */
/* WARNING: Removing unreachable block (ram,0xf005458c) */

undefined8 _ipc_hash_insert(int param_1,undefined4 param_2,uint param_3,int param_4)

{
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
  if ((param_3 >> 8 < *(uint *)(param_1 + 0x18)) &&
     (param_4 == *(int *)(param_1 + 0x14) + (param_3 >> 8) * 0x10)) {
    _ipc_hash_local_insert(param_1,param_2);
  }
  else {
    _ipc_hash_global_insert(param_1,param_2,param_3);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1063 start=0xf00545b0 */

/* WARNING: Removing unreachable block (ram,0xf00545f4) */
/* WARNING: Removing unreachable block (ram,0xf00545e0) */

undefined8 _ipc_hash_delete(int param_1,undefined4 param_2,uint param_3,int param_4)

{
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
  if ((param_3 >> 8 < *(uint *)(param_1 + 0x18)) &&
     (param_4 == *(int *)(param_1 + 0x14) + (param_3 >> 8) * 0x10)) {
    _ipc_hash_local_delete(param_1,param_2);
  }
  else {
    _ipc_hash_global_delete(param_1,param_2,param_3);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1064 start=0xf0054604 */

/* WARNING: Removing unreachable block (ram,0xf0054640) */

undefined8 _ipc_hash_global_lookup(uint param_1,uint param_2,undefined4 *param_3,int *param_4)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 unaff_l0;
  int *piVar5;
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
  piVar5 = (int *)(_ipc_hash_global_table +
                  ((param_1 >> 4) + (param_2 >> 6) & _ipc_hash_global_mask) * 8);
  do {
    do {
    } while (*piVar5 != 0);
    piVar1 = piVar5;
    _simple_lock_try();
  } while (piVar1 == (int *)0x0);
  iVar3 = piVar5[1];
  if (iVar3 != 0) {
    puVar4 = (undefined4 *)(iVar3 + 0xc);
    if (*(uint *)(iVar3 + 4) != param_2) goto loc_F00546CC;
    if (*(uint *)(iVar3 + 0x14) == param_1) {
      uVar2 = *(undefined4 *)(iVar3 + 0x10);
loc_F00546A0:
      *param_3 = uVar2;
      *param_4 = iVar3;
    }
    else {
      for (iVar3 = *(int *)(iVar3 + 0xc); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0xc)) {
        if (*(uint *)(iVar3 + 4) == param_2) {
          if (*(uint *)(iVar3 + 0x14) == param_1) {
            *puVar4 = *(undefined4 *)(iVar3 + 0xc);
            *(int *)(iVar3 + 0xc) = piVar5[1];
            piVar5[1] = iVar3;
            uVar2 = *(undefined4 *)(iVar3 + 0x10);
            goto loc_F00546A0;
          }
          puVar4 = (undefined4 *)(iVar3 + 0xc);
        }
        else {
          puVar4 = (undefined4 *)(iVar3 + 0xc);
        }
loc_F00546CC:
      }
    }
  }
  *piVar5 = 0;
  return CONCAT44(param_2,(uint)(iVar3 != 0));
}
/* GHIDRADEC_FUNCTION index=1065 start=0xf00546f0 */

/* WARNING: Removing unreachable block (ram,0xf0054738) */

undefined8 _ipc_hash_global_insert(uint param_1,uint param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar2;
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
  *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 1;
  piVar2 = (int *)(_ipc_hash_global_table +
                  ((param_1 >> 4) + (param_2 >> 6) & _ipc_hash_global_mask) * 8);
  do {
    do {
    } while (*piVar2 != 0);
    piVar1 = piVar2;
    _simple_lock_try();
  } while (piVar1 == (int *)0x0);
  *(int *)(param_4 + 0xc) = piVar2[1];
  piVar2[1] = param_4;
  *piVar2 = 0;
  return CONCAT44(param_2 >> 6,piVar2);
}
/* GHIDRADEC_FUNCTION index=1066 start=0xf0054764 */

/* WARNING: Removing unreachable block (ram,0xf00547ac) */

undefined8 _ipc_hash_global_delete(uint param_1,uint param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar4;
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
  *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + -1;
  piVar4 = (int *)(_ipc_hash_global_table +
                  ((param_1 >> 4) + (param_2 >> 6) & _ipc_hash_global_mask) * 8);
  do {
    do {
    } while (*piVar4 != 0);
    piVar3 = piVar4;
    _simple_lock_try();
  } while (piVar3 == (int *)0x0);
  iVar2 = piVar4[1];
  piVar3 = piVar4 + 1;
  if (iVar2 != 0) {
    iVar1 = iVar2 - param_4;
    do {
      if (iVar1 == 0) {
        *piVar3 = *(int *)(iVar2 + 0xc);
        break;
      }
      piVar3 = (int *)(iVar2 + 0xc);
      iVar2 = *(int *)(iVar2 + 0xc);
      iVar1 = iVar2 - param_4;
    } while (iVar2 != 0);
  }
  *piVar4 = 0;
  return CONCAT44(param_2 >> 6,piVar4);
}
/* GHIDRADEC_FUNCTION index=1067 start=0xf0054804 */

/* WARNING: Removing unreachable block (ram,0xf0054814) */

undefined8 _ipc_hash_local_lookup(int param_1,uint param_2,uint *param_3,int *param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 unaff_l0;
  int iVar4;
  undefined4 unaff_l1;
  uint uVar5;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar6;
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
  uVar5 = *(uint *)(param_1 + 0x18);
  uVar1 = param_2 >> 6;
  iVar4 = *(int *)(param_1 + 0x14);
  .urem(uVar1,uVar5);
  iVar2 = *(int *)(iVar4 + uVar1 * 0x10 + 0xc);
  uVar6 = 0;
  if (iVar2 != 0) {
    do {
      iVar3 = iVar4 + iVar2 * 0x10;
      uVar1 = uVar1 + 1;
      if (*(uint *)(iVar3 + 4) == param_2) {
        uVar6 = 1;
        *param_3 = iVar2 << 8 | *(uint *)(iVar4 + iVar2 * 0x10) >> 0x18;
        *param_4 = iVar3;
        goto locret_F00548A0;
      }
      if (uVar1 == uVar5) {
        uVar1 = 0;
      }
      iVar2 = *(int *)(iVar4 + uVar1 * 0x10 + 0xc);
    } while (iVar2 != 0);
    uVar6 = 0;
  }
locret_F00548A0:
  return CONCAT44(param_2,uVar6);
}
/* GHIDRADEC_FUNCTION index=1068 start=0xf00548a8 */

/* WARNING: Removing unreachable block (ram,0xf00548b8) */

undefined8 _ipc_hash_local_insert(int param_1,uint param_2,undefined4 param_3)

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
  uint uVar2;
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
  param_2 = param_2 >> 6;
  uVar2 = *(uint *)(param_1 + 0x18);
  iVar1 = *(int *)(param_1 + 0x14);
  .urem(param_2,uVar2);
  while (*(int *)(iVar1 + param_2 * 0x10 + 0xc) != 0) {
    param_2 = param_2 + 1;
    if (param_2 == uVar2) {
      param_2 = 0;
    }
  }
  *(undefined4 *)(iVar1 + param_2 * 0x10 + 0xc) = param_3;
  return CONCAT44(uVar2,iVar1);
}
/* GHIDRADEC_FUNCTION index=1069 start=0xf0054900 */

/* WARNING: Removing unreachable block (ram,0xf0054984) */
/* WARNING: Removing unreachable block (ram,0xf0054910) */

undefined8 _ipc_hash_local_delete(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  undefined4 unaff_l0;
  int iVar2;
  undefined4 unaff_l1;
  uint uVar3;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar4;
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
  uVar3 = *(uint *)(param_1 + 0x18);
  param_2 = param_2 >> 6;
  iVar2 = *(int *)(param_1 + 0x14);
  .urem(param_2,uVar3);
  while (*(int *)(iVar2 + param_2 * 0x10 + 0xc) != param_3) {
    param_2 = param_2 + 1;
    if (param_2 == uVar3) {
      param_2 = 0;
    }
  }
  do {
    if (param_3 == 0) {
      return CONCAT44(param_2,param_2);
    }
    uVar4 = param_2 + 1;
    while( true ) {
      if (uVar4 == uVar3) {
        uVar4 = 0;
      }
      param_3 = *(int *)(iVar2 + uVar4 * 0x10 + 0xc);
      if (param_3 == 0) break;
      uVar1 = *(uint *)(iVar2 + param_3 * 0x10 + 4) >> 6;
      .urem(uVar1,uVar3);
      if (uVar4 < param_2) {
        if (uVar4 < uVar1) {
          if (uVar1 <= param_2) break;
          uVar4 = uVar4 + 1;
        }
        else {
          uVar4 = uVar4 + 1;
        }
      }
      else {
        if ((uVar1 < param_2) || (uVar1 <= param_2)) break;
        uVar4 = uVar4 + 1;
      }
    }
    *(int *)(iVar2 + param_2 * 0x10 + 0xc) = param_3;
    param_2 = uVar4;
  } while( true );
}
/* GHIDRADEC_FUNCTION index=1070 start=0xf00549e4 */

/* WARNING: Removing unreachable block (ram,0xf0054a6c) */

undefined8 _ipc_hash_init(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
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
  if ((_ipc_hash_global_size == 0) &&
     (_ipc_hash_global_size = _ipc_tree_entry_max >> 8, _ipc_hash_global_size < 0x20)) {
    _ipc_hash_global_size = 0x20;
  }
  _ipc_hash_global_mask = _ipc_hash_global_size - 1;
  if ((_ipc_hash_global_size & _ipc_hash_global_mask) != 0) {
    uVar3 = 1;
    for (_ipc_hash_global_mask = _ipc_hash_global_mask | 1;
        _ipc_hash_global_size = _ipc_hash_global_mask + 1,
        (_ipc_hash_global_size & _ipc_hash_global_mask) != 0;
        _ipc_hash_global_mask = _ipc_hash_global_mask | uVar3) {
      uVar3 = uVar3 << 1;
    }
  }
  iVar1 = _ipc_hash_global_size << 3;
  _kalloc();
  uVar3 = _ipc_hash_global_size;
  uVar2 = 0;
  iVar4 = iVar1;
  _ipc_hash_global_table = iVar1;
  if (_ipc_hash_global_size != 0) {
    do {
      *(undefined4 *)(iVar1 + uVar2 * 8) = 0;
      *(undefined4 *)(iVar4 + 4) = 0;
      uVar2 = uVar2 + 1;
      iVar4 = iVar4 + 8;
    } while (uVar2 < uVar3);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1071 start=0xf0054abc */

/* WARNING: Removing unreachable block (ram,0xf0054b0c) */

undefined8 _ipc_hash_info(int param_1,uint param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 unaff_l0;
  int *piVar3;
  undefined4 unaff_l1;
  int iVar4;
  uint uVar5;
  undefined4 unaff_l3;
  int iVar6;
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
  if (_ipc_hash_global_size < param_2) {
    param_2 = _ipc_hash_global_size;
  }
  uVar5 = 0;
  if (param_2 != 0) {
    iVar6 = 0;
    do {
      iVar4 = 0;
      piVar3 = (int *)(_ipc_hash_global_table + uVar5 * 8);
      do {
        do {
        } while (*piVar3 != 0);
        piVar1 = piVar3;
        _simple_lock_try();
      } while (piVar1 == (int *)0x0);
      for (iVar2 = piVar3[1]; iVar2 != 0; iVar2 = *(int *)(iVar2 + 0xc)) {
        iVar4 = iVar4 + 1;
      }
      *piVar3 = 0;
      *(int *)(iVar6 + param_1) = iVar4;
      uVar5 = uVar5 + 1;
      iVar6 = iVar6 + 4;
    } while (uVar5 < param_2);
  }
  return CONCAT44(param_2,_ipc_hash_global_size);
}
/* GHIDRADEC_FUNCTION index=1072 start=0xf0054b68 */

/* WARNING: Removing unreachable block (ram,0xf0054cc4) */
/* WARNING: Removing unreachable block (ram,0xf0054cb4) */
/* WARNING: Removing unreachable block (ram,0xf0054ca0) */
/* WARNING: Removing unreachable block (ram,0xf0054c7c) */
/* WARNING: Removing unreachable block (ram,0xf0054c30) */
/* WARNING: Removing unreachable block (ram,0xf0054be8) */
/* WARNING: Removing unreachable block (ram,0xf0054bc4) */
/* WARNING: Removing unreachable block (ram,0xf0054c04) */
/* WARNING: Removing unreachable block (ram,0xf0054c50) */
/* WARNING: Removing unreachable block (ram,0xf0054c94) */
/* WARNING: Removing unreachable block (ram,0xf0054cac) */
/* WARNING: Removing unreachable block (ram,0xf0054cbc) */
/* WARNING: Removing unreachable block (ram,0xf0054ccc) */
/* WARNING: Removing unreachable block (ram,0xf0054ba8) */

undefined8 _ipc_bootstrap(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
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
  _ipc_port_multiple_lock_data = 0;
  _ipc_port_timestamp_lock_data = 0;
  _ipc_port_timestamp_data = 0;
  uVar1 = 0x48;
  _zinit(0x48,_ipc_space_max * 0x48,0x48,0,aIpcSpaces);
  _ipc_space_zone = uVar1;
  _zchange();
  uVar1 = 0x20;
  _zinit(0x20,_ipc_tree_entry_max << 5,0x20,0,aIpcTreeEntries);
  _ipc_tree_entry_zone = uVar1;
  _zchange();
  uVar1 = 0x50;
  _zinit(0x50,_ipc_port_max * 0x50,0x50,0,aIpcPorts);
  _ipc_object_zones = uVar1;
  _zchange();
  uVar1 = 0x1c;
  _zinit(0x1c,_ipc_pset_max * 0x1c,0x1c,0,aIpcPortSets);
  DAT_f013bf04 = uVar1;
  _zchange();
  _ipc_space_create_special(&_ipc_space_kernel);
  _ipc_space_create_special(&_ipc_space_reply);
  _ipc_table_init();
  _ipc_notify_init();
  _ipc_hash_init();
  _ipc_marequest_init();
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1073 start=0xf0054cdc */

/* WARNING: Removing unreachable block (ram,0xf0054d30) */
/* WARNING: Removing unreachable block (ram,0xf0054d00) */
/* WARNING: Removing unreachable block (ram,0xf0054d3c) */
/* WARNING: Removing unreachable block (ram,0xf0054cec) */

undefined8 _ipc_init(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
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
  iVar1 = 0;
  _task_create(0,0,&_ipc_soft_task);
  if (iVar1 != 0) {
    _panic(aIpcInit);
  }
  _ipc_soft_map = *(undefined4 *)(_ipc_soft_task._0_4_ + 0xc);
  uVar2 = _kernel_map;
  _kmem_suballoc(_kernel_map,(undefined *)((int)register0x00000038 + -0xc),
                 (undefined *)((int)register0x00000038 + -0x10),_ipc_kernel_map_size,1);
  _ipc_kernel_map = uVar2;
  _ipc_host_init();
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1074 start=0xf0054d4c */

undefined8 _ipc_kmsg_enqueue(int *param_1,int *param_2)

{
  undefined4 *puVar1;
  int iVar2;
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
  iVar2 = *param_1;
  if (iVar2 == 0) {
    *param_1 = (int)param_2;
    *param_2 = (int)param_2;
    param_2[1] = (int)param_2;
  }
  else {
    puVar1 = *(undefined4 **)(iVar2 + 4);
    *param_2 = iVar2;
    param_2[1] = (int)puVar1;
    *(int **)(iVar2 + 4) = param_2;
    *puVar1 = param_2;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1075 start=0xf0054d88 */

undefined8 _ipc_kmsg_dequeue(int *param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar3;
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
  piVar3 = (int *)*param_1;
  if (piVar3 != (int *)0x0) {
    piVar2 = (int *)*piVar3;
    if (piVar2 == piVar3) {
      *param_1 = 0;
    }
    else {
      piVar1 = (int *)piVar3[1];
      *param_1 = (int)piVar2;
      piVar2[1] = (int)piVar1;
      *piVar1 = (int)piVar2;
    }
  }
  return CONCAT44(param_1,piVar3);
}
/* GHIDRADEC_FUNCTION index=1076 start=0xf0054dcc */

undefined8 _ipc_kmsg_rmqueue(int *param_1,int *param_2)

{
  int *piVar1;
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
  int *piVar2;
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
  piVar1 = (int *)*param_2;
  piVar2 = (int *)param_2[1];
  if (piVar1 == param_2) {
    *param_1 = 0;
  }
  else {
    if ((int *)*param_1 == param_2) {
      *param_1 = (int)piVar1;
    }
    piVar1[1] = (int)piVar2;
    *piVar2 = (int)piVar1;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1077 start=0xf0054e08 */

undefined8 _ipc_kmsg_queue_next(int *param_1,int *param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  int iVar1;
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
  iVar1 = *param_2;
  if (*param_1 == iVar1) {
    iVar1 = 0;
  }
  return CONCAT44(iVar1,iVar1);
}
/* GHIDRADEC_FUNCTION index=1078 start=0xf0054e28 */

/* WARNING: Removing unreachable block (ram,0xf0054ea0) */
/* WARNING: Removing unreachable block (ram,0xf0054e6c) */
/* WARNING: Removing unreachable block (ram,0xf0054e78) */
/* WARNING: Removing unreachable block (ram,0xf0054e90) */
/* WARNING: Removing unreachable block (ram,0xf0054e48) */

undefined8 _ipc_kmsg_destroy(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  int iVar2;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar3;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  iVar2 = _active_threads;
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
  piVar3 = (int *)(_active_threads + 0xa4);
  iVar1 = *(int *)(_active_threads + 0xa4);
  _ipc_kmsg_enqueue(piVar3,param_1);
  if (iVar1 == 0) {
    iVar2 = *(int *)(iVar2 + 0xa4);
    while (iVar2 != 0) {
      _ipc_kmsg_clean(iVar2);
      _ipc_kmsg_rmqueue(piVar3,iVar2);
      if (*(int *)(iVar2 + 8) < 1) {
        _ipc_kmsg_free(iVar2);
        iVar2 = *piVar3;
      }
      else {
        _kfree(iVar2);
        iVar2 = *piVar3;
      }
    }
  }
  return CONCAT44(param_2,piVar3);
}
/* GHIDRADEC_FUNCTION index=1079 start=0xf0054ec0 */

/* WARNING: Removing unreachable block (ram,0xf0054fec) */
/* WARNING: Removing unreachable block (ram,0xf0054fa4) */
/* WARNING: Removing unreachable block (ram,0xf0055004) */
/* WARNING: Removing unreachable block (ram,0xf0054f10) */

undefined8 _ipc_kmsg_clean_body(uint *param_1,uint *param_2)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  uint uVar6;
  undefined4 unaff_l0;
  int iVar7;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  uint uVar8;
  undefined4 unaff_l6;
  uint uVar9;
  undefined4 unaff_l7;
  uint *puVar10;
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
    while( true ) {
      while( true ) {
        if (param_2 <= param_1) {
          return CONCAT44(param_2,param_1);
        }
        uVar2 = *param_1;
        uVar8 = uVar2 >> 3 & 1;
        if ((uVar2 & 4) == 0) {
          uVar9 = (uint)*(byte *)param_1;
          uVar6 = uVar2 >> 0x10 & 0xff;
          uVar2 = uVar2 >> 4 & 0xfff;
          param_1 = param_1 + 1;
        }
        else {
          uVar9 = (uint)*(word *)(param_1 + 1);
          uVar6 = (uint)*(word *)((int)param_1 + 6);
          uVar2 = param_1[2];
          param_1 = param_1 + 3;
        }
        uVar3 = uVar2;
        .umul(uVar2,uVar6);
        bVar1 = uVar9 - 0x10 < 6;
        uVar6 = uVar3 + 7 >> 3;
        if (bVar1) {
          if (uVar8 == 0) {
            puVar10 = (uint *)*param_1;
          }
          else {
            for (puVar4 = param_1 + uVar2; puVar10 = param_1, param_2 < puVar4; puVar4 = puVar4 + -1
                ) {
              uVar2 = uVar2 - 1;
            }
          }
          uVar3 = 0;
          if (uVar2 != 0) {
            iVar7 = 0;
            do {
              iVar5 = *(int *)(iVar7 + (int)puVar10);
              if ((iVar5 != 0) && (iVar5 != -1)) {
                _ipc_object_destroy(iVar5,uVar9);
              }
              uVar3 = uVar3 + 1;
              iVar7 = iVar7 + 4;
            } while (uVar3 < uVar2);
          }
        }
        if (uVar8 == 0) break;
        param_1 = (uint *)((int)param_1 + (uVar6 + 3 & 0xfffffffc));
      }
      if (uVar6 != 0) break;
loc_F005500C:
      param_1 = param_1 + 1;
    }
    if (!bVar1) {
      _vm_deallocate(_ipc_soft_map,*param_1,uVar6);
      goto loc_F005500C;
    }
    _kfree(*param_1,uVar6);
    param_1 = param_1 + 1;
  } while( true );
}
/* GHIDRADEC_FUNCTION index=1080 start=0xf005501c */

/* WARNING: Removing unreachable block (ram,0xf005507c) */
/* WARNING: Removing unreachable block (ram,0xf0055050) */
/* WARNING: Removing unreachable block (ram,0xf0055098) */
/* WARNING: Removing unreachable block (ram,0xf0055030) */

undefined8 _ipc_kmsg_clean(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  uint uVar2;
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
  uVar2 = *(uint *)(param_1 + 0x14);
  if (*(int *)(param_1 + 0xc) != 0) {
    _ipc_marequest_destroy();
  }
  iVar1 = *(int *)(param_1 + 0x1c);
  if (iVar1 != 0) {
    if (iVar1 == -1) {
      iVar1 = *(int *)(param_1 + 0x20);
      goto loc_F005505C;
    }
    _ipc_object_destroy(iVar1,uVar2 & 0xff);
  }
  iVar1 = *(int *)(param_1 + 0x20);
loc_F005505C:
  if ((iVar1 != 0) && (iVar1 != -1)) {
    _ipc_object_destroy(iVar1,(uVar2 & 0xff00) >> 8);
  }
  if ((int)uVar2 < 0) {
    _ipc_kmsg_clean_body(param_1 + 0x2c,param_1 + *(int *)(param_1 + 0x18) + 0x14);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1081 start=0xf00550a8 */

/* WARNING: Removing unreachable block (ram,0xf00551f0) */
/* WARNING: Removing unreachable block (ram,0xf005513c) */
/* WARNING: Removing unreachable block (ram,0xf00550dc) */
/* WARNING: Removing unreachable block (ram,0xf00550e8) */
/* WARNING: Removing unreachable block (ram,0xf00551a4) */
/* WARNING: Removing unreachable block (ram,0xf00551dc) */
/* WARNING: Removing unreachable block (ram,0xf00550b4) */

undefined8 _ipc_kmsg_clean_partial(uint param_1,uint *param_2,int param_3,uint param_4)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 unaff_l0;
  uint uVar5;
  uint *puVar6;
  undefined4 unaff_l1;
  uint uVar7;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  uint uVar8;
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
  uVar5 = *(uint *)(param_1 + 0x14);
  _ipc_object_destroy(*(undefined4 *)(param_1 + 0x1c),uVar5 & 0xff);
  iVar2 = *(int *)(param_1 + 0x20);
  if ((iVar2 != 0) && (iVar2 != -1)) {
    _ipc_object_destroy(iVar2,(uVar5 & 0xff00) >> 8);
  }
  _ipc_kmsg_clean_body(param_1 + 0x2c,param_2);
  if (param_3 != 0) {
    uVar5 = *param_2;
    uVar8 = uVar5 >> 3 & 1;
    if ((uVar5 & 4) == 0) {
      uVar7 = (uint)*(byte *)param_2;
      uVar4 = uVar5 >> 0x10 & 0xff;
      uVar5 = uVar5 >> 4 & 0xfff;
      param_2 = param_2 + 1;
    }
    else {
      uVar7 = (uint)*(word *)(param_2 + 1);
      uVar4 = (uint)*(word *)((int)param_2 + 6);
      uVar5 = param_2[2];
      param_2 = param_2 + 3;
    }
    .umul(uVar5,uVar4);
    bVar1 = 5 < uVar7 - 0x10;
    uVar5 = uVar5 + 7 >> 3;
    if (!bVar1) {
      puVar6 = param_2;
      if (uVar8 == 0) {
        puVar6 = (uint *)*param_2;
      }
      param_1 = 0;
      if (param_4 != 0) {
        iVar2 = 0;
        do {
          iVar3 = *(int *)(iVar2 + (int)puVar6);
          if ((iVar3 != 0) && (iVar3 != -1)) {
            _ipc_object_destroy(iVar3,uVar7);
          }
          param_1 = param_1 + 1;
          iVar2 = iVar2 + 4;
        } while (param_1 < param_4);
      }
    }
    if ((uVar8 == 0) && (uVar5 != 0)) {
      if (bVar1) {
        _vm_deallocate(_ipc_soft_map,*param_2,uVar5);
      }
      else {
        _kfree(*param_2,uVar5);
      }
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1082 start=0xf0055200 */

/* WARNING: Removing unreachable block (ram,0xf005523c) */

undefined8 _ipc_kmsg_free(int param_1,undefined4 param_2)

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
  iVar1 = *(int *)(param_1 + 8);
  if (iVar1 != -2) {
    if (iVar1 != -1) {
      if (iVar1 == -3) {
        _netipc_msg_release();
        return CONCAT44(iVar1,param_1);
      }
      _kfree();
    }
    return CONCAT44(param_2,param_1);
  }
  _KernDeviceInterruptMsgRelease();
  return CONCAT44(iVar1,param_1);
}
/* GHIDRADEC_FUNCTION index=1083 start=0xf005524c */

/* WARNING: Removing unreachable block (ram,0xf00552dc) */
/* WARNING: Removing unreachable block (ram,0xf005529c) */
/* WARNING: Removing unreachable block (ram,0xf00552fc) */
/* WARNING: Removing unreachable block (ram,0xf0055320) */
/* WARNING: Removing unreachable block (ram,0xf00552bc) */

undefined8 _ipc_kmsg_get(int param_1,uint param_2,int param_3,int *param_4)

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
  undefined4 uVar2;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  iVar1 = _ipc_kmsg_cache;
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
  if (((param_2 < 0x18) || ((param_2 & 3) != 0)) || (0 < param_3)) {
    uVar2 = 0x10000008;
    goto locret_F0055340;
  }
  if (param_2 < 0xed) {
    if (_ipc_kmsg_cache == 0) {
      iVar1 = 0x100;
      _kalloc();
      if (iVar1 == 0) goto loc_F00552D0;
      *(undefined4 *)(iVar1 + 8) = 0x100;
      goto loc_F00552EC;
    }
    _ipc_kmsg_cache = 0;
  }
  else {
    iVar1 = param_2 + 0x14;
    _kalloc();
    if (iVar1 == 0) {
loc_F00552D0:
      uVar2 = 0x1000000d;
      goto locret_F0055340;
    }
    *(uint *)(iVar1 + 8) = param_2 + 0x14;
loc_F00552EC:
    *(undefined4 *)(iVar1 + 0xc) = 0;
  }
  *(undefined4 *)(iVar1 + 0x10) = 0;
  _copyinmsg(param_1,iVar1 + 0x14,param_2 + param_3);
  if (param_1 == 0) {
    *(int *)(iVar1 + 0x10) = param_3;
    *(uint *)(iVar1 + 0x18) = param_2;
    *param_4 = iVar1;
    uVar2 = 0;
  }
  else {
    if (*(int *)(iVar1 + 8) < 1) {
      _ipc_kmsg_free(iVar1);
    }
    else {
      _kfree(iVar1);
    }
    uVar2 = 0x10000002;
  }
locret_F0055340:
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=1084 start=0xf0055348 */

/* WARNING: Removing unreachable block (ram,0xf0055374) */
/* WARNING: Removing unreachable block (ram,0xf0055350) */

undefined8 _ipc_kmsg_get_from_kernel(undefined4 param_1,int param_2,int param_3,int *param_4)

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
  undefined4 uVar2;
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
  iVar1 = param_2 + 0x14;
  _kalloc();
  if (iVar1 == 0) {
    uVar2 = 0x1000000d;
  }
  else {
    *(int *)(iVar1 + 8) = param_2 + 0x14;
    *(undefined4 *)(iVar1 + 0xc) = 0;
    *(undefined4 *)(iVar1 + 0x10) = 0;
    _bcopy(param_1,iVar1 + 0x14,param_2 + param_3);
    *(int *)(iVar1 + 0x10) = param_3;
    *(int *)(iVar1 + 0x18) = param_2;
    *param_4 = iVar1;
    uVar2 = 0;
  }
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=1085 start=0xf00553a0 */

/* WARNING: Removing unreachable block (ram,0xf00553fc) */
/* WARNING: Removing unreachable block (ram,0xf0055414) */
/* WARNING: Removing unreachable block (ram,0xf00553b0) */

undefined8 _ipc_kmsg_put(undefined4 param_1,int param_2,undefined4 param_3)

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
  undefined4 uVar2;
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
  *(undefined4 *)(param_2 + 0x10) = 0;
  iVar1 = param_2 + 0x14;
  _copyoutmsg(iVar1,param_1,param_3);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0x10004008;
  }
  if (*(int *)(param_2 + 8) == 0x100) {
    iVar1 = param_2;
    if (_ipc_kmsg_cache == 0) goto locret_F005541C;
    iVar1 = *(int *)(param_2 + 8);
  }
  else {
    iVar1 = *(int *)(param_2 + 8);
  }
  if (iVar1 < 1) {
    _ipc_kmsg_free(param_2);
    iVar1 = _ipc_kmsg_cache;
  }
  else {
    _kfree(param_2);
    iVar1 = _ipc_kmsg_cache;
  }
locret_F005541C:
  _ipc_kmsg_cache = iVar1;
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=1086 start=0xf0055424 */

/* WARNING: Removing unreachable block (ram,0xf0055454) */
/* WARNING: Removing unreachable block (ram,0xf0055448) */
/* WARNING: Removing unreachable block (ram,0xf0055430) */

undefined8 _ipc_kmsg_put_to_kernel(undefined4 param_1,int param_2,undefined4 param_3)

{
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
  _bcopy(param_2 + 0x14,param_1,param_3);
  if (*(int *)(param_2 + 8) < 1) {
    _ipc_kmsg_free(param_2);
  }
  else {
    _kfree(param_2);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1087 start=0xf0055464 */

/* WARNING: Removing unreachable block (ram,0xf0055d1c) */
/* WARNING: Removing unreachable block (ram,0xf0055ce4) */
/* WARNING: Removing unreachable block (ram,0xf0055de8) */
/* WARNING: Removing unreachable block (ram,0xf0055dc8) */
/* WARNING: Removing unreachable block (ram,0xf0055d88) */
/* WARNING: Removing unreachable block (ram,0xf0055d50) */
/* WARNING: Removing unreachable block (ram,0xf0055c68) */
/* WARNING: Removing unreachable block (ram,0xf0055bf8) */
/* WARNING: Removing unreachable block (ram,0xf0055ba8) */
/* WARNING: Removing unreachable block (ram,0xf0055b78) */
/* WARNING: Removing unreachable block (ram,0xf0055b38) */
/* WARNING: Removing unreachable block (ram,0xf00559ac) */
/* WARNING: Removing unreachable block (ram,0xf0055a00) */
/* WARNING: Removing unreachable block (ram,0xf0055ac4) */
/* WARNING: Removing unreachable block (ram,0xf0055a94) */
/* WARNING: Removing unreachable block (ram,0xf0055a38) */
/* WARNING: Removing unreachable block (ram,0xf0055908) */
/* WARNING: Removing unreachable block (ram,0xf0055898) */
/* WARNING: Removing unreachable block (ram,0xf00554f4) */
/* WARNING: Removing unreachable block (ram,0xf0055748) */
/* WARNING: Removing unreachable block (ram,0xf0055688) */
/* WARNING: Removing unreachable block (ram,0xf00556ac) */
/* WARNING: Removing unreachable block (ram,0xf00557c8) */
/* WARNING: Removing unreachable block (ram,0xf0055564) */
/* WARNING: Removing unreachable block (ram,0xf00558c4) */
/* WARNING: Removing unreachable block (ram,0xf0055928) */
/* WARNING: Removing unreachable block (ram,0xf0055a64) */
/* WARNING: Removing unreachable block (ram,0xf0055abc) */
/* WARNING: Removing unreachable block (ram,0xf00559ec) */
/* WARNING: Removing unreachable block (ram,0xf0055980) */
/* WARNING: Removing unreachable block (ram,0xf0055b0c) */
/* WARNING: Removing unreachable block (ram,0xf0055b64) */
/* WARNING: Removing unreachable block (ram,0xf0055b8c) */
/* WARNING: Removing unreachable block (ram,0xf0055bd4) */
/* WARNING: Removing unreachable block (ram,0xf0055c1c) */
/* WARNING: Removing unreachable block (ram,0xf0055c94) */
/* WARNING: Removing unreachable block (ram,0xf0055d74) */
/* WARNING: Removing unreachable block (ram,0xf0055da8) */
/* WARNING: Removing unreachable block (ram,0xf0055de0) */
/* WARNING: Removing unreachable block (ram,0xf0055df4) */
/* WARNING: Removing unreachable block (ram,0xf0055d00) */
/* WARNING: Removing unreachable block (ram,0xf0055d24) */
/* WARNING: Removing unreachable block (ram,0xf00555dc) */

undefined8 _ipc_kmsg_copyin_header(uint *param_1,uint *param_2,int param_3)

{
  undefined4 *puVar1;
  uint *puVar2;
  uint *puVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  undefined4 unaff_l0;
  undefined4 *puVar9;
  int *piVar10;
  undefined4 unaff_l1;
  uint *puVar11;
  uint uVar12;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  uint uVar13;
  undefined4 unaff_l5;
  uint uVar14;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar15;
  undefined4 uVar16;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  uint uVar17;
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
  uVar6 = *param_1;
  uVar14 = param_1[2];
  uVar13 = param_1[3];
  if (param_3 == 0) {
    uVar7 = uVar6 & 0xffff;
    if (uVar7 == 0x13) {
      if (uVar13 == 0) {
        do {
          do {
          } while (param_2[2] != 0);
          puVar11 = param_2 + 2;
          _simple_lock_try();
        } while (puVar11 == (uint *)0x0);
        if (((param_2[3] == 0) || (param_2[6] <= uVar14 >> 8)) ||
           (iVar8 = (uVar14 >> 8) * 0x10,
           (*(uint *)(param_2[5] + iVar8) & 0xff010000) != (uVar14 << 0x18 | 0x10000)))
        goto loc_F0055828;
        piVar15 = *(int **)(param_2[5] + iVar8 + 4);
        do {
          do {
          } while (*piVar15 != 0);
          piVar10 = piVar15;
          _simple_lock_try();
        } while (piVar10 == (int *)0x0);
        param_2[2] = 0;
        if (piVar15[2] < 0) {
          piVar15[7] = piVar15[7] + 1;
          piVar15[1] = piVar15[1] + 1;
          *piVar15 = 0;
          *param_1 = uVar6 & 0xbfff0000 | 0x11;
          param_1[2] = (uint)piVar15;
          uVar16 = 0;
          goto locret_F0055E48;
        }
        *piVar15 = 0;
      }
    }
    else if (uVar7 < 0x14) {
      if ((uVar7 == 0x12) && (uVar13 == 0)) {
        do {
          do {
          } while (param_2[2] != 0);
          puVar11 = param_2 + 2;
          _simple_lock_try();
        } while (puVar11 == (uint *)0x0);
        uVar7 = uVar14 >> 8;
        if (param_2[3] != 0) {
          uVar12 = param_2[5];
          if (((uVar7 < param_2[6]) &&
              (puVar11 = (uint *)(uVar12 + uVar7 * 0x10),
              (*(uint *)(uVar12 + uVar7 * 0x10) & 0xff840000) == (uVar14 << 0x18 | 0x40000))) &&
             (puVar11[2] == 0)) {
            piVar15 = (int *)puVar11[1];
            do {
              do {
              } while (*piVar15 != 0);
              piVar10 = piVar15;
              _simple_lock_try();
            } while (piVar10 == (int *)0x0);
            if (piVar15[2] < 0) {
              *piVar15 = 0;
              uVar16 = 0;
              puVar11[2] = *(uint *)(uVar12 + 8);
              *(uint *)(uVar12 + 8) = uVar7;
              *puVar11 = uVar14 << 0x18;
              puVar11[1] = 0;
              param_2[2] = 0;
              *param_1 = uVar6 & 0xbfff0000 | 0x12;
              param_1[2] = (uint)piVar15;
              goto locret_F0055E48;
            }
            *piVar15 = 0;
          }
        }
loc_F0055828:
        param_2[2] = 0;
      }
    }
    else if (uVar7 == 0x1513) {
      do {
        do {
        } while (param_2[2] != 0);
        puVar11 = param_2 + 2;
        _simple_lock_try();
      } while (puVar11 == (uint *)0x0);
      if (param_2[3] != 0) {
        uVar7 = param_2[5];
        if (uVar14 >> 8 < param_2[6]) {
          iVar8 = (uVar14 >> 8) * 0x10;
          if ((*(uint *)(uVar7 + iVar8) & 0xff010000) == (uVar14 << 0x18 | 0x10000)) {
            piVar15 = *(int **)(uVar7 + iVar8 + 4);
            if ((uVar13 >> 8 < param_2[6]) &&
               (iVar8 = (uVar13 >> 8) * 0x10,
               (*(uint *)(uVar7 + iVar8) & 0xff020000) == (uVar13 << 0x18 | 0x20000))) {
              puVar9 = *(undefined4 **)(uVar7 + iVar8 + 4);
              do {
                do {
                } while (*piVar15 != 0);
                piVar10 = piVar15;
                _simple_lock_try();
              } while (piVar10 == (int *)0x0);
              if ((piVar15[2] < 0) &&
                 (puVar1 = puVar9, _simple_lock_try(), puVar1 != (undefined4 *)0x0)) {
                param_2[2] = 0;
                piVar15[7] = piVar15[7] + 1;
                piVar15[1] = piVar15[1] + 1;
                *piVar15 = 0;
                puVar9[8] = puVar9[8] + 1;
                puVar9[1] = puVar9[1] + 1;
                *puVar9 = 0;
                *param_1 = uVar6 & 0xbfff0000 | 0x1211;
                param_1[2] = (uint)piVar15;
                param_1[3] = (uint)puVar9;
                uVar16 = 0;
                goto locret_F0055E48;
              }
              *piVar15 = 0;
            }
          }
        }
      }
      goto loc_F0055828;
    }
  }
  uVar7 = uVar6 & 0xff;
  uVar17 = 0;
  uVar12 = (uVar6 & 0xff00) >> 8;
  if (4 < uVar7 - 0x11) {
loc_F0055880:
    uVar16 = 0x10000010;
    goto locret_F0055E48;
  }
  if (uVar12 == 0) {
    if (uVar13 != 0) goto loc_F0055880;
  }
  else if (4 < uVar12 - 0x11) goto loc_F0055880;
  do {
    do {
      puVar11 = param_2 + 2;
    } while (*puVar11 != 0);
    _simple_lock_try();
  } while (puVar11 == (uint *)0x0);
  if (param_2[3] == 0) goto loc_F0055E2C;
  if (param_3 != 0) {
    puVar11 = param_2;
    _ipc_entry_lookup(param_2,param_3);
    if ((puVar11 == (uint *)0x0) || ((*puVar11 & 0x20000) == 0)) {
      param_2[2] = 0;
      uVar16 = 0x1000000b;
      goto locret_F0055E48;
    }
    uVar17 = puVar11[1];
  }
  if (uVar14 != uVar13) {
    if ((uVar13 == 0) || (uVar13 == 0xffffffff)) {
      puVar11 = param_2;
      _ipc_entry_lookup(param_2,uVar14);
      if ((puVar11 != (uint *)0x0) &&
         (puVar2 = param_2,
         _ipc_right_copyin(param_2,uVar14,puVar11,uVar7,0,
                           (undefined *)((int)register0x00000038 + -0xc),
                           (undefined *)((int)register0x00000038 + -0x10)), puVar2 == (uint *)0x0))
      {
        if ((*puVar11 & 0x1f0000) == 0) {
          _ipc_entry_dealloc(param_2,uVar14,puVar11);
          *(uint *)((int)register0x00000038 + -0x14) = uVar13;
        }
        else {
          *(uint *)((int)register0x00000038 + -0x14) = uVar13;
        }
        *(undefined4 *)((int)register0x00000038 + -0x18) = 0;
        goto loc_F0055D94;
      }
loc_F0055E2C:
      param_2[2] = 0;
    }
    else {
      puVar11 = param_2;
      _ipc_entry_lookup(param_2,uVar14);
      if (puVar11 == (uint *)0x0) goto loc_F0055E2C;
      puVar2 = param_2;
      _ipc_entry_lookup(param_2,uVar13);
      if (puVar2 == (uint *)0x0) {
loc_F0055E3C:
        param_2[2] = 0;
        uVar16 = 0x10000009;
        goto locret_F0055E48;
      }
      puVar3 = param_2;
      _ipc_right_copyin_check(param_2,uVar13,puVar2,uVar12);
      if (puVar3 == (uint *)0x0) goto loc_F0055E3C;
      puVar3 = param_2;
      _ipc_right_copyin(param_2,uVar14,puVar11,uVar7,0,(undefined *)((int)register0x00000038 + -0xc)
                        ,(undefined *)((int)register0x00000038 + -0x10));
      if (puVar3 != (uint *)0x0) goto loc_F0055E2C;
      piVar15 = (int *)puVar2[1];
      if (piVar15 != (int *)0x0) {
        _ipc_object_reference(piVar15);
      }
      puVar3 = param_2;
      _ipc_right_copyin(param_2,uVar13,puVar2,uVar12,1,
                        (undefined *)((int)register0x00000038 + -0x14),
                        (undefined *)((int)register0x00000038 + -0x18));
      if (puVar3 != (uint *)0x0) {
        *(undefined4 *)((int)register0x00000038 + -0x14) = 0xffffffff;
        *(undefined4 *)((int)register0x00000038 + -0x18) = 0;
loc_F0055D58:
        uVar5 = *puVar11;
loc_F0055D60:
        if ((uVar5 & 0x1f0000) == 0) {
          _ipc_entry_dealloc(param_2,uVar14,puVar11);
        }
        if (piVar15 != (int *)0x0) {
          _ipc_object_release(piVar15);
        }
        goto loc_F0055D94;
      }
      if (piVar15 == (int *)0x0) {
loc_F0055D34:
        uVar5 = *puVar2;
loc_F0055D38:
        if ((uVar5 & 0x1f0000) == 0) {
          _ipc_entry_dealloc(param_2,uVar13,puVar2);
          goto loc_F0055D58;
        }
        uVar5 = *puVar11;
        goto loc_F0055D60;
      }
      if (*(int *)((int)register0x00000038 + -0x14) != -1) {
        uVar5 = *puVar2;
        goto loc_F0055D38;
      }
      piVar10 = *(int **)((int)register0x00000038 + -0xc);
      do {
        do {
        } while (*piVar15 != 0);
        piVar4 = piVar15;
        _simple_lock_try();
      } while (piVar4 == (int *)0x0);
      iVar8 = piVar15[3];
      *piVar15 = 0;
      do {
        do {
        } while (*piVar10 != 0);
        piVar4 = piVar10;
        _simple_lock_try();
      } while (piVar4 == (int *)0x0);
      uVar5 = 0;
      if (-1 < piVar10[2]) {
        uVar5 = (uint)(piVar10[3] - iVar8) >> 0x1f;
      }
      *piVar10 = 0;
      if (uVar5 == 0) goto loc_F0055D34;
      _ipc_right_copyin_undo
                (param_2,uVar14,puVar11,uVar7,*(undefined4 *)((int)register0x00000038 + -0xc),
                 *(undefined4 *)((int)register0x00000038 + -0x10));
      _ipc_right_copyin_undo
                (param_2,uVar13,puVar2,uVar12,*(undefined4 *)((int)register0x00000038 + -0x14),
                 *(undefined4 *)((int)register0x00000038 + -0x18));
      iVar8 = *(int *)((int)register0x00000038 + -0x10);
      param_2[2] = 0;
      if (iVar8 != 0) {
        _ipc_notify_dead_name(iVar8,uVar14);
      }
      _ipc_object_release(piVar15);
    }
    uVar16 = 0x10000003;
    goto locret_F0055E48;
  }
  puVar11 = param_2;
  _ipc_entry_lookup(param_2,uVar13);
  if (puVar11 == (uint *)0x0) goto loc_F0055E2C;
  puVar2 = param_2;
  _ipc_right_copyin_check(param_2,uVar13,puVar11,uVar12);
  if (puVar2 == (uint *)0x0) goto loc_F0055E3C;
  if ((uVar7 == 0x12) || (uVar12 == 0x12)) goto loc_F0055E2C;
  if ((uVar7 - 0x14 < 2) || (uVar12 - 0x14 < 2)) {
    puVar2 = param_2;
    _ipc_right_copyin(param_2,uVar13,puVar11,uVar7,0,(undefined *)((int)register0x00000038 + -0xc),
                      (undefined *)((int)register0x00000038 + -0x10));
    if (puVar2 != (uint *)0x0) goto loc_F0055E2C;
    _ipc_right_copyin(param_2,uVar13,puVar11,uVar12,1,(undefined *)((int)register0x00000038 + -0x14)
                      ,(undefined *)((int)register0x00000038 + -0x18));
  }
  else if ((uVar7 == 0x13) && (uVar12 == 0x13)) {
    puVar2 = param_2;
    _ipc_right_copyin(param_2,uVar13,puVar11,0x13,0,(undefined *)((int)register0x00000038 + -0xc),
                      (undefined *)((int)register0x00000038 + -0x10));
    if (puVar2 != (uint *)0x0) goto loc_F0055E2C;
    uVar16 = *(undefined4 *)((int)register0x00000038 + -0xc);
    _ipc_port_copy_send();
    *(undefined4 *)((int)register0x00000038 + -0x14) = uVar16;
    *(undefined4 *)((int)register0x00000038 + -0x18) = 0;
  }
  else if ((uVar7 == 0x11) && (uVar12 == 0x11)) {
    puVar2 = param_2;
    _ipc_right_copyin_two
              (param_2,uVar13,puVar11,(undefined *)((int)register0x00000038 + -0xc),
               (undefined *)((int)register0x00000038 + -0x10));
    if (puVar2 != (uint *)0x0) goto loc_F0055E2C;
    uVar16 = *(undefined4 *)((int)register0x00000038 + -0xc);
    if ((*puVar11 & 0x1f0000) == 0) {
      _ipc_entry_dealloc(param_2,uVar13,puVar11);
      uVar16 = *(undefined4 *)((int)register0x00000038 + -0xc);
    }
    *(undefined4 *)((int)register0x00000038 + -0x18) = 0;
    *(undefined4 *)((int)register0x00000038 + -0x14) = uVar16;
  }
  else {
    puVar2 = param_2;
    _ipc_right_copyin(param_2,uVar13,puVar11,0x11,0,(undefined *)((int)register0x00000038 + -0xc),
                      (undefined *)((int)register0x00000038 + -0x1c));
    if (puVar2 != (uint *)0x0) goto loc_F0055E2C;
    if ((*puVar11 & 0x1f0000) == 0) {
      _ipc_entry_dealloc(param_2,uVar13,puVar11);
    }
    uVar16 = *(undefined4 *)((int)register0x00000038 + -0xc);
    _ipc_port_copy_send();
    *(undefined4 *)((int)register0x00000038 + -0x14) = uVar16;
    if (uVar7 == 0x11) {
      *(undefined4 *)((int)register0x00000038 + -0x18) = 0;
      *(undefined4 *)((int)register0x00000038 + -0x10) =
           *(undefined4 *)((int)register0x00000038 + -0x1c);
    }
    else {
      *(undefined4 *)((int)register0x00000038 + -0x10) = 0;
      *(undefined4 *)((int)register0x00000038 + -0x18) =
           *(undefined4 *)((int)register0x00000038 + -0x1c);
    }
  }
loc_F0055D94:
  uVar5 = *(uint *)((int)register0x00000038 + -0x10);
  if (param_3 == 0) {
loc_F0055DB4:
    uVar5 = *(uint *)((int)register0x00000038 + -0x10);
  }
  else if (uVar5 == uVar17) {
    _ipc_port_release_sonce();
    *(undefined4 *)((int)register0x00000038 + -0x10) = 0;
    goto loc_F0055DB4;
  }
  param_2[2] = 0;
  if (uVar5 == 0) {
    iVar8 = *(int *)((int)register0x00000038 + -0x18);
  }
  else {
    _ipc_notify_port_deleted(uVar5,uVar14);
    iVar8 = *(int *)((int)register0x00000038 + -0x18);
  }
  if (iVar8 != 0) {
    _ipc_notify_port_deleted(iVar8,uVar13);
  }
  _ipc_object_copyin_type();
  _ipc_object_copyin_type();
  *param_1 = uVar6 & 0xbfff0000 | uVar7 | uVar12 << 8;
  uVar16 = 0;
  uVar6 = *(uint *)((int)register0x00000038 + -0x14);
  param_1[2] = *(uint *)((int)register0x00000038 + -0xc);
  param_1[3] = uVar6;
locret_F0055E48:
  return CONCAT44(param_2,uVar16);
}
/* GHIDRADEC_FUNCTION index=1088 start=0xf0055e50 */

/* WARNING: Removing unreachable block (ram,0xf0055eb8) */
/* WARNING: Removing unreachable block (ram,0xf005612c) */
/* WARNING: Removing unreachable block (ram,0xf0056100) */
/* WARNING: Removing unreachable block (ram,0xf00560bc) */
/* WARNING: Removing unreachable block (ram,0xf0056084) */
/* WARNING: Removing unreachable block (ram,0xf0056004) */
/* WARNING: Removing unreachable block (ram,0xf0055ff0) */
/* WARNING: Removing unreachable block (ram,0xf0056068) */
/* WARNING: Removing unreachable block (ram,0xf00560a8) */
/* WARNING: Removing unreachable block (ram,0xf00560e0) */
/* WARNING: Removing unreachable block (ram,0xf0055f28) */
/* WARNING: Removing unreachable block (ram,0xf005617c) */
/* WARNING: Removing unreachable block (ram,0xf0056198) */
/* WARNING: Removing unreachable block (ram,0xf0055e64) */

undefined8 _ipc_kmsg_copyin(int param_1,uint param_2,int param_3,undefined4 param_4)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 unaff_l0;
  uint uVar5;
  uint *puVar6;
  undefined4 unaff_l1;
  uint *puVar7;
  uint *puVar8;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  uint uVar9;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  uint *puVar10;
  undefined4 unaff_i3;
  uint *puVar11;
  uint uVar12;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar13;
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
  *(uint *)((int)register0x00000038 + -0x14) = param_2;
  iVar2 = param_1 + 0x14;
  _ipc_kmsg_copyin_header(iVar2,*(undefined4 *)((int)register0x00000038 + -0x14),param_4);
  if (iVar2 == 0) {
    bVar13 = false;
    if (*(int *)(param_1 + 0x14) < 0) {
      *(undefined4 *)((int)register0x00000038 + -0x1c) = *(undefined4 *)(param_1 + 0x1c);
      puVar10 = (uint *)(param_1 + *(int *)(param_1 + 0x18) + 0x14);
      puVar6 = (uint *)(param_1 + 0x2c);
      while (puVar7 = puVar6, puVar7 < puVar10) {
        if ((uint)((int)puVar10 - (int)puVar7) < 4) goto loc_F0055F24;
        uVar12 = *puVar7 >> 2 & 1;
        if (uVar12 == 0) {
          uVar3 = *puVar7;
        }
        else {
          if ((uint)((int)puVar10 - (int)puVar7) < 0xc) goto loc_F0055F24;
          uVar3 = *puVar7;
        }
        uVar5 = uVar3 >> 3 & 1;
        uVar9 = uVar3 >> 1 & 1;
        if (uVar12 == 0) {
          param_2 = (uint)*(byte *)puVar7;
          uVar4 = uVar3 >> 0x10 & 0xff;
          uVar3 = uVar3 >> 4 & 0xfff;
          puVar8 = puVar7 + 1;
        }
        else {
          param_2 = (uint)*(word *)(puVar7 + 1);
          uVar4 = (uint)*(word *)((int)puVar7 + 6);
          uVar3 = puVar7[2];
          puVar8 = puVar7 + 3;
        }
        bVar1 = param_2 - 0x10 < 6;
        if ((bVar1) && (uVar4 != 0x20)) {
loc_F0055FE8:
          _ipc_kmsg_clean_partial(param_1,puVar7,0,0);
          iVar2 = 0x1000000f;
          goto locret_F00561FC;
        }
        uVar4 = *puVar7;
        if (uVar12 != 0) {
          if ((uVar4 & 0xfffffff0) != 0) goto loc_F0055FE8;
          uVar4 = *puVar7;
        }
        if (((uVar4 & 1) != 0) || ((uVar9 != 0 && (uVar5 != 0)))) goto loc_F0055FE8;
        uVar4 = uVar3;
        .umul();
        puVar6 = (uint *)(uVar4 + 7 >> 3);
        if (uVar5 == 0) {
          if ((uint)((int)puVar10 - (int)puVar8) < 4) goto loc_F0055F24;
          uVar5 = *puVar8;
          if (puVar6 != (uint *)0x0) {
            if (bVar1) {
              puVar11 = puVar6;
              _kalloc();
              if (puVar11 != (uint *)0x0) {
                iVar2 = param_3;
                _copyinmap(param_3,uVar5,puVar11,puVar6);
                if ((iVar2 == 0) &&
                   ((uVar9 == 0 ||
                    (iVar2 = param_3, _vm_deallocate(param_3,uVar5,puVar6), iVar2 == 0))))
                goto loc_F0056114;
                _kfree(puVar11,puVar6);
              }
            }
            else {
              iVar2 = param_3;
              _vm_move(param_3,uVar5,_ipc_soft_map,puVar6,uVar9,
                       (undefined *)((int)register0x00000038 + -0xc));
              puVar11 = *(uint **)((int)register0x00000038 + -0xc);
              if (iVar2 == 0) goto loc_F0056114;
            }
            _ipc_kmsg_clean_partial(param_1,puVar7,0,0);
            iVar2 = 0x1000000c;
            goto locret_F00561FC;
          }
          puVar11 = (uint *)0x0;
loc_F0056114:
          *puVar8 = (uint)puVar11;
          puVar6 = puVar8 + 1;
          bVar13 = true;
        }
        else {
          uVar5 = (uint)((int)puVar6 + 3) & 0xfffffffc;
          if ((uint)((int)puVar10 - (int)puVar8) < uVar5) {
loc_F0055F24:
            _ipc_kmsg_clean_partial(param_1,puVar7,0,0);
            iVar2 = 0x10000008;
            goto locret_F00561FC;
          }
          puVar6 = (uint *)((int)puVar8 + uVar5);
          puVar11 = puVar8;
        }
        if (bVar1) {
          uVar5 = param_2;
          _ipc_object_copyin_type();
          if (uVar12 == 0) {
            *(byte *)puVar7 = (byte)uVar5;
          }
          else {
            *(sword *)(puVar7 + 1) = (sword)uVar5;
          }
          uVar12 = 0;
          if (uVar3 != 0) {
            do {
              uVar9 = *puVar11;
              if ((uVar9 != 0) &&
                 (iVar2 = *(int *)((int)register0x00000038 + -0x14), uVar9 != 0xffffffff)) {
                _ipc_object_copyin(iVar2,uVar9,param_2,
                                   (undefined *)((int)register0x00000038 + -0x10));
                if (iVar2 != 0) {
                  _ipc_kmsg_clean_partial(param_1,puVar7,1,uVar12);
                  iVar2 = 0x1000000a;
                  goto locret_F00561FC;
                }
                uVar9 = *(uint *)((int)register0x00000038 + -0x10);
                if (uVar5 == 0x10) {
                  _ipc_port_check_circularity
                            (uVar9,*(undefined4 *)((int)register0x00000038 + -0x1c));
                  bVar13 = uVar9 != 0;
                  uVar9 = *(uint *)((int)register0x00000038 + -0x10);
                  if (bVar13) {
                    *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | 0x40000000;
                    uVar9 = *(uint *)((int)register0x00000038 + -0x10);
                  }
                }
                *puVar11 = uVar9;
              }
              uVar12 = uVar12 + 1;
              puVar11 = puVar11 + 1;
            } while (uVar12 < uVar3);
          }
          bVar13 = true;
        }
      }
      if (bVar13) {
        iVar2 = 0;
      }
      else {
        *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) & 0x7fffffff;
        iVar2 = 0;
      }
    }
    else {
      iVar2 = 0;
    }
  }
locret_F00561FC:
  return CONCAT44(param_2,iVar2);
}
/* GHIDRADEC_FUNCTION index=1089 start=0xf0056204 */

/* WARNING: Removing unreachable block (ram,0xf00563b8) */
/* WARNING: Removing unreachable block (ram,0xf005630c) */
/* WARNING: Removing unreachable block (ram,0xf0056274) */
/* WARNING: Removing unreachable block (ram,0xf0056248) */
/* WARNING: Removing unreachable block (ram,0xf0056280) */
/* WARNING: Removing unreachable block (ram,0xf0056360) */
/* WARNING: Removing unreachable block (ram,0xf00563d0) */
/* WARNING: Removing unreachable block (ram,0xf005622c) */

undefined8 _ipc_kmsg_copyin_from_kernel(int param_1,uint *param_2)

{
  uint uVar1;
  undefined4 unaff_l0;
  int iVar2;
  uint *puVar3;
  int iVar4;
  undefined4 unaff_l1;
  uint uVar5;
  uint *puVar6;
  uint *puVar7;
  uint *puVar8;
  uint uVar9;
  undefined4 unaff_l3;
  uint uVar10;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  uint uVar11;
  undefined4 unaff_l6;
  uint uVar12;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 uVar13;
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
  uVar13 = *(undefined4 *)(param_1 + 0x1c);
  uVar5 = *(uint *)(param_1 + 0x14);
  iVar2 = *(int *)(param_1 + 0x20);
  uVar10 = uVar5 & 0xff;
  uVar9 = (uVar5 & 0xff00) >> 8;
  _ipc_object_copyin_from_kernel(uVar13,uVar10);
  if ((iVar2 != 0) && (iVar2 != -1)) {
    _ipc_object_copyin_from_kernel(iVar2,uVar9);
  }
  if (uVar5 == 0x80000013) {
    *(undefined4 *)(param_1 + 0x14) = 0x80000011;
  }
  else {
    _ipc_object_copyin_type();
    _ipc_object_copyin_type();
    uVar10 = uVar5 & 0xffff0000 | uVar10 | uVar9 << 8;
    *(uint *)(param_1 + 0x14) = uVar10;
    if (-1 < (int)uVar10) goto locret_F0056408;
  }
  puVar6 = (uint *)(param_1 + 0x2c);
  param_2 = (uint *)(param_1 + *(int *)(param_1 + 0x18) + 0x14);
  if (puVar6 < param_2) {
    uVar10 = *puVar6;
    while( true ) {
      uVar9 = uVar10 >> 2 & 1;
      if (uVar9 == 0) {
        uVar12 = (uint)*(byte *)puVar6;
        uVar5 = uVar10 >> 0x10 & 0xff;
        uVar11 = uVar10 >> 4 & 0xfff;
        puVar7 = puVar6 + 1;
      }
      else {
        uVar12 = (uint)*(word *)(puVar6 + 1);
        uVar5 = (uint)*(word *)((int)puVar6 + 6);
        uVar11 = puVar6[2];
        puVar7 = puVar6 + 3;
      }
      uVar1 = uVar11;
      .umul(uVar11,uVar5);
      if ((uVar10 >> 3 & 1) == 0) {
        puVar3 = (uint *)*puVar7;
        puVar8 = puVar7 + 1;
      }
      else {
        puVar8 = (uint *)((int)puVar7 + ((uVar1 + 7 >> 3) + 3 & 0xfffffffc));
        puVar3 = puVar7;
      }
      if (uVar12 - 0x10 < 6) {
        uVar10 = uVar12;
        _ipc_object_copyin_type();
        if (uVar9 == 0) {
          *(byte *)puVar6 = (byte)uVar10;
        }
        else {
          *(sword *)(puVar6 + 1) = (sword)uVar10;
        }
        uVar9 = 0;
        if (uVar11 != 0) {
          iVar2 = 0;
          do {
            iVar4 = *(int *)(iVar2 + (int)puVar3);
            if ((((iVar4 != 0) && (iVar4 != -1)) &&
                (_ipc_object_copyin_from_kernel(iVar4,uVar12), uVar10 == 0x10)) &&
               (_ipc_port_check_circularity(iVar4,uVar13), iVar4 != 0)) {
              *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | 0x40000000;
            }
            uVar9 = uVar9 + 1;
            iVar2 = iVar2 + 4;
          } while (uVar9 < uVar11);
        }
      }
      if (param_2 <= puVar8) break;
      uVar10 = *puVar8;
      puVar6 = puVar8;
    }
  }
locret_F0056408:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1090 start=0xf0056410 */

/* WARNING: Removing unreachable block (ram,0xf0056908) */
/* WARNING: Removing unreachable block (ram,0xf0056a0c) */
/* WARNING: Removing unreachable block (ram,0xf005698c) */
/* WARNING: Removing unreachable block (ram,0xf0056960) */
/* WARNING: Removing unreachable block (ram,0xf0056bd8) */
/* WARNING: Removing unreachable block (ram,0xf0056b64) */
/* WARNING: Removing unreachable block (ram,0xf0056a6c) */
/* WARNING: Removing unreachable block (ram,0xf0056948) */
/* WARNING: Removing unreachable block (ram,0xf00568c0) */
/* WARNING: Removing unreachable block (ram,0xf0056894) */
/* WARNING: Removing unreachable block (ram,0xf005681c) */
/* WARNING: Removing unreachable block (ram,0xf00567bc) */
/* WARNING: Removing unreachable block (ram,0xf0056ae4) */
/* WARNING: Removing unreachable block (ram,0xf005668c) */
/* WARNING: Removing unreachable block (ram,0xf0056598) */
/* WARNING: Removing unreachable block (ram,0xf00564f8) */
/* WARNING: Removing unreachable block (ram,0xf0056740) */
/* WARNING: Removing unreachable block (ram,0xf0056484) */
/* WARNING: Removing unreachable block (ram,0xf0056550) */
/* WARNING: Removing unreachable block (ram,0xf00565bc) */
/* WARNING: Removing unreachable block (ram,0xf0056ab8) */
/* WARNING: Removing unreachable block (ram,0xf0056b2c) */
/* WARNING: Removing unreachable block (ram,0xf00567ec) */
/* WARNING: Removing unreachable block (ram,0xf0056840) */
/* WARNING: Removing unreachable block (ram,0xf00568a8) */
/* WARNING: Removing unreachable block (ram,0xf00568e4) */
/* WARNING: Removing unreachable block (ram,0xf0056a58) */
/* WARNING: Removing unreachable block (ram,0xf0056a84) */
/* WARNING: Removing unreachable block (ram,0xf0056bac) */
/* WARNING: Removing unreachable block (ram,0xf0056c54) */
/* WARNING: Removing unreachable block (ram,0xf0056970) */
/* WARNING: Removing unreachable block (ram,0xf00569e4) */
/* WARNING: Removing unreachable block (ram,0xf00569c8) */
/* WARNING: Removing unreachable block (ram,0xf0056910) */
/* WARNING: Removing unreachable block (ram,0xf00566d8) */

undefined8 _ipc_kmsg_copyout_header(uint *param_1,uint *param_2,int param_3)

{
  int *piVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 unaff_l0;
  int *piVar7;
  undefined4 unaff_l1;
  int *piVar8;
  int iVar9;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  uint uVar10;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint *puVar11;
  undefined4 uVar12;
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
  uVar10 = *param_1;
  piVar8 = (int *)param_1[2];
  if (param_3 == 0) {
    uVar5 = uVar10 & 0xffff;
    if (uVar5 == 0x12) {
      do {
        do {
        } while (*piVar8 != 0);
        piVar7 = piVar8;
        _simple_lock_try();
      } while (piVar7 == (int *)0x0);
      if (piVar8[2] < 0) {
        if ((uint *)piVar8[3] == param_2) {
          piVar8[1] = piVar8[1] + -1;
          piVar8[8] = piVar8[8] + -1;
          uVar5 = piVar8[4];
          *piVar8 = 0;
        }
        else {
          *piVar8 = 0;
          _ipc_notify_send_once(piVar8);
          uVar5 = 0;
        }
        *param_1 = uVar10 & 0xffff0000 | 0x1200;
        param_1[3] = uVar5;
loc_F0056768:
        param_1[2] = 0;
        uVar12 = 0;
        goto locret_F0056C88;
      }
loc_F00566FC:
      *piVar8 = 0;
      piVar7 = (int *)param_1[3];
    }
    else if (uVar5 < 0x13) {
      if (uVar5 == 0x11) {
        do {
          do {
          } while (*piVar8 != 0);
          piVar7 = piVar8;
          _simple_lock_try();
        } while (piVar7 == (int *)0x0);
        if (-1 < piVar8[2]) goto loc_F00566FC;
        piVar8[1] = piVar8[1] + -1;
        uVar5 = 0;
        if ((uint *)piVar8[3] == param_2) {
          uVar5 = piVar8[4];
        }
        iVar4 = piVar8[7];
        piVar8[7] = iVar4 + -1;
        if ((iVar4 + -1 == 0) && (iVar4 = piVar8[9], iVar4 != 0)) {
          piVar8[9] = 0;
          *piVar8 = 0;
          _ipc_notify_no_senders(iVar4,piVar8[6]);
        }
        else {
          *piVar8 = 0;
        }
        *param_1 = uVar10 & 0xffff0000 | 0x1100;
        param_1[3] = uVar5;
        goto loc_F0056768;
      }
      piVar7 = (int *)param_1[3];
    }
    else {
      piVar7 = (int *)param_1[3];
      if (uVar5 == 0x1211) {
        if ((piVar7 == (int *)0x0) || (piVar7 == (int *)0xffffffff)) goto loc_F0056780;
        do {
          do {
          } while (param_2[2] != 0);
          puVar11 = param_2 + 2;
          _simple_lock_try();
        } while (puVar11 == (uint *)0x0);
        if (param_2[3] != 0) {
          uVar5 = param_2[5];
          iVar4 = *(int *)(uVar5 + 8);
          if (iVar4 != 0) {
            do {
              do {
              } while (*piVar8 != 0);
              piVar1 = piVar8;
              _simple_lock_try();
            } while (piVar1 == (int *)0x0);
            if ((piVar8[2] < 0) && (piVar1 = piVar7, _simple_lock_try(), piVar1 != (int *)0x0)) {
              if (piVar7[2] < 0) {
                *piVar7 = 0;
                iVar9 = iVar4 * 0x10;
                iVar6 = uVar5 + iVar9;
                *(undefined4 *)(uVar5 + 8) = *(undefined4 *)(iVar6 + 8);
                *(undefined4 *)(iVar6 + 8) = 0;
                uVar2 = *(int *)(uVar5 + iVar9) + 0x1000000;
                *(uint *)(uVar5 + iVar9) = uVar2 | 0x40001;
                *(int **)(iVar6 + 4) = piVar7;
                param_2[2] = 0;
                piVar8[1] = piVar8[1] + -1;
                uVar5 = 0;
                if ((uint *)piVar8[3] == param_2) {
                  uVar5 = piVar8[4];
                }
                iVar9 = piVar8[7];
                piVar8[7] = iVar9 + -1;
                if ((iVar9 + -1 == 0) && (iVar9 = piVar8[9], iVar9 != 0)) {
                  piVar8[9] = 0;
                  *piVar8 = 0;
                  _ipc_notify_no_senders(iVar9,piVar8[6]);
                }
                else {
                  *piVar8 = 0;
                }
                *param_1 = uVar10 & 0xffff0000 | 0x1112;
                param_1[3] = uVar5;
                param_1[2] = iVar4 << 8 | uVar2 >> 0x18;
                uVar12 = 0;
                goto locret_F0056C88;
              }
              *piVar7 = 0;
            }
            *piVar8 = 0;
          }
        }
        param_2[2] = 0;
        piVar7 = (int *)param_1[3];
      }
    }
  }
  else {
loc_F0056780:
    piVar7 = (int *)param_1[3];
  }
  uVar5 = (uVar10 & 0xff00) >> 8;
  if ((piVar7 == (int *)0x0) || (piVar7 == (int *)0xffffffff)) {
    do {
      do {
      } while (param_2[2] != 0);
      puVar11 = param_2 + 2;
      _simple_lock_try();
    } while (puVar11 == (uint *)0x0);
    if (param_2[3] != 0) {
      if ((param_3 == 0) ||
         ((puVar11 = param_2, _ipc_entry_lookup(param_2,param_3), puVar11 != (uint *)0x0 &&
          ((*puVar11 & 0x20000) != 0)))) {
        do {
          do {
          } while (*piVar8 != 0);
          piVar1 = piVar8;
          _simple_lock_try();
        } while (piVar1 == (int *)0x0);
        param_2[2] = 0;
loc_F0056B44:
        *(int **)((int)register0x00000038 + -0xc) = piVar7;
        iVar4 = piVar8[2];
loc_F0056B4C:
        if (iVar4 < 0) {
          _ipc_object_copyout_dest
                    (param_2,piVar8,uVar10 & 0xff,(undefined *)((int)register0x00000038 + -0x18));
        }
        else {
          iVar9 = piVar8[3];
          iVar4 = piVar8[1];
          piVar8[1] = iVar4 + -1;
          *piVar8 = 0;
          if (iVar4 + -1 == 0) {
            _zfree((&_ipc_object_zones)[(piVar8[2] & 0x7fffffffU) >> 0x10],piVar8);
          }
          if ((piVar7 == (int *)0x0) || (piVar7 == (int *)0xffffffff)) {
            *(undefined4 *)((int)register0x00000038 + -0x18) = 0xffffffff;
          }
          else {
            do {
              do {
              } while (*piVar7 != 0);
              piVar8 = piVar7;
              _simple_lock_try();
            } while (piVar8 == (int *)0x0);
            if ((piVar7[2] < 0) || (iVar9 - piVar7[3] < 0)) {
              *(undefined4 *)((int)register0x00000038 + -0x18) = 0xffffffff;
            }
            else {
              *(undefined4 *)((int)register0x00000038 + -0x18) = 0;
            }
            *piVar7 = 0;
          }
        }
        if ((piVar7 != (int *)0x0) && (piVar7 != (int *)0xffffffff)) {
          _ipc_object_release(piVar7);
        }
        *param_1 = uVar10 & 0xffff0000 | uVar5 | (uVar10 & 0xff) << 8;
        uVar12 = 0;
        uVar10 = *(uint *)((int)register0x00000038 + -0xc);
        param_1[3] = *(uint *)((int)register0x00000038 + -0x18);
        param_1[2] = uVar10;
      }
      else {
loc_F0056B0C:
        param_2[2] = 0;
        uVar12 = 0x10004007;
      }
      goto locret_F0056C88;
    }
  }
  else {
    do {
      do {
      } while (param_2[2] != 0);
      puVar11 = param_2 + 2;
      _simple_lock_try();
    } while (puVar11 == (uint *)0x0);
    uVar2 = param_2[3];
    while (uVar2 != 0) {
      if (param_3 == 0) {
        puVar11 = (uint *)0x0;
      }
      else {
        puVar11 = param_2;
        _ipc_port_lookup_notify(param_2,param_3);
        if (puVar11 == (uint *)0x0) goto loc_F0056B0C;
      }
      if ((uVar5 != 0x12) &&
         (puVar3 = param_2,
         _ipc_right_reverse(param_2,piVar7,(undefined *)((int)register0x00000038 + -0xc),
                            (undefined *)((int)register0x00000038 + -0x10)), puVar3 != (uint *)0x0))
      {
        iVar4 = piVar7[1];
loc_F0056A3C:
        piVar7[1] = iVar4 + 1;
        _ipc_right_copyout(param_2,*(undefined4 *)((int)register0x00000038 + -0xc),
                           *(undefined4 *)((int)register0x00000038 + -0x10),uVar5,1,piVar7);
        if (puVar11 != (uint *)0x0) {
          _ipc_port_release_sonce(puVar11);
        }
        do {
          do {
          } while (*piVar8 != 0);
          piVar1 = piVar8;
          _simple_lock_try();
        } while (piVar1 == (int *)0x0);
        param_2[2] = 0;
        iVar4 = piVar8[2];
        goto loc_F0056B4C;
      }
      do {
        do {
        } while (*piVar7 != 0);
        piVar1 = piVar7;
        _simple_lock_try();
      } while (piVar1 == (int *)0x0);
      if (-1 < piVar7[2]) {
        iVar4 = piVar7[1];
        piVar7[1] = iVar4 + -1;
        *piVar7 = 0;
        if (iVar4 + -1 == 0) {
          _zfree((&_ipc_object_zones)[(piVar7[2] & 0x7fffffffU) >> 0x10],piVar7);
        }
        if (puVar11 != (uint *)0x0) {
          _ipc_port_release_sonce(puVar11);
        }
        do {
          do {
          } while (*piVar8 != 0);
          piVar7 = piVar8;
          _simple_lock_try();
        } while (piVar7 == (int *)0x0);
        param_2[2] = 0;
        piVar7 = (int *)0xffffffff;
        goto loc_F0056B44;
      }
      puVar3 = param_2;
      _ipc_entry_get(param_2,(undefined *)((int)register0x00000038 + -0xc),
                     (undefined *)((int)register0x00000038 + -0x10));
      if (puVar3 == (uint *)0x0) {
        if (puVar11 == (uint *)0x0) {
          *(int **)(*(int *)((int)register0x00000038 + -0x10) + 4) = piVar7;
loc_F0056A38:
          iVar4 = piVar7[1];
          goto loc_F0056A3C;
        }
        piVar1 = piVar7;
        _ipc_port_dnrequest(piVar7,*(undefined4 *)((int)register0x00000038 + -0xc),puVar11,
                            (undefined *)((int)register0x00000038 + -0x14));
        iVar4 = *(int *)((int)register0x00000038 + -0x10);
        if (piVar1 == (int *)0x0) {
          puVar11 = (uint *)0x0;
          uVar12 = *(undefined4 *)((int)register0x00000038 + -0x14);
          *(int **)(iVar4 + 4) = piVar7;
          *(undefined4 *)(iVar4 + 8) = uVar12;
          goto loc_F0056A38;
        }
        *piVar7 = 0;
        _ipc_port_release_sonce(puVar11);
        _ipc_entry_dealloc(param_2,*(undefined4 *)((int)register0x00000038 + -0xc),
                           *(undefined4 *)((int)register0x00000038 + -0x10));
        param_2[2] = 0;
        do {
          do {
          } while (*piVar7 != 0);
          piVar1 = piVar7;
          _simple_lock_try();
        } while (piVar1 == (int *)0x0);
        if (piVar7[2] < 0) {
          piVar1 = piVar7;
          _ipc_port_dngrow();
          if (piVar1 != (int *)0x0) goto loc_F0056C30;
          do {
            do {
            } while (param_2[2] != 0);
            puVar11 = param_2 + 2;
            _simple_lock_try();
          } while (puVar11 == (uint *)0x0);
          uVar2 = param_2[3];
        }
        else {
          *piVar7 = 0;
          do {
            do {
            } while (param_2[2] != 0);
            puVar11 = param_2 + 2;
            _simple_lock_try();
          } while (puVar11 == (uint *)0x0);
          uVar2 = param_2[3];
        }
      }
      else {
        *piVar7 = 0;
        if (puVar11 != (uint *)0x0) {
          _ipc_port_release_sonce(puVar11);
        }
        puVar11 = param_2;
        _ipc_entry_grow_table();
        if (puVar11 != (uint *)0x0) {
          if (puVar11 != (uint *)0x6) goto loc_F0056C28;
loc_F0056C30:
          uVar12 = 0x1000480b;
          goto locret_F0056C88;
        }
        uVar2 = param_2[3];
      }
    }
  }
  param_2[2] = 0;
loc_F0056C28:
  uVar12 = 0x1000600b;
locret_F0056C88:
  return CONCAT44(param_2,uVar12);
}
/* GHIDRADEC_FUNCTION index=1091 start=0xf0056c90 */

/* WARNING: Removing unreachable block (ram,0xf0056dbc) */
/* WARNING: Removing unreachable block (ram,0xf0056d10) */
/* WARNING: Removing unreachable block (ram,0xf0056d3c) */
/* WARNING: Removing unreachable block (ram,0xf0056dd0) */
/* WARNING: Removing unreachable block (ram,0xf0056cd0) */

undefined8 _ipc_kmsg_copyout_object(int param_1,int *param_2,int param_3,undefined4 *param_4)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar4;
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
  if ((param_2 == (int *)0x0) || (param_2 == (int *)0xffffffff)) {
    *param_4 = param_2;
  }
  else {
    if (param_3 == 0x11) {
      do {
        do {
        } while (*(int *)(param_1 + 8) != 0);
        piVar1 = (int *)(param_1 + 8);
        _simple_lock_try();
      } while (piVar1 == (int *)0x0);
      if (*(int *)(param_1 + 0xc) == 0) {
        *(undefined4 *)(param_1 + 8) = 0;
      }
      else {
        do {
          do {
          } while (*param_2 != 0);
          piVar1 = param_2;
          _simple_lock_try();
        } while (piVar1 == (int *)0x0);
        if ((param_2[2] < 0) &&
           (iVar2 = param_1,
           _ipc_hash_local_lookup
                     (param_1,param_2,param_4,(undefined *)((int)register0x00000038 + -0xc)),
           iVar2 != 0)) {
          param_2[7] = param_2[7] + -1;
          param_2[1] = param_2[1] + -1;
          *param_2 = 0;
          uVar3 = **(uint **)((int)register0x00000038 + -0xc) + 1;
          if ((uVar3 & 0xffff) < 0xffff) {
            **(uint **)((int)register0x00000038 + -0xc) = uVar3;
          }
          *(undefined4 *)(param_1 + 8) = 0;
          uVar4 = 0;
          goto locret_F0056E04;
        }
        *param_2 = 0;
        *(undefined4 *)(param_1 + 8) = 0;
      }
    }
    _ipc_object_copyout(param_1,param_2,param_3,1,param_4);
    if (param_1 != 0) {
      _ipc_object_destroy(param_2,param_3);
      if (param_1 != 0x14) {
        *param_4 = 0;
        uVar4 = 0x2000;
        if (param_1 == 6) {
          uVar4 = 0x800;
        }
        goto locret_F0056E04;
      }
      *param_4 = 0xffffffff;
    }
  }
  uVar4 = 0;
locret_F0056E04:
  return CONCAT44(param_2,uVar4);
}
/* GHIDRADEC_FUNCTION index=1092 start=0xf0056e0c */

/* WARNING: Removing unreachable block (ram,0xf0056f78) */
/* WARNING: Removing unreachable block (ram,0xf0056fac) */
/* WARNING: Removing unreachable block (ram,0xf0056f14) */
/* WARNING: Removing unreachable block (ram,0xf0056ebc) */
/* WARNING: Removing unreachable block (ram,0xf0056ed0) */
/* WARNING: Removing unreachable block (ram,0xf0056fc4) */
/* WARNING: Removing unreachable block (ram,0xf0056f84) */
/* WARNING: Removing unreachable block (ram,0xf0056e70) */

undefined8 _ipc_kmsg_copyout_body(uint *param_1,uint *param_2,uint param_3,int param_4)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar8;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  uint uVar9;
  undefined4 unaff_l6;
  uint uVar10;
  undefined4 unaff_l7;
  uint uVar11;
  undefined4 unaff_i0;
  uint *puVar12;
  undefined4 unaff_i1;
  uint *puVar13;
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
  uVar11 = 0;
  puVar13 = param_2;
loc_F0056E1C:
  do {
    if (param_2 <= param_1) {
      return CONCAT44(puVar13,uVar11);
    }
    uVar2 = *param_1;
    uVar5 = uVar2 >> 2 & 1;
    uVar9 = uVar2 >> 3 & 1;
    if (uVar5 == 0) {
      uVar10 = (uint)*(byte *)param_1;
      uVar6 = uVar2 >> 0x10 & 0xff;
      uVar2 = uVar2 >> 4 & 0xfff;
      puVar12 = param_1 + 1;
    }
    else {
      uVar10 = (uint)*(word *)(param_1 + 1);
      uVar6 = (uint)*(word *)((int)param_1 + 6);
      uVar2 = param_1[2];
      puVar12 = param_1 + 3;
    }
    uVar8 = uVar2;
    .umul(uVar2,uVar6);
    bVar1 = 5 < uVar10 - 0x10;
    uVar6 = uVar8 + 7 >> 3;
    puVar13 = param_1;
    if (!bVar1) {
      puVar7 = puVar12;
      if (uVar9 != 0) {
loc_F0056EF0:
        uVar8 = 0;
        if (uVar2 != 0) {
          do {
            uVar8 = uVar8 + 1;
            uVar4 = param_3;
            _ipc_kmsg_copyout_object(param_3,*puVar7,uVar10,puVar7);
            uVar11 = uVar11 | uVar4;
            puVar7 = puVar7 + 1;
          } while (uVar8 < uVar2);
        }
        goto loc_F0056F30;
      }
      if ((uVar6 == 0) ||
         (iVar3 = param_4,
         _vm_allocate(param_4,(undefined *)((int)register0x00000038 + -0xc),uVar6,1), iVar3 == 0)) {
        puVar7 = (uint *)*puVar12;
        goto loc_F0056EF0;
      }
      _ipc_kmsg_clean_body(param_1,puVar12);
loc_F0056FD8:
      *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
      if (uVar5 == 0) {
        *(byte *)((int)param_1 + 1) = 0;
      }
      else {
        ((byte *)((int)param_1 + 6))[0] = 0;
        ((byte *)((int)param_1 + 6))[1] = 0;
      }
      if (iVar3 == 6) {
        uVar11 = uVar11 | 0x400;
      }
      else {
        uVar11 = uVar11 | 0x1000;
      }
      goto loc_F0057004;
    }
loc_F0056F30:
    if (uVar9 == 0) {
      uVar2 = *puVar12;
      if (uVar6 == 0) {
        *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
loc_F0057004:
        uVar5 = *param_1;
      }
      else {
        if (bVar1) {
          iVar3 = _ipc_soft_map;
          _vm_move(_ipc_soft_map,uVar2,param_4,uVar6,0,(undefined *)((int)register0x00000038 + -0xc)
                  );
          _vm_deallocate(_ipc_soft_map,uVar2,uVar6);
          if (iVar3 != 0) goto loc_F0056FD8;
          goto loc_F0057004;
        }
        _copyoutmap(param_4,uVar2,*(undefined4 *)((int)register0x00000038 + -0xc),uVar6);
        _kfree(uVar2,uVar6);
        uVar5 = *param_1;
      }
      uVar2 = *(uint *)((int)register0x00000038 + -0xc);
      *param_1 = uVar5 | 2;
      *puVar12 = uVar2;
      param_1 = puVar12 + 1;
      goto loc_F0056E1C;
    }
    *param_1 = *param_1 & 0xfffffffd;
    param_1 = (uint *)((int)puVar12 + (uVar6 + 3 & 0xfffffffc));
  } while( true );
}
/* GHIDRADEC_FUNCTION index=1093 start=0xf0057028 */

/* WARNING: Removing unreachable block (ram,0xf0057068) */
/* WARNING: Removing unreachable block (ram,0xf005703c) */

undefined8 _ipc_kmsg_copyout(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar3;
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
  uVar1 = param_1 + 0x14;
  iVar3 = *(int *)(param_1 + 0x14);
  _ipc_kmsg_copyout_header(uVar1,param_2,param_4);
  if ((uVar1 == 0) && (uVar2 = param_1 + 0x2c, iVar3 < 0)) {
    _ipc_kmsg_copyout_body(uVar2,param_1 + *(int *)(param_1 + 0x18) + 0x14,param_2,param_3);
    uVar1 = 0;
    if (uVar2 != 0) {
      uVar1 = uVar2 | 0x1000400c;
    }
  }
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=1094 start=0xf005708c */

/* WARNING: Removing unreachable block (ram,0xf00570cc) */
/* WARNING: Removing unreachable block (ram,0xf0057110) */
/* WARNING: Removing unreachable block (ram,0xf00570b4) */

undefined8 _ipc_kmsg_copyout_pseudo(int param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 unaff_l3;
  uint uVar4;
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
  uVar2 = *(uint *)(param_1 + 0x14);
  uVar3 = *(undefined4 *)(param_1 + 0x20);
  uVar4 = param_2;
  _ipc_kmsg_copyout_object
            (param_2,*(undefined4 *)(param_1 + 0x1c),uVar2 & 0xff,
             (undefined *)((int)register0x00000038 + -0xc));
  uVar1 = param_2;
  _ipc_kmsg_copyout_object
            (param_2,uVar3,(uVar2 & 0xff00) >> 8,(undefined *)((int)register0x00000038 + -0x10));
  uVar4 = uVar4 | uVar1;
  *(uint *)(param_1 + 0x14) = uVar2 & 0xbfffffff;
  uVar3 = *(undefined4 *)((int)register0x00000038 + -0x10);
  *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)((int)register0x00000038 + -0xc);
  *(undefined4 *)(param_1 + 0x20) = uVar3;
  if ((int)uVar2 < 0) {
    uVar1 = param_1 + 0x2c;
    _ipc_kmsg_copyout_body(uVar1,param_1 + *(int *)(param_1 + 0x18) + 0x14,param_2,param_3);
    uVar4 = uVar4 | uVar1;
  }
  return CONCAT44(param_2,uVar4);
}
/* GHIDRADEC_FUNCTION index=1095 start=0xf0057124 */

/* WARNING: Removing unreachable block (ram,0xf00571f0) */
/* WARNING: Removing unreachable block (ram,0xf0057188) */
/* WARNING: Removing unreachable block (ram,0xf00571cc) */
/* WARNING: Removing unreachable block (ram,0xf005723c) */
/* WARNING: Removing unreachable block (ram,0xf0057158) */

undefined8 _ipc_kmsg_copyout_dest(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 unaff_l0;
  int *piVar3;
  undefined4 unaff_l1;
  int iVar4;
  uint uVar5;
  undefined4 unaff_l3;
  uint uVar6;
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
  piVar3 = *(int **)(param_1 + 0x1c);
  uVar5 = *(uint *)(param_1 + 0x14);
  iVar4 = *(int *)(param_1 + 0x20);
  uVar6 = (uVar5 & 0xff00) >> 8;
  do {
    do {
    } while (*piVar3 != 0);
    piVar1 = piVar3;
    _simple_lock_try();
  } while (piVar1 == (int *)0x0);
  if (piVar3[2] < 0) {
    _ipc_object_copyout_dest
              (param_2,piVar3,uVar5 & 0xff,(undefined *)((int)register0x00000038 + -0xc));
  }
  else {
    iVar2 = piVar3[1];
    piVar3[1] = iVar2 + -1;
    *piVar3 = 0;
    if (iVar2 + -1 == 0) {
      _zfree((&_ipc_object_zones)[(piVar3[2] & 0x7fffffffU) >> 0x10],piVar3);
    }
    *(undefined4 *)((int)register0x00000038 + -0xc) = 0xffffffff;
  }
  if ((iVar4 != 0) && (iVar4 != -1)) {
    _ipc_object_destroy(iVar4,uVar6);
    iVar4 = 0;
  }
  *(uint *)(param_1 + 0x14) = uVar5 & 0xffff0000 | uVar6 | (uVar5 & 0xff) << 8;
  *(int *)(param_1 + 0x1c) = iVar4;
  *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)((int)register0x00000038 + -0xc);
  if ((int)uVar5 < 0) {
    _ipc_kmsg_clean_body(param_1 + 0x2c,param_1 + *(int *)(param_1 + 0x18) + 0x14);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1096 start=0xf005724c */

/* WARNING: Removing unreachable block (ram,0xf0057384) */
/* WARNING: Removing unreachable block (ram,0xf00575c8) */
/* WARNING: Removing unreachable block (ram,0xf005759c) */
/* WARNING: Removing unreachable block (ram,0xf0057558) */
/* WARNING: Removing unreachable block (ram,0xf0057520) */
/* WARNING: Removing unreachable block (ram,0xf00574a0) */
/* WARNING: Removing unreachable block (ram,0xf00572d4) */
/* WARNING: Removing unreachable block (ram,0xf00572c0) */
/* WARNING: Removing unreachable block (ram,0xf005734c) */
/* WARNING: Removing unreachable block (ram,0xf0057504) */
/* WARNING: Removing unreachable block (ram,0xf0057544) */
/* WARNING: Removing unreachable block (ram,0xf005757c) */
/* WARNING: Removing unreachable block (ram,0xf00573ec) */
/* WARNING: Removing unreachable block (ram,0xf005761c) */
/* WARNING: Removing unreachable block (ram,0xf0057638) */
/* WARNING: Removing unreachable block (ram,0xf0057290) */

undefined8 _ipc_kmsg_copyin_compat(int param_1,uint param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 unaff_l0;
  int iVar7;
  uint *puVar8;
  undefined4 unaff_l1;
  uint *puVar9;
  uint uVar10;
  uint *puVar11;
  uint *puVar12;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  uint uVar13;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  uint uVar14;
  undefined4 unaff_i3;
  uint *puVar15;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar16;
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
  *(undefined4 *)((int)register0x00000038 + -0x20) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)((int)register0x00000038 + -0x1c) = *(undefined4 *)(param_1 + 0x18);
  uVar4 = *(undefined4 *)(param_1 + 0x1c);
  *(uint *)((int)register0x00000038 + -0x3c) = param_2;
  *(undefined4 *)((int)register0x00000038 + -0x18) = uVar4;
  iVar7 = *(int *)(param_1 + 0x20);
  *(int *)((int)register0x00000038 + -0x14) = iVar7;
  uVar4 = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)((int)register0x00000038 + -0x10) = uVar4;
  iVar2 = *(int *)((int)register0x00000038 + -0x3c);
  *(undefined4 *)((int)register0x00000038 + -0xc) = *(undefined4 *)(param_1 + 0x28);
  _ipc_object_copyin_header
            (iVar2,uVar4,(undefined *)((int)register0x00000038 + -0x24),
             (undefined *)((int)register0x00000038 + -0x28));
  if (iVar2 == 0) {
    iVar2 = *(int *)((int)register0x00000038 + -0x3c);
    if (iVar7 == 0) {
      *(undefined4 *)((int)register0x00000038 + -0x2c) = 0;
      *(undefined4 *)((int)register0x00000038 + -0x30) = 0;
    }
    else {
      _ipc_object_copyin_header
                (iVar2,iVar7,(undefined *)((int)register0x00000038 + -0x2c),
                 (undefined *)((int)register0x00000038 + -0x30));
      if (iVar2 != 0) {
        _ipc_object_destroy(*(undefined4 *)((int)register0x00000038 + -0x24),
                            *(undefined4 *)((int)register0x00000038 + -0x28));
        uVar4 = 0x10000009;
        goto locret_F0057698;
      }
    }
    *(uint *)(param_1 + 0x14) =
         *(uint *)((int)register0x00000038 + -0x28) | *(int *)((int)register0x00000038 + -0x30) << 8
    ;
    uVar5 = *(undefined4 *)((int)register0x00000038 + -0x24);
    *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)((int)register0x00000038 + -0x1c);
    uVar4 = *(undefined4 *)((int)register0x00000038 + -0x2c);
    *(undefined4 *)(param_1 + 0x1c) = uVar5;
    *(undefined4 *)(param_1 + 0x20) = uVar4;
    *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)((int)register0x00000038 + -0x18);
    *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)((int)register0x00000038 + -0xc);
    bVar16 = false;
    if (*(char *)((int)register0x00000038 + -0x1d) == '\0') {
      puVar15 = (uint *)(param_1 + *(int *)(param_1 + 0x18) + 0x14);
      puVar9 = (uint *)(param_1 + 0x2c);
      while (puVar11 = puVar9, puVar11 < puVar15) {
        if ((uint)((int)puVar15 - (int)puVar11) < 4) {
loc_F00573E8:
          _ipc_kmsg_clean_partial(param_1,puVar11,0,0);
          uVar4 = 0x10000008;
          goto locret_F0057698;
        }
        uVar10 = *puVar11 >> 2 & 1;
        if (uVar10 == 0) {
          uVar3 = *puVar11;
        }
        else {
          if ((uint)((int)puVar15 - (int)puVar11) < 0xc) goto loc_F00573E8;
          uVar3 = *puVar11;
        }
        param_2 = uVar3 >> 1 & 1;
        if (uVar10 == 0) {
          uVar14 = (uint)*(byte *)puVar11;
          uVar6 = uVar3 >> 0x10 & 0xff;
          uVar13 = uVar3 >> 4 & 0xfff;
          puVar12 = puVar11 + 1;
        }
        else {
          uVar14 = (uint)*(word *)(puVar11 + 1);
          uVar6 = (uint)*(word *)((int)puVar11 + 6);
          uVar13 = puVar11[2];
          puVar12 = puVar11 + 3;
        }
        bVar1 = uVar14 - 5 < 2;
        if ((bVar1) && (uVar6 != 0x20)) {
          _ipc_kmsg_clean_partial(param_1,puVar11,0,0);
          uVar4 = 0x1000000f;
          goto locret_F0057698;
        }
        *puVar11 = *puVar11 & 0xfffffffe;
        if (uVar10 != 0) {
          *(byte *)puVar11 = 0;
          *(byte *)((int)puVar11 + 1) = 0;
          *puVar11 = *puVar11 & 0xffff000f;
        }
        uVar6 = uVar13;
        .umul();
        puVar9 = (uint *)(uVar6 + 7 >> 3);
        if ((uVar3 >> 3 & 1) == 0) {
          if ((uint)((int)puVar15 - (int)puVar12) < 4) goto loc_F00573E8;
          uVar3 = *puVar12;
          if (puVar9 != (uint *)0x0) {
            if (bVar1) {
              puVar8 = puVar9;
              _kalloc();
              if (puVar8 != (uint *)0x0) {
                iVar2 = param_3;
                _copyinmap(param_3,uVar3,puVar8,puVar9);
                if ((iVar2 == 0) &&
                   ((param_2 == 0 ||
                    (iVar2 = param_3, _vm_deallocate(param_3,uVar3,puVar9), iVar2 == 0))))
                goto loc_F00575B0;
                _kfree(puVar8,puVar9);
              }
            }
            else {
              iVar2 = param_3;
              _vm_move(param_3,uVar3,_ipc_soft_map,puVar9,param_2,
                       (undefined *)((int)register0x00000038 + -0x34));
              puVar8 = *(uint **)((int)register0x00000038 + -0x34);
              if (iVar2 == 0) goto loc_F00575B0;
            }
            _ipc_kmsg_clean_partial(param_1,puVar11,0,0);
            uVar4 = 0x1000000c;
            goto locret_F0057698;
          }
          puVar8 = (uint *)0x0;
loc_F00575B0:
          *puVar12 = (uint)puVar8;
          puVar9 = puVar12 + 1;
          bVar16 = true;
        }
        else {
          uVar3 = (uint)((int)puVar9 + 3) & 0xfffffffc;
          if ((uint)((int)puVar15 - (int)puVar12) < uVar3) goto loc_F00573E8;
          puVar9 = (uint *)((int)puVar12 + uVar3);
          puVar8 = puVar12;
        }
        if (bVar1) {
          uVar3 = uVar14;
          _ipc_object_copyin_type();
          if (uVar10 == 0) {
            *(byte *)puVar11 = (byte)uVar3;
          }
          else {
            *(sword *)(puVar11 + 1) = (sword)uVar3;
          }
          uVar10 = 0;
          if (uVar13 != 0) {
            do {
              uVar6 = *puVar8;
              if ((uVar6 != 0) &&
                 (iVar2 = *(int *)((int)register0x00000038 + -0x3c), uVar6 != 0xffffffff)) {
                _ipc_object_copyin_compat
                          (iVar2,uVar6,uVar14,param_2,(undefined *)((int)register0x00000038 + -0x38)
                          );
                if (iVar2 != 0) {
                  _ipc_kmsg_clean_partial(param_1,puVar11,1,uVar10);
                  uVar4 = 0x1000000a;
                  goto locret_F0057698;
                }
                uVar6 = *(uint *)((int)register0x00000038 + -0x38);
                if (uVar3 == 0x10) {
                  _ipc_port_check_circularity
                            (uVar6,*(undefined4 *)((int)register0x00000038 + -0x24));
                  bVar16 = uVar6 != 0;
                  uVar6 = *(uint *)((int)register0x00000038 + -0x38);
                  if (bVar16) {
                    *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | 0x40000000;
                    uVar6 = *(uint *)((int)register0x00000038 + -0x38);
                  }
                }
                *puVar8 = uVar6;
              }
              uVar10 = uVar10 + 1;
              puVar8 = puVar8 + 1;
            } while (uVar10 < uVar13);
          }
          bVar16 = true;
        }
      }
      if (bVar16) {
        *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | 0x80000000;
      }
      uVar4 = 0;
    }
    else {
      uVar4 = 0;
    }
  }
  else {
    uVar4 = 0x10000003;
  }
locret_F0057698:
  return CONCAT44(param_2,uVar4);
}
/* GHIDRADEC_FUNCTION index=1097 start=0xf00576a0 */

/* WARNING: Removing unreachable block (ram,0xf0057898) */
/* WARNING: Removing unreachable block (ram,0xf00577fc) */
/* WARNING: Removing unreachable block (ram,0xf0057704) */
/* WARNING: Removing unreachable block (ram,0xf00576fc) */
/* WARNING: Removing unreachable block (ram,0xf0057710) */
/* WARNING: Removing unreachable block (ram,0xf0057840) */
/* WARNING: Removing unreachable block (ram,0xf00578b0) */
/* WARNING: Removing unreachable block (ram,0xf00576dc) */

undefined8 _ipc_kmsg_copyin_compat_from_kernel(int param_1)

{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint *puVar8;
  uint *puVar9;
  uint *puVar10;
  uint uVar11;
  undefined4 unaff_l3;
  uint *puVar12;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  uint uVar13;
  undefined4 unaff_l6;
  uint uVar14;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  uint *puVar15;
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
  *(undefined4 *)((int)register0x00000038 + -0x20) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)((int)register0x00000038 + -0x1c) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)((int)register0x00000038 + -0x18) = *(undefined4 *)(param_1 + 0x1c);
  iVar7 = *(int *)(param_1 + 0x20);
  *(int *)((int)register0x00000038 + -0x14) = iVar7;
  uVar2 = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)((int)register0x00000038 + -0x10) = uVar2;
  *(undefined4 *)((int)register0x00000038 + -0xc) = *(undefined4 *)(param_1 + 0x28);
  _ipc_object_copyin_from_kernel(uVar2,0x13);
  if ((iVar7 != 0) && (iVar7 != -1)) {
    _ipc_object_copyin_from_kernel(iVar7,0x14);
  }
  uVar3 = 0x13;
  _ipc_object_copyin_type();
  iVar4 = 0x14;
  _ipc_object_copyin_type();
  *(uint *)(param_1 + 0x14) = uVar3 | iVar4 << 8;
  *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)((int)register0x00000038 + -0x1c);
  *(undefined4 *)(param_1 + 0x1c) = uVar2;
  *(int *)(param_1 + 0x20) = iVar7;
  *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)((int)register0x00000038 + -0x18);
  *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)((int)register0x00000038 + -0xc);
  puVar8 = (uint *)(param_1 + 0x2c);
  if (*(char *)((int)register0x00000038 + -0x1d) == '\0') {
    puVar15 = (uint *)(param_1 + *(int *)(param_1 + 0x18) + 0x14);
    bVar1 = false;
    if (puVar8 < puVar15) {
      uVar3 = *puVar8;
      while( true ) {
        uVar11 = uVar3 >> 2 & 1;
        if (uVar11 == 0) {
          uVar14 = (uint)*(byte *)puVar8;
          uVar6 = uVar3 >> 0x10 & 0xff;
          uVar13 = uVar3 >> 4 & 0xfff;
          puVar9 = puVar8 + 1;
        }
        else {
          uVar14 = (uint)*(word *)(puVar8 + 1);
          uVar6 = (uint)*(word *)((int)puVar8 + 6);
          uVar13 = puVar8[2];
          puVar9 = puVar8 + 3;
        }
        *puVar8 = *puVar8 & 0xfffffffe;
        if (uVar11 != 0) {
          *(byte *)puVar8 = 0;
          *(byte *)((int)puVar8 + 1) = 0;
          *puVar8 = *puVar8 & 0xffff000f;
        }
        uVar5 = uVar13;
        .umul(uVar13,uVar6);
        if ((uVar3 >> 3 & 1) == 0) {
          puVar12 = (uint *)*puVar9;
          bVar1 = true;
          puVar10 = puVar9 + 1;
        }
        else {
          puVar10 = (uint *)((int)puVar9 + ((uVar5 + 7 >> 3) + 3 & 0xfffffffc));
          puVar12 = puVar9;
        }
        if (uVar14 - 5 < 2) {
          uVar3 = uVar14;
          _ipc_object_copyin_type();
          if (uVar11 == 0) {
            *(byte *)puVar8 = (byte)uVar3;
          }
          else {
            *(sword *)(puVar8 + 1) = (sword)uVar3;
          }
          uVar11 = 0;
          if (uVar13 != 0) {
            iVar7 = 0;
            do {
              iVar4 = *(int *)(iVar7 + (int)puVar12);
              if ((((iVar4 != 0) && (iVar4 != -1)) &&
                  (_ipc_object_copyin_from_kernel(iVar4,uVar14), uVar3 == 0x10)) &&
                 (_ipc_port_check_circularity(iVar4,uVar2), iVar4 != 0)) {
                *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | 0x40000000;
              }
              uVar11 = uVar11 + 1;
              iVar7 = iVar7 + 4;
            } while (uVar11 < uVar13);
          }
          bVar1 = true;
        }
        if (puVar15 <= puVar10) break;
        uVar3 = *puVar10;
        puVar8 = puVar10;
      }
    }
    if (bVar1) {
      *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | 0x80000000;
    }
  }
  return CONCAT44(uVar2,param_1);
}
/* GHIDRADEC_FUNCTION index=1098 start=0xf005790c */

/* WARNING: Removing unreachable block (ram,0xf0057c1c) */
/* WARNING: Removing unreachable block (ram,0xf0057c54) */
/* WARNING: Removing unreachable block (ram,0xf0057bbc) */
/* WARNING: Removing unreachable block (ram,0xf0057b48) */
/* WARNING: Removing unreachable block (ram,0xf0057adc) */
/* WARNING: Removing unreachable block (ram,0xf00579dc) */
/* WARNING: Removing unreachable block (ram,0xf0057960) */
/* WARNING: Removing unreachable block (ram,0xf00579a4) */
/* WARNING: Removing unreachable block (ram,0xf00579f0) */
/* WARNING: Removing unreachable block (ram,0xf0057b24) */
/* WARNING: Removing unreachable block (ram,0xf0057ba4) */
/* WARNING: Removing unreachable block (ram,0xf0057c40) */
/* WARNING: Removing unreachable block (ram,0xf0057c10) */
/* WARNING: Removing unreachable block (ram,0xf0057b38) */
/* WARNING: Removing unreachable block (ram,0xf0057930) */

sqword _ipc_kmsg_copyout_compat(int param_1,uint *param_2,int param_3)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  uint *puVar4;
  uint uVar5;
  undefined4 unaff_l0;
  int *piVar6;
  uint uVar7;
  undefined4 unaff_l1;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint *puVar11;
  uint *puVar12;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  uint uVar13;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar14;
  undefined4 unaff_i1;
  uint *puVar15;
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
  uVar10 = *(uint *)(param_1 + 0x14);
  piVar6 = *(int **)(param_1 + 0x1c);
  iVar8 = *(int *)(param_1 + 0x20);
  do {
    do {
    } while (*piVar6 != 0);
    piVar2 = piVar6;
    _simple_lock_try();
  } while (piVar2 == (int *)0x0);
  if (piVar6[2] < 0) {
    _ipc_object_copyout_dest
              (param_2,piVar6,uVar10 & 0xff,(undefined *)((int)register0x00000038 + -0x24));
  }
  else {
    iVar3 = piVar6[1];
    piVar6[1] = iVar3 + -1;
    *piVar6 = 0;
    if (iVar3 + -1 == 0) {
      _zfree((&_ipc_object_zones)[(piVar6[2] & 0x7fffffffU) >> 0x10],piVar6);
      *(undefined4 *)((int)register0x00000038 + -0x24) = 0;
    }
    else {
      *(undefined4 *)((int)register0x00000038 + -0x24) = 0;
    }
  }
  if ((iVar8 != 0) && (iVar8 != -1)) {
    uVar7 = (uVar10 & 0xff00) >> 8;
    puVar15 = param_2;
    _ipc_object_copyout_compat(param_2,iVar8,uVar7,(undefined *)((int)register0x00000038 + -0x28));
    if (puVar15 == (uint *)0x0) goto loc_F00579FC;
    _ipc_object_destroy(iVar8,uVar7);
  }
  *(undefined4 *)((int)register0x00000038 + -0x28) = 0;
loc_F00579FC:
  *(uint *)((int)register0x00000038 + -0x20) = (uint)*(byte *)((int)register0x00000038 + -0x1d);
  *(byte *)((int)register0x00000038 + -0x1d) = (byte)(uVar10 >> 0x1f) ^ 1;
  *(undefined4 *)((int)register0x00000038 + -0x1c) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)((int)register0x00000038 + -0x18) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)((int)register0x00000038 + -0x14) =
       *(undefined4 *)((int)register0x00000038 + -0x24);
  *(undefined4 *)((int)register0x00000038 + -0x10) =
       *(undefined4 *)((int)register0x00000038 + -0x28);
  *(undefined4 *)((int)register0x00000038 + -0xc) = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)((int)register0x00000038 + -0x20);
  *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)((int)register0x00000038 + -0x1c);
  *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)((int)register0x00000038 + -0x18);
  *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)((int)register0x00000038 + -0x14);
  *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)((int)register0x00000038 + -0x10);
  *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)((int)register0x00000038 + -0xc);
  puVar11 = (uint *)(param_1 + 0x2c);
  puVar15 = param_2;
  if ((*(char *)((int)register0x00000038 + -0x1d) == '\0') &&
     (puVar15 = (uint *)(param_1 + *(int *)(param_1 + 0x18) + 0x14), puVar11 < puVar15)) {
    uVar10 = *puVar11;
    do {
      uVar7 = uVar10 >> 2 & 1;
      uVar14 = uVar10 >> 3 & 1;
      if (uVar7 == 0) {
        uVar13 = (uint)*(byte *)puVar11;
        uVar5 = uVar10 >> 0x10 & 0xff;
        uVar10 = uVar10 >> 4 & 0xfff;
        puVar12 = puVar11 + 1;
      }
      else {
        uVar13 = (uint)*(word *)(puVar11 + 1);
        uVar5 = (uint)*(word *)((int)puVar11 + 6);
        uVar10 = puVar11[2];
        puVar12 = puVar11 + 3;
      }
      uVar9 = uVar10;
      .umul(uVar10,uVar5);
      bVar1 = 5 < uVar13 - 0x10;
      uVar5 = uVar9 + 7 >> 3;
      if (bVar1) {
loc_F0057BDC:
        if (uVar14 == 0) {
          uVar10 = *puVar12;
          if (uVar5 == 0) {
loc_F0057C68:
            *(undefined4 *)((int)register0x00000038 + -0x2c) = 0;
            goto loc_F0057C6C;
          }
          if (bVar1) {
            iVar8 = _ipc_soft_map;
            _vm_move(_ipc_soft_map,uVar10,param_3,uVar5,0,
                     (undefined *)((int)register0x00000038 + -0x2c));
            _vm_deallocate(_ipc_soft_map,uVar10,uVar5);
            uVar10 = *(uint *)((int)register0x00000038 + -0x2c);
            if (iVar8 != 0) goto loc_F0057C68;
          }
          else {
            _copyoutmap(param_3,uVar10,*(undefined4 *)((int)register0x00000038 + -0x2c),uVar5);
            _kfree(uVar10,uVar5);
            uVar10 = *(uint *)((int)register0x00000038 + -0x2c);
          }
          goto loc_F0057C70;
        }
        puVar11 = (uint *)((int)puVar12 + (uVar5 + 3 & 0xfffffffc));
      }
      else {
        if (((uVar14 != 0) || (uVar5 == 0)) ||
           (iVar8 = param_3,
           _vm_allocate(param_3,(undefined *)((int)register0x00000038 + -0x2c),uVar5,1), iVar8 == 0)
           ) {
          uVar9 = uVar13;
          _ipc_object_copyout_type_compat();
          if (uVar7 == 0) {
            *(byte *)puVar11 = (byte)uVar9;
          }
          else {
            *(sword *)(puVar11 + 1) = (sword)uVar9;
          }
          puVar11 = puVar12;
          if (uVar14 == 0) {
            puVar11 = (uint *)*puVar12;
          }
          uVar7 = 0;
          if (uVar10 != 0) {
            do {
              uVar9 = *puVar11;
              if ((uVar9 == 0) || (uVar9 == 0xffffffff)) {
loc_F0057BC4:
                *puVar11 = 0;
              }
              else {
                puVar4 = param_2;
                _ipc_object_copyout_compat(param_2,uVar9,uVar13,puVar11);
                if (puVar4 != (uint *)0x0) {
                  _ipc_object_destroy(uVar9,uVar13);
                  goto loc_F0057BC4;
                }
              }
              uVar7 = uVar7 + 1;
              puVar11 = puVar11 + 1;
            } while (uVar7 < uVar10);
          }
          goto loc_F0057BDC;
        }
        _ipc_kmsg_clean_body(puVar11,puVar12);
        *(undefined4 *)((int)register0x00000038 + -0x2c) = 0;
loc_F0057C6C:
        uVar10 = *(uint *)((int)register0x00000038 + -0x2c);
loc_F0057C70:
        *puVar12 = uVar10;
        puVar11 = puVar12 + 1;
      }
      if (puVar15 <= puVar11) break;
      uVar10 = *puVar11;
    } while( true );
  }
  return ZEXT48(puVar15) << 0x20;
}
/* GHIDRADEC_FUNCTION index=1099 start=0xf0057c8c */

/* WARNING: Removing unreachable block (ram,0xf0057d78) */
/* WARNING: Removing unreachable block (ram,0xf0057d94) */
/* WARNING: Removing unreachable block (ram,0xf0057d14) */

undefined8 _ipc_marequest_init(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
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
  if ((_ipc_marequest_size == 0) &&
     (_ipc_marequest_size = _ipc_marequest_max >> 8, _ipc_marequest_size < 0x10)) {
    _ipc_marequest_size = 0x10;
  }
  _ipc_marequest_mask = _ipc_marequest_size - 1;
  if ((_ipc_marequest_size & _ipc_marequest_mask) != 0) {
    uVar4 = 1;
    for (_ipc_marequest_mask = _ipc_marequest_mask | 1;
        _ipc_marequest_size = _ipc_marequest_mask + 1,
        (_ipc_marequest_size & _ipc_marequest_mask) != 0;
        _ipc_marequest_mask = _ipc_marequest_mask | uVar4) {
      uVar4 = uVar4 << 1;
    }
  }
  iVar1 = _ipc_marequest_size << 3;
  _kalloc();
  uVar4 = _ipc_marequest_size;
  uVar3 = 0;
  iVar5 = iVar1;
  _ipc_marequest_table = iVar1;
  if (_ipc_marequest_size != 0) {
    do {
      *(undefined4 *)(iVar1 + uVar3 * 8) = 0;
      *(undefined4 *)(iVar5 + 4) = 0;
      uVar3 = uVar3 + 1;
      iVar5 = iVar5 + 8;
    } while (uVar3 < uVar4);
  }
  uVar2 = 0x10;
  _zinit(0x10,_ipc_marequest_max << 4,0x10,0,aIpcMsgAccepted);
  _ipc_marequest_zone = uVar2;
  _zchange();
  return CONCAT44(param_2,param_1);
}

