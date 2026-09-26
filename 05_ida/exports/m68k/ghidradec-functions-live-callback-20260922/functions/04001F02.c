
undefined4 trap5(void)

{
  return *(undefined4 *)(*(int *)(_active_threads + 0x24) + 0x50);
}

