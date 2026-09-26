/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00105840 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _load_init_program(void)

{
  undefined4 uVar1;
  uint uVar2;
  char **ppcVar3;
  char *unaff_EBX;
  char **unaff_ESI;
  int iVar4;
  vm_address_t vVar5;
  vm_address_t local_10;
  uint local_c;
  undefined4 local_8;
  
  iVar4 = 0;
  do {
    if (((byte)_boothowto & 0x10) != 0) {
      _printf(s_init_program__001da7f0);
      _gets(_init_program_name);
    }
    if (((iVar4 != 0) && (((byte)_boothowto & 0x10) == 0)) && (_init_attempts == 1)) {
      _printf(s_Load_of__s__errno__d__trying__s_001da809,_init_program_name,iVar4,
              s__etc_init_001da7ff);
      iVar4 = 0;
      _bcopy(s__etc_init_001da7ff,_init_program_name,10);
    }
    _init_attempts = _init_attempts + 1;
    if (iVar4 == 0) {
      vVar5 = 0;
      _vm_allocate(*(vm_map_t *)(*(int *)(_active_threads + 0xc) + 0xc),
                   (vm_address_t *)&stack0xffffffec,_page_size,1);
      if (vVar5 == 0) {
        vVar5 = 1;
      }
      _copyout(_init_program_name,vVar5,0x81);
      uVar2 = vVar5 + 0x8f & 0xfffffff0;
      local_10 = vVar5;
      _copyout(&_init_args,uVar2,0x80);
      ppcVar3 = (char **)(uVar2 + 0x8f & 0xfffffff0);
      local_8 = 0;
      local_c = uVar2;
      _copyout(&local_10,ppcVar3,0xc);
      __init_exec_args = local_10;
      _DAT_001e90c8 = 0;
      uVar1 = *(undefined4 *)(DAT_001e875c + 0x24);
      _DAT_001e90c4 = ppcVar3;
      *(undefined **)(DAT_001e875c + 0x24) = &_init_exec_args;
      iVar4 = _execve(unaff_EBX,unaff_ESI,ppcVar3);
      *(undefined4 *)(DAT_001e875c + 0x24) = uVar1;
    }
    else {
      _printf(s_Load_of__s_failed__errno__d_001da82a,_init_program_name,iVar4);
      iVar4 = 0;
      _boothowto._0_1_ = (byte)_boothowto | 0x10;
    }
  } while (iVar4 != 0);
  return;
}

