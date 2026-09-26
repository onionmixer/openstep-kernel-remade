
undefined4 _isclosing(word param_1,int param_2)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(_stable + ((uint)(byte)param_1 + (uint)(param_1 >> 8) & 0xf) * 4);
  while( true ) {
    if (puVar1 == (undefined4 *)0x0) {
      return 0;
    }
    if (((param_1 == *(word *)(puVar1 + 0x10)) && (param_2 == puVar1[0xb])) &&
       ((*(byte *)((int)puVar1 + 0x3f) & 8) != 0)) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  return 1;
}
