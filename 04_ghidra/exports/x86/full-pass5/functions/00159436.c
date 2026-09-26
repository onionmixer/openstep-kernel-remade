/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00159436 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_00159436(void)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 unaff_EBX;
  int iVar3;
  int unaff_EBP;
  int unaff_ESI;
  int unaff_EDI;
  
  *(undefined4 *)(unaff_ESI + 100) = 0;
  *(undefined4 *)(unaff_ESI + 0x68) = unaff_EBX;
  uVar2 = _ipc_port_make_send();
  *(undefined4 *)(unaff_ESI + 0x6c) = uVar2;
  *(undefined4 *)(unaff_ESI + 0x88) = *(undefined4 *)(unaff_EBP + -4);
  if (unaff_EDI == 0) {
    *(undefined4 *)(unaff_ESI + 0x70) = 0;
    *(undefined4 *)(unaff_ESI + 0x74) = 0;
    iVar3 = 3;
    do {
      *(undefined4 *)(unaff_ESI + 0x78 + iVar3 * 4) = 0;
      iVar3 = iVar3 + -1;
    } while (-1 < iVar3);
  }
  else {
    piVar1 = (int *)(unaff_EDI + 100);
    do {
      do {
      } while (*piVar1 != 0);
      LOCK();
      iVar3 = *piVar1;
      *piVar1 = 1;
      UNLOCK();
    } while (iVar3 == 1);
    iVar3 = 0;
    do {
      uVar2 = _ipc_port_copy_send();
      *(undefined4 *)(unaff_ESI + 0x78 + iVar3 * 4) = uVar2;
      iVar3 = iVar3 + 1;
    } while (iVar3 < 4);
    uVar2 = _ipc_port_copy_send();
    *(undefined4 *)(unaff_ESI + 0x70) = uVar2;
    uVar2 = _ipc_port_copy_send(*(undefined4 *)(unaff_EDI + 0x74));
    *(undefined4 *)(unaff_ESI + 0x74) = uVar2;
    LOCK();
    uVar2 = *(undefined4 *)(unaff_EDI + 100);
    *(undefined4 *)(unaff_EDI + 100) = 0;
    UNLOCK();
  }
  return uVar2;
}

