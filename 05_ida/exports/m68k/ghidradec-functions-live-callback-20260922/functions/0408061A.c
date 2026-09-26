
void sub_408061A(int param_1)

{
  int iVar1;
  int iVar2;
  
  if ((&unk_40C6DF4)[param_1] == 0) {
    iVar2 = _kalloc(0x54);
    _snd_stream_queue_init(iVar2,iVar2,_dspq_start_complex);
    iVar1 = iVar2 + 0x3e;
    *(int *)(iVar2 + 0x42) = iVar1;
    *(int *)iVar1 = iVar1;
    (&unk_40C6DF4)[param_1] = iVar2;
    *(undefined4 *)(iVar2 + 0x32) = 0x10000;
    *(undefined4 *)(iVar2 + 0x36) = 0xc000;
    *(undefined4 *)(iVar2 + 0x46) = 0;
  }
  return;
}

