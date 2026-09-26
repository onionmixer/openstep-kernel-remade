
void _adb_listen(sword param_1,word param_2,undefined4 param_3,undefined4 param_4)

{
  word unaff_D2w;
  
  sub_40645EA(unaff_D2w & 0xff | param_1 << 0xc | 0x800 | (param_2 & 3) << 8,param_3,param_4,1);
  return;
}

