
undefined4 _in_broadcast(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  for (iVar1 = _in_ifaddr; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x40)) {
    if (((*(byte *)(*(int *)(iVar1 + 0x20) + 0xd) & 2) != 0) &&
       (((param_1 == *(int *)(iVar1 + 0x14) || (param_1 == *(int *)(iVar1 + 0x30))) ||
        (param_1 == *(int *)(iVar1 + 0x28))))) goto loc_401F4DC;
  }
  if ((param_1 == -1) || (param_1 == 0)) {
loc_401F4DC:
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

