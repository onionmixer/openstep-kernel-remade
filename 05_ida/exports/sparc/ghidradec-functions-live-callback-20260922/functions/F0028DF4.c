
/* WARNING: Removing unreachable block (ram,0xf0028fdc) */
/* WARNING: Removing unreachable block (ram,0xf0028edc) */
/* WARNING: Removing unreachable block (ram,0xf0028f20) */
/* WARNING: Removing unreachable block (ram,0xf0028e58) */
/* WARNING: Removing unreachable block (ram,0xf0028e6c) */
/* WARNING: Removing unreachable block (ram,0xf0028f3c) */
/* WARNING: Removing unreachable block (ram,0xf0028f70) */
/* WARNING: Removing unreachable block (ram,0xf0028fe4) */
/* WARNING: Removing unreachable block (ram,0xf0028e0c) */

undefined8
_vn_create(undefined *param_1,undefined4 param_2,int *param_3,int param_4,uint param_5,int *param_6)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
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
  *(undefined4 *)((int)register0x00000038 + -0x1c) = 0;
  *param_6 = 0;
  _pn_get(param_1,param_2,(undefined *)((int)register0x00000038 + -0x18));
  if (param_1 != (undefined *)0x0) goto locret_F0028FEC;
  if ((param_4 == 1) && (*param_3 != 2)) {
    uVar2 = 0;
    piVar3 = (int *)0x0;
  }
  else {
    uVar2 = 1;
    piVar3 = param_6;
  }
  param_1 = (undefined *)((int)register0x00000038 + -0x18);
  _lookuppn(param_1,uVar2,(undefined *)((int)register0x00000038 + -0x1c),piVar3);
  if (param_1 != (undefined *)0x0) {
    _pn_free((undefined *)((int)register0x00000038 + -0x18));
    goto locret_F0028FEC;
  }
  if (*param_6 == 0) {
    iVar1 = *(int *)((int)register0x00000038 + -0x1c);
  }
  else {
    iVar1 = *(int *)((int)register0x00000038 + -0x1c);
    if (*(int *)(*param_6 + 0x28) == 6) {
      param_1 = (undefined *)0x2d;
      goto locret_F0028FEC;
    }
  }
  if ((*(uint *)(*(int *)(iVar1 + 0x24) + 0xc) & 1) == 0) {
loc_F0028EF0:
    if (param_4 == 0) {
      iVar1 = *param_6;
      if (iVar1 != 0) {
        if ((((param_5 & 0x80) != 0) && ((*(word *)(iVar1 + 4) & 2) != 0)) &&
           (_vnode_uncache(iVar1), (*(word *)(*param_6 + 4) & 2) != 0)) {
          param_1 = (undefined *)0x1a;
        }
        _vn_rele(*param_6);
      }
    }
  }
  else {
    iVar1 = *param_6;
    if (iVar1 == 0) {
      param_1 = (undefined *)0x1e;
    }
    else {
      if (*(int *)(iVar1 + 0x28) - 3U < 2) goto loc_F0028EF0;
      param_1 = (undefined *)0x1e;
      if (iVar1 != 0) {
        _vn_rele(iVar1);
        param_1 = (undefined *)0x1e;
      }
    }
  }
  if (param_1 == (undefined *)0x0) {
    param_1 = *(undefined **)((int)register0x00000038 + -0x1c);
    if (*param_3 == 2) {
      if (*param_6 == 0) {
        param_1 = *(undefined **)((int)register0x00000038 + -0x1c);
        (**(code **)(*(int *)(param_1 + 0x1c) + 0x34))
                  (param_1,*(undefined4 *)((int)register0x00000038 + -0x14),param_3,param_6,
                   *(undefined4 *)(_active_u + 0x1c));
      }
      else {
        param_1 = (undefined *)0x11;
        _vn_rele();
      }
    }
    else {
      (**(code **)(*(int *)(param_1 + 0x1c) + 0x24))
                (param_1,*(undefined4 *)((int)register0x00000038 + -0x14),param_3,param_4,param_5,
                 param_6,*(undefined4 *)(_active_u + 0x1c));
    }
  }
  _pn_free((undefined *)((int)register0x00000038 + -0x18));
  _vn_rele(*(undefined4 *)((int)register0x00000038 + -0x1c));
locret_F0028FEC:
  return CONCAT44((undefined *)((int)register0x00000038 + -0x18),param_1);
}

