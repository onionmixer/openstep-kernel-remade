
int _socreate(undefined4 param_1,undefined4 *param_2,int param_3,int param_4)

{
  sword *psVar1;
  int iVar2;
  undefined2 *puVar3;
  
  if (param_4 == 0) {
    psVar1 = (sword *)_pffindtype(param_1,param_3);
  }
  else {
    psVar1 = (sword *)_pffindproto(param_1,param_4,param_3);
  }
  if (psVar1 == (sword *)0x0) {
    iVar2 = 0x2b;
  }
  else if (param_3 == *psVar1) {
    iVar2 = _m_getclr(1,3);
    puVar3 = (undefined2 *)(*(int *)(iVar2 + 4) + iVar2);
    puVar3[1] = 0x20;
    puVar3[3] = 0;
    *puVar3 = (sword)param_3;
    if (*(sword *)(*(int *)(_active_u + 0x1a) + 2) == 0) {
      puVar3[3] = 0x80;
    }
    *(sword **)(puVar3 + 6) = psVar1;
    iVar2 = (**(code **)(psVar1 + 0xd))(puVar3,0,0,param_4,0);
    if (iVar2 == 0) {
      *param_2 = puVar3;
      iVar2 = 0;
    }
    else {
      puVar3[3] = puVar3[3] | 1;
      _sofree(puVar3);
    }
  }
  else {
    iVar2 = 0x29;
  }
  return iVar2;
}

