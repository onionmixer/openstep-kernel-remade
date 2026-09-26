/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001666e4 */

kern_return_t
_task_info(task_name_t target_task,task_flavor_t flavor,task_info_t task_info_out,
          mach_msg_type_number_t *task_info_outCnt)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (target_task != 0) {
    if (flavor == 1) {
      if (7 < *task_info_outCnt) {
        iVar3 = _kernel_map;
        if (_kernel_task != target_task) {
          iVar3 = *(int *)(target_task + 0xc);
        }
        task_info_out[2] = *(integer_t *)(iVar3 + 0x28);
        task_info_out[3] = *(int *)(*(int *)(iVar3 + 0x24) + 0x10) * _page_size;
        do {
          do {
          } while (*(int *)target_task != 0);
          LOCK();
          iVar3 = *(int *)target_task;
          *(undefined4 *)target_task = 1;
          UNLOCK();
        } while (iVar3 == 1);
        task_info_out[1] = *(integer_t *)(target_task + 0x48);
        *task_info_out = *(integer_t *)(target_task + 0x44);
        task_info_out[4] = *(integer_t *)(target_task + 0x54);
        task_info_out[5] = *(integer_t *)(target_task + 0x58);
        task_info_out[6] = *(integer_t *)(target_task + 0x5c);
        task_info_out[7] = *(integer_t *)(target_task + 0x60);
        LOCK();
        *(undefined4 *)target_task = 0;
        UNLOCK();
        *task_info_outCnt = 8;
        return 0;
      }
    }
    else if ((flavor == 3) && (3 < *task_info_outCnt)) {
      *task_info_out = 0;
      task_info_out[1] = 0;
      task_info_out[2] = 0;
      task_info_out[3] = 0;
      do {
        do {
        } while (*(int *)target_task != 0);
        LOCK();
        iVar3 = *(int *)target_task;
        *(undefined4 *)target_task = 1;
        UNLOCK();
      } while (iVar3 == 1);
      for (iVar3 = *(int *)(target_task + 0x1c); target_task + 0x1c != iVar3;
          iVar3 = *(int *)(iVar3 + 0x10)) {
        uVar4 = _splsched();
        piVar1 = (int *)(iVar3 + 0x20);
        do {
          do {
          } while (*piVar1 != 0);
          LOCK();
          iVar2 = *piVar1;
          *piVar1 = 1;
          UNLOCK();
        } while (iVar2 == 1);
        _thread_read_times(iVar3,&local_c,&local_14);
        LOCK();
        *(undefined4 *)(iVar3 + 0x20) = 0;
        UNLOCK();
        _splx(uVar4);
        task_info_out[1] = task_info_out[1] + local_8;
        *task_info_out = *task_info_out + local_c;
        if (999999 < task_info_out[1]) {
          task_info_out[1] = task_info_out[1] + -1000000;
          *task_info_out = *task_info_out + 1;
        }
        task_info_out[3] = task_info_out[3] + local_10;
        task_info_out[2] = task_info_out[2] + local_14;
        if (999999 < task_info_out[3]) {
          task_info_out[3] = task_info_out[3] + -1000000;
          task_info_out[2] = task_info_out[2] + 1;
        }
      }
      LOCK();
      *(undefined4 *)target_task = 0;
      UNLOCK();
      *task_info_outCnt = 4;
      return 0;
    }
  }
  return 4;
}

