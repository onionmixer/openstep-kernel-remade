/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015c6b4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

segment_command * _getfakefvmseg(void)

{
  int iVar1;
  segment_command *psVar2;
  segment_command *psVar3;
  uint uVar4;
  
  psVar3 = &segment_command_0010001c;
  uVar4 = 0;
  do {
    if ((psVar3->cmd == 1) && (iVar1 = _strncmp(psVar3->segname,s___USER_001def08,0x10), iVar1 == 0)
       ) goto LAB_0015c6f6;
    psVar3 = (segment_command *)(psVar3->segname + (psVar3->cmdsize - 8));
    uVar4 = uVar4 + 1;
  } while (uVar4 < 7);
  psVar3 = (segment_command *)0x0;
LAB_0015c6f6:
  if ((psVar3 == (segment_command *)0x0) &&
     (iVar1 = _strcmp(s___USER_001def08,_fvm_seg->segname), iVar1 == 0)) {
    psVar3 = _fvm_seg;
  }
  psVar2 = &segment_command_0010001c;
  uVar4 = 0;
  do {
    if (psVar2->cmd == 9) goto LAB_0015c73f;
    psVar2 = (segment_command *)(psVar2->segname + (psVar2->cmdsize - 8));
    uVar4 = uVar4 + 1;
  } while (uVar4 < 7);
  psVar2 = (segment_command *)0x0;
LAB_0015c73f:
  if (psVar3 == (segment_command *)0x0) {
    if (psVar2 == (segment_command *)0x0) {
      psVar3 = (segment_command *)0x0;
    }
    else {
      _fvm_seg = (segment_command *)&DAT_001dee8c;
      DAT_001deea4 = *(undefined4 *)(psVar2->segname + 4);
      DAT_001deea8 = FUN_0015c7a4(DAT_001deea4);
      psVar3 = (segment_command *)_strcpy(&DAT_001deec4,*(char **)psVar2->segname);
      _DAT_001deee4 = DAT_001deea4;
      _DAT_001deee8 = DAT_001deea8;
    }
  }
  return psVar3;
}

