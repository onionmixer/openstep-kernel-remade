
void std_trap(word param_1)

{
  undefined *puVar1;
  undefined auStack_40 [8];
  
  puVar1 = auStack_40;
  if (((undefined *)0x4001318 < auStack_40) &&
     ((_stack_pointers < auStack_40 || (auStack_40 <= _stack_pointers + -0xff4)))) {
    puVar1 = _stack_pointers;
  }
  *(undefined **)(puVar1 + -4) = auStack_40;
  *(uint *)(puVar1 + -0x14) = param_1 & 0xfff;
  func_0x0400217c();
  return;
}
