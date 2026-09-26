
undefined4 _proc_from_thread(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = **(undefined4 **)(*(int *)(param_1 + 0xc) + 0x30);
  }
  return uVar1;
}

