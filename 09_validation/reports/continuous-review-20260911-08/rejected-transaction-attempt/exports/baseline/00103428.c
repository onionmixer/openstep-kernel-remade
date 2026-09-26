
int _compress(Bytef *dest,uLongf *destLen,Bytef *source,uLong sourceLen)

{
  uint uVar1;
  undefined4 local_c;
  undefined4 local_8;
  
  local_c = 0;
  uVar1 = 0;
  local_8 = (int)dest * 0x40;
  if (destLen != (uLongf *)0x0) {
    local_8 = local_8 + (int)destLen / 0x3d09;
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

