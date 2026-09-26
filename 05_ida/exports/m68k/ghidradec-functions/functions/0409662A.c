
bool _inet_aton(char *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  bool bVar2;
  int iStack_c;
  undefined4 uStack_8;
  
  puVar1 = &uStack_8;
  iStack_c = 0;
  do {
    if (*param_1 == '\0') {
      bVar2 = (undefined4 *)((int)&uStack_8 + 3) == puVar1;
      if (bVar2) {
        *(char *)puVar1 = (char)iStack_c;
        *param_2 = uStack_8;
      }
      return bVar2;
    }
    if (*param_1 == '.') {
      if ((undefined4 *)((int)&uStack_8 + 3U) <= puVar1) {
        return false;
      }
      *(char *)puVar1 = (char)iStack_c;
      puVar1 = (undefined4 *)((int)puVar1 + 1);
      iStack_c = 0;
    }
    else {
      if ((*param_1 < '0') || ('9' < *param_1)) {
        return false;
      }
      iStack_c = iStack_c * 10 + -0x30 + (int)*param_1;
      if ((0xff < iStack_c) || (iStack_c < 0)) {
        return false;
      }
    }
    param_1 = param_1 + 1;
  } while( true );
}
