
/* WARNING: Removing unreachable block (ram,0xf008b640) */
/* WARNING: Removing unreachable block (ram,0xf008b6c0) */
/* WARNING: Removing unreachable block (ram,0xf008b608) */

undefined8 _vnode_pagein(int param_1,undefined4 *param_2)

{
  int *piVar1;
  undefined4 unaff_l0;
  int iVar2;
  undefined4 unaff_l1;
  int *piVar3;
  bool bVar4;
  undefined4 unaff_l3;
  int *piVar5;
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
  piVar5 = *(int **)(*(int *)(param_1 + 0x14) + 0x28);
  piVar3 = piVar5;
  _vnode_pager_vget();
  bVar4 = false;
  iVar2 = *(int *)(param_1 + 0x18) + *(int *)(*(int *)(param_1 + 0x14) + 0x2c);
  if (piVar5[3] < 0) {
    piVar1 = piVar5;
    sub_F008B138(piVar5,iVar2,1,(undefined *)((int)register0x00000038 + -0xc));
    if (piVar1 == (int *)0x5) {
      bVar4 = true;
    }
    else {
      iVar2 = (*(uint *)((int)register0x00000038 + -0xc) & 0xffffff) << ((byte)_page_shift & 0x1f);
      piVar3 = *(int **)(*(int *)(unk_F0130F70 + (uint)*(byte *)((int)register0x00000038 + -0xc) * 4
                                 ) + 8);
    }
  }
  piVar1 = (int *)0x1;
  if ((!bVar4) &&
     (piVar1 = piVar3, (**(code **)(piVar3[7] + 0x74))(piVar3,param_1,iVar2),
     param_2 != (undefined4 *)0x0)) {
    *param_2 = *(undefined4 *)(*piVar3 + 0x34);
  }
  _vnode_pager_vput(piVar5);
  return CONCAT44(param_2,piVar1);
}
