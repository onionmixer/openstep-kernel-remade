
void sub_406D5CE(undefined4 param_1,word param_2,word param_3)

{
  undefined auStack_5e [2];
  undefined4 uStack_5c;
  undefined4 uStack_58;
  word wStack_54;
  undefined4 uStack_44;
  
  _bzero(auStack_5e,0x5a);
  wStack_54 = CONCAT11(0x12,(undefined)wStack_54);
  wStack_54 = wStack_54 & 0xfffc | (param_2 & 1) << 1 | param_3 & 1;
  uStack_5c = 10000;
  uStack_58 = 1;
  uStack_44 = 2;
  _fc_send_cmd(param_1,auStack_5e);
  return;
}

