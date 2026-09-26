/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00165a48 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_00165a48(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *unaff_EBX;
  int unaff_EBP;
  undefined *puVar4;
  int *unaff_EDI;
  
  uVar3 = _zalloc();
  unaff_EBX[0xe] = uVar3;
  _utask_zero();
  unaff_EBX[1] = 2;
  if (*(undefined4 **)(unaff_EBP + 0x10) == &_kernel_task) {
    unaff_EBX[3] = _kernel_map;
  }
  else if (*(int *)(unaff_EBP + 0xc) == 0) {
    uVar3 = _pmap_create(0,0,~_page_mask & 0xc0000000);
    uVar3 = _vm_map_create(uVar3);
    unaff_EBX[3] = uVar3;
  }
  else {
    uVar3 = _vm_map_fork();
    unaff_EBX[3] = uVar3;
  }
  *unaff_EBX = 0;
  unaff_EBX[8] = unaff_EBX + 7;
  unaff_EBX[7] = unaff_EBX + 7;
  unaff_EBX[10] = 0;
  unaff_EBX[6] = 0;
  unaff_EBX[2] = 1;
  unaff_EBX[0x11] = 0;
  unaff_EBX[9] = 0;
  unaff_EBX[0x10] = 0;
  _pcb_common_init();
  unaff_EBX[0x14] = 0;
  _ipc_task_init();
  unaff_EBX[0x15] = 0;
  unaff_EBX[0x16] = 0;
  unaff_EBX[0x17] = 0;
  unaff_EBX[0x18] = 0;
  if (unaff_EDI == (int *)0x0) {
    unaff_EBX[0x13] = 0;
    puVar4 = &_default_pset;
    _pset_reference();
    unaff_EBX[0x12] = 10;
  }
  else {
    unaff_EBX[0x13] = unaff_EDI[0x13];
    do {
      do {
      } while (*unaff_EDI != 0);
      LOCK();
      iVar2 = *unaff_EDI;
      *unaff_EDI = 1;
      UNLOCK();
    } while (iVar2 == 1);
    puVar4 = (undefined *)unaff_EDI[0xb];
    if (*(int *)(puVar4 + 0x154) == 0) {
      puVar4 = &_default_pset;
    }
    _pset_reference();
    unaff_EBX[0x12] = unaff_EDI[0x12];
    LOCK();
    *unaff_EDI = 0;
    UNLOCK();
  }
  piVar1 = (int *)(puVar4 + 0x158);
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar2 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar2 == 1);
  _pset_add_task(puVar4);
  LOCK();
  *(undefined4 *)(puVar4 + 0x158) = 0;
  UNLOCK();
  unaff_EBX[0xc] = 1;
  unaff_EBX[0xd] = 0;
  _ipc_task_enable();
  **(undefined4 **)(unaff_EBP + 0x10) = unaff_EBX;
  return 0;
}

