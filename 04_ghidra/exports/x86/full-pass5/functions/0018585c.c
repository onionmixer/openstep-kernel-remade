/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018585c */

void FUN_0018585c(int param_1)

{
  undefined **ppuVar1;
  undefined **ppuVar2;
  undefined **ppuVar3;
  undefined **ppuVar4;
  undefined **ppuVar5;
  
  if (DAT_001e13ec == *(int *)(param_1 + 0x1c)) {
    DAT_001e13ec = 0;
  }
  else {
    ppuVar4 = (undefined **)PTR_LOOP_001e1404;
    if (_panel_req_port == *(int *)(param_1 + 0x1c)) {
      while (ppuVar4 != &PTR_LOOP_001e1404) {
        ppuVar1 = (undefined **)*ppuVar4;
        if ((code *)ppuVar4[3] != (code *)0x0) {
          (*(code *)ppuVar4[3])(ppuVar4[4],ppuVar4[2],0);
        }
        ppuVar2 = (undefined **)*ppuVar4;
        ppuVar3 = (undefined **)ppuVar4[1];
        ppuVar5 = ppuVar3;
        if (ppuVar2 != &PTR_LOOP_001e1404) {
          ppuVar2[1] = (undefined *)ppuVar3;
          ppuVar5 = DAT_001e1408;
        }
        DAT_001e1408 = ppuVar5;
        if (ppuVar3 != &PTR_LOOP_001e1404) {
          *ppuVar3 = (undefined *)ppuVar2;
          ppuVar2 = (undefined **)PTR_LOOP_001e1404;
        }
        PTR_LOOP_001e1404 = (undefined *)ppuVar2;
        _kfree(ppuVar4,0x14);
        ppuVar4 = ppuVar1;
      }
      _panel_req_port = 0;
    }
  }
  return;
}

