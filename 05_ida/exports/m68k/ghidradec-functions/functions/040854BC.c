
void _snd_reply_ret_formats
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6)

{
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  uint uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uStack_34 = dword_40B21D8;
  uStack_2c = dword_40B21E0;
  uStack_28 = dword_40B21E4;
  uStack_20 = 0x140;
  uStack_30 = 0x30;
  uStack_24 = param_1;
  uStack_1c = dword_40B21FC & 0xffff005f | 0x50;
  uStack_18 = param_2;
  uStack_14 = param_3;
  uStack_10 = param_4;
  uStack_c = param_5;
  uStack_8 = param_6;
  _msg_send(&uStack_34,1,0);
  return;
}
