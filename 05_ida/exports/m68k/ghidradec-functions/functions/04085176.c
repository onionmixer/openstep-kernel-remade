
void _snd_reply_illegal_msg
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  uint uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uStack_28 = dword_40B21D8;
  uStack_20 = dword_40B21E0;
  uStack_14 = 0x13a;
  uStack_24 = 0x24;
  uStack_1c = param_1;
  uStack_18 = param_2;
  uStack_10 = dword_40B21FC & 0xffff002f | 0x20;
  uStack_c = param_3;
  uStack_8 = param_4;
  _msg_send(&uStack_28,1,0);
  return;
}
