
undefined4
_processor_set_stack_usage
          (int param_1,int *param_2,uint *param_3,uint *param_4,uint *param_5,int *param_6)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int *piVar8;
  uint uVar9;
  int iVar10;
  int *piVar11;
  int *piVar12;
  int *piVar13;
  int iVar14;
  
  if (param_1 == 0) {
loc_4053C0E:
    uVar3 = 4;
  }
  else {
    piVar8 = (int *)0x0;
    uVar7 = 0;
    do {
      if (*(int *)(param_1 + 0x148) == 0) goto loc_4053C0E;
      uVar2 = *(uint *)(param_1 + 0x138);
      uVar6 = uVar2 << 2;
      if (uVar6 <= uVar7) {
        uVar6 = 0;
        iVar10 = *(int *)(param_1 + 0x130);
        piVar13 = piVar8;
        if (uVar2 != 0) {
          do {
            _thread_reference(iVar10);
            *piVar13 = iVar10;
            uVar6 = uVar6 + 1;
            iVar10 = *(int *)(iVar10 + 0x18);
            piVar13 = piVar13 + 1;
          } while (uVar6 < uVar2);
        }
        iVar14 = 0;
        uVar9 = 0;
        iVar10 = 0;
        uVar6 = 0;
        piVar13 = piVar8;
        if (uVar2 != 0) {
          do {
            iVar1 = *piVar13;
            iVar4 = 0;
            if ((*(byte *)(iVar1 + 0x4a) & 1) == 0) {
              iVar4 = *(int *)(iVar1 + 0x28);
              piVar11 = &_active_stacks;
              piVar12 = &_active_threads;
              do {
                if (iVar1 == *piVar12) {
                  iVar4 = *piVar11;
                  break;
                }
                piVar11 = piVar11 + 1;
                piVar12 = piVar12 + 1;
              } while ((int)piVar11 < 0x40c22dd);
            }
            if (((iVar4 != 0) && (iVar14 = iVar14 + 1, _stack_check_usage != 0)) &&
               (uVar5 = _stack_usage(iVar4), uVar9 < uVar5)) {
              uVar9 = uVar5;
              iVar10 = iVar1;
            }
            _thread_deallocate(iVar1);
            piVar13 = piVar13 + 1;
            uVar6 = uVar6 + 1;
          } while (uVar6 < uVar2);
        }
        if (uVar7 != 0) {
          _kfree(piVar8,uVar7);
        }
        *param_2 = iVar14;
        uVar7 = ~_page_mask & _page_mask + iVar14 * 0xff4;
        *param_3 = uVar7;
        *param_4 = uVar7;
        *param_5 = uVar9;
        *param_6 = iVar10;
        return 0;
      }
      if (uVar7 != 0) {
        _kfree(piVar8,uVar7);
      }
      piVar8 = (int *)_kalloc(uVar6);
      uVar7 = uVar6;
    } while (piVar8 != (int *)0x0);
    uVar3 = 6;
  }
  return uVar3;
}
