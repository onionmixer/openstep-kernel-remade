
void _sunsave(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = (undefined4 *)0x0;
  puVar2 = *(undefined4 **)
            (_stable +
            ((*(word *)(param_1 + 0x10) & 0xff) + (uint)(*(word *)(param_1 + 0x10) >> 8) & 0xf) * 4)
  ;
  while( true ) {
    if (puVar2 == (undefined4 *)0x0) {
      return;
    }
    if (param_1 == puVar2) break;
    puVar1 = puVar2;
    puVar2 = (undefined4 *)*puVar2;
  }
  if (puVar1 == (undefined4 *)0x0) {
    *(undefined4 *)
     (_stable +
     ((*(word *)(puVar2 + 0x10) & 0xff) + (uint)(*(word *)(puVar2 + 0x10) >> 8) & 0xf) * 4) =
         *puVar2;
    return;
  }
  *puVar1 = *puVar2;
  return;
}

