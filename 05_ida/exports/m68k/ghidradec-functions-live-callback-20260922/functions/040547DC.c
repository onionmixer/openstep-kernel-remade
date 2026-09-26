
void sub_40547DC(void)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int *piVar5;
  
  uVar3 = _active_threads;
  while (0 < dword_40B4DD0) {
    if ((int **)dword_40B4DC0 == &dword_40B4DC0) {
      piVar5 = (int *)0x0;
    }
    else {
      *(int ***)(*dword_40B4DC0 + 4) = &dword_40B4DC0;
      piVar5 = dword_40B4DC0;
      dword_40B4DC0 = (int *)*dword_40B4DC0;
    }
    dword_40B4DD0 = dword_40B4DD0 + -1;
    pcVar1 = (code *)piVar5[2];
    iVar2 = piVar5[3];
    piVar5[7] = 0;
    piVar4 = piVar5;
    if ((&DAT_40b45b3 < piVar5) && (piVar5 < &DAT_40b4db4)) {
      *piVar5 = (int)&dword_40B4DB8;
      piVar5[1] = (int)dword_40B4DBC;
      *(int **)piVar5[1] = piVar5;
      piVar4 = (int *)0x0;
      dword_40B4DBC = piVar5;
    }
    dword_40B4DD4 = dword_40B4DD4 + 1;
    (*pcVar1)(iVar2,piVar4);
    dword_40B4DD4 = dword_40B4DD4 + -1;
  }
  if (dword_40B4DD8 - dword_40B4DD4 < 5) {
    _assert_wait(&dword_40B4DD0,0);
    _thread_block_with_continuation(sub_40547DC);
  }
  dword_40B4DD8 = dword_40B4DD8 + -1;
  _thread_terminate(uVar3);
  _thread_halt_self();
  return;
}

