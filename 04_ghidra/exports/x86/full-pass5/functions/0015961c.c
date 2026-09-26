/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015961c */

void _ipc_thread_init(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *local_c;
  undefined1 local_8 [4];
  
  iVar1 = _ipc_port_alloc_special(_ipc_space_kernel);
  if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(s_ipc_thread_init_001dece0);
  }
  *(int *)(param_1 + 0x90) = param_1;
  *(int *)(param_1 + 0x94) = param_1;
  *(undefined4 *)(param_1 + 0xa4) = 0;
  *(undefined4 *)(param_1 + 0xa8) = 0;
  *(int *)(param_1 + 0xac) = iVar1;
  uVar2 = _ipc_port_make_send(iVar1);
  *(undefined4 *)(param_1 + 0xb0) = uVar2;
  *(undefined4 *)(param_1 + 0xb4) = 0;
  *(undefined4 *)(param_1 + 0xbc) = 0;
  *(undefined4 *)(param_1 + 0xc0) = 0;
  iVar1 = _ipc_port_alloc_compat(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0x88),local_8,&local_c);
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(s_ipc_thread_init_001decf0);
  }
  local_c[7] = local_c[7] + 1;
  local_c[1] = local_c[1] + 1;
  LOCK();
  *local_c = 0;
  UNLOCK();
  *(undefined4 **)(param_1 + 0xb8) = local_c;
  return;
}

