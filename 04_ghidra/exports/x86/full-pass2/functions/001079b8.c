/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001079b8 */

void _delete_posix_proc(int param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  char local_54 [80];
  
  uVar4 = *(ushort *)(param_1 + 0x30) & 0x3f;
  piVar3 = &_posix_proc_hash + uVar4;
  iVar1 = (&_posix_proc_hash)[uVar4];
  while( true ) {
    if (iVar1 == 0) {
      _sprintf(local_54,s_delete_posix_proc____no_posix_pr_001da956,(int)*(short *)(param_1 + 0x30))
      ;
                    /* WARNING: Subroutine does not return */
      _panic(local_54);
    }
    piVar2 = (int *)*piVar3;
    if (*piVar2 == (int)*(short *)(param_1 + 0x30)) break;
    piVar3 = piVar2 + 7;
    iVar1 = piVar2[7];
  }
  *piVar3 = piVar2[7];
  _kfree(piVar2,0x20);
  return;
}

