
void _in_makeaddr(uint param_1)

{
  int iVar1;
  
  for (iVar1 = _in_ifaddr;
      (iVar1 != 0 && ((param_1 & *(uint *)(iVar1 + 0x2c)) != *(uint *)(iVar1 + 0x28)));
      iVar1 = *(int *)(iVar1 + 0x40)) {
  }
  return;
}
