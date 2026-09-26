
undefined4 _task_threads(int param_1,undefined4 *param_2,uint *param_3)

{
  uint uVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int *piVar8;
  
  if (param_1 == 0) {
    uVar2 = 4;
  }
  else {
    piVar8 = (int *)0x0;
    uVar7 = 0;
    do {
      if (*(int *)(param_1 + 4) == 0) {
        return 5;
      }
      uVar1 = *(uint *)(param_1 + 0x20);
      uVar6 = uVar1 << 2;
      if (uVar6 <= uVar7) {
        uVar5 = 0;
        iVar4 = *(int *)(param_1 + 0x18);
        piVar3 = piVar8;
        if (uVar1 != 0) {
          do {
            _thread_reference(iVar4);
            *piVar3 = iVar4;
            uVar5 = uVar5 + 1;
            iVar4 = *(int *)(iVar4 + 0x10);
            piVar3 = piVar3 + 1;
          } while (uVar5 < uVar1);
        }
        if (uVar1 == 0) {
          *param_2 = 0;
          *param_3 = 0;
          if (uVar7 != 0) {
            _kfree(piVar8,uVar7);
          }
        }
        else {
          piVar3 = piVar8;
          if (uVar6 < uVar7) {
            piVar3 = (int *)_kalloc(uVar6);
            if (piVar3 == (int *)0x0) {
              uVar6 = 0;
              piVar3 = piVar8;
              if (uVar1 != 0) {
                do {
                  _thread_deallocate(*piVar3);
                  uVar6 = uVar6 + 1;
                  piVar3 = piVar3 + 1;
                } while (uVar6 < uVar1);
              }
              _kfree(piVar8,uVar7);
              return 6;
            }
            _bcopy(piVar8,piVar3,uVar6);
            _kfree(piVar8,uVar7);
          }
          *param_2 = piVar3;
          *param_3 = uVar1;
          uVar7 = 0;
          if (uVar1 != 0) {
            do {
              iVar4 = _convert_thread_to_port(*piVar3);
              *piVar3 = iVar4;
              uVar7 = uVar7 + 1;
              piVar3 = piVar3 + 1;
            } while (uVar7 < uVar1);
          }
        }
        return 0;
      }
      if (uVar7 != 0) {
        _kfree(piVar8,uVar7);
      }
      piVar8 = (int *)_kalloc(uVar6);
      uVar7 = uVar6;
    } while (piVar8 != (int *)0x0);
    uVar2 = 6;
  }
  return uVar2;
}
