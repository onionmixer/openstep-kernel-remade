/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001284c0 */

void _tcp_trace(undefined2 param_1,undefined2 param_2,undefined4 *param_3,undefined4 *param_4,
               undefined2 param_5)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  
  iVar1 = _tcp_debx * 0xa4;
  _tcp_debx = _tcp_debx + 1;
  if (_tcp_debx == 100) {
    _tcp_debx = 0;
  }
  uVar2 = _iptime();
  *(undefined4 *)(&_tcp_debug + iVar1) = uVar2;
  *(undefined2 *)(&DAT_001ead54 + iVar1) = param_1;
  *(undefined2 *)(&DAT_001ead56 + iVar1) = param_2;
  *(undefined4 **)(&DAT_001ead58 + iVar1) = param_3;
  if (param_3 == (undefined4 *)0x0) {
    _bzero(&DAT_001ead88 + iVar1,0x6c);
  }
  else {
    puVar4 = (undefined4 *)(&DAT_001ead88 + iVar1);
    for (iVar3 = 0x1b; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar4 = *param_3;
      param_3 = param_3 + 1;
      puVar4 = puVar4 + 1;
    }
  }
  if (param_4 == (undefined4 *)0x0) {
    _bzero(&DAT_001ead5c + iVar1,0x28);
  }
  else {
    puVar4 = (undefined4 *)(&DAT_001ead5c + iVar1);
    for (iVar3 = 10; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar4 = *param_4;
      param_4 = param_4 + 1;
      puVar4 = puVar4 + 1;
    }
  }
  *(undefined2 *)(&DAT_001ead84 + iVar1) = param_5;
  return;
}

