
void sub_407F1EE(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_kalloc(0x14);
  puVar1[2] = param_1;
  puVar1[3] = param_2;
  puVar1[4] = param_3;
  *dword_40B5032 = puVar1;
  puVar1[1] = dword_40B5032;
  *puVar1 = &unk_40B502E;
  dword_40B5032 = puVar1;
  _thread_wakeup_prim(&dword_40B5046,0,0);
  return;
}
