
uint _zstrygetc(word param_1)

{
  uint uVar1;
  byte *pbVar2;
  
  uVar1 = param_1 & 0x1f;
  if ((param_1 & 0x1f) == 0) {
    pbVar2 = (byte *)(_slot_id_bmap + 0x2018001);
  }
  else {
    pbVar2 = (byte *)(_slot_id_bmap + 0x2018000);
  }
  if (uVar1 < 3) {
    _delay(1);
    if ((*pbVar2 & 1) == 0) {
      uVar1 = 0xffffffff;
    }
    else {
      _delay(1);
      uVar1 = pbVar2[2] & 0x7f;
      if (uVar1 == 0xd) {
        uVar1 = 10;
      }
    }
  }
  return uVar1;
}

