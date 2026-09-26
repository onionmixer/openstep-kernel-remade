
undefined4 _dspq_start_simple(int param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = 1;
  if (param_2 == 0) {
    iVar3 = 2;
  }
  if ((dword_40C6E84 & 0x20000) == 0) {
    if (param_2 == 1) {
      *(undefined4 *)(param_1 + 0x18) = 4;
      _dma_enqueue(&_dsp_var,param_1 + 0xc);
    }
    else {
      piVar1 = *(int **)((&unk_40C6DF4)[iVar3] + 0x42);
      if (piVar1 == (int *)((&unk_40C6DF4)[iVar3] + 0x3e)) {
        *piVar1 = param_1;
      }
      else {
        piVar1[0xb] = param_1;
      }
      *(int **)(param_1 + 0x30) = piVar1;
      *(int *)(param_1 + 0x2c) = (&unk_40C6DF4)[iVar3] + 0x3e;
      *(int *)((&unk_40C6DF4)[iVar3] + 0x42) = param_1;
    }
    if (((dword_40C6E84 & 0x10000) != 0) || ((undefined4 **)dword_40C6E46 != &dword_40C6E46)) {
      iVar3 = _dspq_check();
      if (iVar3 != 0) {
        _callout_dispatch(1,_dspq_execute,0);
      }
    }
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

