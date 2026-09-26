/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00182d68 */

void FUN_00182d68(int *param_1,int param_2)

{
  undefined4 uVar1;
  uint uVar2;
  
  if (((((uint)param_1[1] < 0x68) || (*param_1 < 0)) || (param_1[6] != DAT_001e115c)) ||
     (((param_1[8] != DAT_001e1160 || ((param_1[0x19] & 0x3000ffffU) != 0x10000808)) ||
      (uVar2 = *(ushort *)((int)param_1 + 0x66) & 0xfff,
      param_1[1] != (uVar2 + 3 & 0xfffffffc) + 0x68)))) {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  else {
    uVar1 = _convert_port_to_host_priv(param_1[2],param_1[7],param_1 + 9,param_1 + 0x1a,uVar2);
    uVar1 = _kern_IOSetCharValues(uVar1);
    *(undefined4 *)(param_2 + 0x1c) = uVar1;
  }
  return;
}

