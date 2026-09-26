
undefined4 _km_send(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = _slot_id;
  iVar3 = 100000;
  _mon_send(param_1,param_2);
  do {
    if ((*(byte *)(iVar1 + 0x200e001) & 0x40) != 0) break;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  uVar2 = 0x40000000;
  if (iVar3 != 0) {
    uVar2 = 0;
  }
  return uVar2;
}
