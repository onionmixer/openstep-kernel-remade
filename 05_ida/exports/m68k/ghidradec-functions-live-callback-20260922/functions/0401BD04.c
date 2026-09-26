
word * _ifa_ifwithnet(word *param_1)

{
  word *pwVar1;
  int iVar2;
  code *pcVar3;
  int iVar4;
  
  if (*param_1 < 0x11) {
    pcVar3 = (&off_40AE86A)[(uint)*param_1 * 2];
    for (iVar2 = _ifnet; iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x5a)) {
      for (pwVar1 = *(word **)(iVar2 + 0x16); pwVar1 != (word *)0x0;
          pwVar1 = *(word **)(pwVar1 + 0x12)) {
        if ((*param_1 == *pwVar1) && (iVar4 = (*pcVar3)(pwVar1,param_1), iVar4 != 0)) {
          return pwVar1;
        }
      }
    }
  }
  return (word *)0x0;
}

