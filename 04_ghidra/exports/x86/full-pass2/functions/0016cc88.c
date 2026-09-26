/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016cc88 */

void _kern_serv_shutdown(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = *param_1;
  if (*(int *)(iVar1 + 0x4d0) != 0) {
    _objc_unregisterModule(*(int *)(iVar1 + 0x4d0),0);
  }
  if (*(int *)(iVar1 + 0x30) != 0) {
    FUN_0016d054(iVar1 + 0x24);
    *(undefined4 *)(iVar1 + 0x30) = 0;
  }
  iVar4 = 0;
  iVar3 = 0;
  do {
    iVar2 = *(int *)(iVar3 + 0x18c + iVar1);
    if (iVar2 != 0) {
      _port_deallocate_EXTERNAL(*(undefined4 *)(iVar1 + 8),iVar2);
      *(undefined4 *)(iVar3 + 0x18c + iVar1) = 0;
      *(undefined4 *)(iVar3 + 400 + iVar1) = 0;
    }
    iVar3 = iVar3 + 0x10;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 0x32);
  _port_deallocate_EXTERNAL(*(undefined4 *)(iVar1 + 8),*(undefined4 *)(iVar1 + 0x14));
  _port_deallocate_EXTERNAL(*(undefined4 *)(iVar1 + 8),*(undefined4 *)(iVar1 + 0x1c));
  _port_set_deallocate_EXTERNAL(*(undefined4 *)(iVar1 + 8),*(undefined4 *)(iVar1 + 0x20));
  _kfree(*(undefined4 *)(iVar1 + 0x44),*(undefined4 *)(iVar1 + 0x48));
  _kfree(iVar1,0x4d4);
  _thread_terminate(_active_threads);
  do {
    _thread_halt_self();
  } while( true );
}

