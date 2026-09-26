/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015c59c */

section_64 * _getsectbyname(char *segname,char *sectname)

{
  int iVar1;
  section_64 *psVar2;
  uint uVar3;
  segment_command *psVar4;
  uint local_8;
  
  psVar4 = &segment_command_0010001c;
  local_8 = 0;
  do {
    if (6 < local_8) {
      return (section_64 *)0x0;
    }
    if ((psVar4->cmd == 1) && (iVar1 = _strncmp(psVar4->segname,segname,0x10), iVar1 == 0)) {
      psVar2 = (section_64 *)(psVar4 + 1);
      uVar3 = 0;
      if (psVar4->nsects != 0) {
        do {
          iVar1 = _strncmp(psVar2->sectname,sectname,0x10);
          if ((iVar1 == 0) && (iVar1 = _strncmp(psVar2->segname,segname,0x10), iVar1 == 0)) {
            return psVar2;
          }
          psVar2 = (section_64 *)&psVar2->reserved1;
          uVar3 = uVar3 + 1;
        } while (uVar3 < psVar4->nsects);
      }
    }
    psVar4 = (segment_command *)(psVar4->segname + (psVar4->cmdsize - 8));
    local_8 = local_8 + 1;
  } while( true );
}

