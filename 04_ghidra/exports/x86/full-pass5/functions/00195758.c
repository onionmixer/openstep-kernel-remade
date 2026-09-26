/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00195758 */

undefined4 _DoRestore(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  if (_kmAlertConsole == (undefined4 *)0x0) {
    if (_kmId == 0) {
      uVar3 = 0;
    }
    else {
      (*DAT_001e776c)(*(undefined4 *)(_kmId + 0x108),PTR_s_lock_001f9220);
      iVar2 = _kmId;
      if (*(int *)(_kmId + 0x114) == 3) {
        iVar1 = *(int *)(_kmId + 0x11c);
        if (iVar1 == 0) {
          uVar3 = 0x10;
        }
        else {
          *(int *)(_kmId + 0x11c) = iVar1 + -1;
          if (iVar1 == 1) {
            *(int *)(iVar2 + 0x114) = *(int *)(iVar2 + 0x118);
            if (*(int *)(iVar2 + 0x118) == 3) {
              _IOLog(s_kmDevice__Recursive_SCM_ALERT_in_001e3997);
            }
            else {
              uVar3 = (**(code **)(*(int *)(iVar2 + 0x110) + 8))(*(int *)(iVar2 + 0x110));
              (*(code *)**(undefined4 **)(_kmId + 0x110))(*(undefined4 **)(_kmId + 0x110));
              *(undefined4 *)(_kmId + 0x110) = 0;
            }
          }
        }
      }
      else {
        uVar3 = 0x16;
      }
      (*DAT_001e7770)(*(undefined4 *)(_kmId + 0x108),PTR_s_unlock_001f9474);
    }
  }
  else {
    (*(code *)_kmAlertConsole[2])(_kmAlertConsole);
    (*(code *)*_kmAlertConsole)(_kmAlertConsole);
    _kmAlertConsole = (undefined4 *)0x0;
    uVar3 = 0;
  }
  return uVar3;
}

