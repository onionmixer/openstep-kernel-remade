
uint * _get_posix_proc(uint param_1)

{
  uint *puVar1;
  undefined auStack_54 [80];
  
  puVar1 = *(uint **)(_posix_proc_hash + (param_1 & 0x3f) * 4);
  while( true ) {
    if (puVar1 == (uint *)0x0) {
      _sprintf(auStack_54,aGetPosixProcNo,param_1);
                    /* WARNING: Subroutine does not return */
      _panic(auStack_54);
    }
    if (param_1 == *puVar1) break;
    puVar1 = *(uint **)((int)puVar1 + 0x1a);
  }
  return puVar1;
}
