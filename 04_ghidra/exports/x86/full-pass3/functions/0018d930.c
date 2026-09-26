/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018d930 */

undefined4 _task_locate_ldt(int *param_1,uint param_2,uint param_3)

{
  uint *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  undefined *puVar5;
  undefined4 uVar6;
  int iVar7;
  
  puVar1 = (uint *)param_1[0x10];
  if ((param_2 < *(uint *)(param_1[3] + 0x14)) ||
     (*(uint *)(param_1[3] + 0x18) <= param_3 + param_2)) {
    uVar6 = 1;
  }
  else {
    iVar7 = _task_hold(param_1);
    if (iVar7 == 0) {
      _lock_write(puVar1 + 4);
      *puVar1 = param_2;
      puVar1[1] = param_3;
      _task_dowait(param_1,1);
      puVar2 = (undefined4 *)param_1[0x10];
      do {
        do {
        } while (*param_1 != 0);
        LOCK();
        iVar7 = *param_1;
        *param_1 = 1;
        UNLOCK();
      } while (iVar7 == 1);
      piVar3 = (int *)0x0;
      for (piVar4 = (int *)param_1[7]; param_1 + 7 != piVar4; piVar4 = (int *)piVar4[4]) {
        _thread_reference(piVar4);
        LOCK();
        *param_1 = 0;
        UNLOCK();
        if (piVar3 != (int *)0x0) {
          _thread_deallocate(piVar3);
        }
        uVar6 = puVar2[1];
        *(undefined4 *)(piVar4[10] + 0x74) = *puVar2;
        *(undefined4 *)(piVar4[10] + 0x78) = uVar6;
        puVar5 = _gdt;
        if (_active_threads == piVar4) {
          uVar6 = *(undefined4 *)(piVar4[10] + 0x74);
          iVar7 = *(int *)(piVar4[10] + 0x78) + -1;
          *(short *)(_gdt + 0x22) = (short)uVar6;
          puVar5[0x24] = (char)((uint)uVar6 >> 0x10);
          puVar5[0x27] = (char)((uint)uVar6 >> 0x18);
          puVar5[0x25] = puVar5[0x25] & 0xe0 | 0x82;
          puVar5[0x26] = puVar5[0x26] & 0x7f;
          *(short *)(puVar5 + 0x20) = (short)iVar7;
          puVar5[0x26] = puVar5[0x26] & 0xf0 | (byte)((uint)iVar7 >> 0x10) & 0xf;
          LocalDescriptorTableRegister(0x20);
        }
        do {
          do {
          } while (*param_1 != 0);
          LOCK();
          iVar7 = *param_1;
          *param_1 = 1;
          UNLOCK();
        } while (iVar7 == 1);
        piVar3 = piVar4;
      }
      LOCK();
      *param_1 = 0;
      UNLOCK();
      if (piVar3 != (int *)0x0) {
        _thread_deallocate(piVar3);
      }
      _task_release(param_1);
      _lock_done(puVar1 + 4);
      uVar6 = 0;
    }
    else {
      uVar6 = 4;
    }
  }
  return uVar6;
}

