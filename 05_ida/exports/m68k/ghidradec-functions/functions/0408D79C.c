
undefined4 _zsint(void)

{
  byte bVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  while( true ) {
    _delay(1);
    *(undefined *)(_slot_id_bmap + 0x2018001) = 3;
    _delay(1);
    bVar1 = *(byte *)(_slot_id_bmap + 0x2018001);
    if (bVar1 == 0) break;
    if ((bVar1 & 8) != 0) {
      (**(code **)(*off_40B243E + 8))(0);
      uVar2 = 1;
    }
    if ((bVar1 & 1) != 0) {
      (*(code *)off_40B2446[2])(1);
      uVar2 = 1;
    }
    if ((bVar1 & 0x20) != 0) {
      (**(code **)(*off_40B243E + 4))(0);
      uVar2 = 1;
    }
    if ((bVar1 & 4) != 0) {
      (*(code *)off_40B2446[1])(1);
      uVar2 = 1;
    }
    if ((bVar1 & 0x10) != 0) {
      (**(code **)*off_40B243E)(0);
      uVar2 = 1;
    }
    if ((bVar1 & 2) != 0) {
      (*(code *)*off_40B2446)(1);
      uVar2 = 1;
    }
  }
  return uVar2;
}
