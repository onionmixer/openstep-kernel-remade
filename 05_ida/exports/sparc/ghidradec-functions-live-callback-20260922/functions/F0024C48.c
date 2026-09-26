
/* WARNING: Removing unreachable block (ram,0xf0024ca4) */
/* WARNING: Removing unreachable block (ram,0xf0024c68) */
/* WARNING: Removing unreachable block (ram,0xf0024c80) */
/* WARNING: Removing unreachable block (ram,0xf0024cd0) */
/* WARNING: Removing unreachable block (ram,0xf0024c60) */

undefined8 _geteblk(int param_1,undefined4 param_2)

{
  undefined *puVar1;
  uint *puVar2;
  uint *puVar3;
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
  puVar1 = (undefined *)(uint *)0xf010bc00;
  if (0x2000 < param_1) {
    puVar1 = aGeteblkSizeToo;
    _panic();
  }
  do {
    puVar2 = (uint *)puVar1;
    _getnewbuf();
    *puVar2 = *puVar2 | 0x10000;
    _bfree();
    *(uint *)(puVar2[2] + 4) = puVar2[1];
    *(uint *)(puVar2[1] + 8) = puVar2[2];
    sub_F0025690(puVar2);
    *(undefined2 *)(puVar2 + 7) = 0;
    puVar2[10] = 0;
    puVar2[1] = DAT_f0133e6c._0_4_;
    puVar2[2] = (uint)unk_F0133E68;
    *(uint **)(DAT_f0133e6c._0_4_ + 8) = puVar2;
    puVar3 = puVar2;
    DAT_f0133e6c._0_4_ = puVar2;
    _brealloc(puVar2,param_1);
    puVar1 = (undefined *)(uint *)0x0;
  } while (puVar3 == (uint *)0x0);
  return CONCAT44(param_2,puVar2);
}

