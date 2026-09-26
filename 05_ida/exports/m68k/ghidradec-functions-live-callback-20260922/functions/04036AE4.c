
undefined4 sub_4036AE4(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iStack_20;
  int iStack_1c;
  word wStack_18;
  word wStack_16;
  char cStack_14;
  char cStack_13;
  
  uVar2 = 0;
  if (*(int *)(param_1 + 0x6e) != 0) {
    do {
      iVar1 = _rdwri(0,param_1,&iStack_1c,0xc,uVar2,1,&iStack_20);
      if ((((iVar1 != 0) || (iStack_20 != 0)) || (wStack_18 == 0)) ||
         ((iStack_1c != 0 &&
          (((2 < wStack_16 || (cStack_14 != '.')) ||
           ((wStack_16 != 1 && ((cStack_13 != '.' || (param_2 != iStack_1c)))))))))) {
        return 0;
      }
      uVar2 = wStack_18 + uVar2;
    } while (uVar2 < *(uint *)(param_1 + 0x6e));
  }
  return 1;
}

