/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b277c */

int FUN_001b277c(int param_1,undefined4 param_2,char param_3)

{
  undefined *puVar1;
  
  if (param_3 == '\x01') {
    if (*(char *)(param_1 + 0x1d3) != '\0') {
      return param_1;
    }
    puVar1 = PTR_s_doAutoDim_001f999c;
    if (*(char *)(param_1 + 0x1d2) == '\x01') {
      *(undefined4 *)(param_1 + 0x1a4) = *(undefined4 *)(*(int *)(param_1 + 0x168) + 0x10);
      puVar1 = PTR_s_doAutoDim_001f999c;
    }
  }
  else {
    if (*(char *)(param_1 + 0x1d3) != '\x01') {
      return param_1;
    }
    puVar1 = PTR_s_undoAutoDim_001f99cc;
    if (*(char *)(param_1 + 0x1d2) == '\x01') {
      *(int *)(param_1 + 0x1a4) =
           *(int *)(*(int *)(param_1 + 0x168) + 0x10) + *(int *)(param_1 + 0x1a0);
      puVar1 = PTR_s_undoAutoDim_001f99cc;
    }
  }
  _objc_msgSend(param_1,puVar1);
  return param_1;
}

