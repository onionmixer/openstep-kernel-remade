
undefined4 sub_4080B2E(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_kalloc(*(int *)(param_1 + 0x3c) + 0x26);
  *puVar1 = 9;
  *(undefined *)((int)puVar1 + 0x23) = 1;
  *(undefined *)(puVar1 + 9) = 0;
  _bcopy(*(undefined4 *)(param_1 + 0x38),*(undefined4 *)(param_1 + 0x3c),
         *(undefined4 *)(param_1 + 0x40),*(undefined4 *)(param_1 + 0x44),
         *(undefined4 *)(param_1 + 0x48),*(undefined4 *)(param_1 + 0x4c),(int)puVar1 + 0x26,
         *(undefined4 *)(param_1 + 0x3c));
  if (dword_40C6E72 != (undefined4 *)0x0) {
    _dspq_free_msg(dword_40C6E72);
  }
  if (*(int *)(param_1 + 0x28) == 0) {
    *(undefined4 *)(puVar1[1] + 0x10) = _snd_var;
  }
  else {
    *(int *)(puVar1[1] + 0x10) = *(int *)(param_1 + 0x28);
  }
  dword_40C6E6A = *(undefined4 *)(param_1 + 0x1c);
  dword_40C6E6E = *(undefined4 *)(param_1 + 0x20);
  dword_40C6E72 = puVar1;
  _dspq_execute();
  return 100;
}

