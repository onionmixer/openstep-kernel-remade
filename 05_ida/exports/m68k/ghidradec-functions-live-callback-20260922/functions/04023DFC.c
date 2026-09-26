
void _tcp_pulloutofband(int param_1,int param_2,int *param_3)

{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  undefined *puVar4;
  
  iVar3 = *(word *)(param_2 + 0x26) - 1;
  do {
    if (iVar3 < 0) break;
    if (iVar3 < *(sword *)(param_3 + 2)) {
      puVar4 = (undefined *)((int)param_3 + iVar3 + param_3[1]);
      iVar1 = *(int *)(*(int *)(param_1 + 8) + 0x1c);
      *(undefined *)(iVar1 + 0x69) = *puVar4;
      pbVar2 = (byte *)(iVar1 + 0x68);
      *pbVar2 = *pbVar2 | 1;
      _bcopy(puVar4 + 1,puVar4,(*(sword *)(param_3 + 2) - iVar3) + -1);
      *(sword *)(param_3 + 2) = *(sword *)(param_3 + 2) + -1;
      return;
    }
    iVar3 = iVar3 - *(sword *)(param_3 + 2);
    param_3 = (int *)*param_3;
  } while (param_3 != (int *)0x0);
                    /* WARNING: Subroutine does not return */
  _panic(aTcpPulloutofba);
}

