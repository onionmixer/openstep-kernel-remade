
undefined4 _arpioctl(int param_1,sword *param_2)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  
  iVar2 = 0;
  if ((*param_2 != 2) || (param_2[8] != 0)) {
    return 0x2f;
  }
  puVar3 = (uint *)(_arptab + (*(uint *)(param_2 + 2) % 0x13) * 0xb4);
  iVar1 = 0;
  do {
    if (*(uint *)(param_2 + 2) == *puVar3) break;
    iVar1 = iVar1 + 1;
    puVar3 = puVar3 + 5;
  } while (iVar1 < 9);
  if (8 < iVar1) {
    puVar3 = (uint *)0x0;
  }
  if (puVar3 == (uint *)0x0) {
    if (param_1 != -0x7fdb96e2) {
      return 6;
    }
    iVar2 = _ifa_ifwithnet(param_2);
    if (iVar2 == 0) {
      return 0x33;
    }
  }
  if (param_1 == -0x7fdb96e0) {
    _arptfree(puVar3);
  }
  else if (param_1 < -0x7fdb96df) {
    if (param_1 == -0x7fdb96e2) {
      if (puVar3 == (uint *)0x0) {
        puVar3 = (uint *)_arptnew(*(undefined4 *)(iVar2 + 0x20),param_2 + 2);
        if (puVar3 == (uint *)0x0) {
          return 0x31;
        }
        if ((*(byte *)((int)param_2 + 0x23) & 4) != 0) {
          iVar2 = _arptnew(puVar3[4],param_2 + 2);
          if (iVar2 == 0) {
            _arptfree(puVar3);
            return 0x31;
          }
          _arptfree(iVar2);
        }
      }
      _bcopy(param_2 + 9,puVar3 + 1,6);
      *(byte *)((int)puVar3 + 0xb) = *(byte *)((int)param_2 + 0x23) & 0x1c | 3;
      *(undefined *)((int)puVar3 + 10) = 0;
    }
  }
  else if (param_1 == -0x3fdb96e1) {
    _bcopy(puVar3 + 1,param_2 + 9,6);
    *(uint *)(param_2 + 0x10) = (uint)*(byte *)((int)puVar3 + 0xb);
  }
  return 0;
}

