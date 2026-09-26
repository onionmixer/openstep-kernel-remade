
int sub_4028652(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined2 *puVar4;
  undefined4 *puVar5;
  
  if ((_nfs_portmon == 0) || (*(word *)(*(int *)(param_2 + 0x1c) + 0x10) < 0x400)) {
    iVar2 = *(int *)(param_2 + 0xc);
    if (iVar2 != *(int *)(param_1 + 8)) {
      iVar2 = 0;
    }
    if (iVar2 == 0) {
loc_40286CE:
      *(undefined2 *)(param_3 + 2) = *(undefined2 *)(param_1 + 6);
      *(undefined2 *)(param_3 + 4) = *(undefined2 *)(param_1 + 6);
      puVar4 = (undefined2 *)(param_3 + 10);
    }
    else {
      if (iVar2 != 1) goto loc_4028692;
      iVar2 = *(int *)(param_2 + 0x18);
      if ((*(int *)(iVar2 + 8) == 0) &&
         (iVar3 = sub_402860E(*(int *)(param_2 + 0x1c) + 0xe,param_1 + 0xc), iVar3 == 0))
      goto loc_40286CE;
      *(undefined2 *)(param_3 + 2) = *(undefined2 *)(iVar2 + 10);
      *(undefined2 *)(param_3 + 4) = *(undefined2 *)(iVar2 + 0xe);
      puVar5 = *(undefined4 **)(iVar2 + 0x14);
      for (puVar4 = (undefined2 *)(param_3 + 10);
          puVar4 < (undefined2 *)(param_3 + 10 + *(int *)(iVar2 + 0x10) * 2); puVar4 = puVar4 + 1) {
        *puVar4 = (sword)*puVar5;
        puVar5 = puVar5 + 1;
      }
    }
    for (; puVar4 < (undefined2 *)(param_3 + 0x2a); puVar4 = puVar4 + 1) {
      *puVar4 = 0xffff;
    }
    iVar2 = -(int)-(*(sword *)(param_3 + 2) != -1);
  }
  else {
    uVar1 = _inet_ntoa(*(int *)(param_2 + 0x1c) + 0x12);
    _printf(aNfsRequestFrom,uVar1);
loc_4028692:
    iVar2 = 0;
  }
  return iVar2;
}

