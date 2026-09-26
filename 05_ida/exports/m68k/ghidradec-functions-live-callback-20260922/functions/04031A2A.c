
undefined4 * _other_specvp(undefined4 *param_1)

{
  undefined4 *puVar1;
  word wVar2;
  
  wVar2 = *(word *)(*(int *)((int)param_1 + 0x2e) + 0x40);
  puVar1 = *(undefined4 **)(_stable + ((uint)(byte)wVar2 + (uint)(wVar2 >> 8) & 0xf) * 4);
  while( true ) {
    if (puVar1 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
    if (((wVar2 == *(word *)(puVar1 + 0x10)) && (param_1 != puVar1 + 1)) &&
       (puVar1[0xb] == param_1[10])) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  return puVar1 + 1;
}

