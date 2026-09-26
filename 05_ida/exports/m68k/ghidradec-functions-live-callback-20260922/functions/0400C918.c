
void _soo_rw(int param_1,int param_2,int param_3)

{
  code *pcVar1;
  
  if (((*(byte *)(*_active_u + 0x16) & 0x40) != 0) && ((*(uint *)(param_1 + 8) & 0x2000) != 0)) {
    *(sword *)(param_3 + 0x10) = (sword)*(uint *)(param_1 + 8);
  }
  pcVar1 = _sosend;
  if (param_2 == 0) {
    pcVar1 = _soreceive;
  }
  (*pcVar1)(*(undefined4 *)(param_1 + 0x16),0,param_3,0,0);
  return;
}

