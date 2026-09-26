
void _DoModCalc(int param_1,int param_2)

{
  byte bVar1;
  undefined2 uStack_10;
  undefined2 uStack_e;
  undefined2 uStack_c;
  undefined2 uStack_a;
  undefined2 uStack_8;
  undefined2 uStack_6;
  
  bVar1 = *(byte *)(param_1 + 2 + param_2);
  if ((bVar1 & 0x10) != 0) {
    _CalcModBit(param_1,bVar1 & 0xf);
    if ((bVar1 & 0x20) == 0) {
      uStack_8 = (undefined2)param_2;
      uStack_6 = 0;
      uStack_e = 0;
      uStack_a = 0;
      uStack_c = 0;
      uStack_10 = 0;
      _LLEventPost(0xc,*(undefined4 *)(_evg + 0x18),&uStack_10);
    }
  }
  return;
}

