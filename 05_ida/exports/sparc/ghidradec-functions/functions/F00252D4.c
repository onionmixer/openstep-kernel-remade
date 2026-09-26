
/* WARNING: Removing unreachable block (ram,0xf00253a0) */
/* WARNING: Removing unreachable block (ram,0xf0025390) */
/* WARNING: Removing unreachable block (ram,0xf0025368) */
/* WARNING: Removing unreachable block (ram,0xf0025398) */
/* WARNING: Removing unreachable block (ram,0xf00253c8) */
/* WARNING: Removing unreachable block (ram,0xf00252d8) */

undefined8 _bflush(uint *param_1,undefined4 param_2,word param_3)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  undefined4 unaff_l0;
  uint *puVar4;
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
loc_F00252D8:
  _splusclock();
  puVar4 = (uint *)DAT_f0133dec._0_4_;
  puVar2 = &_bfreelist;
joined_r0xf002530c:
  do {
    while( true ) {
      while (puVar4 == puVar2) {
        if (&DAT_f0133eab < puVar2 + 0x11) {
          _splx(param_1);
          return CONCAT44(param_2,puVar1);
        }
        puVar4 = (uint *)puVar2[0x14];
        puVar2 = puVar2 + 0x11;
      }
      if ((word)param_2 == 0xffff) break;
      if ((word)param_2 == (*(word *)((int)puVar4 + 0x1e) & param_3)) {
        uVar3 = *puVar4;
        goto loc_F0025340;
      }
      puVar4 = (uint *)puVar4[3];
    }
    uVar3 = *puVar4;
loc_F0025340:
    if ((uVar3 & 0x200) == 0) {
      puVar4 = (uint *)puVar4[3];
      goto joined_r0xf002530c;
    }
    if ((puVar1 == (uint *)puVar4[0x10]) || (puVar1 == (uint *)0x0)) break;
    puVar4 = (uint *)puVar4[3];
  } while( true );
  *puVar4 = uVar3 | 0x100;
  _spltty();
  *(uint *)(puVar4[4] + 0xc) = puVar4[3];
  *(uint *)(puVar4[3] + 0x10) = puVar4[4];
  *puVar4 = *puVar4 | 8;
  _splx();
  _splx(param_1);
  _bwrite();
  param_1 = puVar4;
  goto loc_F00252D8;
}
