
undefined4 _dnlc_lookupSymLink(char *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _strlen(param_1);
  if (iVar1 < 0x21) {
    uVar2 = sub_4018BAE(param_2,param_1,iVar1,
                        param_2 + iVar1 + (int)param_1[iVar1 + -1] + (int)*param_1 & 0x3f,0xffffffff
                       );
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

