
undefined4 __event_port_by_tag(uint param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uStack_8;
  
  iVar1 = *(int *)(_active_threads + 0xc);
  if ((((param_1 == 0) && (iVar2 = _suser(), iVar2 == 0)) || ((int)param_1 < 0)) || (2 < param_1)) {
    uStack_8 = 0;
  }
  else {
    iVar2 = *(int *)((int)&_ev_port_list + param_1 * 4);
    if (iVar2 == 0) {
      uStack_8 = 0;
    }
    else {
      uVar3 = _ipc_port_copy_send(iVar2,0x11,1,&uStack_8);
      _ipc_object_copyout(*(undefined4 *)(iVar1 + 0x7c),uVar3);
    }
  }
  return uStack_8;
}
