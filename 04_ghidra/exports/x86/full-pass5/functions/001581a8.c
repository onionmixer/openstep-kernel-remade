/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001581a8 */

int _ipc_kobject_server(int param_1)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
  iVar1 = _kalloc(0x800);
  if (iVar1 == 0) {
    _printf(s_ipc_kobject_server__dropping_req_001debec);
    _ipc_kmsg_destroy(param_1);
    iVar1 = 0;
  }
  else {
    *(undefined4 *)(iVar1 + 8) = 0x800;
    *(undefined4 *)(iVar1 + 0xc) = 0;
    *(undefined4 *)(iVar1 + 0x10) = 0;
    *(uint *)(iVar1 + 0x14) = (uint)*(byte *)(param_1 + 0x15);
    *(undefined4 *)(iVar1 + 0x18) = 0x20;
    *(undefined4 *)(iVar1 + 0x1c) = *(undefined4 *)(param_1 + 0x20);
    *(undefined4 *)(iVar1 + 0x20) = 0;
    *(undefined4 *)(iVar1 + 0x24) = 0;
    *(int *)(iVar1 + 0x28) = *(int *)(param_1 + 0x28) + 100;
    *(undefined4 *)(iVar1 + 0x2c) = DAT_001dec14;
    iVar2 = _netipc_msg_send(param_1);
    if (iVar2 == 0) {
      iVar2 = param_1 + 0x14;
      pcVar3 = (code *)_mach_server_routine(iVar2);
      if ((((pcVar3 == (code *)0x0) &&
           (pcVar3 = (code *)_mach_port_server_routine(iVar2), pcVar3 == (code *)0x0)) &&
          (pcVar3 = (code *)_mach_host_server_routine(iVar2), pcVar3 == (code *)0x0)) &&
         ((pcVar3 = (code *)_mach_debug_server_routine(iVar2), pcVar3 == (code *)0x0 &&
          (pcVar3 = (code *)_driverServer_server_routine(iVar2), pcVar3 == (code *)0x0)))) {
        iVar2 = _ipc_kobject_notify(iVar2,iVar1 + 0x14);
        if (iVar2 == 0) {
          *(undefined4 *)(iVar1 + 0x30) = 0xfffffed1;
        }
      }
      else {
        (*pcVar3)(param_1 + 0x14,iVar1 + 0x14);
      }
    }
    else {
      *(undefined4 *)(iVar1 + 0x30) = 0xfffffecf;
    }
    if (*(char *)(param_1 + 0x14) == '\x11') {
      _ipc_port_release_send(*(undefined4 *)(param_1 + 0x1c));
    }
    else {
      if (*(char *)(param_1 + 0x14) != '\x12') {
                    /* WARNING: Subroutine does not return */
        _panic(s_ipc_object_destroy__strange_dest_001dec18);
      }
      _ipc_port_release_sonce(*(undefined4 *)(param_1 + 0x1c));
    }
    *(undefined4 *)(param_1 + 0x1c) = 0;
    iVar2 = *(int *)(iVar1 + 0x30);
    if ((iVar2 == 0) || (iVar2 == -0x131)) {
      *(undefined4 *)(param_1 + 0x10) = 0;
      if ((*(int *)(param_1 + 8) == 0x100) && (_ipc_kmsg_cache == 0)) {
        _ipc_kmsg_cache = param_1;
      }
      else if (*(int *)(param_1 + 8) < 1) {
        _ipc_kmsg_free(param_1);
      }
      else {
        _kfree(param_1,*(int *)(param_1 + 8));
      }
    }
    else {
      *(undefined4 *)(param_1 + 0x20) = 0;
      _ipc_kmsg_destroy(param_1);
    }
    if (iVar2 == -0x131) {
      if (*(int *)(iVar1 + 8) < 1) {
        _ipc_kmsg_free(iVar1);
      }
      else {
        _kfree(iVar1,*(int *)(iVar1 + 8));
      }
      iVar1 = 0;
    }
    else if ((*(int *)(iVar1 + 0x1c) == 0) || (*(int *)(iVar1 + 0x1c) == -1)) {
      _ipc_kmsg_destroy(iVar1);
      iVar1 = 0;
    }
  }
  return iVar1;
}

