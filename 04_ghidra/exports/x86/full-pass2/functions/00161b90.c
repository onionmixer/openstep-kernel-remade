/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00161b90 */

undefined4 _processor_set_things(int param_1,undefined4 *param_2,uint *param_3,int param_4)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  undefined4 *local_10;
  uint local_8;
  
  if (param_1 == 0) {
    uVar1 = 4;
  }
  else {
    local_8 = 0;
    local_10 = (undefined4 *)0x0;
    piVar3 = (int *)(param_1 + 0x158);
    do {
      do {
        do {
        } while (*piVar3 != 0);
        LOCK();
        iVar6 = *piVar3;
        *piVar3 = 1;
        UNLOCK();
      } while (iVar6 == 1);
      if (*(int *)(param_1 + 0x154) == 0) {
        LOCK();
        *(undefined4 *)(param_1 + 0x158) = 0;
        UNLOCK();
        return 5;
      }
      if (param_4 == 0) {
        uVar7 = *(uint *)(param_1 + 0x134);
      }
      else {
        uVar7 = *(uint *)(param_1 + 0x140);
      }
      uVar5 = uVar7 * 4;
      if (uVar5 < local_8 || uVar5 - local_8 == 0) {
        if (param_4 == 0) {
          uVar4 = 0;
          iVar6 = *(int *)(param_1 + 300);
          if (uVar7 != 0) {
            do {
              _task_reference(iVar6);
              local_10[uVar4] = iVar6;
              uVar4 = uVar4 + 1;
              iVar6 = *(int *)(iVar6 + 0x10);
            } while (uVar4 < uVar7);
          }
        }
        else if (param_4 == 1) {
          uVar4 = 0;
          iVar6 = *(int *)(param_1 + 0x138);
          if (uVar7 != 0) {
            do {
              _thread_reference(iVar6);
              local_10[uVar4] = iVar6;
              uVar4 = uVar4 + 1;
              iVar6 = *(int *)(iVar6 + 0x18);
            } while (uVar4 < uVar7);
          }
        }
        LOCK();
        *(undefined4 *)(param_1 + 0x158) = 0;
        UNLOCK();
        if (uVar7 == 0) {
          *param_2 = 0;
          *param_3 = 0;
          if (local_8 != 0) {
            _kfree(local_10,local_8);
          }
        }
        else {
          if (uVar5 < local_8) {
            puVar2 = (undefined4 *)_kalloc(uVar5);
            if (puVar2 == (undefined4 *)0x0) {
              if (param_4 == 0) {
                uVar5 = 0;
                if (uVar7 != 0) {
                  do {
                    _task_deallocate(local_10[uVar5]);
                    uVar5 = uVar5 + 1;
                  } while (uVar5 < uVar7);
                }
              }
              else if ((param_4 == 1) && (uVar5 = 0, uVar7 != 0)) {
                do {
                  _thread_deallocate(local_10[uVar5]);
                  uVar5 = uVar5 + 1;
                } while (uVar5 < uVar7);
              }
              _kfree(local_10,local_8);
              return 6;
            }
            _bcopy(local_10,puVar2,uVar5);
            _kfree(local_10,local_8);
            local_10 = puVar2;
          }
          *param_2 = local_10;
          *param_3 = uVar7;
          if (param_4 == 0) {
            uVar5 = 0;
            if (uVar7 != 0) {
              do {
                uVar1 = _convert_task_to_port(*local_10);
                *local_10 = uVar1;
                local_10 = local_10 + 1;
                uVar5 = uVar5 + 1;
              } while (uVar5 < uVar7);
            }
          }
          else if ((param_4 == 1) && (uVar5 = 0, uVar7 != 0)) {
            do {
              uVar1 = _convert_thread_to_port(*local_10);
              *local_10 = uVar1;
              local_10 = local_10 + 1;
              uVar5 = uVar5 + 1;
            } while (uVar5 < uVar7);
          }
        }
        return 0;
      }
      LOCK();
      *(undefined4 *)(param_1 + 0x158) = 0;
      UNLOCK();
      if (local_8 != 0) {
        _kfree(local_10,local_8);
      }
      local_10 = (undefined4 *)_kalloc(uVar5);
      local_8 = uVar5;
    } while (local_10 != (undefined4 *)0x0);
    uVar1 = 6;
  }
  return uVar1;
}

