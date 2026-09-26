/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015a39c */

undefined4 _host_priv_self(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_8;
  
  iVar1 = *(int *)(_active_threads + 0xc);
  iVar2 = _suser();
  if (iVar2 == 0) {
    local_8 = 0;
  }
  else if (DAT_001e97b4 == 0) {
    local_8 = 0;
  }
  else {
    uVar3 = _ipc_port_copy_send(DAT_001e97b4,0x11,1,&local_8);
    _ipc_object_copyout(*(undefined4 *)(iVar1 + 0x88),uVar3);
  }
  return local_8;
}

