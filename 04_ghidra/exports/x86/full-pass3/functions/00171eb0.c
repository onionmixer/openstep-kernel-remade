/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00171eb0 */

undefined4
_catch_exception_raise
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  undefined4 uVar2;
  int local_c;
  undefined4 local_8;
  
  uVar2 = 0;
  local_c = 0;
  iVar1 = _object_copyin(*(undefined4 *)(_active_threads + 0xc),param_2,6,0,&local_8);
  if (iVar1 != 0) {
    iVar1 = _convert_port_to_thread(local_8);
    _port_release(local_8);
    if (iVar1 != 0) {
      FUN_00171f6c(param_4,param_5,param_6,&local_c,*(int *)(iVar1 + 0x84) + 0x74);
      if (local_c != 0) {
        _thread_psignal(iVar1,local_c);
      }
      _thread_deallocate(iVar1);
      goto LAB_00171f41;
    }
  }
  uVar2 = 4;
LAB_00171f41:
  _port_deallocate_EXTERNAL(DAT_001e7284,param_3);
  _port_deallocate_EXTERNAL(DAT_001e7284,param_2);
  return uVar2;
}

