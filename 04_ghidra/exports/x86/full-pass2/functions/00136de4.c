/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00136de4 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

boolean_t _svc_register(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 in_stack_00000008;
  undefined4 in_stack_0000000c;
  int in_stack_00000010;
  
  iVar1 = FUN_00136e88();
  if (iVar1 == 0) {
    puVar2 = (undefined4 *)_kalloc(0x10);
    puVar2[1] = in_stack_00000008;
    puVar2[2] = in_stack_0000000c;
    puVar2[3] = in_stack_00000010;
    *puVar2 = DAT_001e5a1c;
    DAT_001e5a1c = puVar2;
  }
  else if (*(int *)(iVar1 + 0xc) != in_stack_00000010) {
    return 0;
  }
  return 1;
}

