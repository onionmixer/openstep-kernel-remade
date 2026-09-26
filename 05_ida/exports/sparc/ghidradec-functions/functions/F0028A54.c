
/* WARNING: Removing unreachable block (ram,0xf0028af0) */
/* WARNING: Removing unreachable block (ram,0xf0028afc) */
/* WARNING: Removing unreachable block (ram,0xf0028ad4) */

undefined8
_vn_rdwr(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
        undefined4 param_6)

{
  undefined4 unaff_l0;
  undefined4 uVar1;
  undefined4 unaff_l1;
  int *piVar2;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
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
  uVar1 = *(undefined4 *)((int)register0x00000038 + 0x5c);
  piVar2 = *(int **)((int)register0x00000038 + 0x60);
  if (param_1 == 1) {
    if ((*(uint *)(*(int *)(param_2 + 0x24) + 0xc) & 1) != 0) {
      iVar3 = 0x1e;
      goto locret_F0028B5C;
    }
    *(undefined4 *)((int)register0x00000038 + -0x28) = param_3;
  }
  else {
    *(undefined4 *)((int)register0x00000038 + -0x28) = param_3;
  }
  *(undefined4 *)((int)register0x00000038 + -0x24) = param_4;
  *(undefined **)((int)register0x00000038 + -0x20) = (undefined *)((int)register0x00000038 + -0x28);
  *(undefined4 *)((int)register0x00000038 + -0x1c) = 1;
  *(qword *)((int)register0x00000038 + -0x18) = CONCAT44(param_5,param_6);
  *(undefined4 *)((int)register0x00000038 + -0xc) = param_4;
  iVar3 = param_2;
  if ((*(int *)(param_2 + 0x28) == 1) && ((*(uint *)(*_active_u + 0x14) & 0x4000) == 0)) {
    _map_vnode(param_2);
    _mfs_io(param_2,(undefined *)((int)register0x00000038 + -0x20),param_1,uVar1,_active_u[7]);
    _unmap_vnode(param_2);
  }
  else {
    (**(code **)(*(int *)(param_2 + 0x1c) + 8))
              (param_2,(undefined *)((int)register0x00000038 + -0x20),param_1,uVar1,_active_u[7]);
  }
  if (piVar2 == (int *)0x0) {
    if ((*(int *)((int)register0x00000038 + -0xc) != 0) && (iVar3 == 0)) {
      iVar3 = 5;
    }
  }
  else {
    *piVar2 = *(int *)((int)register0x00000038 + -0xc);
  }
locret_F0028B5C:
  return CONCAT44(param_2,iVar3);
}
