
void sub_40865FC(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uStack_18 = 0x194;
  uStack_14 = 0x193;
  uStack_10 = 0x191;
  uStack_c = 400;
  uStack_8 = 0x192;
  uStack_38 = param_6;
  uStack_34 = param_7;
  uStack_30 = param_3;
  uStack_2c = sub_40865CC(param_4);
  uStack_28 = param_5;
  (*___NXAudioSetStreamParameters)(param_2,&uStack_18,5,&uStack_38);
  return;
}
