
/* WARNING: Removing unreachable block (ram,0xf0047158) */
/* WARNING: Removing unreachable block (ram,0xf0047178) */
/* WARNING: Removing unreachable block (ram,0xf00471b8) */

undefined8 sub_F0047104(undefined4 *param_1,undefined4 param_2)

{
  word wVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
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
  if (_fifo_alloc < dword_F010F3A0) {
    _fifo_alloc = _fifo_alloc + dword_F010F39C;
    _kmem_alloc_wired(_kernel_map,(undefined *)((int)register0x00000038 + -0xc));
    uVar3 = *(undefined4 *)((int)register0x00000038 + -0xc);
    *(sword *)((int)param_1 + 0x8a) = *(sword *)((int)param_1 + 0x8a) + 1;
  }
  else {
    wVar1 = *(word *)(param_1 + 0x10);
    *(word *)(param_1 + 0x10) = wVar1 & 0xfffe;
    if ((wVar1 & 0x10) != 0) {
      *(word *)(param_1 + 0x10) = wVar1 & 0xffee;
      _wakeup(param_1);
    }
    uVar3 = 0x1a;
    puVar2 = &_fifo_alloc;
    while( true ) {
      _sleep(puVar2,uVar3);
      if ((*(word *)(param_1 + 0x10) & 1) == 0) break;
      *(word *)(param_1 + 0x10) = *(word *)(param_1 + 0x10) | 0x10;
      uVar3 = 10;
      puVar2 = param_1;
    }
    uVar3 = 0;
    *(word *)(param_1 + 0x10) = *(word *)(param_1 + 0x10) | 1;
  }
  return CONCAT44(param_2,uVar3);
}
