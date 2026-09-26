/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ad4cc. */
int __cdecl -[SCSIDisk sdRawRead:blockCnt:buffer:](SCSIDisk *self, SEL a2, int a3, int a4, void *a5)
{
  $BB0ECD142E749ABD0946980FC80D177E *v5; // eax
  id v6; // esi
  $BB0ECD142E749ABD0946980FC80D177E *v8; // [esp+Ch] [ebp-4h]

  v5 = -[SCSIDisk allocSdBuf:](self, sel_allocSdBuf_, 0); /*0x1ad4eb*/
  v5->var0 = 0; /*0x1ad4f2*/
  v5->var1 = a3; /*0x1ad4f8*/
  v5->var2 = a4; /*0x1ad4fb*/
  v5->var3 = a5; /*0x1ad4fe*/
  v8 = v5; /*0x1ad501*/
  v5->var4 = IOVmTaskSelf(); /*0x1ad50c*/
  *((_BYTE *)v8 + 32) |= 3u; /*0x1ad50f*/
  v6 = -[SCSIDisk enqueueSdBuf:](self, sel_enqueueSdBuf_, v8); /*0x1ad524*/
  -[SCSIDisk freeSdBuf:](self, sel_freeSdBuf_, v8); /*0x1ad535*/
  return (int)v6; /*0x1ad53f*/
}
