
byte _ttyclose(undefined *param_1)

{
  undefined *puVar1;
  int iVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  byte bVar7;
  
  iVar2 = _ttynty(param_1);
  if (param_1 == _cons_tp) {
    _cons_tp = _cons;
    (**(code **)(DAT_40b0ad0 + (uint)(*(word *)(param_1 + 0x38) >> 8) * 0x2c))
              ((int)(sword)*(word *)(param_1 + 0x38),0x20006b08,0,0);
  }
  _ttyflush(param_1,3);
  if ((*(byte *)(*_active_u + 0x16) & 0x40) != 0) {
    *(undefined4 *)(iVar2 + 8) = 0;
    *(undefined4 *)(iVar2 + 0xc) = 0;
  }
  puVar1 = *(undefined **)((int)_active_u + 0x15e);
  if (param_1 == puVar1) {
    *(byte *)(*_active_u + 0x28) = *(byte *)(*_active_u + 0x28) & 0xbf;
  }
  *(undefined2 *)(param_1 + 0x42) = 0;
  *(undefined4 *)(param_1 + 0x3e) = 0;
  param_1[0x45] = 0;
  *(undefined4 *)(param_1 + 0x82) = 0;
  cVar3 = '\0';
  cVar4 = '\0';
  cVar5 = (byte)((param_1 < puVar1) << 4 | 4U) == 0;
  cVar6 = '\0';
  bVar7 = 0;
  _selthreadclear(param_1 + 0x2c);
  _selthreadclear(param_1 + 0x28);
  return cVar3 << 4 | cVar4 << 3 | cVar5 << 2 | cVar6 << 1 | bVar7;
}

