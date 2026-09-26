/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001859dc */

void FUN_001859dc(void)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  
  iVar1 = _kalloc(0x2000);
LAB_001859f4:
  do {
    while( true ) {
      *(undefined4 *)(iVar1 + 0xc) = DAT_001e13f8;
      *(undefined4 *)(iVar1 + 4) = 0x2000;
      iVar2 = _msg_receive(iVar1,0,0);
      if (iVar2 == 0) break;
      pcVar3 = s_vol_thread__msg_receive___return_001e1696;
LAB_00185a7e:
      _printf(pcVar3,iVar2);
    }
    iVar2 = *(int *)(iVar1 + 0x14);
    if (iVar2 == 0x41) {
      FUN_0018585c(iVar1);
      goto LAB_001859f4;
    }
    if (iVar2 != 0x357) {
      pcVar3 = s_vol_thread__bogus_message_rec_d___001e16bd;
      goto LAB_00185a7e;
    }
    iVar2 = FUN_001857fc(*(undefined4 *)(iVar1 + 0x1c));
    if (iVar2 != 0) {
      if (*(code **)(iVar2 + 0xc) != (code *)0x0) {
        (**(code **)(iVar2 + 0xc))
                  (*(undefined4 *)(iVar2 + 0x10),*(undefined4 *)(iVar2 + 8),
                   *(undefined4 *)(iVar1 + 0x20));
      }
      _kfree(iVar2,0x14);
    }
  } while( true );
}

