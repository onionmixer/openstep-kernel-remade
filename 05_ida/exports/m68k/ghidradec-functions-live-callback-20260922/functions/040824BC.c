
void sub_40824BC(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = _dma_dequeue(&_dsp_var,0);
  iVar1 = *(int *)(iVar1 + 0x18);
  *(int *)((&unk_40C6DF4)[param_2] + 0x26) =
       *(int *)(iVar1 + 4) + *(int *)((&unk_40C6DF4)[param_2] + 0x26);
  if (param_4 == 0) {
    *(byte *)(_slot_id_bmap + 0x2008000) = *(byte *)(_slot_id_bmap + 0x2008000) & 0x8d;
    *(undefined *)(_slot_id_bmap + 0x2008001) = 0x94;
    iVar2 = 100;
    do {
      if (-1 < *(char *)(_slot_id_bmap + 0x2008001)) break;
      _delay(1);
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    if (iVar2 == 0) {
      _printf(aDspDmaCleanupD);
    }
    dword_40C6E76 = 0;
    *(byte *)(_slot_id_bmap + 0x2008000) = *(byte *)(_slot_id_bmap + 0x2008000) | 1;
  }
  else {
    dword_40C6E84 = dword_40C6E84 | 0x40;
    dword_40C6E76 = 3;
    _dspq_enqueue_cond(0x800000,0);
    _dspq_enqueue_hc(0x12);
    _dspq_enqueue_cond(0x800000,0);
    _dspq_enqueue_hf(0x73000000,0x81000000);
    _dspq_enqueue_state(0);
    dword_40C6E84 = dword_40C6E84 & 0xffffffbf;
    _dspq_execute();
  }
  if ((int *)((&unk_40C6DF4)[param_2] + 0x3e) == *(int **)((&unk_40C6DF4)[param_2] + 0x3e)) {
    *(uint *)(iVar1 + 0x34) = *(uint *)(iVar1 + 0x34) | 1;
  }
  (**(code **)(iVar1 + 0x28))(iVar1);
  return;
}

