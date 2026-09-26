/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014c0e4 */

undefined4 _ipc_object_copyout_type_compat(uint param_1)

{
  if (param_1 == 0x10) {
    return 5;
  }
  if ((0xf < param_1) && (param_1 < 0x13)) {
    return 6;
  }
                    /* WARNING: Subroutine does not return */
  _panic(s_ipc_object_copyout_type_compat__s_001de92b);
}

