/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016191c */

kern_return_t
_processor_set_info(processor_set_name_t set_name,int flavor,host_t *host,
                   processor_set_info_t info_out,mach_msg_type_number_t *info_outCnt)

{
  int *piVar1;
  int iVar2;
  kern_return_t kVar3;
  
  if (set_name == 0) {
LAB_001619fd:
    kVar3 = 4;
  }
  else {
    if (flavor == 1) {
      if (*info_outCnt < 5) {
        return 5;
      }
      piVar1 = (int *)(set_name + 0x158);
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar2 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar2 == 1);
      *info_out = *(integer_t *)(set_name + 0x124);
      info_out[1] = *(integer_t *)(set_name + 0x134);
      info_out[2] = *(integer_t *)(set_name + 0x140);
      info_out[4] = *(integer_t *)(set_name + 0x170);
      info_out[3] = *(integer_t *)(set_name + 0x174);
      LOCK();
      *(undefined4 *)(set_name + 0x158) = 0;
      UNLOCK();
      *info_outCnt = 5;
    }
    else {
      if (flavor != 2) {
        *host = 0;
        goto LAB_001619fd;
      }
      if (*info_outCnt < 2) {
        return 5;
      }
      piVar1 = (int *)(set_name + 0x158);
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar2 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar2 == 1);
      *info_out = *(integer_t *)(set_name + 0x168);
      info_out[1] = *(integer_t *)(set_name + 0x164);
      LOCK();
      *(undefined4 *)(set_name + 0x158) = 0;
      UNLOCK();
      *info_outCnt = 2;
    }
    *host = (host_t)&_realhost;
    kVar3 = 0;
  }
  return kVar3;
}

