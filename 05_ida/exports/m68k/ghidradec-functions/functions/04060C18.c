
void sub_4060C18(int param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  
  _lock_read(param_1);
  iVar2 = *(int *)(param_1 + 0xc);
  if (param_1 + 8 != iVar2) {
    do {
      if ((*(byte *)(iVar2 + 0x18) & 0xa0) == 0) {
        if (((*(uint *)(iVar2 + 8) <= param_3) && (param_2 < *(uint *)(iVar2 + 0xc))) &&
           (iVar1 = *(int *)(iVar2 + 0x10), iVar1 != 0)) {
          do {
            *(uint *)(iVar1 + 0x43) =
                 *(uint *)(iVar1 + 0x43) & 0xf0ffffff | ((param_4 & 0xffff) >> 0xc) << 0x18;
            *(word *)(iVar1 + 0x44) = (sword)param_4 << 4 | *(word *)(iVar1 + 0x44) & 0xf;
            iVar1 = *(int *)(iVar1 + 0x1c);
          } while (iVar1 != 0);
        }
      }
      else {
        sub_4060C18(*(undefined4 *)(iVar2 + 0x10),param_2,param_3,param_4);
      }
      iVar2 = *(int *)(iVar2 + 4);
    } while (param_1 + 8 != iVar2);
  }
  _lock_done(param_1);
  return;
}
