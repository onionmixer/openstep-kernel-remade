
/* WARNING: Removing unreachable block (ram,0xf008b800) */
/* WARNING: Removing unreachable block (ram,0xf008b764) */
/* WARNING: Removing unreachable block (ram,0xf008b750) */
/* WARNING: Removing unreachable block (ram,0xf008b80c) */
/* WARNING: Removing unreachable block (ram,0xf008b814) */
/* WARNING: Removing unreachable block (ram,0xf008b6e0) */

undefined8 _vnode_pageout(int param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int *piVar3;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar4;
  int *piVar5;
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
  piVar3 = *(int **)(*(int *)(param_1 + 0x14) + 0x28);
  piVar5 = piVar3;
  _vnode_pager_vget();
  uVar2 = *(int *)(param_1 + 0x18) + *(int *)(*(int *)(param_1 + 0x14) + 0x2c);
  iVar4 = _page_size;
  if (((-1 < piVar3[3]) && (uVar1 = *(uint *)(*piVar5 + 0x14), uVar1 < uVar2 + _page_size)) &&
     (iVar4 = 0, uVar2 <= uVar1)) {
    iVar4 = uVar1 - uVar2;
  }
  if (piVar3[3] < 0) {
    piVar5 = piVar3;
    sub_F008B138(piVar3,uVar2,0,(undefined *)((int)register0x00000038 + -0xc));
    if (piVar5 == (int *)0x5) {
      _vnode_pager_vput(piVar3);
      piVar5 = (int *)0x2;
      goto locret_F008B81C;
    }
    piVar5 = *(int **)(*(int *)(unk_F0130F70 + (uint)*(byte *)((int)register0x00000038 + -0xc) * 4)
                      + 8);
    uVar2 = (*(uint *)((int)register0x00000038 + -0xc) & 0xffffff) << ((byte)_page_shift & 0x1f);
    if (*(uint *)(*piVar5 + 0x14) < uVar2 + iVar4) {
      *(uint *)(*piVar5 + 0x14) = uVar2 + iVar4;
    }
  }
  if (iVar4 == 0) {
    piVar5 = (int *)0x0;
  }
  else {
    (**(code **)(piVar5[7] + 0x78))(piVar5,*(undefined4 *)(param_1 + 0x24),iVar4,uVar2);
  }
  if (piVar5 == (int *)0x0) {
    *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) | 0x400;
    _pmap_clear_modify(*(undefined4 *)(param_1 + 0x24));
  }
  else {
    _printf(aVnodePageoutFa);
  }
  _vnode_pager_vput(piVar3);
locret_F008B81C:
  return CONCAT44(param_2,piVar5);
}

