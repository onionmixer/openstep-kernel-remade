
/* WARNING: Removing unreachable block (ram,0xf00940d4) */
/* WARNING: Removing unreachable block (ram,0xf0094174) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_f00940d4(undefined **param_1,undefined4 param_2)

{
  undefined **ppuVar1;
  undefined **ppuVar2;
  undefined **ppuVar3;
  code *pcVar4;
  undefined **ppuVar5;
  undefined **ppuVar6;
  
  if (param_1[7] == DAT_f0112510) {
    DAT_f0112510 = (undefined *)0x0;
  }
  else if (param_1[7] == _panel_req_port) {
    if ((undefined **)PTR_LOOP_f0112528 != &PTR_LOOP_f0112528) {
      pcVar4 = *(code **)(PTR_LOOP_f0112528 + 0xc);
      ppuVar6 = (undefined **)PTR_LOOP_f0112528;
      while( true ) {
        ppuVar5 = (undefined **)*ppuVar6;
        if (pcVar4 != (code *)0x0) {
          (*pcVar4)(ppuVar6[4],ppuVar6[2],0);
        }
        ppuVar3 = (undefined **)*ppuVar6;
        ppuVar2 = (undefined **)ppuVar6[1];
        ppuVar1 = ppuVar2;
        if (ppuVar3 != &PTR_LOOP_f0112528) {
          ppuVar3[1] = (undefined *)ppuVar2;
          ppuVar1 = _DAT_f011252c;
        }
        _DAT_f011252c = ppuVar1;
        if (ppuVar2 != &PTR_LOOP_f0112528) {
          *ppuVar2 = (undefined *)ppuVar3;
          ppuVar3 = (undefined **)PTR_LOOP_f0112528;
        }
        PTR_LOOP_f0112528 = (undefined *)ppuVar3;
        _kfree(ppuVar6,0x14);
        if (ppuVar5 == &PTR_LOOP_f0112528) break;
        pcVar4 = (code *)ppuVar5[3];
        ppuVar6 = ppuVar5;
      }
    }
    param_1 = &PTR_LOOP_f0112528;
    _panel_req_port = (undefined *)0x0;
  }
  return CONCAT44(param_2,param_1);
}

