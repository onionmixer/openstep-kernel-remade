
void addrerr(undefined8 param_1)

{
  undefined *puVar1;
  undefined auStack_40 [8];
  
  param_1._2_4_ = param_1._2_4_ >> 0x1c;
  if (((param_1._2_4_ != 2) && (param_1._2_4_ != 10)) && (param_1._2_4_ != 0xb)) {
                    /* WARNING: Subroutine does not return */
    _panic(aAddrerrBadExce);
  }
  puVar1 = auStack_40;
  if (((undefined *)0x4001318 < auStack_40) &&
     ((_stack_pointers < auStack_40 || (auStack_40 <= _stack_pointers + -0xff4)))) {
    puVar1 = _stack_pointers;
  }
  *(undefined **)(puVar1 + -4) = auStack_40;
  *(undefined4 *)(puVar1 + -0x14) = 0xc;
  func_0x0400217c();
  return;
}

