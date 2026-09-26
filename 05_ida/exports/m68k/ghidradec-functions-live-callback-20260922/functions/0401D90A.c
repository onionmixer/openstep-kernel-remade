
void _rtfree(uint param_1)

{
  if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(&aRtfree);
  }
  *(sword *)(param_1 + 0x26) = *(sword *)(param_1 + 0x26) + -1;
  if ((*(uint *)(param_1 + 0x25) & 0x1ffffff) >> 8 == 0) {
    _rttrash = _rttrash + -1;
    _m_free(param_1 & 0xffffff80);
  }
  return;
}

