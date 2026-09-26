
void _pmonlogexec(undefined4 param_1,undefined4 param_2,undefined4 param_3,char *param_4)

{
  char cVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  int iVar4;
  char *pcVar5;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uVar3 = uRam040c32c2;
  uVar2 = uRam040c2c0e;
  pcVar5 = param_4 + 1;
  cVar1 = *pcVar5;
  while (cVar1 != '\0') {
    pcVar5 = pcVar5 + 1;
    cVar1 = *pcVar5;
  }
  iVar4 = 0;
  do {
    pcVar5 = pcVar5 + -1;
    if (pcVar5 <= param_4) break;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 0xc);
  _strncpy(&uStack_10,pcVar5,0xc);
  _pmonlogevent(param_1,param_2,param_3,CONCAT22(uVar3,uVar2),0);
  _pmonlogevent(param_1,0x8000000,uStack_10,uStack_c,uStack_8);
  return;
}

