
void _ipc_thread_init(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piStack_c;
  undefined auStack_8 [4];
  
  iVar1 = _ipc_port_alloc_special(_ipc_space_kernel);
  if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aIpcThreadInit);
  }
  *(int *)(param_1 + 0x8c) = param_1;
  *(int *)(param_1 + 0x90) = param_1;
  *(undefined4 *)(param_1 + 0xa0) = 0;
  *(int *)(param_1 + 0xa4) = iVar1;
  uVar2 = _ipc_port_make_send(iVar1);
  *(undefined4 *)(param_1 + 0xa8) = uVar2;
  *(undefined4 *)(param_1 + 0xac) = 0;
  *(undefined4 *)(param_1 + 0xb4) = 0;
  *(undefined4 *)(param_1 + 0xb8) = 0;
  iVar1 = _ipc_port_alloc_compat
                    (*(undefined4 *)(*(int *)(param_1 + 0xc) + 0x7c),auStack_8,&piStack_c);
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aIpcThreadInit);
  }
  piStack_c[6] = piStack_c[6] + 1;
  *piStack_c = *piStack_c + 1;
  *(int **)(param_1 + 0xb0) = piStack_c;
  return;
}

