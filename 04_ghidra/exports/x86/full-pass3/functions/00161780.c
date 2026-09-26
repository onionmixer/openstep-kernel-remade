/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00161780 */

kern_return_t
_processor_info(processor_t processor,processor_flavor_t flavor,host_t *host,
               processor_info_t processor_info_out,mach_msg_type_number_t *processor_info_outCnt)

{
  int iVar1;
  kern_return_t kVar2;
  
  if (processor == 0) {
    kVar2 = 4;
  }
  else if ((flavor == 1) && (4 < *processor_info_outCnt)) {
    iVar1 = *(int *)(processor + 0x144);
    *processor_info_out = (&DAT_001e8e04)[iVar1 * 8];
    processor_info_out[1] = (&DAT_001e8e08)[iVar1 * 8];
    if ((*(int *)(processor + 0x114) == 5) || (*(int *)(processor + 0x114) == 0)) {
      processor_info_out[2] = 0;
    }
    else {
      processor_info_out[2] = 1;
    }
    processor_info_out[3] = iVar1;
    if (_master_processor == processor) {
      processor_info_out[4] = 1;
    }
    else {
      processor_info_out[4] = 0;
    }
    *processor_info_outCnt = 5;
    *host = (host_t)&_realhost;
    kVar2 = 0;
  }
  else {
    kVar2 = 5;
  }
  return kVar2;
}

