
bool sub_407E572(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined auStack_56 [12];
  undefined4 uStack_4a;
  undefined4 uStack_46;
  undefined4 uStack_42;
  undefined4 uStack_3e;
  
  _bzero(auStack_56,0x52);
  auStack_56[0] = 0x25;
  uStack_46 = param_2;
  uStack_42 = 8;
  uStack_4a = 0;
  uStack_3e = 0x3c;
  iVar1 = sub_407E678(param_1,auStack_56,param_3);
  if (iVar1 != 0) {
    _printf(aErrorCanTReadD);
  }
  return iVar1 != 0;
}

