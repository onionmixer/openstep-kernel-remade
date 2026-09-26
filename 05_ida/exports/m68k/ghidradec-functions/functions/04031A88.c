
undefined4 * _slookup(int param_1,word param_2)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(_stable + ((uint)(byte)param_2 + (uint)(param_2 >> 8) & 0xf) * 4);
  while( true ) {
    if (puVar1 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
    if ((param_2 == *(word *)(puVar1 + 0x10)) && (param_1 == puVar1[0xb])) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  *(sword *)((int)puVar1 + 10) = *(sword *)((int)puVar1 + 10) + 1;
  return puVar1 + 1;
}
