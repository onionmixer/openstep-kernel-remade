
undefined8 __regparm3 FUN_00186d80(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 auStack_30 [16];
  
  iVar1 = _empty_stacks;
  puVar2 = auStack_30;
  if (_empty_stacks != 0) {
    _empty_stacks = 0;
    puVar2 = _stack_pointers;
  }
  *(undefined1 **)(puVar2 + -4) = auStack_30;
  *(undefined4 *)(puVar2 + -8) = 0x186dc6;
  _catch_interrupt();
  _empty_stacks = iVar1;
  return CONCAT44(param_2,param_1);
}

