
/* WARNING: Removing unreachable block (ram,0xf00af98c) */
/* WARNING: Removing unreachable block (ram,0xf00af9c0) */
/* WARNING: Removing unreachable block (ram,0xf00afa08) */
/* WARNING: Removing unreachable block (ram,0xf00af7bc) */
/* WARNING: Removing unreachable block (ram,0xf00afa10) */
/* WARNING: Removing unreachable block (ram,0xf00af9c8) */
/* WARNING: Removing unreachable block (ram,0xf00afa30) */
/* WARNING: Removing unreachable block (ram,0xf00af7b4) */

char * _prom_printf(char *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5,undefined4 param_6)

{
  uint uVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  int iVar2;
  undefined4 unaff_i2;
  int iVar3;
  byte bVar5;
  char *pcVar4;
  undefined4 unaff_i3;
  undefined4 uVar6;
  undefined4 unaff_i4;
  int *piVar7;
  int *piVar8;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [72];
  int aiStackX_48 [5];
  
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
  *(undefined4 *)((int)register0x00000038 + 0x48) = param_2;
  *(undefined4 *)((int)register0x00000038 + 0x4c) = param_3;
  *(undefined4 *)((int)register0x00000038 + 0x50) = param_4;
  *(undefined4 *)((int)register0x00000038 + 0x54) = param_5;
  *(undefined4 *)((int)register0x00000038 + 0x58) = param_6;
  piVar7 = (int *)((int)register0x00000038 + 0x48);
loc_F00AF794:
  iVar2 = (int)*param_1;
  piVar8 = piVar7;
def_F00AF814:
  iVar3 = 0;
  while (param_1 = param_1 + 1, pcVar4 = param_1, iVar2 != 0x25) {
    if (iVar2 == 0) {
      return param_1;
    }
    if (iVar2 == 10) {
      _prom_putchar(0xd);
    }
    _prom_putchar(iVar2);
    iVar2 = (int)*param_1;
  }
loc_F00AF7D4:
  iVar2 = (int)*pcVar4;
  param_1 = pcVar4 + 1;
  if (iVar2 - 0x32U < 8) {
    iVar3 = iVar2 + -0x30;
    iVar2 = (int)*param_1;
    param_1 = pcVar4 + 2;
  }
  pcVar4 = param_1;
  piVar7 = piVar8;
  switch(iVar2) {
  case :
    goto loc_F00AFA30;
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
    goto loc_F00AF794;
  case :
  case :
  case :
    uVar6 = 10;
    break;
  case :
  case :
    uVar6 = 8;
    break;
  case :
  case :
    uVar6 = 0x10;
    break;
  case :
    iVar3 = *piVar8;
    iVar2 = 0x18;
    bVar5 = 0x18;
    do {
      uVar1 = iVar3 >> bVar5 & 0x7f;
      if (uVar1 != 0) {
        if (uVar1 == 10) {
          _prom_putchar(0xd);
        }
        _prom_putchar(uVar1);
      }
      iVar2 = iVar2 + -8;
      bVar5 = (byte)iVar2 & 0x1f;
    } while (-1 < iVar2);
    iVar2 = (int)*param_1;
    piVar8 = piVar8 + 1;
    goto def_F00AF814;
  case :
    goto loc_F00AF7D4;
  case :
    piVar7 = piVar8 + 1;
    pcVar4 = (char *)*piVar8;
    iVar2 = (int)*pcVar4;
    if (iVar2 != 0) goto loc_F00AF9FC;
    goto loc_F00AF794;
  :
    goto loc_f00af7fc;
  }
  _prom_printn(*piVar8,uVar6,iVar3);
  iVar2 = (int)*param_1;
  piVar8 = piVar8 + 1;
  goto def_F00AF814;
loc_f00af7fc:
  iVar2 = (int)*param_1;
  goto def_F00AF814;
loc_F00AF9FC:
  do {
    pcVar4 = pcVar4 + 1;
    if (iVar2 == 10) {
      _prom_putchar(0xd);
    }
    _prom_putchar(iVar2);
    iVar2 = (int)*pcVar4;
  } while (iVar2 != 0);
  iVar2 = (int)*param_1;
  piVar8 = piVar7;
  goto def_F00AF814;
loc_F00AFA30:
  _prom_putchar(0x25);
  iVar2 = (int)*param_1;
  goto def_F00AF814;
}

