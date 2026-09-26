
/* WARNING: Removing unreachable block (ram,0xf0028dc8) */
/* WARNING: Removing unreachable block (ram,0xf0028c28) */
/* WARNING: Removing unreachable block (ram,0xf0028cb0) */
/* WARNING: Removing unreachable block (ram,0xf0028be8) */
/* WARNING: Removing unreachable block (ram,0xf0028d6c) */
/* WARNING: Removing unreachable block (ram,0xf0028ddc) */
/* WARNING: Removing unreachable block (ram,0xf0028c4c) */

undefined8
_vn_open(undefined *param_1,undefined4 param_2,uint param_3,undefined2 param_4,undefined4 *param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar4;
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
  uVar4 = (param_3 & 1) << 8;
  if ((param_3 & 0x402) != 0) {
    uVar4 = uVar4 | 0x80;
  }
  if ((param_3 & 0x200) == 0) {
    _lookupname(param_1,param_2,1,0,(undefined *)((int)register0x00000038 + -0x4c));
    if (param_1 != (undefined *)0x0) goto locret_F0028DEC;
    if ((param_3 & 0x402) == 0) goto loc_F0028CD0;
    iVar2 = *(int *)(*(int *)((int)register0x00000038 + -0x4c) + 0x28);
    if (iVar2 == 2) {
      param_1 = (undefined *)0x15;
    }
    else if (((*(uint *)(*(int *)(*(int *)((int)register0x00000038 + -0x4c) + 0x24) + 0xc) & 1) == 0
             ) || (param_1 = (undefined *)0x1e, iVar2 - 3U < 2)) {
      if ((*(word *)(*(int *)((int)register0x00000038 + -0x4c) + 4) & 2) != 0) {
        _vnode_uncache(*(int *)((int)register0x00000038 + -0x4c));
        param_1 = (undefined *)0x1a;
        if ((*(word *)(*(int *)((int)register0x00000038 + -0x4c) + 4) & 2) != 0) goto loc_F0028DD0;
      }
loc_F0028CD0:
      param_1 = *(undefined **)((int)register0x00000038 + -0x4c);
      (**(code **)(*(int *)(param_1 + 0x1c) + 0x1c))
                (param_1,uVar4,*(undefined4 *)(_active_u + 0x1c));
      bVar5 = param_1 == (undefined *)0x0;
      iVar2 = *(int *)((int)register0x00000038 + -0x4c);
      if (!bVar5) goto loc_F0028DD4;
      iVar1 = *(int *)(iVar2 + 0x28);
      if ((*(uint *)(*(int *)(iVar2 + 0x24) + 0xc) & 8) == 0) goto loc_F0028D20;
      param_1 = (undefined *)0x1;
      if (1 < iVar1 - 3U) goto loc_F0028D1C;
    }
loc_F0028DD0:
    bVar5 = param_1 == (undefined *)0x0;
  }
  else {
    _vattr_null((undefined *)((int)register0x00000038 + -0x48));
    *(undefined4 *)((int)register0x00000038 + -0x48) = 1;
    *(undefined2 *)((int)register0x00000038 + -0x44) = param_4;
    if ((param_3 & 0x400) != 0) {
      *(undefined4 *)((int)register0x00000038 + -0x30) = 0;
    }
    uVar3 = param_3 & 0x800;
    param_3 = param_3 & 0xfffff1ff;
    _vn_create(param_1,param_2,(undefined *)((int)register0x00000038 + -0x48),uVar3 != 0,uVar4,
               (undefined *)((int)register0x00000038 + -0x4c));
    iVar2 = *(int *)((int)register0x00000038 + -0x4c);
    if (param_1 != (undefined *)0x0) goto locret_F0028DEC;
loc_F0028D1C:
    iVar1 = *(int *)(iVar2 + 0x28);
loc_F0028D20:
    if (iVar1 == 6) {
      param_1 = (undefined *)0x2d;
      goto loc_F0028DD0;
    }
    param_1 = (undefined *)((int)register0x00000038 + -0x4c);
    (*(code *)**(undefined4 **)(iVar2 + 0x1c))(param_1,param_3,*(undefined4 *)(_active_u + 0x1c));
    bVar5 = false;
    if (param_1 == (undefined *)0x0) {
      if ((param_3 & 0x400) != 0) {
        _vattr_null((undefined *)((int)register0x00000038 + -0x90));
        *(undefined4 *)((int)register0x00000038 + -0x78) = 0;
        param_1 = *(undefined **)((int)register0x00000038 + -0x4c);
        param_3 = param_3 & 0xfffffbff;
        (**(code **)(*(int *)(param_1 + 0x1c) + 0x18))
                  (param_1,(undefined *)((int)register0x00000038 + -0x90),
                   *(undefined4 *)(_active_u + 0x1c));
      }
      bVar5 = param_1 == (undefined *)0x0;
      if ((param_1 == (undefined *)0x0) && (bVar5 = true, (param_3 & 0x40000000) == 0)) {
        bVar5 = true;
        if (*(int *)(*(int *)((int)register0x00000038 + -0x4c) + 0x28) == 1) {
          _map_vnode(*(int *)((int)register0x00000038 + -0x4c));
          goto loc_F0028DD0;
        }
      }
    }
  }
loc_F0028DD4:
  if (bVar5) {
    *param_5 = *(undefined4 *)((int)register0x00000038 + -0x4c);
  }
  else {
    _vn_rele(*(undefined4 *)((int)register0x00000038 + -0x4c));
  }
locret_F0028DEC:
  return CONCAT44(param_2,param_1);
}
