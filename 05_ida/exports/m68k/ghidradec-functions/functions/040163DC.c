
void _unp_disconnect(int *param_1)

{
  undefined4 *puVar1;
  sword sVar2;
  int *piVar3;
  int *piVar4;
  
  puVar1 = (undefined4 *)param_1[3];
  if (puVar1 != (undefined4 *)0x0) {
    param_1[3] = 0;
    sVar2 = *(sword *)*param_1;
    if (sVar2 == 1) {
      _soisdisconnected((sword *)*param_1);
      puVar1[3] = 0;
      _soisdisconnected(*puVar1);
    }
    else if (sVar2 == 2) {
      piVar3 = (int *)puVar1[4];
      if (param_1 == (int *)puVar1[4]) {
        puVar1[4] = param_1[5];
      }
      else {
        do {
          piVar4 = piVar3;
          if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            _panic(aUnpDisconnect);
          }
          piVar3 = (int *)piVar4[5];
        } while (param_1 != (int *)piVar4[5]);
        piVar4[5] = param_1[5];
      }
      param_1[5] = 0;
      *(word *)(*param_1 + 6) = *(word *)(*param_1 + 6) & 0xfffd;
    }
  }
  return;
}
