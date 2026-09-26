/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001568fe */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_001568fe(void)

{
  int *piVar1;
  int iVar2;
  mach_port_t task;
  mach_port_t thread;
  int unaff_EBP;
  int unaff_ESI;
  exception_type_t unaff_EDI;
  mach_msg_type_number_t codeCnt;
  exception_data_t code;
  
  codeCnt = *(mach_msg_type_number_t *)(unaff_EBP + -4);
  *(undefined4 *)(unaff_ESI + 0x38) = *(undefined4 *)(unaff_EBP + 0x14);
  piVar1 = (int *)(unaff_ESI + 0xa8);
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar2 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar2 == 1);
  piVar1 = *(int **)(unaff_ESI + 0xb4);
  if ((piVar1 == (int *)0x0) || (piVar1 == (int *)0xffffffff)) {
    LOCK();
    *(undefined4 *)(unaff_ESI + 0xa8) = 0;
    UNLOCK();
  }
  else {
    do {
      do {
      } while (*piVar1 != 0);
      LOCK();
      iVar2 = *piVar1;
      *piVar1 = 1;
      UNLOCK();
    } while (iVar2 == 1);
    LOCK();
    *(undefined4 *)(unaff_ESI + 0xa8) = 0;
    UNLOCK();
    if (piVar1[2] < 0) {
      piVar1[1] = piVar1[1] + 1;
      piVar1[7] = piVar1[7] + 1;
      LOCK();
      *piVar1 = 0;
      UNLOCK();
      *(exception_type_t *)(unaff_ESI + 200) = unaff_EDI;
      code = *(exception_data_t *)(unaff_EBP + 0xc);
      *(exception_data_t *)(unaff_ESI + 0xcc) = code;
      *(mach_msg_type_number_t *)(unaff_ESI + 0xd0) = codeCnt;
      task = _retrieve_task_self_fast(*(undefined4 *)(unaff_ESI + 0xc));
      thread = _retrieve_thread_self_fast();
      _exception_raise((mach_port_t)piVar1,thread,task,unaff_EDI,code,codeCnt);
      return;
    }
    LOCK();
    *piVar1 = 0;
    UNLOCK();
  }
  _exception_try_task();
  return;
}

