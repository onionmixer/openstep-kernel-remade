
void _thread_set_syscall_return(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  if (*(int *)(*(int *)(param_1 + 0x24) + 0x4c) == 0) {
    puVar1 = (undefined4 *)_thread_user_state(param_1);
  }
  else {
    puVar1 = *(undefined4 **)(*(int *)(param_1 + 0x24) + 0x48);
  }
  *puVar1 = param_2;
  return;
}
