
void _SENDEXC(void)

{
  int iVar1;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  undefined4 *puStack_10;
  int iStack_c;
  int *piStack_8;
  
  iVar1 = dword_40C8F04;
  piStack_8 = (int *)&_kdb_net;
  iStack_c = dword_40C8F04;
  puStack_10 = (undefined4 *)(dword_40C8F04 + 0x2a);
  *(undefined4 *)(dword_40C8F04 + 0x2e) = dword_40B5630;
  *(undefined4 *)(iVar1 + 0x3a) = dword_40B5638;
  *(undefined4 *)(iVar1 + 0x36) = dword_40B5634;
  *puStack_10 = DAT_40c9470;
  do {
    _en_send(0x474,iStack_c,0x242);
    for (iStack_18 = 0; iStack_18 < 50000; iStack_18 = iStack_18 + 1) {
      iStack_14 = _en_recv(&iStack_1c,0x242,piStack_8[2],_kdb_ipaddr);
      if (iStack_14 != 0) {
        if ((iStack_1c == 0x474) && (piStack_8[1] == *(int *)(iStack_14 + 0x2a))) {
          piStack_8[1] = piStack_8[1] + 1;
          return;
        }
        iStack_1c = 0x473;
        if (*piStack_8 + -1 == *(int *)(iStack_14 + 0x2a)) {
          _kdebug_send(0x473,*(int *)(iStack_14 + 0x2a));
        }
      }
    }
  } while( true );
}
