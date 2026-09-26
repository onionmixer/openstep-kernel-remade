/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00193e58 */

undefined4 _pagemove(int param_1,int param_2,uint param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 in_CR3;
  
  if ((param_3 & 0xfff) != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(s_pagemove_001e294a);
  }
  for (; 0 < (int)param_3; param_3 = param_3 - 0x1000) {
    puVar1 = (undefined4 *)_pmap_pt_entry(_kernel_pmap,param_1);
    puVar2 = (undefined4 *)_pmap_pt_entry(_kernel_pmap,param_2);
    *puVar2 = *puVar1;
    *puVar1 = 0;
    param_1 = param_1 + 0x1000;
    param_2 = param_2 + 0x1000;
  }
  return in_CR3;
}

