
void _tcp_trace(undefined2 param_1,undefined2 param_2,int param_3,undefined4 *param_4,
               undefined2 param_5)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _tcp_debx * 0xa2;
  _tcp_debx = _tcp_debx + 1;
  if (_tcp_debx == 100) {
    _tcp_debx = 0;
  }
  uVar2 = _iptime();
  *(undefined4 *)(_tcp_debug + iVar1) = uVar2;
  *(undefined2 *)(_tcp_debug + iVar1 + 4) = param_1;
  *(undefined2 *)(_tcp_debug + iVar1 + 6) = param_2;
  *(int *)(_tcp_debug + iVar1 + 8) = param_3;
  if (param_3 == 0) {
    _bzero(iVar1 + 0x40b7e12,0x6c);
  }
  else {
    _bcopy(param_3,iVar1 + 0x40b7e12,0x6c);
  }
  if (param_4 == (undefined4 *)0x0) {
    _bzero(iVar1 + 0x40b7de8,0x28);
  }
  else {
    *(undefined4 *)(_tcp_debug + iVar1 + 0xc) = *param_4;
    *(undefined4 *)(_tcp_debug + iVar1 + 0x10) = param_4[1];
    *(undefined4 *)(_tcp_debug + iVar1 + 0x14) = param_4[2];
    *(undefined4 *)(_tcp_debug + iVar1 + 0x18) = param_4[3];
    *(undefined4 *)(_tcp_debug + iVar1 + 0x1c) = param_4[4];
    *(undefined4 *)(_tcp_debug + iVar1 + 0x20) = param_4[5];
    *(undefined4 *)(_tcp_debug + iVar1 + 0x24) = param_4[6];
    *(undefined4 *)(_tcp_debug + iVar1 + 0x28) = param_4[7];
    *(undefined4 *)(_tcp_debug + iVar1 + 0x2c) = param_4[8];
    *(undefined4 *)(_tcp_debug + iVar1 + 0x30) = param_4[9];
  }
  *(undefined2 *)(_tcp_debug + iVar1 + 0x34) = param_5;
  return;
}
