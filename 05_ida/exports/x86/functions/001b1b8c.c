/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b1b8c. */
int __cdecl -[EventDriver sendIOThreadMsg:to:with:](EventDriver *self, SEL a2, SEL a3, id a4, id a5)
{
  _DWORD v6[3]; // [esp+0h] [ebp-Ch] BYREF

  v6[0] = a4; /*0x1b1b95*/
  v6[1] = a3; /*0x1b1b9b*/
  v6[2] = a5; /*0x1b1ba1*/
  return -[EventDriver _threadOpCommon:opParams:async:](self, sel__threadOpCommon_opParams_async_, 2, v6, 0); /*0x1b1bbc*/
}
