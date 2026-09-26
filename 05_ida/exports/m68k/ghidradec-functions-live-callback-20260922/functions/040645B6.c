
void sub_40645B6(int param_1)

{
  uint *puVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(_slot_id + 0x2208020);
  puVar1 = (uint *)(_slot_id + 0x2208000);
  *puVar1 = *puVar1;
  *puVar2 = 8;
  if (param_1 != 0) {
    do {
    } while ((*puVar1 & 8) == 0);
    *puVar1 = 8;
  }
  return;
}

