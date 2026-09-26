
undefined4 _dspq_start_complex(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  
  iVar2 = **(int **)(*(int *)(param_1 + 8) + 0x3a);
  if ((dword_40C6E84 & 0x20000) == 0) {
    uVar3 = 0;
    piVar4 = &unk_40C6DF4;
    do {
      if (iVar2 == *piVar4) break;
      piVar4 = piVar4 + 1;
      uVar3 = uVar3 + 1;
    } while ((int)uVar3 < 0x13);
    piVar4 = *(int **)(iVar2 + 0x42);
    if (piVar4 == (int *)(iVar2 + 0x3e)) {
      *piVar4 = param_1;
    }
    else {
      piVar4[0xb] = param_1;
    }
    *(int **)(param_1 + 0x30) = piVar4;
    *(int *)(param_1 + 0x2c) = iVar2 + 0x3e;
    *(int *)(iVar2 + 0x42) = param_1;
    if (param_2 == 0) {
      *(byte *)(_slot_id_bmap + 0x2008000) = *(byte *)(_slot_id_bmap + 0x2008000) | 2;
    }
    else {
      if (((dword_40C6E76 != 1) && (dword_40C6E76 != 2)) && (dword_40C6E76 != 6)) {
        *(byte *)(_slot_id_bmap + 0x2008000) = *(byte *)(_slot_id_bmap + 0x2008000) | 1;
      }
      if ((word_40C6E7A == 1) || ((dword_40C6E76 == 1 && (word_40C6E40 == uVar3)))) {
        _dsp_dev_loop();
      }
    }
    if (((dword_40C6E84 & 0x10000) != 0) || ((undefined4 **)dword_40C6E46 != &dword_40C6E46)) {
      iVar2 = _dspq_check();
      if (iVar2 != 0) {
        _callout_dispatch(1,_dspq_execute,0);
      }
    }
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}
