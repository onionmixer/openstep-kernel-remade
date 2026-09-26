
undefined * _ip_optcopy(byte *param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  undefined *puVar3;
  uint uVar4;
  undefined *puVar5;
  
  puVar5 = (undefined *)(param_2 + 0x14);
  uVar2 = (*param_1 & 0xf) * 4 - 0x14;
  for (param_1 = param_1 + 0x14; (0 < (int)uVar2 && (bVar1 = *param_1, bVar1 != 0));
      param_1 = param_1 + uVar4) {
    if (bVar1 == 1) {
      uVar4 = 1;
    }
    else {
      uVar4 = (uint)param_1[1];
    }
    if ((int)uVar2 < (int)uVar4) {
      uVar4 = uVar2;
    }
    if ((char)bVar1 < '\0') {
      _bcopy(param_1,puVar5,uVar4);
      puVar5 = puVar5 + uVar4;
    }
    uVar2 = uVar2 - uVar4;
  }
  puVar3 = puVar5 + (-0x14 - param_2);
  for (; ((uint)puVar3 & 3) != 0; puVar3 = puVar3 + 1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  return puVar3;
}

