
void FUN_040640ea(int param_1)

{
  undefined **ppuVar1;
  undefined **ppuVar2;
  int *piVar3;
  undefined **ppuVar4;
  int *piVar5;
  
  if (*(int *)(param_1 + 0x1c) == DAT_040b06ec) {
    DAT_040b06ec = 0;
  }
  else {
    ppuVar4 = (undefined **)PTR_LOOP_040b0704;
    if (*(int *)(param_1 + 0x1c) == _panel_req_port) {
      while (ppuVar4 != &PTR_LOOP_040b0704) {
        ppuVar1 = (undefined **)*ppuVar4;
        if ((code *)ppuVar4[3] != (code *)0x0) {
          (*(code *)ppuVar4[3])(ppuVar4[4],ppuVar4[2],0);
        }
        ppuVar2 = (undefined **)*ppuVar4;
        piVar3 = (int *)ppuVar4[1];
        piVar5 = piVar3;
        if (ppuVar2 != &PTR_LOOP_040b0704) {
          ppuVar2[1] = (undefined *)piVar3;
          piVar5 = DAT_040b0708;
        }
        DAT_040b0708 = piVar5;
        *piVar3 = (int)ppuVar2;
        _kfree(ppuVar4,0x14);
        ppuVar4 = ppuVar1;
      }
      _panel_req_port = 0;
    }
  }
  return;
}

