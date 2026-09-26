
void _ttypend(undefined4 *param_1)

{
  int iVar1;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  *(byte *)((int)param_1 + 0x3a) = *(byte *)((int)param_1 + 0x3a) & 0xdf;
  *(byte *)((int)param_1 + 0x3f) = *(byte *)((int)param_1 + 0x3f) | 0x10;
  uStack_10 = *param_1;
  uStack_c = param_1[1];
  uStack_8 = param_1[2];
  *param_1 = 0;
  param_1[2] = 0;
  param_1[1] = 0;
  while( true ) {
    iVar1 = _getc(&uStack_10);
    if (iVar1 < 0) break;
    _ttyinput(iVar1,param_1);
  }
  *(byte *)((int)param_1 + 0x3f) = *(byte *)((int)param_1 + 0x3f) & 0xef;
  return;
}

