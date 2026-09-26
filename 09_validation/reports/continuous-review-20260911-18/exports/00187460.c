
undefined4 _PMSetCpuState(int param_1)

{
  uint uVar1;
  undefined1 local_34 [4];
  undefined1 local_30;
  byte local_2f;
  undefined2 local_14;
  undefined2 local_12;
  byte local_c;
  undefined4 local_8;
  
  if (DAT_001e75b8 == 0) {
    if (param_1 != 0) {
      return 0;
    }
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if (param_1 == 0) {
    local_30 = 5;
  }
  else {
    if (param_1 != 1) {
      uVar1 = 0;
      goto LAB_001874d2;
    }
    local_30 = 6;
  }
  local_2f = 0x53;
  local_14 = 0x78;
  local_12 = 0x10;
  local_8 = DAT_001e75b4;
  _bios32(local_34);
  if ((local_c & 1) == 0) {
    return 0x3e80060;
  }
  if (local_2f == 0) {
    uVar1 = 0x3e80101;
  }
  else {
    uVar1 = local_2f | 0x3e80000;
  }
LAB_001874d2:
  if (uVar1 == 0) {
    return 0x3e80060;
  }
  return 0;
}

