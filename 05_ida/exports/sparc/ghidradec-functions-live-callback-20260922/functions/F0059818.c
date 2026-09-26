
/* WARNING: Removing unreachable block (ram,0xf0059898) */
/* WARNING: Removing unreachable block (ram,0xf005984c) */
/* WARNING: Removing unreachable block (ram,0xf0059864) */
/* WARNING: Removing unreachable block (ram,0xf005982c) */

undefined8
_ipc_object_alloc(int param_1,int param_2,uint param_3,uint param_4,undefined4 param_5,
                 undefined4 *param_6)

{
  int *piVar1;
  uint *puVar2;
  int *piVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar4;
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
  piVar1 = (int *)(&_ipc_object_zones)[param_2];
  _zalloc();
  if (piVar1 == (int *)0x0) {
    iVar4 = 6;
  }
  else {
    iVar4 = param_1;
    _ipc_entry_alloc(param_1,param_5,(undefined *)((int)register0x00000038 + -0xc));
    puVar2 = *(uint **)((int)register0x00000038 + -0xc);
    if (iVar4 == 0) {
      puVar2[1] = (uint)piVar1;
      *puVar2 = *puVar2 | param_3 | param_4;
      *piVar1 = 0;
      do {
        do {
        } while (*piVar1 != 0);
        piVar3 = piVar1;
        _simple_lock_try();
      } while (piVar3 == (int *)0x0);
      *(undefined4 *)(param_1 + 8) = 0;
      piVar1[1] = 1;
      piVar1[2] = param_2 << 0x10 | 0x80000000;
      *param_6 = piVar1;
      iVar4 = 0;
    }
    else {
      _zfree((&_ipc_object_zones)[param_2],piVar1);
    }
  }
  return CONCAT44(param_2,iVar4);
}

