/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00159646 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_00159646(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int unaff_EBX;
  int unaff_EBP;
  undefined4 unaff_ESI;
  
  *(int *)(unaff_EBX + 0x90) = unaff_EBX;
  *(int *)(unaff_EBX + 0x94) = unaff_EBX;
  *(undefined4 *)(unaff_EBX + 0xa4) = 0;
  *(undefined4 *)(unaff_EBX + 0xa8) = 0;
  *(undefined4 *)(unaff_EBX + 0xac) = unaff_ESI;
  uVar2 = _ipc_port_make_send();
  *(undefined4 *)(unaff_EBX + 0xb0) = uVar2;
  *(undefined4 *)(unaff_EBX + 0xb4) = 0;
  *(undefined4 *)(unaff_EBX + 0xbc) = 0;
  *(undefined4 *)(unaff_EBX + 0xc0) = 0;
  iVar3 = _ipc_port_alloc_compat
                    (*(undefined4 *)(*(int *)(unaff_EBX + 0xc) + 0x88),unaff_EBP + -4,unaff_EBP + -8
                    );
  if (iVar3 != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(s_ipc_thread_init_001decf0);
  }
  puVar1 = *(undefined4 **)(unaff_EBP + -8);
  puVar1[7] = puVar1[7] + 1;
  puVar1[1] = puVar1[1] + 1;
  LOCK();
  *puVar1 = 0;
  UNLOCK();
  *(undefined4 **)(unaff_EBX + 0xb8) = puVar1;
  return;
}

