
/* WARNING: Removing unreachable block (ram,0xf0024f80) */
/* WARNING: Removing unreachable block (ram,0xf0024fc4) */
/* WARNING: Removing unreachable block (ram,0xf0024f94) */
/* WARNING: Removing unreachable block (ram,0xf0024f9c) */
/* WARNING: Removing unreachable block (ram,0xf0024fe0) */
/* WARNING: Removing unreachable block (ram,0xf0024f88) */
/* WARNING: Removing unreachable block (ram,0xf0024f20) */

undefined8 _getnewbuf(uint *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  while( true ) {
    while( true ) {
      _splusclock();
      puVar1 = (undefined4 *)DAT_f0133e74._0_4_;
      puVar2 = (undefined4 *)unk_F0133E68;
      while ((puVar3 = puVar2, puVar1 == puVar2 && (puVar3 = puVar2 + -0x11, &_bfreelist < puVar3)))
      {
        puVar1 = (undefined4 *)puVar2[-0xe];
        puVar2 = puVar3;
      }
      if (puVar3 != &_bfreelist) break;
      _bfreelist = _bfreelist | 0x40;
      _sleep(&_bfreelist,0x15);
      _splx(param_1);
    }
    _splx(param_1);
    param_1 = (uint *)puVar3[3];
    _spltty();
    *(uint *)(param_1[4] + 0xc) = param_1[3];
    *(uint *)(param_1[3] + 0x10) = param_1[4];
    *param_1 = *param_1 | 8;
    _splx();
    if ((*param_1 & 0x200) == 0) break;
    *param_1 = *param_1 | 0x100;
    _bwrite();
  }
  *param_1 = 8;
  return CONCAT44(param_2,param_1);
}
