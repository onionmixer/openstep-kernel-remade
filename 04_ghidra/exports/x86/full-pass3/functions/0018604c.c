/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018604c */

undefined4 FUN_0018604c(char *param_1)

{
  char cVar1;
  int iVar2;
  
  for (; *param_1 != '\0'; param_1 = param_1 + 1) {
    if ((*param_1 == ' ') || (*param_1 == '\t')) goto LAB_00186077;
  }
LAB_0018607c:
  iVar2 = 0;
  cVar1 = *param_1;
  while ((cVar1 != '\0' && ((byte)(*param_1 - 0x30U) < 10))) {
    iVar2 = (int)*param_1 + iVar2 * 10 + -0x30;
    param_1 = param_1 + 1;
    cVar1 = *param_1;
  }
  if (iVar2 == 0) {
    iVar2 = 6;
  }
  _printf(s_State_pointer___0x_x_001e1728,_miniMonState);
  if (_miniMonState != 0) {
    __i386_backtrace(_miniMonState,iVar2);
  }
  return 1;
LAB_00186077:
  for (; (*param_1 != '\0' && ((*param_1 == ' ' || (*param_1 == '\t')))); param_1 = param_1 + 1) {
  }
  goto LAB_0018607c;
}

