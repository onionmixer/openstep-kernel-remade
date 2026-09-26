/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015a4fc */

undefined4 __event_port_by_tag(uint param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_8;
  
  iVar1 = *(int *)(_active_threads + 0xc);
  if ((((param_1 == 0) && (iVar2 = _suser(), iVar2 == 0)) || ((int)param_1 < 0)) || (2 < param_1)) {
    local_8 = 0;
  }
  else if ((&_ev_port_list)[param_1] == 0) {
    local_8 = 0;
  }
  else {
    uVar3 = _ipc_port_copy_send((&_ev_port_list)[param_1],0x11,1,&local_8);
    _ipc_object_copyout(*(undefined4 *)(iVar1 + 0x88),uVar3);
  }
  return local_8;
}

