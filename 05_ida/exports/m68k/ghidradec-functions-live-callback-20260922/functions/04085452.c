
void _snd_reply_ret_volume(undefined4 param_1,undefined4 param_2)

{
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uStack_24 = dword_40B21D8;
  uStack_1c = dword_40B21E0;
  uStack_18 = dword_40B21E4;
  uStack_10 = 0x132;
  uStack_20 = 0x20;
  uStack_14 = param_1;
  uStack_c = dword_40B21FC;
  uStack_8 = param_2;
  _msg_send(&uStack_24,1,0);
  return;
}

