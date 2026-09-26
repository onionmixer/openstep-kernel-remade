/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015c38c */

section * _getsectbynamefromheader(mach_header *mhp,char *segname,char *sectname)

{
  int iVar1;
  section *psVar2;
  uint uVar3;
  mach_header *pmVar4;
  uint local_8;
  
  pmVar4 = mhp + 1;
  local_8 = 0;
  do {
    if (mhp->ncmds <= local_8) {
      return (section *)0x0;
    }
    if ((pmVar4->magic == 1) &&
       ((iVar1 = _strncmp((char *)&pmVar4->cpusubtype,segname,0x10), iVar1 == 0 ||
        (mhp->filetype == 1)))) {
      psVar2 = (section *)(pmVar4 + 2);
      uVar3 = 0;
      if (pmVar4[1].sizeofcmds != 0) {
        do {
          iVar1 = _strncmp(psVar2->sectname,sectname,0x10);
          if ((iVar1 == 0) && (iVar1 = _strncmp(psVar2->segname,segname,0x10), iVar1 == 0)) {
            return psVar2;
          }
          psVar2 = psVar2 + 1;
          uVar3 = uVar3 + 1;
        } while (uVar3 < pmVar4[1].sizeofcmds);
      }
    }
    pmVar4 = (mach_header *)((int)&pmVar4->magic + pmVar4->cputype);
    local_8 = local_8 + 1;
  } while( true );
}

