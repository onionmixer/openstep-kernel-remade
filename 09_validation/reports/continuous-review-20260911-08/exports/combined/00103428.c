
int _compress(int seconds,int microseconds)

{
  uint uVar1;
  undefined4 local_c;
  undefined4 local_8;
  
  local_c = 0;
  uVar1 = 0;
  local_8 = seconds * 0x40;
  if (microseconds != 0) {
    local_8 = local_8 + microseconds / 0x3d09;
  }
  for (; 0x1fff < (int)local_8; local_8 = (int)local_8 >> 3) {
    local_c = local_c + 1;
    uVar1 = local_8 & 4;
  }
  if ((uVar1 != 0) && (local_8 = local_8 + 1, 0x1fff < (int)local_8)) {
    local_8 = (int)local_8 >> 3;
    local_c = local_c + 1;
  }
  return local_c * 0x2000 + local_8;
}

