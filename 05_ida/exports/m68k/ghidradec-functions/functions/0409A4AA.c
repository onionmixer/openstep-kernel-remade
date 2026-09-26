
void _traceback(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (_traceback_recursive != 0) {
    _printf(aTracebackRecur);
                    /* WARNING: Subroutine does not return */
    _longjmp(_traceback_jb);
  }
  _traceback_recursive = 1;
  _printf(aTracebackFp0xX,param_1);
  puVar3 = _interrupt_stack;
  puVar1 = _interrupt_stack + 0x400;
  do {
    puVar2 = param_1;
    if ((((uint)puVar2 & 1) != 0) ||
       (((puVar2 < puVar3 || (puVar1 < puVar2)) &&
        ((puVar2 < (undefined4 *)0x10000000 || ((undefined4 *)0x14000000 < puVar2))))))
    goto loc_409A556;
    _printf(aCalledFromPc0x,puVar2[1],*puVar2,puVar2[2],puVar2[3],puVar2[4],puVar2[5]);
    param_1 = (undefined4 *)*puVar2;
  } while ((undefined4 *)*puVar2 != puVar2);
  _printf(aLoopingFp);
loc_409A556:
  _printf(aLastFp0xX,puVar2);
  _traceback_recursive = 0;
  return;
}
