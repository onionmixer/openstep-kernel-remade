/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017b7bc */

void _vm_page_unwire(undefined4 *param_1)

{
  short sVar1;
  
  sVar1 = *(short *)(param_1 + 7);
  *(short *)(param_1 + 7) = sVar1 + -1;
  if (sVar1 == 1) {
    if ((undefined4 **)DAT_001f6e44 == &_vm_page_queue_active) {
      _vm_page_queue_active = param_1;
    }
    else {
      *DAT_001f6e44 = param_1;
    }
    param_1[1] = DAT_001f6e44;
    *param_1 = &_vm_page_queue_active;
    DAT_001f6e44 = param_1;
    _vm_page_active_count = _vm_page_active_count + 1;
    *(byte *)((int)param_1 + 0x1e) = *(byte *)((int)param_1 + 0x1e) | 2;
    _vm_page_wire_count = _vm_page_wire_count + -1;
  }
  return;
}

