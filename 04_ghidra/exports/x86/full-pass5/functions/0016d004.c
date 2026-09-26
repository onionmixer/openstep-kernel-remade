/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016d004 */

void FUN_0016d004(int *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = param_2 * 0x20 + _page_mask & ~_page_mask;
  iVar1 = _kalloc(uVar2);
  *param_1 = iVar1;
  param_1[2] = iVar1 + (uVar2 & 0xffffffe0);
  param_1[1] = *param_1;
  _printf(s_kern_serv_log_init__log_0x_x_log_001dfed1,param_1,param_1[2],*param_1);
  return;
}

