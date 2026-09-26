
void _ResetMouse(void)

{
  if (_autoDimmed != 0) {
    _UndoAutoDim();
  }
  _InitMouseVars();
  return;
}

