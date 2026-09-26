
undefined4 _PCbopFA(undefined4 param_1,int param_2,undefined4 *param_3)

{
  uint uVar1;
  
  if ((*(byte *)(param_3 + 1) & 4) == 0) {
    return 0;
  }
  *(undefined4 *)(param_2 + 0x38) = *param_3;
  *(undefined2 *)(param_2 + 0x3c) = *(undefined2 *)(param_3 + 1);
  uVar1 = param_3[2];
  *(uint *)(param_2 + 0x40) = uVar1;
  *(uint *)(param_2 + 0x40) = uVar1 & 0x50fd7 | 0x202;
  *(undefined4 *)(param_2 + 0x44) = param_3[3];
  *(undefined2 *)(param_2 + 0x48) = *(undefined2 *)(param_3 + 4);
                    /* WARNING: Subroutine does not return */
  _thread_exception_return();
}

