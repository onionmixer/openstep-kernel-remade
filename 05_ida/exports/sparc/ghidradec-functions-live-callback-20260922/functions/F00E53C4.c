
/* WARNING: Removing unreachable block (ram,0xf00e5518) */
/* WARNING: Removing unreachable block (ram,0xf00e54b4) */
/* WARNING: Removing unreachable block (ram,0xf00e5460) */
/* WARNING: Removing unreachable block (ram,0xf00e542c) */
/* WARNING: Removing unreachable block (ram,0xf00e541c) */
/* WARNING: Removing unreachable block (ram,0xf00e5440) */
/* WARNING: Removing unreachable block (ram,0xf00e5490) */
/* WARNING: Removing unreachable block (ram,0xf00e54e4) */
/* WARNING: Removing unreachable block (ram,0xf00e553c) */
/* WARNING: Removing unreachable block (ram,0xf00e53f0) */

sqword _cg6ConfigDisplay(int param_1,uint param_2)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
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
  puVar3 = (undefined4 *)(_sparcfbs + param_1 * 0x44 + 8);
  uVar1 = param_2;
  _prom_getproplen(param_2,&aAddress);
  if (0 < (int)uVar1) {
    _prom_getprop(param_2,&aAddress,(undefined *)((int)register0x00000038 + -0x1c));
  }
  _prom_getprop(param_2,&aReg,(undefined *)((int)register0x00000038 + -0x18));
  *puVar3 = 1;
  puVar3[1] = 0;
  uVar1 = param_2;
  _prom_getproplen(param_2,&aWidth);
  if (uVar1 == 0) {
    uVar2 = 1;
  }
  else if ((int)uVar1 < 1) {
    uVar2 = 0x480;
  }
  else if (uVar1 == 4) {
    _prom_getprop(param_2,&aWidth,(undefined *)((int)register0x00000038 + -0x24));
    uVar2 = *(undefined4 *)((int)register0x00000038 + -0x24);
  }
  else {
    uVar2 = 0x480;
  }
  puVar3[8] = uVar2;
  uVar1 = param_2;
  _prom_getproplen(param_2,&aHeight);
  if (uVar1 == 0) {
    uVar2 = 1;
  }
  else if ((int)uVar1 < 1) {
    uVar2 = 900;
  }
  else if (uVar1 == 4) {
    _prom_getprop(param_2,&aHeight,(undefined *)((int)register0x00000038 + -0x24));
    uVar2 = *(undefined4 *)((int)register0x00000038 + -0x24);
  }
  else {
    uVar2 = 900;
  }
  puVar3[9] = uVar2;
  puVar3[5] = *(undefined4 *)((int)register0x00000038 + -0x1c);
  puVar3[6] = *(undefined4 *)((int)register0x00000038 + -0x1c);
  puVar3[3] = 0;
  uVar2 = puVar3[8];
  umul(uVar2,puVar3[9]);
  puVar3[7] = uVar2;
  puVar3[0xc] = 8;
  puVar3[0xd] = 1;
  uVar2 = puVar3[8];
  umul(uVar2,puVar3[0xd]);
  puVar3[0xe] = uVar2;
  return (qword)param_2 << 0x20;
}

