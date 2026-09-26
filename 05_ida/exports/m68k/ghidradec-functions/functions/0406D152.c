
void _fc_configure(undefined4 param_1)

{
  undefined auStack_5e [2];
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined uStack_54;
  undefined uStack_53;
  byte bStack_52;
  undefined uStack_51;
  undefined4 uStack_44;
  
  _bzero(auStack_5e,0x5a);
  uStack_54 = 0x13;
  uStack_53 = 0;
  bStack_52 = byte_40B14AD | byte_40B14A9 | 0x50;
  uStack_51 = 0;
  uStack_5c = 10000;
  uStack_58 = 1;
  uStack_44 = 4;
  _fc_send_cmd(param_1,auStack_5e);
  return;
}
