
int * _retrieve_task_self_fast(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x60);
  if (piVar1 == *(int **)(param_1 + 0x5c)) {
    *piVar1 = *piVar1 + 1;
    piVar1[6] = piVar1[6] + 1;
  }
  else {
    piVar1 = (int *)_ipc_port_copy_send(piVar1);
  }
  return piVar1;
}

