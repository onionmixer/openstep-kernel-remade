/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00186f20 */

void __switch_tss(int param_1,int param_2)

{
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  undefined4 unaff_retaddr;
  
  if (param_1 != 0) {
    *(undefined4 *)(param_1 + 0x44) = unaff_EDI;
    *(undefined4 *)(param_1 + 0x40) = unaff_ESI;
    *(undefined4 *)(param_1 + 0x34) = unaff_EBX;
    *(undefined4 *)(param_1 + 0x3c) = unaff_EBP;
    *(undefined4 *)(param_1 + 0x20) = unaff_retaddr;
    *(int **)(param_1 + 0x38) = &param_1;
                    /* WARNING: Could not recover jumptable at 0x00186f55. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(param_2 + 0x20))();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00186f72. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(param_2 + 0x20))();
  return;
}

