/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00191ba0 */

void _getfsname(undefined4 param_1,undefined1 *param_2)

{
  uint uVar1;
  undefined1 *puVar2;
  char cVar3;
  
  if (((byte)_boothowto & 1) != 0) {
    _printf(s__s_key___s___001e2755,param_1,param_1);
    puVar2 = param_2;
    while( true ) {
      uVar1 = _cngetc();
      uVar1 = uVar1 & 0x7f;
      if (uVar1 == 0xd) break;
      if (uVar1 < 0xe) {
        if (uVar1 != 8) {
          if (uVar1 != 10) goto LAB_00191c54;
          break;
        }
LAB_00191c21:
        if (puVar2 == param_2) {
          cVar3 = '\b';
LAB_00191c44:
          _cnputc(cVar3);
        }
        else {
          _cnputc(' ');
          _cnputc('\b');
          puVar2 = puVar2 + -1;
        }
      }
      else {
        if (uVar1 == 0x40) {
LAB_00191c40:
          cVar3 = '\n';
          puVar2 = param_2;
          goto LAB_00191c44;
        }
        if (uVar1 < 0x41) {
          if (uVar1 == 0x15) goto LAB_00191c40;
        }
        else if (uVar1 == 0x7f) {
          if (puVar2 != param_2) {
            _cnputc('\b');
            _cnputc('\b');
            goto LAB_00191c21;
          }
          cVar3 = '\b';
          goto LAB_00191c44;
        }
LAB_00191c54:
        *puVar2 = (char)uVar1;
        puVar2 = puVar2 + 1;
      }
    }
    *puVar2 = 0;
  }
  return;
}

