/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b1bc0. */
id __cdecl -[EventDriver sendIOThreadAsyncMsg:to:with:](EventDriver *self, SEL a2, SEL a3, id a4, id a5)
{
  _DWORD v6[3]; // [esp+4h] [ebp-Ch] BYREF

  v6[0] = a4; /*0x1b1bcd*/
  v6[1] = a3; /*0x1b1bd3*/
  v6[2] = a5; /*0x1b1bd9*/
  -[EventDriver _threadOpCommon:opParams:async:](self, sel__threadOpCommon_opParams_async_, 2, v6, 1); /*0x1b1bec*/
  return self; /*0x1b1bf3*/
}
