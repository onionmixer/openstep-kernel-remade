
byte _od_run_out(int param_1)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  byte bVar5;
  
  cVar1 = (_od_spl & 0x10) != 0;
  _od_runout = 2;
  cVar2 = param_1 < 0;
  cVar3 = param_1 == 0;
  cVar4 = '\0';
  bVar5 = 0;
  _od_ctrl_start(param_1);
  return cVar1 << 4 | cVar2 << 3 | cVar3 << 2 | cVar4 << 1 | bVar5;
}
