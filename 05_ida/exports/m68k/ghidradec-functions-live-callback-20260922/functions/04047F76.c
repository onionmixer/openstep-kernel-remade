
undefined4 _host_processors(int param_1,undefined4 *param_2,uint *param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  
  if (param_1 == 0) {
    uVar1 = 4;
  }
  else {
    uVar5 = 0;
    iVar3 = 0;
    piVar6 = &_machine_slot;
    do {
      if (*piVar6 != 0) {
        uVar5 = uVar5 + 1;
      }
      piVar6 = piVar6 + 8;
      iVar3 = iVar3 + 1;
    } while (iVar3 < 1);
    if (uVar5 == 0) {
                    /* WARNING: Subroutine does not return */
      _panic(aHostProcessors);
    }
    puVar2 = (undefined4 *)_kalloc(uVar5 << 2);
    if (puVar2 == (undefined4 *)0x0) {
      uVar1 = 6;
    }
    else {
      iVar3 = 0;
      puVar9 = &_processor_ptr;
      piVar6 = &_machine_slot;
      puVar7 = puVar2;
      do {
        puVar8 = puVar7;
        if (*piVar6 != 0) {
          puVar8 = puVar7 + 1;
          *puVar7 = *puVar9;
        }
        puVar9 = puVar9 + 1;
        piVar6 = piVar6 + 8;
        iVar3 = iVar3 + 1;
        puVar7 = puVar8;
      } while (iVar3 < 1);
      *param_3 = uVar5;
      *param_2 = puVar2;
      uVar4 = 0;
      if (uVar5 != 0) {
        do {
          uVar1 = _convert_processor_to_port(*puVar2);
          *puVar2 = uVar1;
          uVar4 = uVar4 + 1;
          puVar2 = puVar2 + 1;
        } while (uVar4 < uVar5);
      }
      uVar1 = 0;
    }
  }
  return uVar1;
}

