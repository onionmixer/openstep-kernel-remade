
undefined4 _adb_poll_keyboard(undefined4 *param_1)

{
  uint uVar1;
  word in_D1w;
  undefined4 uVar2;
  undefined4 *puVar3;
  uint *puVar4;
  
  uVar2 = 0;
  puVar4 = (uint *)(_slot_id + 0x2208028);
  puVar3 = (undefined4 *)(_slot_id + 0x2208020);
  if (dword_40B0830 == 0) {
    uVar2 = 0;
  }
  else {
    uVar1 = *(uint *)(_slot_id + 0x2208000);
    *(uint *)(_slot_id + 0x2208000) = uVar1;
    *puVar3 = 0x10;
    if ((uVar1 & 4) == 0) {
      if ((*puVar4 & 0x20) != 0) {
        return 0;
      }
    }
    else if ((dword_40B0834 == 2) && ((*puVar4 & 8) != 0)) {
      uVar1 = *(uint *)(_slot_id + 0x2208038) >> 3;
      if (uVar1 != 0) {
        *param_1 = *(undefined4 *)(_slot_id + 0x2208080);
      }
      if (4 < uVar1) {
        param_1[1] = *(undefined4 *)(_slot_id + 0x2208088);
      }
      uVar2 = 1;
    }
    dword_40B0834 = 2;
    sub_40645EA(in_D1w & 0xcff | 0x2c00,0,0,0);
    _delay(8000);
  }
  return uVar2;
}

