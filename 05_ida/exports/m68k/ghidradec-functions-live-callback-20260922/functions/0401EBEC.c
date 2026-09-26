
undefined * _ether_sprintf(byte *param_1)

{
  undefined *puVar1;
  int iVar2;
  undefined *puVar3;
  
  iVar2 = 0;
  puVar1 = unk_40B345E;
  do {
    puVar3 = puVar1;
    *puVar3 = a0123456789abcd_1[*param_1 >> 4];
    puVar3[1] = a0123456789abcd_1[*param_1 & 0xf];
    puVar3[2] = 0x3a;
    iVar2 = iVar2 + 1;
    puVar1 = puVar3 + 3;
    param_1 = param_1 + 1;
  } while (iVar2 < 6);
  puVar3[2] = 0;
  return unk_40B345E;
}

