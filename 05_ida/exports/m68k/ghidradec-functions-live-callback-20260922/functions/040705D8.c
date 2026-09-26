
void sub_40705D8(uint param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = (param_1 & 0xffff) >> 8;
  uVar2 = 0;
  if ((uVar1 & 0x40) != 0) {
    uVar2 = 0x80020;
  }
  if ((uVar1 & 0x20) != 0) {
    uVar2 = uVar2 | 0x80040;
  }
  if ((uVar1 & 0x10) != 0) {
    uVar2 = uVar2 | 0x100010;
  }
  if ((uVar1 & 8) != 0) {
    uVar2 = uVar2 | 0x100008;
  }
  if ((uVar1 & 4) != 0) {
    uVar2 = uVar2 | 0x20004;
  }
  if ((uVar1 & 2) != 0) {
    uVar2 = uVar2 | 0x20002;
  }
  if ((uVar1 & 1) != 0) {
    uVar2 = uVar2 | 0x40001;
  }
  _DoSpecialKey(param_1 & 0x7f,-(int)-(param_2 == 0),uVar2);
  return;
}

