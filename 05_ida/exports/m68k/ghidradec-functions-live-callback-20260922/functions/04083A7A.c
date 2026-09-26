
undefined4 sub_4083A7A(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uStack_8;
  
  if (dword_40C6EB8 == *(int *)(_active_threads + 0xc)) {
    uStack_8 = *(undefined4 *)(param_1 + 0x10);
  }
  else {
    iVar1 = _object_copyin(dword_40C6EB8,*(undefined4 *)(param_1 + 0x10),6,0,&uStack_8);
    if (iVar1 == 0) {
      return 5;
    }
  }
  uVar2 = _snd_reply_recorded_data
                    (uStack_8,0,*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),1);
  _dspq_free_msg(param_1);
  return uVar2;
}

