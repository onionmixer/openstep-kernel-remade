
undefined4 _in_localaddr(uint param_1)

{
  int iVar1;
  
  iVar1 = _in_ifaddr;
  if (_subnetsarelocal == 0) {
    for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x40)) {
      if ((*(uint *)(iVar1 + 0x34) & param_1) == *(uint *)(iVar1 + 0x30)) {
        return 1;
      }
    }
  }
  else {
    for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x40)) {
      if ((*(uint *)(iVar1 + 0x2c) & param_1) == *(uint *)(iVar1 + 0x28)) {
        return 1;
      }
    }
  }
  return 0;
}

