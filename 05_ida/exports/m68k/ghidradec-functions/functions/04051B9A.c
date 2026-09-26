
undefined4 _thread_depress_abort(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 4;
  }
  else {
    if (-1 < *(int *)(param_1 + 0x60)) {
      if (*(int *)(param_1 + 0x16c) != 0) {
        _reset_timeout(param_1 + 0x140);
      }
      *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)(param_1 + 0x60);
      *(undefined4 *)(param_1 + 0x60) = 0xffffffff;
      _compute_priority(param_1,0);
    }
    uVar1 = 0;
  }
  return uVar1;
}
