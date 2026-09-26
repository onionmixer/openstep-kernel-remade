
bool _rpsleep(code *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
             undefined4 param_5)

{
  int iVar1;
  undefined auStack_38 [52];
  
  if (-1 < (char)*(byte *)(dword_40B57D4 + 0x6a)) {
    *(byte *)(dword_40B57D4 + 0x6a) = *(byte *)(dword_40B57D4 + 0x6a) | 0x80;
    _uprintf(aSSSPausing,_active_u + 8,param_4,param_5);
  }
  _bcopy(dword_40B57D4 + 0x28,auStack_38,0x34);
  iVar1 = _setjmp(dword_40B57D4 + 0x28);
  if (iVar1 == 0) {
    (*param_1)(param_2,param_3);
  }
  _bcopy(auStack_38,dword_40B57D4 + 0x28,0x34);
  if (-1 < *(char *)(dword_40B57D4 + 0x6a)) {
    _rpcont();
  }
  return iVar1 == 0;
}
