
void _snd_reply_ret_device(undefined4 param_1,undefined4 param_2)

{
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uStack_1c = dword_40B21D8;
  uStack_18 = dword_40B21DC;
  uStack_14 = dword_40B21E0;
  uStack_8 = 0x12f;
  uStack_10 = param_2;
  uStack_c = param_1;
  _msg_send(&uStack_1c,1,0);
  return;
}

