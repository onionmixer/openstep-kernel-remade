
undefined4 sub_407D376(int *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  
  puVar1 = (undefined4 *)*param_1;
  uVar6 = 0;
  if (param_1 == (int *)*puVar1) {
    *(word *)((int)param_1 + 10) = *(word *)((int)param_1 + 10) | 0x100;
    if ((*(byte *)(puVar1[2] + 0x24) & 0x20) == 0) {
      uVar6 = _scsi_dstart(puVar1[2]);
    }
  }
  else {
    *(word *)((int)param_1 + 10) = *(word *)((int)param_1 + 10) | 0x200;
    puVar4 = unk_40B503E;
    if ((undefined4 **)unk_40B503E == &unk_40B503E) {
                    /* WARNING: Subroutine does not return */
      _panic(aSdVstartSdEjec);
    }
    puVar2 = (undefined4 *)*unk_40B503E;
    puVar3 = (undefined4 *)unk_40B503E[1];
    puVar5 = puVar3;
    if ((undefined4 **)puVar2 != &unk_40B503E) {
      puVar2[1] = puVar3;
      puVar5 = dword_40B5042;
    }
    dword_40B5042 = puVar5;
    *puVar3 = puVar2;
    puVar4[2] = *puVar1;
    puVar4[3] = param_1;
    *dword_40B503A = puVar4;
    puVar4[1] = dword_40B503A;
    *puVar4 = &unk_40B5036;
    dword_40B503A = puVar4;
    _thread_wakeup_prim(&dword_40B5046,0,0);
  }
  return uVar6;
}
