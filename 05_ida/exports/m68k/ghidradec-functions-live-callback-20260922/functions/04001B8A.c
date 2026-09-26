
undefined8 ipl1(void)

{
  int iVar1;
  undefined4 in_D0;
  undefined4 in_D1;
  undefined4 *puVar2;
  byte in_stack_00000000;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  
  puVar2 = &uStack_40;
  if ((undefined4 *)0x4001318 < &uStack_40) {
    puVar2 = (undefined4 *)0x4001318;
  }
  uStack_40 = in_D0;
  uStack_3c = in_D1;
  puVar2[-1] = 0;
  puVar2[-2] = 0x4001bbe;
  _softint_run();
  iVar1 = _stack_pointers;
  if ((((in_stack_00000000 & 0x20) == 0) && (_active_threads != 0)) &&
     ((*(byte *)(*(int *)(_active_threads + 0x24) + 0x54) & 0x10) != 0)) {
    *(undefined4 **)(_stack_pointers + -4) = &uStack_40;
    *(undefined4 *)(iVar1 + -8) = 0x4002200;
    _check_for_ast();
  }
  return CONCAT44(uStack_40,uStack_3c);
}

