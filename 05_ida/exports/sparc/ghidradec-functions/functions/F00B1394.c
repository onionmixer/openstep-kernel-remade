
/* WARNING: Removing unreachable block (ram,0xf00b1400) */
/* WARNING: Removing unreachable block (ram,0xf00b13d8) */
/* WARNING: Removing unreachable block (ram,0xf00b13f4) */
/* WARNING: Removing unreachable block (ram,0xf00b13a4) */

undefined8 _idprom(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  undefined4 unaff_l0;
  byte *pbVar3;
  undefined4 unaff_l1;
  byte bVar4;
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
  byte abStack_28 [40];
  
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
  bVar4 = 0;
  pbVar3 = (byte *)((int)register0x00000038 + -0x28);
  _prom_getidprom(pbVar3,0x20);
  iVar2 = 0xf;
  do {
    iVar2 = iVar2 + -1;
    bVar4 = bVar4 ^ *pbVar3;
    pbVar3 = pbVar3 + 1;
  } while (-1 < iVar2);
  if (bVar4 == 0) {
    cVar1 = *(char *)((int)register0x00000038 + -0x28);
  }
  else {
    _printf(aWarningNvramCh);
    cVar1 = *(char *)((int)register0x00000038 + -0x28);
  }
  if (cVar1 == '\x01') {
    _localetheraddr((undefined *)((int)register0x00000038 + -0x26),0);
  }
  else {
    _printf(aInvalidFormatC);
  }
  return CONCAT44(param_2,param_1);
}
