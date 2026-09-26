/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00185cf0 */

undefined4 _kdp_machine_write_regs(undefined4 param_1,int param_2,undefined4 *param_3)

{
  undefined2 *puVar1;
  
  puVar1 = DAT_001f66ac;
  if (param_2 != -2) {
    if (param_2 != -1) {
      return 3;
    }
    *(undefined4 *)(DAT_001f66ac + 0x16) = *param_3;
    *(undefined4 *)(puVar1 + 0x10) = param_3[1];
    *(undefined4 *)(puVar1 + 0x14) = param_3[2];
    *(undefined4 *)(puVar1 + 0x12) = param_3[3];
    *(undefined4 *)(puVar1 + 8) = param_3[4];
    *(undefined4 *)(puVar1 + 10) = param_3[5];
    *(undefined4 *)(puVar1 + 0xc) = param_3[6];
    *(undefined4 *)(puVar1 + 0x20) = param_3[9];
    *(undefined4 *)(puVar1 + 0x1c) = param_3[10];
    puVar1[2] = *(undefined2 *)(param_3 + 0xe);
    *puVar1 = *(undefined2 *)(param_3 + 0xf);
  }
  return 0;
}

