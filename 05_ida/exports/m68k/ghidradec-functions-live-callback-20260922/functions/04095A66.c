
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void _dbg_process(int param_1)

{
  int iVar1;
  int iVar2;
  undefined *puVar3;
  undefined4 uVar4;
  int iVar5;
  int *piStack_28;
  int iStack_10;
  
  iVar2 = dword_40C8F00;
  iVar1 = dword_40C8F00 + 0x2a;
  if ((dword_40C9474 == 0) || (param_1 == 0)) {
    return;
  }
  _nmi_prf(aConnectingToDe);
loc_4095AAE:
  do {
    switch(*(undefined4 *)(param_1 + 0x2e)) {
    case :
      puVar3 = (undefined *)_index(param_1 + 0x42,0x3a);
      if (puVar3 != (undefined *)0x0) {
        *puVar3 = 0;
      }
      _nmi_prf(aDebuggingConne,param_1 + 0x42,puVar3 + 1);
      DAT_40c9470 = 0;
      *(undefined4 *)(iVar2 + 0x2e) = 2;
      break;
    case :
      *(undefined4 *)(iVar2 + 0x3a) = 1;
      *(undefined4 *)(iVar2 + 0x2e) = 5;
      break;
    :
      _nmi_prf(aKdbgUnknownRqT,*(undefined4 *)(iVar2 + 0x2e));
loc_4096144:
      *(undefined4 *)(iVar2 + 0x2e) = 0x16;
      *(undefined4 *)(iVar2 + 0x3e) = 0;
      break;
    case :
      *(undefined4 *)(iVar2 + 0x3e) = 0;
      *(int *)(iVar2 + 0x42) = _slot_id;
      *(undefined4 *)(iVar2 + 0x46) = 0x20000;
      *(undefined4 *)(iVar2 + 0x4a) = 1;
      *(int *)(iVar2 + 0x4e) = _slot_id + 0x1000000;
      *(undefined4 *)(iVar2 + 0x52) = 0x20000;
      *(undefined4 *)(iVar2 + 0x56) = 1;
      *(int *)(iVar2 + 0x5a) = _slot_id + 0x2000000;
      *(undefined4 *)(iVar2 + 0x5e) = 0xc0040;
      *(undefined4 *)(iVar2 + 0x62) = 3;
      *(int *)(iVar2 + 0x66) = _slot_id + 0x2100000;
      *(undefined4 *)(iVar2 + 0x6a) = 0x1e000;
      *(undefined4 *)(iVar2 + 0x6e) = 3;
      *(int *)(iVar2 + 0x72) = _slot_id + 0x4000000;
      if (_dma_chip == 0x139) {
        if (_machine_type == '\x03') {
          uVar4 = 0x2000000;
        }
        else {
          uVar4 = 0x4000000;
        }
      }
      else {
        uVar4 = 0x8000000;
      }
      *(undefined4 *)(iVar2 + 0x76) = uVar4;
      *(undefined4 *)(iVar2 + 0x7a) = 3;
      piStack_28 = (int *)(iVar2 + 0x7e);
      switch(_machine_type) {
      case :
      case :
        break;
      case :
        *piStack_28 = 0x4000000;
        *(undefined4 *)(iVar2 + 0x82) = 0x8000000;
        *(undefined4 *)(iVar2 + 0x86) = 3;
        *(undefined4 *)(iVar2 + 0x8a) = 0xc000000;
        *(undefined4 *)(iVar2 + 0x8e) = 0x10000000;
        *(undefined4 *)(iVar2 + 0x92) = 3;
        *(undefined4 *)(iVar2 + 0x96) = 0x24000000;
        *(undefined4 *)(iVar2 + 0x9a) = 0x28000000;
        *(undefined4 *)(iVar2 + 0x9e) = 3;
        *(undefined4 *)(iVar2 + 0xa2) = 0x2c000000;
        *(undefined4 *)(iVar2 + 0xa6) = 0x30000000;
        *(undefined4 *)(iVar2 + 0xaa) = 3;
        piStack_28 = (int *)(iVar2 + 0xae);
        break;
      :
        *piStack_28 = _slot_id + 0x2200000;
        *(undefined4 *)(iVar2 + 0x82) = 0x9000;
        *(undefined4 *)(iVar2 + 0x86) = 3;
        *(int *)(iVar2 + 0x8a) = _slot_id + 0x2210000;
        *(undefined4 *)(iVar2 + 0x8e) = 4;
        *(undefined4 *)(iVar2 + 0x92) = 3;
        *(int *)(iVar2 + 0x96) = _slot_id + 0x3e00000;
        *(undefined4 *)(iVar2 + 0x9a) = 0x80000;
        *(undefined4 *)(iVar2 + 0x9e) = 3;
        piStack_28 = (int *)(iVar2 + 0xa2);
      }
      *piStack_28 = 0x10000000;
      piStack_28[1] = 0x4000000;
      piStack_28[2] = 3;
      *(int *)(iVar2 + 0x3e) = (int)piStack_28 + (-0xc - iVar1);
      *(undefined4 *)(iVar2 + 0x2e) = 6;
      break;
    case :
      if (0x200 < *(int *)(param_1 + 0x3a)) {
                    /* WARNING: Subroutine does not return */
        _dbg_panic(aBadLengthOfDat);
      }
      for (iStack_10 = 0; iStack_10 < *(int *)(param_1 + 0x3a); iStack_10 = iStack_10 + 4) {
        iVar5 = _rdmem(iStack_10 + *(int *)(param_1 + 0x36),4,iStack_10 + 0x18 + iVar1);
        if (iVar5 != 0) goto loc_4096144;
      }
      *(undefined4 *)(iVar2 + 0x2e) = 3;
      *(undefined4 *)(iVar2 + 0x3e) = *(undefined4 *)(param_1 + 0x3a);
      break;
    case :
      if (*(int *)(param_1 + 0x3e) != 0x200) {
                    /* WARNING: Subroutine does not return */
        _dbg_panic(aBadLengthOfDat);
      }
      for (iStack_10 = 0; iStack_10 < 0x200; iStack_10 = iStack_10 + 4) {
        iVar5 = _wrmem(iStack_10 + *(int *)(param_1 + 0x36),4,
                       *(undefined4 *)(iStack_10 + 0x18 + param_1 + 0x2a));
        if (iVar5 != 0) goto loc_4096144;
      }
      *(undefined4 *)(iVar2 + 0x2e) = 1;
      *(undefined4 *)(iVar2 + 0x3e) = 0;
      break;
    case :
      _bcopy(&dword_40C96D8,iVar2 + 0x42,0x48);
      *(undefined4 *)(iVar2 + 0x3e) = 0x48;
      *(undefined4 *)(iVar2 + 0x2e) = 4;
      break;
    case :
      _bcopy(param_1 + 0x42,&dword_40C96D8,0x48);
      *(undefined4 *)(iVar2 + 0x2e) = 1;
      *(undefined4 *)(iVar2 + 0x3e) = 0;
      break;
    case :
    case :
      *(undefined4 *)(iVar2 + 0x2e) = 1;
      *(undefined4 *)(iVar2 + 0x3e) = 0;
      break;
    case :
    case :
      goto loc_4095eae;
    case :
      dword_40C9474 = 0;
      dword_40B562C = 1;
loc_4095eae:
      *(undefined4 *)(iVar2 + 0x2e) = 1;
      *(undefined4 *)(iVar2 + 0x3e) = 0;
      sub_40964C0();
      if ((word_40C971A & 0x8000) != 0) {
        iVar5 = _get_vbr();
        dword_40B561C = *(undefined4 *)(iVar5 + 0x24);
        *(code **)(iVar5 + 0x24) = __dbg_trap;
        dword_40B5624 = 1;
      }
      _dbg_kresume();
      if (dword_40B562C != 0) goto loc_4095f18;
      _SENDEXC();
      goto loc_409615C;
    case :
      if ((*(int *)(param_1 + 0x3e) == 0) || (0x1ff < *(int *)(param_1 + 0x3e))) {
        _mon_boot(0);
      }
      else {
        *(undefined *)(*(int *)(param_1 + 0x3e) + param_1 + 0x2a + 0x18) = 0;
        _mon_call(param_1 + 0x42);
      }
    }
    sub_40964C0();
loc_409615C:
    param_1 = sub_40963BC(0);
  } while( true );
loc_4095f18:
  dword_40B562C = 0;
  param_1 = _dbg_connect_pkt;
  _dbg_connect_pkt = 0;
  goto loc_4095AAE;
}

