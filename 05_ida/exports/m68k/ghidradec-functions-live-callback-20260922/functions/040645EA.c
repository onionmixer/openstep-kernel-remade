
void sub_40645EA(uint param_1,undefined4 *param_2,int param_3,int param_4)

{
  uint *puVar1;
  int *piVar2;
  undefined4 *puVar3;
  
  piVar2 = (int *)(_slot_id + 0x2208038);
  puVar3 = (undefined4 *)(_slot_id + 0x2208020);
  puVar1 = (uint *)(_slot_id + 0x2208000);
  *(uint *)(_slot_id + 0x2208030) = param_1 >> 8 & 0xff;
  if (param_2 == (undefined4 *)0x0) {
    *piVar2 = 0;
  }
  else {
    if (0 < param_3) {
      *(undefined4 *)(_slot_id + 0x2208080) = *param_2;
    }
    if (4 < param_3) {
      *(undefined4 *)(_slot_id + 0x2208088) = param_2[1];
    }
    *piVar2 = param_3 << 3;
  }
  *puVar3 = 4;
  if (param_4 != 0) {
    do {
    } while ((*puVar1 & 4) == 0);
    *puVar1 = 4;
  }
  return;
}

