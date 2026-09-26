
void _tcp_dooptions(undefined4 param_1,int param_2,int param_3)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  int iVar4;
  undefined2 uStack_6;
  
  iVar4 = (int)*(sword *)(param_2 + 8);
  for (pcVar3 = (char *)(*(int *)(param_2 + 4) + param_2);
      (0 < iVar4 && (cVar1 = *pcVar3, cVar1 != '\0')); pcVar3 = pcVar3 + uVar2) {
    if (cVar1 == '\x01') {
      uVar2 = 1;
    }
    else {
      uVar2 = (uint)(byte)pcVar3[1];
      if (pcVar3[1] == 0) break;
    }
    if (((cVar1 == '\x02') && (uVar2 == 4)) && ((*(byte *)(param_3 + 0x21) & 2) != 0)) {
      _bcopy(pcVar3 + 2,&uStack_6,2);
      _tcp_mss(param_1,uStack_6);
    }
    iVar4 = iVar4 - uVar2;
  }
  _m_free(param_2);
  return;
}

