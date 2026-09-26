/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00157958 */

kern_return_t
_host_processors(host_priv_t host_priv,processor_array_t *out_processor_list,
                mach_msg_type_number_t *out_processor_listCnt)

{
  kern_return_t kVar1;
  int iVar2;
  processor_array_t ppVar3;
  processor_array_t ppVar4;
  processor_t pVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int local_c;
  
  if (host_priv == 0) {
    kVar1 = 4;
  }
  else {
    uVar8 = 0;
    iVar6 = 0;
    iVar2 = 0;
    do {
      if (*(int *)((int)&_machine_slot + iVar2) != 0) {
        uVar8 = uVar8 + 1;
      }
      iVar2 = iVar2 + 0x20;
      iVar6 = iVar6 + 1;
    } while (iVar6 < 1);
    if (uVar8 == 0) {
                    /* WARNING: Subroutine does not return */
      _panic(s_host_processors_001deb90);
    }
    ppVar3 = (processor_array_t)_kalloc(uVar8 * 4);
    if (ppVar3 == (processor_array_t)0x0) {
      kVar1 = 6;
    }
    else {
      iVar2 = 0;
      local_c = 0;
      ppVar4 = ppVar3;
      do {
        if (*(int *)((int)&_machine_slot + local_c) != 0) {
          *ppVar4 = (&_processor_ptr)[iVar2];
          ppVar4 = ppVar4 + 1;
        }
        local_c = local_c + 0x20;
        iVar2 = iVar2 + 1;
      } while (iVar2 < 1);
      *out_processor_listCnt = uVar8;
      *out_processor_list = ppVar3;
      uVar7 = 0;
      if (uVar8 != 0) {
        do {
          pVar5 = _convert_processor_to_port(*ppVar3);
          *ppVar3 = pVar5;
          ppVar3 = ppVar3 + 1;
          uVar7 = uVar7 + 1;
        } while (uVar7 < uVar8);
      }
      kVar1 = 0;
    }
  }
  return kVar1;
}

