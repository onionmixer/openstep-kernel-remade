
int sub_4038B8C(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iStack_c;
  int iStack_8;
  
  uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x10) + 4);
  iStack_8 = *(int *)(param_1 + 0x10) + 4;
  while( true ) {
    iVar2 = sub_4038BEC(uVar1,param_1,2,&iStack_8,&iStack_c);
    if (iVar2 == 0) {
      return 0;
    }
    if (*(sword *)(param_1 + 2) == 2) break;
    if (*(sword *)(iStack_c + 2) == 2) {
      return iStack_c;
    }
    uVar1 = *(undefined4 *)(iStack_c + 0x14);
  }
  return iStack_c;
}
