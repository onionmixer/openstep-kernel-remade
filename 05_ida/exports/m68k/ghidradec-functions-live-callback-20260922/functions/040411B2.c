
int * _ipc_port_lookup_notify(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = _ipc_entry_lookup(param_1,param_2);
  if ((iVar1 == 0) || ((*(byte *)(iVar1 + 1) & 2) == 0)) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = *(int **)(iVar1 + 4);
    *piVar2 = *piVar2 + 1;
    piVar2[7] = piVar2[7] + 1;
  }
  return piVar2;
}

