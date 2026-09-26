
undefined4 _PCbopFC(undefined4 param_1,int param_2,ushort *param_3)

{
  if ((param_3[1] & 4) == 0) {
    return 0;
  }
  *(uint *)(param_2 + 0x38) = (uint)*param_3;
  *(ushort *)(param_2 + 0x3c) = param_3[1];
  *(uint *)(param_2 + 0x40) = param_3[2] & 0xfd7 | 0x202;
  *(uint *)(param_2 + 0x44) = (uint)param_3[3];
  *(ushort *)(param_2 + 0x48) = param_3[4];
                    /* WARNING: Subroutine does not return */
  _thread_exception_return();
}

