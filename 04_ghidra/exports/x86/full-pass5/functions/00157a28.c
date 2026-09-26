/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00157a28 */

kern_return_t
_host_info(host_t host,host_flavor_t flavor,host_info_t host_info_out,
          mach_msg_type_number_t *host_info_outCnt)

{
  int iVar1;
  int iVar2;
  
  if (host != 0) {
    if (flavor != 2) {
      if (flavor < 3) {
        if (flavor != 1) {
          return 4;
        }
        if (4 < *host_info_outCnt) {
          *host_info_out = DAT_001f6348;
          host_info_out[1] = DAT_001f634c;
          host_info_out[2] = DAT_001f6350;
          iVar1 = _master_processor;
          host_info_out[3] = (&DAT_001e8e04)[*(int *)(_master_processor + 0x144) * 8];
          host_info_out[4] = (&DAT_001e8e08)[*(int *)(iVar1 + 0x144) * 8];
          *host_info_outCnt = 5;
          return 0;
        }
      }
      else if (flavor == 3) {
        if (1 < *host_info_outCnt) {
          iVar1 = _tick / 1000;
          *host_info_out = iVar1;
          host_info_out[1] = iVar1;
          *host_info_outCnt = 2;
          return 0;
        }
      }
      else {
        if (flavor != 4) {
          return 4;
        }
        if (5 < *host_info_outCnt) {
          _bcopy(&_avenrun,host_info_out,0xc);
          _bcopy(&_mach_factor,host_info_out + 3,0xc);
          *host_info_outCnt = 6;
          return 0;
        }
      }
      return 5;
    }
    if (*host_info_outCnt != 0) {
      *host_info_outCnt = 0;
      iVar1 = 0;
      iVar2 = 0;
      do {
        if ((*(int *)((int)&_machine_slot + iVar2) != 0) &&
           (*(int *)((int)&DAT_001e8e0c + iVar2) != 0)) {
          *host_info_out = iVar1;
          host_info_out = host_info_out + 1;
          *host_info_outCnt = *host_info_outCnt + 1;
        }
        iVar2 = iVar2 + 0x20;
        iVar1 = iVar1 + 1;
      } while (iVar1 < 1);
      return 0;
    }
  }
  return 4;
}

