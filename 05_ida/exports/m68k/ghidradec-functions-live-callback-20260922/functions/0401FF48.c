
void _icmp_error(byte *param_1,uint param_2,undefined param_3,undefined4 param_4,undefined4 *param_5
                )

{
  undefined *puVar1;
  byte bVar2;
  sword sVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar5 = (*param_1 & 0xf) * 4;
  if (param_2 != 5) {
    _icmpstat = _icmpstat + 1;
  }
  if ((*(word *)(param_1 + 6) & 0x9fff) == 0) {
    if ((((param_1[9] == 1) && (param_2 != 5)) && (bVar2 = param_1[iVar5], bVar2 != 0)) &&
       (((bVar2 != 8 && (1 < (byte)(bVar2 - 0xd))) &&
        ((1 < (byte)(bVar2 - 0xf) && (1 < (byte)(bVar2 - 0x11))))))) {
      dword_40B7BDC = dword_40B7BDC + 1;
    }
    else if ((*(uint *)(param_1 + 0x10) & 0xf0000000) != 0xe0000000) {
      iVar4 = _in_broadcast(*(uint *)(param_1 + 0x10));
      if (iVar4 == 0) {
        iVar4 = _m_get(0,2);
        if (iVar4 != 0) {
          if (*(sword *)(param_1 + 2) < 9) {
            iVar7 = iVar5 + *(sword *)(param_1 + 2);
          }
          else {
            iVar7 = iVar5 + 8;
          }
          sVar3 = (sword)iVar7 + 8;
          *(sword *)(iVar4 + 8) = sVar3;
          iVar6 = 0x7c - sVar3;
          *(int *)(iVar4 + 4) = iVar6;
          puVar1 = (undefined *)(iVar4 + iVar6);
          if (0x12 < param_2) {
                    /* WARNING: Subroutine does not return */
            _panic(aIcmpError);
          }
          *(int *)(unk_40B7BE0 + param_2 * 4) = *(int *)(unk_40B7BE0 + param_2 * 4) + 1;
          *puVar1 = (char)param_2;
          if (param_2 == 5) {
            *(undefined4 *)(puVar1 + 4) = *param_5;
          }
          else {
            *(undefined4 *)(puVar1 + 4) = 0;
          }
          if (param_2 == 0xc) {
            puVar1[4] = param_3;
            param_3 = 0;
          }
          puVar1[1] = param_3;
          _bcopy(param_1,puVar1 + 8,iVar7);
          *(sword *)(puVar1 + 10) = (sword)iVar5 + *(sword *)(puVar1 + 10);
          if (0x70 < (uint)(*(sword *)(iVar4 + 8) + iVar5)) {
            iVar5 = 0x14;
          }
          if (0x70 < (uint)(iVar5 + *(sword *)(iVar4 + 8))) {
                    /* WARNING: Subroutine does not return */
            _panic(aIcmpLen);
          }
          *(int *)(iVar4 + 4) = *(int *)(iVar4 + 4) - iVar5;
          *(sword *)(iVar4 + 8) = (sword)iVar5 + *(sword *)(iVar4 + 8);
          iVar7 = *(int *)(iVar4 + 4) + iVar4;
          _bcopy(param_1,iVar7,iVar5);
          *(undefined2 *)(iVar7 + 2) = *(undefined2 *)(iVar4 + 8);
          *(undefined *)(iVar7 + 9) = 1;
          _icmp_reflect(iVar7,param_4);
        }
      }
    }
  }
  _m_freem((uint)param_1 & 0xffffff80);
  return;
}

