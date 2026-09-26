
uint sub_404B924(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  for (iVar2 = _firstsegfromheader(param_1); iVar2 != 0; iVar2 = _nextsegfromheader(param_1,iVar2))
  {
    uVar1 = *(int *)(iVar2 + 0x24) + *(int *)(iVar2 + 0x20);
    if (uVar3 < uVar1) {
      uVar3 = uVar1;
    }
  }
  return uVar3;
}

