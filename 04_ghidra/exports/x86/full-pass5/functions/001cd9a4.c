/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cd9a4 */

char * FUN_001cd9a4(char *param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
switchD_001cd9bd_caseD_4e:
  cVar1 = *param_1;
  param_1 = param_1 + 1;
  switch(cVar1) {
  case '(':
    uVar3 = 0x29;
    break;
  default:
    return param_1;
  case 'N':
  case 'O':
  case 'V':
  case '^':
  case 'n':
  case 'o':
  case 'r':
    goto switchD_001cd9bd_caseD_4e;
  case '[':
    for (; (byte)(*param_1 - 0x30U) < 10; param_1 = param_1 + 1) {
    }
    uVar3 = 0x5d;
    break;
  case '{':
    uVar3 = 0x7d;
  }
  iVar2 = FUN_001cd92c(param_1,uVar3);
  return param_1 + iVar2 + 1;
}

