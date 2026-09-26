/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00123380 */

undefined4 _localetheraddr(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (DAT_001dba6c == 0) {
    DAT_001dba6c = 1;
    if (param_1 == (undefined4 *)0x0) {
      DAT_001dba6c = 1;
      return 0;
    }
    DAT_001e58dc = *param_1;
    DAT_001e58e0 = *(undefined2 *)(param_1 + 1);
    uVar1 = _ether_sprintf(&DAT_001e58dc);
    _printf(s_Ethernet_address____s_001dba70,uVar1);
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = DAT_001e58dc;
    *(undefined2 *)(param_2 + 1) = DAT_001e58e0;
  }
  return 1;
}

