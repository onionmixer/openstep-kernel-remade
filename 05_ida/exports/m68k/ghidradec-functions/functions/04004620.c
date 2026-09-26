
void _closef(int param_1)

{
  sword sVar1;
  
  if (param_1 != 0) {
    sVar1 = *(sword *)(param_1 + 0xe);
    if (sVar1 < 2) {
      if (sVar1 != 1) {
                    /* WARNING: Subroutine does not return */
        _panic(aFpNotOne);
      }
      if (*(int *)(param_1 + 0x12) != 0) {
        (**(code **)(*(int *)(param_1 + 0x12) + 0xc))(param_1);
      }
      _crfree(*(undefined4 *)(param_1 + 0x1e));
      if (*(sword *)(param_1 + 0xe) != 1) {
                    /* WARNING: Subroutine does not return */
        _panic(aFpNotOne2);
      }
      *(undefined2 *)(param_1 + 0xe) = 0;
      _free_file(param_1);
    }
    else {
      *(sword *)(param_1 + 0xe) = sVar1 + -1;
    }
  }
  return;
}
