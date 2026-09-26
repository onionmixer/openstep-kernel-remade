
/* WARNING: Removing unreachable block (ram,0xf0029444) */
/* WARNING: Removing unreachable block (ram,0xf00293cc) */
/* WARNING: Removing unreachable block (ram,0xf0029394) */
/* WARNING: Removing unreachable block (ram,0xf0029340) */
/* WARNING: Removing unreachable block (ram,0xf0029354) */
/* WARNING: Removing unreachable block (ram,0xf00293fc) */
/* WARNING: Removing unreachable block (ram,0xf002942c) */
/* WARNING: Removing unreachable block (ram,0xf002944c) */
/* WARNING: Removing unreachable block (ram,0xf0029320) */

undefined8 _vn_remove(undefined *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  code *pcVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined *puVar5;
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
  puVar5 = (undefined *)((int)register0x00000038 + -0x18);
  _pn_get(param_1,param_2,puVar5);
  if (param_1 != (undefined *)0x0) goto locret_F0029454;
  *(undefined4 *)((int)register0x00000038 + -0x20) = 0;
  param_1 = puVar5;
  _lookuppn(puVar5,0,(undefined *)((int)register0x00000038 + -0x1c),
            (undefined *)((int)register0x00000038 + -0x20));
  iVar1 = *(int *)((int)register0x00000038 + -0x20);
  if (param_1 != (undefined *)0x0) {
    _pn_free(puVar5);
    goto locret_F0029454;
  }
  if (iVar1 == 0) {
    param_1 = (undefined *)0x2;
  }
  else {
    param_1 = (undefined *)0x1e;
    if (((*(uint *)(*(int *)(iVar1 + 0x24) + 0xc) & 1) == 0) &&
       (param_1 = (undefined *)0x10, (*(word *)(iVar1 + 4) & 1) == 0)) {
      _vnode_uncache(iVar1);
      iVar1 = *(int *)((int)register0x00000038 + -0x20);
      if (*(int *)(iVar1 + 0x28) == 2) {
        param_1 = (undefined *)0x1;
        if ((param_3 == 1) && (param_1 = (undefined *)0x42, *(int *)(iVar1 + 0x10) == 0)) {
          _vn_rele(iVar1);
          uVar2 = *(undefined4 *)((int)register0x00000038 + -0x14);
          uVar3 = *(undefined4 *)(_active_u + 0x1c);
          param_1 = *(undefined **)((int)register0x00000038 + -0x1c);
          pcVar4 = *(code **)(*(int *)(param_1 + 0x1c) + 0x38);
loc_F0029420:
          *(undefined4 *)((int)register0x00000038 + -0x20) = 0;
          (*pcVar4)(param_1,uVar2,uVar3);
        }
      }
      else {
        param_1 = (undefined *)0x14;
        if (param_3 == 0) {
          _vn_rele(iVar1);
          uVar2 = *(undefined4 *)((int)register0x00000038 + -0x14);
          uVar3 = *(undefined4 *)(_active_u + 0x1c);
          param_1 = *(undefined **)((int)register0x00000038 + -0x1c);
          pcVar4 = *(code **)(*(int *)(param_1 + 0x1c) + 0x28);
          goto loc_F0029420;
        }
      }
    }
  }
  _pn_free((undefined *)((int)register0x00000038 + -0x18));
  if (*(int *)((int)register0x00000038 + -0x20) != 0) {
    _vn_rele();
  }
  _vn_rele(*(undefined4 *)((int)register0x00000038 + -0x1c));
locret_F0029454:
  return CONCAT44(puVar5,param_1);
}

