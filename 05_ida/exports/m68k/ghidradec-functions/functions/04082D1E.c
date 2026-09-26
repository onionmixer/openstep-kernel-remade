
void _dspq_enqueue(int *param_1)

{
  int *piVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  undefined4 *puVar5;
  
  piVar1 = (int *)*param_1;
  pbVar3 = (byte *)(piVar1 + 8);
  iVar4 = 0;
  for (; piVar1 != param_1; piVar1 = (int *)piVar1[6]) {
    iVar4 = iVar4 + 1;
  }
  puVar5 = dword_40C6E46;
  if ((undefined4 **)dword_40C6E46 != &dword_40C6E46) {
    do {
      if ((*pbVar3 < *(byte *)(puVar5 + 8)) &&
         ((*(byte *)((int)puVar5 + 0x21) < 2 || ((puVar5[8] & 0x4ff00) == 0)))) break;
      puVar5 = (undefined4 *)puVar5[6];
    } while ((undefined4 **)puVar5 != &dword_40C6E46);
  }
  if ((undefined4 **)dword_40C6E46 == &dword_40C6E46) {
    dword_40C6E46 = (undefined4 *)*param_1;
    dword_40C6E4A = param_1[1];
    iVar2 = *param_1;
    *(undefined4 ***)(param_1[1] + 0x18) = &dword_40C6E46;
    *(undefined4 ***)(iVar2 + 0x1c) = &dword_40C6E46;
  }
  else {
    if ((undefined4 **)puVar5 == &dword_40C6E46) {
      *(int *)(dword_40C6E4A + 0x18) = *param_1;
      *(int *)(*param_1 + 0x1c) = dword_40C6E4A;
      dword_40C6E4A = param_1[1];
    }
    else {
      if ((undefined4 **)puVar5[7] == &dword_40C6E46) {
        dword_40C6E46 = (undefined4 *)*param_1;
      }
      else {
        ((undefined4 *)puVar5[7])[6] = *param_1;
      }
      *(undefined4 *)(*param_1 + 0x1c) = puVar5[7];
      puVar5[7] = param_1[1];
    }
    *(undefined4 **)(param_1[1] + 0x18) = puVar5;
  }
  dword_40C6E4E = iVar4 + dword_40C6E4E;
  iVar4 = _curipl();
  if (((iVar4 == 0) && (0x1ff < dword_40C6E4E)) && ((dword_40C6E84 & 0x40000) == 0)) {
    _port_set_remove(dword_40C6EC0,0x10013);
    dword_40C6E84 = dword_40C6E84 | 0x40000;
  }
  if ((dword_40C6E84 & 0x40) == 0) {
    _dspq_execute();
  }
  return;
}
