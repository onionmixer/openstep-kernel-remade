
int _rfscall(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
            int *param_6,int param_7)

{
  byte bVar1;
  int iVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  int iStack_10;
  int iStack_c;
  
  dword_40BBF1C = dword_40BBF1C + 1;
  *(int *)(unk_40BBF24 + param_2 * 4) = *(int *)(unk_40BBF24 + param_2 * 4) + 1;
  iStack_c = 0;
  iStack_10 = 0;
  iVar9 = 0;
  iVar6 = *(int *)(param_1 + 0x2a) << ((int)*(sword *)(unk_40AEE2C + param_2 * 2) & 0x3fU);
  bVar3 = false;
  do {
    iVar4 = sub_4028828(param_1,param_7);
    if (param_2 == 9) {
      _clntkudp_once(iVar4,1);
    }
loc_4028B56:
    do {
      uVar8 = 0;
      iVar5 = (*(code *)**(undefined4 **)(iVar4 + 4))
                        (iVar4,param_2,param_3,param_4,param_5,param_6,iVar6 / 10,
                         (iVar6 % 10) * 100000);
      switch(iVar5) {
      case :
      case :
      case :
      case :
      case :
      case :
      case :
        break;
      :
        if (iVar5 == 0x12) {
          if ((*(byte *)(param_1 + 0x14) & 0xa0) == 0x80) goto loc_4028B56;
          iStack_10 = 0x12;
          iStack_c = 4;
          uVar8 = 0;
        }
        else {
          uVar8 = *(uint *)(param_1 + 0x14) >> 0x1f;
        }
        if (uVar8 == 0) goto loc_4028C92;
        iVar2 = iVar6 * 4;
        iVar6 = 300;
        if (iVar2 < 0x12d) {
          iVar6 = iVar2;
        }
        if ((*(byte *)(param_1 + 0x14) & 0x40) == 0) {
          *(byte *)(param_1 + 0x14) = *(byte *)(param_1 + 0x14) | 0x40;
          _printf(aNfsServerSNotR,param_1 + 0x32);
        }
        if ((!bVar3) && (*(int *)(_active_u + 0x15e) != 0)) {
          bVar3 = true;
          _uprintf(aNfsServerSNotR,param_1 + 0x32);
        }
      }
    } while (uVar8 != 0);
loc_4028C92:
    _clntkudp_once(iVar4,0);
    if (iVar5 != 0) {
      dword_40BBF20 = dword_40BBF20 + 1;
      *(byte *)(param_1 + 0x14) = *(byte *)(param_1 + 0x14) | 0x10;
      if (iVar5 != 0x12) {
        iStack_c = 0x16;
        uVar7 = _clnt_sperrno(iVar5);
        _printf(aNfsSFailedForS,*(undefined4 *)(_rfsnames + param_2 * 4),param_1 + 0x32,uVar7);
        iStack_10 = iVar5;
        if (*(int *)(_active_u + 0x15e) != 0) {
          uVar7 = _clnt_sperrno(iVar5);
          _uprintf(aNfsSFailedForS,*(undefined4 *)(_rfsnames + param_2 * 4),param_1 + 0x32,uVar7);
        }
      }
      goto loc_4028DAA;
    }
    if ((((param_6 == (int *)0x0) || (*param_6 != 0xd)) || (iVar9 != 0)) ||
       ((*(sword *)(param_7 + 2) != 0 || (*(sword *)(param_7 + 6) == 0)))) {
      bVar1 = *(byte *)(param_1 + 0x14);
      if ((char)bVar1 < '\0') {
        if ((bVar1 & 0x40) != 0) {
          _printf(aNfsServerSOk,param_1 + 0x32);
          *(byte *)(param_1 + 0x14) = *(byte *)(param_1 + 0x14) & 0xbf;
        }
        if (bVar3) {
          _uprintf(aNfsServerSOk,param_1 + 0x32);
        }
      }
      else {
        *(byte *)(param_1 + 0x14) = bVar1 & 0xef;
      }
loc_4028DAA:
      sub_4028A8C(iVar4);
      if (iVar9 != 0) {
        _crfree(iVar9);
      }
      if ((iStack_10 != 0) && (iStack_c == 0)) {
        _printf(aRfscallReStatu,iStack_10);
                    /* WARNING: Subroutine does not return */
        _panic(&aRfscall);
      }
      return iStack_c;
    }
    iVar9 = _crdup(param_7);
    *(undefined2 *)(iVar9 + 2) = *(undefined2 *)(iVar9 + 6);
    sub_4028A8C(iVar4);
    param_7 = iVar9;
  } while( true );
}

