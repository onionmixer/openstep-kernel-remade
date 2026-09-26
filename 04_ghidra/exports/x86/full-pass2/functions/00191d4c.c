/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00191d4c */

int _initrootnet(void)

{
  bool bVar1;
  int iVar2;
  char *pcVar3;
  int local_28;
  undefined1 local_24;
  undefined1 local_23;
  undefined1 local_22;
  undefined1 local_21;
  undefined2 local_14;
  undefined1 local_10 [12];
  
  local_28 = 0;
  bVar1 = false;
  if ((_in_ifaddr == 0) || ((*(byte *)(*(int *)(_in_ifaddr + 0x20) + 0xc) & 8) != 0)) {
    local_24 = *(undefined1 *)*DAT_001e7740;
    local_23 = *(undefined1 *)(*DAT_001e7740 + 1);
    local_22 = 0x30;
    local_21 = 0;
    iVar2 = _socreate(2,&local_28,2,0);
    if (iVar2 == 0) {
      local_14 = 2;
      while (iVar2 = _ifioctl(local_28,0xc0206921,&local_24), iVar2 != 0) {
        if (iVar2 != 0x3c) {
          pcVar3 = s_initrootnet__autoaddr_failed_001e27b0;
          goto LAB_00191df9;
        }
        if (!bVar1) {
          _printf(s_initrootnet__BOOTP_timed_out__st_001e2781);
          bVar1 = true;
        }
      }
      if (bVar1) {
        _printf(s_initrootnet__BOOTP__OK___001e27ce);
      }
      pcVar3 = _inet_ntoa((in_addr)local_10);
      _printf(s_primary_network_interface___s____001e27e8,&local_24,pcVar3);
    }
    else {
      pcVar3 = s_initrootnet__socreate_failed_001e2763;
LAB_00191df9:
      _printf(pcVar3);
    }
    if (local_28 != 0) {
      _soclose(local_28);
    }
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}

