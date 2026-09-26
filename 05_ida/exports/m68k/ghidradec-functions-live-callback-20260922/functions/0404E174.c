
void _miniMonInit(void)

{
  __kernDebuggerLock = _simple_lock_alloc();
  _simple_unlock(__kernDebuggerLock);
  return;
}

