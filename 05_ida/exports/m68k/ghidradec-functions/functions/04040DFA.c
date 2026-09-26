
void _ipc_port_clear_receiver(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x2c);
  if (piVar1 == (int *)0x0) {
    _ipc_mqueue_changed(param_1 + 0x3c,0x10004009);
  }
  else {
    _ipc_pset_remove(piVar1,param_1);
    if (*piVar1 == 0) {
      _zfree((&_ipc_object_zones)[*(word *)(piVar1 + 1) & 0x7fff],piVar1);
    }
  }
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  return;
}
