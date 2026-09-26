
undefined4
_catch_exception_raise
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  undefined4 uVar2;
  int iStack_c;
  undefined4 uStack_8;
  
  uVar2 = 0;
  iStack_c = 0;
  iVar1 = _object_copyin(*(undefined4 *)(_active_threads + 0xc),param_2,6,0,&uStack_8);
  if (iVar1 != 0) {
    iVar1 = _convert_port_to_thread(uStack_8);
    _port_release(uStack_8);
    if (iVar1 != 0) {
      sub_405C390(param_4,param_5,param_6,&iStack_c,*(int *)(iVar1 + 0x80) + 0x6c);
      if (iStack_c != 0) {
        _thread_psignal(iVar1,iStack_c);
      }
      _thread_deallocate(iVar1);
      goto loc_405C368;
    }
  }
  uVar2 = 4;
loc_405C368:
  _port_deallocate_EXTERNAL(dword_40B4DF0,param_3);
  _port_deallocate_EXTERNAL(dword_40B4DF0,param_2);
  return uVar2;
}

