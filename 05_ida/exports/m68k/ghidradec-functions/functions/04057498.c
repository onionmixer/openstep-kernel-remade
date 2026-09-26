
void sub_4057498(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  
  iVar7 = 0;
  puVar1 = dword_40B4DE8;
  if (*(int *)(param_1 + 0x14) == 0x41) {
joined_r0x040574ce:
    puVar4 = puVar1;
    if ((undefined4 **)puVar4 != &dword_40B4DE8) {
      puVar1 = (undefined4 *)*puVar4;
      if (puVar4[3] != *(int *)(param_1 + 0x1c)) goto loc_40574FE;
      puVar2 = (undefined4 *)puVar4[1];
      puVar3 = puVar2;
      if ((undefined4 **)puVar1 != &dword_40B4DE8) {
        puVar1[1] = puVar2;
        puVar3 = dword_40B4DEC;
      }
      dword_40B4DEC = puVar3;
      *puVar2 = puVar1;
      goto loc_4057566;
    }
    if (iVar7 == 0) {
      _printf(aPnNotifyPortNo);
    }
  }
  else {
    _printf(aPnNotifyMsgIdD,*(int *)(param_1 + 0x14));
  }
  return;
loc_40574FE:
  if (*(int *)(param_1 + 0x1c) == puVar4[2]) {
    *(undefined4 *)(param_1 + 0x10) = puVar4[3];
    *(undefined4 *)(param_1 + 0xc) = 0;
    *(undefined *)(param_1 + 3) = 1;
    *(undefined *)(param_1 + 0x18) = 2;
    *(undefined *)(param_1 + 0x19) = 0x20;
    *(undefined4 *)(param_1 + 0x1c) = puVar4[4];
    iVar6 = _msg_send(param_1,1,0);
    if (iVar6 != 0) {
      _printf(aPnNotifyMsgSen,iVar6);
    }
    puVar2 = (undefined4 *)*puVar4;
    puVar3 = (undefined4 *)puVar4[1];
    puVar5 = puVar3;
    if ((undefined4 **)puVar2 != &dword_40B4DE8) {
      puVar2[1] = puVar3;
      puVar5 = dword_40B4DEC;
    }
    dword_40B4DEC = puVar5;
    *puVar3 = puVar2;
loc_4057566:
    _kfree(puVar4,0x14);
    iVar7 = iVar7 + 1;
  }
  goto joined_r0x040574ce;
}
