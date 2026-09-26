
/* WARNING: Removing unreachable block (ram,0xf001b81c) */
/* WARNING: Removing unreachable block (ram,0xf001b800) */
/* WARNING: Removing unreachable block (ram,0xf001b7cc) */
/* WARNING: Removing unreachable block (ram,0xf001b7b0) */
/* WARNING: Removing unreachable block (ram,0xf001b7a8) */
/* WARNING: Removing unreachable block (ram,0xf001b7c4) */
/* WARNING: Removing unreachable block (ram,0xf001b7e0) */
/* WARNING: Removing unreachable block (ram,0xf001b808) */
/* WARNING: Removing unreachable block (ram,0xf001b824) */
/* WARNING: Removing unreachable block (ram,0xf001b788) */

undefined8 _ptcwakeup(int param_1,uint param_2)

{
  undefined *puVar1;
  undefined4 unaff_l0;
  uint *puVar2;
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
  puVar1 = unk_F012F204;
  puVar2 = *(uint **)(unk_F012F204 + (*(word *)(param_1 + 0x38) & 0xff) * 0x10 + 0xc);
  if (*(word *)(param_1 + 0x38) != 0) {
    if ((param_2 & 1) != 0) {
      _spltty();
      if (puVar2[1] != 0) {
        _selwakeup(puVar2[1],*puVar2 & 1);
        _selthreadclear(puVar2 + 1);
        *puVar2 = *puVar2 & 0xfffffffe;
      }
      _splx(puVar1);
      puVar1 = (undefined *)(param_1 + 0x1c);
      _wakeup(puVar1);
    }
    if ((param_2 & 2) != 0) {
      _spltty();
      if (puVar2[2] != 0) {
        _selwakeup(puVar2[2],*puVar2 & 2);
        _selthreadclear(puVar2 + 2);
        *puVar2 = *puVar2 & 0xfffffffd;
      }
      _splx(puVar1);
      _wakeup(param_1 + 4);
    }
  }
  return CONCAT44(param_2,param_1);
}

