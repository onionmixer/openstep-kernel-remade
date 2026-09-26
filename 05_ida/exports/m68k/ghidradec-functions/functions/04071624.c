
void _alert(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
           undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
           undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12)

{
  undefined uStack_104;
  undefined uStack_103;
  undefined uStack_102;
  
  if ((unk_40B6904 & 0x20) != 0) {
    _alert_done();
  }
  if ((_cons_tp == _cons) && ((unk_40B6904 & 8) != 0)) {
    if (word_40B6938 != 0) {
      word_40B6938 = word_40B6938 + 1;
    }
  }
  else {
    _alert_lock_screen(1);
    _kmpopup(param_3,1,param_1,param_2,1);
    word_40B6938 = word_40B6938 + 1;
  }
  _alert_key = 0;
  unk_40B6904 = unk_40B6904 | 0x120;
  uStack_104 = 0x25;
  uStack_103 = 0x4c;
  uStack_102 = 0;
  _strcat(&uStack_104,param_4);
  _printf(&uStack_104,param_5,param_6,param_7,param_8,param_9,param_10,param_11,param_12);
  return;
}
