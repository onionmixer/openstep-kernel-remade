
void _thread_stats(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined *puVar4;
  
  iVar2 = 0;
  iVar3 = 0;
  puVar4 = (undefined *)unk_40B6778._0_4_;
  if ((undefined *)unk_40B6778._0_4_ != unk_40B6778) {
    do {
      iVar2 = iVar2 + 1;
      if (*(int *)(puVar4 + 0xb8) != 0) {
        iVar3 = iVar3 + 1;
      }
      piVar1 = (int *)(puVar4 + 0x18);
      puVar4 = (undefined *)*piVar1;
    } while ((undefined *)*piVar1 != unk_40B6778);
  }
  _printf(aDTotalThreads,iVar2);
  _printf(aDUsingRpcReply,iVar3);
  return;
}
