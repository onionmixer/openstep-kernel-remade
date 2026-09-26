
/* WARNING: Removing unreachable block (ram,0xf002777c) */
/* WARNING: Removing unreachable block (ram,0xf0027758) */
/* WARNING: Removing unreachable block (ram,0xf0027788) */
/* WARNING: Removing unreachable block (ram,0xf0027708) */

undefined8 _copen(int param_1,uint param_2,uint param_3)

{
  int iVar1;
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
  int iVar3;
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
  _falloc();
  if (iVar1 == 0) {
    param_1 = (int)*(char *)(dword_F0133DDC + 0x38);
  }
  else {
    iVar3 = *(int *)(dword_F0133DDC + 0x30);
    _vn_open(param_1,0,param_2,param_3 & ~(int)*(sword *)((int)_active_u + 0x16a) & 0xfffU,
             (undefined *)((int)register0x00000038 + -0xc));
    if (param_1 == 0) {
      *(uint *)(iVar1 + 8) = param_2 & 0xa000004b;
      if (((*(uint *)(*_active_u + 0x14) & 0x4000) != 0) &&
         (*(int *)(*(int *)((int)register0x00000038 + -0xc) + 0x28) == 1)) {
        *(uint *)(iVar1 + 8) = param_2 & 0xa000004b | 0x40001000;
      }
      *(undefined2 *)(iVar1 + 0xc) = 1;
      iVar2 = *(int *)((int)register0x00000038 + -0xc);
      *(undefined **)(iVar1 + 0x14) = _vnodefops;
      *(int *)(iVar1 + 0x18) = iVar2;
      if (*(int *)(iVar2 + 0x28) == 8) {
        *(uint *)(iVar1 + 8) = *(uint *)(iVar1 + 8) | param_2 & 4;
      }
      *(int *)(_active_u[0x53] + iVar3 * 4) = iVar1;
    }
    else {
      *(undefined4 *)(_active_u[0x53] + iVar3 * 4) = 0;
      _crfree(*(undefined4 *)(iVar1 + 0x20));
      *(undefined2 *)(iVar1 + 0xe) = 0;
      _free_file(iVar1);
    }
  }
  return CONCAT44(param_2,param_1);
}
