
undefined4 _processor_set_things(int param_1,undefined4 *param_2,uint *param_3,int param_4)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int *piVar8;
  
  if (param_1 == 0) {
    uVar1 = 4;
  }
  else {
    piVar8 = (int *)0x0;
    uVar6 = 0;
    do {
      if (*(int *)(param_1 + 0x148) == 0) {
        return 5;
      }
      if (param_4 == 0) {
        uVar7 = *(uint *)(param_1 + 300);
      }
      else {
        uVar7 = *(uint *)(param_1 + 0x138);
      }
      uVar5 = uVar7 << 2;
      if (uVar5 <= uVar6) {
        if (param_4 == 0) {
          uVar4 = 0;
          iVar3 = *(int *)(param_1 + 0x124);
          piVar2 = piVar8;
          if (uVar7 != 0) {
            do {
              _task_reference(iVar3);
              *piVar2 = iVar3;
              uVar4 = uVar4 + 1;
              iVar3 = *(int *)(iVar3 + 0xc);
              piVar2 = piVar2 + 1;
            } while (uVar4 < uVar7);
          }
        }
        else if (param_4 == 1) {
          uVar4 = 0;
          iVar3 = *(int *)(param_1 + 0x130);
          piVar2 = piVar8;
          if (uVar7 != 0) {
            do {
              _thread_reference(iVar3);
              *piVar2 = iVar3;
              uVar4 = uVar4 + 1;
              iVar3 = *(int *)(iVar3 + 0x18);
              piVar2 = piVar2 + 1;
            } while (uVar4 < uVar7);
          }
        }
        if (uVar7 == 0) {
          *param_2 = 0;
          *param_3 = 0;
          if (uVar6 != 0) {
            _kfree(piVar8,uVar6);
          }
        }
        else {
          piVar2 = piVar8;
          if (uVar5 < uVar6) {
            piVar2 = (int *)_kalloc(uVar5);
            if (piVar2 == (int *)0x0) {
              if (param_4 == 0) {
                uVar5 = 0;
                piVar2 = piVar8;
                if (uVar7 != 0) {
                  do {
                    _task_deallocate(*piVar2);
                    uVar5 = uVar5 + 1;
                    piVar2 = piVar2 + 1;
                  } while (uVar5 < uVar7);
                }
              }
              else if ((param_4 == 1) && (uVar5 = 0, piVar2 = piVar8, uVar7 != 0)) {
                do {
                  _thread_deallocate(*piVar2);
                  uVar5 = uVar5 + 1;
                  piVar2 = piVar2 + 1;
                } while (uVar5 < uVar7);
              }
              _kfree(piVar8,uVar6);
              return 6;
            }
            _bcopy(piVar8,piVar2,uVar5);
            _kfree(piVar8,uVar6);
          }
          *param_2 = piVar2;
          *param_3 = uVar7;
          if (param_4 == 0) {
            uVar6 = 0;
            if (uVar7 != 0) {
              do {
                iVar3 = _convert_task_to_port(*piVar2);
                *piVar2 = iVar3;
                uVar6 = uVar6 + 1;
                piVar2 = piVar2 + 1;
              } while (uVar6 < uVar7);
            }
          }
          else if ((param_4 == 1) && (uVar6 = 0, uVar7 != 0)) {
            do {
              iVar3 = _convert_thread_to_port(*piVar2);
              *piVar2 = iVar3;
              uVar6 = uVar6 + 1;
              piVar2 = piVar2 + 1;
            } while (uVar6 < uVar7);
          }
        }
        return 0;
      }
      if (uVar6 != 0) {
        _kfree(piVar8,uVar6);
      }
      piVar8 = (int *)_kalloc(uVar5);
      uVar6 = uVar5;
    } while (piVar8 != (int *)0x0);
    uVar1 = 6;
  }
  return uVar1;
}
