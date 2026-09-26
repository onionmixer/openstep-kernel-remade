
int sub_40963BC(int param_1)

{
  bool bVar1;
  int iVar2;
  int aiStack_1c [2];
  int iStack_14;
  int *piStack_10;
  int iStack_c;
  int *piStack_8;
  
  piStack_8 = (int *)&_kdb_net;
  iStack_14 = 0;
loc_40963D0:
  iStack_c = _en_recv(aiStack_1c,0x242,piStack_8[2],_kdb_ipaddr);
  if (iStack_c == 0) {
    if ((param_1 == 0) ||
       (iVar2 = iStack_14 + 1, bVar1 = iStack_14 < param_1, iStack_14 = iVar2, bVar1))
    goto loc_40963D0;
  }
  if ((param_1 != 0) && (iStack_c == 0)) {
    return 0;
  }
  if (aiStack_1c[0] == 0x473) {
    piStack_10 = (int *)(iStack_c + 0x2a);
    if (*piStack_8 == *piStack_10) {
      return iStack_c;
    }
    if (*piStack_8 + -1 == *piStack_10) {
      _kdebug_send(0x473,*piStack_10);
    }
    else if ((*piStack_10 == 0) && (*(int *)(iStack_c + 0x2e) == 8)) {
      *piStack_8 = 0;
      return iStack_c;
    }
  }
  goto loc_40963D0;
}

