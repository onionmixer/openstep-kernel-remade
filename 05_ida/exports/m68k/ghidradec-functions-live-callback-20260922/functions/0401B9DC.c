
int _physio(undefined4 param_1,uint *param_2,undefined2 param_3,uint param_4,code *param_5,
           int *param_6,uint param_7)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = 0;
  do {
    if (param_6[1] == 0) {
      return 0;
    }
    puVar1 = (uint *)*param_6;
    if ((param_6[3] != 1) && (iVar3 = _useracc(*puVar1,puVar1[1],-(int)-(param_4 != 1)), iVar3 == 0)
       ) {
      return 0xe;
    }
    while ((*param_2 & 8) != 0) {
      *param_2 = *param_2 | 0x40;
      _sleep(param_2,0x15);
    }
    *(undefined2 *)(param_2 + 7) = 0;
    param_2[0xb] = *_active_u;
    param_2[8] = *puVar1;
    uVar2 = puVar1[1];
    while (0 < (int)uVar2) {
      *param_2 = param_4 | 0x18;
      *(undefined2 *)((int)param_2 + 0x1e) = param_3;
      param_2[9] = (uint)param_6[2] / param_7;
      param_2[5] = puVar1[1];
      (*param_5)(param_2);
      uVar2 = param_2[5];
      if (param_6[3] == 1) {
        *(byte *)param_2 = *(byte *)param_2 | 4;
      }
      else {
        *(word *)(*_active_u + 0x2a) = *(word *)(*_active_u + 0x2a) | 0x800;
        uVar4 = param_2[8];
        _vslock(uVar4,uVar2);
      }
      _physstrat(param_2,param_1,0x14);
      if (param_6[3] != 1) {
        _vsunlock(uVar4,uVar2,param_4);
        *(word *)(*_active_u + 0x2a) = *(word *)(*_active_u + 0x2a) & 0xf7ff;
      }
      if ((*param_2 & 0x40) != 0) {
        _wakeup(param_2);
      }
      iVar3 = uVar2 - param_2[10];
      param_2[8] = iVar3 + param_2[8];
      puVar1[1] = puVar1[1] - iVar3;
      *(int *)((int)param_6 + 0x12) = *(int *)((int)param_6 + 0x12) - iVar3;
      param_6[2] = iVar3 + param_6[2];
      if ((param_2[10] != 0) || ((*param_2 & 4) != 0)) break;
      uVar2 = puVar1[1];
    }
    *param_2 = *param_2 & 0xffffffa7;
    iVar3 = _geterror(param_2);
    if (param_2[10] != 0) {
      return iVar3;
    }
    if (iVar3 != 0) {
      return iVar3;
    }
    *param_6 = *param_6 + 8;
    param_6[1] = param_6[1] + -1;
  } while( true );
}

