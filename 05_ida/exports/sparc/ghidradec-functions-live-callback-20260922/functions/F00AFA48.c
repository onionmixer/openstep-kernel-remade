
/* WARNING: Removing unreachable block (ram,0xf00afaa0) */
/* WARNING: Removing unreachable block (ram,0xf00afa80) */
/* WARNING: Removing unreachable block (ram,0xf00afae0) */
/* WARNING: Removing unreachable block (ram,0xf00afa64) */

undefined8 _prom_printn(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 unaff_l0;
  char *pcVar2;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  int iVar3;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  char acStack_30 [48];
  
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
  if ((param_2 == 10) && (param_1 < 0)) {
    _prom_putchar(0x2d);
    param_1 = -param_1;
  }
  pcVar2 = (char *)((int)register0x00000038 + -0x30);
  do {
    iVar3 = param_3;
    iVar1 = param_1;
    urem(param_1,param_2);
    param_3 = iVar3 + -1;
    *pcVar2 = a0123456789abcd_4[iVar1];
    pcVar2 = pcVar2 + 1;
    udiv(param_1,param_2);
  } while (param_1 != 0);
  iVar1 = iVar3 + -2;
  while (iVar3 = iVar1, 0 < param_3) {
    *pcVar2 = '0';
    pcVar2 = pcVar2 + 1;
    iVar1 = iVar3 + -1;
    param_3 = iVar3;
  }
  do {
    pcVar2 = pcVar2 + -1;
    _prom_putchar((int)*pcVar2);
  } while ((char *)((int)register0x00000038 + -0x30) < pcVar2);
  return CONCAT44(param_2,(char *)((int)register0x00000038 + -0x30));
}

