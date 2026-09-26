/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00186f88 */

int _set_label(int *param_1)

{
  int iVar1;
  int unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  int unaff_EDI;
  int unaff_retaddr;
  
  iVar1 = _curipl();
  param_1[6] = iVar1;
  *param_1 = unaff_EDI;
  param_1[1] = unaff_ESI;
  param_1[2] = unaff_EBX;
  param_1[3] = unaff_EBP;
  param_1[4] = (int)register0x00000010;
  param_1[5] = unaff_retaddr;
  return 0;
}

