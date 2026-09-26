
undefined4 _task_default_ldt(int *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  undefined *puVar5;
  int iVar6;
  undefined4 uVar7;
  undefined2 local_1c;
  
  puVar1 = (undefined4 *)param_1[0x10];
  iVar6 = _task_hold(param_1);
  if (iVar6 == 0) {
    _lock_write(puVar1 + 4);
    *puVar1 = _ldt + -0x40000000;
    puVar1[1] = 0x18;
    _task_dowait(param_1,1);
    puVar2 = (undefined4 *)param_1[0x10];
    do {
      do {
      } while (*param_1 != 0);
      LOCK();
      iVar6 = *param_1;
      *param_1 = 1;
      UNLOCK();
    } while (iVar6 == 1);
    piVar3 = (int *)0x0;
    for (piVar4 = (int *)param_1[7]; param_1 + 7 != piVar4; piVar4 = (int *)piVar4[4]) {
      _thread_reference(piVar4);
      LOCK();
      *param_1 = 0;
      UNLOCK();
      if (piVar3 != (int *)0x0) {
        _thread_deallocate(piVar3);
      }
      uVar7 = puVar2[1];
      *(undefined4 *)(piVar4[10] + 0x74) = *puVar2;
      *(undefined4 *)(piVar4[10] + 0x78) = uVar7;
      puVar5 = _gdt;
      if (_active_threads == piVar4) {
        uVar7 = *(undefined4 *)(piVar4[10] + 0x74);
        iVar6 = *(int *)(piVar4[10] + 0x78) + -1;
        *(short *)(_gdt + 0x22) = (short)uVar7;
        puVar5[0x24] = (char)((uint)uVar7 >> 0x10);
        puVar5[0x27] = (char)((uint)uVar7 >> 0x18);
        puVar5[0x25] = puVar5[0x25] & 0xe0 | 0x82;
        puVar5[0x26] = puVar5[0x26] & 0x7f;
        local_1c = (undefined2)iVar6;
        *(undefined2 *)(puVar5 + 0x20) = local_1c;
        local_1c._0_1_ = (byte)((uint)iVar6 >> 0x10);
        puVar5[0x26] = puVar5[0x26] & 0xf0 | (byte)local_1c & 0xf;
        LocalDescriptorTableRegister(0x20);
      }
      do {
        do {
        } while (*param_1 != 0);
        LOCK();
        iVar6 = *param_1;
        *param_1 = 1;
        UNLOCK();
      } while (iVar6 == 1);
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
    uVar7 = 0;
  }
  else {
    uVar7 = 4;
  }
  return uVar7;
}

