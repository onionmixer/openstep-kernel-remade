
void sub_4090A50(undefined4 *param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 *in_A1;
  char *pcVar2;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  pcVar2 = (char *)&uStack_24;
  _strcpy(pcVar2,*param_1);
  cVar1 = uStack_24._0_1_;
  while (cVar1 != '\0') {
    pcVar2 = pcVar2 + 1;
    cVar1 = *pcVar2;
  }
  *pcVar2 = (char)*(undefined2 *)(param_1 + 2) + '0';
  pcVar2[1] = '\0';
  _bcopy(param_2,&uStack_14,0x10);
  *in_A1 = uStack_24;
  in_A1[1] = uStack_20;
  in_A1[2] = uStack_1c;
  in_A1[3] = uStack_18;
  in_A1[4] = uStack_14;
  in_A1[5] = uStack_10;
  in_A1[6] = uStack_c;
  in_A1[7] = uStack_8;
  return;
}
