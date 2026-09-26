
void FUN_0016eb34(int *param_1,int param_2)

{
  void *thread;
  int iVar1;
  
  if ((((param_1[1] == 0x28) && (-1 < *param_1)) && (param_1[6] == DAT_001e0184)) &&
     (param_1[8] == DAT_001e0188)) {
    thread = (void *)_convert_port_to_thread(param_1[2]);
    iVar1 = _thread_policy(thread,param_1[7],param_1[9]);
    *(int *)(param_2 + 0x1c) = iVar1;
    _thread_deallocate(thread);
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return;
}

