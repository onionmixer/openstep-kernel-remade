
/* WARNING: Removing unreachable block (ram,0xf0077684) */
/* WARNING: Removing unreachable block (ram,0xf007766c) */
/* WARNING: Removing unreachable block (ram,0xf0077618) */
/* WARNING: Removing unreachable block (ram,0xf0077678) */
/* WARNING: Removing unreachable block (ram,0xf0077698) */
/* WARNING: Removing unreachable block (ram,0xf00775f8) */

undefined8 sub_F00775F0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
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
  
  iVar1 = _active_threads;
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
  _splusclock();
  do {
    do {
    } while (dword_F0130F20 != 0);
    puVar2 = &dword_F0130F20;
    _simple_lock_try();
  } while (puVar2 == (undefined4 *)0x0);
  if (dword_F0130F44 < dword_F0130F40 + dword_F0130F3C) {
    dword_F0130F44 = dword_F0130F44 + 1;
    dword_F0130F20 = 0;
    _kernel_thread(*(undefined4 *)(iVar1 + 0xc),sub_F00775D0,0);
    _thread_block_with_continuation(sub_F00775F0);
  }
  _assert_wait(&dword_F0130F44,0);
  dword_F0130F20 = 0;
  _thread_block_with_continuation(sub_F00775F0);
  return CONCAT44(param_2,param_1);
}
