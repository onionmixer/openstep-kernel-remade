
void _AlphaLockFeedback(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = 0x30000;
  }
  _km_send(0xc5,uVar1);
  _adb_keyboard_LED(param_1);
  return;
}
