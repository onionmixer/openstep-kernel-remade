
undefined4 _host_priv_self(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uStack_8;
  
  iVar1 = *(int *)(_active_threads + 0xc);
  iVar2 = _suser();
  if (iVar2 == 0) {
    uStack_8 = 0;
  }
  else if (dword_40B67DC == 0) {
    uStack_8 = 0;
  }
  else {
    uVar3 = _ipc_port_copy_send(dword_40B67DC,0x11,1,&uStack_8);
    _ipc_object_copyout(*(undefined4 *)(iVar1 + 0x7c),uVar3);
  }
  return uStack_8;
}
