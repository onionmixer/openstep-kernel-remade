
void _idle_thread_continue(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  
  iVar6 = _processor_ptr;
  piVar4 = (int *)(_processor_ptr + 0x114);
  piVar5 = (int *)(_processor_ptr + 0x104);
  do {
    while( true ) {
      _PMSetCpuState(0);
      while (((*piVar4 == 0 && (dword_40B674C == 0)) && (*piVar5 == 0))) {
        if ((_need_ast & 0xfffffff8) != 0) {
          _need_ast = _need_ast & 0xfffffff8;
        }
      }
      _PMSetCpuState(1);
      iVar1 = *(int *)(iVar6 + 0x110);
      if (iVar1 != 3) break;
      iVar1 = *piVar4;
      *piVar4 = 0;
      *(undefined4 *)(iVar6 + 0x110) = 1;
      if (*(int *)(iVar1 + 0x5c) == 2) {
        *(undefined4 *)(iVar6 + 0x11c) = *(undefined4 *)(iVar1 + 0x58);
      }
      else {
        *(undefined4 *)(iVar6 + 0x11c) = dword_40B67A4;
      }
      *(undefined4 *)(iVar6 + 0x120) = 1;
      _thread_run(_idle_thread_continue,iVar1);
    }
    if (iVar1 == 2) {
      iVar1 = *(int *)(iVar6 + 0x128);
      _no_dispatch_count = _no_dispatch_count + 1;
      *(int *)(iVar1 + 0x110) = *(int *)(iVar1 + 0x110) + -1;
      iVar2 = *(int *)(iVar6 + 0x108);
      piVar3 = *(int **)(iVar6 + 0x10c);
      if (iVar2 == iVar1 + 0x108) {
        *(int **)(iVar1 + 0x10c) = piVar3;
      }
      else {
        *(int **)(iVar2 + 0x10c) = piVar3;
      }
      if (piVar3 == (int *)(iVar1 + 0x108)) {
        *piVar3 = iVar2;
      }
      else {
        piVar3[0x42] = iVar2;
      }
      *(undefined4 *)(iVar6 + 0x110) = 1;
    }
    else {
      if (1 < iVar1 - 4U) {
        _printf(aBadProcessorSt,*(undefined4 *)(_processor_ptr + 0x110),0);
                    /* WARNING: Subroutine does not return */
        _panic(aIdleThread);
      }
      iVar1 = *piVar4;
      if (iVar1 != 0) {
        *piVar4 = 0;
        _thread_setrun(iVar1,0);
      }
    }
    _thread_block_with_continuation(_idle_thread_continue);
  } while( true );
}

