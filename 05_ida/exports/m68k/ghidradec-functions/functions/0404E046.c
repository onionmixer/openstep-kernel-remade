
undefined4 sub_404E046(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined *puVar3;
  int *piVar4;
  bool bVar5;
  
  piVar4 = (int *)0x0;
  puVar3 = _miniMonCommands;
  iVar1 = _miniMonCommands._0_4_;
  while (iVar1 != 0) {
    iVar1 = sub_404E00E(*(int *)puVar3,param_1);
    if ((iVar1 == 0) && (bVar5 = piVar4 != (int *)0x0, piVar4 = (int *)puVar3, bVar5))
    goto loc_404E0B0;
    puVar3 = (undefined *)((int)puVar3 + 0xc);
    iVar1 = *(int *)puVar3;
  }
  puVar3 = _miniMonMDCommands;
  iVar1 = _miniMonMDCommands._0_4_;
  while (iVar1 != 0) {
    iVar1 = sub_404E00E(*(int *)puVar3,param_1);
    if ((iVar1 == 0) && (bVar5 = piVar4 != (int *)0x0, piVar4 = (int *)puVar3, bVar5))
    goto loc_404E0B0;
    puVar3 = (undefined *)((int)puVar3 + 0xc);
    iVar1 = *(int *)puVar3;
  }
  if (piVar4 != (int *)0x0) {
    uVar2 = (*(code *)piVar4[1])(param_1);
    return uVar2;
  }
  puVar3 = aInvalidCommand;
loc_404E0B6:
  _safe_prf(puVar3);
  return 1;
loc_404E0B0:
  puVar3 = aAmbiguousComma;
  goto loc_404E0B6;
}
