
/* WARNING: Removing unreachable block (ram,0xf0076144) */
/* WARNING: Removing unreachable block (ram,0xf007611c) */

undefined8
_host_stack_usage(int param_1,undefined4 *param_2,undefined4 *param_3,uint *param_4,uint *param_5,
                 undefined4 *param_6)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 unaff_l0;
  undefined4 *puVar3;
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
  puVar3 = *(undefined4 **)((int)register0x00000038 + 0x5c);
  if (param_1 == 0) {
    uVar4 = 0x16;
  }
  else {
    do {
      do {
      } while (_stack_usage_lock != 0);
      puVar1 = &_stack_usage_lock;
      _simple_lock_try();
    } while (puVar1 == (undefined4 *)0x0);
    _stack_usage_lock = 0;
    *(undefined4 *)((int)register0x00000038 + -0x10) = _stack_max_usage;
    _stack_statistics((undefined *)((int)register0x00000038 + -0xc),
                      (undefined *)((int)register0x00000038 + -0x10));
    *param_2 = 0;
    *param_3 = *(undefined4 *)((int)register0x00000038 + -0xc);
    uVar2 = *(int *)((int)register0x00000038 + -0xc) * 0x3ff4 + _page_mask & ~_page_mask;
    *param_4 = uVar2;
    *param_5 = uVar2;
    uVar4 = 0;
    *param_6 = *(undefined4 *)((int)register0x00000038 + -0x10);
    *puVar3 = 0;
  }
  return CONCAT44(param_2,uVar4);
}
