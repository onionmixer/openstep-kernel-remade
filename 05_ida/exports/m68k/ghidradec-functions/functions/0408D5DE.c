
uint _zsgetc(word param_1)

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
    if (*(int *)(unk_40B52C8 + uVar1 * 4) == 0) {
      *(undefined4 *)(unk_40B52C8 + uVar1 * 4) = 1;
      sub_408D2BE(pbVar2,0x2580);
    }
    do {
      _delay(1);
    } while ((*pbVar2 & 1) == 0);
    _delay(1);
    uVar1 = pbVar2[2] & 0x7f;
    if (uVar1 == 0xd) {
      uVar1 = 10;
    }
    _zsputc((int)(sword)param_1,uVar1);
  }
  return uVar1;
}
