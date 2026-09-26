/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00182fc8 */

void FUN_00182fc8(int *param_1,int param_2)

{
  undefined4 uVar1;
  
  if (((((uint)param_1[1] < 0x24) || (*param_1 < 0)) ||
      ((*(byte *)((int)param_1 + 0x1b) & 0x30) != 0x30)) ||
     ((param_1[7] != 0x80008 || (param_1[1] != (param_1[8] + 3U & 0xfffffffc) + 0x24)))) {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  else {
    uVar1 = _convert_port_to_host(param_1[2],param_1 + 9,param_1[8]);
    uVar1 = _kern_IOProbeDriver(uVar1);
    *(undefined4 *)(param_2 + 0x1c) = uVar1;
  }
  return;
}

