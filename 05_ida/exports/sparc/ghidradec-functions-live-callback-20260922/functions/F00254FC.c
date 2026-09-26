
/* WARNING: Removing unreachable block (ram,0xf0025568) */
/* WARNING: Removing unreachable block (ram,0xf0025560) */
/* WARNING: Removing unreachable block (ram,0xf0025590) */
/* WARNING: Removing unreachable block (ram,0xf0025500) */

undefined8 _btrash(uint param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  uint *puVar4;
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
  
  uVar1 = param_1;
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
    uVar1 = param_1;
  }
loc_F0025500:
  _splusclock();
  puVar3 = &_bfreelist;
  puVar4 = (uint *)DAT_f0133dec._0_4_;
  do {
    if (puVar4 != puVar3) {
      uVar2 = puVar4[0x10];
      while( true ) {
        if ((uVar1 == uVar2) || (uVar1 == 0)) {
          *puVar4 = *puVar4 & 0xfffffdff | 0x10000;
          sub_F0025690();
          _splx(param_1);
          goto loc_F0025500;
        }
        puVar4 = (uint *)puVar4[3];
        if (puVar4 == puVar3) break;
        uVar2 = puVar4[0x10];
      }
    }
    if (&DAT_f0133eab < puVar3 + 0x11) {
      _splx(param_1);
      return CONCAT44(param_2,uVar1);
    }
    puVar4 = (uint *)puVar3[0x14];
    puVar3 = puVar3 + 0x11;
  } while( true );
}

