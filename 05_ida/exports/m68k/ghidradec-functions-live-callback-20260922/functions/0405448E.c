
void _calloutEntryFree(int param_1)

{
  if (*(int *)(param_1 + 0x1c) != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aCalloutentryfr);
  }
  _kfree(param_1,0x20);
  return;
}

