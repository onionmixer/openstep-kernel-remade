/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001618c0 */

kern_return_t _processor_get_assignment(processor_t processor,processor_set_name_t *assigned_set)

{
  int *piVar1;
  int iVar2;
  processor_set_name_t pVar3;
  
  if ((*(int *)(processor + 0x114) != 5) && (*(int *)(processor + 0x114) != 0)) {
    *assigned_set = *(processor_set_name_t *)(processor + 300);
    pVar3 = *assigned_set;
    piVar1 = (int *)(pVar3 + 0x148);
    do {
      do {
      } while (*piVar1 != 0);
      LOCK();
      iVar2 = *piVar1;
      *piVar1 = 1;
      UNLOCK();
    } while (iVar2 == 1);
    *(int *)(pVar3 + 0x144) = *(int *)(pVar3 + 0x144) + 1;
    LOCK();
    *(undefined4 *)(pVar3 + 0x148) = 0;
    UNLOCK();
    return 0;
  }
  return 5;
}

