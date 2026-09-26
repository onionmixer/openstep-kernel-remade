
undefined4 _ipc_object_copyout_type_compat(uint param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0x10) {
    uVar1 = 5;
  }
  else {
    if ((param_1 < 0x10) || (0x12 < param_1)) {
                    /* WARNING: Subroutine does not return */
      _panic(aIpcObjectCopyo_0);
    }
    uVar1 = 6;
  }
  return uVar1;
}
