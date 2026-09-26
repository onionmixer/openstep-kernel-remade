
/* WARNING: Removing unreachable block (ram,0xf00b373c) */
/* WARNING: Removing unreachable block (ram,0xf00b36b4) */
/* WARNING: Removing unreachable block (ram,0xf00b368c) */
/* WARNING: Removing unreachable block (ram,0xf00b36a0) */
/* WARNING: Removing unreachable block (ram,0xf00b3710) */
/* WARNING: Removing unreachable block (ram,0xf00b36dc) */
/* WARNING: Removing unreachable block (ram,0xf00b3654) */

undefined8 _obio_match(int param_1,char *param_2)

{
  char cVar1;
  char cVar2;
  char *pcVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar6;
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
  pcVar3 = param_2;
  _atou();
  cVar1 = *param_2;
  cVar2 = *param_2;
  while ((cVar1 != '\0' && (param_2 = param_2 + 1, cVar2 != ','))) {
    cVar1 = *param_2;
    cVar2 = *param_2;
  }
  _atou(param_2);
  uVar4 = *(undefined4 *)(param_1 + 0x28);
  _getproplen(uVar4,&aReg_4);
  puVar5 = *(undefined4 **)(param_1 + 0x28);
  _getlongprop(puVar5,&aReg_5);
  if (puVar5 == (undefined4 *)0x0) {
    if (dword_F011DFB8 != 0) {
      _printf(aNoAddrQualifie_0,*(undefined4 *)(param_1 + 0x28));
    }
    uVar6 = 0;
  }
  else {
    if (dword_F011DFB8 != 0) {
      _printf(aBustypeDAddrXR,pcVar3,param_2,**(undefined4 **)(param_1 + 0x14),
              (*(undefined4 **)(param_1 + 0x14))[1]);
    }
    uVar6 = 0;
    if (pcVar3 == (char *)*puVar5) {
      uVar6 = (uint)(param_2 == (char *)puVar5[1]);
    }
    _kfree(puVar5,uVar4);
  }
  return CONCAT44(puVar5,uVar6);
}

