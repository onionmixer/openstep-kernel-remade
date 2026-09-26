
void _in_pcbnotify(undefined4 *param_1,sword *param_2,sword param_3,int param_4,sword param_5,
                  uint param_6,code *param_7)

{
  undefined4 *puVar1;
  int iVar2;
  byte bVar3;
  undefined4 *puVar4;
  
  if (((param_6 < 0x16) && (*param_2 == 2)) && (iVar2 = *(int *)(param_2 + 2), iVar2 != 0)) {
    if (((param_6 - 0xe < 4) || (param_6 == 6)) || (param_6 == 1)) {
      param_3 = 0;
      param_5 = 0;
      param_4 = 0;
      if (param_6 != 6) {
        param_7 = _in_rtchange;
      }
    }
    bVar3 = _inetctlerrmap[param_6];
    puVar1 = (undefined4 *)*param_1;
    while (puVar4 = puVar1, param_1 != puVar4) {
      if ((((iVar2 == puVar4[3]) && (puVar4[6] != 0)) &&
          (((param_5 == 0 || (param_5 == *(sword *)((int)puVar4 + 0x16))) &&
           ((param_4 == 0 || (param_4 == *(int *)((int)puVar4 + 0x12))))))) &&
         ((param_3 == 0 || (param_3 == *(sword *)(puVar4 + 4))))) {
        if (bVar3 != 0) {
          *(word *)(puVar4[6] + 0x50) = (word)bVar3;
        }
        puVar1 = (undefined4 *)*puVar4;
        if (param_7 != (code *)0x0) {
          (*param_7)(puVar4);
        }
      }
      else {
        puVar1 = (undefined4 *)*puVar4;
      }
    }
  }
  return;
}

