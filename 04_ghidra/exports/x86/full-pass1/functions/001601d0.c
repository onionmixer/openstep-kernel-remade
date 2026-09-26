/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001601d0 */

void _miniMonLoop(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  
  _miniMonState = param_3;
  if (param_2 != 0) {
    _safe_prf(s_System_Panic__001df12a);
    _safe_prf(&DAT_001df139,_panicstr);
    _safe_prf(s__Type__r__to_reboot_or__m__for_m_001df13d);
    do {
      while (iVar1 = _miniMonTryGetchar(), iVar1 == 0x72) {
        _safe_prf(s_Rebooting____001df165);
        _miniMonReboot(&DAT_001df173);
      }
    } while (iVar1 != 0x6d);
    _safe_prf(&DAT_001df174);
  }
  _safe_prf(s_NEXTSTEP_Mini_monitor_001df176);
  do {
    _safe_prf(&DAT_001df18d,param_1);
    iVar1 = 0x7f;
    puVar3 = &DAT_001e5dc4;
    while (iVar2 = _miniMonGetchar(), iVar2 != 10) {
      if (iVar2 < 0xb) {
        if (iVar2 == 8) {
          _miniMonPutchar(0x20);
          if (puVar3 != &DAT_001e5dc4) {
            _miniMonPutchar(8);
            iVar1 = iVar1 + 1;
            puVar3 = puVar3 + -1;
          }
        }
        else {
LAB_001602d4:
          if (iVar1 == 0) {
            _miniMonPutchar(8);
            _miniMonPutchar(0x20);
            _miniMonPutchar(8);
          }
          else {
            *puVar3 = (char)iVar2;
            iVar1 = iVar1 + -1;
            puVar3 = puVar3 + 1;
          }
        }
      }
      else {
        if (iVar2 == 0xd) {
          _miniMonPutchar(10);
          break;
        }
        if (iVar2 != 0x15) goto LAB_001602d4;
        _miniMonPutchar(10);
        puVar3 = &DAT_001e5dc4;
      }
    }
    *puVar3 = 0;
    iVar1 = FUN_001600cc(&DAT_001e5dc4);
    if (iVar1 == 0) {
      return;
    }
  } while( true );
}

