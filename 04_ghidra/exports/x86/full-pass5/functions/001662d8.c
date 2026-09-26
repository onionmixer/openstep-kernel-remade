/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001662d8 */

kern_return_t
_task_threads(task_t target_task,thread_act_array_t *act_list,mach_msg_type_number_t *act_listCnt)

{
  int iVar1;
  uint uVar2;
  kern_return_t kVar3;
  thread_act_t tVar4;
  uint uVar5;
  uint uVar6;
  uint local_1c;
  thread_act_array_t local_14;
  thread_act_array_t local_c;
  
  if (target_task == 0) {
    kVar3 = 4;
  }
  else {
    local_1c = 0;
    local_14 = (thread_act_array_t)0x0;
    do {
      do {
        do {
        } while (*(int *)target_task != 0);
        LOCK();
        iVar1 = *(int *)target_task;
        *(undefined4 *)target_task = 1;
        UNLOCK();
      } while (iVar1 == 1);
      if (*(int *)(target_task + 8) == 0) {
        LOCK();
        *(undefined4 *)target_task = 0;
        UNLOCK();
        return 5;
      }
      uVar2 = *(uint *)(target_task + 0x24);
      uVar6 = uVar2 * 4;
      if (uVar6 < local_1c || uVar6 - local_1c == 0) {
        local_c = local_14;
        uVar5 = 0;
        tVar4 = *(thread_act_t *)(target_task + 0x1c);
        if (uVar2 != 0) {
          do {
            _thread_reference(tVar4);
            local_14[uVar5] = tVar4;
            uVar5 = uVar5 + 1;
            tVar4 = *(thread_act_t *)(tVar4 + 0x10);
          } while (uVar5 < uVar2);
        }
        LOCK();
        *(undefined4 *)target_task = 0;
        UNLOCK();
        if (uVar2 == 0) {
          *act_list = (thread_act_array_t)0x0;
          *act_listCnt = 0;
          if (local_1c != 0) {
            _kfree(local_14,local_1c);
          }
        }
        else {
          if (uVar6 < local_1c) {
            local_c = (thread_act_array_t)_kalloc(uVar6);
            if (local_c == (thread_act_array_t)0x0) {
              uVar6 = 0;
              if (uVar2 != 0) {
                do {
                  _thread_deallocate(local_14[uVar6]);
                  uVar6 = uVar6 + 1;
                } while (uVar6 < uVar2);
              }
              _kfree(local_14,local_1c);
              return 6;
            }
            _bcopy(local_14,local_c,uVar6);
            _kfree(local_14,local_1c);
          }
          *act_list = local_c;
          *act_listCnt = uVar2;
          uVar6 = 0;
          if (uVar2 != 0) {
            do {
              tVar4 = _convert_thread_to_port(*local_c);
              *local_c = tVar4;
              local_c = local_c + 1;
              uVar6 = uVar6 + 1;
            } while (uVar6 < uVar2);
          }
        }
        return 0;
      }
      LOCK();
      *(undefined4 *)target_task = 0;
      UNLOCK();
      if (local_1c != 0) {
        _kfree(local_14,local_1c);
      }
      local_14 = (thread_act_array_t)_kalloc(uVar6);
      local_1c = uVar6;
    } while (local_14 != (thread_act_array_t)0x0);
    kVar3 = 6;
  }
  return kVar3;
}

