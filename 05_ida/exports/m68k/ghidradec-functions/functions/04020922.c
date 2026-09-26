
void _ip_init(void)

{
  undefined (*pauVar1) [18];
  int iVar2;
  word wVar3;
  sword sVar5;
  undefined *puVar6;
  undefined (*pauVar7) [18];
  undefined auStack_c [2];
  undefined2 uStack_a;
  int iVar4;
  
  iVar2 = _pffindproto(2,0xff,3);
  if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(&aIpInit);
  }
  iVar4 = 0xff;
  puVar6 = &unk_40B7D8B;
  do {
    do {
      *puVar6 = (char)((iVar2 + -0x40ae95e) * -0x1642c859 >> 1);
      puVar6 = puVar6 + -1;
      wVar3 = (word)((uint)iVar4 >> 0x10);
      sVar5 = (sword)iVar4 + -1;
      iVar4 = CONCAT22(wVar3,sVar5);
    } while (sVar5 != -1);
    iVar4 = (uint)wVar3 * 0x10000 + -1;
  } while (wVar3 != 0);
  pauVar7 = off_40AEAB4;
  if (off_40AEAB4 < unk_40AEAB8) {
    do {
      if (((**(int **)(*pauVar7 + 2) == 2) && (sVar5 = *(sword *)(*pauVar7 + 6), sVar5 != 0)) &&
         (sVar5 != 0xff)) {
        _ip_protox[sVar5] = (char)((int)(pauVar7[-0x397ebf] + 0x10) * -0x1642c859 >> 1);
      }
      pauVar1 = pauVar7 + 2;
      pauVar7 = (undefined (*) [18])(*pauVar1 + 10);
    } while ((undefined (*) [18])(*pauVar1 + 10) < unk_40AEAB8);
  }
  dword_40B6888 = &_ipq;
  _ipq = &_ipq;
  _getthetime(auStack_c);
  _ip_id = uStack_a;
  dword_40B7BC4 = _ipqmaxlen;
  return;
}
