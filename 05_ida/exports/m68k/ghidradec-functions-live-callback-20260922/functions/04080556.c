
undefined4 _snd_dsp_cmd_port_msg(int param_1)

{
  undefined4 uVar1;
  
  switch(*(undefined4 *)(param_1 + 0x14)) {
  case :
    uVar1 = sub_408067A(param_1);
    break;
  case :
    uVar1 = sub_4080B2E(param_1);
    break;
  case :
    uVar1 = sub_4080BE6(param_1);
    break;
  case :
    uVar1 = sub_4080D78(param_1);
    break;
  case :
    uVar1 = sub_4080E6E(param_1);
    break;
  case :
    uVar1 = sub_4080F78(param_1);
    break;
  case :
    uVar1 = sub_4080F82(param_1);
    break;
  case :
    uVar1 = sub_4080FE0(param_1);
    break;
  :
    uVar1 = 0x66;
  }
  return uVar1;
}

