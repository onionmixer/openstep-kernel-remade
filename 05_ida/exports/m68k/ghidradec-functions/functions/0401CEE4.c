
void _if_registervirtual(code *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  
  piVar3 = &dword_40B3454;
  puVar2 = (undefined4 *)_kalloc(0xc);
  *puVar2 = param_1;
  puVar2[1] = param_2;
  puVar2[2] = 0;
  iVar1 = dword_40B3454;
  while (iVar1 != 0) {
    piVar3 = (int *)(*piVar3 + 8);
    iVar1 = *piVar3;
  }
  *piVar3 = (int)puVar2;
  for (iVar1 = _ifnet; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x5a)) {
    if (*(int *)(iVar1 + 0x12) == 0) {
      (*param_1)(param_2,iVar1);
    }
  }
  return;
}
