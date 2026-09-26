
undefined4 * _pgfind(uint param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(&_pgrphash)[param_1 & 0x3f];
  while( true ) {
    if (puVar1 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
    if (param_1 == puVar1[3]) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  return puVar1;
}

