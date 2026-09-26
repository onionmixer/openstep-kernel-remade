/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015a3f8 */

undefined4 _device_master_self(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 local_8;
  
  iVar1 = *(int *)(_active_threads + 0xc);
  iVar2 = _suser();
  iVar4 = DAT_001e97b4;
  if (iVar2 == 0) {
    iVar4 = _realhost;
  }
  if (iVar4 == 0) {
    local_8 = 0;
  }
  else {
    uVar3 = _ipc_port_copy_send(iVar4,0x11,1,&local_8);
    _ipc_object_copyout(*(undefined4 *)(iVar1 + 0x88),uVar3);
  }
  return local_8;
}

