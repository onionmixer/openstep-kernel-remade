
char sub_408D2BE(byte *param_1,undefined4 param_2)

{
  uint uVar1;
  undefined uVar2;
  byte bVar3;
  char cVar4;
  
  bVar3 = 0x40;
  if ((byte *)(_slot_id_bmap + 0x2018001) == param_1) {
    bVar3 = 0x80;
  }
  _delay(1);
  *param_1 = 9;
  _delay(1);
  *param_1 = bVar3 | 2;
  _delay(10);
  _delay(1);
  *param_1 = 1;
  _delay(1);
  *param_1 = 0;
  _delay(1);
  *param_1 = 9;
  _delay(1);
  *param_1 = 2;
  _delay(1);
  *param_1 = 10;
  _delay(1);
  *param_1 = 0;
  _delay(1);
  *param_1 = 0xb;
  _delay(1);
  *param_1 = 0x50;
  _delay(1);
  *param_1 = 0xf;
  _delay(1);
  *param_1 = 0;
  _delay(1);
  *param_1 = 4;
  _delay(1);
  *param_1 = 0x44;
  _delay(1);
  *param_1 = 3;
  _delay(1);
  *param_1 = 0xc0;
  _delay(1);
  *param_1 = 5;
  _delay(1);
  *param_1 = 0x60;
  _delay(1);
  *param_1 = 0xe;
  _delay(1);
  *param_1 = 0;
  uVar1 = _zs_tc(param_2,0x10);
  uVar2 = 0x30;
  if (_dma_chip == 0x139) {
    uVar2 = 10;
  }
  *(undefined *)(_slot_id_bmap + 0x2018004) = uVar2;
  _delay(1);
  *param_1 = 0xc;
  _delay(1);
  *param_1 = (byte)uVar1;
  _delay(1);
  *param_1 = 0xd;
  _delay(1);
  cVar4 = (uVar1 >> 7 & 1) != 0;
  *param_1 = (byte)(uVar1 >> 8);
  _delay(1);
  *param_1 = 0xe;
  _delay(1);
  bVar3 = (byte)(uVar1 >> 0x10);
  *param_1 = bVar3;
  _delay(10);
  _delay(1);
  *param_1 = 0xe;
  _delay(1);
  *param_1 = bVar3 | 1;
  _delay(1);
  *param_1 = 3;
  _delay(1);
  *param_1 = 0xc1;
  _delay(1);
  *param_1 = 5;
  _delay(1);
  *param_1 = 0xea;
  _delay(1);
  *param_1 = 0x30;
  _delay(1);
  *param_1 = 0x10;
  _delay(1);
  *param_1 = 0x28;
  return cVar4 << 4;
}

