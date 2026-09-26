/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00164bc0 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_00164bc0(void)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int unaff_EBX;
  undefined4 uStack00000008;
  
  uStack00000008 = 0x164bc8;
  uStack00000008 = _splsched();
  piVar1 = (int *)(unaff_EBX + 0x20);
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar4 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar4 == 1);
  *(byte *)(unaff_EBX + 0x4c) = *(byte *)(unaff_EBX + 0x4c) | 9;
  LOCK();
  *(undefined4 *)(unaff_EBX + 0x20) = 0;
  UNLOCK();
  _splx();
  uVar2 = _processor_ptr;
  uStack00000008 = 0x164c07;
  uVar3 = _splsched();
  _need_ast = _need_ast & 0xfffffffb;
  do {
    uStack00000008 = uVar2;
    uStack00000008 = _thread_select();
    iVar4 = _thread_invoke();
  } while (iVar4 == 0);
  uStack00000008 = uVar3;
  _splx();
  uStack00000008 = 0x164c46;
  _sched_thread_continue();
  return;
}

