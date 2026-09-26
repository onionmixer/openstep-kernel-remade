
/* WARNING: Removing unreachable block (ram,0xf00254bc) */
/* WARNING: Removing unreachable block (ram,0xf00254a4) */
/* WARNING: Removing unreachable block (ram,0xf0025494) */
/* WARNING: Removing unreachable block (ram,0xf002546c) */
/* WARNING: Removing unreachable block (ram,0xf002549c) */
/* WARNING: Removing unreachable block (ram,0xf00254b4) */
/* WARNING: Removing unreachable block (ram,0xf00254ec) */
/* WARNING: Removing unreachable block (ram,0xf00253f8) */

undefined8 _binvalfree(uint *param_1,undefined4 param_2)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  uint *puVar4;
  undefined4 unaff_l0;
  uint *puVar5;
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
  
  puVar1 = param_1;
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
    puVar1 = param_1;
  }
loc_F00253F8:
  _splusclock();
  puVar4 = &_bfreelist;
  puVar5 = (uint *)DAT_f0133dec._0_4_;
  do {
    if (puVar5 != puVar4) {
      puVar2 = (uint *)puVar5[0x10];
      while( true ) {
        if ((puVar1 == puVar2) || (puVar1 == (uint *)0x0)) {
          uVar3 = *puVar5;
          if ((uVar3 & 0x200) == 0) {
            *puVar5 = uVar3 | 0x10000;
            sub_F0025690(puVar5);
            _splx(param_1);
          }
          else {
            puVar5[0xc] = (uint)_brelvp_wakeup;
            *puVar5 = uVar3 | 0x200100;
            _spltty();
            *(uint *)(puVar5[4] + 0xc) = puVar5[3];
            *(uint *)(puVar5[3] + 0x10) = puVar5[4];
            *puVar5 = *puVar5 | 8;
            _splx();
            _splx(param_1);
            _bwrite();
            param_1 = puVar5;
          }
          goto loc_F00253F8;
        }
        puVar5 = (uint *)puVar5[3];
        if (puVar5 == puVar4) break;
        puVar2 = (uint *)puVar5[0x10];
      }
    }
    if (&DAT_f0133eab < puVar4 + 0x11) {
      _splx(param_1);
      return CONCAT44(param_2,puVar1);
    }
    puVar5 = (uint *)puVar4[0x14];
    puVar4 = puVar4 + 0x11;
  } while( true );
}

