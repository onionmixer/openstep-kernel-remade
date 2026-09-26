
void sub_407F250(int *param_1)

{
  word wVar1;
  uint uVar2;
  uint uVar3;
  undefined auStack_a [6];
  
  if ((param_1[2] & 0x400U) == 0) {
    uVar3 = 2;
  }
  else {
    uVar3 = ((word)((word)param_1[2] ^ 4) & 7) >> 2;
  }
  _sprintf(auStack_a,&aSdD,param_1[1]);
  uVar2 = *(uint *)(*(int *)(*param_1 + 0xb2) + 1) >> 0x1f;
  if ((*(byte *)((int)param_1 + 10) & 8) != 0) {
    uVar2 = uVar2 | 2;
  }
  wVar1 = (sword)param_1[1] << 3;
  _vol_notify_dev((int)(sword)(wVar1 | (sword)dword_40B5026 << 8),
                  (int)(sword)(wVar1 | (sword)dword_40B502A << 8),&unk_40A62E7,uVar3,auStack_a,uVar2
                 );
  return;
}
