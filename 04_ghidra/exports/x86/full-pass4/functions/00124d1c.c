/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00124d1c */

void FUN_00124d1c(byte *param_1,byte *param_2,int param_3)

{
  byte bVar1;
  char cVar2;
  
  while( true ) {
    if (param_3 == 0) {
      bVar1 = _kmgetc(0);
    }
    else {
      bVar1 = _kmgetc_silent(0);
    }
    bVar1 = bVar1 & 0x7f;
    if (bVar1 == 0xd) break;
    if (bVar1 < 0xe) {
      if (bVar1 != 8) {
        if (bVar1 != 10) goto LAB_00124dcc;
        break;
      }
LAB_00124d95:
      if (param_2 == param_1) {
        cVar2 = '\b';
LAB_00124dbc:
        _cnputc(cVar2);
      }
      else {
        _cnputc(' ');
        _cnputc('\b');
        param_2 = param_2 + -1;
      }
    }
    else {
      if (bVar1 == 0x40) {
LAB_00124db8:
        cVar2 = '\n';
        param_2 = param_1;
        goto LAB_00124dbc;
      }
      if (bVar1 < 0x41) {
        if (bVar1 == 0x15) goto LAB_00124db8;
      }
      else if (bVar1 == 0x7f) {
        if (param_2 != param_1) {
          _cnputc('\b');
          _cnputc('\b');
          goto LAB_00124d95;
        }
        cVar2 = '\b';
        goto LAB_00124dbc;
      }
LAB_00124dcc:
      *param_2 = bVar1;
      param_2 = param_2 + 1;
    }
  }
  *param_2 = 0;
  return;
}

