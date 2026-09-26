
/* WARNING: Control flow encountered bad instruction data */

undefined4 _ipc_object_copyin_type(undefined4 param_1)

{
  undefined4 uVar1;
  
  switch(param_1) {
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  :
                    /* WARNING: Subroutine does not return */
    _panic(aIpcObjectCopyi);
  case :
  case :
    uVar1 = 0x10;
    break;
  case :
  case :
  case :
  case :
    uVar1 = 0x11;
    break;
  case :
  case :
    uVar1 = 0x12;
  }
  return uVar1;
}

