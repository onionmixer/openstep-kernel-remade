
undefined4 sub_4080BE6(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  code *pcVar6;
  
  if ((*(int *)(param_1 + 4) == 0x34) && (iVar1 = *(int *)(param_1 + 0x30), iVar1 - 1U < 0x13)) {
    if (*(int *)(param_1 + 0x2c) == 5) {
      uVar3 = *(int *)(param_1 + 0x20) * 2;
    }
    else {
      uVar3 = *(int *)(param_1 + 0x2c) * *(int *)(param_1 + 0x20);
    }
    if (uVar3 <= _page_size) {
      if (*(int *)(param_1 + 0x2c) == 5) {
        uVar3 = *(int *)(param_1 + 0x20) * 2;
      }
      else {
        uVar3 = *(int *)(param_1 + 0x2c) * *(int *)(param_1 + 0x20);
      }
      if (_page_size % uVar3 == 0) {
        iVar4 = (&unk_40C6DF4)[iVar1];
        if (iVar4 == 0) {
          iVar4 = _kalloc(0x54);
          pcVar6 = _dspq_start_simple;
          if ((dword_40C6E84 & 0x2000) != 0) {
            pcVar6 = _dspq_start_complex;
          }
          _snd_stream_queue_init(iVar4,iVar4,pcVar6);
          iVar2 = iVar4 + 0x3e;
          *(int *)(iVar4 + 0x42) = iVar2;
          *(int *)iVar2 = iVar2;
          (&unk_40C6DF4)[iVar1] = iVar4;
        }
        *(undefined4 *)(iVar4 + 0x46) = 0;
        *(undefined4 *)(iVar4 + 0x4a) = *(undefined4 *)(param_1 + 0x1c);
        *(undefined2 *)(iVar4 + 0x4e) = *(undefined2 *)(param_1 + 0x22);
        *(undefined2 *)(iVar4 + 0x50) = *(undefined2 *)(param_1 + 0x26);
        *(undefined *)(iVar4 + 0x52) = *(undefined *)(param_1 + 0x2b);
        *(undefined *)(iVar4 + 0x53) = *(undefined *)(param_1 + 0x2f);
        uVar5 = _snd_dspcmd_def_dmasize(iVar1);
        *(undefined4 *)(iVar4 + 0x2a) = uVar5;
        uVar5 = _snd_dspcmd_def_high_water(iVar1);
        *(undefined4 *)(iVar4 + 0x32) = uVar5;
        uVar5 = _snd_dspcmd_def_low_water(iVar1);
        *(undefined4 *)(iVar4 + 0x36) = uVar5;
        return 100;
      }
    }
  }
  return 0x67;
}
