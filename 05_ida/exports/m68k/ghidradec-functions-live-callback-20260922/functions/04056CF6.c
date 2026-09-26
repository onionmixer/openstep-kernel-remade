
void _kern_serv_shutdown(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *param_1;
  if (*(int *)(iVar1 + 0x30) != 0) {
    sub_405709E(iVar1 + 0x24);
    *(undefined4 *)(iVar1 + 0x30) = 0;
  }
  iVar2 = 0;
  iVar3 = iVar1;
  do {
    if (*(int *)(iVar3 + 0x18c) != 0) {
      _port_deallocate_EXTERNAL(*(undefined4 *)(iVar1 + 8),*(int *)(iVar3 + 0x18c));
      *(undefined4 *)(iVar3 + 0x18c) = 0;
      *(undefined4 *)(iVar3 + 400) = 0;
    }
    iVar3 = iVar3 + 0x10;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x32);
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

