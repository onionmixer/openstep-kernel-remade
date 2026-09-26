/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00191af8 */

char * _gets(char *param_1)

{
  uint uVar1;
  char *pcVar2;
  char *in_stack_00000008;
  char cVar3;
  
LAB_00191b04:
  do {
    uVar1 = _cngetc();
    pcVar2 = (char *)(uVar1 & 0x7f);
    if (pcVar2 == (char *)0xd) {
LAB_00191b38:
      *in_stack_00000008 = '\0';
      return pcVar2;
    }
    if (pcVar2 < (char *)0xe) {
      if (pcVar2 != (char *)0x8) {
        if (pcVar2 != (char *)0xa) goto LAB_00191b8c;
        goto LAB_00191b38;
      }
LAB_00191b59:
      if (in_stack_00000008 == param_1) {
        cVar3 = '\b';
LAB_00191b7c:
        _cnputc(cVar3);
      }
      else {
        _cnputc(' ');
        _cnputc('\b');
        in_stack_00000008 = in_stack_00000008 + -1;
      }
      goto LAB_00191b04;
    }
    if (pcVar2 == (char *)0x40) {
LAB_00191b78:
      cVar3 = '\n';
      in_stack_00000008 = param_1;
      goto LAB_00191b7c;
    }
    if (pcVar2 < (char *)0x41) {
      if (pcVar2 == (char *)0x15) goto LAB_00191b78;
    }
    else if (pcVar2 == (char *)0x7f) {
      if (in_stack_00000008 != param_1) {
        _cnputc('\b');
        _cnputc('\b');
        goto LAB_00191b59;
      }
      cVar3 = '\b';
      goto LAB_00191b7c;
    }
LAB_00191b8c:
    *in_stack_00000008 = (char)pcVar2;
    in_stack_00000008 = in_stack_00000008 + 1;
  } while( true );
}

