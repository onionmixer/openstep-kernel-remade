/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015c2fc */

uint _getlastaddr(void)

{
  uint uVar1;
  segment_command *psVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = 0;
  psVar2 = &segment_command_0010001c;
  uVar3 = 0;
  do {
    if ((psVar2->cmd == 1) && (uVar1 = psVar2->vmaddr + psVar2->vmsize, uVar4 < uVar1)) {
      uVar4 = uVar1;
    }
    psVar2 = (segment_command *)(psVar2->segname + (psVar2->cmdsize - 8));
    uVar3 = uVar3 + 1;
  } while (uVar3 < 7);
  return uVar4;
}

