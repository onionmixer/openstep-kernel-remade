/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001681c0 */

kern_return_t
_thread_info(thread_act_t target_act,thread_flavor_t flavor,thread_info_t thread_info_out,
            mach_msg_type_number_t *thread_info_outCnt)

{
  int *piVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  integer_t local_8;
  
  if (target_act != 0) {
    if (flavor == 1) {
      if (10 < *thread_info_outCnt) {
        uVar3 = _splsched();
        piVar1 = (int *)(target_act + 0x20);
        do {
          do {
          } while (*piVar1 != 0);
          LOCK();
          iVar4 = *piVar1;
          *piVar1 = 1;
          UNLOCK();
        } while (iVar4 == 1);
        if (((*(byte *)(target_act + 0x4c) & 4) == 0) &&
           (*(int *)(target_act + 0x70) != _sched_tick)) {
          _update_priority(target_act);
        }
        _thread_read_times(target_act,thread_info_out,thread_info_out + 2);
        thread_info_out[5] = *(integer_t *)(target_act + 0x50);
        thread_info_out[6] = *(integer_t *)(target_act + 0x58);
        thread_info_out[4] = ((*(uint *)(target_act + 0x68) / 1000) * 3) / 5;
        if ((*(uint *)(target_act + 0x4c) & 0x100) == 0) {
          local_8 = 0;
          if ((char)*(uint *)(target_act + 0x4c) < '\0') {
            local_8 = 2;
          }
        }
        else {
          local_8 = 1;
        }
        uVar2 = *(uint *)(target_act + 0x4c);
        if ((uVar2 & 0x10) == 0) {
          if ((uVar2 & 4) == 0) {
            if ((uVar2 & 8) == 0) {
              if ((uVar2 & 2) == 0) {
                iVar4 = 0;
                if ((uVar2 & 1) != 0) {
                  iVar4 = 3;
                }
              }
              else {
                iVar4 = 2;
              }
            }
            else {
              iVar4 = 4;
            }
          }
          else {
            iVar4 = 1;
          }
        }
        else {
          iVar4 = 5;
        }
        thread_info_out[7] = iVar4;
        thread_info_out[8] = local_8;
        thread_info_out[9] = *(integer_t *)(target_act + 0x8c);
        if (iVar4 == 1) {
          thread_info_out[10] = 0;
        }
        else {
          thread_info_out[10] = _sched_tick - *(int *)(target_act + 0x70);
        }
        LOCK();
        *(undefined4 *)(target_act + 0x20) = 0;
        UNLOCK();
        _splx(uVar3);
        *thread_info_outCnt = 0xb;
        return 0;
      }
    }
    else {
      if (flavor != 2) {
        return 4;
      }
      if (6 < *thread_info_outCnt) {
        uVar3 = _splsched();
        piVar1 = (int *)(target_act + 0x20);
        do {
          do {
          } while (*piVar1 != 0);
          LOCK();
          iVar4 = *piVar1;
          *piVar1 = 1;
          UNLOCK();
        } while (iVar4 == 1);
        *thread_info_out = *(integer_t *)(target_act + 0x60);
        if ((*(int *)(target_act + 0x60) == 2) || (*(int *)(target_act + 0x60) == 4)) {
          thread_info_out[1] = (*(int *)(target_act + 0x5c) * _tick) / 1000;
        }
        else {
          thread_info_out[1] = 0;
        }
        thread_info_out[2] = *(integer_t *)(target_act + 0x50);
        thread_info_out[3] = *(integer_t *)(target_act + 0x54);
        thread_info_out[4] = *(integer_t *)(target_act + 0x58);
        thread_info_out[5] = ~*(uint *)(target_act + 100) >> 0x1f;
        thread_info_out[6] = *(integer_t *)(target_act + 100);
        LOCK();
        *(undefined4 *)(target_act + 0x20) = 0;
        UNLOCK();
        _splx(uVar3);
        *thread_info_outCnt = 7;
        return 0;
      }
    }
  }
  return 4;
}

