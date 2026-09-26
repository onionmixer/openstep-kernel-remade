
void _disksort_enter(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = _active_threads;
  sub_4036D3E(param_1);
  if (*(char *)(param_1 + 0xc) < '\0') {
    (*_ds_call)(param_1,param_2);
  }
  else {
    if (iVar1 != 0) {
      *(undefined4 *)(param_2 + 0x3c) = *(undefined4 *)(iVar1 + 0x4c);
    }
    sub_4036F96(param_1,param_2);
  }
  return;
}

