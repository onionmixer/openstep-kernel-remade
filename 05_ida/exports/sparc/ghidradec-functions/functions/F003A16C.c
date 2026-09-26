
/* WARNING: Removing unreachable block (ram,0xf003a26c) */
/* WARNING: Removing unreachable block (ram,0xf003a1d0) */
/* WARNING: Removing unreachable block (ram,0xf003a254) */
/* WARNING: Removing unreachable block (ram,0xf003a240) */
/* WARNING: Removing unreachable block (ram,0xf003a1bc) */

undefined8 _findexivp(int *param_1,int param_2,int param_3)

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
  int iVar2;
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
  *(int *)((int)register0x00000038 + 0x48) = param_2;
  *(sword *)(param_3 + 6) = *(sword *)(param_3 + 6) + 1;
  if (param_2 != 0) {
    *(sword *)(param_2 + 6) = *(sword *)(param_2 + 6) + 1;
  }
  while( true ) {
    iVar2 = param_3;
    (**(code **)(*(int *)(param_3 + 0x1c) + 100))
              (param_3,(undefined *)((int)register0x00000038 + -0xc));
    if (iVar2 != 0) break;
    iVar1 = *(int *)(param_3 + 0x24) + 0x14;
    _findexport(iVar1,*(undefined4 *)((int)register0x00000038 + -0xc));
    *param_1 = iVar1;
    _kfree(*(word **)((int)register0x00000038 + -0xc),
           **(word **)((int)register0x00000038 + -0xc) + 2);
    if (((*param_1 != 0) || (iVar2 = 0x16, (*(word *)(param_3 + 4) & 1) != 0)) ||
       ((*(int *)((int)register0x00000038 + 0x48) == 0 &&
        (iVar2 = param_3,
        (**(code **)(*(int *)(param_3 + 0x1c) + 0x20))
                  (param_3,&unk_F010C9E8,(undefined *)((int)register0x00000038 + 0x48),
                   *(undefined4 *)(_active_u + 0x1c),0,0), iVar2 != 0)))) break;
    _vn_rele(param_3);
    param_3 = *(int *)((int)register0x00000038 + 0x48);
    *(undefined4 *)((int)register0x00000038 + 0x48) = 0;
  }
  _vn_rele(param_3);
  if (*(int *)((int)register0x00000038 + 0x48) != 0) {
    _vn_rele();
  }
  return CONCAT44(param_2,iVar2);
}
