/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015c534 */

segment_command_64 * _getsegbyname(char *segname)

{
  int iVar1;
  segment_command *psVar2;
  uint uVar3;
  
  psVar2 = &segment_command_0010001c;
  uVar3 = 0;
  do {
    if (((segment_command_64 *)psVar2)->cmd == 1) {
      iVar1 = _strncmp(((segment_command_64 *)psVar2)->segname,segname,0x10);
      if (iVar1 == 0) goto LAB_0015c572;
    }
    psVar2 = (segment_command *)
             (((segment_command_64 *)psVar2)->segname +
             (((segment_command_64 *)psVar2)->cmdsize - 8));
    uVar3 = uVar3 + 1;
  } while (uVar3 < 7);
  psVar2 = (segment_command *)0x0;
LAB_0015c572:
  if (((segment_command_64 *)psVar2 == (segment_command_64 *)0x0) &&
     (iVar1 = _strcmp(segname,_fvm_seg->segname), iVar1 == 0)) {
    psVar2 = (segment_command *)_fvm_seg;
  }
  return (segment_command_64 *)psVar2;
}

