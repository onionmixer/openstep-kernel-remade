
byte _np_printing_shutdown(undefined4 *param_1)

{
  byte *pbVar1;
  uint uVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  byte bVar7;
  
  pbVar1 = (byte *)*param_1;
  uVar2 = *(uint *)((int)param_1 + 0x126);
  if (uVar2 == 4) {
    _untimeout(_np_printing_timeout,param_1);
    cVar3 = '\0';
    _np_send(pbVar1,7,0);
    _dma_abort(param_1 + 1);
    *pbVar1 = *pbVar1 & 0x7f;
    cVar4 = (int)param_1 < 0;
    cVar5 = param_1 == (undefined4 *)0x0;
    cVar6 = '\0';
    bVar7 = 0;
    _np_setstate(param_1,5);
    bVar7 = cVar3 << 4 | cVar4 << 3 | cVar5 << 2 | cVar6 << 1 | bVar7;
  }
  else {
    bVar7 = (4 < uVar2) << 4 | ((int)(4 - uVar2) < 0) << 3 | SBORROW4(4,uVar2) << 1 | 4 < uVar2;
  }
  return bVar7;
}
