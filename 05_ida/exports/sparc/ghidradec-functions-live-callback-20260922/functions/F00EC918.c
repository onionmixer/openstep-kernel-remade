
void __threadFreeExceptionStack(int param_1)

{
  int iVar1;
  undefined *puVar2;
  bool bVar3;
  
  puVar2 = unk_F012F048;
  iVar1 = DAT_f012f058;
  do {
    bVar3 = (undefined4 *)puVar2 == (undefined4 *)0x0;
    if (iVar1 == param_1) {
loc_F00EC950:
      if (!bVar3) {
        *(undefined4 *)puVar2 = 0;
        *(undefined4 *)((int)puVar2 + 0xc) = 0;
        *(undefined4 *)((int)puVar2 + 0x10) = 0;
      }
      return;
    }
    puVar2 = *(undefined **)((int)puVar2 + 0x14);
    if ((undefined4 *)puVar2 == (undefined4 *)0x0) {
      bVar3 = true;
      goto loc_F00EC950;
    }
    iVar1 = *(int *)((int)puVar2 + 0x10);
  } while( true );
}

