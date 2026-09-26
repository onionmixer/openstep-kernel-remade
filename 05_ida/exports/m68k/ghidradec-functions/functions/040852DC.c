
void _snd_reply_ret_samples(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uStack_28 = dword_40B21D8;
  uStack_20 = dword_40B21E0;
  uStack_1c = dword_40B21E4;
  uStack_24 = 0x24;
  uStack_14 = 0x12e;
  uStack_18 = param_1;
  uStack_10 = dword_40B21FC;
  uStack_c = param_2;
  uStack_8 = param_3;
  _msg_send(&uStack_28,0x21,0);
  return;
}
