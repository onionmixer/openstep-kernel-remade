
void _dnlc_remove(int param_1,char *param_2)

{
  char cVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = _strlen(param_2);
  if (iVar3 < 0x21) {
    cVar1 = *param_2;
    cVar2 = param_2[iVar3 + -1];
    while( true ) {
      iVar4 = sub_4018BAE(param_1,param_2,iVar3,param_1 + iVar3 + (int)cVar2 + (int)cVar1 & 0x3f,
                          0xffffffff);
      if (iVar4 == 0) break;
      sub_4018AFE(iVar4);
    }
  }
  return;
}

