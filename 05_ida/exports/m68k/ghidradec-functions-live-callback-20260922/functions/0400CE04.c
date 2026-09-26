
byte _ttywait(int param_1)

{
  int iVar1;
  char cVar2;
  bool bVar3;
  bool bVar4;
  
  cVar2 = '\0';
  if (*(int *)(param_1 + 0x18) == 0) goto loc_400CE60;
  do {
    do {
      if ((*(byte *)(param_1 + 0x41) & 0x10) == 0) {
        iVar1 = _ttynty(param_1);
        bVar3 = *(sword *)(iVar1 + 0x12) < 0;
        bVar4 = *(sword *)(iVar1 + 0x12) == 0;
        if (!bVar3) goto loc_400CE6C;
      }
      (**(code **)(param_1 + 0x24))(param_1);
      *(uint *)(param_1 + 0x3e) = *(uint *)(param_1 + 0x3e) | 0x40;
      _sleep((int *)(param_1 + 0x18),0x1d);
    } while (*(int *)(param_1 + 0x18) != 0);
loc_400CE60:
    bVar3 = false;
    bVar4 = (*(uint *)(param_1 + 0x3e) & 0x2000020) == 0;
  } while (!bVar4);
loc_400CE6C:
  return cVar2 << 4 | bVar3 << 3 | bVar4 << 2;
}

