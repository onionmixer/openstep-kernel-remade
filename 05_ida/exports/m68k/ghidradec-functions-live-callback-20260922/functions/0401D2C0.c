
undefined4 _raw_bind(int param_1,int param_2)

{
  int iVar1;
  word *pwVar2;
  
  pwVar2 = (word *)(*(int *)(param_2 + 4) + param_2);
  if (_ifnet != 0) {
    if ((3 < *pwVar2) || (*pwVar2 < 2)) {
      return 0x2f;
    }
    if ((*(int *)(pwVar2 + 2) == 0) || (iVar1 = _ifa_ifwithaddr(pwVar2), iVar1 != 0)) {
      iVar1 = *(int *)(param_1 + 8);
      _bcopy(pwVar2,iVar1 + 0x1c,0x10);
      pwVar2 = (word *)(iVar1 + 0x4c);
      *pwVar2 = *pwVar2 | 1;
      return 0;
    }
  }
  return 0x31;
}

