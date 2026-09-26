
undefined4 sub_407E678(int *param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  byte bVar4;
  uint *puVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined auStack_c [8];
  
  iVar6 = *param_1;
  puVar5 = (uint *)(param_1 + 6);
  uVar7 = 0;
  iVar2 = *(int *)(iVar6 + 8);
  while (((*puVar5 & 8) != 0 && (param_3 == 0))) {
    *puVar5 = *puVar5 | 0x40;
    _sleep(puVar5,0x14);
  }
  *puVar5 = 9;
  param_1[0x17] = param_2;
  _microtime(auStack_c);
  if (param_3 == 1) {
    *(uint *)(iVar6 + 0xc) = *(uint *)(iVar6 + 0xc) & 0xfffffffb | 1;
  }
  else {
    *(uint *)(iVar6 + 0xc) = *(uint *)(iVar6 + 0xc) & 0xfffffffe | 4;
  }
  *(sword *)((int)param_1 + 0x36) = (sword)param_1[1] << 3;
  iVar6 = _sdstrategy(puVar5);
  if (iVar6 == 0) {
    if (param_3 == 0) {
      _biowait(puVar5);
    }
    else {
      iVar6 = 0;
      bVar4 = *(byte *)((int)param_1 + 0x1b);
      while ((bVar4 & 2) == 0) {
        iVar6 = iVar6 + 1;
        if (iVar6 < 0xfa1) {
          _delay(1000);
        }
        else {
          _scsi_timeout(*(undefined4 *)(iVar2 + 0x18));
          iVar6 = 0;
        }
        bVar4 = *(byte *)((int)param_1 + 0x1b);
      }
    }
  }
  if (*(int *)(param_2 + 0x1c) == 2) {
    puVar3 = *(undefined4 **)((int)param_1 + 0xc6);
    *(undefined4 *)(param_2 + 0x22) = *puVar3;
    *(undefined4 *)(param_2 + 0x26) = puVar3[1];
    *(undefined4 *)(param_2 + 0x2a) = puVar3[2];
    *(undefined4 *)(param_2 + 0x2e) = puVar3[3];
    *(undefined4 *)(param_2 + 0x32) = puVar3[4];
    *(undefined4 *)(param_2 + 0x36) = puVar3[5];
    *(undefined2 *)(param_2 + 0x3a) = *(undefined2 *)(puVar3 + 6);
  }
  if ((*(int *)(param_2 + 0x1c) != 0) && (param_3 != 0)) {
    uVar7 = 5;
  }
  _microtime(&uStack_14);
  _timevalsub(&uStack_14,auStack_c);
  *(undefined4 *)(param_2 + 0x40) = uStack_14;
  *(undefined4 *)(param_2 + 0x44) = uStack_10;
  param_1[0x17] = 0;
  uVar1 = *puVar5;
  *puVar5 = uVar1 & 0xfffffff7;
  if (((uVar1 & 0x40) != 0) && (param_3 == 0)) {
    _wakeup(puVar5);
  }
  return uVar7;
}
