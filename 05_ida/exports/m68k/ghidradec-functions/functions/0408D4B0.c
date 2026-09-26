
void _zsputc(word param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  byte bVar3;
  int iVar4;
  byte *pbVar5;
  
  uVar2 = param_1 & 0x1f;
  if ((param_1 & 0x1f) == 0) {
    pbVar5 = (byte *)(_slot_id_bmap + 0x2018001);
  }
  else {
    pbVar5 = (byte *)(_slot_id_bmap + 0x2018000);
  }
  if (uVar2 < 3) {
    if (*(int *)(unk_40B52C8 + uVar2 * 4) == 0) {
      *(undefined4 *)(unk_40B52C8 + uVar2 * 4) = 1;
      sub_408D2BE(pbVar5,0x2580);
    }
    if (param_2 != 0) {
      iVar4 = 30000;
      do {
        _delay(1);
        if ((*pbVar5 & 4) != 0) break;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      _delay(1);
      _delay(1);
      *(undefined *)(_slot_id_bmap + 0x2018001) = 3;
      _delay(1);
      bVar1 = *(byte *)(_slot_id_bmap + 0x2018001);
      bVar3 = 0x10;
      if ((param_1 & 0x1f) != 0) {
        bVar3 = 2;
      }
      _delay(1);
      pbVar5[2] = (byte)param_2;
      _delay(1);
      do {
      } while ((*pbVar5 & 4) == 0);
      _delay(1);
      if ((bVar3 & bVar1) == 0) {
        *pbVar5 = 0x28;
      }
      _delay(1);
      if (param_2 == 10) {
        _zsputc((int)(sword)param_1,0xd);
      }
    }
  }
  return;
}
