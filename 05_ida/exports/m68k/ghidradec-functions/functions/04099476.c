
void _gets(byte *param_1,byte *param_2)

{
  byte bVar1;
  undefined4 uVar2;
  
loc_409948C:
  do {
    bVar1 = _cngetc();
    bVar1 = bVar1 & 0x7f;
    if (bVar1 == 0xd) {
loc_40994C4:
      *param_2 = 0;
      return;
    }
    if (bVar1 < 0xe) {
      if (bVar1 != 8) {
        if (bVar1 != 10) goto loc_409950C;
        goto loc_40994C4;
      }
loc_40994E0:
      if (param_1 == param_2) {
        uVar2 = 8;
loc_4099502:
        _cnputc(uVar2);
      }
      else {
        _cnputc(0x20);
        _cnputc(8);
        param_2 = param_2 + -1;
      }
      goto loc_409948C;
    }
    if (bVar1 == 0x40) {
loc_40994FC:
      uVar2 = 10;
      param_2 = param_1;
      goto loc_4099502;
    }
    if (bVar1 < 0x41) {
      if (bVar1 == 0x15) goto loc_40994FC;
    }
    else if (bVar1 == 0x7f) {
      if (param_1 != param_2) {
        _cnputc(8);
        _cnputc(8);
        goto loc_40994E0;
      }
      uVar2 = 8;
      goto loc_4099502;
    }
loc_409950C:
    *param_2 = bVar1;
    param_2 = param_2 + 1;
  } while( true );
}
