/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00159414 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_00159414(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBP;
  int unaff_ESI;
  int unaff_EDI;
  
  iVar2 = _ipc_port_alloc_special();
  if (iVar2 != 0) {
    *(undefined4 *)(unaff_ESI + 100) = 0;
    *(int *)(unaff_ESI + 0x68) = iVar2;
    uVar3 = _ipc_port_make_send();
    *(undefined4 *)(unaff_ESI + 0x6c) = uVar3;
    *(undefined4 *)(unaff_ESI + 0x88) = *(undefined4 *)(unaff_EBP + -4);
    if (unaff_EDI == 0) {
      *(undefined4 *)(unaff_ESI + 0x70) = 0;
      *(undefined4 *)(unaff_ESI + 0x74) = 0;
      iVar2 = 3;
      do {
        *(undefined4 *)(unaff_ESI + 0x78 + iVar2 * 4) = 0;
        iVar2 = iVar2 + -1;
      } while (-1 < iVar2);
    }
    else {
      piVar1 = (int *)(unaff_EDI + 100);
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar2 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar2 == 1);
      iVar2 = 0;
      do {
        uVar3 = _ipc_port_copy_send();
        *(undefined4 *)(unaff_ESI + 0x78 + iVar2 * 4) = uVar3;
        iVar2 = iVar2 + 1;
      } while (iVar2 < 4);
      uVar3 = _ipc_port_copy_send();
      *(undefined4 *)(unaff_ESI + 0x70) = uVar3;
      uVar3 = _ipc_port_copy_send(*(undefined4 *)(unaff_EDI + 0x74));
      *(undefined4 *)(unaff_ESI + 0x74) = uVar3;
      LOCK();
      uVar3 = *(undefined4 *)(unaff_EDI + 100);
      *(undefined4 *)(unaff_EDI + 100) = 0;
      UNLOCK();
    }
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  _panic(s_ipc_task_init_001decd2);
}

