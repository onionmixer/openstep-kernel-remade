/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014b5d4 */

void _ipc_notify_send_once(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  iVar1 = _kalloc(0x2c);
  if (iVar1 == 0) {
    _printf(s_dropped_send_once__0x_08x__001de7e8,param_1);
    _ipc_port_release_sonce(param_1);
  }
  else {
    *(undefined4 *)(iVar1 + 8) = 0x2c;
    *(undefined4 *)(iVar1 + 0xc) = 0;
    *(undefined4 *)(iVar1 + 0x10) = 0;
    puVar3 = &_ipc_notify_send_once_template;
    puVar4 = (undefined4 *)(iVar1 + 0x14);
    for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    *(undefined4 *)(iVar1 + 0x1c) = param_1;
    _ipc_mqueue_send(iVar1,0x10000,0,0);
  }
  return;
}

